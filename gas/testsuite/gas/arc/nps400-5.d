#as: -mcpu=arc700 -mnps400
#objdump: -dr

.*: +file format .*arc.*

Disassembly of section .text:

[0-9a-f]+ <.*>:
   0:	3925 0080           	dcacl	r0,r1,r2
   4:	3c25 8143           	dcacl.f	r3,r4,r5
   8:	3925 00be           	dcacl	0,r1,r2
   c:	3c25 817e           	dcacl.f	0,r4,r5