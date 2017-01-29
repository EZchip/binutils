#as: -mcpu=arc700 -mnps400
#objdump: -dr

.*: +file format .*arc.*

Disassembly of section .text:

[0-9a-f]+ <.*>:
   0:	3a2f 1300           	dctcp	r10,r12
   4:	3e29 13cd           	dcip	r13,r14,r15
   8:	3d2f 1381           	dcip	r13,r14
   c:	3e29 1f8d 2211 8844 	dcip	r13,r14,0x44,0x88,0x11,0x22
  14:	382f 2442           	dcet	r16,r17
  18:	3b20 2512           	dcet	r18,r19,r20
  1c:	3b20 2f92 4321 1234 	dcet	r18,r19,0x1234,0x4321