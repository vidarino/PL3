

version_str:
	.ascii "release:03.5000:\n"
	.ascii "build:46135,20100721:tetsu@tetsu-linux22.rd.scei.sony.co.jp\n"
	.ascii "target:0001:CEX-ww\n"
	.ascii "security:3960@security/sdk_branches/release_341/trunk:\n"
	.ascii "system:45857@sys/sdk_branches/release_341/trunk:\n"
	.ascii "x3:15557@x3/branches/target34x:\n"
	.ascii "paf:6082@paf/branches/target34x:\n"
	.ascii "vsh:82665@vsh/branches/target34x:\n"
	.ascii "sys_jp:67@sys_jp/branches/target34x:\n"
	.ascii "ps1emu:6377@emu/branches/target101/ps1:\n"
	.ascii "ps1netemu:6520@emu/branches/target340/ps1_net:\n"
	.ascii "ps1newemu:6378@emu/branches/target202/ps1_new:\n"
	.ascii "ps2emu:6448@emu/branches/target340/ps2:\n"
	.ascii "ps2gxemu:13784@branches/target340/gx:\n"
	.ascii "ps2softemu:13474@branches/soft190/soft:\n"
	.ascii "pspemu:6501@emu/branches/target340/psp:\n"
	.ascii "emerald:3697@emerald/target34x:\n"
	.ascii "bdp:13407@bdp/branches/target34x:\n"
	.ascii "patch::\n"
	.ascii "auth:46135:\n"
	.ascii "\n\n\n\n\n\n"

	.org version_str + 0x2d0

