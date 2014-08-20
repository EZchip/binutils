/******************************************/
/* movh b,s16 */
  {(unsigned char *)"movh%> %*,%*,%]", 0xf81f, 0x4fc8, ARCOMPACT, 0, 0 ,0,0},
/* movh.cl b,s16 */
  {(unsigned char *)"movh.cl%> %*,%]", 0xf81f, 0x4fd8, ARCOMPACT, 0, 0 ,0,0},
/* movl b,s16 */
  {(unsigned char *)"movl%> %*,%*,%]", 0xf81f, 0x4fc9, ARCOMPACT, 0, 0 ,0,0},
/* movl.cl b,s16 */
  {(unsigned char *)"movl.cl%> %*,%]", 0xf81f, 0x4fd9, ARCOMPACT, 0, 0 ,0,0},
/* movb<.f><.cl> b,c,dst,src,size */
  {(unsigned char *)"movb%>%.f%.\15 %b,%c,%\221,%\220,%\222%(%\14", 0xf81f, 0x4801, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"movb%>%.\15%.f %b,%c,%\221,%\220,%\222%(%\14", 0xf81f, 0x4801, ARCOMPACT, 0, 0 ,0,0},
/* movb<.f> b,b,c,dst,src,size */
  {(unsigned char *)"movb%>%.f %b,%b,%c,%\221,%\220,%\222%(%\14", 0xf81f, 0x4801, ARCOMPACT, 0, 0 ,0,0},
/* movbi<.f> b,b,imm,dst,size */
  {(unsigned char *)"movbi%>%.f %*,%*,%\303,%\221,%\304%(%\14", 0xf81f, 0x4fcf, ARCOMPACT, 0, 0 ,0,0},
/* movbi<.f>.cl b,imm,dst,size */
  {(unsigned char *)"movbi%>%.f%.\15 %*,%\303,%\221,%\304%(%\14", 0xf81f, 0x4fcf, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"movbi%>%.\15%.f %*,%\303,%\221,%\304%(%\14", 0xf81f, 0x4fcf, ARCOMPACT, 0, 0 ,0,0},
/* mrgb.cl b,b,c,dst1,src1,size1,dst2,src2,size2 */
  {(unsigned char *)"mrgb.cl%Q %b,%b,%c,%\202,%\200,%\204,%\203,%\201,%\205%\26", 0xf81f, 0x5803, ARCOMPACT, 0, 0 ,0,0},
/* mrgb b,b,c,dst1,src1,size1,dst2,src2,size2 */
  {(unsigned char *)"mrgb%Q %b,%b,%c,%\202,%\200,%\204,%\203,%\201,%\205%\26", 0xf81f, 0x5803, ARCOMPACT, 0, 0 ,0,0},
/* mov2b b,b,c,dst1,mod1,src1,dst2,mod2,src2;*/
  {(unsigned char *)"mov2b%Q %b,%b,%c,%\202,%\207,%\200,%\203,%\210,%\201%\31", 0xf81f, 0x5800, ARCOMPACT, 0, 0 ,0,0},
/* mov2b.cl b,c,dst1,mod1,src1,dst2,mod2,src2;*/
  {(unsigned char *)"mov2b.cl%Q %b,%c,%\202,%\207,%\200,%\203,%\210,%\201%\31", 0xf81f, 0x5800, ARCOMPACT, 0, 0 ,0,0},
/* mov3b b,b,c,dst1,mod1,src1,dst2,mod2,src2,dst3,mod3,src3*/
  {(unsigned char *)"mov3b%Q%> %b,%b,%c,%\202,%\207,%\200,%\203,%\210,%\201,%\221,%\213,%\212%\36",0xf81f, 0x5810, ARCOMPACT, 0, 0 ,0,0},
/* mov3bcl b,c,dst1,mod1,src1,dst2,mod2,src2,dst3,mod3,src3*/
  {(unsigned char *)"mov3bcl%Q%> %b,%c,%\202,%\207,%\200,%\203,%\210,%\201,%\221,%\213,%\212%\36",0xf81f, 0x5811, ARCOMPACT, 0, 0 ,0,0},
/* mov4b b,b,c,dst1,mod1,src1,dst2,mod2,src2,dst3,mod3,src3,dst4,mod4,src4*/
  {(unsigned char *)"mov4b%Q%> %b,%b,%c,%\202,%\207,%\200,%\203,%\210,%\201,%\221,%\213,%\212,%\215,%\214,%\220%\36",0xf81f, 0x5810, ARCOMPACT, 0, 0 ,0,0},
/* mov4bcl b,c,dst1,mod1,src1,dst2,mod2,src2,dst3,mod3,src3,dst4,mod4,src4*/
  {(unsigned char *)"mov4bcl%Q%> %b,%c,%\202,%\207,%\200,%\203,%\210,%\201,%\221,%\213,%\212,%\215,%\214,%\220%\36",0xf81f, 0x5811, ARCOMPACT, 0, 0 ,0,0},
/* ext4b.cl b,c,dst,src1,src2,src3,src4 */
  {(unsigned char *)"ext4b.cl%Q %b,%c,%\212,%\200,%\201,%\202,%\203%\32", 0xf81f, 0x5801, ARCOMPACT, 0, 0 ,0,0}, /*AR*/
/* ext4b b,b,c,dst,src1,src2,src3,src4 */
  {(unsigned char *)"ext4b%Q%.) %b,%b,%c,%\212,%\200,%\201,%\202,%\203%\32", 0xf81f, 0x5801, ARCOMPACT, 0, 0 ,0,0},
/* ins4b.cl b,c,src,dst1,dst2,dst3,dst4 */
  {(unsigned char *)"ins4b.cl%Q %b,%c,%\200,%\201,%\202,%\203,%\212%\33", 0xf81f, 0x5802, ARCOMPACT, 0, 0 ,0,0}, /*AR*/
/* ins4b b,b,c,src,dst1,dst2,dst3,dst4 */
  {(unsigned char *)"ins4b%Q %b,%b,%c,%\200,%\201,%\202,%\203,%\212%\33", 0xf81f, 0x5802, ARCOMPACT, 0, 0 ,0,0},
/* mxb.s b,c,FieldStartPos,FieldSz,ShiftFactor,BitsToScramble */
  {(unsigned char *)"mxb.s+\017%> %b,%c,%\247,%\250,%\251,%\252%(%\34", 0xf81f, 0x580b, ARCOMPACT, 0, 0 ,0,0},
/* mxb b,c,FieldStartPos,FieldSz,ShiftFactor*/
  {(unsigned char *)"mxb%> %b,%c,%\247,%\250,%\251%(", 0xf81f, 0x580b, ARCOMPACT, 0, 0 ,0,0},
/* imxb.s b,c,FieldStartPos,FieldSz,ShiftFactor,BitsToScramble */
  {(unsigned char *)"imxb.s+\000+\017%> %b,%c,%\247,%\250,%\251,%\252%(%\34", 0xf81f, 0x580b, ARCOMPACT, 0, 0 ,0,0},
/* imxb b,c,FieldStartPos,FieldSz,ShiftFactor*/
  {(unsigned char *)"imxb+\000%> %b,%c,%\247,%\250,%\251%(", 0xf81f, 0x580b, ARCOMPACT, 0, 0 ,0,0},
/* addl.f b,b,s16 */
  {(unsigned char *)"addl%>%.f %*,%*,%\302%(", 0xf81f, 0x4fca, ARCOMPACT, 0, 0 ,0,0},
/* subl.f b,b,s16 */
  {(unsigned char *)"subl%>%.f %*,%*,%\302%(", 0xf81f, 0x4fcb, ARCOMPACT, 0, 0 ,0,0},
/* orl.f b,b,s16 */
  {(unsigned char *)"orl%>%.f %*,%*,%]%(", 0xf81f, 0x4fcc, ARCOMPACT, 0, 0 ,0,0},
/* andl.f b,b,s16 */
  {(unsigned char *)"andl%>%.f %*,%*,%]%(", 0xf81f, 0x4fcd, ARCOMPACT, 0, 0 ,0,0},
/* xorl.f b,b,s16 */
  {(unsigned char *)"xorl%>%.f %*,%*,%]%(", 0xf81f, 0x4fce, ARCOMPACT, 0, 0 ,0,0},
/* addb.f.sx b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"addb%>%.f%.} %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"addb%>%.}%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* andb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"andb%>+\000%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* xorb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"xorb%>+\001%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* orb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"orb%>+\000+\001%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* subb.f.sx b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"subb%>+\002%.f%.} %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"subb%>+\002%.}%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* adcb.f.sx b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"adcb%>+\000+\002%.f%.} %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adcb%>+\000+\002%.}%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* sbcb.f.sx b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"sbcb%>+\001+\002%.f%.} %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"sbcb%>+\001+\002%.}%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* fxorb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"fxorb%>+\000+\001+\002%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* wxorb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"wxorb%>+\003%.f %b,%b,%c,%\231,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* notb.f b,c,src2_sel,size */
  {(unsigned char *)"notb%>+\000+\003%.f %b,%c,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* cntbb.f b,c,size,src2_sel */
  {(unsigned char *)"cntbb%>+\001+\003%.f %b,%c,%\232,%\230%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* shlb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"shlb%>+\000+\001+\003%.f %b,%b,%c,%\231,%\232,%\230%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* shrb.f b,b,c,src1_sel,src2_sel,size */
  {(unsigned char *)"shrb%>+\002+\003%.f %b,%b,%c,%\231,%\232,%\230%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* div.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"divm%>+\000+\002+\003%.f %b,%b,%c,%\231,%\232%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* div.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"divm%>+\000+\002+\003%.f %b,%b,%\234,%\231+\011%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* div.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"div%>+\000+\002+\003+\016%.f %b,%b,%c,%\231,%\232%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* div.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"div%>+\000+\002+\003+\016%.f %b,%b,%\234,%\231+\011%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* mod.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"mod%>+\000+\002+\003+\017%.f %b,%b,%c,%\231,%\232%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* mod.f b,b,c,src1_sel,dst_sel,mode */
  {(unsigned char *)"mod%>+\000+\002+\003+\017%.f %b,%b,%\234,%\231+\011%(%\301", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* decode<.f><.cl> b,c,dst,src */
  {(unsigned char *)"decode%>%.f%.\15 %b,%c,%\221,%\220%(%\14", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"decode%>%.\15%.f %b,%c,%\221,%\220%(%\14", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* decode<.f> b,b,c,dst,src,size */
  {(unsigned char *)"decode%>%.f %b,%b,%c,%\221,%\220,%\222%(%\14", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"decode%>%.f %b,%b,%c,%\221,%\220,%\222%(%\14", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* encode<.f> b,c,src,size */
  {(unsigned char *)"encode%>%.f %b,%c,%\220,%\222%(", 0xf81f, 0x4804, ARCOMPACT, 0, 0 ,0,0},
#if 1 /* only test for Gal */
/* decode1.cl<.f> b,c,dst */
  {(unsigned char *)"decode1.cl%>%.f+\005+\006+\017 %b,%c,%\220%\14%(", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* fbclr<.f> b,b,c,dst,size */
  {(unsigned char *)"fbclr%>%.f %b,%b,%c,%\220,%\222%\14%(", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* decode1<.f> b,b,c,dst,size */
  {(unsigned char *)"decode1%>%.f+\006+\017 %b,%b,%c,%\220,%\222%\14%(", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* fbset<.f> b,b,c,dst,size */
  {(unsigned char *)"fbset%>%.f+\017 %b,%b,%c,%\220,%\222%\14%(", 0xf81f, 0x4803, ARCOMPACT, 0, 0 ,0,0},
/* encode0<.f> b,c,src,size */
  {(unsigned char *)"encode0%>%.f %b,%c,%\220,%\222%(", 0xf81f, 0x4804, ARCOMPACT, 0, 0 ,0,0},
/* encode1<.f> b,c,src,size */
  {(unsigned char *)"encode1%>+\017%.f %b,%c,%\220,%\222%(", 0xf81f, 0x4804, ARCOMPACT, 0, 0 ,0,0},
#endif
/* qcmp.ar.f b,b,c,src2_pos,size,m1,m2,m3 */
  {(unsigned char *)"qcmp.ar%>+\001+\002+\003%.f %b,%b,%c,%\232,%\355,%\356,%\357,%\234%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.ar.f b,b,c,src2_pos,size,m1,m2 */
  {(unsigned char *)"qcmp.ar%>+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355,%\356,%\357%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.ar.f b,b,c,src2_pos,size,m1 */
  {(unsigned char *)"qcmp.ar%>+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355,%\356%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.ar.f b,b,c,src2_pos,size */
  {(unsigned char *)"qcmp.ar%>+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
 /* qcmp.al.f b,b,c,src2_pos,size,m1,m2,m3 */
  {(unsigned char *)"qcmp.al%>+\000+\001+\002+\003%.f %b,%b,%c,%\232,%\355,%\356,%\357,%\234%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.al.f b,b,c,src2_pos,size,m1,m2 */
  {(unsigned char *)"qcmp.al%>+\000+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355,%\356,%\357%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.al.f b,b,c,src2_pos,size,m1 */
  {(unsigned char *)"qcmp.al%>+\000+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355,%\356%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* qcmp.al.f b,b,c,src2_pos,size */
  {(unsigned char *)"qcmp.al%>+\000+\001+\002+\003+\005+\006+\007+\010%.f %b,%b,%c,%\232,%\355%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calcsd<.f><.xd> b,b,c,size */
  {(unsigned char *)"calcsd%>%.f%.\364+\004 %b,%b,%c,%\363%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calcsd<.xd><.f> b,b,c,size */
  {(unsigned char *)"calcsd%>%.\364%.f+\004 %b,%b,%c,%\363%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calcbsd<.f><.xd> b,b,c */
  {(unsigned char *)"calcbsd%>%.f%.\364+\004+\005 %b,%b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calcbsd<.xd><.f> b,b,c */
  {(unsigned char *)"calcbsd%>%.\364%.f+\004+\005 %b,%b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calckey<.f><.xd> b,b,c */
  {(unsigned char *)"calckey%>%.f%.\364+\004+\006 %b,%b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* calckey<.xd><.f> b,b,c */
  {(unsigned char *)"calckey%>%.\364%.f+\004+\006 %b,%b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/******************************************/
/* dctcp b,c*/
  {(unsigned char *)"dctcp %#,%C", 0xf8ff003f, 0x382f0000, ARCOMPACT, 0, 0 ,0,0},
/* dcip a,b,i0,i1,i2,i3 */
  {(unsigned char *)"dcip%Q %A,%B,%\206,%\211,%\341,%\217" , 0xf8ff0fc0, 0x38290f80, ARCOMPACT, 0, 0 ,0,0},
/* dcip a,b,c */
  {(unsigned char *)"dcip %A,%B,%C" , 0xf8ff0000, 0x38290000, ARCOMPACT, 0, 0 ,0,0},
/* dcip b,c*/
  {(unsigned char *)"dcip %#,%C" , 0xf8ff003f, 0x382f0001, ARCOMPACT, 0, 0 ,0,0},
/* dcet b,c,t0,t1 */
  {(unsigned char *)"dcet%Q %A,%B,%\236,%\237" , 0xf8ff8fc0, 0x38200f80, ARCOMPACT, 0, 0 ,0,0},
/* dcet a,b,c */
  {(unsigned char *)"dcet %A,%B,%C" , 0xf8ff80000, 0x38200000, ARCOMPACT, 0, 0 ,0,0},
/* dcet b,c*/
  {(unsigned char *)"dcet %#,%C" , 0xf8ff003f, 0x382f0002, ARCOMPACT, 0, 0 ,0,0},
/* lbdsize<.f> b,c*/
  {(unsigned char *)"lbdsize%.f %#,%C%F" , 0xf8ff003f, 0x382f0005, ARCOMPACT, 0, 0 ,0,0},
/* getsti %b,[cm:c] */
  {(unsigned char *)"getsti %#,[cm:%C]" , 0xf8ff803f, 0x382f0024, ARCOMPACT, 0, 0 ,0,0},
/* getsti 0,[cm:c] */
  {(unsigned char *)"getsti 0,[cm:%C]" , 0xfffff03f, 0x3e2f7024, ARCOMPACT, 0, 0 ,0,0},
/* getrtc %b,[cm:c] */
  {(unsigned char *)"getrtc %#,[cm:%C]" , 0xf8ff803f, 0x382f0025, ARCOMPACT, 0, 0 ,0,0},
/* getrtc 0,[cm:c] */
  {(unsigned char *)"getrtc 0,[cm:%C]" , 0xfffff03f, 0x3e2f7025, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* tr<.f> a,b,c*/
  {(unsigned char *)"tr%.f %A,%B,%C%F" , 0xf8ff0000, 0x38210000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> a,b,u6 */
  {(unsigned char *)"tr%.f %A,%B,%u%F" , 0xf8ff0000, 0x38610000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> b,b,s12 */
  {(unsigned char *)"tr%.f %#,%B,%K%F" , 0xf8ff0000, 0x38A10000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> a,b,limm */
  {(unsigned char *)"tr%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38210f80, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> a,limm,c */
  {(unsigned char *)"tr%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e217000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> a,limm,u6*/
  {(unsigned char *)"tr%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e617000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> a,limm,limm */
  {(unsigned char *)"tr%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e217f80, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,b,c*/
  {(unsigned char *)"tr%.f 0,%B,%C%F", 0xf8ff003f, 0x3821003e, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,b,u6*/
  {(unsigned char *)"tr%.f 0,%B,%u%F", 0xf8ff003f, 0x3861003e, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,b,limm*/
  {(unsigned char *)"tr%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x38210fbe, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,limm,c*/
  {(unsigned char *)"tr%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e21703e, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,limm,u6*/
  {(unsigned char *)"tr%.f%Q 0,%L,%u%F", 0xffff7000, 0x3ea17000, ARCOMPACT, 0, 0 ,0,0},
/* tr<.f> 0,limm,s12*/
  {(unsigned char *)"tr%.f%Q 0,%L,%K%F", 0xffff7000, 0x3ea17000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* utf8<.f> a,b,c*/
  {(unsigned char *)"utf8%.f %A,%B,%C%F" , 0xf8ff0000, 0x38220000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> a,b,u6 */
  {(unsigned char *)"utf8%.f %A,%B,%u%F" , 0xf8ff0000, 0x38620000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> b,b,s12 */
  {(unsigned char *)"utf8%.f %#,%B,%K%F" , 0xf8ff0000, 0x38A20000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> a,b,limm */
  {(unsigned char *)"utf8%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38220f80, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> a,limm,c */
  {(unsigned char *)"utf8%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e227000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> a,limm,u6*/
  {(unsigned char *)"utf8%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e627000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> a,limm,limm */
  {(unsigned char *)"utf8%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e227f80, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,b,c*/
  {(unsigned char *)"utf8%.f 0,%B,%C%F", 0xf8ff003f, 0x3822003e, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,b,u6*/
  {(unsigned char *)"utf8%.f 0,%B,%u%F", 0xf8ff003f, 0x3862003e, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,b,limm*/
  {(unsigned char *)"utf8%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x38220fbe, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,limm,c*/
  {(unsigned char *)"utf8%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e22703e, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,limm,u6*/
  {(unsigned char *)"utf8%.f%Q 0,%L,%u%F", 0xffff7000, 0x3ea27000, ARCOMPACT, 0, 0 ,0,0},
/* utf8<.f> 0,limm,s12*/
  {(unsigned char *)"utf8%.f%Q 0,%L,%K%F", 0xffff7000, 0x3ea27000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* hash a,b,c,width,perm,nonlinear,basemat */
  {(unsigned char *)"hash %\270,%\272,%\271,%\276,%\274,%\275,%\273", 0xf81f0000, 0x58180000, ARCOMPACT, 0, 0 ,0,0},
/* hash.p0-3 a,b,c,width,len,offset,basemat */
  {(unsigned char *)"hash.p0 %\270,%\272,%\271,%\276,%\257,%\273,%\275", 0xf81f0000, 0x58190000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"hash.p1 %\270,%\272,%\271,%\276,%\257,%\273,%\275", 0xf81f0000, 0x581a0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"hash.p2 %\270,%\272,%\271,%\276,%\257,%\273,%\275", 0xf81f0000, 0x581b0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"hash.p3 %\270,%\272,%\271,%\276,%\257,%\273,%\275", 0xf81f0000, 0x581c0000, ARCOMPACT, 0, 0 ,0,0},
/* e4by a,b,c,index0,index1,index2,index3 */
  {(unsigned char *)"e4by %\270,%\272,%\271,%\300,%\277,%\274,%\273", 0xf81f0000, 0x581d0000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* addf<.f> a,b,c*/
  {(unsigned char *)"addf%.f %A,%B,%C%F" , 0xf8ff0000, 0x38230000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> a,b,u6 */
  {(unsigned char *)"addf%.f %A,%B,%u%F" , 0xf8ff0000, 0x38630000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> b,b,s12 */
  {(unsigned char *)"addf%.f %#,%B,%K%F" , 0xf8ff0000, 0x38A30000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> a,b,limm */
  {(unsigned char *)"addf%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38230f80, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> a,limm,c */
  {(unsigned char *)"addf%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e237000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> a,limm,u6*/
  {(unsigned char *)"addf%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e637000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> a,limm,limm */
  {(unsigned char *)"addf%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e237f80, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,b,c*/
  {(unsigned char *)"addf%.f 0,%B,%C%F", 0xf8ff003f, 0x3823003e, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,b,u6*/
  {(unsigned char *)"addf%.f 0,%B,%u%F", 0xf8ff003f, 0x3863003e, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,b,limm*/
  {(unsigned char *)"addf%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x38230fbe, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,limm,c*/
  {(unsigned char *)"addf%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e23703e, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,limm,u6*/
  {(unsigned char *)"addf%.f%Q 0,%L,%u%F", 0xffff7000, 0x3ea37000, ARCOMPACT, 0, 0 ,0,0},
/* addf<.f> 0,limm,s12*/
  {(unsigned char *)"addf%.f%Q 0,%L,%K%F", 0xffff7000, 0x3ea37000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* ldbit.di<.cl>     a,[b,c] */
  {(unsigned char *)"ldbit.di %A,[%g,%C]%1", 0xf8fe8000, 0x20368000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl %A,[%g,%C]%1", 0xf8ff8000, 0x20378000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di %A,[%g,%C]%1", 0xf8ff8000, 0x20378000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[b] */
  {(unsigned char *)"ldbit.di %A,[%g]%1", 0xf8ff8f80, 0x10000980, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl %A,[%g]%1", 0xf8ff8fc0, 0x100009c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di %A,[%g]%1", 0xf8ff8fc0, 0x100009c0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[b,s9] */
  {(unsigned char *)"ldbit.di %A,[%g,%o]%1", 0xf8000f80, 0x10000980, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl %A,[%g,%o]%1", 0xf8000fc0, 0x100009c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di %A,[%g,%o]%1", 0xf8000fc0, 0x100009c0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[b,limm] */
  {(unsigned char *)"ldbit.di%Q %A,[%g,%L]%1", 0xf8fe0fc0, 0x20368f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20378f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20378f80, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[limm,c] */
  {(unsigned char *)"ldbit.di%Q %A,[%L,%C]%1", 0xfffef000, 0x2636f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl%Q %A,[%L,%C]%1", 0xfffff000, 0x2637f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di%Q %A,[%L,%C]%1", 0xfffff000, 0x2637f000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[limm,s9] */
  {(unsigned char *)"ldbit.di%Q %A,[%L,%o]%1", 0xff007f80, 0x16007980, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl%Q %A,[%L,%o]%1", 0xff007fc0, 0x160079c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di%Q %A,[%L,%o]%1", 0xff007fc0, 0x160079c0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.di<.cl>     a,[limm] */
  {(unsigned char *)"ldbit.di%Q %A,[%L]%3", 0xffffff80, 0x16007980, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.di.cl%Q %A,[%L]%3", 0xffffffc0, 0x160079c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.cl.di%Q %A,[%L]%3", 0xffffffc0, 0x160079c0, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* ldbit.x2.di<.cl>     a,[b,c] */
  {(unsigned char *)"ldbit.x2.di %A,[%g,%C]%1", 0xf8fe8000, 0x20768000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl %A,[%g,%C]%1", 0xf8ff8000, 0x20778000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di %A,[%g,%C]%1", 0xf8ff8000, 0x20778000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[b] */
  {(unsigned char *)"ldbit.x2.di %A,[%g]%1", 0xf8ff8f80, 0x10000b80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl %A,[%g]%1", 0xf8ff8fc0, 0x10000bc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di %A,[%g]%1", 0xf8ff8fc0, 0x10000bc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[b,s9] */
  {(unsigned char *)"ldbit.x2.di %A,[%g,%o]%1", 0xf8000f80, 0x10000b80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl %A,[%g,%o]%1", 0xf8000fc0, 0x10000bc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di %A,[%g,%o]%1", 0xf8000fc0, 0x10000bc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[b,limm] */
  {(unsigned char *)"ldbit.x2.di%Q %A,[%g,%L]%1", 0xf8fe0fc0, 0x20768f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20778f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20778f80, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[limm,c] */
  {(unsigned char *)"ldbit.x2.di%Q %A,[%L,%C]%1", 0xfffef000, 0x2676f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl%Q %A,[%L,%C]%1", 0xfffff000, 0x2677f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di%Q %A,[%L,%C]%1", 0xfffff000, 0x2677f000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[limm,s9] */
  {(unsigned char *)"ldbit.x2.di%Q %A,[%L,%o]%1", 0xff007f80, 0x16007b80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl%Q %A,[%L,%o]%1", 0xff007fc0, 0x16007bc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di%Q %A,[%L,%o]%1", 0xff007fc0, 0x16007bc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x2.di<.cl>     a,[limm] */
  {(unsigned char *)"ldbit.x2.di%Q %A,[%L]%3", 0xffffff80, 0x16007b80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.di.cl%Q %A,[%L]%3", 0xffffffc0, 0x16007bc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x2.cl.di%Q %A,[%L]%3", 0xffffffc0, 0x16007bc0, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* ldbit.x4.di<.cl>     a,[b,c] */
  {(unsigned char *)"ldbit.x4.di %A,[%g,%C]%1", 0xf8fe8000, 0x20b68000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl %A,[%g,%C]%1", 0xf8ff8000, 0x20b78000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di %A,[%g,%C]%1", 0xf8ff8000, 0x20b78000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[b] */
  {(unsigned char *)"ldbit.x4.di %A,[%g]%1", 0xf8ff8f80, 0x10000d80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl %A,[%g]%1", 0xf8ff8fc0, 0x10000dc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di %A,[%g]%1", 0xf8ff8fc0, 0x10000dc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[b,s9] */
  {(unsigned char *)"ldbit.x4.di %A,[%g,%o]%1", 0xf8000f80, 0x10000d80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl %A,[%g,%o]%1", 0xf8000fc0, 0x10000dc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di %A,[%g,%o]%1", 0xf8000fc0, 0x10000dc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[b,limm] */
  {(unsigned char *)"ldbit.x4.di%Q %A,[%g,%L]%1", 0xf8fe0fc0, 0x20b68f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20b78f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di%Q %A,[%g,%L]%1", 0xf8ff0fc0, 0x20b78f80, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[limm,c] */
  {(unsigned char *)"ldbit.x4.di%Q %A,[%L,%C]%1", 0xfffef000, 0x26b6f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl%Q %A,[%L,%C]%1", 0xfffff000, 0x26b7f000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di%Q %A,[%L,%C]%1", 0xfffff000, 0x26b7f000, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[limm,s9] */
  {(unsigned char *)"ldbit.x4.di%Q %A,[%L,%o]%1", 0xff007f80, 0x16007d80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl%Q %A,[%L,%o]%1", 0xff007fc0, 0x16007dc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di%Q %A,[%L,%o]%1", 0xff007fc0, 0x16007dc0, ARCOMPACT, 0, 0 ,0,0},
/* ldbit.x4.di<.cl>     a,[limm] */
  {(unsigned char *)"ldbit.x4.di%Q %A,[%L]%3", 0xffffff80, 0x16007d80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.di.cl%Q %A,[%L]%3", 0xffffffc0, 0x16007dc0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ldbit.x4.cl.di%Q %A,[%L]%3", 0xffffffc0, 0x16007dc0, ARCOMPACT, 0, 0 ,0,0},
  /****************************/


/* schd.rd */
  {(unsigned char *)"schd.rd", 0xffffffff , 0x3e6f7084, ARCOMPACT, 0, 0 ,0,0},
/* schd.wft */
  {(unsigned char *)"schd.wft", 0xffffffff , 0x3e6f7044, ARCOMPACT, 0, 0 ,0,0},
/* schd.rw */
  {(unsigned char *)"schd.rw", 0xffffffff , 0x3e6f7004, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   a,[cm:b],b,c */
  {(unsigned char *)"bdalc %A,[cm:%B],%B,%C" , 0xf8ff0000, 0x38100000, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   a,[cm:b],b,IB,NumOfBuff  */
  {(unsigned char *)"bdalc %A,[cm:%B],%B,%\305,%\306" , 0xf8ff0800, 0x38500800, ARCOMPACT, 0, 0 ,0,0},
/* sbdalc   a,b,IB  */
  {(unsigned char *)"sbdalc %A,%B,%\305" , 0xf8ff09c0, 0x38500040, ARCOMPACT, 0, 0 ,0,0},

/* bdalc   0,[cm:b],b,c */
  {(unsigned char *)"bdalc 0,[cm:%B],%B,%C" , 0xf8ff003f, 0x3810003e, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   0,[cm:b],b,IB,NumOfBuff  */
  {(unsigned char *)"bdalc 0,[cm:%B],%B,%\305,%\306" , 0xf8ff083f, 0x3850083e, ARCOMPACT, 0, 0 ,0,0},
/* sbdalc   0,b,IB  */
  {(unsigned char *)"sbdalc 0,%B,%\305" , 0xf8ff09ff, 0x3850007e, ARCOMPACT, 0, 0 ,0,0},

/* bdalc   a,b,c  */
  {(unsigned char *)"bdalc %A,%B,%C" , 0xf8ff0000, 0x38100000, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   a,b,IB,NumOfBuff  */
  {(unsigned char *)"bdalc %A,%B,%\305,%\306" , 0xf8ff0800, 0x38500800, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   a,b,IB  */
  {(unsigned char *)"bdalc %A,%B,%\305" , 0xf8ff09c0, 0x38500040, ARCOMPACT, 0, 0 ,0,0},

/* bdalc   0,b,c  */
  {(unsigned char *)"bdalc 0,%B,%C" , 0xf8ff003f, 0x3810003e, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   0,b,IB,NumOfBuff  */
  {(unsigned char *)"bdalc 0,%B,%\305,%\306" , 0xf8ff083f, 0x3850083e, ARCOMPACT, 0, 0 ,0,0},
/* bdalc   0,b,IB  */
  {(unsigned char *)"bdalc 0,%B,%\305" , 0xf8ff09ff, 0x3850007e, ARCOMPACT, 0, 0 ,0,0},

/* bdfre a,[cm:b],b,c*/
  {(unsigned char *)"bdfre %A,[cm:%B],%B,%C" , 0xf8ff0000, 0x38110000, ARCOMPACT, 0, 0 ,0,0},
/* bdfre a,[cm:b],b,NumOfBuff*/
  {(unsigned char *)"bdfre %A,[cm:%B],%B,%\306", 0xf8ff0000, 0x38510000, ARCOMPACT, 0, 0 ,0,0},
/* bdfre 0,[cm:b],b,c*/
  {(unsigned char *)"bdfre 0,[cm:%B],%B,%C" , 0xf8ff003f, 0x3811003e, ARCOMPACT, 0, 0 ,0,0},
/* bdfre 0,[cm:b],b,NumOfBuff*/
  {(unsigned char *)"bdfre 0,[cm:%B],%B,%\306", 0xf8ff003f, 0x3851003e, ARCOMPACT, 0, 0 ,0,0},

/* bdfre a,b,c*/
  {(unsigned char *)"bdfre %A,%B,%C" , 0xf8ff0000, 0x38110000, ARCOMPACT, 0, 0 ,0,0},
/* bdfre 0,b,c*/
  {(unsigned char *)"bdfre 0,%B,%C" , 0xf8ff003f, 0x3811003e, ARCOMPACT, 0, 0 ,0,0},
/* bdfre a,b,NumOfBuff*/
  {(unsigned char *)"bdfre %A,%B,%\306", 0xf8ff0000, 0x38510000, ARCOMPACT, 0, 0 ,0,0},
/* bdfre 0,b,NumOfBuff*/
  {(unsigned char *)"bdfre 0,%B,%\306", 0xf8ff003f, 0x3851003e, ARCOMPACT, 0, 0 ,0,0},

/* jobget 0,[cjid:c]*/
    {(unsigned char *)"jobget 0,[cjid:%C]", 0xffff703f, 0x3e2f7020, ARCOMPACT, 0, 0 ,0,0},
/* jobget.cl 0,[cjid:c]*/
    {(unsigned char *)"jobget.cl 0,[cjid:%C]", 0xffff703f, 0x3e2f7021, ARCOMPACT, 0, 0 ,0,0},
/* jobget 0,c*/
  {(unsigned char *)"jobget 0,%C", 0xffff703f, 0x3e2f7020, ARCOMPACT, 0, 0 ,0,0},
/* jobget.cl 0,c*/
  {(unsigned char *)"jobget.cl 0,%C", 0xffff703f, 0x3e2f7021, ARCOMPACT, 0, 0 ,0,0},
/* jobdn a,[cjid:b],b,c */
  {(unsigned char *)"jobdn %A,[cjid:%B],%B,%C" , 0xf8ff0000, 0x38120000, ARCOMPACT, 0, 0 ,0,0},
/* jobdn a,[cjid:b],b,next_dst */
  {(unsigned char *)"jobdn %A,[cjid:%B],%B,%\353" , 0xf8ff0000, 0x38520000, ARCOMPACT, 0, 0 ,0,0},
/* jobdn 0,[cjid:b],b,c */
  {(unsigned char *)"jobdn 0,[cjid:%B],%B,%C" , 0xf8ff003f, 0x3812003e, ARCOMPACT, 0, 0 ,0,0},
/* jobdn 0,[cjid:b],b,next_dst */
  {(unsigned char *)"jobdn 0,[cjid:%B],%B,%\353" , 0xf8ff003f, 0x3852003e, ARCOMPACT, 0, 0 ,0,0},
/* jobdn a,b,c*/
  {(unsigned char *)"jobdn %A,%B,%C" , 0xf8ff0000, 0x38120000, ARCOMPACT, 0, 0 ,0,0},
/* jobdn 0,b,c*/
  {(unsigned char *)"jobdn 0,%B,%C" , 0xf8ff003f, 0x3812003e, ARCOMPACT, 0, 0 ,0,0},
/* jobdn a,b,NumOfBuff*/
  {(unsigned char *)"jobdn %A,%B,%\353", 0xf8ff0000, 0x38520000, ARCOMPACT, 0, 0 ,0,0},
/* jobdn 0,b,NumOfBuff*/
  {(unsigned char *)"jobdn 0,%B,%\353", 0xf8ff003f, 0x3852003e, ARCOMPACT, 0, 0 ,0,0},
/* jobalc a.[cm:b],b,c */
  {(unsigned char *)"jobalc %A,[cm:%B],%B,%C", 0xf8ff8000, 0x381f0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"jobalc 0,[cm:%B],%B,%C", 0xf8ff803f, 0x381f003e, ARCOMPACT, 0, 0 ,0,0},
/* jobalc a.[cm:b],b,NOJ */
  {(unsigned char *)"jobalc %A,[cm:%B],%B,%\226", 0xf8ff8000, 0x385f0800, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"jobalc 0,[cm:%B],%B,%\226", 0xf8ff803f, 0x385f083e, ARCOMPACT, 0, 0 ,0,0},
/* sjobalc a,b*/
  {(unsigned char *)"sjobalc %A,%B", 0xf8ff8000, 0x385f0040, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"sjobalc 0,%B", 0xf8ff803f, 0x385f007e, ARCOMPACT, 0, 0 ,0,0},
/*********************************************************/
/* ldjob a,b,c*/
  {(unsigned char *)"ldjob %A,%B,%C" , 0xf8ff0000, 0x38130000, ARCOMPACT, 0, 0 ,0,0},
/* ldjob 0,b,c*/
  {(unsigned char *)"ldjob 0,%B,%C" , 0xf8ff003f, 0x3813003e, ARCOMPACT, 0, 0 ,0,0},
/* stjob a,b,c*/
  {(unsigned char *)"stjob %A,%B,%C" , 0xf8ff0000, 0x38140000, ARCOMPACT, 0, 0 ,0,0},
/* stjob 0,b,c*/
  {(unsigned char *)"stjob 0,%B,%C" , 0xf8ff003f, 0x3814003e, ARCOMPACT, 0, 0 ,0,0},

/* dcmac a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmac%Q+\032+\035 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\032+\035 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmac a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcmac%Q+\031+\032+\035 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\031+\032+\035 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmac a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmac%Q+\030+\031+\032+\035 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\030+\031+\032+\035 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmac a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmac%Q+\035 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\035 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmac a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcmac%Q+\031+\035 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\031+\035 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmac a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmac%Q+\030+\031+\035 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmac%Q+\030+\031+\035 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmacl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmacl%Q+\032+\035+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\032+\035+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmacl a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcmacl%Q+\031+\032+\035+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\031+\032+\035+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmacl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmacl%Q+\030+\031+\032+\035+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\030+\031+\032+\035+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmacl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmacl%Q+\035+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\035+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmacl a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcmacl%Q+\031+\035+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\031+\035+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmacl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmacl%Q+\030+\031+\035+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmacl%Q+\030+\031+\035+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv4 a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv4%Q %\310,[cm:%\311],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q 0,[cm:%\311],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4 a,[cm:b],[cm:A],c,size */
  {(unsigned char *)"dcipv4%Q+\031 %\310,[cm:%\311],[cm:%\236],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q+\031 0,[cm:%\311],[cm:%\236],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4 a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv4%Q+\030+\031 %\310,[cm:%\236],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q+\030+\031 0,[cm:%\236],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv4 a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv4%Q+\032 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q+\032 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4 a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcipv4%Q+\031+\032 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q+\031+\032 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4 a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv4%Q+\030+\031+\032 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4%Q+\030+\031+\032 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv4l a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv4l%Q+\037 %\310,[cm:%\311],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\037 0,[cm:%\311],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4l a,[cm:b],[cm:A],c,size */
  {(unsigned char *)"dcipv4l%Q+\031+\037 %\310,[cm:%\311],[cm:%\236],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\031+\037 0,[cm:%\311],[cm:%\236],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4l a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv4l%Q+\030+\031+\037 %\310,[cm:%\236],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\030+\031+\037 0,[cm:%\236],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv4l a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv4l%Q+\032+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\032+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4l a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcipv4l%Q+\031+\032+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\031+\032+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv4l a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv4l%Q+\030+\031+\032+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv4l%Q+\030+\031+\032+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv6 a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv6%Q+\033 %\310,[cm:%\311],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\033 0,[cm:%\311],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6 a,[cm:b],[cm:A],c,size */
  {(unsigned char *)"dcipv6%Q+\031+\033 %\310,[cm:%\311],[cm:%\236],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\031+\033 0,[cm:%\311],[cm:%\236],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6 a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv6%Q+\030+\031+\033 %\310,[cm:%\236],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\030+\031+\033 0,[cm:%\236],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv6 a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv6%Q+\032+\033 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\032+\033 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6 a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcipv6%Q+\031+\032+\033 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\031+\032+\033 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6 a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv6%Q+\030+\031+\032+\033 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6%Q+\030+\031+\032+\033 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv6l a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv6l%Q+\033+\037 %\310,[cm:%\311],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\033+\037 0,[cm:%\311],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6l a,[cm:b],[cm:A],c,size */
  {(unsigned char *)"dcipv6l%Q+\031+\033+\037 %\310,[cm:%\311],[cm:%\236],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\031+\033+\037 0,[cm:%\311],[cm:%\236],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6l a,[cm:b],[cm:b],c,size */
  {(unsigned char *)"dcipv6l%Q+\030+\031+\033+\037 %\310,[cm:%\236],[cm:%\311],%\312,%\262", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\030+\031+\033+\037 0,[cm:%\236],[cm:%\311],%\312,%\262", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcipv6l a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv6l%Q+\032+\033+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\032+\033+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6l a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcipv6l%Q+\031+\032+\033+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\031+\032+\033+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcipv6l a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcipv6l%Q+\030+\031+\032+\033+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcipv6l%Q+\030+\031+\032+\033+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmpls a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmpls%Q+\032+\033+\035 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\032+\033+\035 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmpls a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcmpls%Q+\031+\032+\033+\035 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\031+\032+\033+\035 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmpls a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmpls%Q+\030+\031+\032+\033+\035 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\030+\031+\032+\033+\035 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmpls a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmpls%Q+\033+\035 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\033+\035 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmpls a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcmpls%Q+\031+\033+\035 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\031+\033+\035 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmpls a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmpls%Q+\030+\031+\033+\035 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmpls%Q+\030+\031+\033+\035 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmplsl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmplsl%Q+\032+\033+\035+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\032+\033+\035+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmplsl a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcmplsl%Q+\031+\032+\033+\035+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\031+\032+\033+\035+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmplsl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmplsl%Q+\030+\031+\032+\033+\035+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\030+\031+\032+\033+\035+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmplsl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmplsl%Q+\033+\035+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\033+\035+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmplsl a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcmplsl%Q+\031+\033+\035+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\031+\033+\035+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmplsl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmplsl%Q+\030+\031+\033+\035+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmplsl%Q+\030+\031+\033+\035+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcsmpls a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcsmpls%Q+\032+\036 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\032+\036 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmpls a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcsmpls%Q+\031+\032+\036 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\031+\032+\036 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmpls a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcsmpls%Q+\030+\031+\032+\036 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\030+\031+\032+\036 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcsmpls a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcsmpls%Q+\036 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\036 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmpls a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcsmpls%Q+\031+\036 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\031+\036 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmpls a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcsmpls%Q+\030+\031+\036 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmpls%Q+\030+\031+\036 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcsmplsl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcsmplsl%Q+\032+\036+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\032+\036+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmplsl a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcsmplsl%Q+\031+\032+\036+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\031+\032+\036+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmplsl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcsmplsl%Q+\030+\031+\032+\036+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\030+\031+\032+\036+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcsmplsl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcsmplsl%Q+\036+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\036+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmplsl a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcsmplsl%Q+\031+\036+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\031+\036+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcsmplsl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcsmplsl%Q+\030+\031+\036+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsmplsl%Q+\030+\031+\036+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcudpl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcudpl%Q+\032+\033+\034+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\032+\033+\034+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcudpl a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcudpl%Q+\031+\032+\033+\034+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\031+\032+\033+\034+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcudpl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcudpl%Q+\030+\031+\032+\033+\034+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\030+\031+\032+\033+\034+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcudpl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcudpl%Q+\033+\034+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\033+\034+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcudpl a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcudpl%Q+\031+\033+\034+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\031+\033+\034+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcudpl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcudpl%Q+\030+\031+\033+\034+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcudpl%Q+\030+\031+\033+\034+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dctcpl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dctcpl%Q+\032+\034+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\032+\034+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dctcpl a,[cm:b],[cm:A],c */
  {(unsigned char *)"dctcpl%Q+\031+\032+\034+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\031+\032+\034+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dctcpl a,[cm:b],[cm:b],c */
  {(unsigned char *)"dctcpl%Q+\030+\031+\032+\034+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\030+\031+\032+\034+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dctcpl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dctcpl%Q+\034+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\034+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dctcpl a,[cm:b],[cm:A],size */
  {(unsigned char *)"dctcpl%Q+\031+\034+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\031+\034+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dctcpl a,[cm:b],[cm:b],size */
  {(unsigned char *)"dctcpl%Q+\030+\031+\034+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dctcpl%Q+\030+\031+\034+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcgrel a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcgrel%Q+\032+\033+\034+\035+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\032+\033+\034+\035+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcgrel a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcgrel%Q+\031+\032+\033+\034+\035+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\031+\032+\033+\034+\035+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcgrel a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcgrel%Q+\030+\031+\032+\033+\034+\035+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\030+\031+\032+\033+\034+\035+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcgrel a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcgrel%Q+\033+\034+\035+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\033+\034+\035+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcgrel a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcgrel%Q+\031+\033+\034+\035+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\031+\033+\034+\035+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcgrel a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcgrel%Q+\030+\031+\033+\034+\035+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcgrel%Q+\030+\031+\033+\034+\035+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmiml a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmiml%Q+\032+\034+\035+\037 %\310,[cm:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\032+\034+\035+\037 0,[cm:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmiml a,[cm:b],[cm:A],c */
  {(unsigned char *)"dcmiml%Q+\031+\032+\034+\035+\037 %\310,[cm:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\031+\032+\034+\035+\037 0,[cm:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmiml a,[cm:b],[cm:b],c */
  {(unsigned char *)"dcmiml%Q+\030+\031+\032+\034+\035+\037 %\310,[cm:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\030+\031+\032+\034+\035+\037 0,[cm:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/* dcmiml a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmiml%Q+\034+\035+\037 %\310,[cm:%\311],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\034+\035+\037 0,[cm:%\311],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmiml a,[cm:b],[cm:A],size */
  {(unsigned char *)"dcmiml%Q+\031+\034+\035+\037 %\310,[cm:%\311],[cm:%\236],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\031+\034+\035+\037 0,[cm:%\311],[cm:%\236],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},
/* dcmiml a,[cm:b],[cm:b],size */
  {(unsigned char *)"dcmiml%Q+\030+\031+\034+\035+\037 %\310,[cm:%\236],[cm:%\311],%\262%\354", 0xf80007ff, 0x500007c0, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcmiml%Q+\030+\031+\034+\035+\037 0,[cm:%\236],[cm:%\311],%\262%\354", 0xffe007ff, 0x57c007c0, ARCOMPACT, 0, 0 ,0,0},

/******************************************************/
/* mmnt 0,[b],mnt_code */
  {(unsigned char *)"mmnt%Q+\003 0,[%\311],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[b],c */
  {(unsigned char *)"mmnt%Q+\040 0,[%\311],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[xa:b],mnt_code */
  {(unsigned char *)"mmnt%Q+\000+\003 0,[xa:%\311],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[xa:b],c */
  {(unsigned char *)"mmnt%Q+\000 0,[xa:%\311],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b, entry_size, offset], mnt_code */
  {(unsigned char *)"mmnt%Q+\000+\001+\003+\004+\005 0,[sd:%\311,%\254,%\255],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b, entry_size, offset], c */
  {(unsigned char *)"mmnt%Q+\000+\001+\004+\005 0,[sd:%\311,%\254,%\255],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b,c, offset],mnt_code*/
  {(unsigned char *)"mmnt%Q+\000+\001+\003+\005 0,[sd:%\311,%\312,%\255],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b,c, offset],c*/
  {(unsigned char *)"mmnt%Q+\000+\001+\005 0,[sd:%\311,%\312,%\255],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b, entry_size,c],mnt_code*/
  {(unsigned char *)"mmnt%Q+\000+\001+\003+\004 0,[sd:%\311,%\254,%\312],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/* mmnt 0,[sd:b, entry_size,c],c*/
  {(unsigned char *)"mmnt%Q+\000+\001+\004 0,[sd:%\311,%\254,%\312],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[sd:b,c,c],mnt_code*/
  {(unsigned char *)"mmnt%Q+\000+\001+\003 0,[sd:%\311,%\312,%\312],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[sd:b,c,c],c*/
  {(unsigned char *)"mmnt%Q+\000+\001 0,[sd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,entry_size,offset],mnt_code*/
  {(unsigned char *)"mmnt%Q+\002+\003+\004+\005 0,[xd:%\311,%\254,%\255],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,entry_size,offset],c*/
  {(unsigned char *)"mmnt%Q+\002+\004+\005 0,[xd:%\311,%\254,%\255],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,c,offset],mnt_code*/
  {(unsigned char *)"mmnt%Q+\002+\003+\005 0,[xd:%\311,%\312,%\255],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,c,offset],c*/
  {(unsigned char *)"mmnt%Q+\002+\005 0,[xd:%\311,%\312,%\255],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,entry_size,c],mnt_code*/
  {(unsigned char *)"mmnt%Q+\002+\003+\004 0,[xd:%\311,%\254,%\312],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,entry_size,c],c*/
  {(unsigned char *)"mmnt%Q+\002+\004 0,[xd:%\311,%\254,%\312],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,c,c],mnt_code*/
  {(unsigned char *)"mmnt%Q+\002+\003 0,[xd:%\311,%\312,%\312],%\253", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/*mmnt 0,[xd:b,c,c],c*/
  {(unsigned char *)"mmnt%Q+\002 0,[xd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c5, ARCOMPACT, 0, 0 ,0,0},
/******************************************************/

/* lkpitcm a,[cm:b],[cm:b],c */
  {(unsigned char *)"lkpitcm %A,[cm:%B],[cm:%B],%C" , 0xf8ff0000, 0x380e0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"lkpitcm 0,[cm:%B],[cm:%B],%C" , 0xf8ff003f, 0x380e003e, ARCOMPACT, 0, 0 ,0,0},
/* lkpitcm a,[cm:b],[cm:b],sid,pmask,keysize */
  {(unsigned char *)"lkpitcm%Q %A,[cm:%B],[cm:%B],%\240,%\224,%\344" , 0xf8ff0fc0, 0x380e0f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"lkpitcm%Q 0,[cm:%B],[cm:%B],%\240,%\224,%\344" , 0xf8ff0fff, 0x380e0fbe, ARCOMPACT, 0, 0 ,0,0},
/* lkpetcm a,[cm:b],[cm:b],c */
  {(unsigned char *)"lkpetcm %A,[cm:%B],[cm:%B],%C" , 0xf8ff0000, 0x380f0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"lkpetcm 0,[cm:%B],[cm:%B],%C" , 0xf8ff003f, 0x380f003e, ARCOMPACT, 0, 0 ,0,0},
/* lkpetcm a,[cm:b],[cm:b],sid,ops,keysize,reslen */
  {(unsigned char *)"lkpetcm%Q %A,[cm:%B],[cm:%B],%\240,%\243,%\344,%\217" , 0xf8ff0fc0, 0x380f0f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"lkpetcm%Q 0,[cm:%B],[cm:%B],%\240,%\243,%\344,%\217" , 0xf8ff0fff, 0x380f0fbe, ARCOMPACT, 0, 0 ,0,0},

/******************************************************/
/* lkp_0 a,b,c */
  {(unsigned char *)"lkp_0%Q+\033 %\310,%\311,%\312", 0xf80007ff, 0x500007de, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"lkp_0%Q+\033 0,%\311,%\312", 0xffe007ff, 0x57c007de, ARCOMPACT, 0, 0 ,0,0},
/* upd_0 a,b,c */
  {(unsigned char *)"upd_0%Q+\033 %\310,%\311,%\312", 0xf80007ff, 0x500007dd, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"upd_0%Q+\033 0,%\311,%\312", 0xffe007ff, 0x57c007dd, ARCOMPACT, 0, 0 ,0,0},
/* rmv_0 a,b,c */
  {(unsigned char *)"rmv_0%Q+\033 %\310,%\311,%\312", 0xf80007ff, 0x500007dc, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"rmv_0%Q+\033 0,%\311,%\312", 0xffe007ff, 0x57c007dc, ARCOMPACT, 0, 0 ,0,0},
/* add_0 a,b,c */
  {(unsigned char *)"add_0%Q+\033 %\310,%\311,%\312", 0xf80007ff, 0x500007db, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"add_0%Q+\033 0,%\311,%\312", 0xffe007ff, 0x57c007db, ARCOMPACT, 0, 0 ,0,0},
/* ?crst_0 a,b */
  {(unsigned char *)"scrst_0%Q%\320 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcrst_0%Q+\035 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcrst_0%Q+\036 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?crst_0 0,b */
  {(unsigned char *)"scrst_0%Q%\320 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcrst_0%Q+\035 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcrst_0%Q+\036 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cadd_0 a,b,c */
  {(unsigned char *)"scadd_0%Q+\000 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcadd_0%Q+\000+\035 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcadd_0%Q+\000+\036 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cadd_0 0,b,c */
  {(unsigned char *)"scadd_0%Q+\000 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcadd_0%Q+\000+\035 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcadd_0%Q+\000+\036 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cinc_0 a,b */
  {(unsigned char *)"scinc_0%Q+\001 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcinc_0%Q+\001+\035 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcinc_0%Q+\001+\036 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cinc_0 0,b */
  {(unsigned char *)"scinc_0%Q+\001 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcinc_0%Q+\001+\035 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcinc_0%Q+\001+\036 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?csub_0 a,b,c */
  {(unsigned char *)"scsub_0%Q+\000+\001 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsub_0%Q+\000+\001+\035 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcsub_0%Q+\000+\001+\036 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?csub_0 0,b,c */
  {(unsigned char *)"scsub_0%Q+\000+\001 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcsub_0%Q+\000+\001+\035 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcsub_0%Q+\000+\001+\036 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cdec_0 a,b */
  {(unsigned char *)"scdec_0%Q+\002 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcdec_0%Q+\002+\035 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcdec_0%Q+\002+\036 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cdec_0 0,b */
  {(unsigned char *)"scdec_0%Q+\002 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcdec_0%Q+\002+\035 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcdec_0%Q+\002+\036 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cld_0 a,b,c */
  {(unsigned char *)"scld_0%Q+\000+\002 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcld_0%Q+\000+\002+\035 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cld_0 0,b,c */
  {(unsigned char *)"scld_0%Q+\000+\002 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcld_0%Q+\000+\002+\035 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cst_0 a,b,c */
  {(unsigned char *)"scst_0%Q+\001+\002 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcst_0%Q+\001+\002+\035 %\310,%\311,%\312",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
/* ?cld_0 0,b,c */
  {(unsigned char *)"scst_0%Q+\001+\002 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"dcst_0%Q+\001+\002+\035 0,%\311,%\312",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* tbcolor_0 [a,0],b */
  {(unsigned char *)"tbcolor_0%Q+\000+\001+\002+\036 %\310,%\311",0xf800ffff, 0x500007d9, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"tbcolor_0%Q+\000+\001+\002+\036 0,%\311",0xffe0ffff, 0x57c007d9, ARCOMPACT, 0, 0 ,0,0},
/* gets_0 a,c */
  {(unsigned char *)"gets_0%Q+\033 %\310,%\312", 0xf80007ff, 0x500007d7, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"gets_0%Q+\033 0,%\312", 0xffe007ff, 0x57c007d7, ARCOMPACT, 0, 0 ,0,0},
/********************************************************/
/* whash a,[cm:b],c*/
  {(unsigned char *)"whash %A,[cm:%B],%C" , 0xf8ff0000, 0x38150000, ARCOMPACT, 0, 0 ,0,0},
/* whash a,b,size*/
  {(unsigned char *)"whash %A,[cm:%B],%\342", 0xf8ff0000, 0x38550000, ARCOMPACT, 0, 0 ,0,0},
/* whash 0,[cm:b],c*/
  {(unsigned char *)"whash 0,[cm:%B],%C" , 0xf8ff003f, 0x3815003e, ARCOMPACT, 0, 0 ,0,0},
/* whash 0,b,size*/
  {(unsigned char *)"whash 0,[cm:%B],%\342", 0xf8ff003f, 0x3855003e, ARCOMPACT, 0, 0 ,0,0},
/* whash a,b,c*/
  {(unsigned char *)"whash %A,%B,%C" , 0xf8ff0000, 0x38150000, ARCOMPACT, 0, 0 ,0,0},
/* whash 0,b,c*/
  {(unsigned char *)"whash 0,%B,%C" , 0xf8ff003f, 0x3815003e, ARCOMPACT, 0, 0 ,0,0},
/* whash a,b,size*/
  {(unsigned char *)"whash %A,%B,%\342", 0xf8ff0000, 0x38550000, ARCOMPACT, 0, 0 ,0,0},
/* whash 0,b,size*/
  {(unsigned char *)"whash 0,%B,%\342", 0xf8ff003f, 0x3855003e, ARCOMPACT, 0, 0 ,0,0},

/* mcmp<.s><.m> b,[cm:b,O1],[cm:c],size */
  {(unsigned char *)"mcmp%>%.\350%.\216+\017+\016 %b,[cm:%b,%\376],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350+\017+\016 %b,[cm:%b,%\376],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/* mcmp<.s><.m> b,[cm:b,O1],[cm:c],c */
  {(unsigned char *)"mcmp%>%.\350%.\216+\016 %b,[cm:%b,%\376],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350+\016 %b,[cm:%b,%\376],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/* mcmp<.s><.m> b,[cm:b],[cm:c],size */
  {(unsigned char *)"mcmp%>%.\350%.\216+\017+\016 %b,[cm:%b],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350+\017+\016 %b,[cm:%b],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/* mcmp<.s><.m> b,[cm:b],[cm:c],c */
  {(unsigned char *)"mcmp%>%.\350%.\216+\016 %b,[cm:%b],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350+\016 %b,[cm:%b],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/* mcmp<.s><.m> b,[cm:b,b],[cm:c],size */
  {(unsigned char *)"mcmp%>%.\350%.\216+\017 %b,[cm:%b,%b],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350+\017 %b,[cm:%b,%b],[cm:%c],%\344", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/* mcmp<.s><.m> b,[cm:b,b],[cm:c],c */
  {(unsigned char *)"mcmp%>%.\350%.\216 %b,[cm:%b,%b],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"mcmp%>%.\216%.\350 %b,[cm:%b,%b],[cm:%c],%c", 0xf81f, 0x4802, ARCOMPACT, 0, 0 ,0,0},
/*********************************************************/
/* asri 0,c*/
  {(unsigned char *)"asri 0,%B", 0xf8ff8fff, 0x3856003e, ARCOMPACT, 0, 0 ,0,0},
/* asri.core 0,c*/
  {(unsigned char *)"asri.core 0,%B", 0xf8ff8fff, 0x3856007e, ARCOMPACT, 0, 0 ,0,0},
/* asri.clsr 0,c*/
  {(unsigned char *)"asri.clsr 0,%B", 0xf8ff8fff, 0x385600be, ARCOMPACT, 0, 0 ,0,0},
/* asri.all 0,c*/
  {(unsigned char *)"asri.all 0,%B", 0xf8ff8fff, 0x385600fe, ARCOMPACT, 0, 0 ,0,0},
/* asri.gic 0,c*/
  {(unsigned char *)"asri.gic 0,%B", 0xf8ff8fff, 0x3856013e, ARCOMPACT, 0, 0 ,0,0},
/* rspi.gic 0,c*/
  {(unsigned char *)"rspi.gic 0,%B", 0xf8ff8fff, 0x3856017e, ARCOMPACT, 0, 0 ,0,0},

/* wkup.cl*/
  {(unsigned char *)"wkup.cl", 0xf8ff8fff, 0x385b013e, ARCOMPACT, 0, 0 ,0,0},
/* wkup 0, c*/
  {(unsigned char *)"wkup 0,%B", 0xf8ff8fff, 0x385b003e, ARCOMPACT, 0, 0 ,0,0},

/* hwschd.off   b */
  {(unsigned char *)"hwschd.off %B",0xf8ff8fff,0x386f00bf, ARCOMPACT, 0, 0 ,0,0},
/* cnljob   b */
  {(unsigned char *)"cnljob %B",0xf8ff8fff,0x386f00ff, ARCOMPACT, 0, 0 ,0,0},
/* cnljob   0 */
  {(unsigned char *)"cnljob 0",0xf8ff8fff,0x3e6f70ff, ARCOMPACT, 0, 0 ,0,0},

/* hwschd.restore   c */
  {(unsigned char *)"hwschd.restore %C",0xfffff03f,0x3e6f7003, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* dcacl<.f> a,b,c*/
  {(unsigned char *)"dcacl%.f %A,%B,%C%F" , 0xf8ff0000, 0x38250000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> a,b,u6 */
  {(unsigned char *)"dcacl%.f %A,%B,%u%F" , 0xf8ff0000, 0x38650000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> b,b,s12 */
  {(unsigned char *)"dcacl%.f %#,%B,%K%F" , 0xf8ff0000, 0x38A50000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> a,b,limm */
  {(unsigned char *)"dcacl%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38250f80, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> a,limm,c */
  {(unsigned char *)"dcacl%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e257000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> a,limm,u6*/
  {(unsigned char *)"dcacl%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e657000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> a,limm,limm */
  {(unsigned char *)"dcacl%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e257f80, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,b,c*/
  {(unsigned char *)"dcacl%.f 0,%B,%C%F", 0xf8ff003f, 0x3825003e, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,b,u6*/
  {(unsigned char *)"dcacl%.f 0,%B,%u%F", 0xf8ff003f, 0x3865003e, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,b,limm*/
  {(unsigned char *)"dcacl%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x38250fbe, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,limm,c*/
  {(unsigned char *)"dcacl%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e25703e, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,limm,u6*/
  {(unsigned char *)"dcacl%.f%Q 0,%L,%u%F", 0xffff7000, 0x3ea57000, ARCOMPACT, 0, 0 ,0,0},
/* dcacl<.f> 0,limm,s12*/
  {(unsigned char *)"dcacl%.f%Q 0,%L,%K%F", 0xffff7000, 0x3ea57000, ARCOMPACT, 0, 0 ,0,0},
  /****************************/
/****************************/
/* zncv.rd a,b,c*/
  {(unsigned char *)"zncv.rd %A,%B,%C%F" , 0xf8ff0000, 0x38350000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd a,b,u6 */
  {(unsigned char *)"zncv.rd %A,%B,%u%F" , 0xf8ff0000, 0x38750000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd b,b,s12 */
  {(unsigned char *)"zncv.rd %#,%B,%K%F" , 0xf8ff0000, 0x38B50000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd a,b,limm */
  {(unsigned char *)"zncv.rd%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38350f80, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd a,limm,c */
  {(unsigned char *)"zncv.rd%Q %A,%L,%C%F", 0xffff7000, 0x3e357000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd a,limm,u6*/
  {(unsigned char *)"zncv.rd%Q %A,%L,%u%F", 0xffff7000, 0x3e757000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd a,limm,limm */
  {(unsigned char *)"zncv.rd%Q %A,%L,%L%F", 0xffff7fc0, 0x3e357f80, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,b,c*/
  {(unsigned char *)"zncv.rd 0,%B,%C%F", 0xf8ff003f, 0x3835003e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,b,u6*/
  {(unsigned char *)"zncv.rd 0,%B,%u%F", 0xf8ff003f, 0x3875003e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,b,limm*/
  {(unsigned char *)"zncv.rd%Q 0,%B,%L%F", 0xf8ff0fff, 0x38350fbe, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,limm,c*/
  {(unsigned char *)"zncv.rd%Q 0,%L,%C%F", 0xffff703f, 0x3e35703e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,limm,u6*/
  {(unsigned char *)"zncv.rd%Q 0,%L,%u%F", 0xffff7000, 0x3eb57000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.rd 0,limm,s12*/
  {(unsigned char *)"zncv.rd%Q 0,%L,%K%F", 0xffff7000, 0x3eb57000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,b,c*/
  {(unsigned char *)"zncv.wr %A,%B,%C%F" , 0xf8ff0000, 0x38358000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,b,u6 */
  {(unsigned char *)"zncv.wr %A,%B,%u%F" , 0xf8ff0000, 0x38758000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr b,b,s12 */
  {(unsigned char *)"zncv.wr %#,%B,%K%F" , 0xf8ff0000, 0x38B58000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,b,limm */
  {(unsigned char *)"zncv.wr%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38358f80, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,limm,c */
  {(unsigned char *)"zncv.wr%Q %A,%L,%C%F", 0xffff7000, 0x3e35f000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,limm,u6*/
  {(unsigned char *)"zncv.wr%Q %A,%L,%u%F", 0xffff7000, 0x3e75f000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr a,limm,limm */
  {(unsigned char *)"zncv.wr%Q %A,%L,%L%F", 0xffff7fc0, 0x3e35ff80, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,b,c*/
  {(unsigned char *)"zncv.wr 0,%B,%C%F", 0xf8ff003f, 0x3835803e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,b,u6*/
  {(unsigned char *)"zncv.wr 0,%B,%u%F", 0xf8ff003f, 0x3875803e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,b,limm*/
  {(unsigned char *)"zncv.wr%Q 0,%B,%L%F", 0xf8ff0fff, 0x38358fbe, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,limm,c*/
  {(unsigned char *)"zncv.wr%Q 0,%L,%C%F", 0xffff703f, 0x3e35f03e, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,limm,u6*/
  {(unsigned char *)"zncv.wr%Q 0,%L,%u%F", 0xffff7000, 0x3eb5f000, ARCOMPACT, 0, 0 ,0,0},
/* zncv.wr 0,limm,s12*/
  {(unsigned char *)"zncv.wr%Q 0,%L,%K%F", 0xffff7000, 0x3eb5f000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/****************************/
/* hofs<.f> a,b,min_hofs,psbc*/
  {(unsigned char *)"hofs%.f%Q %A,%B,%\225,%\246%F" , 0xf8ff0000, 0x38760000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,b,c*/
  {(unsigned char *)"hofs%.f %A,%B,%C%F" , 0xf8ff0000, 0x38360000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,b,u6 */
  {(unsigned char *)"hofs%.f %A,%B,%u%F" , 0xf8ff0000, 0x38760000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> b,b,s12 */
  {(unsigned char *)"hofs%.f %#,%B,%K%F" , 0xf8ff0000, 0x38B60000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,b,limm */
  {(unsigned char *)"hofs%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x38360f80, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,limm,c */
  {(unsigned char *)"hofs%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e367000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,limm,u6*/
  {(unsigned char *)"hofs%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e767000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> a,limm,limm */
  {(unsigned char *)"hofs%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e367f80, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,b,c*/
  {(unsigned char *)"hofs%.f 0,%B,%C%F", 0xf8ff003f, 0x3836003e, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,b,u6*/
  {(unsigned char *)"hofs%.f 0,%B,%u%F", 0xf8ff003f, 0x3876003e, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,b,limm*/
  {(unsigned char *)"hofs%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x38360fbe, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,limm,c*/
  {(unsigned char *)"hofs%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e36703e, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,limm,u6*/
  {(unsigned char *)"hofs%.f%Q 0,%L,%u%F", 0xffff7000, 0x3eb67000, ARCOMPACT, 0, 0 ,0,0},
/* hofs<.f> 0,limm,s12*/
  {(unsigned char *)"hofs%.f%Q 0,%L,%K%F", 0xffff7000, 0x3eb67000, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* idxalc a,[cm:b],b,c*/
  {(unsigned char *)"idxalc %A,[cm:%B],%B,%C" , 0xf8ff0000, 0x381c0000, ARCOMPACT, 0, 0 ,0,0},
/* idxalc a,[cm:b],b,NumOfBuff*/
  {(unsigned char *)"idxalc %A,[cm:%B],%B,%\306", 0xf8ff0800, 0x385c0800, ARCOMPACT, 0, 0 ,0,0},
/* sidxalc a,b*/
  {(unsigned char *)"sidxalc %A,%B", 0xf8ff0fc0, 0x385c0040, ARCOMPACT, 0, 0 ,0,0},

/* idxalc 0,[cm:b],b,c*/
  {(unsigned char *)"idxalc 0,[cm:%B],%B,%C" , 0xf8ff003f, 0x381c003e, ARCOMPACT, 0, 0 ,0,0},
/* idxalc 0,[cm:b],b,NumOfBuff*/
  {(unsigned char *)"idxalc 0,[cm:%B],%B,%\306", 0xf8ff083f, 0x385c083e, ARCOMPACT, 0, 0 ,0,0},
/* idxalc 0,b*/
  {(unsigned char *)"sidxalc 0,%B", 0xf8ff0fff, 0x385c007e, ARCOMPACT, 0, 0 ,0,0},

/* idxfre a,[cm:b],b,c */
  {(unsigned char *)"idxfre %A,[cm:%B],%B,%C" , 0xf8ff0000, 0x381e0000, ARCOMPACT, 0, 0 ,0,0},
/* idxfre a,[cm:b],b,NumOfBuff */
  {(unsigned char *)"idxfre %A,[cm:%B],%B,%\306" , 0xf8ff0000, 0x385e0000, ARCOMPACT, 0, 0 ,0,0},
/* idxfre 0,[cm:b],b,c */
  {(unsigned char *)"idxfre 0,[cm:%B],%B,%C" , 0xf8ff003f, 0x381e003e, ARCOMPACT, 0, 0 ,0,0},
/* idxfre 0,[cm:b],b,NumOfBuff */
  {(unsigned char *)"idxfre 0,[cm:%B],%B,%\306" , 0xf8ff003f, 0x385e003e, ARCOMPACT, 0, 0 ,0,0},

/* sidxfre a,b,c */
  {(unsigned char *)"sidxfre %A,%B,%C" , 0xf8ff0000, 0x381d0000, ARCOMPACT, 0, 0 ,0,0},
/* sidxfre 0,b,c */
  {(unsigned char *)"sidxfre 0,%B,%C" , 0xf8ff003f, 0x381d003e, ARCOMPACT, 0, 0 ,0,0},

/* encr c,[cm:b],[cm:b],size */
  {(unsigned char *)"encr%>+\017 %c,[cm:%b],[cm:%b],%\374", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* encr c,[cm:b],[cm:b],c */
  {(unsigned char *)"encr%>+\017 %c,[cm:%b],[cm:%b],%c", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* decr c,[cm:b],[cm:b],size */
  {(unsigned char *)"decr%>+\017+\000 %c,[cm:%b],[cm:%b],%\374", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* decr c,[cm:b],[cm:b],c */
  {(unsigned char *)"decr%>+\017+\000 %c,[cm:%b],[cm:%b],%c", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},

/* shash c,[cm:b],size,init,pad */
  {(unsigned char *)"shash%>+\017+\001 %c,[cm:%b],%\374,%\377,%\371", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* shash c,[cm:b],c,init,pad */
  {(unsigned char *)"shash%>+\017+\001 %c,[cm:%b],%c,%\377,%\371", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* hmac.ipad c,[cm:b],size */
  {(unsigned char *)"hmac.ipad%>+\017+\016+\015+\001 %c,[cm:%b],%\374", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* hmac.ipad c,[cm:b],c */
  {(unsigned char *)"hmac.ipad%>+\017+\016+\015+\001 %c,[cm:%b],%c", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* hmac.opad c,[cm:b],size */
  {(unsigned char *)"hmac.opad%>+\017+\016+\004+\001 %c,[cm:%b],%\374", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* hmac.opad c,[cm:b],c */
  {(unsigned char *)"hmac.opad%>+\017+\016+\004+\001 %c,[cm:%b],%c", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},

/* expskey [sm:c] */
  {(unsigned char *)"expskey%>+\017+\001+\000 [sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpssta [sm:c],[cm:b] */
  {(unsigned char *)"cpssta%>+\017+\002+\006 [sm:%c],[cm:%b]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpssta [cm:b],[sm:c] */
  {(unsigned char *)"cpssta%>+\017+\002 [cm:%b],[sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsiv [sm:c],[cm:b] */
  {(unsigned char *)"cpsiv%>+\017+\002+\004+\006 [sm:%c],[cm:%b]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsiv [cm:c],[sm:b] */
  {(unsigned char *)"cpsiv%>+\017+\002+\004 [cm:%b],[sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsmac [sm:c],[cm:b] */
  {(unsigned char *)"cpsmac%>+\017+\002+\005+\006 [sm:%c],[cm:%b]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsmac [cm:b],[sm:c] */
  {(unsigned char *)"cpsmac%>+\017+\002+\005 [cm:%b],[sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpskey [sm:c],[cm:b] */
  {(unsigned char *)"cpskey%>+\017+\002+\003+\006 [sm:%c],[cm:%b]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpskey [cm:b],[sm:c] */
  {(unsigned char *)"cpskey%>+\017+\002+\003 [cm:%b],[sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsctx [sm:c],[cm:b] */
  {(unsigned char *)"cpsctx%>+\017+\002+\003+\004+\006 [sm:%c],[cm:%b]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* cpsctx [cm:b],[sm:c] */
  {(unsigned char *)"cpsctx%>+\017+\002+\003+\004 [cm:%b],[sm:%c]", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* gcm.fin c,[cm:b],size */
  {(unsigned char *)"gcm.fin%>+\017+\000+\002 %c,[cm:%b],%\374", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* gcm.fin c,[cm:b],c */
  {(unsigned char *)"gcm.fin%>+\017+\000+\002 %c,[cm:%b],%c", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},

/* gensiv c,[cm:b],size,init,pad */
  {(unsigned char *)"gensiv%>+\017+\001+\002+\003 %c,[cm:%b],%\374,%\377,%\371", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},
/* gensiv c,[cm:b],c,init,pad */
  {(unsigned char *)"gensiv%>+\017+\001+\002 %c,[cm:%b],%c,%\377,%\371", 0xf81f, 0x4805, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [sd:b,c,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\000+\005+\006+\016+\017 [sd:%b,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [sd:b,c,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\000+\005+\006+\010+\016+\017 [sd:%b,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [sd:b,c,c,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\000+\005+\006+\017 [sd:%b,%c,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [sd:b,c,c,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\000+\005+\006+\010+\017 [sd:%b,%c,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xd:b,c,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\007+\000+\016+\017 [xd:%b,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xd:b,c,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\007+\000+\016+\017+\010 [xd:%b,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xd:b,c,c,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\007+\000+\017 [xd:%b,%c,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xd:b,c,c,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\007+\000+\017+\010 [xd:%b,%c,%c,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [sd:b,entry,off],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\000+\001+\005+\006+\016+\017 [sd:%b,%\372,%\373],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [sd:b,entry,off],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\000+\001+\005+\006+\016+\010+\017 [sd:%b,%\372,%\373],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[sd:b,entry,off,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\001+\017 [cm:%c],[sd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
  //{(unsigned char *)"cp16%>%.\346 [cm:%c],[sd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[sd:b,entry,off,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\001+\010+\017 [cm:%c],[sd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xd:b,entry,off,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\007+\000+\001+\017 [xd:%b,%\372,%\373,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xd:b,entry,off,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\007+\000+\001+\017+\010 [xd:%b,%\372,%\373,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [sd:b,entry,off,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\000+\001+\005+\006+\017 [sd:%b,%\372,%\373,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [sd:b,entry,off,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\000+\001+\005+\006+\017+\010 [sd:%b,%\372,%\373,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xd:b,entry,off],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\000+\001+\007+\016+\017 [xd:%b,%\372,%\373],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xd:b,entry,off],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\000+\001+\007+\016+\017+\010 [xd:%b,%\372,%\373],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[sd:b,entry,off] */
  {(unsigned char *)"cp16%>%.\346+\001+\005+\006+\016+\017 [cm:%c],[sd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[sd:b,entry,off] */
  {(unsigned char *)"cp32%>%.\346+\001+\005+\006+\016+\010+\017 [cm:%c],[sd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xd:b,entry,off,c] */
  {(unsigned char *)"cp16%>%.\346+\007+\001+\017 [cm:%c],[xd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xd:b,entry,off,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\001+\010+\017 [cm:%c],[xd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xd:b,entry,off] */
  {(unsigned char *)"cp16%>%.\346+\007+\001+\016+\017 [cm:%c],[xd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xd:b,entry,off] */
  {(unsigned char *)"cp32%>%.\346+\007+\001+\016+\010+\017 [cm:%c],[xd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xd:b,c,c,c] */
  {(unsigned char *)"cp16%>%.\346+\007+\017 [cm:%c],[xd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xd:b,c,c,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\010+\017 [cm:%c],[xd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xd:b,c,c] */
  {(unsigned char *)"cp16%>%.\346+\007+\016+\017 [cm:%c],[xd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xd:b,c,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\010+\016+\017 [cm:%c],[xd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[sd:b,c,c,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\017 [cm:%c],[sd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[sd:b,c,c,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\010+\017 [cm:%c],[sd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[sd:b,c,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\016+\017 [cm:%c],[sd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[sd:b,c,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\010+\016+\017 [cm:%c],[sd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xa:b],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\005+\005+\000+\001+\016+\017 [xa:%b],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xa:b],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\005+\000+\001+\010+\016+\017 [xa:%b],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xa:b,c],[cm:c] */
  {(unsigned char *)"cp16%>%.\346+\005+\005+\000+\001+\017 [xa:%b,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xa:b,c],[cm:c] */
  {(unsigned char *)"cp32%>%.\346+\005+\000+\001+\010+\017 [xa:%b,%c],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xa:b] */
  {(unsigned char *)"cp16%>%.\346+\005+\001+\016+\017 [cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xa:b] */
  {(unsigned char *)"cp32%>%.\346+\005+\001+\010+\016+\017 [cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [cm:c],[xa:b,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\001+\017 [cm:%c],[xa:%b,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [cm:c],[xa:b,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\001+\010+\017 [cm:%c],[xa:%b,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp32 [jid:b],[cm:c] */
    {(unsigned char *)"cp32%>+\006+\000+\001+\010+\016+\017 [jid:%b],[cm:%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp32 [cm:c],[jid:b] */
  {(unsigned char *)"cp32%>+\006+\001+\010+\016+\017 [cm:%c],[jid:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32 b,[cm:c],[jid:b] */
  {(unsigned char *)"cp32%>+\006+\001+\010+\016 %b,[cm:%c],[jid:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xa:b] */
  {(unsigned char *)"cp16%>%.\346+\005+\001+\016 %b,[cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xa:b] */
  {(unsigned char *)"cp32%>%.\346+\005+\001+\010+\016 %b,[cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xa:b,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\001 %b,[cm:%c],[xa:%b,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xa:b,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\001+\010 %b,[cm:%c],[xa:%b,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> [xa:b],[cm:c],c */
  {(unsigned char *)"cp16%>%.\346+\005+\005+\000+\001+\017 [xa:%b],[cm:%c],%c", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> [xa:b],[cm:c],c */
  {(unsigned char *)"cp32%>%.\346+\005+\000+\001+\010+\017 [xa:%b],[cm:%c],%c", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[sd:b,entry,off] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\001+\016 %b,[cm:%c],[sd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[sd:b,entry,off] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\001+\016+\010 %b,[cm:%c],[sd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[sd:b,entry,off,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\001 %b,[cm:%c],[sd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[sd:b,entry,off,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\001+\010 %b,[cm:%c],[sd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[sd:b,c,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006+\016 %b,[cm:%c],[sd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[sd:b,c,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\010+\016 %b,[cm:%c],[sd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xd:b,entry,off] */
  {(unsigned char *)"cp16%>%.\346+\007+\001+\016 %b,[cm:%c],[xd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xd:b,entry,off] */
  {(unsigned char *)"cp32%>%.\346+\007+\001+\016+\010 %b,[cm:%c],[xd:%b,%\372,%\373]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[sd:b,c,c,c] */
  {(unsigned char *)"cp16%>%.\346+\005+\006 %b,[cm:%c],[sd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[sd:b,c,c,c] */
  {(unsigned char *)"cp32%>%.\346+\005+\006+\010 %b,[cm:%c],[sd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xd:b,entry,off,c] */
  {(unsigned char *)"cp16%>%.\346+\007+\001 %b,[cm:%c],[xd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xd:b,entry,off,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\001+\010 %b,[cm:%c],[xd:%b,%\372,%\373,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xd:b,c,c] */
  {(unsigned char *)"cp16%>%.\346+\007+\016 %b,[cm:%c],[xd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xd:b,c,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\010+\016 %b,[cm:%c],[xd:%b,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16<.na> b,[cm:c],[xd:b,c,c,c] */
  {(unsigned char *)"cp16%>%.\346+\007 %b,[cm:%c],[xd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32<.na> b,[cm:c],[xd:b,c,c,c] */
  {(unsigned char *)"cp32%>%.\346+\007+\010 %b,[cm:%c],[xd:%b,%c,%c,%c]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp16 b,[cm:c],[xa:b] */
  {(unsigned char *)"cp16%>%.\346+\005+\001 %b,[cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* cp32 b,[cm:c],[xa:b] */
  {(unsigned char *)"cp32%>%.\346+\005+\001+\010 %b,[cm:%c],[xa:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* uip<.na> b,[cm:c],[cm:b],c */
  {(unsigned char *)"uip%>%.\346+\007+\005+\001 %b,[cm:%c],[cm:%b],%c", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},
/* uip<.na> b,[cm:c],[cm:b] */
  {(unsigned char *)"uip%>%.\346+\007+\005+\001+\016 %b,[cm:%c],[cm:%b]", 0xf81f, 0x4807, ARCOMPACT, 0, 0 ,0,0},

/* cp<.e><.m> a,[cbd:b,c,c],[cbd:b,c,c],c  */
  {(unsigned char *)"cp%Q%.\317%.\307+\033 %\310,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\033 %\310,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317%.\307+\033 0,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\033 0,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e><.m> a,[cbd:b,c],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\317%.\307+\027+\033 %\310,[cbd:%\311,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\027+\033 %\310,[cbd:%\311,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317%.\307+\027+\033 0,[cbd:%\311,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\027+\033 0,[cbd:%\311,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e><.m> a,[cbd:b,c],[cbd:A,c],c  */
  {(unsigned char *)"cp%Q.e%.\307+\030+\031 %\310,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307.e+\030+\031 %\310,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q.e%.\307+\030+\031 0,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307.e+\030+\031 0,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307 %\310,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307 %\310,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307 0,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307 0,[cbd:%\311,%\312],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e><.m> a,[cbd:A,c],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q.e%.\307+\030+\031+\032 %\310,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307.e+\030+\031+\032 %\310,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q.e%.\307+\030+\031+\032 0,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307.e+\030+\031+\032 0,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032 %\310,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032 %\310,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032 0,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032 0,[cbd:%\236,%\312],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cbd:A,c],s8  */
  {(unsigned char *)"cp%Q%.\307+\030 %\310,[cbd:%\311,%\312],[cbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030 0,[cbd:%\311,%\312],[cbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,c],[cbd:b,c],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\032 %\310,[cbd:%\236,%\312],[cbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\032 0,[cbd:%\236,%\312],[cbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O8],[cbd:A,c],c  */
  {(unsigned char *)"cp%Q%.\307+\031 %\310,[cbd:%\311,%\341],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031 0,[cbd:%\311,%\341],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,O8],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\031+\032 %\310,[cbd:%\236,%\341],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\032 0,[cbd:%\236,%\341],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033 %\310,[cbd:%\311,%\335],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033 0,[cbd:%\311,%\335],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cbd:b,c,c],c  */
  {(unsigned char *)"cp%Q%.\307+\030+\033 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\033 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cbd:b,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033 %\310,[cbd:%\311,%\335],[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033 0,[cbd:%\311,%\335],[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp.e<.m> a,[cbd:b,O10],[cbd:b,O10],c  */
  {(unsigned char *)"cp.e%Q%.\307+\027+\030+\032+\033 %\310,[cbd:%\311,%\335],[cbd:%\311,%\335],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\027+\030+\032+\033+\034 %\310,[cbd:%\311,%\335],[cbd:%\311,%\335],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q%.\307+\027+\030+\032+\033 0,[cbd:%\311,%\335],[cbd:%\311,%\335],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\027+\030+\032+\033+\034 0,[cbd:%\311,%\335],[cbd:%\311,%\335],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp.e<.m> a,[cbd:b,O10,c],[cbd:b,O10,c],c  */
  {(unsigned char *)"cp.e%Q%.\307+\030+\032+\033 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\030+\032+\033+\034 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q%.\307+\030+\032+\033 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\030+\032+\033+\034 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp.e<.m> a,[cbd:b,O10],[cbd:b,O10],s10  */
  {(unsigned char *)"cp.e%Q%.\307+\027+\030+\031+\032+\033 %\310,[cbd:%\311,%\335],[cbd:%\311,%\335],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\027+\030+\031+\032+\033+\034 %\310,[cbd:%\311,%\335],[cbd:%\311,%\335],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q%.\307+\027+\030+\031+\032+\033 0,[cbd:%\311,%\335],[cbd:%\311,%\335],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\027+\030+\031+\032+\033+\034 0,[cbd:%\311,%\335],[cbd:%\311,%\335],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp.e<.m> a,[cbd:b,O10,c],[cbd:b,O10,c],s10  */
  {(unsigned char *)"cp.e%Q%.\307+\030+\031+\032+\033 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\030+\031+\032+\033+\034 %\310,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q%.\307+\030+\031+\032+\033 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.m.e%Q+\030+\031+\032+\033+\034 0,[cbd:%\311,%\335,%\312],[cbd:%\311,%\335,%\312],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e><.m> a,[cbd:b,c],[cbd:b,c],s10  */
  {(unsigned char *)"cp%Q%.\317%.\307+\027+\033+\031 %\310,[cbd:%\311,%\312],[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\027+\033+\031 %\310,[cbd:%\311,%\312],[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317%.\307+\027+\033+\031 0,[cbd:%\311,%\312],[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\027+\033+\031 0,[cbd:%\311,%\312],[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e><.m> a,[cbd:b,c,c],[cbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q%.\317%.\307+\033+\031 %\310,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\033+\031 %\310,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317%.\307+\033+\031 0,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\317+\033+\031 0,[cbd:%\311,%\312,%\312],[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp<.m> a,[cxa:b],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\033+\036 %\310,[cxa:%\311],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\033+\036 0,[cxa:%\311],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:b,c],[cbd:b,c,c],c  */
  {(unsigned char *)"cp%Q%.\307+\033+\036 %\310,[cxa:%\311,%\312],[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\033+\036 0,[cxa:%\311,%\312],[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:b],[cbd:A,c],c  */
  {(unsigned char *)"cp%Q%.\307+\036 %\310,[cxa:%\311],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\036 0,[cxa:%\311],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:A],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\032+\036 %\310,[cxa:%\236],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032+\036 0,[cxa:%\236],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:b],[cbd:A,c],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\036 %\310,[cxa:%\311],[cbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\036 0,[cxa:%\311],[cbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:A],[cbd:b,c],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\032+\036 %\310,[cxa:%\236],[cbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\032+\036 0,[cxa:%\236],[cbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:b],[cbd:b,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\036 %\310,[cxa:%\311],[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\036 0,[cxa:%\311],[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cxa:b,c],[cbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\031+\033+\036 %\310,[cxa:%\311,%\312],[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\033+\036 0,[cxa:%\311,%\312],[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp<.m> a,[cbd:b,c],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\033+\035 %\310,[cbd:%\311,%\312],[cxa:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\033+\035 0,[cbd:%\311,%\312],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\033+\035 %\310,[cbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\033+\035 0,[cbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cxa:A],c  */
  {(unsigned char *)"cp%Q%.\307+\035 %\310,[cbd:%\311,%\312],[cxa:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\035 0,[cbd:%\311,%\312],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,c],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307+\032+\035 %\310,[cbd:%\236,%\312],[cxa:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032+\035 0,[cbd:%\236,%\312],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cxa:A],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\035 %\310,[cbd:%\311,%\312],[cxa:%\236],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\035 0,[cbd:%\311,%\312],[cxa:%\236],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,c],[cxa:b],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\032+\035 %\310,[cbd:%\236,%\312],[cxa:%\311],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\032+\035 0,[cbd:%\236,%\312],[cxa:%\311],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O8],[cxa:A],c  */
  {(unsigned char *)"cp%Q%.\307+\031+\035 %\310,[cbd:%\311,%\341],[cxa:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\035 0,[cbd:%\311,%\341],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,O8],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307+\031+\032+\035 %\310,[cbd:%\236,%\341],[cxa:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\032+\035 0,[cbd:%\236,%\341],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033+\035 %\310,[cbd:%\311,%\335],[cxa:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033+\035 0,[cbd:%\311,%\335],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\307+\030+\033+\035 %\310,[cbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\033+\035 0,[cbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cxa:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033+\035 %\310,[cbd:%\311,%\335],[cxa:%\311],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033+\035 0,[cbd:%\311,%\335],[cxa:%\311],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cxa:b,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033+\035 %\310,[cbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033+\035 0,[cbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cxa:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\035 %\310,[cbd:%\311,%\312],[cxa:%\311],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\035 0,[cbd:%\311,%\312],[cxa:%\311],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c,c],[cxa:b,c],s10  */
  {(unsigned char *)"cp%Q%.\307+\031+\033+\035 %\310,[cbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\033+\035 0,[cbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[cm:b],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q+\027+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\037 0,[cm:%\311],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:c],[cbd:b,c,c],c  */
  {(unsigned char *)"cp%Q+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\033+\037 0,[cm:%\311],[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:A,c],c  */
  {(unsigned char *)"cp%Q+\037 %\310,[cm:%\311],[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\037 0,[cm:%\311],[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[cbd:b,c],c  */
  {(unsigned char *)"cp%Q+\032+\037 %\310,[cm:%\236],[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\037 0,[cm:%\236],[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:A,c],s8  */
  {(unsigned char *)"cp%Q+\030+\037 %\310,[cm:%\311],[cbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\037 0,[cm:%\311],[cbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[cbd:b,c],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\037 %\310,[cm:%\236],[cbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\037 0,[cm:%\236],[cbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:A,O8],c  */
  {(unsigned char *)"cp%Q+\031+\037 %\310,[cm:%\311],[cbd:%\236,%\341],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\037 0,[cm:%\311],[cbd:%\236,%\341],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[cbd:b,O8],c  */
  {(unsigned char *)"cp%Q+\031+\032+\037 %\310,[cm:%\236],[cbd:%\311,%\341],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\032+\037 0,[cm:%\236],[cbd:%\311,%\341],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,O10],c  */
  {(unsigned char *)"cp%Q+\027+\030+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\335],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\033+\037 0,[cm:%\311],[cbd:%\311,%\335],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,O10,c],c  */
  {(unsigned char *)"cp%Q+\030+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\335,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033+\037 0,[cm:%\311],[cbd:%\311,%\335,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,O10,c,c],c  */
  {(unsigned char *)"cp%Q+\030+\033+\037 %\310,[cm:%\311,%\312],[cbd:%\311,%\335,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033+\037 0,[cm:%\311,%\312],[cbd:%\311,%\335,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,O10],s10  */
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\335],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\037 0,[cm:%\311],[cbd:%\311,%\335],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,O10,c],s10  */
  {(unsigned char *)"cp%Q+\030+\031+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\335,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\031+\033+\037 0,[cm:%\311],[cbd:%\311,%\335,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,c],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\037 0,[cm:%\311],[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\037 %\310,[cm:%\311],[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\037 0,[cm:%\311],[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp<.m> a,[cbd:b,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\033+\036+\037 %\310,[cbd:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\033+\036+\037 0,[cbd:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\033+\036+\037 %\310,[cbd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\033+\036+\037 0,[cbd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cm:A],c  */
  {(unsigned char *)"cp%Q%.\307+\036+\037 %\310,[cbd:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\036+\037 0,[cbd:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\032+\036+\037 %\310,[cbd:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\032+\036+\037 0,[cbd:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cm:A],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\036+\037 %\310,[cbd:%\311,%\312],[cm:%\236],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\036+\037 0,[cbd:%\311,%\312],[cm:%\236],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,c],[cm:b],s8  */
  {(unsigned char *)"cp%Q%.\307+\030+\032+\036+\037 %\310,[cbd:%\236,%\312],[cm:%\311],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\032+\036+\037 0,[cbd:%\236,%\312],[cm:%\311],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O8],[cm:A],c  */
  {(unsigned char *)"cp%Q%.\307+\031+\036+\037 %\310,[cbd:%\311,%\341],[cm:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\036+\037 0,[cbd:%\311,%\341],[cm:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:A,O8],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\031+\032+\036+\037 %\310,[cbd:%\236,%\341],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\032+\036+\037 0,[cbd:%\236,%\341],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033+\036+\037 %\310,[cbd:%\311,%\335],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\033+\036+\037 0,[cbd:%\311,%\335],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307+\030+\033+\036+\037 %\310,[cbd:%\311,%\335,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\033+\036+\037 0,[cbd:%\311,%\335,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10],[cm:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033+\036+\037 %\310,[cbd:%\311,%\335],[cm:%\311],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\030+\031+\033+\036+\037 0,[cbd:%\311,%\335],[cm:%\311],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,O10,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033+\036+\037 %\310,[cbd:%\311,%\335,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\030+\031+\033+\036+\037 0,[cbd:%\311,%\335,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\036+\037 %\310,[cbd:%\311,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\027+\031+\033+\036+\037 0,[cbd:%\311,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m> a,[cbd:b,c,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q%.\307+\031+\033+\036+\037 %\310,[cbd:%\311,%\312,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307+\031+\033+\036+\037 0,[cbd:%\311,%\312,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[cm:b],[cjid:b],c  */
  {(unsigned char *)"cp%Q+\027+\033+\035+\037 %\310,[cm:%\311],[cjid:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\035+\037 0,[cm:%\311],[cjid:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cjid:A],c  */
  {(unsigned char *)"cp%Q+\035+\037 %\310,[cm:%\311],[cjid:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\035+\037 0,[cm:%\311],[cjid:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[cjid:b],c  */
  {(unsigned char *)"cp%Q+\032+\035+\037 %\310,[cm:%\236],[cjid:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\035+\037 0,[cm:%\236],[cjid:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cjid:A],s8  */
  {(unsigned char *)"cp%Q+\030+\035+\037 %\310,[cm:%\311],[cjid:%\236],%\332%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\035+\037 0,[cm:%\311],[cjid:%\236],%\332%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[cjid:b],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\035+\037 %\310,[cm:%\236],[cjid:%\311],%\332%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\035+\037 0,[cm:%\236],[cjid:%\311],%\332%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[cjid:b],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\037 %\310,[cm:%\311],[cjid:%\311],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\037 0,[cm:%\311],[cjid:%\311],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[cjid:b],[cm:b],c  */
  {(unsigned char *)"cp%Q+\027+\033+\035+\036+\037 %\310,[cjid:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\035+\036+\037 0,[cjid:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cjid:b],[cm:A],c  */
  {(unsigned char *)"cp%Q+\035+\036+\037 %\310,[cjid:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\035+\036+\037 0,[cjid:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cjid:A],[cm:b],c  */
  {(unsigned char *)"cp%Q+\032+\035+\036+\037 %\310,[cjid:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\035+\036+\037 0,[cjid:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cjid:b],[cm:A],s8  */
  {(unsigned char *)"cp%Q+\030+\035+\036+\037 %\310,[cjid:%\311],[cm:%\236],%\332%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\035+\036+\037 0,[cjid:%\311],[cm:%\236],%\332%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cjid:A],[cm:b],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\035+\036+\037 %\310,[cjid:%\236],[cm:%\311],%\332%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\035+\036+\037 0,[cjid:%\236],[cm:%\311],%\332%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cjid:b],[cm:b],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\036+\037 %\310,[cjid:%\311],[cm:%\311],%\336%\354", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\036+\037 0,[cjid:%\311],[cm:%\311],%\336%\354", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[cbd:b,c],c  */
  {(unsigned char *)"cp%Q+\027+\033+\035+\036 %\310,[cbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\035+\036 0,[cbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cbd:b,c,c],c  */
  {(unsigned char *)"cp%Q+\033+\035+\036 %\310,[cbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\033+\035+\036 0,[cbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cbd:A,c],c  */
  {(unsigned char *)"cp%Q+\035+\036 %\310,[cbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\035+\036 0,[cbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cbd:A,c],s8  */
  {(unsigned char *)"cp%Q+\030+\035+\036 %\310,[cbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\035+\036 0,[cbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cbd:b,c],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\036 %\310,[cbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\035+\036 0,[cbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\035+\036 %\310,[cbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c1, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\035+\036 0,[cbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c1, ARCOMPACT, 0, 0 ,0,0},

/* cp<.e> a,[clbd:b,c],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q%.\317+\027+\033 %\310,[clbd:%\311,%\312],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317+\027+\033 0,[clbd:%\311,%\312],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e> a,[clbd:b,c,c],[clbd:b,c,c],c  */
  {(unsigned char *)"cp%Q%.\317+\033 %\310,[clbd:%\311,%\312,%\312],[clbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317+\033 0,[clbd:%\311,%\312,%\312],[clbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e> a,[clbd:b,c],[clbd:A,c],c  */
  {(unsigned char *)"cp.e%Q+\030+\031 %\310,[clbd:%\311,%\312],[clbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q+\030+\031 0,[clbd:%\311,%\312],[clbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q %\310,[clbd:%\311,%\312],[clbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q 0,[clbd:%\311,%\312],[clbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e> a,[clbd:A,c],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q.e+\030+\031+\032 %\310,[clbd:%\236,%\312],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q.e+\030+\031+\032 0,[clbd:%\236,%\312],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032 %\310,[clbd:%\236,%\312],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032 0,[clbd:%\236,%\312],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c],[clbd:A,c],s8  */
  {(unsigned char *)"cp%Q+\030 %\310,[clbd:%\311,%\312],[clbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030 0,[clbd:%\311,%\312],[clbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:A,c],[clbd:b,c],s8  */
  {(unsigned char *)"cp%Q+\030+\032 %\310,[clbd:%\236,%\312],[clbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032 0,[clbd:%\236,%\312],[clbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O8],[clbd:A,c],c  */
  {(unsigned char *)"cp%Q+\031 %\310,[clbd:%\311,%\341],[clbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031 0,[clbd:%\311,%\341],[clbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:A,O8],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\031+\032 %\310,[clbd:%\236,%\341],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\032 0,[clbd:%\236,%\341],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\027+\030+\033 %\310,[clbd:%\311,%\335],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\033 0,[clbd:%\311,%\335],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10,c],[clbd:b,c,c],c  */
  {(unsigned char *)"cp%Q+\030+\033 %\310,[clbd:%\311,%\335,%\312],[clbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033 0,[clbd:%\311,%\335,%\312],[clbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10],[clbd:b,c],s10  */
  {(unsigned char *)"cp%Q+\027+\030+\031+\033 %\310,[clbd:%\311,%\335],[clbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\031+\033 0,[clbd:%\311,%\335],[clbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10,c],[clbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q+\030+\031+\033 %\310,[clbd:%\311,%\335,%\312],[clbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\031+\033 0,[clbd:%\311,%\335,%\312],[clbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp.e a,[clbd:b,O10],[clbd:b,O10],c  */
  {(unsigned char *)"cp.e%Q+\027+\030+\032+\033 %\310,[clbd:%\311,%\335],[clbd:%\311,%\335],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q+\027+\030+\032+\033 0,[clbd:%\311,%\335],[clbd:%\311,%\335],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp.e a,[clbd:b,O10,c],[clbd:b,O10,c],c  */
  {(unsigned char *)"cp.e%Q+\030+\032+\033 %\310,[clbd:%\311,%\335,%\312],[clbd:%\311,%\335,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q+\030+\032+\033 0,[clbd:%\311,%\335,%\312],[clbd:%\311,%\335,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp.e a,[clbd:b,O10],[clbd:b,O10],s10  */
  {(unsigned char *)"cp.e%Q+\027+\030+\031+\032+\033 %\310,[clbd:%\311,%\335],[clbd:%\311,%\335],%\336%\354", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q+\027+\030+\031+\032+\033 0,[clbd:%\311,%\335],[clbd:%\311,%\335],%\336%\354", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp.e a,[clbd:b,O10,c],[clbd:b,O10,c],s10  */
  {(unsigned char *)"cp.e%Q+\030+\031+\032+\033 %\310,[clbd:%\311,%\335,%\312],[clbd:%\311,%\335,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp.e%Q+\030+\031+\032+\033 0,[clbd:%\311,%\335,%\312],[clbd:%\311,%\335,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e> a,[clbd:b,c],[clbd:b,c],s10  */
  {(unsigned char *)"cp%Q%.\317+\027+\033+\031 %\310,[clbd:%\311,%\312],[clbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317+\027+\033+\031 0,[clbd:%\311,%\312],[clbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp<.e> a,[clbd:b,c,c],[clbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q%.\317+\033+\031 %\310,[clbd:%\311,%\312,%\312],[clbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\317+\033+\031 0,[clbd:%\311,%\312,%\312],[clbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},

/* cp   a,[cxa:b],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\027+\033+\036 %\310,[cxa:%\311],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\036 0,[cxa:%\311],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:b,c],[clbd:b,c,c],c  */
  {(unsigned char *)"cp%Q+\033+\036 %\310,[cxa:%\311,%\312],[clbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\033+\036 0,[cxa:%\311,%\312],[clbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:b],[clbd:A,c],c  */
  {(unsigned char *)"cp%Q+\036 %\310,[cxa:%\311],[clbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\036 0,[cxa:%\311],[clbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:A],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\032+\036 %\310,[cxa:%\236],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\036 0,[cxa:%\236],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:b],[clbd:A,c],s8  */
  {(unsigned char *)"cp%Q+\030+\036 %\310,[cxa:%\311],[clbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\036 0,[cxa:%\311],[clbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:A],[clbd:b,c],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\036 %\310,[cxa:%\236],[clbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\036 0,[cxa:%\236],[clbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:b],[clbd:b,c],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\036 %\310,[cxa:%\311],[clbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\036 0,[cxa:%\311],[clbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[cxa:b,c],[clbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\036 %\310,[cxa:%\311,%\312],[clbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\036 0,[cxa:%\311,%\312],[clbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},

/* cp   a,[clbd:b,c],[cxa:b],c  */
  {(unsigned char *)"cp%Q+\027+\033+\035 %\310,[clbd:%\311,%\312],[cxa:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\035 0,[clbd:%\311,%\312],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,c,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q+\033+\035 %\310,[clbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\033+\035 0,[clbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,c],[cxa:A],c  */
  {(unsigned char *)"cp%Q+\035 %\310,[clbd:%\311,%\312],[cxa:%\236],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\035 0,[clbd:%\311,%\312],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:A,c],[cxa:b],c  */
  {(unsigned char *)"cp%Q+\032+\035 %\310,[clbd:%\236,%\312],[cxa:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\035 0,[clbd:%\236,%\312],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,c],[cxa:A],s8  */
  {(unsigned char *)"cp%Q+\030+\035 %\310,[clbd:%\311,%\312],[cxa:%\236],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\035 0,[clbd:%\311,%\312],[cxa:%\236],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:A,c],[cxa:b],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\035 %\310,[clbd:%\236,%\312],[cxa:%\311],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\035 0,[clbd:%\236,%\312],[cxa:%\311],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,O8],[cxa:A],c  */
  {(unsigned char *)"cp%Q+\031+\035 %\310,[clbd:%\311,%\341],[cxa:%\236],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\035 0,[clbd:%\311,%\341],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:A,O8],[cxa:b],c  */
  {(unsigned char *)"cp%Q+\031+\032+\035 %\310,[clbd:%\236,%\341],[cxa:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\032+\035 0,[clbd:%\236,%\341],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,O10],[cxa:b],c  */
  {(unsigned char *)"cp%Q+\027+\030+\033+\035 %\310,[clbd:%\311,%\335],[cxa:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\033+\035 0,[clbd:%\311,%\335],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,O10,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q+\030+\033+\035 %\310,[clbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033+\035 0,[clbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,O10],[cxa:b],s10  */
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\035 %\310,[clbd:%\311,%\335],[cxa:%\311],%\336%\354", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\035 0,[clbd:%\311,%\335],[cxa:%\311],%\336%\354", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,O10,c],[cxa:b,c],s10  */
  {(unsigned char *)"cp%Q+\030+\031+\033+\035 %\310,[clbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\031+\033+\035 0,[clbd:%\311,%\335,%\312],[cxa:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,c],[cxa:b],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\035 %\310,[clbd:%\311,%\312],[cxa:%\311],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\035 0,[clbd:%\311,%\312],[cxa:%\311],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp   a,[clbd:b,c,c],[cxa:b,c],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\035 %\310,[clbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\035 0,[clbd:%\311,%\312,%\312],[cxa:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[cm:b],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\027+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\037 0,[cm:%\311],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
  /* cp a,[cm:b],[clbd:b,c,c],c  */
    {(unsigned char *)"cp%Q+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
    {(unsigned char *)"cp%Q+\033+\037 0,[cm:%\311],[clbd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:A,c],c  */
  {(unsigned char *)"cp%Q+\037 %\310,[cm:%\311],[clbd:%\236,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\037 0,[cm:%\311],[clbd:%\236,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[clbd:b,c],c  */
  {(unsigned char *)"cp%Q+\032+\037 %\310,[cm:%\236],[clbd:%\311,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\037 0,[cm:%\236],[clbd:%\311,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:A,c],s8  */
  {(unsigned char *)"cp%Q+\030+\037 %\310,[cm:%\311],[clbd:%\236,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\037 0,[cm:%\311],[clbd:%\236,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[clbd:b,c],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\037 %\310,[cm:%\236],[clbd:%\311,%\312],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\037 0,[cm:%\236],[clbd:%\311,%\312],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:A,O8],c  */
  {(unsigned char *)"cp%Q+\031+\037 %\310,[cm:%\311],[clbd:%\236,%\341],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\037 0,[cm:%\311],[clbd:%\236,%\341],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:A],[clbd:b,O8],c  */
  {(unsigned char *)"cp%Q+\031+\032+\037 %\310,[cm:%\236],[clbd:%\311,%\341],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\032+\037 0,[cm:%\236],[clbd:%\311,%\341],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,O10],c  */
  {(unsigned char *)"cp%Q+\027+\030+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\335],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\033+\037 0,[cm:%\311],[clbd:%\311,%\335],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,O10,c],c  */
  {(unsigned char *)"cp%Q+\030+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\335,%\312],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033+\037 0,[cm:%\311],[clbd:%\311,%\335,%\312],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,O10],s10  */
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\335],%\336%\354", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\037 0,[cm:%\311],[clbd:%\311,%\335],%\336%\354", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,O10,c],s10  */
  {(unsigned char *)"cp%Q+\030+\031+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\335,%\312],%\336%\354", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\031+\033+\037 0,[cm:%\311],[clbd:%\311,%\335,%\312],%\336%\354", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,c],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\037 0,[cm:%\311],[clbd:%\311,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[cm:b],[clbd:b,c,c],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\037 %\310,[cm:%\311],[clbd:%\311,%\312,%\312],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\037 0,[cm:%\311],[clbd:%\311,%\312,%\312],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},

/* cp a,[clbd:b,c],[cm:b],c  */
  {(unsigned char *)"cp%Q+\027+\033+\036+\037 %\310,[clbd:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\033+\036+\037 0,[clbd:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c,c],[cm:b],c  */
  {(unsigned char *)"cp%Q+\033+\036+\037 %\310,[clbd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\033+\036+\037 0,[clbd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c],[cm:A],c  */
  {(unsigned char *)"cp%Q+\036+\037 %\310,[clbd:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\036+\037 0,[clbd:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:A,c],[cm:b],c  */
  {(unsigned char *)"cp%Q+\032+\036+\037 %\310,[clbd:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\032+\036+\037 0,[clbd:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c],[cm:A],s8  */
  {(unsigned char *)"cp%Q+\030+\036+\037 %\310,[clbd:%\311,%\312],[cm:%\236],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\036+\037 0,[clbd:%\311,%\312],[cm:%\236],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:A,c],[cm:b],s8  */
  {(unsigned char *)"cp%Q+\030+\032+\036+\037 %\310,[clbd:%\236,%\312],[cm:%\311],%\332", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\032+\036+\037 0,[clbd:%\236,%\312],[cm:%\311],%\332", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O8],[cm:A],c  */
  {(unsigned char *)"cp%Q+\031+\036+\037 %\310,[clbd:%\311,%\341],[cm:%\236],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\036+\037 0,[clbd:%\311,%\341],[cm:%\236],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:A,O8],[cm:b],c  */
  {(unsigned char *)"cp%Q+\031+\032+\036+\037 %\310,[clbd:%\236,%\341],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\032+\036+\037 0,[clbd:%\236,%\341],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10],[cm:b],c  */
  {(unsigned char *)"cp%Q+\027+\030+\033+\036+\037 %\310,[clbd:%\311,%\335],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\033+\036+\037 0,[clbd:%\311,%\335],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10,c],[cm:b],c  */
  {(unsigned char *)"cp%Q+\030+\033+\036+\037 %\310,[clbd:%\311,%\335,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\033+\036+\037 0,[clbd:%\311,%\335,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10],[cm:b],s10  */
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\036+\037 %\310,[clbd:%\311,%\335],[cm:%\311],%\336%\354", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\030+\031+\033+\036+\037 0,[clbd:%\311,%\335],[cm:%\311],%\336%\354", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,O10,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q+\030+\031+\033+\036+\037 %\310,[clbd:%\311,%\335,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\030+\031+\033+\036+\037 0,[clbd:%\311,%\335,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q+\027+\031+\033+\036+\037 %\310,[clbd:%\311,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\027+\031+\033+\036+\037 0,[clbd:%\311,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},
/* cp a,[clbd:b,c,c],[cm:b],s10  */
  {(unsigned char *)"cp%Q+\031+\033+\036+\037 %\310,[clbd:%\311,%\312,%\312],[cm:%\311],%\336", 0xf80007ff, 0x500007c2, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q+\031+\033+\036+\037 0,[clbd:%\311,%\312,%\312],[cm:%\311],%\336", 0xffe007ff, 0x57c007c2, ARCOMPACT, 0, 0 ,0,0},

/* cp<.m><.na><.x> a,[cxa:b],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\035+\036 0,[cxa:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b],[cxa:A],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cxa:A,c],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:A],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\032+\035+\036 %\310,[cxa:%\236],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\032+\035+\036 0,[cxa:%\236],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\032+\035+\036 %\310,[cxa:%\236],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\032+\035+\036 0,[cxa:%\236],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\032+\035+\036 %\310,[cxa:%\236],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\032+\035+\036 0,[cxa:%\236],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036 %\310,[cxa:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036 0,[cxa:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:A,c],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\032+\035+\036 %\310,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\032+\035+\036 0,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\032+\035+\036 %\310,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\032+\035+\036 0,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\032+\035+\036 %\310,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\032+\035+\036 0,[cxa:%\236,%\312],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036 0,[cxa:%\311,%\312],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b],[cxa:b],s16  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\030+\035+\036 %\310,[cxa:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\030+\035+\036 0,[cxa:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cxa:b,c],s16  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\030+\035+\036 %\310,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\030+\035+\036 0,[cxa:%\311,%\312],[cxa:%\311,%\312],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},

/* cp<.na><.x> a,[cm:b],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\035+\037 %\310,[cm:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\035+\037 0,[cm:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\035+\037 %\310,[cm:%\311],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\035+\037 0,[cm:%\311],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:b],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\035+\037 %\310,[cm:%\311],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\035+\037 0,[cm:%\311],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\035+\037 %\310,[cm:%\311],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\035+\037 0,[cm:%\311],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:b],[cxa:A],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\031+\035+\037 %\310,[cm:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\031+\035+\037 0,[cm:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\031+\035+\037 %\310,[cm:%\311],[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\031+\035+\037 0,[cm:%\311],[cxa:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:b],[cxa:A,c],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\031+\035+\037 %\310,[cm:%\311],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\031+\035+\037 0,[cm:%\311],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\031+\035+\037 %\310,[cm:%\311],[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\031+\035+\037 0,[cm:%\311],[cxa:%\236,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:A],[cxa:b],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\031+\032+\035+\037 %\310,[cm:%\236],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\031+\032+\035+\037 0,[cm:%\236],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\031+\032+\035+\037 %\310,[cm:%\236],[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\031+\032+\035+\037 0,[cm:%\236],[cxa:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:A],[cxa:b,c],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\031+\032+\035+\037 %\310,[cm:%\236],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\031+\032+\035+\037 0,[cm:%\236],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\031+\032+\035+\037 %\310,[cm:%\236],[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\031+\032+\035+\037 0,[cm:%\236],[cxa:%\311,%\312],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:b],[cxa:b],s16  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\030+\035+\037 %\310,[cm:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\030+\035+\037 0,[cm:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\030+\035+\037 %\310,[cm:%\311],[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\030+\035+\037 0,[cm:%\311],[cxa:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cm:b],[cxa:b,c],s16  */
  {(unsigned char *)"cp%Q%.\321%.\323+\030+\035+\037 %\310,[cm:%\311],[cxa:%\311,%\312],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323+\030+\035+\037 0,[cm:%\311],[cxa:%\311,%\312],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\030+\035+\037 %\310,[cm:%\311],[cxa:%\311,%\312],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\030+\035+\037 0,[cm:%\311],[cxa:%\311,%\312],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},


/* cp<.m><.na><.x> a,[cxa:b],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b],[cm:A],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\035+\036+\037 %\310,[cxa:%\311],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\035+\036+\037 0,[cxa:%\311],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cm:A],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:A],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\032+\035+\036+\037 %\310,[cxa:%\236],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\031+\032+\035+\036+\037 0,[cxa:%\236],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:A,c],[cm:b],c  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\032+\035+\036+\037 %\310,[cxa:%\236,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\031+\032+\035+\036+\037 0,[cxa:%\236,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b],[cm:b],s16  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\030+\035+\036+\037 %\310,[cxa:%\311],[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\026+\030+\035+\036+\037 0,[cxa:%\311],[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x> a,[cxa:b,c],[cm:b],s16  */
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\321%.\323+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\321+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\307%.\323+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321%.\323%.\307+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321%.\307+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\030+\035+\036+\037 %\310,[cxa:%\311,%\312],[cm:%\311],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\321+\030+\035+\036+\037 0,[cxa:%\311,%\312],[cm:%\311],%\236", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},

/* cp<.m><.na><.x>  a,[csd:b,es,off],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,off,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\033+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,off],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,off,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\033+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\033+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\033+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\033+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,off],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\322+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\322+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,off,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\322+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\322+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\036+\037 %\310,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\036+\037 0,[csd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,off],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,off,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,off],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,off,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\033+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\033+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,off],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,off,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\033+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\033+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\033+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\033+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,c,c],[cm:b],s */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\033+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\033+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\036+\037 %\310,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\036+\037 0,[csd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,es,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\036+\037 %\310,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\036+\037 0,[csd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,es,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\035+\036+\037 %\310,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\032+\035+\036+\037 0,[cxd:%\311,%\242,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,off],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\036+\037 %\310,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\036+\037 0,[csd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,off,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\036+\037 %\310,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\036+\037 0,[csd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,off],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,off,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\035+\036+\037 %\310,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\031+\035+\036+\037 0,[cxd:%\311,%\312,%\244,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\036+\037 %\310,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\036+\037 0,[csd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[csd:b,c,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\036+\037 %\310,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\036+\037 0,[csd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\023+\035+\036+\037 0,[cxd:%\311,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.m><.na><.x>  a,[cxd:b,c,c,c],[cm:b],c */
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\322%.\323+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\307%.\323%.\322+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\307%.\323+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323%.\307+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322%.\307+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\035+\036+\037 %\310,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\307%.\322+\035+\036+\037 0,[cxd:%\311,%\312,%\312,%\312],[cm:%\311],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},

/* cp<.na><.x>  a,[cm:b],[csd:b,es,off],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,off,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,off],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,off,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\033+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\033+\037 0,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},

/* cp<.na><.x>  a,[cm:b],[csd:b,es,off],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,off,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,off],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,off,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,off],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,off,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,off],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,off,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},

/* cp<.na><.x>  a,[cm:b],[csd:b,c,off],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\037 0,[cm:%\311],[csd:%\311,%\312,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\037 0,[cm:%\311],[csd:%\311,%\312,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,off,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\037 0,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\037 0,[cm:%\311],[csd:%\311,%\312,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,off],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\031+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\031+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,off,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\031+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\031+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\244,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\037 0,[cm:%\311],[csd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\037 0,[cm:%\311],[csd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\037 0,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\037 0,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},

/* cp<.na><.x>  a,[cm:b],[csd:b,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,c,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\033+\037 %\310,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\033+\037 0,[cm:%\311],[csd:%\311,%\312,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,c,c,c],s */
  {(unsigned char *)"cp%Q%.\322%.\323+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\033+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\245", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\033+\035+\037 0,[cm:%\311],[cxd:%\311,%\312,%\312,%\312],%\245", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[csd:b,es,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\037 %\310,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\037 0,[cm:%\311],[csd:%\311,%\242,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\023+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\023+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x>  a,[cm:b],[cxd:b,es,c,c],c */
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\322%.\323+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\035+\037 %\310,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\312", 0xf80007ff, 0x500007c4, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\322+\032+\035+\037 0,[cm:%\311],[cxd:%\311,%\242,%\312,%\312],%\312", 0xffe007ff, 0x57c007c4, ARCOMPACT, 0, 0 ,0,0},

/*
 * Must be after any cp<.na>  a,[cm:c],[...
 * so assembler won't complain about missing ']'
 * Maybe there is better way to solve this...
 */
/* cp<.na> a,[cm:b],c  */
  {(unsigned char *)"cp%Q%.\321+\026+\033+\036+\037 %\310,[cm:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321+\026+\033+\036+\037 0,[cm:%\311],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na> a,[cm:A],c  */
  {(unsigned char *)"cp%Q%.\321+\026+\031+\036+\037 %\310,[cm:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321+\026+\031+\036+\037 0,[cm:%\236],%\312", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na> a,[cm:b],s16  */
  {(unsigned char *)"cp%Q%.\321+\026+\030+\036+\037 %\310,[cm:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\321+\026+\030+\036+\037 0,[cm:%\311],%\236%\354", 0xffe007ff, 0x57c007c3, ARCOMPACT, 0, 0 ,0,0},

/*cp<.na><.x> a,[cxa:b],c*/
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\033+\035 %\310,[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\033+\035 %\310,[cxa:%\311],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cxa:A],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\031+\035 %\310,[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\031+\035 %\310,[cxa:%\236],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cxa:b],s16  */
  {(unsigned char *)"cp%Q%.\321%.\323+\026+\030+\035 %\310,[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\026+\030+\035 %\310,[cxa:%\311],%\236%\354", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
/*cp<.na><.x> a,[cxa:b,c],c*/
  {(unsigned char *)"cp%Q%.\321%.\323+\033+\035 %\310,[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\033+\035 %\310,[cxa:%\311,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cxa:A,c],c  */
  {(unsigned char *)"cp%Q%.\321%.\323+\031+\035 %\310,[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\031+\035 %\310,[cxa:%\236,%\312],%\312", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
/* cp<.na><.x> a,[cxa:b,c],s16  */
  {(unsigned char *)"cp%Q%.\321%.\323+\030+\035 %\310,[cxa:%\311,%\312],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cp%Q%.\323%.\321+\030+\035 %\310,[cxa:%\311,%\312],%\236", 0xf80007ff, 0x500007c3, ARCOMPACT, 0, 0 ,0,0},

/* xex.di [cm:GPA1], b,[sd:c]*/
  {(unsigned char *)"xex.di%>+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw}.di [cm:GPA1], b,[xd:c]*/
  {(unsigned char *)"xexb.di%>+\007+\010+\012+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\007+\011+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xex.di%>+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw}.di [cm:GPA2], b,[c]*/
  {(unsigned char *)"xexb.di%>+\010+\012+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\011+\013+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xex.di%>+\012+\013+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aadd{ bwl}.di [cm:GPA1], b,[sd:c]*/
  {(unsigned char *)"aaddb.di%>+\001+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.di%>+\001+\005+\006+\014+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bwl}.di [cm:GPA1], b,[xd:c]*/
  {(unsigned char *)"aaddb.di%>+\001+\007+\010+\012+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\007+\011+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.di%>+\001+\007+\014+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ l}.di [cm:GPA2], b,[c]*/
  {(unsigned char *)"aadd.di%>+\001+\012+\013+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.di%>+\001+\014+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di<.f> b, [cm:GPA1], b,[xa:c]*/
  {(unsigned char *)"aaddl.di%.f%>+\001+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.f.di%>+\001+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di<.f> b, [cm:GPA1], b,[sd:c]*/
  {(unsigned char *)"aaddl.di%.f%>+\001+\005+\006+\014+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.f.di%>+\001+\005+\006+\014+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di<.f> b, [cm:GPA1], b,[xd:c]*/
  {(unsigned char *)"aaddl.di%.f%>+\001+\007+\014+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.f.di%>+\001+\007+\014+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di b, [xa:c]*/
  {(unsigned char *)"aaddl.di%>+\001+\005+\014+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di b, [sd:c]*/
  {(unsigned char *)"aaddl.di%>+\001+\005+\006+\014+\016+\017 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di b, [xd:c]*/
  {(unsigned char *)"aaddl.di%>+\001+\007+\014+\016+\017 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di<.f> b, [cm:GPA1], b,[xa:c]*/
  {(unsigned char *)"aaddl.di%.f%>+\001+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.f.di%>+\001+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di b,[xa:c]*/
  {(unsigned char *)"aaddb.di%>+\001+\005+\010+\012+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\005+\012+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\005+\011+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di b,[sd:c]*/
  {(unsigned char *)"aaddb.di%>+\001+\005+\006+\010+\012+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\005+\006+\012+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\005+\006+\011+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di b,[xd:c]*/
  {(unsigned char *)"aaddb.di%>+\001+\007+\010+\012+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\007+\012+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\007+\011+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bwl}.di b,[c]*/
  {(unsigned char *)"aaddl.di%>+\001+\014+\016+\017 %b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%>+\001+\010+\012+\016+\017 %b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\011+\013+\016+\017 %b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%>+\001+\012+\013+\016+\017 %b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddw.di b,[mbd:c]*/
  {(unsigned char *)"aaddw.di%>+\001+\005+\006+\007+\011+\013+\016+\017 %b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di<.f> b,b,[c]*/
  {(unsigned char *)"aaddb.di%.f%>+\001+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.f.di%>+\001+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%.f%>+\001+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.di%.f%>+\001+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.f.di%>+\001+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddl.di<.f> b,[cm:GPA2],b,[c]*/
  {(unsigned char *)"aaddl.di%.f%>+\001+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddl.f.di%>+\001+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aadd{ bw}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"aadd.di%.f%>+\001+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.f.di%>+\001+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%.f%>+\001+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.f.di%>+\001+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%.f%>+\001+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"aadd.di%.f%>+\001+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.f.di%>+\001+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%.f%>+\001+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.f.di%>+\001+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%.f%>+\001+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aadd{ bw}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"aadd.di%.f%>+\001+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.f.di%>+\001+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%.f%>+\001+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.f.di%>+\001+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%.f%>+\001+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aaddw.di<.f> b,b,[mbd:c]*/
  {(unsigned char *)"aaddw.di%.f%>+\001+\005+\006+\007+\011+\013+\016 %b,%b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\005+\006+\007+\011+\013+\016 %b,%b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aadd{ bw}.di b,[c]*/
  {(unsigned char *)"aadd.di%>+\001+\012+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%>+\001+\010+\012+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%>+\001+\011+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aadd{ bw}.di<.f> b,b,[c]*/
  {(unsigned char *)"aadd.di%.f%>+\001+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aadd.f.di%>+\001+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.di%.f%>+\001+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddb.f.di%>+\001+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.di%.f%>+\001+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aaddw.f.di%>+\001+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/*adadd{ l}.di [cm:GPA1],b,[xa:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\005+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\005+\014+\015+\016+\017 [cm:GPA1],%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di [cm:GPA1],b,[sd:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\005+\006+\014+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di [cm:GPA1],b,[xd:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\007+\014+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di [cm:GPA2],b,[c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\014+\015+\016+\017 [cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\012+\014+\015+\016+\017 [cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di<.f> b,[cm:GPA1],b,[xa:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\005+\012+\013+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\005+\012+\013+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di<.f> b,[cm:GPA1],b,[sd:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\005+\006+\012+\013+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\005+\006+\012+\013+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\005+\006+\014+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\005+\006+\014+\015+\016 %b,[cm:GPA1],%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di<.f> b,[cm:GPA1],b,[xd:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\007+\012+\013+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\007+\012+\013+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\007+\014+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\007+\014+\015+\016 %b,[cm:GPA1],%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*adadd{ l}.di<.f> b,[cm:GPA1],b,[xa:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001\012+\013+\015+\016 %b, %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001\012+\013+\015+\016 %b, %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*aand.di{ bw} [cm:GPA1],b,[sd:c]*/
  {(unsigned char *)"aandb.di%>+\002+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.di%>+\002+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aand.di{ bw} [cm:GPA1],b,[xd:c]*/
  {(unsigned char *)"aandb.di%>+\002+\007+\010+\012+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\007+\011+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.di%>+\002+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aand.di [cm:GPA2],b,[c]*/
  {(unsigned char *)"aand.di%>+\002+\012+\013+\015+\016+\017 [cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*aor.di [cm:GPA2],b,[c]*/
  {(unsigned char *)"aor.di%>+\000+\002+\012+\013+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aor{ bw}.di [cm:GPA1],b,[sd:c]*/
  {(unsigned char *)"aorb.di%>+\000+\002+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.di%>+\000+\002+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aor{ bw}.di [cm:GPA1],b,[xd:c]*/
  {(unsigned char *)"aorb.di%>+\000+\002+\007+\010+\012+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\007+\011+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.di%>+\000+\002+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*axor{ bwl}.di [cm:GPA1],b,[sd:c]*/
  {(unsigned char *)"axorb.di%>+\001+\002+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.di%>+\001+\002+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorl.di%>+\001+\002+\005+\006+\014+\015+\016+\017 [cm:GPA1],%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axor{ bwl}.di [cm:GPA1],b,[xd:c]*/
  {(unsigned char *)"axorb.di%>+\001+\002+\007+\010+\012+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\007+\011+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.di%>+\001+\002+\007+\012+\013+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorl.di%>+\001+\002+\007+\014+\015+\016+\017 [cm:GPA1],%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axor{ l}.di [cm:GPA2],b,[c]*/
  {(unsigned char *)"axor.di%>+\001+\002+\012+\013+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorl.di%>+\001+\002+\014+\015+\016+\017 [cm:GPA2],%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axorl.di<.f> b,[cm:GPA1],b,[xa:c]*/
  {(unsigned char *)"axorl.di%.f%>+\001+\002+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorl.f.di%>+\001+\002+\005+\014+\015+\016 %b,[cm:GPA1],%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axorl.di b,[xa:c]*/
  {(unsigned char *)"axorl.di%>+\001+\002+\005+\014+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axorl.di <.f> b,[cm:GPA2],b,[c]*/
  {(unsigned char *)"axorl.di%.f%>+\001+\002+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorl.f.di%>+\001+\002+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*axorl.di b,[c]*/
  {(unsigned char *)"axorl.di%>+\001+\002+\014+\016+\017 %b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*atst.di [cm:GPA2],[c]*/
  {(unsigned char *)"atst.di%>+\004+\012+\013+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*atst{ bw}.di [cm:GPA1],[sd:c]*/
  {(unsigned char *)"atstb.di%>+\004+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%>+\004+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.di%>+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*atst{ bw}.di [cm:GPA1],[xd:c]*/
  {(unsigned char *)"atstb.di%>+\004+\007+\010+\012+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%>+\004+\007+\011+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.di%>+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*ari{ l}.di [cm:GPA2],[c]*/
  {(unsigned char *)"ari.di%>+\000+\004+\012+\013+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.di%>+\000+\004+\014+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ari{ bwl}.di [cm:GPA1],[sd:c]*/
  {(unsigned char *)"arib.di%>+\000+\004+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%>+\000+\004+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.di%>+\000+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.di%>+\000+\004+\005+\006+\014+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ari{ bwl}.di [cm:GPA1],[xd:c]*/
  {(unsigned char *)"arib.di%>+\000+\004+\007+\010+\012+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%>+\000+\004+\007+\011+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.di%>+\000+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.di%>+\000+\004+\007+\014+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di [xa:c]*/
  {(unsigned char *)"aril.di%>+\000+\004+\005+\014+\016+\017 [xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di<.f> b,[cm:GPA1],[xa:c]*/
  {(unsigned char *)"aril.di%.f%>+\000+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.f.di%>+\000+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di<.f> b,[cm:GPA1],[sd:c]*/
  {(unsigned char *)"aril.di%.f%>+\000+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.f.di%>+\000+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di<.f> b,[cm:GPA1],[xd:c]*/
  {(unsigned char *)"aril.di%.f%>+\000+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.f.di%>+\000+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di [c]*/
  {(unsigned char *)"aril.di%>+\000+\004+\014+\016+\017 [%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aril.di<.f> b,[cm:GPA2],[c]*/
  {(unsigned char *)"aril.di%.f%>+\000+\004+\014+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aril.f.di%>+\000+\004+\014+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*ardc{ l}.di [cm:GPA1],[xa:c]*/
  {(unsigned char *)"ardc.di%>+\001+\004+\005+\012+\013+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.di%>+\001+\004+\005+\014+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardc{ bwl}.di [cm:GPA1],[sd:c]*/
  {(unsigned char *)"ardcb.di%>+\001+\004+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%>+\001+\004+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.di%>+\001+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.di%>+\001+\004+\005+\006+\014+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardc{ bwl}.di [cm:GPA1],[xd:c]*/
  {(unsigned char *)"ardcb.di%>+\001+\004+\007+\010+\012+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%>+\001+\004+\007+\011+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.di%>+\001+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.di%>+\001+\004+\007+\014+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardc{ l}.di [cm:GPA2],[c]*/
  {(unsigned char *)"ardc.di%>+\001+\004+\012+\013+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.di%>+\001+\004+\014+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di [xa:c]*/
  {(unsigned char *)"ardcl.di%>+\001+\004+\005+\014+\016+\017 [xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di<.f> b,[cm:GPA2],[c]*/
  {(unsigned char *)"ardcl.di%.f%>+\001+\004+\014+\015+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.f.di%>+\001+\004+\014+\015+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di<.f> b,[cm:GPA1],[xa:c]*/
  {(unsigned char *)"ardcl.di%.f%>+\001+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.f.di%>+\001+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di<.f> b,[cm:GPA1],[sd:c]*/
  {(unsigned char *)"ardcl.di%.f%>+\001+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.f.di%>+\001+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di<.f> b,[cm:GPA1],[xd:c]*/
  {(unsigned char *)"ardcl.di%.f%>+\001+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcl.f.di%>+\001+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*ardcl.di [c]*/
  {(unsigned char *)"ardcl.di%>+\001+\004+\014+\016+\017 [%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*aric.di [cm:GPA1],[sd:%c]*/
  {(unsigned char *)"aric.di%>+\000+\001+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di [cm:GPA1],[xd:%c]*/
  {(unsigned char *)"aric.di%>+\000+\001+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di [cm:GPA1],[xa:%c]*/
  {(unsigned char *)"aric.di%>+\000+\001+\004+\005+\012+\013+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di [cm:GPA2],[%c]*/
  {(unsigned char *)"aric.di%>+\000+\001+\004+\014+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[cm:GPA2],[%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\012+\013+\014+\015+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di [%c]*/
  {(unsigned char *)"aric.di%>+\000+\001+\004+\014+\016+\017 [%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[xa:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[sd:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[xd:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[cm:GPA1],[xa:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\005+\012+\013+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[cm:GPA1],[sd:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\005+\006+\012+\013+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[cm:GPA1],[xd:%c]*/
  {(unsigned char *)"aric.di%.f%>+\000+\001+\004+\007+\012+\013+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di [cm:GPA1],[xa:%c]*/
  {(unsigned char *)"aric.r.di%>+\002+\004+\005+\012+\013+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di [cm:GPA1],[sd:%c]*/
  {(unsigned char *)"aric.r.di%>+\002+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di [cm:GPA1],[xd:%c]*/
  {(unsigned char *)"aric.r.di%>+\002+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.di<.f> %b,[xa:%c]*/
  {(unsigned char *)"aric.di%.f%>+\002+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di [cm:GPA2],[%c]*/
  {(unsigned char *)"aric.r.di%>+\002+\004+\012+\013+\015+\016+\017 [cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di<.f> %b,[cm:GPA2],[%c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\012+\013+\015+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di [%c]*/
  {(unsigned char *)"aric.r.di%>+\002+\004+\012+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di<.f> %b,[cm:GPA1],[xa:%c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\005+\012+\013+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di<.f> %b,[cm:GPA1],[sd:%c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\005+\006+\012+\013+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*aric.r.di<.f> %b,[cm:GPA1],[xd:%c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\007+\012+\013+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aric{ bw}.r.di<.f> b,[xa:c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aric.r.f.di%>+\002+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aric{ bw}.r.di<.f> b,[sd:c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aric.r.f.di%>+\002+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* aric{ bw}.r.di<.f> b,[xd:c]*/
  {(unsigned char *)"aric.r.di%.f%>+\002+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aric.r.f.di%>+\002+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xex{ bw} b,b,[xa:c]*/
  {(unsigned char *)"xex%>+\005+\012+\013 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb%>+\005+\010+\012 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw%>+\005+\011+\013 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw} b,b,[sd:c]*/
  {(unsigned char *)"xex%>+\005+\006+\012+\013 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb%>+\005+\006+\010+\012 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw%>+\005+\006+\011+\013 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw} b,b,[xd:c]*/
  {(unsigned char *)"xex%>+\007+\012+\013 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb%>+\007+\010+\012 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw%>+\007+\011+\013 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw} b,b,[c]*/
  {(unsigned char *)"xex%>+\012+\013 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb%>+\010+\012 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw%>+\011+\013 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xex{ bw}.di b,b,[xa:c]*/
  {(unsigned char *)"xex.di%>+\005+\012+\013+\016 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb.di%>+\005+\010+\012+\016 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\005+\011+\013+\016 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw}.di b,b,[sd:c]*/
  {(unsigned char *)"xex.di%>+\005+\006+\012+\013+\016 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb.di%>+\005+\006+\010+\012+\016 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\005+\006+\011+\013+\016 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw}.di b,b,[xd:c]*/
  {(unsigned char *)"xex.di%>+\007+\012+\013+\016 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb.di%>+\007+\010+\012+\016 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\007+\011+\013+\016 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xex{ bw}.di b,b,[c]*/
  {(unsigned char *)"xex.di%>+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexb.di%>+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xexw.di%>+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* exc{ bw} b,b,[xa:c]*/
  {(unsigned char *)"exc%>+\000+\005+\012+\013 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb%>+\000+\005+\010+\012 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw%>+\000+\005+\011+\013 %b,%b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* exc{ bw} b,b,[sd:c]*/
  {(unsigned char *)"exc%>+\000+\005+\006+\012+\013 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb%>+\000+\005+\006+\010+\012 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw%>+\000+\005+\006+\011+\013 %b,%b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* exc{ bw} b,b,[xd:c]*/
  {(unsigned char *)"exc%>+\000+\007+\012+\013 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb%>+\000+\007+\010+\012 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw%>+\000+\007+\011+\013 %b,%b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* exc.di{ bw} b,b,[c]*/
  {(unsigned char *)"exc.di%>+\000+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.di%>+\000+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.di%>+\000+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* exc{ bw}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"exc.di%.f%>+\000+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"exc.f.di%>+\000+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.di%.f%>+\000+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.f.di%>+\000+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.di%.f%>+\000+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.f.di%>+\000+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* exc{ bw}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"exc.di%.f%>+\000+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"exc.f.di%>+\000+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.di%.f%>+\000+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.f.di%>+\000+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.di%.f%>+\000+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.f.di%>+\000+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* exc{ bw}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"exc.di%.f%>+\000+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"exc.f.di%>+\000+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.di%.f%>+\000+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excb.f.di%>+\000+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.di%.f%>+\000+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"excw.f.di%>+\000+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di [cm:GPA2],b,[c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\014+\015+\016+\017 [cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\012+\014+\015+\016+\017 [cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di<.f> b,[cm:GPA2],b,[c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\012+\014+\015+\016 %b,[cm:GPA2],%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di b,[xa:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\005+\011+\012+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\005+\011+\014+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di b,[sd:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\005+\006+\011+\012+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\005+\006+\011+\014+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di b,[xd:c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\007+\011+\012+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\007+\011+\014+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\005+\011+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\005+\011+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\005+\011+\014+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\005+\011+\014+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\005+\006+\011+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\005+\006+\011+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\005+\006+\011+\014+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\005+\006+\011+\014+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\007+\011+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\007+\011+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\007+\011+\014+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\007+\011+\014+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di b,[c]*/
  {(unsigned char *)"adadd.di%>+\000+\001+\011+\014+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%>+\000+\001+\011+\012+\014+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* adadd{ l}.di<.f> b,b,[c]*/
  {(unsigned char *)"adadd.di%.f%>+\000+\001+\011+\014+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adadd.f.di%>+\000+\001+\011+\014+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.di%.f%>+\000+\001+\011+\012+\014+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"adaddl.f.di%>+\000+\001+\011+\012+\014+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di b,[xa:c]*/
  {(unsigned char *)"aand.di%>+\002+\005+\012+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%>+\002+\005+\010+\012+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\005+\011+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di b,[sd:c]*/
  {(unsigned char *)"aand.di%>+\002+\005+\006+\012+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%>+\002+\005+\006+\010+\012+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\005+\006+\011+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di b,[xd:c]*/
  {(unsigned char *)"aand.di%>+\002+\007+\012+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%>+\002+\007+\010+\012+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\007+\011+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"aand.di%.f%>+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.f.di%>+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%.f%>+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.f.di%>+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%.f%>+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.f.di%>+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"aand.di%.f%>+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.f.di%>+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%.f%>+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.f.di%>+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%.f%>+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.f.di%>+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"aand.di%.f%>+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.f.di%>+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%.f%>+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.f.di%>+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%.f%>+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.f.di%>+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}.di b,[c]*/
  {(unsigned char *)"aand.di%>+\002+\012+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%>+\002+\010+\012+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%>+\002+\011+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aand{ bw}<.di><.f> b,b,[c]*/
  {(unsigned char *)"aand.di%.f%>+\002+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aand.f.di%>+\002+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.di%.f%>+\002+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandb.f.di%>+\002+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.di%.f%>+\002+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aandw.f.di%>+\002+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di b,[xa:c]*/
  {(unsigned char *)"aor.di%>+\000+\002+\005+\012+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%>+\000+\002+\005+\010+\012+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\005+\011+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di b,[sd:c]*/
  {(unsigned char *)"aor.di%>+\000+\002+\005+\006+\012+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%>+\000+\002+\005+\006+\010+\012+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\005+\006+\011+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di b,[xd:c]*/
  {(unsigned char *)"aor.di%>+\000+\002+\007+\012+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%>+\000+\002+\007+\010+\012+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\007+\011+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"aor.di%.f%>+\000+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.f.di%>+\000+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%.f%>+\000+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.f.di%>+\000+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%.f%>+\000+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.f.di%>+\000+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"aor.di%.f%>+\000+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.f.di%>+\000+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%.f%>+\000+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.f.di%>+\000+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%.f%>+\000+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.f.di%>+\000+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"aor.di%.f%>+\000+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.f.di%>+\000+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%.f%>+\000+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.f.di%>+\000+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%.f%>+\000+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.f.di%>+\000+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di b,[c]*/
  {(unsigned char *)"aor.di%>+\000+\002+\012+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%>+\000+\002+\010+\012+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%>+\000+\002+\011+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* aor{ bw}.di<.f> b,b,[c]*/
  {(unsigned char *)"aor.di%.f%>+\000+\002+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aor.f.di%>+\000+\002+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.di%.f%>+\000+\002+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorb.f.di%>+\000+\002+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.di%.f%>+\000+\002+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"aorw.f.di%>+\000+\002+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di b,[xa:c]*/
  {(unsigned char *)"axor.di%>+\001+\002+\005+\012+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%>+\001+\002+\005+\010+\012+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\005+\011+\013+\016+\017 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di b,[sd:c]*/
  {(unsigned char *)"axor.di%>+\001+\002+\005+\006+\012+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%>+\001+\002+\005+\006+\010+\012+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\005+\006+\011+\013+\016+\017 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di b,[xd:c]*/
  {(unsigned char *)"axor.di%>+\001+\002+\007+\012+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%>+\001+\002+\007+\010+\012+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\007+\011+\013+\016+\017 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di<.f> b,b,[xa:c]*/
  {(unsigned char *)"axor.di%.f%>+\001+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.f.di%>+\001+\002+\005+\012+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%.f%>+\001+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.f.di%>+\001+\002+\005+\010+\012+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%.f%>+\001+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.f.di%>+\001+\002+\005+\011+\013+\016 %b,%b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di<.f> b,b,[sd:c]*/
  {(unsigned char *)"axor.di%.f%>+\001+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.f.di%>+\001+\002+\005+\006+\012+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%.f%>+\001+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.f.di%>+\001+\002+\005+\006+\010+\012+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%.f%>+\001+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.f.di%>+\001+\002+\005+\006+\011+\013+\016 %b,%b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di<.f> b,b,[xd:c]*/
  {(unsigned char *)"axor.di%.f%>+\001+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.f.di%>+\001+\002+\007+\012+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%.f%>+\001+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.f.di%>+\001+\002+\007+\010+\012+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%.f%>+\001+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.f.di%>+\001+\002+\007+\011+\013+\016 %b,%b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di b,[c]*/
  {(unsigned char *)"axor.di%>+\001+\002+\012+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%>+\001+\002+\010+\012+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%>+\001+\002+\011+\013+\016+\017 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* axor{ bw}.di<.f> b,b,[c]*/
  {(unsigned char *)"axor.di%.f%>+\001+\002+\012+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axor.f.di%>+\001+\002+\012+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.di%.f%>+\001+\002+\010+\012+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorb.f.di%>+\001+\002+\010+\012+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.di%.f%>+\001+\002+\011+\013+\016 %b,%b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"axorw.f.di%>+\001+\002+\011+\013+\016 %b,%b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* atst{ bw}.di<.f> b,[xa:c]*/
  {(unsigned char *)"atst.di%.f%>+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.f.di%>+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.di%.f%>+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.f.di%>+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%.f%>+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.f.di%>+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* atst{ bw}.di<.f> b,[sd:c]*/
  {(unsigned char *)"atst.di%.f%>+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.f.di%>+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.di%.f%>+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.f.di%>+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%.f%>+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.f.di%>+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* atst{ bw}.di<.f> b,[xd:c]*/
  {(unsigned char *)"atst.di%.f%>+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.f.di%>+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.di%.f%>+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.f.di%>+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%.f%>+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.f.di%>+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* atst{ bw}.di [c]*/
  {(unsigned char *)"atst.di%>+\004+\012+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.di%>+\004+\010+\012+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%>+\004+\011+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* atst{ bw}.di<.f> b,[c]*/
  {(unsigned char *)"atst.di%.f%>+\004+\012+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atst.f.di%>+\004+\012+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.di%.f%>+\004+\010+\012+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstb.f.di%>+\004+\010+\012+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.di%.f%>+\004+\011+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"atstw.f.di%>+\004+\011+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* ari{ bw}.di<.f> b,[xa:c]*/
  {(unsigned char *)"ari.di%.f%>+\000+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.f.di%>+\000+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.di%.f%>+\000+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.f.di%>+\000+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%.f%>+\000+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.f.di%>+\000+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ari{ bw}.di<.f> b,[sd:c]*/
  {(unsigned char *)"ari.di%.f%>+\000+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.f.di%>+\000+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.di%.f%>+\000+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.f.di%>+\000+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%.f%>+\000+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.f.di%>+\000+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ari{ bw}.di<.f> b,[xd:c]*/
  {(unsigned char *)"ari.di%.f%>+\000+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.f.di%>+\000+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.di%.f%>+\000+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.f.di%>+\000+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%.f%>+\000+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.f.di%>+\000+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ariw.di<.f> b,[mbd:c]*/
  {(unsigned char *)"ariw.di%.f%>+\000+\004+\005+\006+\007+\011+\013+\016 %b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.f.di%>+\000+\004+\005+\006+\007+\011+\013+\016 %b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* ari{ bw}.di [c]*/
  {(unsigned char *)"ari.di%>+\000+\004+\012+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.di%>+\000+\004+\010+\012+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%>+\000+\004+\011+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* ari{ bw}.di<.f> b,[c]*/
  {(unsigned char *)"ari.di%.f%>+\000+\004+\012+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ari.f.di%>+\000+\004+\012+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.di%.f%>+\000+\004+\010+\012+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arib.f.di%>+\000+\004+\010+\012+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.di%.f%>+\000+\004+\011+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ariw.f.di%>+\000+\004+\011+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

/* ardc{ bw}.di<.f> b,[xa:c]*/
  {(unsigned char *)"ardc.di%.f%>+\001+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.f.di%>+\001+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.di%.f%>+\001+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.f.di%>+\001+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%.f%>+\001+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.f.di%>+\001+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ardc{ bw}.di<.f> b,[sd:c]*/
  {(unsigned char *)"ardc.di%.f%>+\001+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.f.di%>+\001+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.di%.f%>+\001+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.f.di%>+\001+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%.f%>+\001+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.f.di%>+\001+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ardc{ bw}.di<.f> b,[xd:c]*/
  {(unsigned char *)"ardc.di%.f%>+\001+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.f.di%>+\001+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.di%.f%>+\001+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.f.di%>+\001+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%.f%>+\001+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.f.di%>+\001+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* ardcw.di<.f> b,[mbd:c]*/
  {(unsigned char *)"ardcw.di%.f%>+\001+\004+\005+\006+\007+\011+\013+\016 %b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.f.di%>+\001+\004+\005+\006+\007+\011+\013+\016 %b,[mbd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* ardc{ bw}.di [c]*/
  {(unsigned char *)"ardc.di%>+\001+\004+\012+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.di%>+\001+\004+\010+\012+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%>+\001+\004+\011+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* ardc{ bw}.di<.f> b,[c]*/
  {(unsigned char *)"ardc.di%.f%>+\001+\004+\012+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardc.f.di%>+\001+\004+\012+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.di%.f%>+\001+\004+\010+\012+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcb.f.di%>+\001+\004+\010+\012+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.di%.f%>+\001+\004+\011+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"ardcw.f.di%>+\001+\004+\011+\013+\016 %b,[%c]", 0xf81f, 0x4816, ARCOMPACT, 0, 0 ,0,0},

  /*arcl{ l}.di [cm:GPA1],[xa:c]*/
  {(unsigned char *)"arcl.di%>+\000+\002+\004+\005+\012+\013+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcll.di%>+\000+\002+\004+\005+\014+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ lbw}.di [cm:GPA1],[sd:c]*/
  {(unsigned char *)"arcl.di%>+\000+\002+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%>+\000+\002+\004+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%>+\000+\002+\004+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcll.di%>+\000+\002+\004+\005+\006+\014+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ lbw}.di [cm:GPA1],[xd:c]*/
  {(unsigned char *)"arcl.di%>+\000+\002+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%>+\000+\002+\004+\007+\010+\012+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%>+\000+\002+\004+\007+\011+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcll.di%>+\000+\002+\004+\007+\014+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ l}.di [cm:GPA2],[c]*/
  {(unsigned char *)"arcll.di%>+\000+\002+\004+\014+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcl.di%>+\000+\002+\004+\012+\013+\015+\016+\017 [cm:GPA2],[%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcll.di<.f> b,[cm:GPA1],[xa:c]*/
  {(unsigned char *)"arcll.di%.f%>+\000+\002+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcll.di<.f> b,[cm:GPA1],[sd:c]*/
  {(unsigned char *)"arcll.di%.f%>+\000+\002+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcll.di<.f> b,[cm:GPA1],[xd:c]*/
  {(unsigned char *)"arcll.di%.f%>+\000+\002+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ bw}.di<.f> b,[xa:c]*/
  {(unsigned char *)"arcl.di%.f%>+\000+\002+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcl.f.di%>+\000+\002+\004+\005+\012+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%.f%>+\000+\002+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.f.di%>+\000+\002+\004+\005+\010+\012+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%.f%>+\000+\002+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.f.di%>+\000+\002+\004+\005+\011+\013+\016 %b,[xa:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ bw}.di<.f> b,[sd:c]*/
  {(unsigned char *)"arcl.di%.f%>+\000+\002+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcl.f.di%>+\000+\002+\004+\005+\006+\012+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%.f%>+\000+\002+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.f.di%>+\000+\002+\004+\005+\006+\010+\012+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%.f%>+\000+\002+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.f.di%>+\000+\002+\004+\005+\006+\011+\013+\016 %b,[sd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ bw}.di<.f> b,[xd:c]*/
  {(unsigned char *)"arcl.di%.f%>+\000+\002+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcl.f.di%>+\000+\002+\004+\007+\012+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%.f%>+\000+\002+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.f.di%>+\000+\002+\004+\007+\010+\012+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%.f%>+\000+\002+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.f.di%>+\000+\002+\004+\007+\011+\013+\016 %b,[xd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ bwl}.di [c]*/
  {(unsigned char *)"arcl.di%>+\000+\002+\004+\012+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%>+\000+\002+\004+\010+\012+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%>+\000+\002+\004+\011+\013+\016+\017 [%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcll.di%>+\000+\002+\004+\014+\016+\017 [%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcl{ bw}.di<.f> b,[c]*/
  {(unsigned char *)"arcl.di%.f%>+\000+\002+\004+\012+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arcl.f.di%>+\000+\002+\004+\012+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.di%.f%>+\000+\002+\004+\010+\012+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclb.f.di%>+\000+\002+\004+\010+\012+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.di%.f%>+\000+\002+\004+\011+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"arclw.f.di%>+\000+\002+\004+\011+\013+\016 %b,[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*arcll.di<.f> b,[cm:GPA2],[c]*/
  {(unsigned char *)"arcll.di%.f%>+\000+\002+\004+\014+\015+\016 %b,[cm:GPA2],[%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

  /****************************/
/*xld{ l}.di [cm:GPA1],[xa:%c]*/
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\005+\014+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xld.di%>+\001+\002+\004+\005+\012+\013+\015+\016+\017 [cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*xld{ bwl}.di [cm:GPA1],[sd:%c]*/
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\005+\006+\011+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\005+\006+\014+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xld.di%>+\001+\002+\004+\005+\006+\012+\013+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldb.di%>+\001+\002+\004+\005+\006+\010+\012+\015+\016+\017 [cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*xld{ bwl}.di [cm:GPA1],[xd:%c]*/
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\007+\011+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\007+\014+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xld.di%>+\001+\002+\004+\007+\012+\013+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldb.di%>+\001+\002+\004+\007+\010+\012+\015+\016+\017 [cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xldw.di b,[mbd:c]*/
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\005+\006+\007+\011+\013+\016 %b,[mbd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xld{ bw}.di b,[xa:c]*/
  {(unsigned char *)"xld.di%>+\001+\002+\004+\005+\012+\013+\016 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldb.di%>+\001+\002+\004+\005+\010+\012+\016 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\005+\011+\013+\016 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xld{ bw}.di b,[sd:c]*/
  {(unsigned char *)"xld.di%>+\001+\002+\004+\005+\006+\012+\013+\016 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldb.di%>+\001+\002+\004+\005+\006+\010+\012+\016 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\005+\006+\011+\013+\016 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* xld{ bw}.di b,[xd:c]*/
  {(unsigned char *)"xld.di%>+\001+\002+\004+\007+\012+\013+\016 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldb.di%>+\001+\002+\004+\007+\010+\012+\016 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xldw.di%>+\001+\002+\004+\007+\011+\013+\016 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*xldl.di %b,[cm:GPA1],[xa:%c]*/
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\005+\014+\015+\016 %b,[cm:GPA1],[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*xldl.di %b,[cm:GPA1],[sd:%c]*/
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\005+\006+\014+\015+\016 %b,[cm:GPA1],[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*xldl.di %b,[cm:GPA1],[xd:%c]*/
  {(unsigned char *)"xldl.di%>+\001+\002+\004+\007+\014+\015+\016 %b,[cm:GPA1],[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xst{ bwl}.di b,[xa:c]*/
  {(unsigned char *)"xst.di%>+\000+\001+\002+\005+\012+\013+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstb.di%>+\000+\001+\002+\005+\010+\012+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstw.di%>+\000+\001+\002+\005+\011+\013+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstl.di%>+\000+\001+\002+\005+\010+\011+\014+\016+\017 %b,[xa:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xst{ bwl}.di b,[sd:c]*/
  {(unsigned char *)"xst.di%>+\000+\001+\002+\005+\006+\012+\013+\016+\017 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstb.di%>+\000+\001+\002+\005+\006+\010+\012+\016+\017 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstw.di%>+\000+\001+\002+\005+\006+\011+\013+\016+\017 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstl.di%>+\000+\001+\002+\005+\006+\010+\011+\014+\016+\017 %b,[sd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xst{ bwl}.di b,[xd:c]*/
  {(unsigned char *)"xst.di%>+\000+\001+\002+\007+\012+\013+\016+\017 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstb.di%>+\000+\001+\002+\007+\010+\012+\016+\017 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstw.di%>+\000+\001+\002+\007+\011+\013+\016+\017 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"xstl.di%>+\000+\001+\002+\007+\010+\011+\014+\016+\017 %b,[xd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* xstw.di b,[mbd:c]*/
  {(unsigned char *)"xstw.di%>+\000+\001+\002+\005+\006+\007+\011+\013+\016+\017 %b,[mbd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* cinit.di [cm:GPA2],SRC1,[{ s}cd:SRC2]  */
  {(unsigned char *)"cinit.di%>+\006+\007+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cinit.di%>+\006+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cinit.di<.f> DST,[cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cinit.di%.f%>+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cinit.f.di%>+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cinit.di%.f%>+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cinit.f.di%>+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cinit.di SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cinit.di%>+\006+\007+\010+\011+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cinit.di%>+\006+\010+\011+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.di [cm:GPA2],SRC1,[{ s}cd:SRC2]  */
  {(unsigned char *)"cminit.di%>+\000+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.di%>+\000+\003+\004+\006+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.di<.f> DST,[cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cminit.di%.f%>+\000+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.f.di%>+\000+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.di%.f%>+\000+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.f.di%>+\000+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.di SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cminit.di%>+\000+\003+\004+\006+\007+\010+\011+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.di%>+\000+\003+\004+\006+\010+\011+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.rst.di [cm:GPA2],SRC1,[{ s}cd:SRC2]  */
  {(unsigned char *)"cminit.rst.di%>+\001+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.rst.di%>+\001+\003+\004+\006+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.rst.di<.f> DST,[cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cminit.rst.di%.f%>+\001+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.rst.di%.f%>+\001+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cminit.rst.di SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cminit.rst.di%>+\001+\003+\004+\006+\007+\010+\011+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cminit.rst.di%>+\001+\003+\004+\006+\010+\011+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* crd.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"crd.di%>+\001+\002+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crd.di%>+\001+\002+\003+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* crd.di<.f> DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"crd.di%.f%>+\001+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crd.f.di%>+\001+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crd.di%.f%>+\001+\002+\003+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crd.f.di%>+\001+\002+\003+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cwrdb.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cwrdb.di%>+\000+\001+\003+\004+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrdb.di%>+\000+\001+\003+\004+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cwrdb.di<.f> DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cwrdb.di%.f%>+\000+\001+\003+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrdb.f.di%>+\000+\001+\003+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrdb.di%.f%>+\000+\001+\003+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrdb.f.di%>+\000+\001+\003+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cwrde.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cwrde.di%>+\002+\003+\004+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrde.di%>+\002+\003+\004+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cwrde.di<.f> DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cwrde.di%.f%>+\002+\003+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrde.f.di%>+\002+\003+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrde.di%.f%>+\002+\003+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwrde.f.di%>+\002+\003+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* crst.di [{ s}cd:SRC2] */
  {(unsigned char *)"crst.di%>+\000+\006+\007+\012+\014+\016+\017 [cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crst.di%>+\000+\006+\012+\014+\016+\017 [scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* crst.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"crst.di%>+\000+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crst.di%>+\000+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* crst.di<.f> DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"crst.di%.f%>+\000+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crst.f.di%>+\000+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crst.di%.f%>+\000+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"crst.f.di%>+\000+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr.di%>+\001+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr.di%>+\001+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr.di%.f%>+\001+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cincr.f.di%>+\001+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr.di<.f> DST,SRC1,[cd:SRC2],SRC1 */
  {(unsigned char *)"cincr.di%.f%>+\001+\006+\007+\012+\014+\016 %b,%b,[cd:%c],%b%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cincr.f.di%>+\001+\006+\007+\012+\014+\016 %b,%b,[cd:%c],%b%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr.di%>+\000+\001+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr.di%>+\000+\001+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr.di%.f%>+\000+\001+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdecr.f.di%>+\000+\001+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr.di<.f> DST,SRC1,[cd:SRC2],SRC1 */
  {(unsigned char *)"cdecr.di%.f%>+\000+\001+\006+\007+\012+\014+\016 %b,%b,[cd:%c],%b%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdecr.f.di%>+\000+\001+\006+\007+\012+\014+\016 %b,%b,[cd:%c],%b%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr1.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr1.di%>+\001+\002+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr1.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr1.di%>+\001+\002+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr1.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr1.di%.f%>+\001+\002+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cincr1.f.di%>+\001+\002+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cincr1.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cincr1.di%.f%>+\001+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cincr1.f.di%>+\001+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr1.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr1.di%>+\000+\001+\002+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr1.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr1.di%>+\000+\001+\002+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr1.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr1.di%.f%>+\000+\001+\002+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdecr1.f.di%>+\000+\001+\002+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecr1.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecr1.di%.f%>+\000+\001+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdecr1.f.di%>+\000+\001+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecrc.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecrc.di%>+\000+\004+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecrc.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecrc.di%>+\000+\004+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdecrc.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdecrc.di%.f%>+\000+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdecrc.f.di%>+\000+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdincr.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdincr.di%>+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdincr.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cdincr.di%>+\003+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cdincr.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cdincr.di%.f%>+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cdincr.f.di%>+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbset.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbset.di%>+\001+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cbset.di<.f> b,[cm:GPA2],b,[cd:c]*/
  {(unsigned char *)"cbset.di%.f%>+\001+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbset.f.di%>+\001+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbset.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cbset.di%>+\001+\003+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbset.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cbset.di%.f%>+\001+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbset.f.di%>+\001+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbclr.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbclr.di%>+\000+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cbclr.di<.f> b,[cm:GPA2],b,[cd:c]*/
  {(unsigned char *)"cbclr.di%.f%>+\000+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbclr.f.di%>+\000+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbclr.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cbclr.di%>+\000+\003+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbclr.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cbclr.di%.f%>+\000+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbclr.f.di%>+\000+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbwr.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbwr.di%>+\002+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbwr.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cbwr.di%>+\002+\003+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cbwr.di<.f> b,[cm:GPA2],b,[cd:c]*/
  {(unsigned char *)"cbwr.di%.f%>+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbwr.f.di%>+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbwr.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cbwr.di%.f%>+\002+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbwr.f.di%>+\002+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbrd.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbrd.di%>+\000+\002+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbrd.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbrd.di%.f%>+\000+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbrd.f.di%>+\000+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbrd.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cbrd.di%.f%>+\000+\002+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbrd.f.di%>+\000+\002+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbcswp.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbcswp.di%>+\000+\001+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbcswp.di<.f> DST,[cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cbcswp.di%.f%>+\000+\001+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbcswp.f.di%>+\000+\001+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cbcswp.di<.f> DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cbcswp.di%.f%>+\000+\001+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cbcswp.f.di%>+\000+\001+\003+\006+\007+\012+\014+\016 %b,%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cftch.di [cd:SRC2] */
  {(unsigned char *)"cftch.di%>+\001+\002+\004+\006+\007+\012+\014+\016+\017 [cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cgetc.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cgetc.di%>+\002+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cgetc.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cgetc.di%>+\002+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cgetc.di DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cgetc.di%>+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cchkc.di [cm:GPA2],SRC1,[cd:SRC2] */
  {(unsigned char *)"cchkc.di%>+\000+\002+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cchkc.di SRC1,[cd:SRC2] */
  {(unsigned char *)"cchkc.di%>+\000+\002+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cchkc.di DST,SRC1,[cd:SRC2] */
  {(unsigned char *)"cchkc.di%>+\000+\002+\006+\007+\012+\014+\016 %b,%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cld.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cld.di%>+\000+\001+\002+\003+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cld.di%>+\000+\001+\002+\003+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cld.di DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cld.di%>+\000+\001+\002+\003+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cld.di%>+\000+\001+\002+\003+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cmld.di [cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cmld.di%>+\000+\001+\002+\004+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cmld.di%>+\000+\001+\002+\004+\006+\012+\014+\015+\016+\017 [cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cmld.di DST,[cm:GPA2],[{ s}cd:SRC2] */
  {(unsigned char *)"cmld.di%>+\000+\001+\002+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cmld.di%>+\000+\001+\002+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cst.di [cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cst.di%>+\004+\006+\007+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cst.di%>+\004+\006+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cst.di SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cst.di%>+\004+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cst.di%>+\004+\006+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cst.di DST,[cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cst.di%>+\004+\006+\007+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cst.di%>+\004+\006+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cmst.di [cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cmst.di SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\007+\010+\011+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\010+\011+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/* cmst.di DST,[cm:GPA2],SRC1,[{ s}cd:SRC2] */
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cmst.di%>+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*cwcfg.di [cm:GPA2],b,[{ s}cd:c]*/
  {(unsigned char *)"cwcfg.di%>+\001+\002+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwcfg.di%>+\001+\002+\003+\004+\006+\010+\011+\012+\014+\015+\016+\017 [cm:GPA2],%b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cwcfg.di b,[{ s}cd:c]*/
  {(unsigned char *)"cwcfg.di%>+\001+\002+\003+\004+\006+\007+\010+\011+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwcfg.di%>+\001+\002+\003+\004+\006+\010+\011+\012+\014+\016+\017 %b,[scd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cwcfg.di<.f> b,[cm:GPA2],b,[{ s}cd:c]*/
  {(unsigned char *)"cwcfg.di%.f%>+\001+\002+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwcfg.f.di%>+\001+\002+\003+\004+\006+\007+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwcfg.di%.f%>+\001+\002+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwcfg.f.di%>+\001+\002+\003+\004+\006+\010+\011+\012+\014+\015+\016 %b,[cm:GPA2],%b,[scd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/*cwchk.di b,[cd:c]*/
  {(unsigned char *)"cwchk.di%>+\000+\001+\002+\003+\004+\006+\007+\012+\014+\016+\017 %b,[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cwchk.di %b,[cm:GPA2],[cd:c]*/
  {(unsigned char *)"cwchk.di%>+\000+\001+\002+\003+\004+\006+\007+\012+\014+\015+\016+\017 %b,[cm:GPA2],[cd:%c]", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
/*cwchk.di<.f> %b,%b,[cm:GPA2],[cd:c]*/
  {(unsigned char *)"cwchk.di%.f%>+\000+\001+\002+\003+\004+\006+\007+\012+\014+\015+\016 %b,%b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"cwchk.f.di%>+\000+\001+\002+\003+\004+\006+\007+\012+\014+\015+\016 %b,%b,[cm:GPA2],[cd:%c]%(", 0xf81f, 0x4806, ARCOMPACT, 0, 0 ,0,0},

/* bdlen<.f> b,b,c,Len */
  {(unsigned char *)"bdlen%.f%>+\000+\001+\004+\017 %b,%b,%c,%\375%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* bdlen<.f> b,b,c */
  {(unsigned char *)"bdlen%.f%>+\000+\001+\004+\016+\017 %b,%b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* bdlen<.f> b,c,Len */
  {(unsigned char *)"bdlen%.f%>+\000+\001+\004 %b,%c,%\375%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* bdlen<.f> b,c */
  {(unsigned char *)"bdlen%.f%>+\000+\001+\004+\016 %b,%c%(", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},

/* xldb b,[v16] */
  {(unsigned char *)"xldb%> %*,[%\236]", 0xf81f, 0x5fc8, ARCOMPACT, 0, 0 ,0,0},
/* xldw b,[v16] */
  {(unsigned char *)"xldw%> %*,[%\236]", 0xf81f, 0x5fc9, ARCOMPACT, 0, 0 ,0,0},
/* xld b,[v16] */
  {(unsigned char *)"xld%> %*,[%\236]", 0xf81f, 0x5fca, ARCOMPACT, 0, 0 ,0,0},
/* xstb b,[v16] */
  {(unsigned char *)"xstb%> %*,[%\236]", 0xf81f, 0x5fcc, ARCOMPACT, 0, 0 ,0,0},
/* xstw b,[v16] */
  {(unsigned char *)"xstw%> %*,[%\236]", 0xf81f, 0x5fcd, ARCOMPACT, 0, 0 ,0,0},
/* xst b,[v16] */
  {(unsigned char *)"xst%> %*,[%\236]", 0xf81f, 0x5fce, ARCOMPACT, 0, 0 ,0,0},

/* andab<.f> b,c,pos,size */
  {(unsigned char *)"andab%>%.f+\000+\004 %b,%c,%\221,%\222%(%\14", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* orab<.f> b,c,pos,size */
  {(unsigned char *)"orab%>%.f+\001+\004 %b,%c,%\221,%\222%(%\14", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* andab<.f> b,b,c,pos,size */
  {(unsigned char *)"andab%>%.f+\000+\004+\017 %b,%b,%c,%\221,%\222%(%\14", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},
/* orab<.f> b,b,c,pos,size */
  {(unsigned char *)"orab%>%.f+\001+\004+\017 %b,%b,%c,%\221,%\222%(%\14", 0xf81f, 0x4800, ARCOMPACT, 0, 0 ,0,0},

/* bdbgt a,b,c */
  {(unsigned char *)"bdbgt %A,%B,%C" , 0xf8ff0000, 0x38180000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"bdbgt 0,%B,%C" , 0xf8ff003f, 0x3818003e, ARCOMPACT, 0, 0 ,0,0},
/* sbdfre a,b,c */
  {(unsigned char *)"sbdfre %A,%B,%C" , 0xf8ff0000, 0x38170000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"sbdfre 0,%B,%C" , 0xf8ff003f, 0x3817003e, ARCOMPACT, 0, 0 ,0,0},
/* idxbgt a,b,c */
  {(unsigned char *)"idxbgt %A,%B,%C" , 0xf8ff0000, 0x38190000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"idxbgt 0,%B,%C" , 0xf8ff003f, 0x3819003e, ARCOMPACT, 0, 0 ,0,0},
/* jobbgt a,b,c */
  {(unsigned char *)"jobbgt %A,%B,%C" , 0xf8ff0000, 0x381a0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"jobbgt 0,%B,%C" , 0xf8ff003f, 0x381a003e, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* efabgt a,b,c */
  {(unsigned char *)"efabgt %A,%B,%C" , 0xf8ff0000, 0x380d0000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"efabgt 0,%B,%C" , 0xf8ff003f, 0x380d003e, ARCOMPACT, 0, 0 ,0,0},
/* efabgt a,limm,c */
  {(unsigned char *)"efabgt %A,%L,%C" , 0xf8ff0000, 0x3E0d7000, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"efabgt 0,%L,%C" , 0xf8ff003f, 0x3E0d703e, ARCOMPACT, 0, 0 ,0,0},
/* efabgt a,b,limm */
  {(unsigned char *)"efabgt %A,%B,%L" , 0xf8ff0000, 0x380d0f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"efabgt 0,%B,%L" , 0xf8ff003f, 0x380d0fbe, ARCOMPACT, 0, 0 ,0,0},
/* efabgt a,limm,limm */
  {(unsigned char *)"efabgt %A,%L,%L" , 0xf8ff0000, 0x3E0d7f80, ARCOMPACT, 0, 0 ,0,0},
  {(unsigned char *)"efabgt 0,%L,%L" , 0xf8ff003f, 0x3E0d7fbe, ARCOMPACT, 0, 0 ,0,0},
/****************************/
/* csma a,b,c*/
  {(unsigned char *)"csma %A,%B,%C" , 0xf8ff8000, 0x382A0000, ARCOMPACT, 0, 0 ,0,0},
/* csma a,b,u6*/
  {(unsigned char *)"csma %A,%B,%u" , 0xf8ff8000, 0x386A0000, ARCOMPACT, 0, 0 ,0,0},
/* csma a,b,limm*/
  {(unsigned char *)"csma%Q %A,%B,%L", 0xf8ff8fc0, 0x382A0f80, ARCOMPACT, 0, 0 ,0,0},
/* csma a,limm,c*/
  {(unsigned char *)"csma%Q %A,%L,%C", 0xfffff000, 0x3e2A7000, ARCOMPACT, 0, 0 ,0,0},
/* csma a,limm,u6*/
  {(unsigned char *)"csma%Q %A,%L,%u", 0xfffff000, 0x3e6A7000, ARCOMPACT, 0, 0 ,0,0},
/* csma a,limm,limm*/
  {(unsigned char *)"csma%Q %A,%L,%L", 0xffffffc0, 0x3e2A7f80, ARCOMPACT, 0, 0 ,0,0},
/* csma 0,b,c*/
  {(unsigned char *)"csma 0,%B,%C", 0xf8ff803f, 0x382A003e, ARCOMPACT, 0, 0 ,0,0},
/* csma 0,b,u6*/
  {(unsigned char *)"csma 0,%B,%u", 0xf8ff803f, 0x386A003e, ARCOMPACT, 0, 0 ,0,0},
/* csma 0,b,limm*/
  {(unsigned char *)"csma%Q 0,%B,%L", 0xf8ff8fff, 0x382A0fbe, ARCOMPACT, 0, 0 ,0,0},
/* csma 0,limm,c*/
  {(unsigned char *)"csma%Q 0,%L,%C", 0xfffff03f, 0x3e2A703e, ARCOMPACT, 0, 0 ,0,0},
/* csma 0,limm,u6*/
  {(unsigned char *)"csma%Q 0,%L,%u", 0xfffff000, 0x3eAA7000, ARCOMPACT, 0, 0 ,0,0},

  /****************************/
  /* csms a,b,c*/
    {(unsigned char *)"csms %A,%B,%C" , 0xf8ff8000, 0x382C0000, ARCOMPACT, 0, 0 ,0,0},
  /* csms a,b,u6*/
    {(unsigned char *)"csms %A,%B,%u" , 0xf8ff8000, 0x386C0000, ARCOMPACT, 0, 0 ,0,0},
  /* csms a,b,limm*/
    {(unsigned char *)"csms%Q %A,%B,%L", 0xf8ff8fc0, 0x382C0f80, ARCOMPACT, 0, 0 ,0,0},
  /* csms a,limm,c*/
    {(unsigned char *)"csms%Q %A,%L,%C", 0xfffff000, 0x3e2C7000, ARCOMPACT, 0, 0 ,0,0},
  /* csms a,limm,u6*/
    {(unsigned char *)"csms%Q %A,%L,%u", 0xfffff000, 0x3e6C7000, ARCOMPACT, 0, 0 ,0,0},
  /* csms a,limm,limm*/
    {(unsigned char *)"csms%Q %A,%L,%L", 0xffffffc0, 0x3e2C7f80, ARCOMPACT, 0, 0 ,0,0},
  /* csms 0,b,c*/
    {(unsigned char *)"csms 0,%B,%C", 0xf8ff803f, 0x382C003e, ARCOMPACT, 0, 0 ,0,0},
  /* csms 0,b,u6*/
    {(unsigned char *)"csms 0,%B,%u", 0xf8ff803f, 0x386C003e, ARCOMPACT, 0, 0 ,0,0},
  /* csms 0,b,limm*/
    {(unsigned char *)"csms%Q 0,%B,%L", 0xf8ff8fff, 0x382C0fbe, ARCOMPACT, 0, 0 ,0,0},
  /* csms 0,limm,c*/
    {(unsigned char *)"csms%Q 0,%L,%C", 0xfffff03f, 0x3e2C703e, ARCOMPACT, 0, 0 ,0,0},
  /* csms 0,limm,u6*/
    {(unsigned char *)"csms%Q 0,%L,%u", 0xfffff000, 0x3eAC7000, ARCOMPACT, 0, 0 ,0,0},

/****************************/
/* cbba<.f> a,b,c*/
  {(unsigned char *)"cbba%.f %A,%B,%C%F" , 0xf8ff0000, 0x382D0000, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> a,b,u6*/
  {(unsigned char *)"cbba%.f %A,%B,%u%F" , 0xf8ff0000, 0x386D0000, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> a,b,limm*/
  {(unsigned char *)"cbba%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x382D0f80, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> a,limm,c*/
  {(unsigned char *)"cbba%.f%Q %A,%L,%C%F", 0xffff7000, 0x3e2D7000, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> a,limm,u6*/
  {(unsigned char *)"cbba%.f%Q %A,%L,%u%F", 0xffff7000, 0x3e6D7000, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> a,limm,limm*/
  {(unsigned char *)"cbba%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x3e2D7f80, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> 0,b,c*/
  {(unsigned char *)"cbba%.f 0,%B,%C%F", 0xf8ff003f, 0x382D003e, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> 0,b,u6*/
  {(unsigned char *)"cbba%.f 0,%B,%u%F", 0xf8ff003f, 0x386D003e, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> 0,b,limm*/
  {(unsigned char *)"cbba%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x382D0fbe, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> 0,limm,c*/
  {(unsigned char *)"cbba%.f%Q 0,%L,%C%F", 0xffff703f, 0x3e2D703e, ARCOMPACT, 0, 0 ,0,0},
/* cbba<.f> 0,limm,u6*/
  {(unsigned char *)"cbba%.f%Q 0,%L,%u%F", 0xffff7000, 0x3eAD7000, ARCOMPACT, 0, 0 ,0,0},

/****************************/
/* rflt a,b,c*/
  {(unsigned char *)"rflt %A,%B,%C" , 0xf8ff8000, 0x382E0000, ARCOMPACT, 0, 0 ,0,0},
/* rflt a,b,u6*/
  {(unsigned char *)"rflt %A,%B,%u%\241" , 0xf8ff8000, 0x386E0000, ARCOMPACT, 0, 0 ,0,0},
/* rflt a,b,limm*/
  {(unsigned char *)"rflt%Q %A,%B,%L", 0xf8ff8fc0, 0x382E0f80, ARCOMPACT, 0, 0 ,0,0},
/* rflt a,limm,c*/
  {(unsigned char *)"rflt%Q %A,%L,%C", 0xfffff000, 0x3e2E7000, ARCOMPACT, 0, 0 ,0,0},
/* rflt a,limm,u6*/
  {(unsigned char *)"rflt%Q %A,%L,%u%\241", 0xfffff000, 0x3e6E7000, ARCOMPACT, 0, 0 ,0,0},
/* rflt a,limm,limm*/
  {(unsigned char *)"rflt%Q %A,%L,%L", 0xffffffc0, 0x3e2E7f80, ARCOMPACT, 0, 0 ,0,0},
/* rflt 0,b,c*/
  {(unsigned char *)"rflt 0,%B,%C", 0xf8ff803f, 0x382E003e, ARCOMPACT, 0, 0 ,0,0},
/* rflt 0,b,u6*/
  {(unsigned char *)"rflt 0,%B,%u%\241", 0xf8ff803f, 0x386E003e, ARCOMPACT, 0, 0 ,0,0},
/* rflt 0,b,limm*/
  {(unsigned char *)"rflt%Q 0,%B,%L", 0xf8ff8fff, 0x382E0fbe, ARCOMPACT, 0, 0 ,0,0},
/* rflt 0,limm,c*/
  {(unsigned char *)"rflt%Q 0,%L,%C", 0xfffff03f, 0x3e2E703e, ARCOMPACT, 0, 0 ,0,0},
/* rflt 0,limm,u6*/
  {(unsigned char *)"rflt%Q 0,%L,%u%\241", 0xfffff000, 0x3eAE7000, ARCOMPACT, 0, 0 ,0,0},

/****************************/
/* crc16<.r> a,b,c*/
  {(unsigned char *)"crc16%.\337 %A,%B,%C" , 0xf8ff0000, 0x38330000, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> a,b,u6*/
  {(unsigned char *)"crc16%.\337 %A,%B,%u" , 0xf8ff0000, 0x38730000, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> a,b,limm*/
  {(unsigned char *)"crc16%.\337%Q %A,%B,%L", 0xf8ff0fc0, 0x38330f80, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> a,limm,c*/
  {(unsigned char *)"crc16%.\337%Q %A,%L,%C", 0xffff7000, 0x3e337000, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> a,limm,u6*/
  {(unsigned char *)"crc16%.\337%Q %A,%L,%u", 0xffff7000, 0x3e737000, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> a,limm,limm*/
  {(unsigned char *)"crc16%.\337%Q %A,%L,%L", 0xffff7fc0, 0x3e337f80, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> 0,b,c*/
  {(unsigned char *)"crc16%.\337 0,%B,%C", 0xf8ff003f, 0x3833003e, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> 0,b,u6*/
  {(unsigned char *)"crc16%.\337 0,%B,%u", 0xf8ff003f, 0x3873003e, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> 0,b,limm*/
  {(unsigned char *)"crc16%.\337%Q 0,%B,%L", 0xf8ff0fff, 0x38330fbe, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> 0,limm,c*/
  {(unsigned char *)"crc16%.\337%Q 0,%L,%C", 0xffff703f, 0x3e33703e, ARCOMPACT, 0, 0 ,0,0},
/* crc16<.r> 0,limm,u6*/
  {(unsigned char *)"crc16%.\337%Q 0,%L,%u", 0xffff7000, 0x3eB37000, ARCOMPACT, 0, 0 ,0,0},

/* crc32<.r> a,b,c*/
  {(unsigned char *)"crc32%.\337 %A,%B,%C" , 0xf8ff0000, 0x38340000, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> a,b,u6*/
  {(unsigned char *)"crc32%.\337 %A,%B,%u" , 0xf8ff0000, 0x38740000, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> a,b,limm*/
  {(unsigned char *)"crc32%.\337%Q %A,%B,%L", 0xf8ff0fc0, 0x38340f80, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> a,limm,c*/
  {(unsigned char *)"crc32%.\337%Q %A,%L,%C", 0xffff7000, 0x3e347000, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> a,limm,u6*/
  {(unsigned char *)"crc32%.\337%Q %A,%L,%u", 0xffff7000, 0x3e747000, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> a,limm,limm*/
  {(unsigned char *)"crc32%.\337%Q %A,%L,%L", 0xffff7fc0, 0x3e347f80, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> 0,b,c*/
  {(unsigned char *)"crc32%.\337 0,%B,%C", 0xf8ff003f, 0x3834003e, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> 0,b,u6*/
  {(unsigned char *)"crc32%.\337 0,%B,%u", 0xf8ff003f, 0x3874003e, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> 0,b,limm*/
  {(unsigned char *)"crc32%.\337%Q 0,%B,%L", 0xf8ff0fff, 0x38340fbe, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> 0,limm,c*/
  {(unsigned char *)"crc32%.\337%Q 0,%L,%C", 0xffff703f, 0x3e34703e, ARCOMPACT, 0, 0 ,0,0},
/* crc32<.r> 0,limm,u6*/
  {(unsigned char *)"crc32%.\337%Q 0,%L,%u", 0xffff7000, 0x3eB47000, ARCOMPACT, 0, 0 ,0,0},


