/*
 * dump_lv2_pcap_to_bin.h -- PS3 Jailbreak - dump lv2 pcap capture to bin
 *
 * Copyright (C) Youness Alaoui (KaKaRoTo)
 *
 * This software is distributed under the terms of the GNU General Public
 * License ("GPL") version 3, as published by the Free Software Foundation.
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>


typedef struct pcap_hdr_s {
  uint32_t magic_number;   /* magic number */
  uint16_t version_major;  /* major version number */
  uint16_t version_minor;  /* minor version number */
  int32_t  thiszone;       /* GMT to local correction */
  uint32_t sigfigs;        /* accuracy of timestamps */
  uint32_t snaplen;        /* max length of captured packets, in octets */
  uint32_t network;        /* data link type */
} pcap_hdr_t;

typedef struct pcaprec_hdr_s {
  uint32_t ts_sec;         /* timestamp seconds */
  uint32_t ts_usec;        /* timestamp microseconds */
  uint32_t incl_len;       /* number of octets of packet saved in file */
  uint32_t orig_len;       /* actual length of packet */
} pcaprec_hdr_t;

typedef struct ethernet_hdr_s {
  char dest[6];
  char src[6];
  uint16_t type;
} ethernet_hdr_t;

static int am_big_endian(void)
{
  long one= 1;
  return !(*((char *)(&one)));
}


static uint32_t be32_to_cpu (uint32_t cpu)
{
  int i;
  uint32_t result;

  if (am_big_endian ())
    return cpu;

  for (i = 0; i < sizeof(uint32_t); i++)
    ((char *)&result)[i] = ((char *)&cpu)[sizeof(uint32_t) - i - 1];

  return result;
}


int main (int argc, char *argv[])
{
  FILE *in = NULL;
  FILE *out = NULL;
  int ret;
  char buf[1028];
  int offset;
  int last_offset = -1;

  if (argc != 3) {
    printf ("Usage : %s in.pcap out.bin\n", argv[0]);
    return -1;
  }

  in = fopen (argv[1], "rb");
  if (in == NULL) {
    perror ("Could not open input file :");
    return -1;
  }
  out = fopen (argv[2], "wb");
  if (in == NULL) {
    perror ("Could not open output file :");
    fclose (in);
    return -1;
  }

  ret = fread(buf, sizeof(pcap_hdr_t), 1, in);
  if (ret != 1) {
    printf ("Error reading pcap header\n");
    return -2;
  }


  while (1) {
    ret = fread(buf, sizeof(pcaprec_hdr_t), 1, in);
    if (ret != 1)
      break;
    ret = fread(buf, sizeof(ethernet_hdr_t), 1, in);
    if (ret != 1)
      break;
    ret = fread(buf, 1, 1028, in);
    if (ret != 1028)
      break;
    offset = be32_to_cpu (*((int *) buf));
    if (last_offset > 0 && offset != last_offset &&
        offset != last_offset + 1024) {
      printf ("WARNING: offset %X missing!!!\n", last_offset + 1024);
    }
    last_offset = offset;
    fseek (out, offset, SEEK_SET);
    fwrite (buf+4, 1, 1024, out);
  }
  printf ("Written %d bytes\n", offset + 1024);
  fclose (in);
  fclose (out);

  return 0;
}
