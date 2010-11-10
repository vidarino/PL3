#include "macros.h.S"

.align 4
model_set:
	lis	%r31, 1
	ori	%r31, %r31, 0x9004
	cmpw	%r31, %r3
	bne	loc273650
	li	%r30, 0x82
	stb	%r30, 3(%r4)
	ld	%r0, 0xC0(%r1)
	ld	%r29, 0x98(%r1)
	ld	%r30, 0xA0(%r1)
	mtlr	%r0
	ld	%r31, 0xA8(%r1)
	addi	%r1, %r1,0xB0
	li	%r3, 0
	blr
loc273650:
	mr	%r30, %r3
	b	ABSOLUTE_MEM2(patch_func20 + 4)
