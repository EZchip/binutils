/* Opcode table for the ARC.
   Copyright 1994, 1995, 1997, 1998, 2000, 2001, 2002, 2004, 2005, 2007
   Free Software Foundation, Inc.
   Contributed by Doug Evans (dje@cygnus.com).

   Copyright 2007-2012 Synopsys Inc
   Contributor: Brendon Kehoe <brendan@zen.org>
   Contributor: Michael Eager <eager@eagercon.com>
   Contributor: Joern Rennecke <joern.rennecke@embecosm.com>
   Contributor: Claudiu Zissulescu <claziss@synopsys.com>

   This file is part of libopcodes.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */

#include "sysdep.h"
#include <stdio.h>
#include "ansidecl.h"
#include "opcode/arc.h"
#include "opintl.h"
#include <assert.h>

/* -------------------------------------------------------------------------- */
/*                                  local types                               */
/* -------------------------------------------------------------------------- */

enum operand {OP_NONE,OP_REG,OP_SHIMM,OP_LIMM};


/* -------------------------------------------------------------------------- */
/*                                 local macros                               */
/* -------------------------------------------------------------------------- */

#define ELEMENTS_IN(arr)    (sizeof (arr) / sizeof ((arr)[0]))


/* -------------------------------------------------------------------------- */
/*   prototypes for external functions (to calm -Werror=missing-prototypes)   */
/* -------------------------------------------------------------------------- */

extern unsigned char arc_get_branch_prediction(void);
extern void arc_reset_branch_prediction(void);
extern unsigned char em_jumplink_or_jump_insn(arc_insn insn,
					      int compact_insn16);
extern unsigned char em_branch_or_jump_insn(arc_insn insn,
					    int compact_insn16);

/* -------------------------------------------------------------------------- */
/*                      forward declarations of functions                     */
/* -------------------------------------------------------------------------- */
#ifdef ARC_NPS_CMDS
static int extraData16Value;
int extraData;
int flag335;
int prev335;
char *lastOpcodeSyntax;
extern char *getLastOpcodeSyntax();
int getExtraData16value(void);
void setExtraData16value(int value);
#endif // #ifdef ARC_NPS_CMDS

int arc_get_noshortcut_flag (void);

#define INSERT_FN(fn) \
static arc_insn fn (arc_insn, long *, const struct arc_operand *, \
		    int, const struct arc_operand_value *, long, \
		    const char **)

#define EXTRACT_FN(fn) \
static long fn (arc_insn *, const struct arc_operand *, \
		int, const struct arc_operand_value **, int *)

#ifndef ARC_NO_SIMD_CMDS
INSERT_FN (insert_u8);
INSERT_FN (insert_u16);
INSERT_FN (insert_uu16);
INSERT_FN (insert_ul16);
INSERT_FN (insert_null);
INSERT_FN (insert_s12);
INSERT_FN (insert_s15);
#endif  // #ifndef ARC_NO_SIMD_CMDS
INSERT_FN (insert_reg);
INSERT_FN (insert_shimmfinish);
INSERT_FN (insert_limmfinish);
INSERT_FN (insert_offset);
INSERT_FN (insert_base);
INSERT_FN (insert_st_syntax);
INSERT_FN (insert_ld_syntax);
INSERT_FN (insert_ex_syntax);
INSERT_FN (insert_addr_wb);
INSERT_FN (insert_flag);
INSERT_FN (insert_nullify);
INSERT_FN (insert_flagfinish);
INSERT_FN (insert_cond);
INSERT_FN (insert_forcelimm);
INSERT_FN (insert_reladdr);
INSERT_FN (insert_absaddr);
INSERT_FN (insert_jumpflags);
INSERT_FN (insert_unopmacro);
#ifdef ARC_NPS_CMDS
INSERT_FN (insert_force16);
INSERT_FN (insert_su16);
INSERT_FN (insert_nTo48);
INSERT_FN (insert_cmd_operand);
INSERT_FN (insert_valid_movb);
INSERT_FN (insert_valid_mrgb);
INSERT_FN (insert_valid_mov2b);
INSERT_FN (insert_valid_mov4b);
INSERT_FN (insert_clear_mov4b);
INSERT_FN (insert_valid_ext4b);
INSERT_FN (insert_valid_ins4b);
INSERT_FN (insert_valid_mxb);
INSERT_FN (insert_cmd16_32);
INSERT_FN (validate_u6_124);
INSERT_FN (insert_valid_arith);
INSERT_FN (insert_size_1248);
INSERT_FN (insert_skipRes);
INSERT_FN (dup_bits);
INSERT_FN (set_limm_p);
#endif // #ifdef ARC_NPS_CMDS

INSERT_FN(insert_v2_16);
INSERT_FN(insert_v2_Tflag);
INSERT_FN(insert_Ybit);
INSERT_FN(insert_Ybit_neg);

EXTRACT_FN (extract_reg);
EXTRACT_FN (extract_ld_offset);
EXTRACT_FN (extract_ld_syntax);
EXTRACT_FN (extract_st_offset);
EXTRACT_FN (extract_st_syntax);
EXTRACT_FN (extract_flag);
EXTRACT_FN (extract_cond);
EXTRACT_FN (extract_reladdr);
EXTRACT_FN (extract_jumpflags);
EXTRACT_FN (extract_unopmacro);

#ifdef ARC_NPS_CMDS
#define NPS_32_FIELD      0x20
#define NPS_SPECIAL_FIELD 0x40
#endif // #ifdef ARC_NPS_CMDS

static int ac_sdasym_limm_p (arc_insn);
/* -------------------------------------------------------------------------- */
/*                               local data                                   */
/* -------------------------------------------------------------------------- */

/* Nonzero if we've seen an 'f' suffix (in certain insns).  */

static int flag_p;

/* Nonzero if we've finished processing the 'f' suffix.  */
static int flagshimm_handled_p;

/* Nonzero if we've seen a 'a' suffix (address writeback).  */
static int addrwb_p;

/* Nonzero if we've inserted a nullify condition.  */
static int nullify_p;

/* The value of the a nullify condition we inserted.  */
static int nullify;

/* Nonzero if we've inserted jumpflags.  */
static int jumpflags_p;

/* Nonzero if we've inserted a shimm.  */
static int shimm_p;

/* The value of the shimm we inserted (each insn only gets one but it can
   appear multiple times).  */
static int shimm;

/* Nonzero if we've inserted a limm (during assembly) or seen a limm
   (during disassembly).  */
static int limm_p;

/* The value of the limm we inserted.  Each insn only gets one but it can
   appear multiple times.  */
static long limm;

/*Nonzero if we've seen an <.T> flag*/
static enum { NONE = 0, TAKEN = 1, NTAKEN =2} tflag_p = NONE;
/* Commented out, since unused. */
/* static unsigned char brpredict = 0; */

/* Configuration flags.  */

/* Various ARC_HAVE_XXX bits.  */
static int cpu_type;


/* Given a format letter, yields the index into `arc_operands'.
   eg: arc_operand_map['a'] = REGA, for ARCtangent-A4.  */
static unsigned short arc_operand_map_a4[512];
static unsigned short arc_operand_map_ac[512];


#define OPERANDS 3

static enum operand ls_operand[OPERANDS];


/* Various types of ARC operands, including insn suffixes.  */

/* Insn format values:

   'a'	REGA		register A field
   'b'	REGB		register B field
   'c'	REGC		register C field
   'S'	SHIMMFINISH	finish inserting a shimm value
   'L'	LIMMFINISH	finish inserting a limm value
   'o'	OFFSET		offset in st insns
   'O'	OFFSET		offset in ld insns
   '0'	SYNTAX_ST_NE	enforce store insn syntax, no errors
   '1'	SYNTAX_LD_NE	enforce load insn syntax, no errors
   '2'  SYNTAX_ST       enforce store insn syntax, errors, last pattern only
   '3'  SYNTAX_LD       enforce load insn syntax, errors, last pattern only
   's'  BASE            base in st insn
   'f'	FLAG		F flag
   'F'	FLAGFINISH	finish inserting the F flag
   'G'	FLAGINSN	insert F flag in "flag" insn
   'n'	DELAY		N field (nullify field)
   'q'	COND		condition code field
   'Q'	FORCELIMM	set `arc_cond_p' to 1 to ensure a constant is a limm
   'B'	BRANCH		branch address (22 bit pc relative)
   'J'	JUMP		jump address (26 bit absolute)
   'j'  JUMPFLAGS       optional high order bits of 'J'
   'z'	SIZE1		size field in ld a,[b,c]
   'Z'	SIZE10		size field in ld a,[b,shimm]
   'y'	SIZE22		size field in st c,[b,shimm]
   'x'	SIGN0		sign extend field ld a,[b,c]
   'X'	SIGN9		sign extend field ld a,[b,shimm]
   'w'	ADDRESS3	write-back field in ld a,[b,c]
   'W'	ADDRESS12	write-back field in ld a,[b,shimm]
   'v'	ADDRESS24	write-back field in st c,[b,shimm]
   'e'	CACHEBYPASS5	cache bypass in ld a,[b,c]
   'E'	CACHEBYPASS14	cache bypass in ld a,[b,shimm]
   'D'	CACHEBYPASS26	cache bypass in st c,[b,shimm]
   'U'	UNOPMACRO	fake operand to copy REGB to REGC for unop macros

   The following modifiers may appear between the % and char (eg: %.f):

   '.'	MODDOT		'.' prefix must be present
   'r'	REG		generic register value, for register table
   'A'	AUXREG		auxiliary register in lr a,[b], sr c,[b]

   Fields are:

   CHAR BITS SHIFT FLAGS INSERT_FN EXTRACT_FN  */

/* Operand table used for ARCtangent-A4 instructions */

static const struct arc_operand arc_operands_a4[] =
{
/* Place holder (??? not sure if needed).  */
#define UNUSED 0
  { 0, 0, 0, 0, 0, 0 },

/* Register A or shimm/limm indicator.  */
#define REGA (UNUSED + 1)
  { 'a', 6, ARC_SHIFT_REGA, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* Register B or shimm/limm indicator.  */
#define REGB (REGA + 1)
  { 'b', 6, ARC_SHIFT_REGB, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* Register C or shimm/limm indicator.  */
#define REGC (REGB + 1)
  { 'c', 6, ARC_SHIFT_REGC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* Fake operand used to insert shimm value into most instructions.  */
#define SHIMMFINISH (REGC + 1)
  { 'S', 9, 0, ARC_OPERAND_SIGNED + ARC_OPERAND_FAKE, insert_shimmfinish, 0 },

/* Fake operand used to insert limm value into most instructions.  */
#define LIMMFINISH (SHIMMFINISH + 1)
  { 'L', 32, 32, ARC_OPERAND_ADDRESS + ARC_OPERAND_LIMM + ARC_OPERAND_FAKE, insert_limmfinish, 0 },

/* Shimm operand when there is no reg indicator (st).  */
#define ST_OFFSET (LIMMFINISH + 1)
  { 'o', 9, 0, ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED | ARC_OPERAND_STORE, insert_offset, extract_st_offset },

/* Shimm operand when there is no reg indicator (ld).  */
#define LD_OFFSET (ST_OFFSET + 1)
  { 'O', 9, 0,ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED | ARC_OPERAND_LOAD, insert_offset, extract_ld_offset },

/* Operand for base.  */
#define BASE (LD_OFFSET + 1)
  { 's', 6, ARC_SHIFT_REGB, ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED, insert_base, extract_reg},

/* 0 enforce syntax for st insns.  */
#define SYNTAX_ST_NE (BASE + 1)
  { '0', 9, 0, ARC_OPERAND_FAKE, insert_st_syntax, extract_st_syntax },

/* 1 enforce syntax for ld insns.  */
#define SYNTAX_LD_NE (SYNTAX_ST_NE + 1)
  { '1', 9, 0, ARC_OPERAND_FAKE, insert_ld_syntax, extract_ld_syntax },

/* 0 enforce syntax for st insns.  */
#define SYNTAX_ST (SYNTAX_LD_NE + 1)
  { '2', 9, 0, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR, insert_st_syntax, extract_st_syntax },

/* 0 enforce syntax for ld insns.  */
#define SYNTAX_LD (SYNTAX_ST + 1)
  { '3', 9, 0, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR, insert_ld_syntax, extract_ld_syntax },

/* Flag update bit (insertion is defered until we know how).  */
#define FLAG (SYNTAX_LD + 1)
  { 'f', 1, 8, ARC_OPERAND_SUFFIX, insert_flag, extract_flag },

/* Fake utility operand to finish 'f' suffix handling.  */
#define FLAGFINISH (FLAG + 1)
  { 'F', 1, 8, ARC_OPERAND_FAKE, insert_flagfinish, 0 },

/* Fake utility operand to set the 'f' flag for the "flag" insn.  */
#define FLAGINSN (FLAGFINISH + 1)
  { 'G', 1, 8, ARC_OPERAND_FAKE, insert_flag, 0 },

/* Branch delay types.  */
#define DELAY (FLAGINSN + 1)
  { 'n', 2, 5, ARC_OPERAND_SUFFIX , insert_nullify, 0 },

/* Conditions.  */
#define COND (DELAY + 1)
  { 'q', 5, 0, ARC_OPERAND_SUFFIX, insert_cond, extract_cond },

/* Set `arc_cond_p' to 1 to ensure a constant is treated as a limm.  */
#define FORCELIMM (COND + 1)
  { 'Q', 0, 0, ARC_OPERAND_FAKE, insert_forcelimm, 0 },

/* Branch address; b, bl, and lp insns.  */
#define BRANCH (FORCELIMM + 1)
  { 'B', 20, 7, ARC_OPERAND_RELATIVE_BRANCH + (ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR), insert_reladdr, extract_reladdr },

/* Jump address; j insn (this is basically the same as 'L' except that the
   value is right shifted by 2).  */
#define JUMP (BRANCH + 1)
  { 'J', 24, 32, (ARC_OPERAND_ERROR | ARC_OPERAND_ABSOLUTE_BRANCH) + ARC_OPERAND_LIMM + ARC_OPERAND_FAKE, insert_absaddr, 0 },

/* Jump flags; j{,l} insn value or'ed into 'J' addr for flag values.  */
#define JUMPFLAGS (JUMP + 1)
  { 'j', 6, 26, ARC_OPERAND_JUMPFLAGS | ARC_OPERAND_ERROR, insert_jumpflags, extract_jumpflags },

/* Size field, stored in bit 1,2.  */
#define SIZE1 (JUMPFLAGS + 1)
  { 'z', 2, 1, ARC_OPERAND_SUFFIX, 0, 0 },

/* Size field, stored in bit 10,11.  */
#define SIZE10 (SIZE1 + 1)
  { 'Z', 2, 10, ARC_OPERAND_SUFFIX, 0, 0 },

/* Size field, stored in bit 22,23.  */
#define SIZE22 (SIZE10 + 1)
  { 'y', 2, 22, ARC_OPERAND_SUFFIX, 0, 0 },

/* Sign extend field, stored in bit 0.  */
#define SIGN0 (SIZE22 + 1)
  { 'x', 1, 0, ARC_OPERAND_SUFFIX, 0, 0 },

/* Sign extend field, stored in bit 9.  */
#define SIGN9 (SIGN0 + 1)
  { 'X', 1, 9, ARC_OPERAND_SUFFIX, 0, 0 },

/* Address write back, stored in bit 3.  */
#define ADDRESS3 (SIGN9 + 1)
  { 'w', 1, 3, ARC_OPERAND_SUFFIX, insert_addr_wb, 0},

/* Address write back, stored in bit 12.  */
#define ADDRESS12 (ADDRESS3 + 1)
  { 'W', 1, 12, ARC_OPERAND_SUFFIX, insert_addr_wb, 0},

/* Address write back, stored in bit 24.  */
#define ADDRESS24 (ADDRESS12 + 1)
  { 'v', 1, 24, ARC_OPERAND_SUFFIX, insert_addr_wb, 0},

/* Cache bypass, stored in bit 5.  */
#define CACHEBYPASS5 (ADDRESS24 + 1)
  { 'e', 1, 5, ARC_OPERAND_SUFFIX, 0, 0 },

/* Cache bypass, stored in bit 14.  */
#define CACHEBYPASS14 (CACHEBYPASS5 + 1)
  { 'E', 1, 14, ARC_OPERAND_SUFFIX, 0, 0 },

/* Cache bypass, stored in bit 26.  */
#define CACHEBYPASS26 (CACHEBYPASS14 + 1)
  { 'D', 1, 26, ARC_OPERAND_SUFFIX, 0, 0 },

/* Unop macro, used to copy REGB to REGC.  */
#define UNOPMACRO (CACHEBYPASS26 + 1)
  { 'U', 6, ARC_SHIFT_REGC, ARC_OPERAND_FAKE, insert_unopmacro, extract_unopmacro },

/* '.' modifier ('.' required).  */
#define MODDOT (UNOPMACRO + 1)
  { '.', 1, 0, ARC_MOD_DOT, 0, 0 },

/* Dummy 'r' modifier for the register table.
   It's called a "dummy" because there's no point in inserting an 'r' into all
   the %a/%b/%c occurrences in the insn table.  */
#define REG (MODDOT + 1)
  { 'r', 6, 0, ARC_MOD_REG, 0, 0 },

/* Known auxiliary register modifier (stored in shimm field).  */
#define AUXREG (REG + 1)
  { 'A', 9, 0, ARC_MOD_AUXREG, 0, 0 },

/* End of list place holder.  */
  { 0, 0, 0, 0, 0, 0 }
};


/* Various types of ARCompact operands, including insn suffixes */

/* Operand format values:

   'A'	REGA_AC            register A field for ARCompact 32-bit insns
   'B'	REGB_SOURCE_AC     register B (as a source) field for ARCompact 32-bit insns
   '#'	REGB_DEST_AC       register B (as a destination) field for ARCompact 32-bit insns
   'C'	REGC_AC            register C field for ARCompact 32-bit insns
   'u'	UIMM6_AC           6-bit unsigned immediate
   'K'	SIMM12_AC          12-bit signed immediate
   'L'	LIMM_AC            32-bit long immediate
   'F'	FLAGFINISH_AC      finish inserting the F flag for ARCompact insns
   'n'	DELAY_AC           N field (nullify field)
   'N'	JUMP_DELAY_AC      nullify field for "j" and "jl" insns
   'o'	OFFSET_AC          9-bit Offset in ARCompact 32-bit 'ld' insns
   'd'	SIMM9_AC           9-bit signed immediate value for 'bbit' insns
   'z'	SIZE1_AC           size field in ARCompact "st" insns
   't'	SIZE7_AC           size field in ARCompact "ld" insns
   'T'	SIZE17_AC          size field in ARCompact "ld" insns
   'x'	SIGN6_AC           sign extend field in ARCompact "ld" insns
   'X'	SIGN16_AC          sign extend field in ARCompact "ld" insns
   'w'	ADDRESS3_AC        write-back field in ld a,[b,c]
   'p'	ADDRESS9_AC        write-back field in ARCompact "ld a,[b,s9]" insns
   'P'	ADDRESS22_AC       write-back field in ARCompact "ld a,[b,c]" insns

   '&'	ADDRESS22S_AC      scaling field in ARCompact "ld a,[limm,c]" insns
   'D'	CACHEBYPASS5_AC    cache bypass in ARCompact "st" insns
   'v'	CACHEBYPASS11_AC   cache bypass in ARCompact "ld a,[b,s9]" insns
   'V'	CACHEBYPASS15_AC   cache bypass in ARCompact "ld a,[b,c]" insns and
                           A700 Atomic Exchange (ex.<di> b,[c] and ex.<di> b,[limm]
   'g'	BASE_AC            base in ARCompact "st" insns
   'h'	BLINK_AC           branch address (21-bit pc-relative) in
                           conditional 'bl' (BLcc) insns
   'H'	UNCOND_BLINK_AC    branch address (25-bit pc-relative) in
                           unconditional 'bl' (BL) insns
   'i'	BRANCH_AC          branch address (21-bit pc-relative) in
                           conditional 'b' (Bcc) insns
   'I'	UNCOND_BRANCH_AC   branch address (25-bit pc-relative) in
                           unconditional 'b' (B) insns
   'y'	UIMM7BY2_AC        7-bit unsigned immediate operand used in ARCompact
                           'lp' insns
   'Y'	SIMM13BY2_AC       13-bit signed immediate operand used in ARCompact
                           'lp' insns
   'q'	COND_AC            condition code field
   'f'	FLAG_AC            F flag in ARCompact insns
   'Q'	FORCELIMM_AC       set `arc_cond_p' to 1 to ensure a constant is a limm
   '0'	SYNTAX_ST_NE_AC    enforce store insn syntax, no errors
   '1'	SYNTAX_LD_NE_AC    enforce load insn syntax, no errors
   '2'  SYNTAX_ST_AC       enforce store insn syntax, errors, last pattern only
   '3'  SYNTAX_LD_AC       enforce load insn syntax, errors, last pattern only
   '7'	ILINK1             'ilink1' register indicator
   '8'	ILINK2             'ilink2' register indicator

   The following modifiers may appear between the % and char (eg: %.f):

   '.'	MODDOT_AC          '.' prefix must be present
   'r'	REG_AC             generic register value, for register table
   'G'	AUXREG_AC          auxiliary register in "lr" and "sr" insns

   The following operands are used specific to 16-bit insns

   'a'	REGA_AC16          register A field for ARCompact 16-bit insns
   'b'	REGB_AC16          register B field for ARCompact 16-bit insns
   'c'	REGC_AC16          register C field for ARCompact 16-bit insns
   'U'	REGH_AC16          high register H field for ARCompact 16-bit insns


   'e'	UIMM3_AC16         3-bit unsigned immediate
   'E'	UIMM5_AC16         5-bit unsigned immediate
   'j'	UIMM7_AC16         7-bit unsigned immediate
   'J'	UIMM8_AC16         8-bit unsigned immediate
   'k'	UIMM6BY2_AC16      6-bit unsigned immediate, stored in bits 0-4
   'l'	UIMM7BY4_AC16      7-bit unsigned immediate, stored in bits 0-4
   'm'	UIMM10BY4_AC16     10-bit unsigned immediate, stored in bits 0-7
   's'	COND_BRANCH_AC16   branch address (7-bit pc-relative) for 16-bit
                           conditional branch insns (ex: bgt_s)
   'S'	CMP_BRANCH_AC16    branch address (8-bit pc-relative) for 16-bit
                           compare and branch insns (ex: breq_s, brne_s)
   'Z'	UNCOND_BRANCH_AC16 branch address (10-bit pc-relative) for 16-bit
                           branch insns (b_s, beq_s, bne_s)
   'W'	BLINK_AC16         branch address (11-bit pc-relative) for 16-bit
                           branch and link insns (bl_s)
   'M'	SIMM9_AC16         9-bit offset, used in "ldb_s" insn
   'O'	SIMM10BY2_AC16     10-bit offset(2-byte aligned), used in "ldw_s" insn
   'R'	SIMM11BY4_AC16     11-bit offset(4-byte aligned), used in "ld_s" insn
   '4'	REG_R0             'r0' register indicator
   '5'	REG_GP             'gp' register indicator
   '6'	REG_SP             'sp' register indicator
   '9'	REG_BLINK          'blink' register indicator
   '!'	REG_PCL            'pcl' register indicator
   '@'  UIMM6_A700_16         6-bit unsigned immediate in A700

   The following operands are used specific to the Aurora SIMD insns

   '*' SIMD_VR_DEST        'vr' registers as the destination in the A field
   '(' SIMD_VR_REGB        'vr' registers in the field B
   ')' SIMD_VR_REGC        'vr' registers in the field C

   '{' SIMD_I_REGB         'I'  registers in the field B
   '}' SIMD_I_REGC         'I'  registers in the field C

   '<' SIMD_DR_REGB        'DR' registers in the field B
   '>' SIMD_DR_REGC        'DR' registers in the field C
   '?' SIMD_U8_CONSTANT     A unsigned 8 bit constant
 '\13' SIMD_I_REGA         'I'  registers in the field A
 '\14' SIMD_I_S12          signed 12 bit in simd instruction
 '\15' SIMD_I_K_REGA       'K'  registers in the field A
 '\16' SIMD_I_K_REGB       'K'  registers in the field B
 '\17' SIMD_I_K_REGC       'K'  registers in the field C
 '\20' SIMD_I_U16          unsigned 16 bit in simd
 '\21' SIMD_I_UU16         high order 8 of 16 bit unsigned
 '\22' SIMD_I_UL16         low order 8 of 16 bit unsigned
 '\23' SIMD_DISCARDED      value not used
 '\24' SIMD_I_S15          simd 15 bit signed field 
 '\25' SIMD_I_ZR           zero constant value field
   
 The following operands are specific to the ARCv2 architecture

 '\128' ARCV2_REGH         5-bit h-register base address
 '\129' ARCV2_REG_R1       'r1' register indicator
 '\130' ARCV2_REG_R2       'r2' register indicator
 '\131' ARCV2_REG_R3       'r3' register indicator
 '\132' ARCV2_REGW         6-bit w-register base address

 ArcV2 constants:
 '\133' ARCV2_SIGNS3       3-bit signed constant [26:24]

   Fields are:

   CHAR BITS SHIFT FLAGS INSERT_FN EXTRACT_FN
*/

/* Operand table used for ARCompact instructions */

static const struct arc_operand arc_operands_ac[] =
{
/* place holder (??? not sure if needed) */
#define UNUSED_AC 0
  { 0, 0, 0, 0, 0, 0 },

/* register A used for ARCompact 32-bit insns */
#define REGA_AC (UNUSED_AC + 1)
  { 'A', 6, ARC_SHIFT_REGA_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* register B used for ARCompact 32-bit insns as a source */
#define REGB_SOURCE_AC (REGA_AC + 1)
  { 'B', 6, ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* register B used for ARCompact 32-bit insns as a destination */
#define REGB_DEST_AC (REGB_SOURCE_AC + 1)
  { '#', 6, ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* register C used for ARCompact 32-bit insns */
#define REGC_AC (REGB_DEST_AC + 1)
  { 'C', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* 6-bit unsigned immediate value, used in ARCompact 32-bit insns */
#define UIMM6_AC (REGC_AC + 1)
  { 'u', 6, 6, ARC_OPERAND_UNSIGNED, 0, 0 },

/* 12-bit signed immediate value, used in ARCompact 32-bit insns */
#define SIMM12_AC (UIMM6_AC + 1)
  { 'K', 12, 6, ARC_OPERAND_SIGNED, 0, 0 },

/* 32-bit long immediate value, used in ARCompact insns */
#define LIMM_AC (SIMM12_AC + 1)
  { 'L', 32, 32, ARC_OPERAND_ADDRESS | ARC_OPERAND_LIMM, insert_reg, 0 },

/* set `arc_cond_p' to 1 to ensure a constant is treated as a limm */
#define FORCELIMM_AC (LIMM_AC + 1)
  { 'Q', 0, 0, ARC_OPERAND_FAKE, insert_forcelimm, 0 },

/* conditional code indicator, used in ARCompact insns */
#define COND_AC (FORCELIMM_AC + 1)
  { 'q', 5, 0, ARC_OPERAND_SUFFIX, insert_cond, extract_cond },

/* flag update bit (insertion is defered until we know how) */
#define FLAG_AC (COND_AC + 1)
  { 'f', 1, 15, ARC_OPERAND_SUFFIX, insert_flag, extract_flag },

/* fake utility operand to finish 'f' suffix handling for ARCompact inst */
#define FLAGFINISH_AC (FLAG_AC + 1)
  { 'F', 1, 15, ARC_OPERAND_FAKE, insert_flagfinish, 0 },

/* branch delay types for ARCompact 32-bit insns */
#define DELAY_AC (FLAGFINISH_AC + 1)
  { 'n', 1, 5, ARC_OPERAND_SUFFIX, insert_nullify, 0 },

/* delay types for ARCompact 32-bit "j"/"jl" insns */
#define JUMP_DELAY_AC (DELAY_AC + 1)
  { 'N', 1, 16, ARC_OPERAND_SUFFIX, insert_nullify, 0 },

/* size field, stored in bit 1,2 */
#define SIZE1_AC (JUMP_DELAY_AC + 1)
  { 'z', 2, 1, ARC_OPERAND_SUFFIX, 0, 0 },

/* size field, stored in bit 7,8 */
#define SIZE7_AC (SIZE1_AC + 1)
  { 't', 2, 7, ARC_OPERAND_SUFFIX, 0, 0 },

/* size field, stored in bit 17,18 */
#define SIZE17_AC (SIZE7_AC + 1)
  { 'T', 2, 17, ARC_OPERAND_SUFFIX, 0, 0 },

/* sign extend field, stored in bit 6 */
#define SIGN6_AC (SIZE17_AC + 1)
  { 'x', 1, 6, ARC_OPERAND_SUFFIX, 0, 0 },

/* sign extend field, stored in bit 16 */
#define SIGN16_AC (SIGN6_AC + 1)
  { 'X', 1, 16, ARC_OPERAND_SUFFIX, 0, 0 },

/* address write back field, stored in bit 3,4 */
#define ADDRESS3_AC (SIGN16_AC + 1)
  { 'w', 2, 3, ARC_OPERAND_SUFFIX, insert_addr_wb, 0 },

/* address write back field, stored in bit 9, 10 */
#define ADDRESS9_AC (ADDRESS3_AC + 1)
  { 'p', 2, 9, ARC_OPERAND_SUFFIX, insert_addr_wb, 0 },

/* address write back field, stored in bit 22 */
#define ADDRESS22_AC (ADDRESS9_AC + 1)
  { 'P', 2, 22, ARC_OPERAND_SUFFIX, insert_addr_wb, 0 },

/* address scaling field, stored in bit 22 */
#define ADDRESS22S_AC (ADDRESS22_AC + 1)
  { '&', 2, 22, ARC_OPERAND_SUFFIX, insert_addr_wb, 0 },

/* cache bypass field, stored in bit 5 */
#define CACHEBYPASS5_AC (ADDRESS22S_AC + 1)
  { 'D', 1, 5, ARC_OPERAND_SUFFIX, 0, 0 },

/* cache bypass field, stored in bit 11 */
#define CACHEBYPASS11_AC (CACHEBYPASS5_AC + 1)
  { 'v', 1, 11, ARC_OPERAND_SUFFIX, 0, 0 },

/* cache bypass field, stored in bit 15 */
#define CACHEBYPASS15_AC (CACHEBYPASS11_AC + 1)
  { 'V', 1, 15, ARC_OPERAND_SUFFIX, 0, 0 },

/* base register for ARCompact 32-bit "ld"/"st" insns */
#define BASE_AC (CACHEBYPASS15_AC + 1)
  { 'g', 6, ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_LIMM |ARC_OPERAND_SIGNED, insert_base, extract_reg },

/* 9-bit signed immediate offset, used in ARCompact 32-bit "ld" insn */
#define OFFSET_AC (BASE_AC + 1)
  { 'o', 9, 16, ARC_OPERAND_SIGNED | ARC_OPERAND_LOAD, insert_offset, extract_ld_offset },

/* branch address(9-bit, pc-relative, 2-byte aligned), used for
  "bbit0"/"bbit1" insns */
#define SIMM9_AC (OFFSET_AC + 1)
  { 'd', 8, 17, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr  },

/* branch address(21-bit, pc-relative, 4-byte aligned), used for
   ARCompact 32-bit conditional 'bl' insns */
#define BLINK_AC (SIMM9_AC + 1)
  { 'h', 19, 18, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_4BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(25-bit, pc-relative, 4-byte aligned), used for
   ARCompact 32-bit unconditional 'bl' insns */
#define UNCOND_BLINK_AC (BLINK_AC + 1)
  { 'H', 23, 18, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_4BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(21-bit, pc-relative, 2-byte aligned), used for
   ARCompact 32-bit conditional 'b' insns */
#define BRANCH_AC (UNCOND_BLINK_AC + 1)
  { 'i', 20, 17, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(25-bit, pc-relative, 2-byte aligned), used for
   ARCompact 32-bit unconditional 'b' insns */
#define UNCOND_BRANCH_AC (BRANCH_AC + 1)
  { 'I', 24, 17, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address (7-bit, unsigned pc-relative, 2-byte aligned), used for
   ARCompact 32-bit conditional 'lp' insns */
#define UIMM7BY2_AC (UNCOND_BRANCH_AC + 1)
  { 'y', 6, 6, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr  },

/* branch address (13-bit, pc-relative, 2-byte aligned), used for
   ARCompact 32-bit uncoditional 'lp' insns */
#define SIMM13BY2_AC (UIMM7BY2_AC + 1)
  { 'Y', 12, 6, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* enforce syntax for st insns */
#define SYNTAX_ST_NE_AC (SIMM13BY2_AC + 1)
  { '0', 9, 0, ARC_OPERAND_FAKE, insert_st_syntax, extract_st_syntax },

/* enforce syntax for ld insns */
#define SYNTAX_LD_NE_AC (SYNTAX_ST_NE_AC + 1)
  { '1', 9, 0, ARC_OPERAND_FAKE, insert_ld_syntax, extract_ld_syntax },

/* enforce syntax for st insns */
#define SYNTAX_ST_AC (SYNTAX_LD_NE_AC + 1)
  { '2', 9, 0, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR, insert_st_syntax, extract_st_syntax },

/* enforce syntax for ld insns */
#define SYNTAX_LD_AC (SYNTAX_ST_AC + 1)
  { '3', 9, 0, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR, insert_ld_syntax, extract_ld_syntax },

/* enforce syntax for ex insns */
#define SYNTAX_EX_AT (SYNTAX_LD_AC + 1)
  { '^', 9, 0, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR, insert_ex_syntax, 0 },

/* 'ilink1' register indicator, used for ARCompact 'j' insn */
#define ILINK1 (SYNTAX_EX_AT + 1)
  { '7', 0, 0, 0, 0, 0 },

/* 'ilink2' register indicator, used for ARCompact 'j' insn */
#define ILINK2 (ILINK1 + 1)
  { '8', 0, 0, 0, 0, 0 },

/* '.' modifier ('.' required).  */
#define MODDOT_AC (ILINK2 + 1)
  { '.', 1, 0, ARC_MOD_DOT, 0, 0 },

/* Dummy 'r' modifier for the register table. */
#define REG_AC (MODDOT_AC + 1)
  { 'r', 6, 0, ARC_MOD_REG, 0, 0 },

/* Known auxiliary register modifier */
#define AUXREG_AC (REG_AC + 1)
  { 'G', 9, 0, ARC_MOD_AUXREG, 0, 0 },

/* Operands used specific to ARCompact 16-bit insns */

/* register A indicator, for ARCompact 16-bit insns */
#define REGA_AC16 (AUXREG_AC + 1)
  { 'a', 3, 0, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* register B indicator, for ARCompact 16-bit insns */
#define REGB_AC16 (REGA_AC16 + 1)
  { 'b', 3, 8, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* register C indicator, for ARCompact 16-bit insns */
#define REGC_AC16 (REGB_AC16 + 1)
  { 'c', 3, 5, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* high register(r0-r63) indicator, for ARCompact 16-bit insns */
#define REGH_AC16 (REGC_AC16 + 1)
  { 'U', 6, 5, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

/* 3-bit unsigned immediate, stored in bits 0-2 */
#define UIMM3_AC16 (REGH_AC16 + 1)
  { 'e', 3, 0, ARC_OPERAND_UNSIGNED, 0, 0 },

/* 5-bit unsigned immediate, stored in bits 0-4 */
#define UIMM5_AC16 (UIMM3_AC16 + 1)
  { 'E', 5, 0, ARC_OPERAND_UNSIGNED, 0, 0 },

/* 7-bit unsigned immediate, stored in bits 0-6 */
#define UIMM7_AC16 (UIMM5_AC16 + 1)
  { 'j', 7, 0, ARC_OPERAND_UNSIGNED, 0, 0 },

/* 8-bit unsigned immediate, stored in bits 0-7 */
#define UIMM8_AC16 (UIMM7_AC16 + 1)
  { 'J', 8, 0, ARC_OPERAND_UNSIGNED, 0, 0 },

/* 6-bit unsigned immediate, stored in bits 0-4, used in 16-bit ld insns */
#define UIMM6BY2_AC16 (UIMM8_AC16 + 1)
  { 'k', 5, 0, ARC_OPERAND_UNSIGNED | ARC_OPERAND_LOAD | ARC_OPERAND_2BYTE_ALIGNED , insert_offset, extract_ld_offset },

/* 7-bit unsigned immediate, stored in bits 0-4, used in 16-bit
   add/sub/ld/st insns */
#define UIMM7BY4_AC16 (UIMM6BY2_AC16 + 1)
  { 'l', 5, 0, ARC_OPERAND_UNSIGNED | ARC_OPERAND_4BYTE_ALIGNED, 0, 0 },

/* 10-bit unsigned immediate, stored in bits 0-7, used in "ld_s" insn */
#define UIMM10BY4_AC16 (UIMM7BY4_AC16 + 1)
  { 'm', 8, 0, ARC_OPERAND_UNSIGNED | ARC_OPERAND_LOAD | ARC_OPERAND_4BYTE_ALIGNED , insert_offset, extract_ld_offset },

/* branch address(7-bit, pc-relative, 2-byte aligned), used for
   ARCompact 16-bit conditional branch insns */
#define COND_BRANCH_AC16 (UIMM10BY4_AC16 + 1)
  { 's', 6, 0, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(8-bit, pc-relative, 2-byte aligned), used for
   ARCompact 16-bit compare and branch insns */
#define CMP_BRANCH_AC16 (COND_BRANCH_AC16 + 1)
  { 'S', 7, 0, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(10-bit, pc-relative, 2-byte aligned), used for
   ARCompact 16-bit branch insns */
#define UNCOND_BRANCH_AC16 (CMP_BRANCH_AC16 + 1)
  { 'Z', 9, 0, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* branch address(13-bit, pc-relative), used for ARCompact 16-bit
   branch and link insns */
#define BLINK_AC16 (UNCOND_BRANCH_AC16 + 1)
  { 'W', 11, 0, ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_4BYTE_ALIGNED | ARC_OPERAND_ERROR, insert_reladdr, extract_reladdr },

/* 9-bit signed immediate offset, used in "ldb_s" insn */
#define SIMM9_AC16 (BLINK_AC16 + 1)
  { 'M', 9, 0, ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED | ARC_OPERAND_LOAD, insert_offset, extract_ld_offset },

/* 10-bit signed immediate offset(2-byte aligned), used in "ldw_s" insn */
#define SIMM10BY2_AC16 (SIMM9_AC16 + 1)
  { 'O', 9, 0, ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED | ARC_OPERAND_LOAD | ARC_OPERAND_2BYTE_ALIGNED , insert_offset, extract_ld_offset },

/* 11-bit signed immediate offset(4-byte aligned), used in "ld_s" insn */
#define SIMM11BY4_AC16 (SIMM10BY2_AC16 + 1)
  { 'R', 9, 0, ARC_OPERAND_LIMM | ARC_OPERAND_SIGNED | ARC_OPERAND_LOAD | ARC_OPERAND_4BYTE_ALIGNED , insert_offset, extract_ld_offset },

/* 'r0' register indicator */
#define REG_R0 (SIMM11BY4_AC16 + 1)
  { '4', 0, 0, 0, 0, 0 },

/* 'gp' register indicator */
#define REG_GP (REG_R0 + 1)
  { '5', 0, 0, 0, 0, 0 },

/* 'sp' register indicator */
#define REG_SP (REG_GP + 1)
  { '6', 0, 0, 0, 0, 0 },

/* 'blink' register indicator */
#define REG_BLINK (REG_SP + 1)
  { '9', 0, 0, 0, 0, 0 },

/* 'pcl' register indicator */
#define REG_PCL (REG_BLINK + 1)
  { '!', 0, 0, 0, 0, 0 },

  /* 'd'  UIMM6_A700_16         6-bit unsigned immediate in A700 */
#define UIMM6_A700_16 (REG_PCL + 1)
  { '@', 6 ,5, ARC_OPERAND_UNSIGNED, 0 , 0},
#ifndef ARC_NO_SIMD_CMDS

 /***** Here are the operands exclusively used in the Aurora SIMD instructions  *******/

  /* '*' For a 128 bit vr  register for the Aurora platform in field A*/
#define SIMD_VR_DEST (UIMM6_A700_16 + 1)
  { '*', 6, ARC_SHIFT_REGA_AC     , ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /* '(' For a 128 bit vr  register for the Aurora platform in field B*/
#define SIMD_VR_REGB   (SIMD_VR_DEST + 1)
  { '(', 6, ARC_SHIFT_REGB_LOW_AC , ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /*')' For a 128 bit vr register for the Aurora platform in field C*/
#define SIMD_VR_REGC (SIMD_VR_REGB + 1)
  { ')', 6, ARC_SHIFT_REGC_AC     , ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /*'?' For a 8 bit unsigned constant */
#define SIMD_U8_CONSTANT (SIMD_VR_REGC + 1)
  { '?', 8, 6 , ARC_OPERAND_UNSIGNED , insert_u8, 0},

  /* '{' For  the I registers inserted into field B*/
#define SIMD_I_REGB (SIMD_U8_CONSTANT + 1)
  { '{', 6 , ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /* '}' For the I  registers inserted into field C*/
#define SIMD_I_REGC (SIMD_I_REGB + 1)
  { '}', 6 , ARC_SHIFT_REGC_AC    , ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /* '<' For the DR registers inserted into field B */
#define SIMD_DR_REGB (SIMD_I_REGC + 1)
  { '<', 6 , ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /* '>' For the DR registers inserted into field C*/
#define SIMD_DR_REGC (SIMD_DR_REGB + 1)
  { '>', 6 , ARC_SHIFT_REGC_AC    , ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0},

  /* small data symbol */
#define SDASYM (SIMD_DR_REGC + 1)
  { '[', 0, 0, ARC_MOD_SDASYM, 0, 0 },

/* simd const lanemask */
#define SIMD_LANEMASK (SDASYM+1)
  { ']', 0, 15, ARC_OPERAND_SUFFIX,0,0},

#define THROW_AC (SIMD_LANEMASK + 1)
  { '\07', 6, 0, ARC_OPERAND_UNSIGNED, 0, 0 },

#define SIMD_I_REGA (THROW_AC + 1)
  { '\13', 6, ARC_SHIFT_REGA_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_reg, 0 },
#define SIMD_I_S12  (SIMD_I_REGA+1)
  { '\14', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_s12, 0 },
#define SIMD_K_A  (SIMD_I_S12+1)
  { '\15', 6, ARC_SHIFT_REGA_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_reg, 0 },
#define SIMD_K_B  (SIMD_K_A+1)
  { '\16', 6, ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_reg, 0 },
#define SIMD_K_C  (SIMD_K_B+1)
  { '\17', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_reg, 0 },
#define SIMD_I_U16  (SIMD_K_C+1)
  { '\20', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_u16, 0 },
#define SIMD_I_UU16  (SIMD_I_U16+1)
  { '\21', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_uu16, 0 },
#define SIMD_I_UL16  (SIMD_I_UU16+1)
  { '\22', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_ul16, 0 },
#define SIMD_DISCARDED  (SIMD_I_UL16+1)
  { '\23', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_null, 0 },
#define SIMD_I_S15   (SIMD_DISCARDED+1)
  { '\24', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, insert_s15, 0 },
#define SIMD_I_ZERO   (SIMD_I_S15+1)
  { '\25', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED|ARC_OPERAND_ERROR, 0, 0 },
#endif  // #ifndef ARC_NO_SIMD_CMDS

#ifdef NPS_ARCv2
  /* ARCv2 modchars*/
#define ARCV2_REGH ( SIMD_I_ZERO+1)
  { 128, 5, 5, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

  /*r1 register indicator*/
#define ARCV2_REG_R1 ( ARCV2_REGH+1)
  { 129, 0, 0, 0, 0, 0 },

  /*r2 register indicator*/
#define ARCV2_REG_R2 (ARCV2_REG_R1+1)
  { 130, 0, 0, 0, 0, 0 },

  /*r3 register indicator*/
#define ARCV2_REG_R3 (ARCV2_REG_R2+1)
  { 131, 0, 0, 0, 0, 0 },

  /*w6 6bit signed store immediate*/
#define ARCV2_SIGNW6 (ARCV2_REG_R3+1)
  { 132, 6, 6, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, 0, 0 },

  /*s3 3-bit signed immediate*/
#define ARCV2_SIGNS3 (ARCV2_SIGNW6+1)
  { 133, 3, 8, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, 0, 0 },

  /*Au6 6-bit unsigned immediate as used in ADD_S*/
#define ARCV2_UIMM6 (ARCV2_SIGNS3+1)
  { 134, 6, 0, ARC_OPERAND_UNSIGNED  | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /*Eu6 6-bit unsigned immediate as used in ENTER_S*/
#define ARCV2_ENTERU6 ( ARCV2_UIMM6+1)
  { 135, 6, 1, ARC_OPERAND_UNSIGNED  | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /*u10 10-bit unsigned immediate as used in EI_S*/
#define ARCV2_EIU10 ( ARCV2_ENTERU6+1)
  { 136, 10, 0, ARC_OPERAND_UNSIGNED  | ARC_OPERAND_ERROR, 0, 0 },

  /*Lu7 7-bit unsigned immediate as used in LDI_S*/
#define ARCV2_LDIU7 ( ARCV2_EIU10+1)
  { 137, 7, 0, ARC_OPERAND_UNSIGNED  | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /*u7 7-bit unsigned immediate as used in LEAVE_S*/
#define ARCV2_LVSU7 ( ARCV2_LDIU7+1)
  { 138, 7, 1, ARC_OPERAND_UNSIGNED  | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /*g5 register indicator*/
#define ARCV2_REGG (ARCV2_LVSU7+1)
  { 140, 5, 8, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },

  /*s11 9-bit signed immediate as used in ST_S*/
#define ARCV2_STS11 (ARCV2_REGG+1)
  { 141, 11, 0, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /*u5 3-bit unsigned immediate as used in LD_S*/
#define ARCV2_LDU5 (ARCV2_STS11+1)
  { 142, 5, 3, ARC_OPERAND_UNSIGNED | ARC_OPERAND_ERROR, insert_v2_16, 0 },

  /**/
#define ARCV2_TFLAG (ARCV2_LDU5+1)
  { 143, 1, 3, ARC_OPERAND_SUFFIX, insert_v2_Tflag, 0 },

  /*overloads the 'd' flag*/
#define ARCV2_TFLAGFINBBIT (ARCV2_TFLAG+1)
  { 144, 8, 17, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR | ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED,
    insert_Ybit, 0 },

  /*overloads the 'd' flag*/
#define ARCV2_TFLAGFINBR (ARCV2_TFLAGFINBBIT+1)
  { 145, 8, 17, ARC_OPERAND_FAKE | ARC_OPERAND_ERROR | ARC_OPERAND_RELATIVE_BRANCH | ARC_OPERAND_SIGNED | ARC_OPERAND_2BYTE_ALIGNED,
    insert_Ybit_neg, 0 },
#endif /* #ifdef NPS_ARCv2 */

#ifdef ARC_NPS_CMDS
/* 16-bit immediate active  */
#define SET_AC16 (UIMM6_A700_16 + 1)
  { '>', 0, 0, ARC_OPERAND_FAKE, insert_force16, 0 },
/* 16-bit signed immediate, stored in bits 0-15,  */
#define SIMM15_AC16 (SET_AC16 + 1)
  { 0302, 16, 0, ARC_OPERAND_SIGNED | ARC_OPERAND_4BYTE_ALIGNED, insert_su16, 0 },
/* 16-bit unsigned immediate, stored in bits 0-15,  */
#define UIMM15_AC16 (SIMM15_AC16 + 1)
  { ']', 16, 0, ARC_OPERAND_UNSIGNED | ARC_OPERAND_4BYTE_ALIGNED, insert_su16, 0 },
/* register * used for arc 16 bit single register */
#define REG64_AC16 (UIMM15_AC16 + 1)
  { '*', 6, 5, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, extract_reg },
  /* fake utility operand to finish 'f' suffix handling for ARCompact inst */
#define FLAGFINISH16_AC16 (REG64_AC16 + 1)
  { '(', 1, 4, ARC_OPERAND_FAKE, insert_flagfinish, 0 },
  /* 5-bit unsigned immediate, stored in bits 0-4,  */
#define BITS_0_4_AC16 (FLAGFINISH16_AC16 + 1)
  { 0220, 5, 0, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 5-9,  */
#define BITS_5_9_AC16 (BITS_0_4_AC16 + 1)
  { 0221, 5, 5, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 10-14, values 1-32 */
#define BITS_10_14D_AC16 (BITS_5_9_AC16 + 1)
  { 0222, 5, 10, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_nTo48, 0 },
/* 3-bit unsigned immediate, stored in bits 3-5,  values 0-7*/
#define BITS_3_5_AC16 (BITS_10_14D_AC16 + 1)
  { 0247, 3, 3, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
/* 3-bit unsigned immediate, stored in bits 6-8, values 1-8 */
#define BITS_6_8_AC16 (BITS_3_5_AC16 + 1)
  { 0250, 3, 6, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
/* 3-bit unsigned immediate, stored in bits 9-11,  values 1-8*/
#define BITS_9_11_AC16 (BITS_6_8_AC16 + 1)
  { 0251, 3, 9, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
/* 3-bit unsigned immediate, stored in bits 12-14,  values 1-8*/
#define BITS_12_14_AC16 (BITS_9_11_AC16 + 1)
  { 0252, 3, 12, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
  /* clear bit store in bit 15 */
#define CLEAR_B15_AC16 (BITS_12_14_AC16 + 1)
  { '\15', 0, 15, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* s bit store in bit 13 */
  { 0350, 0, 13, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
#define S_B13_AC16 (CLEAR_B15_AC16 + 1)
  /* m bit store in bit 07 */
#define M_B07_AC16 (S_B13_AC16 + 1)
  { 0216, 0,  7, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* di bit store in bit 3 */
#define DI_B03_AC32 (M_B07_AC16 + 1)
  { 0351, 1, 5,ARC_OPERAND_SUFFIX, insert_cmd_operand, 0 },
  /* merge bit store limm bit 28 */
#define MERGE_BDCP_AC32 (DI_B03_AC32 + 1)
  { 0307, 0, 28, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
/* no allocate bit store limm bit 27 */
#define NO_ALLOCATE_BIT_27_AC32 (MERGE_BDCP_AC32 + 1)
  { 0321, 0, 27, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
/* no allocate bit store limm bit 24 */
#define NO_ALLOCATE_BIT_24_AC32 (NO_ALLOCATE_BIT_27_AC32 + 1)
  { 0322, 0, 24, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
/* exp bit store limm bit 23 */
#define EXP_BIT_23_AC32 (NO_ALLOCATE_BIT_24_AC32 + 1)
  { 0323, 0, 23, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* equal bit store limm bit 26 */
#define EQUAL_BD1_AC32 (EXP_BIT_23_AC32 + 1)
  { 0317, 0, 26, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* equal bit store limm bits 24-25 */
#define EQUAL_BD3_AC32 (EQUAL_BD1_AC32 + 1)
  { 0316, 3, 24, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* valid movb_i command */
#define VALID_MOVB_AC16 (EQUAL_BD3_AC32 + 1)
  { '\14', 0, 0, ARC_OPERAND_FAKE, insert_valid_movb, 0 },
  /* clear bit store in bit 31 */
#define CLEAR_B31_AC32 (VALID_MOVB_AC16 + 1)
  { ')', 0, 31, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* 5-bit unsigned immediate, stored in bits 0-4,  */
#define BITS_0_4_AC32 (CLEAR_B31_AC32 + 1)
  { 0200, 5, NPS_32_FIELD | 0, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 5-9,  */
#define BITS_5_9_AC32 (BITS_0_4_AC32 + 1)
  { 0201, 5, NPS_32_FIELD | 5, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 10-14,  */
#define BITS_10_14_AC32 (BITS_5_9_AC32 + 1)
  { 0202, 5, NPS_32_FIELD | 10, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 15-19,  */
#define BITS_15_19_AC32 (BITS_10_14_AC32 + 1)
  { 0203, 5, NPS_32_FIELD | 15, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 20-24, values 1-32 */
#define BITS_20_24D_AC32 (BITS_15_19_AC32 + 1)
  { 0204, 5, NPS_32_FIELD | 20, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 25-29, values 1-32 */
#define BITS_25_29D_AC32 (BITS_20_24D_AC32 + 1)
  { 0205, 5, NPS_32_FIELD | 25, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_nTo48, 0 },
  /* valid mrgb_i command */
#define VALID_MRGB_AC16 (BITS_25_29D_AC32 + 1)
  { '\26', 0, 0, ARC_OPERAND_FAKE, insert_valid_mrgb, 0 },
  /* 2-bit unsigned immediate, stored in bits 25-26,  */
#define BITS_25_26_AC32 (VALID_MRGB_AC16 + 1)
  { 0207, 2, NPS_32_FIELD | 25, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 24-25,  */
#define BITS_24_25_AC32 (BITS_25_26_AC32 + 1)
  { 0223, 2, NPS_32_FIELD | 24, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
/* 2-bit unsigned immediate, stored in bits 22-23,  */
#define BITS_22_23_AC32 (BITS_24_25_AC32 + 1)
  { 0243, 2, NPS_32_FIELD | 22, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 10-bit unsigned immediate, stored in bits 19-28,  */
#define BITS_19_28_AC32 (BITS_22_23_AC32 + 1)
  { 0224, 10, NPS_32_FIELD | 19, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 4-bit unsigned immediate, stored in bits 28-31,  */
#define BITS_28_31_AC32 (BITS_19_28_AC32 + 1)
  { 0253, 4, NPS_32_FIELD | 28, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 6-bit unsigned immediate, stored in bits 8-13, values 8,16,32,64,128,256 */
#define BITS_8_13_AC32 (BITS_28_31_AC32 + 1)
  { 0254, 10, NPS_SPECIAL_FIELD | 0x0F, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 10-bit unsigned immediate, stored in bits 16-25,  */
#define BITS_16_25_AC32 (BITS_8_13_AC32 + 1)
  { 0255, 10, NPS_32_FIELD | 16, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 4-bit unsigned immediate, stored in u6 bits 0-3,  */
#define BITS_0_3_AC32 (BITS_16_25_AC32 + 1)
  { 0225, 4, 6, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 1-bit unsigned immediate, stored in u6 bit 5,  */
#define BITS_5_5_AC32 (BITS_0_3_AC32 + 1)
  { 0246, 1, 11, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 4-bit unsigned immediate, stored in bits 18-21,  */
#define BITS_18_21_AC32 (BITS_5_5_AC32 + 1)
  { 0227, 4, NPS_32_FIELD | 18, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 27-28,  */
#define BITS_27_28_AC32 (BITS_18_21_AC32 + 1)
  { 0210, 2, NPS_32_FIELD | 27, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* valid mov2b_i command */
#define VALID_MOV2B_AC16 (BITS_27_28_AC32 + 1)
  { '\31', 0, 0, ARC_OPERAND_FAKE, insert_valid_mov2b, 0 },
  /* 5-bit unsigned immediate, stored in bits 20-24 */
#define BITS_20_24_AC32 (VALID_MOV2B_AC16 + 1)
  { 0212, 5, NPS_32_FIELD | 20, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 29-30,  */
#define BITS_29_30_AC32 (BITS_20_24_AC32 + 1)
  { 0213, 2, NPS_32_FIELD | 29, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in 31 (limm-MSB) & 15 (simm-LSB)  */
#define BITS_SPC1_AC32 (BITS_29_30_AC32 + 1)
  { 0214, 2, NPS_SPECIAL_FIELD | 0x01, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 10-14, */
#define BITS_10_14_AC16 (BITS_SPC1_AC32 + 1)
  { 0215, 5, 10, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* valid mov4b_i command */
#define VALID_MOV4B_AC48 (BITS_10_14_AC16 + 1)
  { '\36', 0, 0, ARC_OPERAND_FAKE, insert_valid_mov4b, 0 },
  /* clear bit store for mov4b_i */
#define CLEAR_MOV4B_AC48 (VALID_MOV4B_AC48 + 1)
  { '\37', 0, 0, ARC_OPERAND_SUFFIX, insert_clear_mov4b, 0 },
  /* valid ext4b_i command */
#define VALID_EXT4B_AC16 (CLEAR_MOV4B_AC48 + 1)
  { '\32', 0, 0, ARC_OPERAND_FAKE, insert_valid_ext4b, 0 },
  /* valid ins4b_i command */
#define VALID_INS4B_AC16 (VALID_EXT4B_AC16 + 1)
  { '\33', 0, 0, ARC_OPERAND_FAKE, insert_valid_ins4b, 0 },
  /* valid mxb command */
#define VALID_MXB_AC32 (VALID_INS4B_AC16 + 1)
  { '\34', 0, 0, ARC_OPERAND_FAKE, insert_valid_mxb, 0 },

  /* 5-bit unsigned immediate, stored in bits 5-9, values 1-32 */
#define BITS_5_9D_AC16 (VALID_MXB_AC32 + 1)
  { 0230, 5, 5, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_nTo48, 0 },

  /* 2-bit unsigned immediate, stored in bits 10-11, values 0-3 */
#define BITS_10_11_AC16 (BITS_5_9D_AC16 + 1)
  { 0231, 5, NPS_SPECIAL_FIELD | 0x06, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 12-13, values 0-3 */
#define BITS_12_13_AC16 (BITS_10_11_AC16 + 1)
  { 0232, 5, NPS_SPECIAL_FIELD | 0x05, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 14-15, values 0-3 */
#define BITS_14_15_AC16 (BITS_12_13_AC16 + 1)
  { 0233, 5, NPS_SPECIAL_FIELD | 0x04, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 4-bit unsigned immediate, stored in bits 5_8, values 0-f */
#define BITS_5_8_AC16 (BITS_14_15_AC16 + 1)
  { 0234, 4, 5, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 16-bit unsigned immediate, stored in bits 0_15, values 0000-ffff */
#define BITS_0_15_AC32 (BITS_5_8_AC16 + 1)
  { 0236, 16, NPS_32_FIELD | 0, ARC_OPERAND_ADDRESS | ARC_OPERAND_LIMM , insert_nTo48, 0 },
  /* 16-bit unsigned immediate, stored in bits 16_31, values 0000-ffff */
#define BITS_16_31_AC32 (BITS_0_15_AC32 + 1)
  { 0237, 16, NPS_32_FIELD | 16, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* valid arithmetic command */
#define VALID_ARITH_AC16 (BITS_16_31_AC32 + 1)
  { 0301, 0, 0, ARC_OPERAND_FAKE, insert_valid_arith, 0 },
  /* sign ext. store in bit 14 */
#define SIGN_EXT_B14_AC16 (VALID_ARITH_AC16 + 1)
  { '}', 0, 14, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* small data symbol */
#define SDASYM (SIGN_EXT_B14_AC16 + 1)
  { '[', 0, 0, ARC_MOD_SDASYM, 0, 0 },
  /* register 5 bits from bit 11 */
#define REG_5_F11 (SDASYM + 1)
  { 0270, 5, 11, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },
  /* register 3 bits from bit 21 */
#define REG_3_F21 (REG_5_F11 + 1)
  { 0271, 3, 21, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },
  /* register 3 bits from bit 24 */
#define REG_3_F24 (REG_3_F21 + 1)
  { 0272, 3, 24, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },
  /* 2-bit unsigned immediate, stored in bits 0-1, values 0-3 */
#define BITS_0_1_ACMD (REG_3_F24 + 1)
  { 0273, 2, 0, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 3-bit unsigned immediate, stored in bits 2-4, values 0-7 */
#define BITS_2_4_ACMD (BITS_0_1_ACMD + 1)
  { 0274, 3, 2, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 3-bit unsigned immediate, stored in bits 2-4, values 1-8 */
#define BITS_2_4_D_ACMD (BITS_2_4_ACMD + 1)
  { 0257, 3, 2, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_cmd_operand, 0 },
  /* 1-bit unsigned immediate, stored in bits 5-5, values 0-1 */
#define BITS_5_5_ACMD (BITS_2_4_D_ACMD + 1)
  { 0275, 1, 5, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 5-bit unsigned immediate, stored in bits 6-10, values 1-32 */
#define BITS_6_10_ACMD (BITS_5_5_ACMD + 1)
  { 0276, 5, 6, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_cmd_operand, 0 },
  /* 3-bit unsigned immediate, stored in bits 5-7, values 0-7 */
#define BITS_5_7_ACMD (BITS_6_10_ACMD + 1)
  { 0277, 3, 5, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 3-bit unsigned immediate, stored in bits 8-10, values 0-7 */
#define BITS_8_10_ACMD (BITS_5_7_ACMD + 1)
  { 0300, 3, 8, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 8-bit unsigned immediate, stored in simm12-14 (MSB) & simm0-4 (LSB)  */
#define BITS_SPC2_AC32 (BITS_8_10_ACMD + 1)
  { 0303, 8, NPS_SPECIAL_FIELD | 0x02, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 2-bit unsigned immediate, translate 1,2,4,8 -> 0,1,2,3  */
#define SIZE_1248_AC32 (BITS_SPC2_AC32 + 1)
  { 0304, 2, 10, ARC_OPERAND_UNSIGNED, insert_size_1248, 0 },
  /* 1-bit unsigned immediate, stored in bit 10  */
#define BITS_10_10_ACMD (SIZE_1248_AC32 + 1)
  { 0305, 1, 10, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 3-bit unsigned immediate, stored in bits 6-8, values 1-8 */
#define BITS_6_8_ACMD (BITS_10_10_ACMD + 1)
  { 0306, 3, 6, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_cmd_operand, 0  },
  /* 2-bit unsigned immediate, stored in bits 6-7, values 1-4 */
#define BITS_6_7_ACMD (BITS_6_8_ACMD + 1)
  { 0226, 2, 6, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_cmd_operand, 0  },
  /* 6-bit unsigned immediate, stored in bits 6-11, values 1-64 */
#define BITS_6_11_ACMD (BITS_6_7_ACMD + 1)
  { 0342, 6, 6, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_cmd_operand, 0  },

  /* register A used for ARCompact 32-bit insns only registers 0-31 valid */
#define REGA5_AC (BITS_6_11_ACMD + 1)
  { 0310, 6, 21, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },
  /* register B used for ARCompact 32-bit insns as a source only registers 0-31 valid */
#define REGB5_AC (REGA5_AC + 1)
  { 0311, 5, 16, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },
  /* register C used for ARCompact 32-bit insns only registers 0-31 valid*/
#define REGC5_AC (REGB5_AC + 1)
  { 0312, 5, 11, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },

  /* cpb2b sub command, */
#define CPB2B_29_31_AC32 (REGC5_AC + 1)
  { 0320, 0, 0, ARC_OPERAND_FAKE, set_limm_p, 0 },
  /* 8-bit unsigned immediate, stored in bits 16_23, values 01-100 */
#define BITS_16_23D_AC32 (CPB2B_29_31_AC32 + 1)
  { 0332, 8, NPS_32_FIELD | 16, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
  /* 10-bit unsigned immediate, stored in bits 00_09, values 000-3ff */
#define BITS_00_09_AC32 (BITS_16_23D_AC32 + 1)
  { 0335, 10, NPS_32_FIELD | 0, ARC_OPERAND_UNSIGNED , insert_nTo48, 0 },
  /* 10-bit unsigned immediate, stored in bits 12_21, values 001-400 */
#define BITS_12_21_AC32 (BITS_00_09_AC32 + 1)
  { 0336, 10, NPS_32_FIELD | 12, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK , insert_nTo48, 0 },
  /* 8-bit unsigned immediate, stored in bits 16_23, values 00-255 */
#define BITS_16_23_AC32 (BITS_12_21_AC32 + 1)
  { 0341, 8, NPS_32_FIELD | 16, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 6-bit unsigned immediate, stored in 16-21 values 1-63 for 64 save 0  */
#define BITS_16_21_AC32 (BITS_16_23_AC32 + 1)
  { 0262, 6, 16, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK , insert_nTo48, 0 },
  /* 2-bit unsigned immediate, stored in bits 13-14, values 0,16,32 */
#define SKIP_ACMD (BITS_16_21_AC32 + 1)
  { 0343, 2, 13, ARC_OPERAND_UNSIGNED, insert_skipRes, 0  },
  /* 7-bit unsigned immediate, stored in bits 0-6, values 1-128 */
#define BITS_0_6D_AC16 (SKIP_ACMD + 1)
  { 0344, 7, 0, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, stored in bits 8-12, values 0-31 */
#define BITS_8_12_AC16 (BITS_0_6D_AC16 + 1)
  { 0345, 5, 8, ARC_OPERAND_UNSIGNED , insert_nTo48, 0 },
/* 6-bit unsigned immediate value, stored in bits 0-5 values 0-63*/
#define UIMM6_0_5_AC (BITS_8_12_AC16 + 1)
  { 0347, 6, 0, ARC_OPERAND_UNSIGNED, insert_cmd_operand, 0 },
  /* 2-bit unsigned immediate, translate 1,2,4,8 -> 0,1,2,3  */
#define SIZE_1248_CMD (UIMM6_0_5_AC + 1)
  { 0352, 2, 3, ARC_OPERAND_UNSIGNED, insert_size_1248, 0 },
  /* 4-bit unsigned immediate, stored in bits 6-9, values 0-15 */
#define BITS_6_9_ACMD0 (SIZE_1248_CMD + 1)
  { 0353, 4, 6, ARC_OPERAND_UNSIGNED , insert_cmd_operand, 0  },
  /* duplicate 5-bit src1 => src2 major 0xA */
#define DUP_5_11_BITS (BITS_6_9_ACMD0 + 1)
  { 0354, 5, 11, ARC_OPERAND_FAKE , dup_bits, 0  },
  /* 3-bit unsigned immediate, stored in bits 9-11, values 1-8 */
#define BITS_9_11_D_ACMD (DUP_5_11_BITS + 1)
  { 0355, 3, 9, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_1, insert_nTo48, 0 },
  /* 1-bit unsigned immediate, stored in bit 14, values 0-1 */
#define BIT_14_14_ACMD (BITS_9_11_D_ACMD + 1)
  { 0356, 1, 14, ARC_OPERAND_UNSIGNED , insert_nTo48, 0 },
  /* 1-bit unsigned immediate, stored in bit 15, values 0-1 */
#define BIT_15_15_ACMD (BIT_14_14_ACMD + 1)
  { 0357, 1, 15, ARC_OPERAND_UNSIGNED , insert_nTo48, 0 },
  /* 4-bit unsigned immediate, log value store in Short Imm 8-11  */
#define BITS_SPC7_AC16 (BIT_15_15_ACMD + 1)
  { 0363, 16, NPS_SPECIAL_FIELD | 0x07, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* type store in bit 14 */
#define TYPE_B14_AC16 (BITS_SPC7_AC16 + 1)
  { 0364, 0,  14, ARC_OPERAND_SUFFIX, insert_cmd16_32, 0 },
  /* 1-bit unsigned immediate, store in bit 4  */
#define BITS_SHASH_PAD_AC16 (TYPE_B14_AC16 + 1)
  { 0371, 1, NPS_SPECIAL_FIELD | 0x0C, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 4-bit unsigned immediate, 2**N (N=4,5,6,7,8) store in Short Imm 12-15  */
#define BITS_PWR2_AC16 (BITS_SHASH_PAD_AC16 + 1)
  { 0372, 12, NPS_SPECIAL_FIELD | 0x09, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 4-bit unsigned immediate, N/16 store in Short Imm 11-14  */
#define BITS_OFF4_AC16 (BITS_PWR2_AC16 + 1)
  { 0373, 11, NPS_SPECIAL_FIELD | 0x08, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 8-bit unsigned immediate, N/16 store in Short Imm 5-12  */
#define BITS_OFF3_AC16 (BITS_OFF4_AC16 + 1)
  { 0374, 5, NPS_SPECIAL_FIELD | 0x0A, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 8-bit unsigned immediate, store in SHIMM 5-12*/
#define BIT_6_6_AC16 (BITS_OFF3_AC16 + 1)
  { 0375, 8, 5, ARC_OPERAND_UNSIGNED | ARC_NPS_DECR_MASK, insert_nTo48, 0 },
  /* 5-bit unsigned immediate, N/4 store in Short Imm 8-12  */
#define BITS_OFF5_AC16 (BIT_6_6_AC16 + 1)
  { 0376, 8, NPS_SPECIAL_FIELD | 0x0B, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 1-bit unsigned immediate, store in bit 13  */
#define BITS_SHASH_INIT_AC16 (BITS_OFF5_AC16 + 1)
  { 0377, 1, NPS_SPECIAL_FIELD | 0x0D, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 3-bit unsigned immediate, stored in bits 5-7,  */
#define BITS_5_7_AC32 (BITS_SHASH_INIT_AC16 + 1)
  { 0235, 3, NPS_32_FIELD | 5, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
/* 3-bit unsigned immediate, hash to limm bits 20-22, bits==9 to avoid check error */
#define BITS_20_22_AC32 (BITS_5_7_AC32 + 1)
  { 0242, 9, NPS_SPECIAL_FIELD | 0x0E, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
/* 10-bit unsigned immediate, stored in bits 10-19,  */
#define BITS_10_19_AC32 (BITS_20_22_AC32 + 1)
  { 0244, 10, NPS_32_FIELD | 10, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
/* 10-bit unsigned immediate, stored in bits 0-9,  */
#define BITS_0_9_AC32 (BITS_10_19_AC32 + 1)
  { 0245, 10, NPS_32_FIELD, ARC_OPERAND_UNSIGNED | 0, insert_nTo48, 0 },
  /* 8-bit unsigned immediate, stored in bits 0-7, values 00-255 */
#define BITS_0_7_AC32 (BITS_0_9_AC32 + 1)
  { 0206, 8, NPS_32_FIELD | 0, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 8-bit unsigned immediate, stored in bits 8-15, values 00-255 */
#define BITS_8_15_AC32 (BITS_0_7_AC32 + 1)
  { 0211, 8, NPS_32_FIELD | 8, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 7-bit unsigned immediate, stored in bits 8-14, values 00-127 */
#define BITS_8_14_AC32 (BITS_8_15_AC32 + 1)
  { 0240, 7, NPS_32_FIELD | 8, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* 8-bit unsigned immediate, stored in bits 24-31, values 00-255 */
#define BITS_24_31_AC32 (BITS_8_14_AC32 + 1)
  { 0217, 8, NPS_32_FIELD | 24, ARC_OPERAND_UNSIGNED, insert_nTo48, 0 },
  /* parity bit 9 cp16/32 */
#define NO_ALLOC_B9 (BITS_24_31_AC32 + 1)
  { 0346, 0, 9, ARC_OPERAND_SUFFIX , insert_cmd16_32, 0 },
  /* parity bit 24 cp16/32 */
#define PARITY_B24 (NO_ALLOC_B9 + 1)
  { 0347, 0, 24, ARC_OPERAND_SUFFIX , insert_cmd16_32, 0 },
  /* 6-bit unsigned immediate value, used in ARCompact 32-bit insns 1,2,4 are valid */
#define UIMM6_124_AC (PARITY_B24 + 1)
  { 0241, 6, 6, ARC_OPERAND_ERROR | ARC_OPERAND_FAKE, validate_u6_124, 0 },
#endif // #ifdef ARC_NPS_CMDS

  /* set bit 0 in shimm/limm */
#define BIT_0_0_SHIMM (UIMM6_124_AC + 1)
  { 0400, 0, 0, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\000 */
  /* set bit 1 in shimm/limm */
#define BIT_1_1_SHIMM (BIT_0_0_SHIMM + 1)
  { 0401, 0, 1, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\001 */
  /* set bit 2 in shimm/limm */
#define BIT_2_2_SHIMM (BIT_1_1_SHIMM + 1)
  { 0402, 0, 2, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\002 */
  /* set bit 3 in shimm/limm */
#define BIT_3_3_SHIMM (BIT_2_2_SHIMM + 1)
  { 0403, 0, 3, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\003 */
  /* set bit 4 in shimm/limm */
#define BIT_4_4_SHIMM (BIT_3_3_SHIMM + 1)
  { 0404, 0, 4, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\004 */
  /* set bit 5 in shimm/limm */
#define BIT_5_5_SHIMM (BIT_4_4_SHIMM + 1)
  { 0405, 0, 5, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\005 */
  /* set bit 6 in shimm/limm */
#define BIT_6_6_SHIMM (BIT_5_5_SHIMM + 1)
  { 0406, 0, 6, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\006 */
  /* set bit 7 in shimm/limm */
#define BIT_7_7_SHIMM (BIT_6_6_SHIMM + 1)
  { 0407, 0, 7, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\007 */
  /* set bit 8 in shimm/limm */
#define BIT_8_8_SHIMM (BIT_7_7_SHIMM + 1)
  { 0410, 0, 8, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\010 */
  /* set bit 9 in shimm/limm */
#define BIT_9_9_SHIMM (BIT_8_8_SHIMM + 1)
  { 0411, 0, 9, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\011 */
  /* set bit 10 in shimm/limm */
#define BIT_10_10_SHIMM (BIT_9_9_SHIMM + 1)
  { 0412, 0, 10, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\012 */
  /* set bit 11 in shimm/limm */
#define BIT_11_11_SHIMM (BIT_10_10_SHIMM + 1)
  { 0413, 0, 11, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\013 */
  /* set bit 12 in shimm/limm */
#define BIT_12_12_SHIMM (BIT_11_11_SHIMM + 1)
  { 0414, 0, 12, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\014 */
  /* set bit 13 in shimm/limm */
#define BIT_13_13_SHIMM (BIT_12_12_SHIMM + 1)
  { 0415, 0, 13, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\015 */
  /* set bit 14 in shimm/limm */
#define BIT_14_14_SHIMM (BIT_13_13_SHIMM + 1)
  { 0416, 0, 14, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\016 */
  /* set bit 15 in shimm/limm */
#define BIT_15_15_SHIMM (BIT_14_14_SHIMM + 1)
  { 0417, 0, 15, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\017 */

  /* set bit 16 in limm */
#define BIT_16_16_LIMM (BIT_15_15_SHIMM + 1)
  { 0420, 0, 16, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\020 */
  /* set bit 17 in limm */
#define BIT_17_17_LIMM (BIT_16_16_LIMM + 1)
  { 0421, 0, 17, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\021 */
  /* set bit 18 in limm */
#define BIT_18_18_LIMM (BIT_17_17_LIMM + 1)
  { 0422, 0, 18, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\022 */
  /* set bit 19 in limm */
#define BIT_19_19_LIMM (BIT_18_18_LIMM + 1)
  { 0423, 0, 19, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\023 */
  /* set bit 20 in limm */
#define BIT_20_20_LIMM (BIT_19_19_LIMM + 1)
  { 0424, 0, 20, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\024 */
  /* set bit 21 in limm */
#define BIT_21_21_LIMM (BIT_20_20_LIMM + 1)
  { 0425, 0, 21, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\025 */
  /* set bit 22 in limm */
#define BIT_22_22_LIMM (BIT_21_21_LIMM + 1)
  { 0426, 0, 22, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\026 */
  /* set bit 23 in limm */
#define BIT_23_23_LIMM (BIT_22_22_LIMM + 1)
  { 0427, 0, 23, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\027 */
  /* set bit 24 in liimm */
#define BIT_24_24_LIMM (BIT_23_23_LIMM + 1)
  { 0430, 0, 24, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\030 */
  /* set bit 25 in limm */
#define BIT_25_25_LIMM (BIT_24_24_LIMM + 1)
  { 0431, 0, 25, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\031 */
  /* set bit 26 in limm */
#define BIT_26_26_LIMM (BIT_25_25_LIMM + 1)
  { 0432, 0, 26, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\032 */
    /* set bit 27 in limm */
#define BIT_27_27_LIMM (BIT_26_26_LIMM + 1)
  { 0433, 0, 27, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\033 */
  /* set bit 28 in limm */
#define BIT_28_28_LIMM (BIT_27_27_LIMM + 1)
  { 0434, 0, 28, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\034 */
  /* set bit 29 in limm */
#define BIT_29_29_LIMM (BIT_28_28_LIMM + 1)
  { 0435, 0, 29, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\035 */
  /* set bit 30 in limm */
#define BIT_30_30_LIMM (BIT_29_29_LIMM + 1)
  { 0436, 0, 30, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\036 */
  /* set bit 31 in limm */
#define BIT_31_31_LIMM (BIT_30_30_LIMM + 1)
  { 0437, 0, 31, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\037 */
  /* clear all 32 bits in limm */
#define BIT_32_32_LIMM (BIT_31_31_LIMM + 1)
  { 0440, 0, 32, ARC_OPERAND_FAKE, insert_cmd16_32, 0 },  /* use +\040 */
  /* reflect store in bit 15 */
#define REFLECT_B15_AC32 (BIT_32_32_LIMM + 1)
  { 0337, 1,  15, ARC_OPERAND_SUFFIX, insert_cond, 0 },

  /* register A for 64 bit ops. */
#define ARCV2_REGA_64 (ARCV2_TFLAGFINBR+1)
  { '=', 6, ARC_SHIFT_REGA_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },

  /* register B used for 64-bit ops */
#define ARCV2_REGB_64 (ARCV2_REGA_64 + 1)
  { ';', 6, ARC_SHIFT_REGB_LOW_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },

  /* register C used for 64-bit ops */
#define ARCV2_REGC_64 (ARCV2_REGB_64 + 1)
  { '_', 6, ARC_SHIFT_REGC_AC, ARC_OPERAND_SIGNED | ARC_OPERAND_ERROR, insert_reg, 0 },

  /* immediate 3-bits used by DMB instruction */
#define ARCV2_UIMM3_AC32 (ARCV2_REGC_64 + 1)
  { '~', 3, 6, ARC_OPERAND_UNSIGNED, 0, 0 },

/* end of list place holder */
  { 0, 0, 0, 0, 0, 0 }
};


/* -------------------------------------------------------------------------- */
/*                            externally visible data                         */
/* -------------------------------------------------------------------------- */

/* Nonzero if we've seen a 'q' suffix (condition code).  */
int arc_cond_p;

/* For ARC700, no extension registers nor LP_COUNT may be the target of
   LD or EX instructions, the only allowed encoding above 32 is 62,
   which is used for prefetch.  The initial setting of arc_ld_ext_mask
   reflects these constraints.

   For ARC500 / ARC600, LP_COUNT is also forbidden for loads, but extension
   registers might allow loads.  */
unsigned long arc_ld_ext_mask = 1 << (62 - 32);

int arc_user_mode_only = 0;

struct arc_ext_operand_value *arc_ext_operands;

#define LS_VALUE  0
#define LS_DEST   0
#define LS_BASE   1
#define LS_OFFSET 2

/* By default, the pointer 'arc_operand_map' points to the operand map table
   used for ARCtangent-A4 (i.e arc_operand_map_a4[]) .  */
unsigned short *arc_operand_map = arc_operand_map_a4;

/* By default, the pointer 'arc_operands' points to the operand table
   used for 32-bit instructions (i.e arc_operands_a4[]) */
const struct arc_operand *arc_operands = arc_operands_a4;


/* -------------------------------------------------------------------------- */
/*                               local functions                              */
/* -------------------------------------------------------------------------- */

/* Insertion functions.  */

/**** ARC V2 specific insert functions *****/

/* Insert a number into a 16 bit instruction.
 *
 * insn    Top half of instruction.
 * ex      Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_v2_16  (arc_insn insn,  long *ex ATTRIBUTE_UNUSED,
	      const struct arc_operand *operand,
	      int mods ATTRIBUTE_UNUSED,
	      const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
	      long value,
	      const char **errmsg
	      )
{
  arc_insn msb = 0;
  arc_insn lsb = 0;

  switch (operand->fmt)
    {
    case 134: /* ADD_S u6 */
      msb = (value & 0x38) << 1;
      lsb = (value & 0x07);
      break;
    case 135: /* enter_s u6 */
      msb = (value & 0x30) << 4;
      lsb = (value & 0x0F) << 1;
      break;
    case 137: /* ldi_s u7 */
      msb = (value & 0x78) << 1;
      lsb = (value & 0x07);
      break;
    case 138: /* leave_s u7 */
      msb = (value & 0x70) << 4;
      lsb = (value & 0x0F) << 1;
      break;
    case 141: /* st_s s11 */
      value = value >> 2; /* truncate last 2 bits*/
      msb = (value & 0x1F8) << 2;
      lsb = (value & 0x07);
      break;
    case 142: /* ld_s u5 */
      value = value >> 2; /* truncate last 2 bits*/
      msb = (value & 0x04) << 8;
      lsb = (value & 0x03) << 3;
      break;
    default:
      *errmsg = _("unknown type of 6-bit unsigned constant");
    }

  insn |= msb;
  insn |= lsb;

  return insn;
}

/* Called when we see an <.T> flag.  */

static arc_insn
insert_v2_Tflag (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
	     const struct arc_operand *operand ATTRIBUTE_UNUSED,
	     int mods ATTRIBUTE_UNUSED,
	     const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
	     long value ATTRIBUTE_UNUSED,
	     const char **errmsg ATTRIBUTE_UNUSED)
{
  /* We can't store anything in the insn until we've parsed the shimm field.
     Just record the fact that we've got this flag.  */

  tflag_p = NTAKEN;
  if (value)
    {
      tflag_p = TAKEN;
    }

  return insn;
}

unsigned char arc_get_branch_prediction(void)
{
  return tflag_p;
}

void arc_reset_branch_prediction(void)
{
  tflag_p = NONE;
}

static arc_insn
insert_Ybit (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
	     const struct arc_operand *operand,
	     int mods,
	     const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
	     long value ,
	     const char **errmsg ATTRIBUTE_UNUSED)
{
  arc_insn bitY = 0;

  /*mods == -1 only in fixup*/
  if (!value && mods != -1)
    {
      if (tflag_p == NONE)
	{
	  /* I need to add the default behaviour: BBITx: Y=1 */
	  insn |= 8;
	}
      return insn;
    }

  if (value < 0)
    {
      bitY = 1;
    }

  /* Insert least significant 7-bits.  */
  insn |= ((value >> 1) & 0x7f) << operand->shift;
  /* Insert most significant bit.  */
  insn |= (((value >> 1) & 0x80) >> 7) << 15;

  insn |= (bitY) << 3;

  return insn;
}

static arc_insn
insert_Ybit_neg (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
		 const struct arc_operand *operand,
		 int mods ATTRIBUTE_UNUSED,
		 const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		 long value ,
		 const char **errmsg ATTRIBUTE_UNUSED)
{
  arc_insn bitY = 1;

  if (!value && mods != -1)
    return insn;

  if (value < 0)
    {
      bitY = 0;
    }

  /* Insert least significant 7-bits.  */
  insn |= ((value >> 1) & 0x7f) << operand->shift;
  /* Insert most significant bit.  */
  insn |= (((value >> 1) & 0x80) >> 7) << 15;

  insn |= (bitY) << 3;

  return insn;
}


#ifndef ARC_NO_SIMD_CMDS
/********Insertion function for some SIMD operands***************/
static arc_insn
insert_u8  (arc_insn insn, long * insn2 ATTRIBUTE_UNUSED,
            const struct arc_operand *operand,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  long msb2;
  long lsb6;

  msb2 = value >> 6;
  msb2 = msb2  << 15;

  lsb6 = value & 0x3f ;

  insn |= msb2;
  insn |= (lsb6 << operand->shift);
  return insn;
}
/* Insert a signed twelve bit number into a 64 bit instruction.
 * insn is top 32 bits of instruction and gets the least significant six
 * bits in the C operand position.  The most significant six bits go to the
 * bottom of ex.  
 * insn    Top half of instruction.
 * ex      Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_s12  (arc_insn insn,  long *ex,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  long msb6;
  long lsb6;

  msb6 = (value >> 6) & 0x3ff;
  lsb6 = (value & 0x3f) << 6 ;

  insn |= lsb6;
  if(ex)
      *ex |= msb6;
  return insn;
}
/* Insert an unsigned sixteen bit number into a 64 bit instruction.
 * insn is top 32 bits of instruction and gets the least significant six
 * bits in the C operand position.  The most significant six bits go to the
 * bottom of ex.  
 * insn    Top half of instruction.
 * ex      Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_u16  (arc_insn insn, long *ex,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  long msb6;
  long lsb6;

  msb6 = (value >> 6) & 0x3ff;
  lsb6 = (value & 0x3f) << 6 ;

  insn |= lsb6;
  if(ex)
      *ex |= msb6;
  return insn;
}
/* Insert upper half of unsigned sixteen bit number into a 64 bit instruction.
 * insn is top 32 bits of instruction and gets the least significant six
 * bits in the C operand position.  The most significant six bits go to the
 * bottom of ex.  
 * insn    Top half of instruction.
 * ex      Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_uu16  (arc_insn insn, long *ex,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  long msb8;

  msb8 = (value & 0xff) << 2;
  if(ex)
      *ex |= msb8;
  return insn;
}
/* Insert lower eight bits of unsigned sixteen bit number into a 64 bit 
 * instruction.
 * insn is top 32 bits of instruction and gets the least significant six
 * bits in the C operand position.  The most significant six bits go to the
 * bottom of ex.  
 * insn    Top half of instruction.
 * ex      Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_ul16  (arc_insn insn, long *ex,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  long msb2;
  long lsb6;

  msb2 = (value >> 6) & 0x3;
  lsb6 = (value & 0x3f) << 6 ;

  insn |= lsb6;
  if(ex)
      *ex |= msb2;
  return insn;
}
/* Insert 15 bits of signed number into a 64 bit instruction.
 * insn is top 32 bits of instruction and is unchanged.
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_s15  (arc_insn insn, long *ex,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{

  if(ex)
      *ex |= (value & 0x7fff);
  return insn;
}
/* Discarded field.
 * insn is top 32 bits of instruction and gets the least significant six
 * bits in the C operand position.  The most significant six bits go to the
 * bottom of ex.  
 * insn    Top half of instruction.
 * insn2   Bottom half of instruction.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_null  (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{
  return insn;
}
#endif  // #ifndef ARC_NO_SIMD_CMDS

/* Insert a value into a register field.
   If REG is NULL, then this is actually a constant.

   We must also handle auxiliary registers for lr/sr insns.  */

static arc_insn
insert_reg (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
	    const struct arc_operand *operand,
	    int mods,
	    const struct arc_operand_value *reg,
	    long value,
	    const char **errmsg)
{
  static char buf[100];
  enum operand op_type = OP_NONE;
  if (reg == NULL)
    {
      /* We have a constant that also requires a value stored in a register
	 field.  Handle these by updating the register field and saving the
	 value for later handling by either %S (shimm) or %L (limm).  */

      if ((mods & ARC_MOD_SDASYM) && !ac_sdasym_limm_p (insn))
	{
	  /* Check if this insn is a prefetch that needs a limm */
	  if ((insn & 0xFFFFF87F) == 0x1600703E)
	    {
	      limm_p = 1;
	    }
	  /* If it is an ld/ldw/st/stw insn without any .aa suffixes, then
	     make it a scaled instruction, i.e. set .aa field to 3 */
	  else if (addrwb_p == 0)
	    {
	      /* Check for ld with .aa=0 */
	      if ((insn & 0xf8000000) == 0x10000000)
		{
		  /* if an ld/ldw insn */
		  if ((((insn >> 7) & 3) == 0) ||
		      (((insn >> 7) & 3) == 2))
		    /* Set .aa to 3 */
		    addrwb_p =  0x600;
		}
	      /* Check for st with .aa=0 */
	      else if ((insn & 0xf8000001) == 0x18000000)
		{
		  /* if an st/stw insn */
		  if ((((insn >> 1) & 3) == 0) ||
		  (((insn >> 1) & 3) == 2))
		    /* Set .aa to 3 */
		    addrwb_p = 0x18;
		}
	    } /* addrwb_p == 0 */
	}
      /* We have to use a limm.  If we've already seen one they must match.  */
      else if (!limm_p || limm == value)
	{
	    if ('a' != operand->fmt)
	      {
		op_type = OP_LIMM;
		limm_p = 1;
		limm = value;
		/* The constant is stored later.  */
	      }
	}
      else
	{
	  *errmsg = _("unable to fit different valued constants into instruction");
	}
    }
  else
    {
      /* We have to handle both normal and auxiliary registers.  */

      if ((reg->type == AUXREG) || (reg->type == AUXREG_AC))
	{
	  if (!(mods & ARC_MOD_AUXREG))
	    *errmsg = _("auxiliary register not allowed here");
	  else /* Insert auxiliary register value for ARCompact ISA.  */
	    {
	      /* TODO: Check for validity of using ARCompact auxiliary regs.  */

	      /* Replace this later with the corresponding function to
		 do the insertion of signed 12 bit immediates .  This
		 is because the auxillary registers used as a mnemonic
		 would be stored in this fashion.  */

	      /* Predicated AEX doesn't allow s12 immediate. Only u6. */
	      if ((insn & 0xF8FF8020) == 0x20E70020)
		{
		  if ((reg->value < 0) || (reg->value > 63))
		    *errmsg = _("unable to fit auxiliary register into instruction");
		  else
		    insn |= ((reg->value & 0x3f) << 6);
		}
	      else
		{
		  if ((reg->value < -2048) || (reg->value > 2047))
		    *errmsg = _("unable to fit auxiliary register into instruction");
		  else
		    insn |= (((reg->value & 0x3f) << 6) | ((reg->value & 0xfc0) >> 6));
		}
	    }
	}
      else
	{
          /* Check for use validity.  */
          if (('a' == operand->fmt)
              || ('A' == operand->fmt)
              || ('#' == operand->fmt))
            {
	      if (reg->flags & ARC_REGISTER_READONLY)
		*errmsg = _("attempt to set readonly register");
            }
          if ('a' != operand->fmt || (('A' != operand->fmt)))
            {
	      if (reg->flags & ARC_REGISTER_WRITEONLY)
		*errmsg = _("attempt to read writeonly register");
	    }
	  /* We should never get an invalid register number here.  */
	  if ((unsigned int) reg->value > 63)
	    {
	      sprintf (buf, _("invalid register number `%d'"), reg->value);
	      *errmsg = buf;
	    }
#ifndef ARC_NO_SIMD_CMDS
          if ((   ('B' == operand->fmt) || ('#' == operand->fmt)
			   || ('g' == operand->fmt) || ('(' == operand->fmt)
			   || ('{' == operand->fmt) || ('<' == operand->fmt)))
#else
          if ((   ('B' == operand->fmt) || ('#' == operand->fmt)
			   || ('g' == operand->fmt)))
#endif  // #ifndef ARC_NO_SIMD_CMDS
	    {
	      insn |= (reg->value & 0x7) << operand->shift;
	      insn |= (reg->value >> 3) << ARC_SHIFT_REGB_HIGH_AC;
	    }
          else if ('U' == operand->fmt)
            {
	      insn |= (reg->value & 0x7) << operand->shift;
	      insn |= reg->value >> 3;

	      /* Ravi: Quoting from the ARC Programmer reference:
		 The program counter (PCL) is not permitted to be the
		 destination of an instruction.  A value of in 0x03 in the
		 sub opcode field, i, and a value of 0x3F in destination
		 register field, H, will raise an Instruction Error
		 exception.
		 This should solve the mov_s pcl, whatever bug.  */
	      if ((insn & 0xFF) == 0xFF)
		*errmsg = _("attempt to set readonly register");
            }
          else if (operand->fmt == 128)
	    {
	      if (reg->value > 31
		  || reg->value == 30
		  || reg->value == 29)
		{
		  sprintf (buf, _("invalid register number `%d'"), reg->value);
		  *errmsg = buf;
		}
	      else
		{
		  /* H5 class*/
		  insn |= (reg->value & 0x7) << operand->shift;
		  insn |= reg->value >> 3;
		}
	    }
	  else if (operand->fmt == 140)
	    {
	      if (reg->value > 31)
		{
		  sprintf (buf, _("invalid register number `%d'"), reg->value);
		  *errmsg = buf;
		} else
		{
		  /* G5 class*/
		  insn |= (reg->value & 0x07) << operand->shift;
		  insn |= (reg->value & 0x18);
		}
	    }
	  else if (operand->fmt == '=' || operand->fmt == '_')
	    {
	      if ((reg->value % 2) == 1 )
		{
		  sprintf (buf, _("invalid register number `%d'"), reg->value);
		  *errmsg = buf;
		}
	      else
		{
		  /* A (64 bit) class*/
		  insn |= (reg->value & 0x3E) << operand->shift;
		}
	    }
	  else if ((operand->fmt == ';'))
	    {
	      if ((reg->value % 2) == 1 )
		{
		  sprintf (buf, _("invalid register number `%d'"), reg->value);
		  *errmsg = buf;
		}
	      else
		{
		  /* A (64 bit) class*/
		  insn |= (reg->value & 0x6) << operand->shift;
		  insn |= (reg->value >> 3) << ARC_SHIFT_REGB_HIGH_AC;
		}
	    }
	  else
#ifdef ARC_NPS_CMDS
           {
        	     if ( operand->fmt != '*' ) {
         	 	    insn |= reg->value << operand->shift;
        	     }
        	     else {
        	    	 int k = (insn & (0x3F << operand->shift)) >> operand->shift;
        	    	 if (k == 62) {
        	    		 insn &= ~(0x3F << operand->shift);
        	    		 insn |= reg->value << operand->shift;
        	    	 }
        	    	 else {
        	    		 if ( k != reg->value ) {
        	    			 *errmsg = _("attempt to set destination register equal source register");
        	    		 }
        	    	 }
        	     }
            }
#else
	    insn |= reg->value << operand->shift;
#endif
          op_type = OP_REG;
	}
    }

  switch (operand->fmt)
    {
    case 'a':
    case 'A':
    case '#':
#ifndef ARC_NO_SIMD_CMDS
    case '*':
#endif // #ifndef ARC_NO_SIMD_CMDS
      ls_operand[LS_DEST] = op_type;
      break;
    case 'C':
#ifndef ARC_NO_SIMD_CMDS
    case ')':
    case '}':
    case '>':
#endif // #ifndef ARC_NO_SIMD_CMDS
      if ((insn & I(-1)) == I(3))
        ls_operand[LS_VALUE] = op_type;
      else
        ls_operand[LS_OFFSET] = op_type;
      break;
    }

  return insn;
}

/* Called when we see an 'f' flag.  */

static arc_insn
insert_flag (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
	     const struct arc_operand *operand ATTRIBUTE_UNUSED,
	     int mods ATTRIBUTE_UNUSED,
	     const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
	     long value ATTRIBUTE_UNUSED,
	     const char **errmsg ATTRIBUTE_UNUSED)
{
  /* We can't store anything in the insn until we've parsed the registers.
     Just record the fact that we've got this flag.  `insert_reg' will use it
     to store the correct value (ARC_REG_SHIMM_UPDATE or bit 0x100).  */
  flag_p = 1;
  return insn;
}

/* Called when we see an nullify condition.  */

static arc_insn
insert_nullify (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		const struct arc_operand *operand,
		int mods ATTRIBUTE_UNUSED,
		const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		long value,
		const char **errmsg ATTRIBUTE_UNUSED)
{
  nullify_p = 1;
  insn |= (value & ((1 << operand->bits) - 1)) << operand->shift;
  nullify = value;
  return insn;
}

/* Called after completely building an insn to ensure the 'f' flag gets set
   properly.  This is needed because we don't know how to set this flag until
   we've parsed the registers.  */

static arc_insn
insert_flagfinish (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		   const struct arc_operand *operand,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		   long value ATTRIBUTE_UNUSED,
		   const char **errmsg ATTRIBUTE_UNUSED)
{
  if (flag_p && !flagshimm_handled_p)
    {
      if (shimm_p)
	abort ();
      flagshimm_handled_p = 1;
      insn |= (1 << operand->shift);
    }
  return insn;
}

/* Called when we see a conditional flag (eg: .eq).  */

static arc_insn
insert_cond (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
	     const struct arc_operand *operand,
	     int mods ATTRIBUTE_UNUSED,
	     const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
	     long value,
	     const char **errmsg ATTRIBUTE_UNUSED)
{
  arc_cond_p = 1;

  insn |= (value & ((1 << operand->bits) - 1)) << operand->shift;
  return insn;
}

/* Used in the "j" instruction to prevent constants from being interpreted as
   shimm values (which the jump insn doesn't accept).  This can also be used
   to force the use of limm values in other situations (eg: ld r0,[foo] uses
   this).
   ??? The mechanism is sound.  Access to it is a bit klunky right now.  */

static arc_insn
insert_forcelimm (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand ATTRIBUTE_UNUSED,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg ATTRIBUTE_UNUSED)
{
  arc_cond_p = 1;
#ifdef ARC_NPS_CMDS
  extraData += 32;
#endif // #ifdef ARC_NPS_CMDS
  return insn;
}

#ifdef ARC_NPS_CMDS
static arc_insn
insert_force16 (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand ATTRIBUTE_UNUSED,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg ATTRIBUTE_UNUSED)
{
  extraData += 16;
  return insn;
}
#endif // #ifdef ARC_NPS_CMDS

static arc_insn
insert_addr_wb (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		const struct arc_operand *operand,
		int mods ATTRIBUTE_UNUSED,
		const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		long value ATTRIBUTE_UNUSED,
		const char **errmsg ATTRIBUTE_UNUSED)
{
    /* Ravi: added the 'w' to handle the st.ab st.as instructions after
     * adding suport for it in the arc_suffixes_ac by defining aw, ab and as
     * to be ADDRESS3_AC also */

    if (('p' == operand->fmt)
        || ('P' == operand->fmt)
        || ('w' == operand->fmt)
        || ('&' == operand->fmt))
      addrwb_p = value << operand->shift;
    else
      addrwb_p = 1 << operand->shift;
    return insn;
}

static arc_insn
insert_base (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
	     const struct arc_operand *operand,
	     int mods,
	     const struct arc_operand_value *reg,
	     long value,
	     const char **errmsg)
{
  if (reg != NULL)
    {
      arc_insn myinsn;
      if (('g' == operand->fmt))
        insn |= insert_reg (0, ex, operand,mods, reg, value, errmsg);
      else
	{
	  myinsn = (insert_reg (0, ex, operand,mods, reg, value, errmsg)
		    >> operand->shift);
	  insn |= B (myinsn);
	}
      ls_operand[LS_BASE] = OP_REG;
    }

  return insn;
}

/* Used in ld/st insns to handle the offset field. We don't try to
   match operand syntax here.  We catch bad combinations later.  */

static arc_insn
insert_offset (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
	       const struct arc_operand *operand,
	       int mods,
	       const struct arc_operand_value *reg,
	       long value,
	       const char **errmsg)
{
  long minval, maxval;

  if (reg != NULL)
    {
      insn |= insert_reg (0, ex, operand, mods, reg, value, errmsg);
      ls_operand[LS_OFFSET] = OP_REG;
    }
  else
    {
      int bits;

      if (operand->flags & ARC_OPERAND_2BYTE_ALIGNED)
	bits = operand->bits + 1;
      else if (operand->flags & ARC_OPERAND_4BYTE_ALIGNED)
	bits = operand->bits + 2;
      else
	bits = operand->bits;

      /* This is *way* more general than necessary, but maybe some day it'll
	 be useful.  */
      if (operand->flags & ARC_OPERAND_SIGNED)
	{
	  minval = -(1 << (bits - 1));
	  maxval = (1 << (bits - 1)) - 1;
	}
      else
	{
	  minval = 0;
	  maxval = (1 << bits) - 1;
	}

      if ((value < minval || value > maxval))
        *errmsg = _("Immediate value out of bounds");

      switch (operand->fmt)
        {
        case 'o':
          insn |= ((value & 0xff) << operand->shift);
          insn |= (((value & 0x100) >> 8) << 15);
          break;
        case 'k':
          insn |= ((value >> 1) & 0x1f) << operand->shift;
          break;
        case 'm':
          insn |= ((value >> 2) & 0xff) << operand->shift;
          break;
        case 'M':
          insn |= (value & 0x1ff) << operand->shift;
          break;
        case 'O':
          insn |= ((value >> 1) & 0x1ff) << operand->shift;
          break;
        case 'R':
          insn |= ((value >> 2) & 0x1ff) << operand->shift;
          break;
        }
      shimm = value;
      shimm_p = 1;
      ls_operand[LS_OFFSET] = OP_SHIMM;
    }

  return insn;
}

#ifdef ARC_NPS_CMDS
void updateLastOpcodeSyntax(char *str)
{
    lastOpcodeSyntax = str;
    return;
}

static void procSpecialField(int mode, long value,const char **errmsg ATTRIBUTE_UNUSED)
{
	int tmp = 0;
	static char errStr[100];
	long orignValue = value;
	switch (mode) {
	    case 0x01:
	    	if ( ( value & 0x01 ) != 0 ) {
	    		extraData16Value |= 0x8000;
	    	}
	    	if ( ( value & 0x02 ) != 0 ) {
	    		limm |= 0x80000000;
	    	}
	    	break;
	    case 0x02:
	    	tmp = value & 0x01F;
	    	extraData16Value |= tmp;
	    	tmp = (value & 0x0E0) << (12-5);
	    	extraData16Value |= tmp;
	    	break;
	    case 0x03:
	    	if ( ( value <= 0 ) || ( value > 64 ) ) {
	    		*errmsg = _("Value invalid, only values 1 <= x <= 64 valid");
	    	}
	    	value += 7; // go to next n*8
	    	value &= ~7;
    		tmp = value  << (16-3);
    		limm |= tmp;
	    	break;
	    case 0x04:
	    case 0x05:
	    case 0x06:
            if ( ( value & 0xffffffe7 ) != 0 ) {
            	*errmsg = _("Value invalid, only values 0,8,16,24 are valid");
	    	}
            switch (mode) {
            case 0x04:
            	extraData16Value |= (value << (14-3));
            	break;
            case 0x05:
            	extraData16Value |= (value << (12-3));
            	break;
            case 0x06:
            	extraData16Value |= (value << (10-3));
            	break;
            }
            break;
        case 0x07:
            {
            	int k=0;
            	if ( value != 0 ) {
            		do {
            			if ( ( value & 1 ) != 0 ) break;
            			k++;
            			value >>= 1;
            		} while (value != 0);
            		if ( ( value == 1 ) && (k <= 8) ) {
                    	extraData16Value |= (k << 8);
                    	break;
            		}
            	}
#if 0
    		    *errmsg = _("Illegal Entry Size value");
#else
    		    sprintf(errStr,"Illegal Entry Size value %d",(int)orignValue);
    		    *errmsg = errStr;
#endif
    		    break;
           }
        case 0x08:
        	if ( (value & 0xFFFFFF0F) != 0 ) {
    		    sprintf(errStr,"Illegal Offset value %d",(int)value);
    		    *errmsg = errStr;
    		    break;
        	}
        	extraData16Value |= ((value & 0x000000F0) << (10-4));
        	extraData16Value |= 0x0002;
        	break;
        case 0x09:
            {
            	int origValue = value;
            	int pwr = 0;
		if (value != 0) {
            		while ( ( value & 1 ) != 1 ) {
            			value >>= 1;
            			pwr++;
            		}
		}
            	if ( ( value != 1 ) || ( pwr < 4 ) || ( pwr > 8 ) ) {
        		    sprintf(errStr,"Illegal entry value %d",(int)origValue);
        		    *errmsg = errStr;
        		    break;
            	}
            	extraData16Value |= ((pwr-4) << 2);
            	extraData16Value |= 0x4000;
            	break;
            }
        case 0x0A:
        	*errmsg = NULL;
        	if ( ( value > 128 ) || ( value <= 0 ) ) {
    		    sprintf(errStr,"Illegal imm. size %d",(int)value);
    		    *errmsg = errStr;
    		    break;
        	}
        	extraData16Value |= ( value << 5 );
        	extraData16Value |= 0x0008;
        	break;
        case 0x0B:
        	*errmsg = NULL;
        	if ( (value & 0xFFFFFF83) != 0 ) {
    		    sprintf(errStr,"Illegal imm. offse %d",(int)value);
    		    *errmsg = errStr;
    		    break;
        	}
        	extraData16Value |= ((value & 0x0000007C) << (8-2));
        	break;
        case 0x0C:
               if ( ( value > 1 ) || ( value < 0 ) ) {
                   sprintf(errStr,"Illegal imm. pad %d",(int)value);
                   *errmsg = errStr;
                   break;
               }
               extraData16Value |= (value << 4);
               break;
        case 0x0D:
               if ( ( value > 1 ) || ( value < 0 ) ) {
                   sprintf(errStr,"Illegal imm. init %d",(int)value);
                   *errmsg = errStr;
                   break;
               }
               extraData16Value |= (value << 13);
               break;
        case 0x0E:
               if ((value != 16) && (value != 32) && (value != 64) && (value != 128) && (value != 256)) {
                       *errmsg = _("Illegal entry size value");
                       break;
               }
               while (((value/16) >> 1) != 0) {
                       value = value >> 1;
                       tmp++;
               }
               limm |= (tmp << 20);
               break;
        case 0x0F:
            if ((value != 8) && (value != 16) && (value != 32) && (value != 64) && (value != 128) && (value != 256)) {
                    *errmsg = _("Illegal entry size value");
                    break;
            }
            tmp = 1;
            while (((value/8) >> 1) != 0) {
                    value = value >> 1;
                    tmp = (tmp << 1);
            }
            limm |= (tmp << 8);
        	break;
	default:
		*errmsg = _("Unknown special mode");
		break;
	}
	return;
}


/* insert_skipRes
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_skipRes   (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	if ( ( (value & (~0x30)) != 0 ) || (value == 48) ) {
#if 0
	    *errmsg = _("Invalid SkipRes value");
#else
		static char errStr[100];
        sprintf((char *)errStr,"Invalid SkipRes value %d",(int)value);
    	*errmsg = (const char *)errStr;
#endif
	    return insn;
	}
	value >>= 4;
	extraData16Value |= (value << operand->shift);
    return insn;
}

/* insert_cmd16_32
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_cmd16_32   (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
		if ( operand->shift == 0 ) {
			if ( extraData != 32 ) {
	            extraData16Value |= operand->bits;
			}
			else {
	            limm |= operand->bits;
	        	limm_p = 1;
			}
		}
	    if ( operand->bits == 0 ) {
			if ( extraData != 32 ) {
                extraData16Value |= (1 << operand->shift);
			}
			else {
				if (operand->shift == 32)
					limm = 0;
				else
					limm |= (1 << operand->shift);
	        	limm_p = 1;
			}
	    }
	    if ( ( operand->shift != 0 ) && (operand->bits != 0) ) {
			int val = operand->bits;
			if ( extraData != 32 ) {
                extraData16Value |= (val << operand->shift);
			}
			else {
                limm |= (val << operand->shift);
	        	limm_p = 1;
			}
	    }
    return insn;
}

/* insert_size_1248
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_size_1248    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int dstInsn = 0;
	if ((insn & 0xf8ff0000) == 0x38590000) dstInsn = 1;
	switch(value) {
        case 1:
        	if ( dstInsn == 0 ) {
        	    extraData16Value |= (0 << operand->shift);
        	}
        	else {
        	    insn |= (0 << operand->shift);
        	}
        	break;
        case 2:
        	if ( dstInsn == 0 ) {
        	    extraData16Value |= (1 << operand->shift);
        	}
        	else {
        	    insn |= (1 << operand->shift);
        	}
    	    break;
        case 4:
        	if ( dstInsn == 0 ) {
        	    extraData16Value |= (2 << operand->shift);
        	}
        	else {
        	    insn |= (2 << operand->shift);
        	}
    	    break;
        case 8:
            	if ( dstInsn == 0 ) {
            	    extraData16Value |= (3 << operand->shift);
            	}
            	else {
            	    insn |= (3 << operand->shift);
            	}
        		break;
        default:
         	     *errmsg = _("valid size values are: 1,2,4,8");
         	     break;
	}
	return insn;
}

/* insert_cmd_operand
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_cmd_operand    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int maxValue = 0;
	int minValue = 0;
	int mask;
	int check = 0;
	int shift = operand->shift;
	if ( operand->flags & ARC_OPERAND_SIGNED ) {
		minValue = 0 - (1 << (operand->bits - 1));
		maxValue = 0 - minValue - 1;
		check = 1;
	}
	if ( operand->flags & ARC_OPERAND_UNSIGNED ) {
		maxValue = (1 << operand->bits) - 1;
		minValue = 0;
		check = 1;
	}
	if ( ( ( insn & 0xf81f0000 ) == 0x581d0000 ) && (shift == 0 ) ) { /* command e4by index3 */
		maxValue = 7;
		minValue = 4;
	}
	if ( ( ( insn & 0xf8ff0000 ) == 0x38760000 ) && (shift == 6 ) ) { /* command hofs */
		if ((value % 16))
			*errmsg = _("Illegal min_hofs value");
		value = value / 16;
	}
	if ( check != 0 ) {
		if ( operand->flags & ARC_NPS_DECR_1 ) {
			value--;
		}
		if ( operand->flags & ARC_NPS_DECR_MASK ) {
			if ( value == 0 ) value--;
			if ( value == (1 << operand->bits) ) {
				value = 0;
			}
		}
	    if ( value > maxValue) {
            *errmsg = _("value too high");
	    }
	    if ( value < minValue) {
	    	if ( ( ( insn & 0x001f0000 ) == 0x001d0000 ) && (shift == 0 ) && (value <= 3) ) {
	    		*errmsg = _("Valid values 4-7 for INDEX3");
	    	}
	    	else {
		        *errmsg = _("value too low");
	    	}
	    }
	}
	mask = (1 << operand->bits) - 1;
	value &= mask;
	mask <<= shift;
	value <<= shift;
	insn = (insn & (~mask)) | value;
    return insn;
}

/* insert_nTo48
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_nTo48   (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int maxValue = 0;
	int minValue = 0;
	int mask;
	int check = 0;
	int shift = operand->shift;
	if ( operand->flags & ARC_OPERAND_SIGNED ) {
		minValue = 0 - (1 << (operand->bits - 1));
		maxValue = 0 - minValue - 1;
		check = 1;
	}
	if ( ( operand->flags & ARC_OPERAND_UNSIGNED ) ||
		 ( operand->flags & ARC_OPERAND_ADDRESS ) ||
		 (operand->bits == 1) ) {
		maxValue = (1 << operand->bits) - 1;
		minValue = 0;
		check = 1;
		if ( operand->fmt == 0x9e /* \236 */ ) {
			unsigned int tmp = value & 0xFFFF0000;
			if ( tmp != 0 ) {
				if ( tmp == VALID_MSB_CCM1 ) {
					value &= 0x0000FFFF;
				}
			}
		}
	}
	if ( check != 0 ) {
		if ( operand->flags & ARC_NPS_DECR_1 ) {
			value--;
		}
		if ( operand->flags & ARC_NPS_DECR_MASK ) {
			if ( value == 0 ) value--;
			if ( value == (1 << operand->bits) ) {
				value = 0;
			}
		}
	    if ( value > maxValue) {
		    *errmsg = _("value too high");
	    }
	    if ( value < minValue) {
		    *errmsg = _("value too low");
	    }
            if (operand->fmt == 0244) {
                if ((value % 16) || (value > 240)) {
                        *errmsg = _("illegal offset value");
                }
            }
            if (operand->fmt == 0245) {
                if ((value % 16)) {
                        *errmsg = _("illegal size value");
                }
            }
	}

	if ( ( shift & NPS_SPECIAL_FIELD ) != 0 ) {
		shift &= ~(NPS_SPECIAL_FIELD);
		procSpecialField(shift,value,errmsg);
	    return insn;
	}
	if ( ( shift & NPS_32_FIELD ) != 0 ) {
		shift &= ~(NPS_32_FIELD);
		if ( extraData == 48 ) {
			shift += 16;
		}
	}
	switch (extraData) {
	    case 16:
	    	mask = (1 << operand->bits) - 1;
	    	value &= mask;
	    	mask <<= shift;
	    	value <<= shift;
	    	extraData16Value = (extraData16Value & (~mask)) | value;
	    	break;
	    case 32:
	    	mask = (1 << operand->bits) - 1;
	    	value &= mask;
	    	mask <<= shift;
	    	value <<= shift;
	    	limm = (limm & (~mask)) | value;
	    	limm_p = 1;
	    	break;
	    case 48:
	    	if ( shift < 48 ) {
	    		if (shift < 16 ) {
	    	    	mask = (1 << operand->bits) - 1;
	    	    	value &= mask;
	    	    	mask <<= shift;
	    	    	value <<= shift;
	    	    	extraData16Value = (extraData16Value & (~mask)) | value;
	    		}
	    		else {
	    	    	mask = (1 << operand->bits) - 1;
	    	    	value &= mask;
	    	    	mask <<= shift-16;
	    	    	value <<= shift-16;
	    	    	limm = (limm & (~mask)) | value;
	    	    	limm_p = 1;
	    		}
	    	}
	    	break;
	}
	if ( operand->fmt == 0335 ) {
		if ( (flag335 !=0) && (prev335 != value) ) {
			*errmsg = _("both offsets must be equal");
		}
		flag335 = 1;
		prev335 = value;
	}
    return insn;
}

/* validate nps constant commands parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
validate_u6_124    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	long val = (insn >> operand->shift) & ((1 << operand->bits) - 1);

	switch (val) {
	case 1:
	case 2:
	case 4:
		break;
	default:
		*errmsg = _("Valid values 1,2,4 for src2 as u6");
		break;
	}
    return insn;
}


/* check nps arithmetic commands parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_arith    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int subopcode = (extraData16Value & 0x001F) >>  0;
	int size = ((extraData16Value & 0x03E0) >>  5) + 1;
	int ri = (extraData16Value & 0x0200) >> 8;
	int imm = (extraData16Value & 0x01E0) >> 5;
	int mode = (extraData16Value & 0xC000) >> 14;
	int src1 = (extraData16Value & 0x0C00 ) >> 10;
	int src2 = (extraData16Value & 0x3000 ) >> 12;
	int dst = (extraData16Value & 0xC000) >> 14; // dst = mode
	int tmp;

	switch (subopcode) {
	  case 0:
	  case 4:
	  case 5:
	  case 6:
		  if ( size < 2 ) {
			    *errmsg = _("minimum size 2");
		  }
		  tmp = (src1 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src1_byte_sel*8 + size) > 32");
		  }
		  tmp = (src2 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src2_byte_sel*8 + size) > 32");
		  }
		  break;
	  case 1:
	  case 2:
	  case 3:
		  tmp = (src1 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src1_byte_sel*8 + size) > 32");
		  }
		  tmp = (src2 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src2_byte_sel*8 + size) > 32");
		  }
		  tmp = (dst << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(dst_byte_sel*8 + size) > 32");
		  }
		  break;
	  case 7:
		  if ( size < 8 ) {
			    *errmsg = _("minimum size 8");
		  }
		  break;
	  case 8: // wxorb_i
		  if ( size < 16 ) {
			    *errmsg = _("minimum size 16");
		  }
		  if ( dst > 2 ) {
			    *errmsg = _("dst_byte_sel > 2");
		  }
		  tmp = (src1 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src1_byte_sel*8 + size) > 32");
		  }
		  tmp = (src2 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src2_byte_sel*8 + size) > 32");
		  }
		  break;
	  case 9:  // notb_i
		  tmp = (src2 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src2_byte_sel*8 + size) > 32");
		  }
		  tmp = (dst << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(dst_byte_sel*8 + size) > 32");
		  }
		  break;
	  case 10:  // cntbb_i
		  tmp = (src2 << 3) + size;
		  if ( tmp > 32 ) {
			    *errmsg = _("(src2_byte_sel*8 + size) > 32");
		  }
		  break;
	  case 13:
		  if ( mode == 3 ) {
			    *errmsg = _("Illegal mode (3)");
			    break;
		  }
		  if ( ( ri != 0 ) && ( imm == 0 ) ) {
			  *errmsg = _("Illegal value (0) in 'imm' field ");
		  }
		  break;
	}
    return insn;
}

static arc_insn checkAddClear(arc_insn insn)
{
	if ( lastOpcodeSyntax != NULL ) {
		if (strstr(lastOpcodeSyntax,".cl") != NULL) {
			if ( ( strncmp(lastOpcodeSyntax,"mov4b",5) == 0 ) || ( strncmp(lastOpcodeSyntax,"mov3b",5) == 0 ) ) {
				insn |= 0x0001;
			}
			else {
			    limm |= 0x80000000;
			}
		}
	}
	return insn;
}

/* set_limm_p -
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
set_limm_p    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	limm_p = 1;
    return insn;
}

/* dup_bits - duplicates bits
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
dup_bits    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
    unsigned int mask = (1 << operand->bits)-1;
    int srcShift = operand->bits + operand->shift;
    mask <<= srcShift;
    value = (insn & mask) >> operand->bits;
    insn |= value;
    return insn;
}

/*  AR - check if we need routine exb_w_check !!!! */
/* check exb/exw parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
exb_w_check    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
    unsigned ac_reg_hi = (insn >> 12) & 7;
    unsigned ac_reg_lo = (insn >> 24) & 7;
    unsigned ac_reg_num = (ac_reg_hi << 3) | ac_reg_lo;
    insn |= ac_reg_num;
    return insn;
}

/* check movb_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_movb    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int subOpcode = insn & 0x000F;
	int src  = (extraData16Value & 0x001F) >>  0;
	int dst  = (extraData16Value & 0x03E0) >>  5;
	int size = (extraData16Value & 0x7C00) >> 10;
	int clear = (extraData16Value & 0x8000) >> 15;
	*errmsg = NULL;
	switch (subOpcode) {
	    case 0:
		    if ( ( src == 17 ) || ( src == 18 ) ) {
		    	if ( (dst+size) >= 32 ) {
		    		*errmsg = _("position+size > 32");
		    	}
		    }
		    break;
	    case 1:
	    	if ((src+size) >= 32) {
	    	    *errmsg = _("source register - maximum 32 bits");
	    	}
	    	if ((dst+size) >= 32) {
	    	    *errmsg = _("destination register - maximum 32 bits");
	    	}
	    	if ( ( clear == 0 ) && (lastOpcodeSyntax != NULL) ) {
	    		if ( strstr(lastOpcodeSyntax,"%b,%b,%c") == NULL ) {
	    		    *errmsg = _("source register missing");
	    		}
	    	}
	    	break;
	    case 3:
	    	if ((src+size) >= 32) {
	    	    *errmsg = _("source register - maximum 32 bits");
	    	}
	    	if ( ( extraData16Value & 0x8060 ) == 0x8060 ) {
	    		size = 31 - src;
		    	extraData16Value &= 0x83FF;
		    	extraData16Value |= ( size << 10);
	    	}
	    	break;
	    case 4:
	    	if ((src+size) >= 32) {
	    	    *errmsg = _("source register - maximum 32 bits");
	    	}
	    	if ((dst+size) >= 32) {
	    	    *errmsg = _("destination register - maximum 32 bits");
	    	}
	    	if ( dst > 27 ) {
	    	    *errmsg = _("destination must start at bit 27 or less");
	    	}
	    	if ( ( clear == 0 ) && (lastOpcodeSyntax != NULL) ) {
	    		if ( strstr(lastOpcodeSyntax,"%b,%b,%c") == NULL ) {
	    		    *errmsg = _("source register missing");
	    		}
	    	}
	    	break;
	    case 15:
	    	size = 1 << (size & 3);
	    	if ((dst+size) > 32) {
	    	    *errmsg = _("destination register - maximum 32 bits");
	    	}
	    	break;
	}
    return insn;
}

/* check mov2b_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_mov2b    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int dst1   = (limm & 0x00007C00) >>  10;
	int dst2   = (limm & 0x000F8000) >>  15;
	checkAddClear(insn);
#if 0
	if ( dst1 == dst2 ) {
	    *errmsg = _("destination bit 1 equal destination bit 2");
	}
#endif
    return insn;
}

/* check mov4b_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_mov4b    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int dst1   = (limm & 0x00007C00) >>  10;
	int dst2   = (limm & 0x000F8000) >>  15;
	int dst3   = (extraData16Value & 0x000003E0) >>  5;
	int dst4   = (extraData16Value & 0x00007C00) >>  10;
	int mov3bCase = ( strncmp(lastOpcodeSyntax,"mov3b",5) == 0 )  ? 1 : 0;
	if ( mov3bCase != 0 ) {
		extraData16Value |= dst3 <<10;  // write dst3 on dst4
		limm |= 0x80000000;
	}
	insn = checkAddClear(insn);
#if 0
	if ( dst1 == dst2 ) {
	    *errmsg = _("destination bit 1 equal destination bit 2");
	}
	if ( dst1 == dst3 ) {
	    *errmsg = _("destination bit 1 equal destination bit 3");
	}
	if ( dst2 == dst3 ) {
	    *errmsg = _("destination bit 2 equal destination bit 3");
	}
	if ( mov3bCase == 0 ) {
	    if ( dst1 == dst4 ) {
	        *errmsg = _("destination bit 1 equal destination bit 4");
	    }
	    if ( dst2 == dst4 ) {
	        *errmsg = _("destination bit 2 equal destination bit 4");
	    }
	    if ( dst3 == dst4 ) {
	        *errmsg = _("destination bit 3 equal destination bit 4");
	    }
	}
#endif
    return insn;
}

/* check ext4b_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_ext4b    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int dst    = (limm & 0x01F00000) >>  20;
	checkAddClear(insn);
	if ( dst > 28 ) {
	    *errmsg = _("destination position > 28");
	}
    return insn;
}


/* check ins4b_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_ins4b    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int dst1   = (limm & 0x0000001F) >>   0;
	int dst2   = (limm & 0x000003E0) >>   5;
	int dst3   = (limm & 0x00007C00) >>  10;
	int dst4   = (limm & 0x000F8000) >>  15;
	int src    = (limm & 0x01F00000) >>  20;
	checkAddClear(insn);
#if 0
	if ( dst1 == dst2 ) {
	    *errmsg = _("destination bit 1 equal destination bit 2");
	}
	if ( dst1 == dst3 ) {
	    *errmsg = _("destination bit 1 equal destination bit 3");
	}
	if ( dst1 == dst4 ) {
	    *errmsg = _("destination bit 1 equal destination bit 4");
	}
	if ( dst2 == dst3 ) {
	    *errmsg = _("destination bit 2 equal destination bit 3");
	}
	if ( dst2 == dst4 ) {
	    *errmsg = _("destination bit 2 equal destination bit 4");
	}
	if ( dst3 == dst4 ) {
	    *errmsg = _("destination bit 3 equal destination bit 4");
	}
#endif
	if ( src > 28 ) {
	    *errmsg = _("sourse position > 28");
	}
    return insn;
}

/* check mxb parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrelavent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_mxb    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int v = extraData16Value & 0x0000FFFF;
	int FieldSz = (v & 0x000001C0) >> 6;
	int BitsToScramble = (v & 0x00007000) >> 12;
	if (FieldSz == 0) FieldSz = 8;
	if (BitsToScramble == 0) BitsToScramble = 8;

	if (BitsToScramble > FieldSz)
		*errmsg = _("BitsToScramble can't be bigger than FieldSz");
	return insn;
}

/* add clear to mov4b_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_clear_mov4b    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
    insn |= 0x0001;
    return insn;
}

/* check mrgb_i parameters
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_valid_mrgb    (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
        const struct arc_operand *operand ATTRIBUTE_UNUSED,
        int mods ATTRIBUTE_UNUSED,
        const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
        long value ATTRIBUTE_UNUSED,
        const char **errmsg ATTRIBUTE_UNUSED
       )
{
	int src1   = (limm & 0x0000001F) >>  0;
	int src2   = (limm & 0x000003E0) >>  5;
	int dst1  = (limm & 0x00007C00) >>  10;
	int dst2  = (limm & 0x000F8000) >>  15;
	int size1   = (limm & 0x01F00000) >>  20;
	int size2   = (limm & 0x3E000000) >>  25;
	unsigned int mask1;
	unsigned int mask2;
	checkAddClear(insn);
	if ((src1+size1) > 32) {
	    *errmsg = _("source register 1 - maximum 32 bits");
	    return insn;
	}
	if ((dst1+size1) > 32) {
	    *errmsg = _("destination register 1 - maximum 32 bits");
	    return insn;
	}
	if ((src2+size2) > 32) {
	    *errmsg = _("source register 2 - maximum 32 bits");
	    return insn;
	}
	if ((dst2+size2) > 32) {
	    *errmsg = _("destination register 2 - maximum 32 bits");
	    return insn;
	}
#if 0
	mask1 = ( (dst1+size1) == 32 ) ? (unsigned int) 0xFFFFFFFF : (unsigned int) (1 << (dst1+size1))-1;
	mask1 ^= (1 << dst1)-1;
	mask2 = ( (dst2+size2) == 32 ) ? (unsigned int) 0xFFFFFFFF : (unsigned int) (1 << (dst2+size2))-1;
	mask2 ^= (1 << dst2)-1;
	if ( (mask1&mask2) != 0 ) {
	    *errmsg = _("destination mask not ortigonal");
	}
#endif
    return insn;
}

/* Insert_su16 lables parameters.
 * insn    Top half of instruction.
 * ex      Bottom half of instruction, receives value in lower 15 bits.
 * operand unused.
 * reg     irrevent, only used for register operands.
 * value   Signed twelve bit number.
 * errmsg  error message.
 */
static arc_insn
insert_su16  (arc_insn insn, long *ex ATTRIBUTE_UNUSED,
            const struct arc_operand *operand ATTRIBUTE_UNUSED,
            int mods ATTRIBUTE_UNUSED,
            const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
            long value ATTRIBUTE_UNUSED,
            const char **errmsg ATTRIBUTE_UNUSED
           )
{
	if ( ( insn & 0xF800 ) == 0x4800 ) {  // major = 0x9
		int lValue = (int)value;
		if ( operand->flags & ARC_OPERAND_SIGNED ) {
	        if ( ( lValue >= 0x8000 )  || ( lValue < -0x8000 ) ) {
	            *errmsg = _("value out of range +/-32k");
	            return insn;
	        }
	    }
		if ( operand->flags & ARC_OPERAND_UNSIGNED ) {
	        if ( lValue & 0xFFFF0000 ) {
	            *errmsg = _("value out of range 0-64k");
	            return insn;
	        }
	    }
	}
	if ( ( insn & 0xF800 ) == 0x5800 ) {  // major = 0xB
		if ( ( value & 0xFFFF0000 ) == 0x57F00000 ) value &= 0x0000FFFF;
        if ( value & 0xFFFF0000 ) {
            *errmsg = _("value out of range 0-64k");
            return insn;
        }
	}
    extraData16Value = value & 0x0000FFFF;
    return insn;
}

int getExtraData16value(void)
{
    return extraData16Value;
}

void setExtraData16value(int value)
{
    extraData16Value = value;
}

#endif // #ifdef ARC_NPS_CMDS
/* Used in st insns to do final disasemble syntax check.  */

static long
extract_st_syntax (arc_insn *insn,
		   const struct arc_operand *operand ATTRIBUTE_UNUSED,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		   int *invalid)
{
#define ST_SYNTAX(V,B,O) \
((ls_operand[LS_VALUE]  == (V) && \
  ls_operand[LS_BASE]   == (B) && \
  ls_operand[LS_OFFSET] == (O)))

  if (!((ST_SYNTAX(OP_REG,OP_REG,OP_NONE) && (insn[0] & 511) == 0)
	|| ST_SYNTAX(OP_REG,OP_LIMM,OP_NONE)
	|| (ST_SYNTAX(OP_SHIMM,OP_REG,OP_NONE) && (insn[0] & 511) == 0)
	|| (ST_SYNTAX(OP_SHIMM,OP_SHIMM,OP_NONE) && (insn[0] & 511) == 0)
	|| ST_SYNTAX(OP_SHIMM,OP_LIMM,OP_NONE)
	|| ST_SYNTAX(OP_SHIMM,OP_LIMM,OP_SHIMM)
	|| ST_SYNTAX(OP_SHIMM,OP_SHIMM,OP_SHIMM)
	|| (ST_SYNTAX(OP_LIMM,OP_REG,OP_NONE) && (insn[0] & 511) == 0)
	|| ST_SYNTAX(OP_REG,OP_REG,OP_SHIMM)
	|| ST_SYNTAX(OP_REG,OP_SHIMM,OP_SHIMM)
	|| ST_SYNTAX(OP_SHIMM,OP_REG,OP_SHIMM)
	|| ST_SYNTAX(OP_LIMM,OP_SHIMM,OP_SHIMM)
	|| ST_SYNTAX(OP_LIMM,OP_SHIMM,OP_NONE)
	|| ST_SYNTAX(OP_LIMM,OP_REG,OP_SHIMM)))
    *invalid = 1;
  return 0;
}

int
arc_limm_fixup_adjust (arc_insn insn)
{
  int retval = 0;

  /* Check for st shimm,[limm].  */

  if ((insn & (I(-1) | C(-1) | B(-1))) ==
      (I(2) | C(ARC_REG_SHIMM) | B(ARC_REG_LIMM)))
    {
      retval = insn & 0x1ff;
      if (retval & 0x100) /* Sign extend 9 bit offset.  */
	retval |= ~0x1ff;
    }
  return -retval; /* Negate offset for return.  */
}

/* Used in st insns to do final syntax check.  */

static arc_insn
insert_st_syntax (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand ATTRIBUTE_UNUSED,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg)
{
  /* do syntax check for ARCompact 'st' insn */
  /* TODO - check for validity of operands for ARCompact store insn */

  if (addrwb_p)
    {
      if (ls_operand[LS_BASE] != OP_REG)
        *errmsg = _("address writeback not allowed");
      insn |= addrwb_p;
    }
  return insn;
}

/* Used in ld insns to do final syntax check.  */

static arc_insn
insert_ld_syntax (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand ATTRIBUTE_UNUSED,
		  int mods ,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg)
{
#define LD_SYNTAX(D, B, O) \
  (   (ls_operand[LS_DEST]   == (D) \
    && ls_operand[LS_BASE]   == (B) \
    && ls_operand[LS_OFFSET] == (O)))

#define X(x,b,m) ((unsigned)((x)&(((1<<m)-1)<<b))>>b)

  /* do syntax check for ARCompact 'ld' insn */
  /* TODO - check for validity of operands for ARCompact load insn */

  /* Extract operand 6 bits of the A field from insn starting at bit
     position 0.  */
  unsigned char ac_reg_num = X(insn,0,6);

  if (addrwb_p)
    {
      if (ls_operand[LS_BASE] != OP_REG
          /* .as is not actually an address write-back.  */
          && addrwb_p != 0xc00000  && (mods & ARC_OPERAND_ERROR))
        *errmsg = _("address writeback not allowed");
      insn |= addrwb_p;
    }

  /* Fixme: We should hash define register names to their respective
     numbers and not use them as 29, 30, 31,....  */

  if (0x20 <= ac_reg_num && ac_reg_num <= 0x3F)
    {
      if (!((arc_ld_ext_mask >> (ac_reg_num - 32)) & 1))
        *errmsg = _("ld operand error: Instruction Error exception");
    }

  /* Ravi: operand validity checks for the ARC700 */
  if (cpu_type == ARC_MACH_ARC7 && arc_user_mode_only)
    /* if (arc_get_opcode_mach (arc_mach_type, 0) == ARC_MACH_ARC7) */
    {
      if (ac_reg_num == 29 || ac_reg_num == 30)
        {
          *errmsg = _("ld operand error: Privilege Violation exception");
        }
    }
  if ((cpu_type & ARC_MACH_ARCV2) && arc_user_mode_only && (ac_reg_num == 29))
    {
      *errmsg = _("ld operand error: Privilege Violation exception");
    }

  return insn;
}

/* Used in ld insns to do final syntax check.  */

static long
extract_ld_syntax (arc_insn *insn,
		   const struct arc_operand *operand ATTRIBUTE_UNUSED,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		   int *invalid)
{
  int test = insn[0] & I(-1);

  if (!(test == I(1)))
    {
      if ((ls_operand[LS_DEST] == OP_SHIMM || ls_operand[LS_BASE] == OP_SHIMM
	   || ls_operand[LS_OFFSET] == OP_SHIMM))
	*invalid = 1;
    }
  if (!(   (LD_SYNTAX (OP_REG, OP_REG, OP_NONE) && test == I (1))
	||  LD_SYNTAX (OP_REG, OP_REG, OP_REG)
	||  LD_SYNTAX (OP_REG, OP_REG, OP_SHIMM)
	|| (LD_SYNTAX (OP_REG, OP_REG, OP_LIMM) && test != I (1))
	|| (LD_SYNTAX (OP_REG, OP_LIMM, OP_REG) && test != I (1))
	|| (LD_SYNTAX (OP_REG, OP_SHIMM, OP_NONE) && shimm == 0)
	||  LD_SYNTAX (OP_REG, OP_SHIMM, OP_SHIMM)
	|| (LD_SYNTAX (OP_REG, OP_LIMM, OP_NONE) && test == I (1))))
       *invalid = 1;
  return 0;
}

static arc_insn
insert_ex_syntax (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand ATTRIBUTE_UNUSED,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg)
{
  unsigned ac_reg_hi = X (insn, 12, 3);
  unsigned ac_reg_lo = X (insn, 24, 3);
  unsigned ac_reg_num = (ac_reg_hi << 3) | ac_reg_lo;
  /* Ravi: operand validity checks for the ARC700 */
  if (cpu_type == ARC_MACH_ARC7)
  /* if (arc_get_opcode_mach (arc_mach_type, 0) == ARC_MACH_ARC7) */
    {
      if (arc_user_mode_only && (ac_reg_num == 29 || ac_reg_num == 30))
	*errmsg = _("ex operand error: Privilege Violation exception");
      if (0x20 <= ac_reg_num && ac_reg_num <= 0x3F
	  && !((arc_ld_ext_mask >> (ac_reg_num - 32)) & 1))
	*errmsg = _("ld operand error: Instruction Error exception");
    }
  else if (cpu_type & ARC_MACH_ARCV2)
    {
      if (arc_user_mode_only && ac_reg_num == 29)
	{
	  *errmsg = _("ex operand error: Privilege Violation exception");
	}
    }
  return insn;
}


/* Called at the end of processing normal insns (eg: add) to insert a shimm
   value (if present) into the insn.  */

static arc_insn
insert_shimmfinish (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		    const struct arc_operand *operand,
		    int mods ATTRIBUTE_UNUSED,
		    const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		    long value ATTRIBUTE_UNUSED,
		    const char **errmsg ATTRIBUTE_UNUSED)
{
  if (shimm_p)
    insn |= (shimm & ((1 << operand->bits) - 1)) << operand->shift;
  return insn;
}

/* Called at the end of processing normal insns (eg: add) to insert a limm
   value (if present) into the insn.

   Note that this function is only intended to handle instructions (with 4 byte
   immediate operands).  It is not intended to handle data.  */

/* ??? Actually, there's nothing for us to do as we can't call frag_more, the
   caller must do that.  The extract fns take a pointer to two words.  The
   insert fns could be converted and then we could do something useful, but
   then the reloc handlers would have to know to work on the second word of
   a 2 word quantity.  That's too much so we don't handle them.  */

static arc_insn
insert_limmfinish (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		   const struct arc_operand *operand ATTRIBUTE_UNUSED,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		   long value ATTRIBUTE_UNUSED,
		   const char **errmsg ATTRIBUTE_UNUSED)
{
  return insn;
}

static arc_insn
insert_jumpflags (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value,
		  const char **errmsg)
{
  if (!flag_p)
    *errmsg = _("jump flags, but no .f seen");

  else if (!limm_p)
    *errmsg = _("jump flags, but no limm addr");

  else if (limm & 0xfc000000)
    *errmsg = _("flag bits of jump address limm lost");

  else if (limm & 0x03000000)
    *errmsg = _("attempt to set HR bits");

  else if ((value & ((1 << operand->bits) - 1)) != value)
    *errmsg = _("bad jump flags value");

  jumpflags_p = 1;
  limm = ((limm & ((1 << operand->shift) - 1))
	  | ((value & ((1 << operand->bits) - 1)) << operand->shift));
  return insn;
}

/* Called at the end of unary operand macros to copy the B field to C.  */

static arc_insn
insert_unopmacro (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		  const struct arc_operand *operand,
		  int mods ATTRIBUTE_UNUSED,
		  const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		  long value ATTRIBUTE_UNUSED,
		  const char **errmsg ATTRIBUTE_UNUSED)
{
  insn |= ((insn >> ARC_SHIFT_REGB) & ARC_MASK_REG) << operand->shift;
  return insn;
}

/* Insert a relative address for a branch insn (b, bl, or lp).  */

static arc_insn
insert_reladdr (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		const struct arc_operand *operand,
		int mods ATTRIBUTE_UNUSED,
		const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		long value,
		const char **errmsg)
{
  if ('h' == operand->fmt)
    {
      if (value & 3)
	*errmsg = _("branch address not on 4 byte boundary");

      value = value >> 2;
      /* Insert least significant 9-bits.  */
      insn |= (value & 0x1ff) << operand->shift;
      /* Insert most significant 10-bits.  */
      insn |= ((value >> 9) & 0x3ff) << 6;
    }
  else if ('H' == operand->fmt)
    {
      if (value & 3)
	*errmsg = _("branch address not on 4 byte boundary");

      value = value >> 2;
      /* Insert least significant 9-bits.  */
      insn |= (value & 0x1ff) << operand->shift;
      /* Insert next least significant 10-bits.  */
      insn |= ((value >> 9) & 0x3ff) << 6;
      /* Insert most significant 4-bits.  */
      insn |= (value >> 19) & 0xf;
    }
  else if ('i' == operand->fmt)
    {
      if (value & 1)
	*errmsg = _("branch address not on 2 byte boundary");

      value = value >> 1;
      /* Insert least significant 10-bits.  */
      insn |= (value & 0x3ff) << operand->shift;
      /* Insert most significant 10-bits.  */
      insn |= ((value >> 10) & 0x3ff) << 6;
    }
  else if ('I' == operand->fmt)
    {
      if (value & 1)
	*errmsg = _("branch address not on 2 byte boundary");

      value = value >> 1;
      /* Insert least significant 10-bits.  */
      insn |= (value & 0x3ff) << operand->shift;
      /* Insert next least significant 10-bits.  */
      insn |= ((value >> 10) & 0x3ff) << 6;
      /* Insert most significant 4-bits.  */
      insn |= (value >> 20) & 0xf;
    }
  else if ('d' == operand->fmt)
    {
      /* Insert least significant 7-bits.  */
      insn |= ((value >> 1) & 0x7f) << operand->shift;
      /* Insert most significant bit.  */
      insn |= (((value >> 1) & 0x80) >> 7) << 15;
    }
  else if ('y' == operand->fmt)
    {
      /* Insert most significant 6-bits of 7-bit unsigned immediate value.  */
      insn |= ((value >> 1) & 0x3f) << operand->shift;
    }
  else if ('Y' == operand->fmt)
    {
      /* Insert bit-1 to bit-6 of 13-bit signed immediate value.  */
      insn |= ((value >> 1) & 0x3f) << operand->shift;
      /* Insert bit-7 to bit-13 of 13-bit signed immediate value.  */
      insn |= ((value >> 1) & 0xfc0) >> 6;
    }
  else if (('s' == operand->fmt) || ('S' == operand->fmt)
            || ('Z' == operand->fmt))
    {
      if (value & 1)
	*errmsg = _("branch address not on 2 byte boundary");
      insn |= ((value >> 1) & ((1 << operand->bits) - 1)) << operand->shift;
    }
  else if ('W' == operand->fmt)
    {
      if (value & 3)
	*errmsg = _("branch address not on 4 byte boundary");
      insn |= ((value >> 2) & ((1 << operand->bits) - 1)) << operand->shift;
    }
  else
    {
      /* TODO: When support for ARCtangent-A4 was removed this code was
         left over, and included a comment right here, that implied this
         code would only ever be reached for the A4 architecture, in which
         case this code is now unreachable.  We should consider replacing
         this code with an error.  */

      if (value & 3)
	*errmsg = _("branch address not on 4 byte boundary");
      insn |= ((value >> 2) & ((1 << operand->bits) - 1)) << operand->shift;
    }
  return insn;
}

/* Insert a limm value as a 26 bit address right shifted 2 into the insn.

   Note that this function is only intended to handle instructions (with 4 byte
   immediate operands).  It is not intended to handle data.  */

/* ??? Actually, there's little for us to do as we can't call frag_more, the
   caller must do that.  The extract fns take a pointer to two words.  The
   insert fns could be converted and then we could do something useful, but
   then the reloc handlers would have to know to work on the second word of
   a 2 word quantity.  That's too much so we don't handle them.

   We do check for correct usage of the nullify suffix, or we
   set the default correctly, though.  */

static arc_insn
insert_absaddr (arc_insn insn,long *ex ATTRIBUTE_UNUSED,
		const struct arc_operand *operand ATTRIBUTE_UNUSED,
		int mods ATTRIBUTE_UNUSED,
		const struct arc_operand_value *reg ATTRIBUTE_UNUSED,
		long value ATTRIBUTE_UNUSED,
		const char **errmsg)
{
  if (limm_p)
    {
      /* If it is a jump and link, .jd must be specified.  */
      if (insn & R (-1, 9, 1))
	{
	  if (!nullify_p)
	    insn |=  0x02 << 5;  /* Default nullify to .jd.  */
	  else if (nullify != 0x02)
	    *errmsg = _("must specify .jd or no nullify suffix");
	}
    }
  return insn;
}

/* Extraction functions.

   The suffix extraction functions' return value is redundant since it can be
   obtained from (*OPVAL)->value.  However, the boolean suffixes don't have
   a suffix table entry for the "false" case, so values of zero must be
   obtained from the return value (*OPVAL == NULL).  */

/* Called by the disassembler before printing an instruction.  */

void
arc_opcode_init_extract (void)
{
  arc_opcode_init_insert ();
}

static const struct arc_operand_value *
lookup_register (int type, long regno)
{
  const struct arc_operand_value *r,*end;
  struct arc_ext_operand_value *ext_oper = arc_ext_operands;

  while (ext_oper)
    {
      if (ext_oper->operand.type == type && ext_oper->operand.value == regno)
	return (&ext_oper->operand);
      ext_oper = ext_oper->next;
    }

  if (type == REG || type == REG_AC)
    return &arc_reg_names[regno];

  /* ??? This is a little slow and can be speeded up.  */
  for (r = arc_reg_names, end = arc_reg_names + arc_reg_names_count;
       r < end; ++r)
    if (type == r->type	&& regno == r->value)
      return r;
  return 0;
}

/* As we're extracting registers, keep an eye out for the 'f' indicator
   (ARC_REG_SHIMM_UPDATE).  If we find a register (not a constant marker,
   like ARC_REG_SHIMM), set OPVAL so our caller will know this is a register.

   We must also handle auxiliary registers for lr/sr insns.  They are just
   constants with special names.  */

static long
extract_reg (arc_insn *insn,
	     const struct arc_operand *operand,
	     int mods,
	     const struct arc_operand_value **opval,
	     int *invalid ATTRIBUTE_UNUSED)
{
  int regno;
  long value;
  enum operand op_type;

  /* Get the register number.  */
  regno = (*insn >> operand->shift) & ((1 << operand->bits) - 1);

  /* Is it a constant marker?  */
  if (regno == ARC_REG_SHIMM)
    {
      op_type = OP_SHIMM;
      /* Always return zero if dest is a shimm  mlm.  */

      if ('a' != operand->fmt)
	{
	  value = *insn & 511;
	  if ((operand->flags & ARC_OPERAND_SIGNED)
	      && (value & 256))
	    value -= 512;
	  if (!flagshimm_handled_p)
	    flag_p = 0;
	  flagshimm_handled_p = 1;
	}
      else
	value = 0;
    }
  else if (regno == ARC_REG_SHIMM_UPDATE)
    {
      op_type = OP_SHIMM;

      /* Always return zero if dest is a shimm  mlm.  */
      if ('a' != operand->fmt)
	{
	  value = *insn & 511;
	  if ((operand->flags & ARC_OPERAND_SIGNED) && (value & 256))
	    value -= 512;
	}
      else
	value = 0;

      flag_p = 1;
      flagshimm_handled_p = 1;
    }
  else if (regno == ARC_REG_LIMM)
    {
      op_type = OP_LIMM;
      value = insn[1];
      limm_p = 1;

      /* If this is a jump instruction (j,jl), show new pc correctly.  */
      if (0x07 == ((*insn & I(-1)) >> 27))
	value = (value & 0xffffff);
    }

  /* It's a register, set OPVAL (that's the only way we distinguish registers
     from constants here).  */
  else
    {
      const struct arc_operand_value *reg = lookup_register (REG, regno);

      op_type = OP_REG;

      if (reg == NULL)
	abort ();
      if (opval != NULL)
	*opval = reg;
      value = regno;
    }

  /* If this field takes an auxiliary register, see if it's a known one.  */
  if ((mods & ARC_MOD_AUXREG)
      && ARC_REG_CONSTANT_P (regno))
    {
      const struct arc_operand_value *reg = lookup_register (AUXREG, value);

      /* This is really a constant, but tell the caller it has a special
	 name.  */
      if (reg != NULL && opval != NULL)
	*opval = reg;
    }

  switch (operand->fmt)
    {
    case 'a':
      ls_operand[LS_DEST] = op_type;
      break;
    case 's':
      ls_operand[LS_BASE] = op_type;
      break;
    case 'c':
      if ((insn[0]& I(-1)) == I(2))
	ls_operand[LS_VALUE] = op_type;
      else
	ls_operand[LS_OFFSET] = op_type;
      break;
    case 'o': case 'O':
      ls_operand[LS_OFFSET] = op_type;
      break;
    }

  return value;
}

/* Return the value of the "flag update" field for shimm insns.
   This value is actually stored in the register field.  */

static long
extract_flag (arc_insn *insn,
	      const struct arc_operand *operand,
	      int mods ATTRIBUTE_UNUSED,
	      const struct arc_operand_value **opval,
	      int *invalid ATTRIBUTE_UNUSED)
{
  int f;
  const struct arc_operand_value *val;

  if (flagshimm_handled_p)
    f = flag_p != 0;
  else
    f = (*insn & (1 << operand->shift)) != 0;

  /* There is no text for zero values.  */
  if (f == 0)
    return 0;
  flag_p = 1;
  val = arc_opcode_lookup_suffix (operand, 1);
  if (opval != NULL && val != NULL)
    *opval = val;
  return val->value;
}

/* Extract the condition code (if it exists).
   If we've seen a shimm value in this insn (meaning that the insn can't have
   a condition code field), then we don't store anything in OPVAL and return
   zero.  */

static long
extract_cond (arc_insn *insn,
	      const struct arc_operand *operand,
	      int mods ATTRIBUTE_UNUSED,
	      const struct arc_operand_value **opval,
	      int *invalid ATTRIBUTE_UNUSED)
{
  long cond;
  const struct arc_operand_value *val;

  if (flagshimm_handled_p)
    return 0;

  cond = (*insn >> operand->shift) & ((1 << operand->bits) - 1);
  val = arc_opcode_lookup_suffix (operand, cond);

  /* Ignore NULL values of `val'.  Several condition code values are
     reserved for extensions.  */
  if (opval != NULL && val != NULL)
    *opval = val;
  return cond;
}

/* Extract a branch address.
   We return the value as a real address (not right shifted by 2).  */

static long
extract_reladdr (arc_insn *insn,
		 const struct arc_operand *operand,
		 int mods ATTRIBUTE_UNUSED,
		 const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		 int *invalid ATTRIBUTE_UNUSED)
{
  long addr;

  addr = (*insn >> operand->shift) & ((1 << operand->bits) - 1);
  if ((operand->flags & ARC_OPERAND_SIGNED)
      && (addr & (1 << (operand->bits - 1))))
    addr -= 1 << operand->bits;

  return addr << 2;
}

/* Extract the flags bits from a j or jl long immediate.  */

static long
extract_jumpflags (arc_insn *insn,
		   const struct arc_operand *operand,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		   int *invalid)
{
  if (!flag_p || !limm_p)
    *invalid = 1;
  return ((flag_p && limm_p)
	  ? (insn[1] >> operand->shift) & ((1 << operand->bits) -1): 0);
}

/* Extract st insn's offset.  */

static long
extract_st_offset (arc_insn *insn,
		   const struct arc_operand *operand,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		   int *invalid)
{
  int value = 0;

  if (ls_operand[LS_VALUE] != OP_SHIMM || ls_operand[LS_BASE] != OP_LIMM)
    {
      value = insn[0] & 511;
      if ((operand->flags & ARC_OPERAND_SIGNED) && (value & 256))
	value -= 512;
      if (value)
	ls_operand[LS_OFFSET] = OP_SHIMM;
    }
  else
    *invalid = 1;

  return value;
}

/* Extract ld insn's offset.  */

static long
extract_ld_offset (arc_insn *insn,
		   const struct arc_operand *operand,
		   int mods,
		   const struct arc_operand_value **opval,
		   int *invalid)
{
  int test = insn[0] & I(-1);
  int value = 0;

  if (test)
    {
      value = insn[0] & 511;
      if ((operand->flags & ARC_OPERAND_SIGNED) && (value & 256))
	value -= 512;
      if (value)
	ls_operand[LS_OFFSET] = OP_SHIMM;

      return value;
    }
  /* If it isn't in the insn, it's concealed behind reg 'c'.  */
  return extract_reg (insn, &arc_operands[arc_operand_map['c']],
		      mods, opval, invalid);
}

/* The only thing this does is set the `invalid' flag if B != C.
   This is needed because the "mov" macro appears before it's real insn "and"
   and we don't want the disassembler to confuse them.  */

static long
extract_unopmacro (arc_insn *insn,
		   const struct arc_operand *operand ATTRIBUTE_UNUSED,
		   int mods ATTRIBUTE_UNUSED,
		   const struct arc_operand_value **opval ATTRIBUTE_UNUSED,
		   int *invalid)
{
  /* This misses the case where B == ARC_REG_SHIMM_UPDATE &&
     C == ARC_REG_SHIMM (or vice versa).  No big deal.  Those insns will get
     printed as "and"s.  */
  if (((*insn >> ARC_SHIFT_REGB) & ARC_MASK_REG)
      != ((*insn >> ARC_SHIFT_REGC) & ARC_MASK_REG))
    if (invalid != NULL)
      *invalid = 1;

  return 0;
}

/* ARC instructions.

   Longer versions of insns must appear before shorter ones (if gas sees
   "lsr r2,r3,1" when it's parsing "lsr %a,%b" it will think the ",1" is
   junk).  This isn't necessary for `ld' because of the trailing ']'.

   Instructions that are really macros based on other insns must appear
   before the real insn so they're chosen when disassembling.  Eg: The `mov'
   insn is really the `and' insn.

   This table is best viewed on a wide screen (161 columns).  I'd prefer to
   keep it this way.  The rest of the file, however, should be viewable on an
   80 column terminal.  */

/* ??? This table also includes macros: asl, lsl, and mov.  The ppc port has
   a more general facility for dealing with macros which could be used if
   we need to.  */

/* This table can't be `const' because members `next_asm' and `next_dis' are
   computed at run-time.  We could split this into two, but that doesn't seem
   worth it.  */

static struct arc_opcode arc_opcodes[] = {

  /* Base case instruction set (ARC4, ARC5, ARC6, ARC7).  */
  /* Macros appear first.  */

  /* "mov" is really an "and".  */
  { (unsigned char *) "mov%.q%.f %a,%b%F%S%L%U", I(-1), I(12), ARC_MACH_ARC4, 0, 0 ,0,0},
  /* "asl" is really an "add".  */
  { (unsigned char *) "asl%.q%.f %a,%b%F%S%L%U", I(-1), I(8), ARC_MACH_ARC4, 0, 0 ,0,0},
  /* "lsl" is really an "add".  */
  { (unsigned char *) "lsl%.q%.f %a,%b%F%S%L%U", I(-1), I(8), ARC_MACH_ARC4, 0, 0 ,0,0},
  /* "nop" is really an "xor".  */
  { (unsigned char *) "nop", 0xffffffff, 0x7fffffff, ARC_MACH_ARC4, 0, 0 ,0,0},
  /* "rlc" is really an "adc".  */
  { (unsigned char *) "rlc%.q%.f %a,%b%F%S%L%U", I(-1), I(9), ARC_MACH_ARC4, 0, 0 ,0,0},

  /* The rest of these needn't be sorted, but it helps to find them if they are.  */
  { (unsigned char *) "adc%.q%.f %a,%b,%c%F%S%L", I(-1), I(9), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f %a,%b,%c%F%S%L",	I(-1), I(8), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f %a,%b,%c%F%S%L",	I(-1), I(12), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(1), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f %a,%b,%c%F%S%L",	I(-1), I(14), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "b%q%.n %B", I(-1),	I(4), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "bl%q%.n %B", I(-1), I(5), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "b%.q%.n %B", I(-1),	I(4), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "bl.%q%.n %B", I(-1), I(5), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "brk", 0x1ffffe00, 0x1ffffe00, ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "extb%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(7), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "extw%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(8), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "flag%.q %b%G%S%L",	I(-1)|A(-1)|C(-1), I(3)|A(ARC_REG_SHIMM_UPDATE)|C(0), ARC_MACH_ARC4, 0, 0 ,0,0},

  /* %Q: force arc_cond_p=1 --> no shimm values */
  /* This insn allows an optional flags spec.  */
  { (unsigned char *) "j%q%Q%.n%.f %b%F%J,%j", I(-1)|A(-1)|C(-1)|R(-1,7,1), I(7)|A(0)|C(0)|R(0,7,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "j%q%Q%.n%.f %b%F%J,%j", I(-1)|A(-1)|C(-1)|R(-1,7,1), I(7)|A(0)|C(0)|R(0,7,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "j%.q%Q%.n%.f %b%F%J", I(-1)|A(-1)|C(-1)|R(-1,7,1), I(7)|A(0)|C(0)|R(0,7,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  /* This insn allows an optional flags spec.  */
  { (unsigned char *) "jl%q%Q%.n%.f %b%F%J,%j", I(-1)|A(-1)|C(-1)|R(-1,7,1)|R(-1,9,1), I(7)|A(0)|C(0)|R(0,7,1)|R(1,9,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "jl%.q%Q%.n%.f %b%F%J,%j", I(-1)|A(-1)|C(-1)|R(-1,7,1)|R(-1,9,1), I(7)|A(0)|C(0)|R(0,7,1)|R(1,9,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "jl%q%Q%.n%.f %b%F%J", I(-1)|A(-1)|C(-1)|R(-1,7,1)|R(-1,9,1), I(7)|A(0)|C(0)|R(0,7,1)|R(1,9,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  { (unsigned char *) "jl%.q%Q%.n%.f %b%F%J", I(-1)|A(-1)|C(-1)|R(-1,7,1)|R(-1,9,1), I(7)|A(0)|C(0)|R(0,7,1)|R(1,9,1), ARC_MACH_ARC4 | ARC_OPCODE_COND_BRANCH, 0, 0 ,0,0},
  /* Put opcode 1 ld insns first so shimm gets prefered over limm.  */
  /* "[%b]" is before "[%b,%o]" so 0 offsets don't get printed.  */
  { (unsigned char *) "ld%Z%.X%.W%.E %a,[%s]%S%L%1", I(-1)|R(-1,13,1)|R(-1,0,511), I(1)|R(0,13,1)|R(0,0,511), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "ld%z%.x%.w%.e %a,[%s]%S%L%1", I(-1)|R(-1,4,1)|R(-1,6,7), I(0)|R(0,4,1)|R(0,6,7), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "ld%z%.x%.w%.e %a,[%s,%O]%S%L%1", I(-1)|R(-1,4,1)|R(-1,6,7), I(0)|R(0,4,1)|R(0,6,7), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "ld%Z%.X%.W%.E %a,[%s,%O]%S%L%3", I(-1)|R(-1,13,1),	I(1)|R(0,13,1), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "lp%q%.n %B", I(-1), I(6), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "lp%.q%.n %B", I(-1), I(6), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "lr %a,[%Ab]%S%L", I(-1)|C(-1), I(1)|C(0x10), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(2), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f %a,%b,%c%F%S%L", I(-1), I(13), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(3), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(4), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sbc%.q%.f %a,%b,%c%F%S%L", I(-1), I(11), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(5), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sexw%.q%.f %a,%b%F%S%L", I(-1)|C(-1), I(3)|C(6), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sleep", 0x1ffffe01, 0x1ffffe01, ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sr %c,[%Ab]%S%L", I(-1)|A(-1), I(2)|A(0x10), ARC_MACH_ARC4, 0, 0 ,0,0},
  /* "[%b]" is before "[%b,%o]" so 0 offsets don't get printed.  */
  { (unsigned char *) "st%y%.v%.D %c,[%s]%L%S%0", I(-1)|R(-1,25,1)|R(-1,21,1), I(2)|R(0,25,1)|R(0,21,1), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "st%y%.v%.D %c,[%s,%o]%S%L%2", I(-1)|R(-1,25,1)|R(-1,21,1),	I(2)|R(0,25,1)|R(0,21,1), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f %a,%b,%c%F%S%L",	I(-1), I(10), ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "swi", 0x1ffffe02, 0x1ffffe02, ARC_MACH_ARC4, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f %a,%b,%c%F%S%L",	I(-1), I(15), ARC_MACH_ARC4, 0, 0 ,0,0},

  /* ARCompact Instruction Set */

  { (unsigned char *) "abs%.f %#,%C%F", 0xf8ff003f, 0x202f0009, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "abs%.f %#,%u%F", 0xf8ff003f, 0x206f0009, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "abs%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f89, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "abs%.f 0,%C%F", 0xffff703f, 0x262f7009, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "abs%.f 0,%u%F", 0xf8ff003f, 0x266f7009, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "abs%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f89, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "adc%.f %A,%B,%C%F", 0xf8ff0000, 0x20010000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f %A,%B,%u%F", 0xf8ff0000, 0x20410000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f %#,%B,%K%F", 0xf8ff0000, 0x20810000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f %#,%K,%B%F", 0xf8ff0000, 0x20810000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20010f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q %A,%L,%C%F", 0xffff7000, 0x26017000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q %A,%L,%u%F", 0xffff7000, 0x26417000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26017f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c10000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20c10020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c10000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f %#,%u,%B%F", 0xf8ff00f0, 0x20c10020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f%Q %#,%B,%L%F", 0xf8ff0ff0, 0x20c10f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f%Q %#,%L,%B%F", 0xf8ff0ff0, 0x20c10f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f 0,%B,%C%F", 0xf8ff00ff, 0x2001003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f 0,%B,%u%F", 0xf8ff003f, 0x2041003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20010fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q 0,%L,%C%F", 0xffff703f, 0x2601703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q 0,%L,%u%F", 0xffff703f, 0x2641703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.f%Q 0,%L,%K%F", 0xffff7000, 0x26817000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c17000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c17020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "adc%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c17f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f %A,%B,%C%F", 0xf8ff0000, 0x20000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f %A,%B,%u%F", 0xf8ff0000, 0x20400000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f %#,%B,%K%F", 0xf8ff0000, 0x20800000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q %A,%B,%[L%F", 0xf8ff0fc0, 0x20000f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20000f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q %A,%L,%C%F", 0xffff7000, 0x26007000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q %A,%L,%u%F", 0xffff7000, 0x26407000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26007f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c00000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20c00020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c00000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f %#,%u,%B%F", 0xf8ff00f0, 0x20c00020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c00f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20c00f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f 0,%B,%C%F", 0xf8ff003f, 0x2000003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f 0,%B,%u%F", 0xf8ff003f, 0x2040003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20000fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q 0,%L,%C%F", 0xffff703f, 0x2600703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q 0,%L,%u%F", 0xffff703f, 0x2640703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.f%Q 0,%L,%K%F", 0xffff7000, 0x26807000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c07000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c07020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c07f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f %A,%B,%C%F", 0xf8ff0000, 0x20140000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f %A,%B,%u%F", 0xf8ff0000, 0x20540000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f %#,%B,%K%F", 0xf8ff0000, 0x20940000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20140f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q %A,%L,%C%F", 0xffff7000, 0x26147000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q %A,%L,%u%F", 0xffff7000, 0x26547000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26147f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d40000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20d40020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f%Q %#,%B,%L%F", 0xf8ff0ff0, 0x20d40f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f 0,%B,%C%F", 0xf8ff003f, 0x2014003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f 0,%B,%u%F", 0xf8ff003f, 0x2054003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20140fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q 0,%L,%C%F", 0xffff703f, 0x2614703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q 0,%L,%u%F", 0xffff703f, 0x2654703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.f%Q 0,%L,%K%F", 0xffff7000, 0x26947000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d47000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d47020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add1%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26d47f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f %A,%B,%C%F", 0xf8ff0000, 0x20150000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f %A,%B,%u%F", 0xf8ff0000, 0x20550000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f %#,%B,%K%F", 0xf8ff0000, 0x20950000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20150f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q %A,%L,%C%F", 0xffff7000, 0x26157000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q %A,%L,%u%F", 0xffff7000, 0x26557000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26157f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d50000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20d50020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f%Q %#,%B,%L%F", 0xf8ff0ff0, 0x20d50f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f 0,%B,%C%F", 0xf8ff003f, 0x2015003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f 0,%B,%u%F", 0xf8ff003f, 0x2055003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20150fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q 0,%L,%C%F", 0xffff703f, 0x2615703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q 0,%L,%u%F", 0xffff703f, 0x2655703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.f%Q 0,%L,%K%F", 0xffff7000, 0x26957000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d57000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d57020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add2%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26d57f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f %A,%B,%C%F", 0xf8ff0000, 0x20160000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f %A,%B,%u%F", 0xf8ff0000, 0x20560000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f %#,%B,%K%F", 0xf8ff0000, 0x20960000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20160f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q %A,%L,%C%F", 0xffff7000, 0x26167000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q %A,%L,%u%F", 0xffff7000, 0x26567000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26167f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d60000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20d60020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f%Q %#,%B,%L%F", 0xf8ff0ff0, 0x20d60f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f 0,%B,%C%F", 0xf8ff003f, 0x2016003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f 0,%B,%u%F", 0xf8ff003f, 0x2056003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20160fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q 0,%L,%C%F", 0xffff703f, 0x2616703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q 0,%L,%u%F", 0xffff7000, 0x26967000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.f%Q 0,%L,%K%F", 0xffff7000, 0x26967000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d67000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d67020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "add3%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26d67f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "and%.f %A,%B,%C%F", 0xf8ff0000, 0x20040000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f %A,%B,%u%F", 0xf8ff0000, 0x20440000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f %#,%B,%K%F", 0xf8ff0000, 0x20840000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20040f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q %A,%L,%C%F", 0xffff7000, 0x26047000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q %A,%L,%u%F", 0xffff7000, 0x26447000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26047f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c40000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c40000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f %#,%B,%u%F", 0xf8ff00f0, 0x20c40020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f %#,%u,%B%F", 0xf8ff00f0, 0x20c40020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c40f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20c40f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f 0,%B,%C%F", 0xf8ff003f, 0x2004003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f 0,%B,%u%F", 0xf8ff003f, 0x2044003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20040fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q 0,%L,%C%F", 0xffff703f, 0x2604703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q 0,%L,%u%F", 0xffff703f, 0x2644703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.f%Q 0,%L,%K%F", 0xffff7000, 0x26847000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c47000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c47020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "and%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c47f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "asl%.f %A,%B,%C%F", 0xf8ff0000, 0x28000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f %A,%B,%u%F", 0xf8ff0000, 0x28400000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f %#,%B,%K%F", 0xf8ff0000, 0x28800000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x28000f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q %A,%L,%C%F", 0xffff7000, 0x2e007000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q %A,%L,%u%F", 0xffff7000, 0x2e407000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x2e007f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x28c00000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x28c00020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x28c00f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f 0,%B,%C%F", 0xf8ff003f, 0x2800003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f 0,%B,%u%F", 0xf8ff003f, 0x2840003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x28000fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q 0,%L,%C%F", 0xffff703f, 0x2e00703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q 0,%L,%u%F", 0xffff703f, 0x2e40703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q 0,%L,%K%F", 0xffff7000, 0x2e807000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x2ec07000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x2ec07020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x2ec07f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f %#,%C%F", 0xf8ff003f, 0x202f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f %#,%u%F", 0xf8ff003f, 0x206f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f 0,%C%F", 0xffff703f, 0x262f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f 0,%u%F", 0xffff703f, 0x266f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asl%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "asr%.f %A,%B,%C%F", 0xf8ff0000, 0x28020000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f %A,%B,%u%F", 0xf8ff0000, 0x28420000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f %#,%B,%K%F", 0xf8ff0000, 0x28820000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x28020f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q %A,%L,%C%F", 0xffff7000, 0x2e027000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q %A,%L,%u%F", 0xffff7000, 0x2e427000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x2e027f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x28c20000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x28c20020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x28c20f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f 0,%B,%C%F", 0xf8ff003f, 0x2802003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f 0,%B,%u%F", 0xf8ff003f, 0x2842003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x28020fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q 0,%L,%C%F", 0xffff703f, 0x2e02703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q 0,%L,%u%F", 0xffff703f, 0x2e42703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q 0,%L,%K%F", 0xffff7000, 0x2e827000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x2ec27000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x2ec27020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x2ec27f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f %#,%C%F", 0xf8ff003f, 0x202f0001, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f %#,%u%F", 0xf8ff003f, 0x206f0001, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f81, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f 0,%C%F", 0xffff703f, 0x262f7001, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f 0,%u%F", 0xffff703f, 0x266f7001, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "asr%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f81, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bbit0%.n %B,%C,%d", 0xf801001f, 0x0801000e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit0%.n %B,%u,%d", 0xf801001f, 0x0801001e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit0%Q %B,%L,%d",  0xf8010fff, 0x08010f8e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit0%Q %L,%C,%d",  0xff01703f, 0x0e01700e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit1%.n %B,%C,%d", 0xf801001f, 0x0801000f, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit1%.n %B,%u,%d", 0xf801001f, 0x0801001f, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit1%Q %B,%L,%d",  0xf8010fff, 0x08010f8f, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bbit1%Q %L,%C,%d",  0xff01703f, 0x0e01700f, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "b%.n %I", 0xf8010010, 0x00010000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "b%q%.n %i", 0xf8010000, 0x00000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "b%.q%.n %i", 0xf8010000, 0x00000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f %A,%B,%C%F", 0xf8ff0000, 0x20100000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f %A,%B,%u%F", 0xf8ff0000, 0x20500000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f %#,%B,%K%F", 0xf8ff0000, 0x20900000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20100f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q %A,%L,%C%F", 0xffff7000, 0x26107000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q %A,%L,%u%F", 0xffff7000, 0x26507000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26107f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d00000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20d00020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20d00f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f 0,%B,%C%F", 0xf8ff003f, 0x2010003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f 0,%B,%u%F", 0xf8ff003f, 0x2050003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20100fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q 0,%L,%C%F", 0xffff703f, 0x2610703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q 0,%L,%u%F", 0xffff703f, 0x2650703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.f%Q 0,%L,%K%F", 0xffff7000, 0x26907000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d07000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d07020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bclr%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x26d07f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f %A,%B,%C%F", 0xf8ff0000, 0x20060000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f %A,%B,%u%F", 0xf8ff0000, 0x20460000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f %#,%B,%K%F", 0xf8ff0000, 0x20860000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20060f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q %A,%L,%C%F", 0xffff7000, 0x26067000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q %A,%L,%u%F", 0xffff7000, 0x26467000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q %A,%L,%K%F", 0xffff7000, 0x26067000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c60000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20c60020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c60f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f 0,%B,%C%F", 0xf8ff003f, 0x2006003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f 0,%B,%u%F", 0xf8ff003f, 0x2046003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20060fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q 0,%L,%C%F", 0xffff703f, 0x2606703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q 0,%L,%u%F", 0xffff703f, 0x2646703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.f%Q 0,%L,%K%F", 0xffff7000, 0x26867000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c67000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c67020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bic%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x26c67f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bl%.n %H", 0xf8030030, 0x08020000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bl%q%.n %h", 0xf803003f, 0x08000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bl%.q%.n %h", 0xf803003f, 0x08000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f %A,%B,%C%F", 0xf8ff0000, 0x20130000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f %A,%B,%u%F", 0xf8ff0000, 0x20530000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f %#,%B,%K%F", 0xf8ff0000, 0x20930000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20130f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q %A,%L,%C%F", 0xffff7000, 0x26137000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q %A,%L,%u%F", 0xffff7000, 0x26537000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26137f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d30000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20d30020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20d30f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f 0,%B,%C%F", 0xf8ff003f, 0x2013003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f 0,%B,%u%F", 0xf8ff003f, 0x2053003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20130fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q 0,%L,%C%F", 0xffff703f, 0x2613703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q 0,%L,%u%F", 0xffff703f, 0x2653703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.f%Q 0,%L,%K%F", 0xffff7000, 0x26937000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d37000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d37020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bmsk%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x26d37f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "breq%.n %B,%C,%d", 0xf801003f, 0x08010000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "breq%.n %B,%u,%d", 0xf801003f, 0x08010010, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "breq%Q %B,%L,%d",  0xf8010fff, 0x08010f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "breq%Q %L,%C,%d",  0xff01703f, 0x0e017000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brne%.n %B,%C,%d", 0xf801003f, 0x08010001, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brne%.n %B,%u,%d", 0xf801003f, 0x08010011, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brne%Q %B,%L,%d",  0xf8010fff, 0x08010f81, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brne%Q %L,%C,%d",  0xff01703f, 0x0e017001, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  /*Pseudo mnemonics for BRcc instruction*/
  { (unsigned char *) "brgt%.n %C,%B,%d", 0xf801003f, 0x08010002, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brgt%.n %B,%u,%d", 0xf801003f, 0x08010013, (ARCOMPACT & (~ARC_MACH_ARCV2)) | ARC_INCR_U6, 0, 0 ,0,0},
  { (unsigned char *) "brgt%Q %L,%B,%d",  0xf8010fff, 0x08010f82, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brgt%Q %C,%L,%d",  0xff01703f, 0x0e017002, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "brle%.n %C,%B,%d", 0xf801003f, 0x08010003, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brle%.n %B,%u,%d", 0xf801003f, 0x08010012, (ARCOMPACT & (~ARC_MACH_ARCV2)) | ARC_INCR_U6, 0, 0 ,0,0},
  { (unsigned char *) "brle%Q %L,%B,%d",  0xf8010fff, 0x08010f83, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brle%Q %C,%L,%d",  0xff01703f, 0x0e017003, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "brhi%.n %C,%B,%d", 0xf801003f, 0x08010004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhi%.n %B,%u,%d", 0xf801003f, 0x08010015, (ARCOMPACT & (~ARC_MACH_ARCV2)) | ARC_INCR_U6, 0, 0 ,0,0},
  { (unsigned char *) "brhi%Q %L,%B,%d",  0xf8010fff, 0x08010f84, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhi%Q %C,%L,%d",  0xff01703f, 0x0e017004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},


  { (unsigned char *) "brls%.n %C,%B,%d", 0xf801003f, 0x08010005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brls%.n %B,%u,%d", 0xf801003f, 0x08010014, (ARCOMPACT & (~ARC_MACH_ARCV2)) | ARC_INCR_U6, 0, 0 ,0,0},
  { (unsigned char *) "brls%Q %L,%B,%d",  0xf8010fff, 0x08010f85, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brls%Q %C,%L,%d",  0xff01703f, 0x0e017005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "brcc%.n %B,%C,%d", 0xff01003f, 0x08010005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcc%.n %B,%u,%d", 0xff01003f, 0x08010015, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcc%Q %B,%L,%d",  0xf8010fff, 0x08010f85, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcc%Q %L,%C,%d",  0xf801003f, 0x0e017005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "brcs%.n %B,%C,%d", 0xff01003f, 0x08010004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcs%.n %B,%u,%d", 0xff01003f, 0x08010014, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcs%Q %B,%L,%d",  0xf8010fff, 0x08010f84, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brcs%Q %L,%C,%d",  0xf801003f, 0x0e017004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  /*Pseudo Mnemonics definition ends*/

  { (unsigned char *) "brlt%.n %B,%C,%d", 0xf801003f, 0x08010002, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlt%.n %B,%u,%d", 0xf801003f, 0x08010012, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlt%Q %B,%L,%d",  0xf8010fff, 0x08010f82, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlt%Q %L,%C,%d",  0xff01703f, 0x0e017002, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brk",             0xffffffff, 0x256F003F, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "brge%.n %B,%C,%d", 0xf801003f, 0x08010003, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brge%.n %B,%u,%d", 0xf801003f, 0x08010013, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brge%Q %B,%L,%d",  0xf8010fff, 0x08010f83, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brge%Q %L,%C,%d",  0xff01703f, 0x0e017003, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlo%.n %B,%C,%d", 0xf801003f, 0x08010004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlo%.n %B,%u,%d", 0xf801003f, 0x08010014, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlo%Q %B,%L,%d",  0xf8010fff, 0x08010f84, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brlo%Q %L,%C,%d",  0xff01703f, 0x0e017004, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhs%.n %B,%C,%d", 0xf801003f, 0x08010005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhs%.n %B,%u,%d", 0xf801003f, 0x08010015, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhs%Q %B,%L,%d",  0xf8010fff, 0x08010f85, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "brhs%Q %L,%C,%d",  0xff01703f, 0x0e017005, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "bset%.f %A,%B,%C%F", 0xf8ff0000, 0x200f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f %A,%B,%u%F", 0xf8ff0000, 0x204f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f %#,%B,%K%F", 0xf8ff0000, 0x208f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x200f0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q %A,%L,%C%F", 0xffff7000, 0x260f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q %A,%L,%u%F", 0xffff7000, 0x264f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x260f7f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20cf0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20cf0020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20cf0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f 0,%B,%C%F", 0xf8ff003f, 0x200f003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f 0,%B,%u%F", 0xf8ff003f, 0x204f003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x200f0fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q 0,%L,%C%F", 0xffff703f, 0x260f703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q 0,%L,%u%F", 0xffff703f, 0x264f703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.f%Q 0,%L,%K%F", 0xffff7000, 0x268f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26cf7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26cf7020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bset%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x26cf7f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst %B,%C", 0xf8ff803f, 0x20118000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst %B,%u", 0xf8ff803f, 0x20518000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst %B,%K", 0xf8ff8000, 0x20918000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%Q %B,%L", 0xf8ff8000, 0x20118f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%Q %L,%C", 0xfffff03f, 0x2611f000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%Q %L,%u", 0xfffff03f, 0x2651f000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%Q %L,%K", 0xFFFFF000, 0x2691F000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "btst%Q %L,%L", 0xffffffff, 0x2611ff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q %B,%C", 0xf8ff8020, 0x20d18000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q %B,%u", 0xf8ff8020, 0x20d18020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q%Q %B,%L", 0xf8ff8fe0, 0x20d18f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q%Q %L,%C", 0xfffff020, 0x26d1f000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q%Q %L,%u", 0xfffff020, 0x26d1f020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "btst%.q%Q %L,%L", 0xffffffe0, 0x26d1ff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f %A,%B,%C%F", 0xf8ff0000, 0x20120000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f %A,%B,%u%F", 0xf8ff0000, 0x20520000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f %#,%B,%K%F", 0xf8ff0000, 0x20920000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20120f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q %A,%L,%C%F", 0xffff7000, 0x26127000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q %A,%L,%u%F", 0xffff7000, 0x26527000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26127f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d20000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20d20000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20d20020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f %#,%u,%B%F", 0xf8ff0020, 0x20d20020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20d20f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20d20f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f 0,%B,%C%F", 0xf8ff003f, 0x2012003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f 0,%B,%u%F", 0xf8ff003f, 0x2052003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20120fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q 0,%L,%C%F", 0xffff703f, 0x2612703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q 0,%L,%u%F", 0xffff703f, 0x2652703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.f%Q 0,%L,%K%F", 0xffff7000, 0x26927000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d27000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d27020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "bxor%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x26d27f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp %B,%C", 0xf8ff803f, 0x200c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f %B,%C", 0xf8ff803f, 0x200c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp %B,%u", 0xf8ff803f, 0x204c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f %B,%u", 0xf8ff803f, 0x204c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp %B,%K", 0xf8ff8000, 0x208c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f %B,%K", 0xf8ff8000, 0x208c8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%Q %B,%L", 0xf8ff8000, 0x200c8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f%Q %B,%L", 0xf8ff8000, 0x200c8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%Q %L,%C", 0xfffff03f, 0x260cf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f%Q %L,%C", 0xfffff03f, 0x260cf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%Q %L,%u", 0xfffff03f, 0x264cf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f%Q %L,%u", 0xfffff03f, 0x264cf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%Q %L,%K", 0xFFFFF000, 0x268CF000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "cmp%Q %L,%L", 0xffffffff, 0x260cff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.f%Q %L,%L", 0xffffffff, 0x260cff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q %B,%C", 0xf8ff8020, 0x20cc8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f %B,%C", 0xf8ff8020, 0x20cc8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q %B,%u", 0xf8ff8020, 0x20cc8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f %B,%u", 0xf8ff8020, 0x20cc8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%Q %B,%L", 0xf8ff8fe0, 0x20cc8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f%Q %B,%L", 0xf8ff8fe0, 0x20cc8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%Q %L,%C", 0xfffff020, 0x26ccf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f%Q %L,%C", 0xfffff020, 0x26ccf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%Q %L,%u", 0xfffff020, 0x26ccf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f%Q %L,%u", 0xfffff020, 0x26ccf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%Q %L,%L", 0xffffffe0, 0x26ccff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "cmp%.q%.f%Q %L,%L", 0xffffffe0, 0x26ccff80, ARCOMPACT, 0, 0 ,0,0},

  /* ARC A700 extension for Atomic Exchange */
  { (unsigned char *) "ex%.V %#,[%C]%^",0xf8ff003f,0x202f000C,ARC_MACH_ARC7 | ARC_MACH_ARCV2,0,0,0,0},
  { (unsigned char *) "ex%.V %#,[%u]%^",0xf8ff003f,0x206f000C,ARC_MACH_ARC7 | ARC_MACH_ARCV2,0,0,0,0},
  { (unsigned char *) "ex%.V %#,[%L]%^",0xf8ff0fff,0x202f0f8c,ARC_MACH_ARC7 | ARC_MACH_ARCV2,0,0,0,0},

  { (unsigned char *) "extb%.f %#,%C%F", 0xf8ff003f, 0x202f0007, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extb%.f %#,%u%F", 0xf8ff003f, 0x206f0007, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extb%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f87, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extb%.f 0,%C%F", 0xffff703f, 0x262f7007, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extb%.f 0,%u%F", 0xffff703f, 0x266f7007, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extb%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f87, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "extw%.f %#,%C%F",   0xf8ff003f, 0x202f0008, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "extw%.f %#,%u%F",   0xf8ff003f, 0x206f0008, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "extw%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f88, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "extw%.f 0,%C%F",    0xffff703f, 0x262f7008, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "extw%.f 0,%u%F",    0xffff703f, 0x266f7008, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "extw%.f%Q 0,%L%F",  0xffff7fff, 0x262f7f88, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "flag %u", 0xfffff020, 0x20690000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "flag %C", 0xfffff020, 0x20290000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "flag%.q%Q %C", 0xfffff020, 0x20e90000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "flag%.q%Q %u", 0xfffff020, 0x20e90020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "flag %K", 0xfffff000, 0x20a90000, ARCOMPACT, 0, 0, 0, 0 },
  { (unsigned char *) "flag %L", 0xffffffff, 0x20290f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "flag%.q%Q %L", 0xffffffe0, 0x20e90f80, ARCOMPACT, 0, 0, 0, 0 },

  { (unsigned char *) "j%.N [%C]",    0xfffef03f, 0x20200000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.N %u",      0xfffef03f, 0x20600000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.N %K",      0xfffef000, 0x20a00000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%Q %L",       0xffffffff, 0x20200f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.f [%7]",    0xffffffff, 0x20208740, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.f [%8]",    0xffffffff, 0x20208780, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%q%.N [%C]",  0xfffef020, 0x20e00000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%q%.N %u",    0xfffef020, 0x20e00020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%q%Q %L",     0xffffffe0, 0x20e00f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%q%.f [%7]",  0xffffffe0, 0x20e08740, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%q%.f [%8]",  0xffffffe0, 0x20e08780, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.q%.N [%C]", 0xfffef020, 0x20e00000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.q%.N %u",   0xfffef020, 0x20e00020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.q%Q %L",    0xffffffe0, 0x20e00f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.q%.f [%7]", 0xffffffe0, 0x20e08740, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "j%.q%.f [%8]", 0xffffffe0, 0x20e08780, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.N [%C]",    0xfffef03f, 0x20220000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.N %u",      0xfffef03f, 0x20620000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.N %K",      0xfffef000, 0x20a20000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%Q %L",       0xffffffff, 0x20220f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%q%.N [%C]",  0xfffef020, 0x20e20000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%q%.N %u",    0xfffef020, 0x20e20020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%q%Q %L",     0xffffffe0, 0x20e20f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.q%.N [%C]", 0xfffef020, 0x20e20000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.q%.N %u",   0xfffef020, 0x20e20020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "jl%.q%Q %L",    0xffffffe0, 0x20e20f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  /* Prefetch equivalent with ld<.aa> 0,[b,s9] / [b,limm] / [limm]
     / [b,c] / [limm,c]
     This is valid only in the A700
  */

  { (unsigned char *) "ld%.p 0,[%g,%o]%3",    0xf80009ff, 0x1000003e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "prefetch%.p [%g,%o]%3",0xf80009ff, 0x1000003e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "pf%.p [%g,%o]%3",      0xf80009ff, 0x1000003e, ARC_MACH_ARC7, 0, 0 ,0,0},

  { (unsigned char *) "ld 0,[%L]%3",     0xff0079ff, 0x1600703e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "prefetch [%L]%3", 0xff0079ff, 0x1600703e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "pf [%L]%3",       0xff0079ff, 0x1600703e, ARC_MACH_ARC7, 0, 0 ,0,0},


  { (unsigned char *) "ld%.P 0,[%g,%C]%1",     0xf83f803f, 0x2030003e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "prefetch%.p [%g,%C]%1", 0xf83f803f, 0x2030003e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "pf%.P [%g,%C]%1",       0xf83f803f, 0x2030003e, ARC_MACH_ARC7, 0, 0 ,0,0},


  { (unsigned char *) "ld%.P 0,[%g,%L]%1",     0xf83f8fff, 0x20300fbe, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "prefetch%.p [%g,%L]%1", 0xf83f8fff, 0x20300fbe, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "pf%.P [%g,%L]%1",       0xf83f8fff, 0x20300fbe, ARC_MACH_ARC7, 0, 0 ,0,0},

  { (unsigned char *) "ld 0,[%L,%C]%1",     0xff3ff03f, 0x2630703e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "prefetch [%L,%C]%1", 0xff3ff03f, 0x2630703e, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "pf [%L,%C]%1",       0xff3ff03f, 0x2630703e, ARC_MACH_ARC7, 0, 0 ,0,0},

  /*PREFETCH */
  /* prefetch<.aa>    [b,c] 	0010 0bbb aa11 0000 0BBB CCCC CC11 1110  */
  { (unsigned char *) "prefetch%.P [%g,%C]%3",                   0xF83F803F, 0x2030003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [b,s9] 	0001 0bbb ssss ssss SBBB 0aa0 0011 1110  */
  { (unsigned char *) "prefetch%.p [%g,%o]%3",                   0xF80009FF, 0x1000003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [b,limm] 	0010 0bbb aa11 0000 0BBB 1111 1011 1110  */
  { (unsigned char *) "prefetch%.P%Q [%g,%L]%3",                 0xF83F8FFF, 0x20300FBE, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [limm,c] 	0010 0110 aa11 0000 0111 CCCC CC11 1110  */
  { (unsigned char *) "prefetch%.P%Q [%L,%C]%1",                 0xFF3FF03F, 0x2630703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [limm,s9] 	0001 0110 ssss ssss S111 0aa0 0011 1110  */
  { (unsigned char *) "prefetch%.p%Q [%L,%o]%1",                 0xFF0079FF, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [b] 	0001 0bbb 0000 0000 0BBB 0aa0 0011 1110  */
  { (unsigned char *) "prefetch%.p [%g]%3",                      0xF8FF89FF, 0x1000003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* prefetch<.aa>    [limm] 	0001 0110 0000 0000 0111 0aa0 0011 1110  */
  { (unsigned char *) "prefetch%.p%Q [%[L]%1",                    0xFFFFF9FF, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  { (unsigned char *) "prefetch%.p%Q [%L]%1",                    0xFFFFF9FF, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /*LD 0 */
  /* ld<.aa><.di><.x><.ZZ>    0,[b,c] 	0010 0bbb aa11 0ZZX DBBB CCCC CC11 1110  */
  { (unsigned char *) "ld%T%.X%.P%.V 0,[%g,%C]%3",             0xF838003F, 0x2030003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.aa><.di><.x><.ZZ>    0,[b,s9] 	0001 0bbb ssss ssss SBBB DaaZ ZX11 1110  */
  { (unsigned char *) "ld%t%.x%.p%.v 0,[%g,%o]%1",             0xF800003F, 0x1000003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  { (unsigned char *) "ld%t%.x%.p%.v 0,[%g]%1",                0xF800003F, 0x1000003E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.aa><.di><.x><.ZZ>    0,[b,limm] 	0010 0bbb aa11 0ZZX DBBB 1111 1011 1110  */
  { (unsigned char *) "ld%T%.X%.P%.V%Q 0,[%g,%L]%3",           0xF8380FFF, 0x20300FBE, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.aa><.di><.x><.ZZ>    0,[limm,c] 	0010 0110 aa11 0ZZX D111 CCCC CC11 1110  */
  { (unsigned char *) "ld%T%.X%.P%.V%Q 0,[%L,%C]%3",           0xFF38703F, 0x2630703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.di><.x><.ZZ>    0,[limm,c] 	0010 0110 RR11 0ZZX D111 CCCC CC11 1110  */
  { (unsigned char *) "ld%T%.X%.V%Q 0,[%L,%C]%3",              0xFFF8703F, 0x2630703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.aa><.di><.x><.ZZ>    0,[limm,s9] 	0001 0110 ssss ssss S111 DaaZ ZX11 1110  */
  { (unsigned char *) "ld%t%.x%.p%.v%Q 0,[%L,%o]%3",           0xFF00703F, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.aa><.di><.x><.ZZ>    0,[limm,limm] 	0010 0110 aa11 0ZZX D111 1111 1011 1110  */
  { (unsigned char *) "ld%T%.X%.P%.V%Q 0,[%L,%L]%3",           0xFF387FFF, 0x26307FBE, ARC_MACH_ARCV2, 0, 0, 0, 0},
  /* ld<.di><.x><.ZZ>    0,[limm 	0001 0110 0000 0000 0111 DRRZ ZX11 1110  */
  { (unsigned char *) "ld%t%.x%.v%Q 0,[%[L]%3",                 0xFFFFF63F, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},
  { (unsigned char *) "ld%t%.x%.v%Q 0,[%L]%3",                 0xFFFFF63F, 0x1600703E, ARC_MACH_ARCV2, 0, 0, 0, 0},

  /* load instruction opcodes */
  { (unsigned char *) "ld%T%.X%.P%.V %A,[%g,%C]%1",   0xf8380000, 0x20300000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.P%.X%.V %A,[%g,%C]%1",   0xf8380000, 0x20300000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.x%.p%.v %A,[%g]%1",      0xf8ff8000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.p%.x%.v %A,[%g]%1",      0xf8ff8000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.x%.p%.v %A,[%g,%o]%1",   0xf8000000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.p%.x%.v %A,[%g,%o]%1",   0xf8000000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.x%.p%.v %A,[%g,%[L]%1",  0xf8000000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.p%.x%.v %A,[%g,%[L]%1",  0xf8000000, 0x10000000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.X%.P%.V%Q %A,[%g,%L]%1", 0xf8380fc0, 0x20300f80, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.P%.X%.V%Q %A,[%g,%L]%1", 0xf8380fc0, 0x20300f80, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.X%.&%.V%Q %A,[%L,%C]%1", 0xfff87000, 0x26307000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.&%.X%.V%Q %A,[%L,%C]%1", 0xfff87000, 0x26307000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.x%.v%Q %A,[%L,%o]%1",    0xfff87000, 0x16007000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.v%.x%Q %A,[%L,%o]%1",    0xfff87000, 0x16007000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.X%.V%Q %A,[%L,%L]%1",    0xfff87fc0, 0x26307f80, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%T%.V%.X%Q %A,[%L,%L]%1",    0xfff87fc0, 0x26307f80, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.x%.v%Q %A,[%L]%3",       0xfffff600, 0x16007000, ARCOMPACT , 0, 0 ,0,0},
  { (unsigned char *) "ld%t%.v%.x%Q %A,[%L]%3",       0xfffff600, 0x16007000, ARCOMPACT , 0, 0 ,0,0},



  { (unsigned char *) "lp %Y",    0xfffff000, 0x20a80000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "lp%q %y",  0xfffff020, 0x20e80020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "lp%.q %y", 0xfffff020, 0x20e80020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "lr %#,[%C]",   0xf8ff803f, 0x202a0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "lr %#,[%GC]",  0xf8ff8000, 0x20aa0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "lr %#,[%K]",   0xf8ff8000, 0x20aa0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "lr%Q %#,[%L]", 0xf8ff8fff, 0x202a0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "lsl%.f %A,%B,%C%F", 0xf8ff0000, 0x28000000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f %A,%B,%u%F", 0xf8ff0000, 0x28400000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f %#,%B,%K%F", 0xf8ff0000, 0x28800000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x28000f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q %A,%L,%C%F", 0xffff7000, 0x2e007000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q %A,%L,%u%F", 0xffff7000, 0x2e407000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x2e007f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x28c00000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x28c00020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x28c00f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f 0,%B,%C%F", 0xf8ff003f, 0x2800003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f 0,%B,%u%F", 0xf8ff003f, 0x2840003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x28000fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q 0,%L,%C%F", 0xffff703f, 0x2e00703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q 0,%L,%K%F", 0xffff003f, 0x2e807000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q 0,%L,%u%F", 0xffff703f, 0x2e40703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x2ec07000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x2ec07020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.q%.f%Q 0,%L,%u%F", 0xffff7fe0, 0x2ec07f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f %#,%C%F", 0xf8ff003f, 0x202f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f %#,%u%F", 0xf8ff003f, 0x206f0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f 0,%C%F", 0xffff703f, 0x262f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f 0,%u%F", 0xffff703f, 0x266f7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsl%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "lsr%.f %A,%B,%C%F", 0xf8ff0000, 0x28010000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f %A,%B,%u%F", 0xf8ff0000, 0x28410000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f %#,%B,%K%F", 0xf8ff0000, 0x28810000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x28010f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q %A,%L,%C%F", 0xffff7000, 0x2e017000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q %A,%L,%u%F", 0xffff7000, 0x2e417000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x2e017f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x28c10000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x28c10020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x28c10f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f 0,%B,%C%F", 0xf8ff003f, 0x2801003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f 0,%B,%u%F", 0xf8ff003f, 0x2841003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x28010fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q 0,%L,%C%F", 0xffff703f, 0x2e01703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q 0,%L,%u%F", 0xffff703f, 0x2e41703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q 0,%L,%K%F", 0xffff003f, 0x2e817000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x2ec17000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x2ec17020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.q%.f%Q 0,%L,%L%F", 0xffff7fe0, 0x2ec17f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f %#,%C%F", 0xf8ff003f, 0x202f0002, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f %#,%u%F", 0xf8ff003f, 0x206f0002, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f82, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f 0,%C%F", 0xffff703f, 0x262f7002, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f 0,%u%F", 0xffff703f, 0x266f7002, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "lsr%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f82, ARCOMPACT, 0, 0 ,0,0},
  /*MAX */
  { (unsigned char *) "max%.f %A,%B,%C%F",      0xF8FF0000, 0x20080000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f %A,%B,%u%F",      0xF8FF0000, 0x20480000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f %#,%B,%K%F",      0xF8FF0000, 0x20880000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q %A,%B,%L%F",    0xF8FF0FC0, 0x20080F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q %A,%L,%C%F",    0xFFFF7000, 0x26087000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q %A,%L,%u%F",    0xFFFF7000, 0x26487000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q %A,%L,%L%F",    0xFFFF7FC0, 0x26087F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f %#,%B,%C%F",   0xF8FF0020, 0x20C80000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f %#,%B,%u%F",   0xF8FF0020, 0x20C80020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f%Q %#,%B,%L%F", 0xF8FF0FE0, 0x20C80F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f 0,%B,%C%F",       0xF8FF003F, 0x2008003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f 0,%B,%u%F",       0xF8FF003F, 0x2048003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q 0,%B,%L%F",     0xF8FF0FFF, 0x20080FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q 0,%L,%C%F",     0xFFFF703F, 0x2608703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q 0,%L,%u%F",     0xFFFF703F, 0x2648703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q 0,%L,%K%F",     0xFFFF7000, 0x26887000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.f%Q 0,%L,%L%F",     0xFFFF7FFF, 0x26087FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f%Q 0,%L,%C%F",  0xFFFF7020, 0x26C87000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f%Q 0,%L,%u%F",  0xFFFF7020, 0x26C87020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "max%.q%.f%Q 0,%L,%L%F",  0xFFFF7FE0, 0x26C87F80, ARCOMPACT, 0, 0, 0, 0},
/*MIN */
  { (unsigned char *) "min%.f %A,%B,%C%F",      0xF8FF0000, 0x20090000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f %A,%B,%u%F",      0xF8FF0000, 0x20490000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f %#,%B,%K%F",      0xF8FF0000, 0x20890000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q %A,%B,%L%F",    0xF8FF0FC0, 0x20090F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q %A,%L,%C%F",    0xFFFF7000, 0x26097000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q %A,%L,%u%F",    0xFFFF7000, 0x26497000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q %A,%L,%L%F",    0xFFFF7FC0, 0x26097F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f %#,%B,%C%F",   0xF8FF0020, 0x20C90000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f %#,%B,%u%F",   0xF8FF0020, 0x20C90020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f%Q %#,%B,%L%F", 0xF8FF0FE0, 0x20C90F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f 0,%B,%C%F",       0xF8FF003F, 0x2009003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f 0,%B,%u%F",       0xF8FF003F, 0x2049003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q 0,%B,%L%F",     0xF8FF0FFF, 0x20090FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q 0,%L,%C%F",     0xFFFF703F, 0x2609703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q 0,%L,%u%F",     0xFFFF703F, 0x2649703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q 0,%L,%K%F",     0xFFFF7000, 0x26897000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.f%Q 0,%L,%L%F",     0xFFFF7FFF, 0x26097FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f%Q 0,%L,%C%F",  0xFFFF7020, 0x26C97000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f%Q 0,%L,%u%F",  0xFFFF7020, 0x26C97020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "min%.q%.f%Q 0,%L,%L%F",  0xFFFF7FE0, 0x26C97F80, ARCOMPACT, 0, 0, 0, 0},

  { (unsigned char *) "mov%.f %#,%C%F", 0xf8ff003f, 0x200A0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f %#,%u%F", 0xf8ff003f, 0x204a0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f %#,%K%F", 0xf8ff0000, 0x208a0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f%Q %#,%L%F", 0xf8ff0fff, 0x200a0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f %#,%C%F", 0xf8ff0020, 0x20ca0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f %#,%u%F", 0xf8ff0020, 0x20ca0020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f%Q %#,%L%F", 0xf8ff0fe0, 0x20ca0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f 0,%C%F", 0xffff703f, 0x260a7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f 0,%u%F", 0xffff703f, 0x264a7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f 0,%K%F", 0xffff7000, 0x268a7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.f%Q 0,%L%F", 0xffff7fff, 0x260a7f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f 0,%C%F", 0xffff7020, 0x26ca7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f 0,%u%F", 0xffff7020, 0x26ca7020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "mov%.q%.f%Q 0,%L%F", 0xffff7fe0, 0x26ca7f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "neg%.f %A,%B%F", 0xf8ff0000, 0x204e0000, ARCOMPACT, 0, 0 ,0, 0},
  { (unsigned char *) "neg%.f 0,%B%F",  0xF8FF0FFF, 0x204E003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "neg%.q%.f %#,%B%F", 0xf8ff0020, 0x20ce0020, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "norm%.f %#,%C%F", 0xf8ff003f, 0x282f0001, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "norm%.f %#,%u%F", 0xf8ff003f, 0x286f0001, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "norm%.f%Q %#,%L%F", 0xf8ff0fff, 0x282f0f81, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "norm%.f 0,%C%F", 0xffff703f, 0x2e2f7001, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "norm%.f 0,%u%F", 0xffff703f, 0x2e6f7001, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "norm%.f%Q 0,%L%F", 0xffff7fff, 0x2e2f7f81, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f %#,%C%F", 0xf8ff003f, 0x282f0008, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f %#,%u%F", 0xf8ff003f, 0x286f0008, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f%Q %#,%L%F", 0xf8ff0fff, 0x282f0f88, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f 0,%C%F", 0xffff703f, 0x2e2f7008, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f 0,%u%F", 0xffff703f, 0x2e6f7008, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "normw%.f%Q 0,%L%F", 0xffff7fff, 0x2e2f7f88, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "not%.f %#,%C%F", 0xf8ff003f, 0x202f000a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "not%.f %#,%u%F", 0xf8ff003f, 0x206f000a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "not%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f8a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "not%.f 0,%C%F", 0xffff703f, 0x262f700a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "not%.f 0,%u%F", 0xffff703f, 0x266f700a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "not%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f8a, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f %A,%B,%C%F", 0xf8ff0000, 0x20050000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f %A,%B,%u%F", 0xf8ff0000, 0x20450000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f %#,%B,%K%F", 0xf8ff0000, 0x20850000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20050f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q %A,%L,%C%F", 0xffff7000, 0x26057000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q %A,%L,%u%F", 0xffff7000, 0x26457000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26057f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c50000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c50000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20c50020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f %#,%u,%B%F", 0xf8ff0020, 0x20c50020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c50f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20c50f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f 0,%B,%C%F", 0xf8ff003f, 0x2005003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f 0,%B,%u%F", 0xf8ff003f, 0x2045003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q 0,%B,%L%F", 0xf8ff8fff, 0x20050fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q 0,%L,%C%F", 0xffff703f, 0x2605703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q 0,%L,%u%F", 0xffff703f, 0x2645703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.f%Q 0,%L,%K%F", 0xffff7fff, 0x26857000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c57000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c57020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "or%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c57f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp %B,%C", 0xf8ff803f, 0x200d8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp %B,%u", 0xf8ff803f, 0x204d8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp %B,%K", 0xf8ff8000, 0x208d8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%Q %B,%L", 0xf8ff8000, 0x200d8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%Q %L,%C", 0xfffff03f, 0x260df000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%Q %L,%u", 0xfffff03f, 0x264df000, ARCOMPACT, 0, 0 ,0,0},
#ifndef ARC_NPS_CMDS
  { (unsigned char *) "rcmp%Q %L,%K", 0xfffff000, 0x268df000, ARCOMPACT, 0, 0 ,0,0},
#endif // #ifndef ARC_NPS_CMDS
  { (unsigned char *) "rcmp%.q %B,%C", 0xf8ff8020, 0x20cd8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q %B,%u", 0xf8ff8020, 0x20cd8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f %B,%C", 0xf8ff8020, 0x20cd8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f %B,%u", 0xf8ff8020, 0x20cd8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%Q %B,%L", 0xf8ff8fe0, 0x20cd8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%Q %L,%C", 0xfffff020, 0x26cdf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%Q %L,%u", 0xfffff020, 0x26cdf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%Q %L,%L", 0xffffffff, 0x26cdff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f%Q %B,%L", 0xf8ff8fe0, 0x20cd8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f%Q %L,%C", 0xfffff020, 0x26cdf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f%Q %L,%u", 0xfffff020, 0x26cdf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rcmp%.q%.f%Q %L,%L", 0xffffffff, 0x268df780, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "rlc%.f %#,%C%F", 0xf8ff003f, 0x202f000b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rlc%.f %#,%u%F", 0xf8ff003f, 0x206f000b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rlc%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f8b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rlc%.f 0,%C%F", 0xffff703f, 0x262f700b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rlc%.f 0,%u%F", 0xffff703f, 0x266f700b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rlc%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f8b, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f %A,%B,%C%F", 0xf8ff0000, 0x28030000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f %A,%B,%u%F", 0xf8ff0000, 0x28430000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f %#,%B,%K%F", 0xf8ff0000, 0x28830000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x28030f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q %A,%L,%C%F", 0xffff7000, 0x2e037000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q %A,%L,%u%F", 0xffff7000, 0x2e437000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x2e037f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x28c30000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x28c30020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x28c30f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f 0,%B,%C%F", 0xf8ff003f, 0x2803003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f 0,%B,%u%F", 0xf8ff003f, 0x2843003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x28030fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q 0,%L,%C%F", 0xffff703f, 0x2e03703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q 0,%L,%u%F", 0xffff703f, 0x2e43703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q 0,%L,%K%F", 0xffff0000, 0x2e837000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x2ec37000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x2ec37020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x2ec37f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f %#,%C%F", 0xf8ff003f, 0x202f0003, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f %#,%u%F", 0xf8ff003f, 0x206f0003, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f83, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f 0,%C%F", 0xffff703f, 0x262f7003, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f 0,%u%F", 0xffff703f, 0x266f7003, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ror%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f83, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f %#,%C%F", 0xf8ff003f, 0x202f0004, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f %#,%u%F", 0xf8ff003f, 0x206f0004, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f84, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f 0,%C%F", 0xffff703f, 0x262f7004, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f 0,%u%F", 0xffff703f, 0x266f7004, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rrc%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f84, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f %A,%B,%C%F", 0xf8ff0000, 0x200e0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f %A,%B,%u%F", 0xf8ff0000, 0x204e0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f %#,%B,%K%F", 0xf8ff0000, 0x208e0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x200e0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q %A,%B,%[L%F", 0xf8ff0fc0, 0x200e0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q %A,%L,%C%F", 0xffff7000, 0x260e7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q %A,%L,%u%F", 0xffff7000, 0x264e7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q %A,%L,%L%F", 0xffff7000, 0x260e7f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20ce0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20ce0020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20ce0f80, ARCOMPACT, 0, 0 ,0,0},
/* commute sub to do the following three operations */
  { (unsigned char *) "rsub%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c20000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f %#,%u,%B%F", 0xf8ff0020, 0x20c20020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20c20f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f 0,%B,%C%F", 0xf8ff003f, 0x200e003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f 0,%B,%u%F", 0xf8ff003f, 0x204e003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x200e0fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q 0,%L,%C%F", 0xffff703f, 0x260e703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q 0,%L,%u%F", 0xffff703f, 0x264e703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.f%Q 0,%L,%K%F", 0xffff7000, 0x268e7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26ce7000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26ce7020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "rsub%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26ce7f80, ARCOMPACT, 0, 0 ,0,0},

  /* Return from Interrupt or Exception  .New A700 instruction */
  { (unsigned char *) "rtie",0xffffffff,0x242F003F,ARC_MACH_ARC7,0,0,0,0},
  
  /*SBC */
  { (unsigned char *) "sbc%.f %A,%B,%C%F",      0xF8FF0000, 0x20030000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f %A,%B,%u%F",      0xF8FF0000, 0x20430000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f %#,%B,%K%F",      0xF8FF0000, 0x20830000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q %A,%B,%L%F",    0xF8FF0FC0, 0x20030F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q %A,%L,%C%F",    0xFFFF7000, 0x26037000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q %A,%L,%u%F",    0xFFFF7000, 0x26437000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q %A,%L,%L%F",    0xFFFF7FC0, 0x26037F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f %#,%B,%C%F",   0xF8FF0020, 0x20C30000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f %#,%B,%u%F",   0xF8FF0020, 0x20C30020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f%Q %#,%B,%L%F", 0xF8FF0FE0, 0x20C30F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f 0,%B,%C%F",       0xF8FF003F, 0x2003003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f 0,%B,%u%F",       0xF8FF003F, 0x2043003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q 0,%B,%L%F",     0xF8FF0FFF, 0x20030FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q 0,%L,%C%F",     0xFFFF703F, 0x2603703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q 0,%L,%u%F",     0xFFFF703F, 0x2643703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q 0,%L,%K%F",     0xFFFF7000, 0x26837000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.f%Q 0,%L,%L%F",     0xFFFF7FFF, 0x26037FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f%Q 0,%L,%C%F",  0xFFFF7020, 0x26C37000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f%Q 0,%L,%u%F",  0xFFFF7020, 0x26C37020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sbc%.q%.f%Q 0,%L,%L%F",  0xFFFF7FE0, 0x26C37F80, ARCOMPACT, 0, 0, 0, 0},

  { (unsigned char *) "sexb%.f %#,%C%F", 0xf8ff003f, 0x202f0005, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.f %#,%u%F", 0xf8ff003f, 0x206f0005, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f85, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.f 0,%C%F", 0xffff703f, 0x262f7005, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.f 0,%u%F", 0xffff703f, 0x266f7005, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexb%.f%Q 0,%L%F", 0xffff7fff, 0x262f7f85, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f %#,%C%F",   0xf8ff003f, 0x202f0006, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f %#,%u%F",   0xf8ff003f, 0x206f0006, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f%Q %#,%L%F", 0xf8ff0fff, 0x202f0f86, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f 0,%C%F",    0xffff703f, 0x262f7006, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f 0,%u%F",    0xffff703f, 0x266f7006, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sexw%.f%Q 0,%L%F",  0xffff7fff, 0x262f7f86, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  /* ARC700 sleep instruction */
  { (unsigned char *) "sleep %u", 0xfffff03f, 0x216f003f, ARC_MACH_ARC7, 0, 0,0,0},
  { (unsigned char *) "sleep %C", 0xfffff03f, 0x212f003f, ARC_MACH_ARC5 | ARC_MACH_ARC6 | ARC_MACH_ARC601, 0, 0 ,0,0},
  { (unsigned char *) "sleep %u", 0xfffff03f, 0x216f003f, ARC_MACH_ARC5 | ARC_MACH_ARC6 | ARC_MACH_ARC601, 0, 0 ,0,0},
  { (unsigned char *) "sleep %L", 0xffffffff, 0x212f0fbf, ARC_MACH_ARC5 | ARC_MACH_ARC6 | ARC_MACH_ARC601, 0, 0 ,0,0},
  { (unsigned char *) "sleep", 0xffffffff, 0x216f003f, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

  { (unsigned char *) "sr %B,[%C]",    0xf8ff803f, 0x202b0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr %B,[%u]",    0xf8ff8000, 0x206b0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr %B,[%K]",    0xf8ff8000, 0x20ab0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr %B,[%GC]",   0xf8ff8000, 0x20ab0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr%Q %B,[%L]",  0xf8ff8fff, 0x202b0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr%Q %L,[%C]",  0xfffff03f, 0x262b7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr%Q %L,[%u]",  0xfffff000, 0x266b7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr%Q %L,[%K]",  0xfffff000, 0x26ab7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sr%Q %L,[%GC]", 0xfffff000, 0x26ab7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.w%.D %C,[%g]%0",      0xf8ff8001, 0x18000000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.w%.D %C,[%g,%[L]%0",  0xf8000001, 0x18000000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.w%.D %C,[%g,%o]%0",   0xf8000001, 0x18000000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.D%Q %C,[%L,%o]%0",    0xff007001, 0x1e007000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.D%Q %C,[%L]%0",       0xfffff001, 0x1e007000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.w%.D%Q %L,[%g]%0",    0xf8ff8fc1, 0x18000f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.w%.D%Q %L,[%g,%o]%0", 0xf8000fc1, 0x18000f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.D%Q %L,[%L,%o]%0",    0xff007fc1, 0x1e007f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "st%z%.D%Q %L,[%L]%0",       0xff007fc1, 0x1e007f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "sub%.f %A,%B,%C%F", 0xf8ff0000, 0x20020000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f %A,%B,%u%F", 0xf8ff0000, 0x20420000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f %#,%B,%K%F", 0xf8ff0000, 0x20820000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20020f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q %A,%L,%C%F", 0xffff7000, 0x26027000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q %A,%L,%u%F", 0xffff7000, 0x26427000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q %A,%L,%L%F", 0xffff7000, 0x26027f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c20000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20c20020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c20f80, ARCOMPACT, 0, 0 ,0,0},
/* commute rsub to do the following three operations */
  { (unsigned char *) "sub%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20ce0000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f %#,%u,%B%F", 0xf8ff0020, 0x20ce0020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20ce0f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f 0,%B,%C%F", 0xf8ff003f, 0x2002003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f 0,%B,%u%F", 0xf8ff003f, 0x2042003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20020fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q 0,%L,%C%F", 0xffff703f, 0x2602703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q 0,%L,%u%F", 0xffff703f, 0x2642703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.f%Q 0,%L,%K%F", 0xffff7fff, 0x26827000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c27000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c27020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c27f80, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "sub1%.f %A,%B,%C%F", 0xf8ff0000, 0x20170000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f %A,%B,%u%F", 0xf8ff0000, 0x20570000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f %#,%B,%K%F", 0xf8ff0000, 0x20970000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20170f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q %A,%L,%C%F", 0xffff7000, 0x26177000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q %A,%L,%u%F", 0xffff7000, 0x26577000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20d70000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20d70020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20d70f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f 0,%B,%C%F", 0xf8ff003f, 0x2017003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f 0,%B,%u%F", 0xf8ff003f, 0x2057003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20170fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q 0,%L,%C%F", 0xffff703f, 0x2617703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q 0,%L,%u%F", 0xffff703f, 0x2657703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.f%Q 0,%L,%K%F", 0xffff7fff, 0x26977000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26d77000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26d77020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "sub1%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26d77f80, ARCOMPACT, 0, 0 ,0,0},
/*SUB2 */
  { (unsigned char *) "sub2%.f %A,%B,%C%F",      0xF8FF0000, 0x20180000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f %A,%B,%u%F",      0xF8FF0000, 0x20580000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f %#,%B,%K%F",      0xF8FF0000, 0x20980000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q %A,%B,%L%F",    0xF8FF0FC0, 0x20180F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q %A,%L,%C%F",    0xFFFF7000, 0x26187000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q %A,%L,%u%F",    0xFFFF7000, 0x26587000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q %A,%L,%L%F",    0xFFFF7FC0, 0x26187F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f %#,%B,%C%F",   0xF8FF0020, 0x20D80000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f %#,%B,%u%F",   0xF8FF0020, 0x20D80020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f%Q %#,%B,%L%F", 0xF8FF0FE0, 0x20D80F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f 0,%B,%C%F",       0xF8FF003F, 0x2018003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f 0,%B,%u%F",       0xF8FF003F, 0x2058003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q 0,%B,%L%F",     0xF8FF0FFF, 0x20180FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q 0,%L,%C%F",     0xFFFF703F, 0x2618703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q 0,%L,%u%F",     0xFFFF703F, 0x2658703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q 0,%L,%K%F",     0xFFFF7000, 0x26987000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.f%Q 0,%L,%L%F",     0xFFFF7FFF, 0x26187FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f%Q 0,%L,%C%F",  0xFFFF7020, 0x26D87000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f%Q 0,%L,%u%F",  0xFFFF7020, 0x26D87020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub2%.q%.f%Q 0,%L,%L%F",  0xFFFF7FE0, 0x26D87F80, ARCOMPACT, 0, 0, 0, 0},
/*SUB3 */
  { (unsigned char *) "sub3%.f %A,%B,%C%F",      0xF8FF0000, 0x20190000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f %A,%B,%u%F",      0xF8FF0000, 0x20590000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f %#,%B,%K%F",      0xF8FF0000, 0x20990000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f 0,%B,%C%F",       0xF8FF003F, 0x2019003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f 0,%B,%u%F",       0xF8FF003F, 0x2059003E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q %A,%B,%L%F",    0xF8FF0FC0, 0x20190F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q %A,%L,%C%F",    0xFFFF7000, 0x26197000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q %A,%L,%u%F",    0xFFFF7000, 0x26597000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q %A,%L,%L%F",    0xFFFF7FC0, 0x26197F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q 0,%L,%C%F",     0xFFFF703F, 0x2619703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q 0,%L,%u%F",     0xFFFF703F, 0x2659703E, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q 0,%L,%K%F",     0xFFFF7000, 0x26997000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q 0,%L,%L%F",     0xFFFF7FFF, 0x26197FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.f%Q 0,%B,%L%F",     0xF8FF0FFF, 0x20190FBE, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f %#,%B,%C%F",   0xF8FF0020, 0x20D90000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f %#,%B,%u%F",   0xF8FF0020, 0x20D90020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f%Q %#,%B,%L%F", 0xF8FF0FE0, 0x20D90F80, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f%Q 0,%L,%C%F",  0xFFFF7020, 0x26D97000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f%Q 0,%L,%u%F",  0xFFFF7020, 0x26D97020, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "sub3%.q%.f%Q 0,%L,%L%F",  0xFFFF7FE0, 0x26D97F80, ARCOMPACT, 0, 0, 0, 0},

  { (unsigned char *) "swap%.f %#,%C%F", 0xf8ff003f, 0x282f0000, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swap%.f %#,%u%F", 0xf8ff003f, 0x286f0000, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swap%.f%Q %#,%L%F", 0xf8ff0fff, 0x282f0f80, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swap%.f 0,%C%F", 0xffff703f, 0x2e2f7000, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swap%.f 0,%u%F", 0xffff703f, 0x2e6f7000, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swap%.f%Q 0,%L%F", 0xffff7fff, 0x2e2f7f80, ARC_MACH_ARC7, 0, 0 ,0,0},
  { (unsigned char *) "swi", 0xffffffff, 0x226f003f, (ARC_MACH_ARC5 | ARC_MACH_ARC6 | ARC_MACH_ARC601), 0, 0 ,0,0},

  /* New A700 Instructions */
#ifdef ARC_NPS_CMDS
/* sync.wr*/
  { (unsigned char *) "sync.wr", 0xffffffff, 0x396f003f, ARCOMPACT, 0, 0 ,0,0},
/* sync.rd*/
  { (unsigned char *) "sync.rd", 0xffffffff, 0x386f003f, ARCOMPACT, 0, 0 ,0,0},
#endif // #ifdef ARC_NPS_CMDS
  { (unsigned char *) "sync",  0xffffffff, 0x236f003f,ARC_MACH_ARC7 | ARC_MACH_ARCV2,0,0,0,0},
  { (unsigned char *) "trap0", 0xffffffff, 0x226f003f, ARC_MACH_ARC7, 0, 0 ,0,0},

  { (unsigned char *) "tst %B,%C%F", 0xf8ff803f, 0x200b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f %B,%C%F", 0xf8ff803f, 0x200b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst %B,%u%F", 0xf8ff803f, 0x204b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f %B,%u%F", 0xf8ff803f, 0x204b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst %B,%K%F", 0xf8ff8000, 0x208b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f %B,%K%F", 0xf8ff8000, 0x208b8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst %B,%L%F", 0xf8ff8fff, 0x200b8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f %B,%L%F", 0xf8ff8fff, 0x200b8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%Q %L,%C", 0xfffff03f, 0x260bf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f%Q %L,%C", 0xfffff03f, 0x260bf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%Q %L,%u", 0xfffff03f, 0x264bf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f%Q %L,%u", 0xfffff03f, 0x264bf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%Q %L,%K", 0xFFFFF000, 0x268BF000, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "tst%Q %L,%L", 0xffffffff, 0x260bff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst.f%Q %L,%L", 0xffffffff, 0x260bff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q %B,%C", 0xf8ff8020, 0x20cb8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f %B,%C", 0xf8ff8020, 0x20cb8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q %B,%u", 0xf8ff8020, 0x20cb8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f %B,%u", 0xf8ff8020, 0x20cb8020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q%Q %B,%L", 0xf8ff8fe0, 0x20cb8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f%Q %B,%L", 0xf8ff8fe0, 0x20cb8f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q%Q %L,%C", 0xfffff020, 0x26cbf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f%Q %L,%C", 0xfffff020, 0x26cbf000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q%Q %L,%u", 0xfffff020, 0x26cbf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f%Q %L,%u", 0xfffff020, 0x26cbf020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q%Q %L,%L", 0xffffffe0, 0x26cbff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "tst%.q.f%Q %L,%L", 0xffffffe0, 0x26cbff80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f %A,%B,%C%F", 0xf8ff0000, 0x20070000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f %A,%B,%u%F", 0xf8ff0000, 0x20470000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f %#,%B,%K%F", 0xf8ff0000, 0x20870000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q %A,%B,%L%F", 0xf8ff0fc0, 0x20070f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q %A,%L,%C%F", 0xffff7000, 0x26077000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q %A,%L,%u%F", 0xffff7000, 0x26477000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q %A,%L,%L%F", 0xffff7fc0, 0x26077f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f %#,%B,%C%F", 0xf8ff0020, 0x20c70000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f %#,%C,%B%F", 0xf8ff0020, 0x20c70000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f %#,%B,%u%F", 0xf8ff0020, 0x20c70020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f %#,%u,%B%F", 0xf8ff0020, 0x20c70020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20c70f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20c70f80, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f 0,%B,%C%F", 0xf8ff003f, 0x2007003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f 0,%B,%u%F", 0xf8ff003f, 0x2047003e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q 0,%B,%L%F", 0xf8ff0fff, 0x20070fbe, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q 0,%L,%C%F", 0xffff703f, 0x2607703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q 0,%L,%u%F", 0xffff703f, 0x2647703e, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.f%Q 0,%L,%K%F", 0xffff7000, 0x26877000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26c77000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26c77020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "xor%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26c77f80, ARCOMPACT, 0, 0 ,0,0},

  /* ARCompact 16-bit instructions */

/* abs_s b,c;                   01111 bbb ccc 10001 */
  { (unsigned char *) "abs_s %b,%c", 0xf81f, 0x7811, ARCOMPACT, 0, 0 ,0,0},

/* add_s a,b,c;                 01100 bbb ccc 11 aaa */
  { (unsigned char *) "add_s %a,%b,%c", 0xf818, 0x6018, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s b,b,h;                 01110 bbb hhh 00 hhh */
  { (unsigned char *) "add_s %b,%b,%U", 0xf818, 0x7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s c,b,u3;                01101 bbb ccc 00 uuu */
  { (unsigned char *) "add_s %c,%b,%e", 0xf818, 0x6800, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s b,b,u7;                11100 bbb 0 uuuuuuu */
  { (unsigned char *) "add_s %b,%b,%j", 0xf880, 0xe000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s b,b,limm;              01110 bbb 110 00 111 [L] */
  { (unsigned char *) "add_s%Q %b,%b,%L", 0xf8ff, 0x70c7, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s b,sp,u7;               11000 bbb 100 uuuuu */
  { (unsigned char *) "add_s %b,%6,%l", 0xf8e0, 0xc080, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s sp,sp,u7;              11000 000 101 uuuuu */
  { (unsigned char *) "add_s %6,%6,%l", 0xffe0, 0xc0a0, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* add_s r0,gp,s11;             11001 11 sssssssss */
  { (unsigned char *) "add_s %4,%5,%R", 0xfe00, 0xce00, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  //  { (unsigned char *) "add_s %4,%5,%[L", 0xfe00, 0xce00, ARCOMPACT, 0, 0 ,0,0},

/* add1_s b,b,c;                01111 bbb ccc 10100 */
  { (unsigned char *) "add1_s %b,%b,%c", 0xf81f, 0x7814, ARCOMPACT, 0, 0 ,0,0},

/* add2_s b,b,c;                01111 bbb ccc 10101 */
  { (unsigned char *) "add2_s %b,%b,%c", 0xf81f, 0x7815, ARCOMPACT, 0, 0 ,0,0},

/* add3_s b,b,c;                01111 bbb ccc 10110 */
  { (unsigned char *) "add3_s %b,%b,%c", 0xf81f, 0x7816, ARCOMPACT, 0, 0 ,0,0},

/* and_s b,b,c;                 01111 bbb ccc 00100 */
  { (unsigned char *) "and_s %b,%b,%c", 0xf81f, 0x7804, ARCOMPACT, 0, 0 ,0,0},

/* asl_s b,b,c;                 01111 bbb ccc 11000 */
  { (unsigned char *) "asl_s %b,%b,%c", 0xf81f, 0x7818, ARCOMPACT, 0, 0 ,0,0},
/* asl_s c,b,u3;                01101 bbb ccc 10 uuu */
  { (unsigned char *) "asl_s %c,%b,%e", 0xf818, 0x6810, ARCOMPACT, 0, 0 ,0,0},
/* asl_s b,b,u5;                10111 bbb 000 uuuuu */
  { (unsigned char *) "asl_s %b,%b,%E", 0xf8e0, 0xb800, ARCOMPACT, 0, 0 ,0,0},
/* asl_s b,c;                   01111 bbb ccc 11011 */
  { (unsigned char *) "asl_s %b,%c", 0xf81f, 0x781b, ARCOMPACT, 0, 0 ,0,0},

/* asr_s b,b,c;                 01111 bbb ccc 11010 */
  { (unsigned char *) "asr_s %b,%b,%c", 0xf81f, 0x781a, ARCOMPACT, 0, 0 ,0,0},
/* asr_s c,b,u3;                01101 bbb ccc 11 uuu */
  { (unsigned char *) "asr_s %c,%b,%e", 0xf818, 0x6818, ARCOMPACT, 0, 0 ,0,0},
/* asr_s b,b,u5;                10111 bbb 010 uuuuu */
  { (unsigned char *) "asr_s %b,%b,%E", 0xf8e0, 0xb840, ARCOMPACT, 0, 0 ,0,0},
/* asr_s b,c;                   01111 bbb ccc 11100 */
  { (unsigned char *) "asr_s %b,%c", 0xf81f, 0x781c, ARCOMPACT, 0, 0 ,0,0},

/* b_s d10;                     11110 00 sssssssss */
  { (unsigned char *) "b_s %Z", 0xfe00, 0xf000, ARCOMPACT, 0, 0 ,0,0},
/* beq_s d10;                   11110 01 sssssssss */
  { (unsigned char *) "beq_s %Z", 0xfe00, 0xf200, ARCOMPACT, 0, 0 ,0,0},
/* bne_s d10;                   11110 10 sssssssss */
  { (unsigned char *) "bne_s %Z", 0xfe00, 0xf400, ARCOMPACT, 0, 0 ,0,0},
/* bgt_s d7;                    11110 11 000 ssssss */
  { (unsigned char *) "bgt_s %s", 0xffc0, 0xf600, ARCOMPACT, 0, 0 ,0,0},
/* bge_s d7;                    11110 11 001 ssssss */
  { (unsigned char *) "bge_s %s", 0xffc0, 0xf640, ARCOMPACT, 0, 0 ,0,0},
/* blt_s d7;                    11110 11 010 ssssss */
  { (unsigned char *) "blt_s %s", 0xffc0, 0xf680, ARCOMPACT, 0, 0 ,0,0},
/* ble_s d7;                    11110 11 011 ssssss */
  { (unsigned char *) "ble_s %s", 0xffc0, 0xf6c0, ARCOMPACT, 0, 0 ,0,0},
/* bhi_s d7;                    11110 11 100 ssssss */
  { (unsigned char *) "bhi_s %s", 0xffc0, 0xf700, ARCOMPACT, 0, 0 ,0,0},
/* bhs_s d7;                    11110 11 101 ssssss */
  { (unsigned char *) "bhs_s %s", 0xffc0, 0xf740, ARCOMPACT, 0, 0 ,0,0},
/* blo_s d7;                    11110 11 110 ssssss */
  { (unsigned char *) "blo_s %s", 0xffc0, 0xf780, ARCOMPACT, 0, 0 ,0,0},
/* bls_s d7;                    11110 11 111 ssssss */
  { (unsigned char *) "bls_s %s", 0xffc0, 0xf7c0, ARCOMPACT, 0, 0 ,0,0},

/* bclr_s b,b,u5;               10111 bbb 101 uuuuu */
  { (unsigned char *) "bclr_s %b,%b,%E", 0xf8e0, 0xb8a0, ARCOMPACT, 0, 0 ,0,0},

/* bic_s b,b,c;                 01111 bbb ccc 00110 */
  { (unsigned char *) "bic_s %b,%b,%c", 0xf81f, 0x7806, ARCOMPACT, 0, 0 ,0,0},

/* bl_s d11;                    11111 sssssssssss */
  { (unsigned char *) "bl_s %W", 0xf800, 0xf800, ARCOMPACT, 0, 0 ,0,0},

/* bmsk_s b,b,u5;               10111 bbb 110 uuuuu */
  { (unsigned char *) "bmsk_s %b,%b,%E", 0xf8e0, 0xb8c0, ARCOMPACT, 0, 0 ,0,0},

/* breq_s b,0,d8;               11101 bbb 0 sssssss */
  { (unsigned char *) "breq_s %b,0,%S", 0xf880, 0xe800, ARCOMPACT, 0, 0 ,0,0},
/* brne_s b,0,d8;               11101 bbb 1 sssssss */
  { (unsigned char *) "brne_s %b,0,%S", 0xf880, 0xe880, ARCOMPACT, 0, 0 ,0,0},

/* brk_s ;                      01111 111 111 11111 */
  { (unsigned char *) "brk_s", 0xffff, 0x7fff, ARCOMPACT, 0, 0 ,0,0},

/* bset_s b,b,u5;               10111 bbb 100 uuuuu */
  { (unsigned char *) "bset_s %b,%b,%E", 0xf8e0, 0xb880, ARCOMPACT, 0, 0 ,0,0},

/* btst_s b,u5;                 10111 bbb 111 uuuuu */
  { (unsigned char *) "btst_s %b,%E", 0xf8e0, 0xb8e0, ARCOMPACT, 0, 0 ,0,0},

/* cmp_s b,h;                   01110 bbb hhh 10 hhh */
  { (unsigned char *) "cmp_s %b,%U", 0xf818, 0x7010, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* cmp_s b,u7;                  11100 bbb 1 uuuuuuu */
  { (unsigned char *) "cmp_s %b,%j", 0xf880, 0xe080, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* cmp_s b,limm;                01110 bbb 110 10 111 [L] */
  { (unsigned char *) "cmp_s%Q %b,%L", 0xf8ff, 0x70d7, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* extb_s b,c;                  01111 bbb ccc 01111 */
  { (unsigned char *) "extb_s %b,%c", 0xf81f, 0x780f, ARCOMPACT, 0, 0 ,0,0},

/* extw_s b,c;                  01111 bbb ccc 10000 */
  { (unsigned char *) "extw_s %b,%c", 0xf81f, 0x7810, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* j_s [b];                     01111 bbb 000 00000 */
  { (unsigned char *) "j_s [%b]", 0xf8ff, 0x7800, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
  { (unsigned char *) "j_s.nd [%b]", 0xf8ff, 0x7800, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
/* j_s.d [b];                   01111 bbb 001 00000 */
  { (unsigned char *) "j_s.d [%b]", 0xf8ff, 0x7820, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
/* j_s [blink];                 01111 110 111 00000 */
  { (unsigned char *) "j_s [%9]", 0xffff, 0x7ee0, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
  { (unsigned char *) "j_s.nd [%9]", 0xffff, 0x7ee0, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
/* j_s.d [blink];               01111 111 111 00000 */
  { (unsigned char *) "j_s.d [%9]", 0xffff, 0x7fe0, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
/* jeq_s [blink];               01111 100 111 00000 */
  { (unsigned char *) "jeq_s [%9]", 0xffff, 0x7ce0, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* jne_s [blink];               01111 101 111 00000 */
  { (unsigned char *) "jne_s [%9]", 0xffff, 0x7de0, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* jl_s [b];                    01111 bbb 010 00000 */
  { (unsigned char *) "jl_s [%b]", 0xf8ff, 0x7840, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
  { (unsigned char *) "jl_s.nd [%b]", 0xf8ff, 0x7840, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},
/* jl_s.d [b];                  01111 bbb 011 00000 */
  { (unsigned char *) "jl_s.d [%b]", 0xf8ff, 0x7860, ARCOMPACT | ARC_MACH_ARCV2, 0, 0 ,0,0},

/* ld_s a,[b,c];                01100 bbb ccc 00 aaa */
  { (unsigned char *) "ld_s %a,[%b,%c]", 0xf818, 0x6000, ARCOMPACT, 0, 0 ,0,0},
/* ldb_s a,[b,c];               01100 bbb ccc 01 aaa */
  { (unsigned char *) "ldb_s %a,[%b,%c]", 0xf818, 0x6008, ARCOMPACT, 0, 0 ,0,0},
/* ldw_s a,[b,c];               01100 bbb ccc 10 aaa */
  { (unsigned char *) "ldw_s %a,[%b,%c]", 0xf818, 0x6010, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* ld_s c,[b,u7];               10000 bbb ccc uuuuu */
  { (unsigned char *) "ld_s %c,[%b,%l]", 0xf800, 0x8000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ld_s %c,[%b]", 0xf800, 0x8000, ARCOMPACT, 0, 0 ,0,0},
/* ldb_s c,[b,u5];              10001 bbb ccc uuuuu */
  { (unsigned char *) "ldb_s %c,[%b,%E]", 0xf800, 0x8800, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ldb_s %c,[%b]", 0xf800, 0x8800, ARCOMPACT, 0, 0 ,0,0},
/* ldw_s c,[b,u6];              10010 bbb ccc uuuuu */
  { (unsigned char *) "ldw_s %c,[%b,%k]", 0xf800, 0x9000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "ldw_s %c,[%b]",    0xf800, 0x9000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* ldw_s.x c,[b,u6];            10011 bbb ccc uuuuu */
  { (unsigned char *) "ldw_s.x %c,[%b,%k]", 0xf800, 0x9800, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "ldw_s.x %c,[%b]",    0xf800, 0x9800, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* ld_s b,[sp,u7];              11000 bbb 000 uuuuu */
  { (unsigned char *) "ld_s %b,[%6,%l]", 0xf8e0, 0xc000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ld_s %b,[%6]", 0xf8e0, 0xc000, ARCOMPACT, 0, 0 ,0,0},
/* ldb_s b,[sp,u7];             11000 bbb 001 uuuuu */
  { (unsigned char *) "ldb_s %b,[%6,%l]", 0xf8e0, 0xc020, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ldb_s %b,[%6]", 0xf8e0, 0xc020, ARCOMPACT, 0, 0 ,0,0},
/* ld_s r0,[gp,s11];            11001 00 sssssssss */
  { (unsigned char *) "ld_s %4,[%5,%[L]", 0xfe00, 0xc800, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ld_s %4,[%5,%R]", 0xfe00, 0xc800, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ld_s %4,[%5]", 0xfe00, 0xc800, ARCOMPACT, 0, 0 ,0,0},
/* ldb_s r0,[gp,s9];            11001 01 sssssssss */
  { (unsigned char *) "ldb_s %4,[%5,%[L]", 0xfe00, 0xca00, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ldb_s %4,[%5,%M]", 0xfe00, 0xca00, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ldb_s %4,[%5]", 0xfe00, 0xca00, ARCOMPACT, 0, 0 ,0,0},
/* ldw_s r0,[gp,s10];           11001 10 sssssssss */
  { (unsigned char *) "ldw_s %4,[%5,%[L]", 0xfe00, 0xcc00, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "ldw_s %4,[%5,%O]",  0xfe00, 0xcc00, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "ldw_s %4,[%5]",     0xfe00, 0xcc00, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* ld_s b,[pcl,u10];            11010 bbb uuuuuuuu */
  { (unsigned char *) "ld_s %b,[%!,%m]", 0xf800, 0xd000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "ld_s %b,[%!]", 0xf800, 0xd000, ARCOMPACT, 0, 0 ,0,0},

/* lsl_s b,b,c;                 01111 bbb ccc 11000 */
  { (unsigned char *) "lsl_s %b,%b,%c", 0xf81f, 0x7818, ARCOMPACT, 0, 0 ,0,0},
/* lsl_s c,b,u3;                01101 bbb ccc 10 uuu */
  { (unsigned char *) "lsl_s %c,%b,%e", 0xf818, 0x6810, ARCOMPACT, 0, 0 ,0,0},
/* lsl_s b,b,u5;                10111 bbb 000 uuuuu */
  { (unsigned char *) "lsl_s %b,%b,%E", 0xf8e0, 0xb800, ARCOMPACT, 0, 0 ,0,0},
/* lsl_s b,c;                   01111 bbb ccc 11011 */
  { (unsigned char *) "lsl_s %b,%c", 0xf81f, 0x781b, ARCOMPACT, 0, 0 ,0,0},

/* lsr_s b,b,c;                 01111 bbb ccc 11001 */
  { (unsigned char *) "lsr_s %b,%b,%c", 0xf81f, 0x7819, ARCOMPACT, 0, 0 ,0,0},
/* lsr_s b,b,u5;                10111 bbb 001 uuuuu */
  { (unsigned char *) "lsr_s %b,%b,%E", 0xf8e0, 0xb820, ARCOMPACT, 0, 0 ,0,0},
/* lsr_s b,c;                   01111 bbb ccc 11101 */
  { (unsigned char *) "lsr_s %b,%c", 0xf81f, 0x781d, ARCOMPACT, 0, 0 ,0,0},

/* mov_s b,h;                   01110 bbb hhh 01 hhh */
  { (unsigned char *) "mov_s %b,%U", 0xf818, 0x7008, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* mov_s b,u8;                  11011 bbb uuuuuuuu */
  { (unsigned char *) "mov_s %b,%J", 0xf800, 0xd800, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* mov_s b,limm;                01110 bbb 110 01 111 [L] */
  { (unsigned char *) "mov_s%Q %b,%L", 0xf8ff, 0x70cf, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* mov_s b,limm@sda;            01110 bbb 110 01 111 [L] */
  { (unsigned char *) "mov_s%Q %b,%[L", 0xf8ff, 0x70cf, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* mov_s h,b;                   01110 bbb hhh 11 hhh */
  { (unsigned char *) "mov_s %U,%b", 0xf818, 0x7018, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
/* mov_s 0,b;                   01110 bbb 110 11 111 */
  { (unsigned char *) "mov_s 0,%b", 0xf8ff, 0x70df, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* mul64_s 0,b,c;               01111 bbb ccc 01100 */
  { (unsigned char *) "mul64_s 0,%b,%c", 0xf81f, 0x780c, ARCOMPACT, 0, 0 ,0,0},

/* neg_s b,c;                   01111 bbb ccc 10011 */
  { (unsigned char *) "neg_s %b,%c", 0xf81f, 0x7813, ARCOMPACT, 0, 0 ,0,0},

/* not_s b,c;                   01111 bbb ccc 10010 */
  { (unsigned char *) "not_s %b,%c", 0xf81f, 0x7812, ARCOMPACT, 0, 0 ,0,0},

/* nop_s ;                      01111 000 111 00000 */
  { (unsigned char *) "nop_s", 0xffff, 0x78e0, ARCOMPACT, 0, 0 ,0,0},

/* unimp_s ;                    01111 001 111 00000 */
/* ARC700 addition */
  { (unsigned char *) "unimp_s", 0xffff, 0x79e0, ARC_MACH_ARC7 | ARC_MACH_ARCV2, 0, 0 ,0,0},

/* or_s b,b,c;                  01111 bbb ccc 00101 */
  { (unsigned char *) "or_s %b,%b,%c", 0xf81f, 0x7805, ARCOMPACT, 0, 0 ,0,0},

/* pop_s b;                     11000 bbb 110 00001 */
  { (unsigned char *) "pop_s %b", 0xf8ff, 0xc0c1, ARCOMPACT, 0, 0 ,0,0},
/* pop_s blink;                 11000 rrr 110 10001 */
  { (unsigned char *) "pop_s %9", 0xffff, 0xc0d1, ARCOMPACT, 0, 0 ,0,0},

/* push_s b;                    11000 bbb 111 00001 */
  { (unsigned char *) "push_s %b", 0xf8ff, 0xc0e1, ARCOMPACT, 0, 0 ,0,0},
/* push_s blink;                11000 rrr 111 10001 */
  { (unsigned char *) "push_s %9", 0xffff, 0xc0f1, ARCOMPACT, 0, 0 ,0,0},

/* sexb_s b,c;                  01111 bbb ccc 01101 */
  { (unsigned char *) "sexb_s %b,%c", 0xf81f, 0x780d, ARCOMPACT, 0, 0 ,0,0},

/* sexw_s b,c;                  01111 bbb ccc 01110 */
  { (unsigned char *) "sexw_s %b,%c", 0xf81f, 0x780e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* st_s b,[sp,u7];                  11000 bbb 010 uuuuu */
  { (unsigned char *) "st_s %b,[%6,%l]", 0xf8e0, 0xc040, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "st_s %b,[%6]",    0xf8e0, 0xc040, ARCOMPACT, 0, 0 ,0,0},
/* stb_s b,[sp,u7];                  11000 bbb 011 uuuuu */
  { (unsigned char *) "stb_s %b,[%6,%l]", 0xf8e0, 0xc060, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "stb_s %b,[%6]", 0xf8e0, 0xc060, ARCOMPACT, 0, 0 ,0,0},
/* st_s c,[b,u7];                  10100 bbb ccc uuuuu */
  { (unsigned char *) "st_s %c,[%b,%l]", 0xf800, 0xa000, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "st_s %c,[%b]", 0xf800, 0xa000, ARCOMPACT, 0, 0 ,0,0},
/* stb_s c,[b,u5];                  10101 bbb ccc uuuuu */
  { (unsigned char *) "stb_s %c,[%b,%E]", 0xf800, 0xa800, ARCOMPACT, 0, 0 ,0,0},
  { (unsigned char *) "stb_s %c,[%b]", 0xf800, 0xa800, ARCOMPACT, 0, 0 ,0,0},
/* stw_s c,[b,u6];                  10110 bbb ccc uuuuu */
  { (unsigned char *) "stw_s %c,[%b,%k]", 0xf800, 0xb000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},
  { (unsigned char *) "stw_s %c,[%b]",    0xf800, 0xb000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0,0},

/* sub_s b,b,c;                 01111 bbb ccc 00010 */
  { (unsigned char *) "sub_s %b,%b,%c", 0xf81f, 0x7802, ARCOMPACT, 0, 0 ,0,0},
/* sub_s c,b,u3;                01101 bbb ccc 01 uuu */
  { (unsigned char *) "sub_s %c,%b,%e", 0xf818, 0x6808, ARCOMPACT, 0, 0 ,0,0},
/* sub_s b,b,u5;                10111 bbb 011 uuuuu */
  { (unsigned char *) "sub_s %b,%b,%E", 0xf8e0, 0xb860, ARCOMPACT, 0, 0 ,0,0},
/* sub_s sp,sp,u7;              11000 001 101 uuuuu */
  { (unsigned char *) "sub_s %6,%6,%l", 0xffe0, 0xc1a0, ARCOMPACT, 0, 0 ,0,0},
/* sub_s.ne b,b,b;              01111 bbb 110 00000 */
  { (unsigned char *) "sub_s.ne %b,%b,%b", 0xf8ff, 0x78c0, ARCOMPACT, 0, 0 ,0,0},

/* trap_s unsigned 6 ;   ARC A700 new instruction    01111 1uuuuuu 11110*/
  { (unsigned char *) "trap_s %@", 0xffff, 0x781E, ARC_MACH_ARC7 | ARC_MACH_ARCV2, 0, 0 ,0,0},

/* tst_s b,c;                   01111 bbb ccc 01011 */
  { (unsigned char *) "tst_s %b,%c", 0xf81f, 0x780b, ARCOMPACT, 0, 0 ,0,0},

/* xor_s b,b,c;                 01111 bbb ccc 00111 */
  { (unsigned char *) "xor_s %b,%b,%c", 0xf81f, 0x7807, ARCOMPACT, 0, 0 ,0,0},

  { (unsigned char *) "nop", 0xffffffff, 0x264a7000, ARCOMPACT, 0, 0 ,0,0},

/* MPYW & MPYUW -- 16-bit multiply instructions.  */
  { (unsigned char *) "mpyw%.f %A,%B,%C%F",      0xf8ff0000, 0x201e0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f %A,%B,%u%F",      0xf8ff0000, 0x205e0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f %#,%B,%K%F",      0xf8ff0000, 0x209e0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q %A,%B,%L%F",    0xf8ff0fc0, 0x201e0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q %A,%L,%C%F",    0xffff7000, 0x261e7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q %A,%L,%u%F",    0xffff7000, 0x265e7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q %A,%L,%L%F",    0xffff7fc0, 0x261e7f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f %#,%B,%C%F",   0xf8ff0020, 0x20de0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f %#,%C,%B%F",   0xf8ff0020, 0x20de0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f %#,%B,%u%F",   0xf8ff00f0, 0x20de0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f %#,%u,%B%F",   0xf8ff00f0, 0x20de0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f%Q %#,%B,%L%F", 0xf8ff0fe0, 0x20de0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f%Q %#,%L,%B%F", 0xf8ff0fe0, 0x20de0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f 0,%B,%C%F",       0xf8ff003f, 0x201e003e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f 0,%B,%u%F",       0xf8ff003f, 0x205e003e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q 0,%B,%L%F",     0xf8ff0fff, 0x201e0fbe, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q 0,%L,%C%F",     0xffff703f, 0x261e703e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q 0,%L,%u%F",     0xffff703f, 0x265e703e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.f%Q 0,%L,%K%F",     0xffff7000, 0x269e7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f%Q 0,%L,%C%F",  0xffff7020, 0x26de7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f%Q 0,%L,%u%F",  0xffff7020, 0x26de7020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyw%.q%.f%Q 0,%L,%L%F",  0xffff7fff, 0x26de7f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},

  { (unsigned char *) "mpyuw%.f %A,%B,%C%F",     0xf8ff0000, 0x201f0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f %A,%B,%u%F",     0xf8ff0000, 0x205f0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f %#,%B,%K%F",     0xf8ff0000, 0x209f0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q %A,%B,%L%F",   0xf8ff0fc0, 0x201f0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q %A,%L,%C%F",   0xffff7000, 0x261f7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q %A,%L,%u%F",   0xffff7000, 0x265f7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q %A,%L,%L%F",   0xffff7fc0, 0x261f7f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f %#,%B,%C%F",  0xf8ff0020, 0x20df0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f %#,%C,%B%F",  0xf8ff0020, 0x20df0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f %#,%B,%u%F",  0xf8ff00f0, 0x20df0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f %#,%u,%B%F",  0xf8ff00f0, 0x20df0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f%Q %#,%B,%L%F",0xf8ff0fe0, 0x20df0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f%Q %#,%L,%B%F",0xf8ff0fe0, 0x20df0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f 0,%B,%C%F",      0xf8ff003f, 0x201f003e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f 0,%B,%u%F",      0xf8ff003f, 0x205f003e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q 0,%B,%L%F",    0xf8ff0fff, 0x201f0fbe, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q 0,%L,%C%F",    0xffff703f, 0x261f703e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q 0,%L,%u%F",    0xffff703f, 0x265f703e, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.f%Q 0,%L,%K%F",    0xffff7000, 0x269f7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f%Q 0,%L,%C%F", 0xffff7020, 0x26df7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f%Q 0,%L,%u%F", 0xffff7020, 0x26df7020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},
  { (unsigned char *) "mpyuw%.q%.f%Q 0,%L,%L%F", 0xffff7fff, 0x26df7f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0 ,0, 0},

  /* RTSC */
  { (unsigned char *) "rtsc %B,0", 0x0, 0x306f001a, ARCOMPACT, 0, 0, 0, 0},
  { (unsigned char *) "rtsc 0,0",  0x0, 0x366f701a, ARCOMPACT, 0, 0, 0, 0},

  /* Android Extension Instructions */
  { (unsigned char *) "avgqb %A,%B,%C%F",     0x0, 0x30230000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb %A,%B,%u%F",     0x0, 0x30630000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb %A,%B,%L%F",     0x0, 0x30230f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb %A,%L,%C%F",     0x0, 0x36237000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb%.q %#,%B,%C%F",  0x0, 0x30e30000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb%.q %#,%B,%u%F",  0x0, 0x30e30020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb%.q %#,%B,%L%F",  0x0, 0x30e30f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "avgqb %#,%B,%K%F",     0x0, 0x30a30000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs %A,%B,%C%F",    0x0, 0x30240000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs %A,%B,%u%F",    0x0, 0x30640000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs %A,%B,%L%F",    0x0, 0x30240f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs %A,%L,%C%F",    0x0, 0x36247000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs%.q %#,%B,%C%F", 0x0, 0x30e40000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs%.q %#,%B,%u%F", 0x0, 0x30e40020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs%.q %#,%B,%L%F", 0x0, 0x30e40f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "addqbs %#,%B,%K%F",    0x0, 0x30a40000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb %A,%B,%C%F",     0x0, 0x30250000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb %A,%B,%u%F",     0x0, 0x30650000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb %A,%B,%L%F",     0x0, 0x30250f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb %A,%L,%C%F",     0x0, 0x36257000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb%.q %#,%B,%C%F",  0x0, 0x30e50000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb%.q %#,%B,%u%F",  0x0, 0x30e50020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb%.q %#,%B,%L%F",  0x0, 0x30e50f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyqb %#,%B,%K%F",     0x0, 0x30a50000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb %A,%B,%C%F",      0x0, 0x30200000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb %A,%B,%u%F",      0x0, 0x30600000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb %A,%B,%L%F",      0x0, 0x30200f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb %A,%L,%C%F",      0x0, 0x36207000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb%.q %#,%B,%C%F",   0x0, 0x30e00000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb%.q %#,%B,%u%F",   0x0, 0x30e00020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb%.q %#,%B,%L%F",   0x0, 0x30e00f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "pkqb %#,%B,%K%F",      0x0, 0x30a00000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb %A,%B,%C%F",     0x0, 0x30210000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb %A,%B,%u%F",     0x0, 0x30610000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb %A,%B,%L%F",     0x0, 0x30210f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb %A,%L,%C%F",     0x0, 0x36217000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb%.q %#,%B,%C%F",  0x0, 0x30e10000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb%.q %#,%B,%u%F",  0x0, 0x30e10020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb%.q %#,%B,%L%F",  0x0, 0x30e10f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "upkqb %#,%B,%K%F",     0x0, 0x30a10000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr %A,%B,%C%F",      0x0, 0x30260000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr %A,%B,%u%F",      0x0, 0x30660000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr %A,%B,%L%F",      0x0, 0x30260f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr %A,%L,%C%F",      0x0, 0x36267000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr%.q %#,%B,%C%F",   0x0, 0x30e60000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr%.q %#,%B,%u%F",   0x0, 0x30e60020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr%.q %#,%B,%L%F",   0x0, 0x30e60f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "fxtr %#,%B,%K%F",      0x0, 0x30a60000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb %A,%B,%C%F",     0x0, 0x30220000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb %A,%B,%u%F",     0x0, 0x30620000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb %A,%B,%L%F",     0x0, 0x30220f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb %A,%L,%C%F",     0x0, 0x36227000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb%.q %#,%B,%C%F",  0x0, 0x30e20000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb%.q %#,%B,%u%F",  0x0, 0x30e20020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb%.q %#,%B,%L%F",  0x0, 0x30e20f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "xpkqb %#,%B,%K%F",     0x0, 0x30a20000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm %A,%B,%C%F",       0x0, 0x30280000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm %A,%B,%u%F",       0x0, 0x30680000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm %A,%B,%L%F",       0x0, 0x30280f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm %A,%L,%C%F",       0x0, 0x36287000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm%.q %#,%B,%C%F",    0x0, 0x30e80000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm%.q %#,%B,%u%F",    0x0, 0x30e80020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm%.q %#,%B,%L%F",    0x0, 0x30e80f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "acm %#,%B,%K%F",       0x0, 0x30a80000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr %A,%B,%C%F",     0x0, 0x30290000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr %A,%B,%u%F",     0x0, 0x30690000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr %A,%B,%L%F",     0x0, 0x30290f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr %A,%L,%C%F",     0x0, 0x36297000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr%.q %#,%B,%C%F",  0x0, 0x30e90000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr%.q %#,%B,%u%F",  0x0, 0x30e90020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr%.q %#,%B,%L%F",  0x0, 0x30e90f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "sfxtr %#,%B,%K%F",     0x0, 0x30a90000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp %A,%B,%C%F",     0x0, 0x302a0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp %A,%B,%u%F",     0x0, 0x306a0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp %A,%B,%L%F",     0x0, 0x302a0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp %A,%L,%C%F",     0x0, 0x362a7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp%.q %#,%B,%C%F",  0x0, 0x30ea0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp%.q %#,%B,%u%F",  0x0, 0x30ea0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp%.q %#,%B,%L%F",  0x0, 0x30ea0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "clamp %#,%B,%K%F",     0x0, 0x30aa0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16 %A,%B,%C%F",    0x0, 0x302b0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16 %A,%B,%u%F",    0x0, 0x306b0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16 %A,%B,%L%F",    0x0, 0x302b0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16 %A,%L,%C%F",    0x0, 0x362b7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16%.q %#,%B,%C%F", 0x0, 0x30eb0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16%.q %#,%B,%u%F", 0x0, 0x30eb0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16%.q %#,%B,%L%F", 0x0, 0x30eb0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpyu16 %#,%B,%K%F",    0x0, 0x30ab0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16 %A,%B,%C%F",     0x0, 0x302c0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16 %A,%B,%u%F",     0x0, 0x306c0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16 %A,%B,%L%F",     0x0, 0x302c0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16 %A,%L,%C%F",     0x0, 0x362c7000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16%.q %#,%B,%C%F",  0x0, 0x30ec0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16%.q %#,%B,%u%F",  0x0, 0x30ec0020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16%.q %#,%B,%L%F",  0x0, 0x30ec0f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "mpy16 %#,%B,%K%F",     0x0, 0x30ac0000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr %A,%B,%C%F",     0x0, 0x30270000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr %A,%B,%u%F",     0x0, 0x30670000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr %A,%B,%L%F",     0x0, 0x30270f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr %A,%L,%C%F",     0x0, 0x36277000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr%.q %#,%B,%C%F",  0x0, 0x30e70000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr%.q %#,%B,%u%F",  0x0, 0x30e70020, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr%.q %#,%B,%L%F",  0x0, 0x30e70f80, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},
  { (unsigned char *) "iaddr %#,%B,%K%F",     0x0, 0x30a70000, ARCOMPACT & (~ARC_MACH_ARCV2), 0, 0, 0, 0},

  /*ARC v2 extensions*/
  #include "arc-em.h"

#ifdef ARC_NPS_CMDS
  #include "arc-nps.h"
#endif // #ifdef ARC_NPS_CMDS

};


/* Register names table for ARCtangent-A4 */

static const struct arc_operand_value arc_reg_names_a4[] =
{
  /* Sort this so that the first 61 entries are sequential.
     IE: For each i (i<61), arc_reg_names[i].value == i.  */

  { "r0", 0, REG, 0 }, { "r1", 1, REG, 0 }, { "r2", 2, REG, 0 },
  { "r3", 3, REG, 0 }, { "r4", 4, REG, 0 }, { "r5", 5, REG, 0 },
  { "r6", 6, REG, 0 }, { "r7", 7, REG, 0 }, { "r8", 8, REG, 0 },
  { "r9", 9, REG, 0 },
  { "r10", 10, REG, 0 }, { "r11", 11, REG, 0 }, { "r12", 12, REG, 0 },
  { "r13", 13, REG, 0 }, { "r14", 14, REG, 0 }, { "r15", 15, REG, 0 },
  { "r16", 16, REG, 0 }, { "r17", 17, REG, 0 }, { "r18", 18, REG, 0 },
  { "r19", 19, REG, 0 }, { "r20", 20, REG, 0 }, { "r21", 21, REG, 0 },
  { "r22", 22, REG, 0 }, { "r23", 23, REG, 0 }, { "r24", 24, REG, 0 },
  { "r25", 25, REG, 0 }, { "r26", 26, REG, 0 }, { "r27", 27, REG, 0 },
  { "r28", 28, REG, 0 }, { "r29", 29, REG, 0 }, { "r30", 30, REG, 0 },
  { "r31", 31, REG, 0 },
  { "r60", 60, REG, 0 },
  { "fp", 27, REG, 0 }, { "sp", 28, REG, 0 },
  { "ilink1", 29, REG, 0 }, { "ilink2", 30, REG, 0 }, { "blink", 31, REG, 0 },
  { "lp_count", 60, REG, 0 },

    /* Standard auxiliary registers.  */
  { "status",         0x00, AUXREG, ARC_REGISTER_READONLY },
  { "semaphore",      0x01, AUXREG, 0 },
  { "lp_start",       0x02, AUXREG, 0 },
  { "lp_end",         0x03, AUXREG, 0 },
  { "identity",       0x04, AUXREG, ARC_REGISTER_READONLY },
  { "debug",          0x05, AUXREG, 0 },
    /* Extension auxilary registers */
  { "ivic",           0x10, AUXREG, ARC_REGISTER_WRITEONLY },
  { "ch_mode_ctl",    0x11, AUXREG, 0 },
  { "lockline",       0x13, AUXREG, 0 },
  { "code_ram",       0x14, AUXREG, 0 },
  { "tag_addr_mask",  0x15, AUXREG, 0 },
  { "tag_data_mask",  0x16, AUXREG, 0 },
  { "line_length_mask",       0x17, AUXREG, 0 },
  { "local_ram",      0x18, AUXREG, 0 },
  { "unlockline",     0x19, AUXREG, 0 },
  { "sram_seq",       0x20, AUXREG, 0 },
  { "timer",          0x21, AUXREG, 0 },
  { "tcontrol",       0x22, AUXREG, 0 },
  { "hint",           0x23, AUXREG, ARC_REGISTER_WRITEONLY },
  { "pcport",         0x24, AUXREG, ARC_REGISTER_WRITEONLY },
  { "sp1_ctrl",       0x30, AUXREG, 0 },
  { "sp1_val",        0x31, AUXREG, 0 },
  { "sp2_ctrl",       0x32, AUXREG, 0 },
  { "sp2_val",        0x33, AUXREG, 0 },
  { "sp3_ctrl",       0x34, AUXREG, 0 },
  { "sp3_val",        0x35, AUXREG, 0 },
  { "burst_size",     0x38, AUXREG, 0 },
  { "scratch_a",      0x39, AUXREG, 0 },
  { "load_a",         0x3A, AUXREG, 0 },
  { "store_a",        0x3B, AUXREG, 0 },
  { "bm_status",      0x3C, AUXREG, ARC_REGISTER_READONLY },
  { "xtp_newval",     0x40, AUXREG, 0 },
  { "macmode",        0x41, AUXREG, 0 },
  { "lsp_newval",     0x42, AUXREG, 0 },
  { "status32",       0xa, AUXREG, ARC_REGISTER_READONLY },
  { "status32_l1",    0xb, AUXREG, 0 },
  { "status32_l2",    0xc, AUXREG, 0 },
  { "int_vector_base",0x25, AUXREG, 0 }
};


/* Register names table for ARC A500 and A600*/
static const struct arc_operand_value arc_reg_names_a500600[] =
{
  /* Sort this so that the first 61 entries are sequential.
     IE: For each i (i<61), arc_reg_names[i].value == i.  */

  { "r0", 0, REG_AC, 0 }, { "r1", 1, REG_AC, 0 }, { "r2", 2, REG_AC, 0 },
  { "r3", 3, REG_AC, 0 }, { "r4", 4, REG_AC, 0 }, { "r5", 5, REG_AC, 0 },
  { "r6", 6, REG_AC, 0 }, { "r7", 7, REG_AC, 0 }, { "r8", 8, REG_AC, 0 },
  { "r9", 9, REG_AC, 0 },
  { "r10", 10, REG_AC, 0 }, { "r11", 11, REG_AC, 0 }, { "r12", 12, REG_AC, 0 },
  { "r13", 13, REG_AC, 0 }, { "r14", 14, REG_AC, 0 }, { "r15", 15, REG_AC, 0 },
  { "r16", 16, REG_AC, 0 }, { "r17", 17, REG_AC, 0 }, { "r18", 18, REG_AC, 0 },
  { "r19", 19, REG_AC, 0 }, { "r20", 20, REG_AC, 0 }, { "r21", 21, REG_AC, 0 },
  { "r22", 22, REG_AC, 0 }, { "r23", 23, REG_AC, 0 }, { "r24", 24, REG_AC, 0 },
  { "r25", 25, REG_AC, 0 }, { "r26", 26, REG_AC, 0 }, { "r27", 27, REG_AC, 0 },
  { "r28", 28, REG_AC, 0 }, { "r29", 29, REG_AC, 0 }, { "r30", 30, REG_AC, 0 },
  { "r31", 31, REG_AC, 0 },
  { "gp", 26, REG_AC, 0 },  { "fp", 27, REG_AC, 0 },  { "sp", 28, REG_AC, 0 },
  { "ilink1", 29, REG_AC, 0 },
  { "ilink2", 30, REG_AC, 0 },
  { "blink", 31, REG_AC, 0 },
  { "lp_count", 60, REG_AC, 0 }, { "r60", 60, REG_AC, 0 },
  { "pcl", 63, REG_AC, ARC_REGISTER_READONLY },
  { "r63", 63, REG_AC, ARC_REGISTER_READONLY },

  /* General Purpose Registers for ARCompact 16-bit insns */

  { "r0", 0, REG_AC, ARC_REGISTER_16 }, { "r1", 1, REG_AC, ARC_REGISTER_16 },
  { "r2", 2, REG_AC, ARC_REGISTER_16 }, { "r3", 3, REG_AC, ARC_REGISTER_16 },
  { "r12", 4, REG_AC, ARC_REGISTER_16 }, { "r13", 5, REG_AC, ARC_REGISTER_16 },
  { "r14", 6, REG_AC, ARC_REGISTER_16 }, { "r15", 7, REG_AC, ARC_REGISTER_16 },

    /* Standard auxiliary registers.  */
  { "status",         0x00, AUXREG_AC, ARC_REGISTER_READONLY },
  { "semaphore",      0x01, AUXREG_AC, 0 },
  { "lp_start",       0x02, AUXREG_AC, 0 },
  { "lp_end",         0x03, AUXREG_AC, 0 },
  { "identity",       0x04, AUXREG_AC, ARC_REGISTER_READONLY },
  { "debug",          0x05, AUXREG_AC, ARC_REGISTER_READONLY },
  { "pc",             0x06, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32",       0xa, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32_l1",    0xb, AUXREG_AC, 0 },
  { "status32_l2",    0xc, AUXREG_AC, 0 },
  { "int_vector_base",0x25, AUXREG_AC, 0 },
  /* Optional extension auxiliary registers */
  { "multiply_build", 0x7b, AUXREG_AC, ARC_REGISTER_READONLY },
  { "swap_build",     0x7c, AUXREG_AC, ARC_REGISTER_READONLY },
  { "norm_build",     0x7d, AUXREG_AC, ARC_REGISTER_READONLY },
  { "barrel_build",   0x7f, AUXREG_AC, ARC_REGISTER_READONLY },
};


/* Register names table for ARC 700 */
static const struct arc_operand_value arc_reg_names_a700[] =
{
  /* Sort this so that the first 61 entries are sequential.
     IE: For each i (i<61), arc_reg_names[i].value == i.  */

  { "r0", 0, REG_AC, 0 }, { "r1", 1, REG_AC, 0 }, { "r2", 2, REG_AC, 0 },
  { "r3", 3, REG_AC, 0 }, { "r4", 4, REG_AC, 0 }, { "r5", 5, REG_AC, 0 },
  { "r6", 6, REG_AC, 0 }, { "r7", 7, REG_AC, 0 }, { "r8", 8, REG_AC, 0 },
  { "r9", 9, REG_AC, 0 },
  { "r10", 10, REG_AC, 0 }, { "r11", 11, REG_AC, 0 }, { "r12", 12, REG_AC, 0 },
  { "r13", 13, REG_AC, 0 }, { "r14", 14, REG_AC, 0 }, { "r15", 15, REG_AC, 0 },
  { "r16", 16, REG_AC, 0 }, { "r17", 17, REG_AC, 0 }, { "r18", 18, REG_AC, 0 },
  { "r19", 19, REG_AC, 0 }, { "r20", 20, REG_AC, 0 }, { "r21", 21, REG_AC, 0 },
  { "r22", 22, REG_AC, 0 }, { "r23", 23, REG_AC, 0 }, { "r24", 24, REG_AC, 0 },
  { "r25", 25, REG_AC, 0 }, { "r26", 26, REG_AC, 0 }, { "r27", 27, REG_AC, 0 },
  { "r28", 28, REG_AC, 0 }, { "r29", 29, REG_AC, 0 }, { "r30", 30, REG_AC, 0 },
  { "r31", 31, REG_AC, 0 },
  { "gp", 26, REG_AC, 0 }, { "fp", 27, REG_AC, 0 }, { "sp", 28, REG_AC, 0 },
  { "ilink1", 29, REG_AC, 0 },
  { "ilink2", 30, REG_AC, 0 },
  { "blink", 31, REG_AC, 0 },
#ifdef ARC_NPS_CMDS
  { "r58", 58, REG_AC, 0 },
#endif  // #ifdef ARC_NPS_CMDS
  { "lp_count", 60, REG_AC, 0 }, { "r60", 60, REG_AC, 0 },
  { "pcl", 63, REG_AC, ARC_REGISTER_READONLY },
  { "r63", 63, REG_AC, ARC_REGISTER_READONLY },

  /* General Purpose Registers for ARCompact 16-bit insns */

  { "r0", 0, REG_AC, ARC_REGISTER_16 }, { "r1", 1, REG_AC, ARC_REGISTER_16 },
  { "r2", 2, REG_AC, ARC_REGISTER_16 }, { "r3", 3, REG_AC, ARC_REGISTER_16 },
  { "r12", 4, REG_AC, ARC_REGISTER_16 }, { "r13", 5, REG_AC, ARC_REGISTER_16 },
  { "r14", 6, REG_AC, ARC_REGISTER_16 }, { "r15", 7, REG_AC, ARC_REGISTER_16 },


    /* Standard auxiliary registers.  */
  { "status",         0x00, AUXREG_AC, ARC_REGISTER_READONLY },
  { "semaphore",      0x01, AUXREG_AC, 0 },
  { "lp_start",       0x02, AUXREG_AC, 0  },
  { "lp_end",         0x03, AUXREG_AC, 0 },
  { "identity",       0x04, AUXREG_AC, ARC_REGISTER_READONLY },
  { "debug",          0x05, AUXREG_AC, ARC_REGISTER_READONLY },
  { "pc",             0x06, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32",       0xa, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32_l1",    0xb, AUXREG_AC, 0 },
  { "status32_l2",    0xc, AUXREG_AC, 0 },
  { "int_vector_base",0x25, AUXREG_AC, 0 },
  { "aux_irq_lv12" ,  0x43, AUXREG_AC, 0 },
  /* Optional extension auxiliary registers */
  /* START ARC LOCAL */
  /* Data Cache Flush */
  { "dc_startr",      0x4d, AUXREG_AC, 0 },
  { "dc_endr",        0x4e, AUXREG_AC, 0 },
  /* Time Stamp Counter */
  { "tsch",           58,   REG_AC, 0 },
  /* END ARC LOCAL */
  { "multiply_build", 0x7b, AUXREG_AC, ARC_REGISTER_READONLY },
  { "swap_build",     0x7c, AUXREG_AC, ARC_REGISTER_READONLY },
  { "norm_build",     0x7d, AUXREG_AC, ARC_REGISTER_READONLY },
  { "barrel_build",   0x7f, AUXREG_AC, ARC_REGISTER_READONLY },
  { "aux_irq_lev", 0x200,AUXREG_AC,0 },
  { "aux_irq_hint",0x201,AUXREG_AC, 0 },
  /* Some Tazer specific auxillary registers */
  { "eret",   0x400, AUXREG_AC, 0 }, /* Exception Return Address */
  { "erbta",  0x401, AUXREG_AC, 0}, /* Exception Return Branch Target Address */
  { "erstatus", 0x402,AUXREG_AC, 0},/* Exception Return Status */
  { "ecr" , 0x403, AUXREG_AC, 0 } , /* Exception Cause Register */
  { "efa" , 0x404, AUXREG_AC, 0 } , /* Exception Fault Address */
  /* Level 1 Interrupt Cause */
  { "icause1", 0x40A, AUXREG_AC, ARC_REGISTER_READONLY } ,
  /* Level 2 Interrupt Cause */
  { "icause2", 0x40B, AUXREG_AC, ARC_REGISTER_READONLY } ,

  { "auxienable",0x40C, AUXREG_AC, 0 } , /* Interrupt Mask Programming */
  { "auxitrigger",0x40D, AUXREG_AC, 0} , /* Interrupt Sensitivity Programming */
  { "xpu" , 0x410, AUXREG_AC, 0 } , /* User Mode Extension Enables */
  { "xpk" , 0x411, AUXREG_AC, 0 } , /* Kernel Mode Extension Enables */
  { "bta_l1" , 0x413, AUXREG_AC, 0} , /* Level 1 Return Branch Target */
  { "bta_l2" ,0x414, AUXREG_AC, 0 } , /* Level 2 Return Branch Target */
  /* Interrupt Edge Cancel */
  { "aux_irq_edge_cancel",0x415,AUXREG_AC,  ARC_REGISTER_WRITEONLY } ,
  /* Interrupt Pending Cancel */
  { "aux_irq_pending" , 0x416,AUXREG_AC, ARC_REGISTER_READONLY},

  /* Build Control Registers */
  /* DCCM BCR */
  { "dccm_base_build_bcr", 0x61, AUXREG_AC, ARC_REGISTER_READONLY},
  { "DCCM_BASE_BUILD_BCR", 0x61, AUXREG_AC, ARC_REGISTER_READONLY},
  /* CRC Build BCR */
  { "crc_build_bcr", 0x62, AUXREG_AC, ARC_REGISTER_READONLY},
  { "CRC_BUILD_BCR", 0x62, AUXREG_AC, ARC_REGISTER_READONLY},
  /* BTA Build BCR Signifies the presence of BTA_L1/ L2 registers */
  { "bta_link_build", 0x63,AUXREG_AC, ARC_REGISTER_READONLY},
  { "BTA_LINK_BUILD", 0x63,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Dual Viterbi Butterfly BCR . Signifies presence of that instruction*/
  { "DVBF_BUILD",0x64,AUXREG_AC, ARC_REGISTER_READONLY},
  { "dvbf_build",0x64,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Extended Arithmetic Instructions are present */
  { "tel_instr_build",0x65,AUXREG_AC, ARC_REGISTER_READONLY},
  { "TEL_INSTR_BUILD",0x65,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Memory Subsystem BCR Information regarding the endian-ness etc. */
  { "memsubsys",0x67,AUXREG_AC, ARC_REGISTER_READONLY},
  { "MEMSUBSYS",0x67,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Interrupt vector base register */
  {"vecbase_ac_build",0x68,AUXREG_AC, ARC_REGISTER_READONLY},
  {"VECBASE_AC_BUILD",0x68,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Peripheral base address register */
  { "p_base_addr",0x69,AUXREG_AC, ARC_REGISTER_READONLY},
  { "P_BASE_ADDR",0x69,AUXREG_AC, ARC_REGISTER_READONLY},
  /* MMU BCR . Specifies the associativity of the TLB etc. */
  {"mmu_build",0x6F,AUXREG_AC, ARC_REGISTER_READONLY},
  {"MMU_BUILD",0x6F,AUXREG_AC, ARC_REGISTER_READONLY},
  /* ARC Angel BCR . Specifies the version of the ARC Angel Dev. Board */
  { "arcangel_build",0x70,AUXREG_AC, ARC_REGISTER_READONLY},
  { "ARCANGEL_BUILD",0x70,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Data Cache BCR . Associativity/Line Size/ size of the Data Cache etc. */
  {"dcache_build",0x72,AUXREG_AC, ARC_REGISTER_READONLY},
  {"DCACHE_BUILD",0x72,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Information regarding multiple arc debug interfaces */
  {"madi_build",0x73,AUXREG_AC, ARC_REGISTER_READONLY},
  {"MADI_BUILD",0x73,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for data closely coupled memory */
  {"dccm_build",0x74,AUXREG_AC, ARC_REGISTER_READONLY},
  {"DCCM_BUILD",0x74,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for timers */
  {"timer_build",0x75,AUXREG_AC, ARC_REGISTER_READONLY},
  {"TIMER_BUILD",0x75,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Actionpoints build */
  {"ap_build",0x76,AUXREG_AC, ARC_REGISTER_READONLY},
  {"AP_BUILD",0x76,AUXREG_AC, ARC_REGISTER_READONLY},
  /* Instruction Cache BCR */
  {"icache_build",0x77,AUXREG_AC, ARC_REGISTER_READONLY},
  {"ICACHE_BUILD",0x77,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for Instruction Closely Coupled Memory.
     Used to be BCR for Saturated ADD/SUB.
  */
  {"iccm_build",0x78,AUXREG_AC, ARC_REGISTER_READONLY},
  {"ICCM_BUILD",0x78,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for X/Y Memory */
  {"dspram_build",0x79,AUXREG_AC, ARC_REGISTER_READONLY},
  {"DSPRAM_BUILD",0x79,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for MAC / MUL */
  {"mac_build",0x7A,AUXREG_AC, ARC_REGISTER_READONLY},
  {"MAC_BUILD",0x7A,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for old 32 * 32 Multiply */
  {"multiply_build",0x7B,AUXREG_AC, ARC_REGISTER_READONLY},
  {"MULTIPLY_BUILD",0x7B,AUXREG_AC, ARC_REGISTER_READONLY},

  /* BCR for swap */
  {"swap_build",0x7C,AUXREG_AC, ARC_REGISTER_READONLY},
  {"SWAP_BUILD",0x7C,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR For Norm */
  {"norm_build",0x7D,AUXREG_AC, ARC_REGISTER_READONLY},
  {"NORM_BUILD",0x7D,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for Min  / Max instructions */
  {"minmax_build",0x7E,AUXREG_AC, ARC_REGISTER_READONLY},
  {"MINMAX_BUILD",0x7E,AUXREG_AC, ARC_REGISTER_READONLY},
  /* BCR for barrel shifter */
  {"barrel_build",0x7F,AUXREG_AC, ARC_REGISTER_READONLY},
  {"BARREL_BUILD",0x7F,AUXREG_AC, ARC_REGISTER_READONLY}

};

static const struct arc_operand_value arc_reg_names_em[] =
{
  /* Sort this so that the first 61 entries are sequential.
     IE: For each i (i<61), arc_reg_names[i].value == i.  */

  { "r0", 0, REG_AC, 0 }, { "r1", 1, REG_AC, 0 }, { "r2", 2, REG_AC, 0 },
  { "r3", 3, REG_AC, 0 }, { "r4", 4, REG_AC, 0 }, { "r5", 5, REG_AC, 0 },
  { "r6", 6, REG_AC, 0 }, { "r7", 7, REG_AC, 0 }, { "r8", 8, REG_AC, 0 },
  { "r9", 9, REG_AC, 0 },
  { "r10", 10, REG_AC, 0 }, { "r11", 11, REG_AC, 0 }, { "r12", 12, REG_AC, 0 },
  { "r13", 13, REG_AC, 0 }, { "r14", 14, REG_AC, 0 }, { "r15", 15, REG_AC, 0 },
  { "r16", 16, REG_AC, 0 }, { "r17", 17, REG_AC, 0 }, { "r18", 18, REG_AC, 0 },
  { "r19", 19, REG_AC, 0 }, { "r20", 20, REG_AC, 0 }, { "r21", 21, REG_AC, 0 },
  { "r22", 22, REG_AC, 0 }, { "r23", 23, REG_AC, 0 }, { "r24", 24, REG_AC, 0 },
  { "r25", 25, REG_AC, 0 }, { "r26", 26, REG_AC, 0 }, { "r27", 27, REG_AC, 0 },
  { "r28", 28, REG_AC, 0 }, { "r29", 29, REG_AC, 0 }, { "r30", 30, REG_AC, 0 },
  { "r31", 31, REG_AC, 0 },
  { "gp", 26, REG_AC, 0 }, { "fp", 27, REG_AC, 0 }, { "sp", 28, REG_AC, 0 },
  { "ilink", 29, REG_AC, 0 },
  { "blink", 31, REG_AC, 0 },
  { "r58", 58, REG_AC, 0 }, { "r59", 59, REG_AC, 0 },
  { "lp_count", 60, REG_AC, 0 }, { "r60", 60, REG_AC, 0 },
  { "pcl", 63, REG_AC, ARC_REGISTER_READONLY },
  { "r63", 63, REG_AC, ARC_REGISTER_READONLY },

  /* General Purpose Registers for ARCompact 16-bit insns */

  { "r0", 0, REG_AC, ARC_REGISTER_16 }, { "r1", 1, REG_AC, ARC_REGISTER_16 },
  { "r2", 2, REG_AC, ARC_REGISTER_16 }, { "r3", 3, REG_AC, ARC_REGISTER_16 },
  { "r12", 4, REG_AC, ARC_REGISTER_16 }, { "r13", 5, REG_AC, ARC_REGISTER_16 },
  { "r14", 6, REG_AC, ARC_REGISTER_16 }, { "r15", 7, REG_AC, ARC_REGISTER_16 },


    /* Standard auxiliary registers.  */
  { "identity",       0x04, AUXREG_AC, ARC_REGISTER_READONLY },
  { "pc",             0x06, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32",       0x0A, AUXREG_AC, ARC_REGISTER_READONLY },
  { "status32_p0",    0x0B, AUXREG_AC, ARC_REGISTER_READONLY },
  { "bta",            0x412, AUXREG_AC, 0},
  { "ecr",            0x403, AUXREG_AC, 0},
  { "int_vector_base",0x25, AUXREG_AC, 0},
  /*Saved exception and interrupt state*/
  { "aux_user_sp",    0x0D, AUXREG_AC, 0},
  { "eret",           0x400, AUXREG_AC, 0}, /* Exception Return Address */
  { "erbta",          0x401, AUXREG_AC, 0}, /* Exception Return Branch Target Address */
  { "erstatus",       0x402, AUXREG_AC, 0}, /* Exception Return Status */
  /*Build configuration registers*/
  { "bcr_ver",        0x60, AUXREG_AC, ARC_REGISTER_READONLY },
  { "bta_link_build", 0x63, AUXREG_AC, ARC_REGISTER_READONLY },
  { "vecbase_ac_build", 0x68, AUXREG_AC, ARC_REGISTER_READONLY },
  { "rf_build",       0x6E, AUXREG_AC, ARC_REGISTER_READONLY },
  { "isa_config",     0xC1, AUXREG_AC, ARC_REGISTER_READONLY },

  /*Optional aux registers*/
  /*Zero overhead loop aux regs*/
  { "lp_start",       0x02, AUXREG_AC, 0},
  { "lp_end",         0x03, AUXREG_AC, 0},
  /*Indexed table auxiliary register*/
  { "jli_base",       0x290, AUXREG_AC, 0},
  { "ldi_base",       0x291, AUXREG_AC, 0},
  { "ei_base",        0x292, AUXREG_AC, 0},
  /*Debug registers*/
  { "debug",          0x05, AUXREG_AC, ARC_REGISTER_READONLY },
  { "debugi",         0x1F, AUXREG_AC, ARC_REGISTER_READONLY },
  /*Extended exception state aux regs*/
  { "efa",            0x404, AUXREG_AC, 0 } , /* Exception Fault Address */
  /*Aux timer regs*/
  { "count0",         0x21, AUXREG_AC, 0},
  { "control0",       0x22, AUXREG_AC, 0},
  { "limit0",         0x23, AUXREG_AC, 0},
  { "count1",         0x100, AUXREG_AC, 0},
  { "control1",       0x101, AUXREG_AC, 0},
  { "limit1",         0x102, AUXREG_AC, 0},
  { "aux_rtc_ctrl",   0x103, AUXREG_AC, 0},
  { "aux_rtc_low",    0x104, AUXREG_AC, ARC_REGISTER_READONLY},
  { "aux_rtc_high",   0x105, AUXREG_AC, ARC_REGISTER_READONLY},
  /*User extension aux regs*/
  { "xpu" ,           0x410, AUXREG_AC, 0 } , /* User Mode Extension Enables */
  { "xflags" ,        0x44F, AUXREG_AC, 0 } ,
  /*Cache aux regs*/
  { "ic_ivic",        0x10, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "ic_ctrl",        0x11, AUXREG_AC, 0 } ,
  { "ic_lil",         0x13, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "ic_ivil",        0x19, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "ic_ram_addr",    0x1A, AUXREG_AC, 0 } ,
  { "ic_tag",         0x1B, AUXREG_AC, 0 } ,
  { "ic_data",        0x1D, AUXREG_AC, 0 } ,
  { "dc_ivdc",        0x47, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "dc_ctrl",        0x48, AUXREG_AC, 0 } ,
  { "dc_flsh",        0x4B, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "aux_cache_limit",0x209, AUXREG_AC, 0 },
  { "dc_ldl",         0x49, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "dc_ivdl",        0x4A, AUXREG_AC, ARC_REGISTER_WRITEONLY},
  { "dc_fldl",        0x4C, AUXREG_AC, ARC_REGISTER_WRITEONLY}
};



const struct arc_operand_value *arc_reg_names = arc_reg_names_a4;
int arc_reg_names_count;



/* The suffix table for ARCtangent-A4.
   Operands with the same name must be stored together.  */

static const struct arc_operand_value arc_suffixes_a4[] =
{
  /* Entry 0 is special, default values aren't printed by the disassembler.  */
  { "", 0, -1, 0 },
  { "al", 0, COND, 0 },
  { "ra", 0, COND, 0 },
  { "eq", 1, COND, 0 },
  { "z", 1, COND, 0 },
  { "ne", 2, COND, 0 },
  { "nz", 2, COND, 0 },
  { "p", 3, COND, 0 },
  { "pl", 3, COND, 0 },
  { "n", 4, COND, 0 },
  { "mi", 4, COND, 0 },
  { "c", 5, COND, 0 },
  { "cs", 5, COND, 0 },
  { "lo", 5, COND, 0 },
  { "nc", 6, COND, 0 },
  { "cc", 6, COND, 0 },
  { "hs", 6, COND, 0 },
  { "v", 7, COND, 0 },
  { "vs", 7, COND, 0 },
  { "nv", 8, COND, 0 },
  { "vc", 8, COND, 0 },
  { "gt", 9, COND, 0 },
  { "ge", 10, COND, 0 },
  { "lt", 11, COND, 0 },
  { "le", 12, COND, 0 },
  { "hi", 13, COND, 0 },
  { "ls", 14, COND, 0 },
  { "pnz", 15, COND, 0 },
  { "f", 1, FLAG, 0 },
  { "nd", ARC_DELAY_NONE, DELAY, 0 },
  { "d", ARC_DELAY_NORMAL, DELAY, 0 },
  { "jd", ARC_DELAY_JUMP, DELAY, 0 },
/*{ "b", 7, SIZEEXT },*/
/*{ "b", 5, SIZESEX },*/
  { "b", 1, SIZE1, 0 },
  { "b", 1, SIZE10, 0 },
  { "b", 1, SIZE22, 0 },
/*{ "w", 8, SIZEEXT },*/
/*{ "w", 6, SIZESEX },*/
  { "w", 2, SIZE1, 0 },
  { "w", 2, SIZE10, 0 },
  { "w", 2, SIZE22, 0 },
  { "x", 1, SIGN0, 0 },
  { "x", 1, SIGN9, 0 },
  { "a", 1, ADDRESS3, 0 },
  { "a", 1, ADDRESS12, 0 },
  { "a", 1, ADDRESS24, 0 },
  { "cc16", 16, COND, 0 },
  { "16", 16, COND, 0 },
  { "cc17", 17, COND, 0 },
  { "17", 17, COND, 0 },
  { "cc18", 18, COND, 0 },
  { "18", 18, COND, 0 },
  { "cc19", 19, COND, 0 },
  { "19", 19, COND, 0 },
  { "cc20", 20, COND, 0 },
  { "20", 20, COND, 0 },
  { "cc21", 21, COND, 0 },
  { "21", 21, COND, 0 },
  { "cc22", 22, COND, 0 },
  { "22", 22, COND, 0 },
  { "cc23", 23, COND, 0 },
  { "23", 23, COND, 0 },
  { "cc24", 24, COND, 0 },
  { "24", 24, COND, 0 },
  { "cc25", 25, COND, 0 },
  { "25", 25, COND, 0 },
  { "cc26", 26, COND, 0 },
  { "26", 26, COND, 0 },
  { "cc27", 27, COND, 0 },
  { "27", 27, COND, 0 },
  { "cc28", 28, COND, 0 },
  { "28", 28, COND, 0 },
  { "cc29", 29, COND, 0 },
  { "29", 29, COND, 0 },
  { "cc30", 30, COND, 0 },
  { "30", 30, COND, 0 },
  { "cc31", 31, COND, 0 },
  { "31", 31, COND, 0 },
  { "di", 1, CACHEBYPASS5, 0 },
  { "di", 1, CACHEBYPASS14, 0 },
  { "di", 1, CACHEBYPASS26, 0 },
};


/* The suffix table for ARCompact.
   Operands with the same name must be stored together.  */

static const struct arc_operand_value arc_suffixes_ac[] =
{
  /* Entry 0 is special, default values aren't printed by the disassembler.  */
  { "", 0, -1, 0 },
  { "al", 0, COND_AC, 0 },
  { "ra", 0, COND_AC, 0 },
  { "eq", 1, COND_AC, 0 },
  { "z", 1, COND_AC, 0 },
  { "ne", 2, COND_AC, 0 },
  { "nz", 2, COND_AC, 0 },
  { "p", 3, COND_AC, 0 },
#ifdef ARC_NPS_CMDS
  { "p", 3, PARITY_B24, 0 },
#endif
  { "pl", 3, COND_AC, 0 },
  { "n", 4, COND_AC, 0 },
  { "mi", 4, COND_AC, 0 },
  { "c", 5, COND_AC, 0 },
  { "cs", 5, COND_AC, 0 },
  { "lo", 5, COND_AC, 0 },
  { "nc", 6, COND_AC, 0 },
  { "cc", 6, COND_AC, 0 },
  { "hs", 6, COND_AC, 0 },
  { "v", 7, COND_AC, 0 },
  { "vs", 7, COND_AC, 0 },
  { "nv", 8, COND_AC, 0 },
  { "vc", 8, COND_AC, 0 },
  { "gt", 9, COND_AC, 0 },
  { "ge", 10, COND_AC, 0 },
  { "lt", 11, COND_AC, 0 },
  { "le", 12, COND_AC, 0 },
  { "hi", 13, COND_AC, 0 },
  { "ls", 14, COND_AC, 0 },
  { "pnz", 15, COND_AC, 0 },
  { "ss" , 16, COND_AC, 0 },
  { "sc" , 17, COND_AC, 0 },
#ifdef ARC_NPS_CMDS
  { "lb",  18, COND_AC, 0 },
  { "lb2", 19, COND_AC, 0 },
  { "olb",  20, COND_AC, 0 },
  { "nj",  21, COND_AC, 0 },
  { "at",  22, COND_AC, 0 },
  { "nm",  23, COND_AC, 0 },
  { "nt",  24, COND_AC, 0 },
#endif //   #ifdef ARC_NPS_CMDS
  { "f", 1, FLAG_AC, 0 },
  { "nd", ARC_DELAY_NONE, DELAY_AC, 0 },
  { "nd", ARC_DELAY_NONE, JUMP_DELAY_AC, 0 },
  { "d", ARC_DELAY_NORMAL, DELAY_AC, 0 },
  { "d", ARC_DELAY_NORMAL, JUMP_DELAY_AC, 0 },
  { "b", 1, SIZE1_AC, 0 },
  { "b", 1, SIZE7_AC, 0 },
  { "b", 1, SIZE17_AC, 0 },
  { "w", 2, SIZE1_AC, 0 },
  { "w", 2, SIZE7_AC, 0 },
  { "w", 2, SIZE17_AC, 0 },
  { "x", 1, SIGN6_AC, 0 },
  { "x", 1, SIGN16_AC, 0 },
  { "x", 1, EXP_BIT_23_AC32, 0 },
  { "a", 1, ADDRESS3_AC, 0 },
  { "a", 1, ADDRESS9_AC, 0 },
  { "a", 1, ADDRESS22_AC, 0 },
  { "aw", 1, ADDRESS3_AC, 0 },	/* This is to handle the st instr */
  { "aw", 1, ADDRESS9_AC, 0 },
  { "aw", 1, ADDRESS22_AC, 0 },
  { "ab", 2, ADDRESS3_AC, 0 },
  { "ab", 2, ADDRESS9_AC, 0 },
  { "ab", 2, ADDRESS22_AC, 0 },
  { "as", 3, ADDRESS3_AC, 0 },
  { "as", 3, ADDRESS9_AC, 0 },
  { "as", 3, ADDRESS22_AC, 0 },
  { "as", 3, ADDRESS22S_AC, 0 },
  { "di", 1, CACHEBYPASS5_AC, 0 },
  { "di", 1, CACHEBYPASS11_AC, 0 },
#ifdef ARC_NPS_CMDS
  { "di", 1, CACHEBYPASS15_AC, 0 },
  { "di", 1, DI_B03_AC32, 0 },
  { "s",  1, S_B13_AC16, 0 },
  { "e",  1, EQUAL_BD1_AC32, 0 },
  { "e",  3, EQUAL_BD3_AC32, 0 },
  { "m",  1, MERGE_BDCP_AC32, 0 },
  { "m",  1, M_B07_AC16, 0 },
  { "na", 1, NO_ALLOC_B9, 0 },
  { "na", 1, NO_ALLOCATE_BIT_27_AC32, 0 },
  { "na", 1, NO_ALLOCATE_BIT_24_AC32, 0 },
  { "sx", 1, SIGN_EXT_B14_AC16, 0 },
  { "cl", 1, CLEAR_B15_AC16, 0 },
  { "cl", 1, CLEAR_MOV4B_AC48, 0 },
  { "cl", 1, CLEAR_B31_AC32, 0 },
  { "xd", 1, TYPE_B14_AC16, 0 },
  { "r", 1, REFLECT_B15_AC32, 0 },
#else
  { "di", 1, CACHEBYPASS15_AC, 0 },
#endif // #ifdef ARC_NPS_CMDS
#ifdef NPS_ARCv2
  /*ARCv2 specific*/
  { "nt", 0, ARCV2_TFLAG, 0},
  { "t", 1, ARCV2_TFLAG, 0},
#endif // #ifdef NPS_ARCv2
  { "h", 2, SIZE1_AC, 0 },
  { "h", 2, SIZE7_AC, 0 },
  { "h", 2, SIZE17_AC, 0 }
};


const struct arc_operand_value *arc_suffixes = arc_suffixes_a4;
int arc_suffixes_count;

/* Indexed by first letter of opcode.  Points to chain of opcodes with same
   first letter.  */
static struct arc_opcode *opcode_map[26 + 1];

/* Indexed by insn code.  Points to chain of opcodes with same insn code.  */
static struct arc_opcode *icode_map[32];


/* -------------------------------------------------------------------------- */
/*                            externally visible functions                    */
/* -------------------------------------------------------------------------- */

/* Translate a bfd_mach_arc_xxx value to a ARC_MACH_XXX value.  */

int
arc_get_opcode_mach (int bfd_mach, int big_p)
{
  static int mach_type_map[] =
    {
      ARC_MACH_ARC4,
      ARC_MACH_ARC5,
      ARC_MACH_ARC6,
      ARC_MACH_ARC7,
      ARC_MACH_ARC601,
      ARC_MACH_ARCV2,
      ARC_MACH_ARCV2 | ARC_MACH_ARCV2HS
    };

  return mach_type_map[bfd_mach] | (big_p ? ARC_MACH_BIG : 0);
}


/* Initialize any tables that need it.
   Must be called once at start up (or when first needed).

   FLAGS is a set of bits that say what version of the cpu we have,
   and in particular at least (one of) ARC_MACH_XXX.  */

void
arc_opcode_init_tables (int flags)
{
  static int init_p = 0;

  /* If initialization was already done but current cpu type is different
     from the one for which initialization was done earlier, then do
     initialization again */
  if (init_p && cpu_type != flags)
    init_p = 0;

  cpu_type = flags;

  /* We may be intentionally called more than once (for example gdb will call
     us each time the user switches cpu).  These tables only need to be init'd
     once though.  */
  /* ??? We can remove the need for arc_opcode_supported by taking it into
     account here, but I'm not sure I want to do that yet (if ever).  */
  if (!init_p)
    {
      int i;

      /* Initialize operand map table for ARCompact */
      memset (arc_operand_map_ac, 0, sizeof (arc_operand_map_ac));

      for (i = 0; i < (int) ELEMENTS_IN (arc_operands_ac); ++i)
        {
          /*Just make sure that no strange number is comming through*/
          assert(arc_operands_ac[i].fmt < 512);
          arc_operand_map_ac[arc_operands_ac[i].fmt] = i;
        }

      /* Set the pointers to operand table, operand map table */
      arc_operands = arc_operands_ac;
      arc_operand_map = arc_operand_map_ac;

      /* Codito :: Ideally all the checking should be on this
         basis and not on flags shared across the libraries as seems
         to be the case for A4. Would have to check that and test
         it at some point in time.
      */
      if (ARC_OPCODE_CPU(flags) == ARC_MACH_ARC7)
        {
          arc_reg_names       = arc_reg_names_a700;
          arc_reg_names_count = ELEMENTS_IN(arc_reg_names_a700);
        }
      else if (ARC_OPCODE_CPU(flags) & ARC_MACH_ARCV2)
        {
          arc_reg_names       = arc_reg_names_em;
          arc_reg_names_count = ELEMENTS_IN(arc_reg_names_em);
        }
      else
        {
          arc_reg_names       = arc_reg_names_a500600;
          arc_reg_names_count = ELEMENTS_IN(arc_reg_names_a500600);
        }
      arc_suffixes       = arc_suffixes_ac;
      arc_suffixes_count = ELEMENTS_IN(arc_suffixes_ac);

      memset (opcode_map, 0, sizeof (opcode_map));
      memset (icode_map,  0, sizeof (icode_map));

      /* Scan the table backwards so macros appear at the front.  */
      for (i = ELEMENTS_IN(arc_opcodes) - 1; i >= 0; --i)
	{
	  int opcode_hash = ARC_HASH_OPCODE (arc_opcodes[i].syntax);
	  int icode_hash = ARC_HASH_ICODE (arc_opcodes[i].value);

	  arc_opcodes[i].next_asm = opcode_map[opcode_hash];
	  opcode_map[opcode_hash] = &arc_opcodes[i];

	  arc_opcodes[i].next_dis = icode_map[icode_hash];
	  icode_map[icode_hash] = &arc_opcodes[i];
	}

      init_p = 1;
    }
}


/* Return non-zero if OPCODE is supported on the specified cpu.
   Cpu selection is made when calling `arc_opcode_init_tables'.  */

int
arc_opcode_supported (const struct arc_opcode *opcode)
{
  if (ARC_OPCODE_CPU (opcode->flags) == 0)
    return 1;
  if (ARC_OPCODE_CPU (opcode->flags) & ARC_HAVE_CPU (cpu_type))
    return 1;
  return 0;
}


/* Return non-zero if OPVAL is supported on the specified cpu.
   Cpu selection is made when calling `arc_opcode_init_tables'.  */

int
arc_opval_supported (const struct arc_operand_value *opval ATTRIBUTE_UNUSED)
{
#if 0 /* I'm leaving this is a place holder, we don't discrimnate */
  if (ARC_OPVAL_CPU (opval->flags) == 0)
    return 1;
  if (ARC_OPVAL_CPU (opval->flags) & ARC_HAVE_CPU (cpu_type))
    return 1;
  return 0;
#endif
  return(1);
}


/* Return the first insn in the chain for assembling INSN.  */

const struct arc_opcode *
arc_opcode_lookup_asm (const char *insn)
{
  return opcode_map[ARC_HASH_OPCODE (insn)];
}


/* Return the first insn in the chain for disassembling INSN.  */

const struct arc_opcode *
arc_opcode_lookup_dis (unsigned int insn)
{
  return icode_map[ARC_HASH_ICODE (insn)];
}

/* START ARC LOCAL */
int 
arc_test_wb (void)
{
  return addrwb_p;
}
/* END ARC LOCAL */

/* Called by the assembler before parsing an instruction.  */

void
arc_opcode_init_insert (void)
{
  int i;

  for(i = 0; i < OPERANDS; i++)
    ls_operand[i] = OP_NONE;

  flag_p = 0;
  flagshimm_handled_p = 0;
  arc_cond_p = 0;
  addrwb_p = 0;
  shimm_p = 0;
  limm_p = 0;
  jumpflags_p = 0;
  nullify_p = 0;
  nullify = 0; /* The default is important.  */
#ifdef ARC_NPS_CMDS
  limm = 0;
  extraData = 0;
  extraData16Value = 0;
  flag335 = 0;
#endif // #ifdef ARC_NPS_CMDS
}


/* Called by the assembler to see if the insn has a limm operand.
   Also called by the disassembler to see if the insn contains a limm.  */

int
arc_opcode_limm_p (long *limmp)
{
  if (limmp)
    *limmp = limm;
  return limm_p;
}


/* Utility for the extraction functions to return the index into
   `arc_suffixes'.  */

const struct arc_operand_value *
arc_opcode_lookup_suffix (const struct arc_operand *type, int value)
{
  const struct arc_operand_value *v,*end;
  struct arc_ext_operand_value *ext_oper = arc_ext_operands;

  while (ext_oper)
    {
    if (type == &arc_operands[ext_oper->operand.type]
         && value == ext_oper->operand.value)
      return (&ext_oper->operand);
    ext_oper = ext_oper->next;
    }

  /* ??? This is a little slow and can be speeded up.  */
  for (v = arc_suffixes, end = arc_suffixes + arc_suffixes_count; v < end; ++v)
    if (type == &arc_operands[v->type]
	&& value == v->value)
      return v;
  return 0;
}



/* Ravi:  warning: function declaration isn't a prototype */
int arc_insn_is_j(arc_insn);
int ac_lpcc_insn(arc_insn insn);
int ac_add_reg_sdasym_insn(arc_insn);
int ac_get_load_sdasym_insn_type(arc_insn, int);
int ac_get_store_sdasym_insn_type(arc_insn, int);
int arc_insn_not_jl(arc_insn insn);
int arc_insn_is_j(arc_insn insn);
int ac_brk_s_insn(arc_insn insn);
int ac_branch_or_jump_insn(arc_insn insn, int compact_insn_16);
int ARC700_rtie_insn(arc_insn insn);


int
arc_insn_is_j (arc_insn insn)
{
  return (insn & (I(-1))) == I(0x7);
}


int
arc_insn_not_jl (arc_insn insn)
{
  return ((insn & (I(-1)|A(-1)|C(-1)|R(-1,7,1)|R(-1,9,1)))
	  != (I(0x7) | R(-1,9,1)));
}


/* Returns true if insn being encoded is a brk_s insn
   It can be used only for ARCompact architecture */
int
ac_brk_s_insn(arc_insn insn)
{
  return insn == 0x7fff;
}


/* Returns 1 if insn being encoded is either branch or jump insn.  It
   can be used only for ARCompact architecture.

   CZI: This procedure does not work for 16bit instructions due to
   definition of the I() macro.  */

int
ac_branch_or_jump_insn(arc_insn insn, int compact_insn_16)
{

  return ((!compact_insn_16 && ((insn & I(-1)) == I(0x4)) &&
			       (((insn >> 18) & 0xf) == 0x8)) ||
	  (compact_insn_16 && ((insn & I(-1)) == I(0xf))) ||
	  (!compact_insn_16 && ((insn & I(-1)) == I(0x1))) ||
	  (compact_insn_16 && ((insn & I(-1)) == I(0x1f))) ||
	  (!compact_insn_16 && ((insn & I(-1)) == I(0x0))) ||
	  (compact_insn_16 && ((insn & I(-1)) == I(0x1e))));
}

/* Returns 1 if the insn is a J_S.D or JL_S.D. It should work for
   ARCompact and ARC EM architectures*/
unsigned char
em_jumplink_or_jump_insn(arc_insn insn, int compact_insn16)
{

  /*J_S.D [b] */
  if ( (0xF8FF & insn) == 0x7820)
    return compact_insn16?1:0;
  /*J_S.D [blink] */
  if ( (0xFFFF & insn) == 0x7FE0)
    return compact_insn16?1:0;
  /*JL_S.D [b] */
  if ( (0xF8FF & insn) == 0x7860)
    return compact_insn16?1:0;

  return 0;
}

/* Returns 1 if the insn is a J_S, JL_S, JEQ_S, JNE_S. It should work
   for both ARCompact and ARC EM architectures */
unsigned char
em_branch_or_jump_insn(arc_insn insn, int compact_insn16)
{
#define MAJOR16(x) (((unsigned) (x) & 31) << 11)
#define SOPCOD2(x) (((unsigned) (x) & 7) << 5)
#define SOPCOD3(x) (((unsigned) (x) & 7) << 8)

  return ((compact_insn16 && (((insn & MAJOR16(-1)) == MAJOR16(0x0F)) &&
			      ((insn & SOPCOD2(-1)) <= SOPCOD2(0x03) ||
			       ((insn & SOPCOD2(-1)) == SOPCOD2(0x07) &&
				(insn & SOPCOD3(-1)) >= SOPCOD3(0x04))) &&
			      ((insn & 0x1F) == 0x00)
			      )) ||
	  (compact_insn16 && ((insn & MAJOR16(-1)) == MAJOR16(0x1E))) || /*all 16bit cond branches + B_S*/
	  (compact_insn16 && ((insn & MAJOR16(-1)) == MAJOR16(0x1F))) || /*BL_S s13*/
	  (compact_insn16 && ((insn & MAJOR16(-1)) == MAJOR16(0x1D))) /* BREQ_S and BRNE_S*/
	  );

#undef SOPCOD3
#undef MAJOR16
#undef SOPCOD2
}

/* This function returns true if insn being encoded is an lpcc insn.
   Ideally, we should be doing this and the other checks using the opcode
   tables. */
int
ac_lpcc_insn(arc_insn insn)
{
    return ( ((insn & 0xfffff000) == 0x20a80000) ||
	     ((insn & 0xfffff020) == 0x20a80020));
}


/* This function returns true if insn being encoded is an add a,b,var@sda insn */
int
ac_add_reg_sdasym_insn (arc_insn insn)
{
  return ((insn & 0xf8ff0fc0) == 0x20000f80);
}


/* This function returns true if insn being encoded is an rtie insn. */
int
ARC700_rtie_insn (arc_insn insn)
{
  return insn == 0x242f003f;
}


/* This function returns the following values for the given insns
           Insn                 Returns
           ----                 -------
    ld.as r0, [gp, var@sda]       0
    ld/ldb/ldw r0, [gp, var@sda]  1
    ldw.as  r0, [gp, var@sda]     2

    ld_s r0, [gp, var@sda]        10
    ldb_ r0,  [gp, var@sda]       11
    ldw_s  r0, [gp, var@sda]      12

    Any other insn                -1

    compact_insn_16 => insn is a 16-bit ARCompact insn
*/
int
ac_get_load_sdasym_insn_type (arc_insn insn, int compact_insn_16)
{
  int load_type = -1;

  /* ld[b/w]_s */
  if (compact_insn_16)
    {
      switch (insn & 0xfe00)
	{
	  /* ld_s */
	case 0xc800:
	  load_type = 10;
	  break;

	  /* ldb_s */
	case 0xca00:
	  load_type = 11;
	  break;

	  /* ldw_s */
	case 0xcc00:
	  load_type = 12;
	  break;
	}
     if ((insn & 0xF818) == 0x5000)
	{
	  load_type = 13;
	}
    }
  else
    {
      /* ld/ldw/ldb */
      switch (insn & 0xf8000180)
	{
	  /* ld */
	case 0x10000000:
	  if (((insn>>9) & 3) == 3)
	    load_type = 0;
	  else
	    load_type = 1;
	  break;

	  /* ldw */
	case 0x10000100:
	  if (((insn>>9) & 3) == 3)
	    load_type = 2;
	  else
	    load_type = 1;
	  break;

	  /* ldb */
	case 0x10000080:
	  load_type = 1;
	  break;

	}
    }

  return load_type;
}


/* This function returns the following values for the given insns
           Insn                 Returns
           ----                 -------
    st.as r0, [gp, var@sda]       0
    st/stb/stw r0, [gp, var@sda]  1
    stw.as  r0, [gp, var@sda]     2

    Any other insn                -1

     compact_insn_16 => insn is a 16-bit ARCompact insn
*/
int
ac_get_store_sdasym_insn_type (arc_insn insn,
			       int compact_insn_16)
{
  int store_type = -1;

  /* st_s r0,[gp,s11] */
  if (compact_insn_16)
    {
      if ((insn &  0xF818) == 0x5010)
	{
	  store_type = 3;
	}
    }
  else
    {
      /* st/stw/stb */
      switch (insn & 0xf8000007)
	{
	  /* st */
	case 0x18000000:
	  if (((insn>>3) & 3) == 3)
	    store_type = 0;
	  else
	    store_type = 1;
	  break;

	  /* stw */
	case 0x18000004:
	  if (((insn>>3) & 3) == 3)
	    store_type = 2;
	  else
	    store_type = 1;
	  break;

	  /* stb */
	case 0x18000002:
	  store_type = 1;
	  break;
	}
    }

  return store_type;
}

static int
ac_sdasym_limm_p (arc_insn insn)
{
  int short_insn = 0;

  if (ac_add_reg_sdasym_insn (insn))
    return 1;

  /* A crude way to check for short instructions.  */
  short_insn = (insn & 0xFFFF0000) ? 0 : 1;

  if ((ac_get_load_sdasym_insn_type (insn, short_insn) == -1)
      && (ac_get_store_sdasym_insn_type (insn, short_insn) == -1))
    return 1;

  return 0;
}

/* Returns 1 if the given operand is a valid constant operand for
   ARCompact ISA. It can be used only for ARCompact architecture */
int
ac_constant_operand (const struct arc_operand *op)
{
  switch (op->fmt)
    {
    case '@': /* This is valid only for A700 . The checks in the instruction patterns would take care of other checks.*/

    case 'u':
    case 'K':
    case 'L':
    case 'o':
    case 'd':
    case 'e':
    case 'E':
    case 'j':
    case 'J':
    case 'k':
    case 'l':
    case 'm':
    case 'M':
    case 'O':
    case 'R':
#ifndef ARC_NO_SIMD_CMDS
      /* Operands for the Aurora SIMD ISA*/
    case '?':
    case '\14':
    case '\20':
    case '\21':
    case '\22':
    case '\23':
    case '\24':
    case '\25':
#endif  // #ifndef ARC_NO_SIMD_CMDS
#ifdef NPS_ARCv2
      /* ARCv2 */
    case 132: /* W6 */
    case 133:
    case 134:
    case 135:
    case 136: /*u10 as in EI_S*/
    case 137: /*u7 as in LDI_S*/
    case 138: /*u7 as in LEAVE_S*/
    case 141: /*s11 as in ST_S*/
    case 142: /*u5 as in LD_S*/
    case '~': /*u2 as in DMB */
#endif /* #ifdef NPS_ARCv2 */
#ifdef ARC_NPS_CMDS
    case ')':
    case ']':
    case 0220 /*'\220'*/:
    case 0221 /*'\221'*/:
    case 0222 /*'\222'*/:
    case 0223 /*'\223'*/:
    case 0224 /*'\224'*/:
    case 0225 /*'\225'*/:
    case 0227 /*'\227'*/:
    case 0200 /*'\200'*/:
    case 0201 /*'\201'*/:
    case 0202 /*'\202'*/:
    case 0203 /*'\203'*/:
    case 0204 /*'\204'*/:
    case 0205 /*'\205'*/:
    case 0206 /*'\206'*/:
    case 0207 /*'\207'*/:
    case 0210 /*'\210'*/:
    case 0211 /*'\211'*/:
    case 0212 /*'\212'*/:
    case 0213 /*'\213'*/:
    case 0214 /*'\214'*/:
    case 0215 /*'\215'*/:
    case 0217 /*'\217'*/:
    case 0226 /*'\226'*/:
    case 0230 /*'\230'*/:
    case 0231 /*'\231'*/:
    case 0232 /*'\232'*/:
    case 0233 /*'\233'*/:
    case 0234 /*'\234'*/:
    case 0235 /*'\235'*/:
    case 0236 /*'\236'*/:
    case 0237 /*'\237'*/:
    case 0240 /*'\240'*/:
    case 0241 /*'\241'*/:
    case 0242 /*'\242'*/:
    case 0243 /*'\243'*/:
    case 0244 /*'\244'*/:
    case 0245 /*'\245'*/:
    case 0246 /*'\246'*/:
    case 0247 /*'\247'*/:
    case 0250 /*'\250'*/:
    case 0251 /*'\251'*/:
    case 0252 /*'\252'*/:
    case 0253 /*'\253'*/:
    case 0254 /*'\254'*/:
    case 0255 /*'\255'*/:
    case 0257 /*'\257'*/:
    case 0262 /*'\262'*/:
    case 0273 /*'\273'*/:
    case 0274 /*'\274'*/:
    case 0275 /*'\275'*/:
    case 0276 /*'\276'*/:
    case 0277 /*'\277'*/:
    case 0300 /*'\300'*/:
    case 0302 /*'\302'*/:
    case 0303 /*'\303'*/:
    case 0304 /*'\304'*/:
    case 0305 /*'\305'*/:
    case 0306 /*'\306'*/:
    case 0332 /*'\332'*/:
    case 0335 /*'\335'*/:
    case 0336 /*'\336'*/:
    case 0341 /*'\341'*/:
    case 0342 /*'\342'*/:
    case 0343 /*'\343'*/:
    case 0344 /*'\344'*/:
    case 0345 /*'\345'*/:
    case 0347 /*'\347'*/:
    case 0352 /*'\352'*/:
    case 0353 /*'\353'*/:
    case 0355 /*'\355'*/:
    case 0356 /*'\356'*/:
    case 0357 /*'\357'*/:
    case 0363 /*'\363'*/:
    case 0371 /*'\371'*/:
    case 0372 /*'\372'*/:
    case 0373 /*'\373'*/:
    case 0374 /*'\374'*/:
    case 0375 /*'\375'*/:
    case 0376 /*'\376'*/:
    case 0377 /*'\377'*/:
#endif // #ifdef ARC_NPS_CMDS

      return 1;
    }
    return 0;
}


#ifndef ARC_NO_SIMD_CMDS
/* Returns non-zero if the given operand is a valid register operand for
   the Aurora SIMD operand.  */
int
ARC700_register_simd_operand (char fmt)
{
  switch (fmt)
    {
    case '*':
    case '(':
    case ')':
      return 1; /*If the operand belongs to  the Vector register(Vrxx) set*/
    case '<':
    case '>':
      return 2; /*If the operand belongs to the DMA registers (DRxx) set*/
    case '\13':
    case '{':
    case '}':
      return 3; /*If the operand belongs to the Scalar register (Ixx) set*/
    case '\15':
    case '\16':
    case '\17':
      return 4; /*If the operand belongs to the Scalar register (Kxx) set*/
    }
  return 0;
}
#endif  // #ifndef ARC_NO_SIMD_CMDS


/* Returns 1 if the given operand is a valid register operand for
   ARCompact ISA. It can be used only for ARCompact architecture */
int
ac_register_operand (const struct arc_operand *op)
{
  switch (op->fmt)
    {
      case 'a':
      case 'b':
      case 'c':
      case 'A':
      case 'B':
      case '#':
      case 'C':
      case 'U':
      case 'g':
      case 'G':
      case 'r':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
      case '!':
#ifdef NPS_ARCv2
	/*ARCv2 specific FIXME! fix U*/
      case 128: /* H5 */
      case 129: /* R1 */
      case 130: /* R2 */
      case 131: /* R3 */
      case 140: /* G5 */
      case '=': /* A 64 */
      case '_': /* A 64 */
      case ';': /* A 64 */
#endif /* #ifdef NPS_ARCv2 */
#ifdef ARC_NPS_CMDS
      case '*':
      case 0270 /*'\270'*/:
      case 0271 /*'\271'*/:
      case 0272 /*'\272'*/:
      case 0310 /*'\310'*/:
      case 0311 /*'\311'*/:
      case 0312 /*'\312'*/:
#endif // #ifdef ARC_NPS_CMDS
        return 1;
    }
    return 0;
}


/* Returns 1 if the given operand is a valid symbol operand for ARCompact ISA */
int
ac_symbol_operand (const struct arc_operand *op)
{
  switch (op->fmt)
    {
      case 'L':
      case 'd':
      case 'h':
      case 'H':
      case 'i':
      case 'I':
      case 'y':
      case 'Y':
      case 's':
      case 'S':
      case 'Z':
      case 'W':
#ifdef ARC_NPS_CMDS
      case ']':
      case 0236 /*'\236'*/:
#endif // #ifdef ARC_NPS_CMDS
        return 1;
    }
  return 0;
}


int
arc_operand_type (int opertype)
{
  switch (opertype)
    {
    case 0:
      return (COND_AC);
    case 1:
      return (REG_AC);
    case 2:
      return (AUXREG_AC);
    default:
      abort();
    }
}


struct arc_operand_value *
get_ext_suffix (char *s, char field)
{
  struct arc_ext_operand_value *suffix = arc_ext_operands;
  char ctype;

  ctype = 0;
#ifdef ARC_NPS_CMDS
  switch(field & 0x0FF){
#else
  switch(field){
#endif
  case 'e' : 
      ctype = 0;
      break;
  case 'f' : 
      ctype = FLAG_AC;
      break;
  case 'j' : 
      ctype = 0;
      break;
  case 'p' : 
      ctype = ADDRESS9_AC;
      break;
  case 'q' : 
      ctype = COND_AC;
      break;
  case 't' : 
      ctype = SIZE7_AC;
      break;
  case 'v' : 
      ctype = CACHEBYPASS11_AC;
      break;
  case 'w' : 
      ctype = ADDRESS3_AC;
      break;
  case 'x' : 
      ctype = SIGN6_AC;
      break;
  case 'y' : 
      ctype = 0;
      break;
  case 'z' : 
      ctype = SIZE1_AC;
      break;
  case 'D' : 
      ctype = CACHEBYPASS5_AC;
      break;
  case 'E' : 
      ctype = 0;
      break;
  case 'P' : 
      ctype = ADDRESS22_AC;
      break;
  case 'T' : 
      ctype = SIZE17_AC;
      break;
  case 'V' : 
      ctype = CACHEBYPASS15_AC;
      break;
  case 'W' : 
      ctype = 0;
      break;
  case 'X' : 
      ctype = SIGN16_AC;
      break;
  case 'Z' : 
      ctype = 0;
      break;
  case '&' : 
      ctype = ADDRESS22S_AC;
      break;
#ifdef ARC_NPS_CMDS
  case '\15' :
      ctype = CLEAR_B15_AC16;
      break;
  case ')' :
      ctype = CLEAR_B31_AC32;
      break;
  case '\37' :
      ctype = CLEAR_MOV4B_AC48;
      break;
  case 0x8e /* '\216' */:
      ctype = M_B07_AC16;
      break;
  case 0xc7 /* '\307' */ :
      ctype = MERGE_BDCP_AC32;
      break;
  case 0xd1 /* '\321' */ :
	  ctype = NO_ALLOCATE_BIT_27_AC32;
  case 0xd2 /* '\322' */ :
	  ctype = NO_ALLOCATE_BIT_24_AC32;
	  break;
  case 0xd3 /* '\323' */ :
	  ctype = EXP_BIT_23_AC32;
	  break;
  case 0xcf /* '\317' */ :
      ctype = EQUAL_BD1_AC32;
      break;
  case 0xce /* '\316' */ :
      ctype = EQUAL_BD3_AC32;
      break;
  case 0xe6 /* '\346' */:
      ctype = NO_ALLOC_B9;
      break;
  case 0xe7 /* '\347' */:
      ctype = PARITY_B24;
      break;
  case 0xe8 /* '\350' */:
      ctype = S_B13_AC16;
      break;
  case 0xe9 /* '\351' */:
      ctype = DI_B03_AC32;
      break;
  case 0xf4 /* '\364' */:
      ctype = TYPE_B14_AC16;
      break;
  case 0xdf /* '\337' */:
      ctype = REFLECT_B15_AC32;
      break;
#endif // #ifdef ARC_NPS_CMDS
  default : 
      ctype = COND_AC;
      break;
  } /* end switch(field) */

  if(ctype == 0)
      ctype = COND_AC;

  while (suffix){
    if ((suffix->operand.type == ctype)
        && !strcmp(s,suffix->operand.name)){
	return(&suffix->operand);
      }
      suffix = suffix->next;
  } /* end while(suffix) */

  return NULL;
}


int
arc_get_noshortcut_flag (void)
{
  return ARC_REGISTER_NOSHORT_CUT;
}


char *
arc_aux_reg_name (int regVal)
{
  int i;

  for (i= arc_reg_names_count ; i > 0  ; i--)
    {
      if ((arc_reg_names[i].type == AUXREG_AC)
	  && (arc_reg_names[i].value == regVal ))
	return arc_reg_names[i].name;
    }

  return NULL;
}

#ifdef ARC_NPS_CMDS
int npsNonRelevant(char *s1,char *s2,int len)
{
	int k;
	if ( len == 0 ) return 1;
	k = strncmp(s1,s2,len);
	return k;
}

static inline int types_48_f(char *ptr)
{
	if ( (ptr[0] == ' ') || (ptr[0] == '.') ) return 1;
	if ( (ptr[0] == 'l') && ( (ptr[1] == ' ') || (ptr[1] == '.') ) ) return 1;
	return 0;
}

static inline int types_124_f(char *ptr)
{
	if ( (ptr[0] == ' ') || (ptr[0] == '.') ) return 1;
	if ( (ptr[0] == 'b') && ( (ptr[1] == ' ') || (ptr[1] == '.') ) ) return 1;
	if ( (ptr[0] == 'w') && ( (ptr[1] == ' ') || (ptr[1] == '.') ) ) return 1;
	if ( (ptr[0] == 'l') && ( (ptr[1] == ' ') || (ptr[1] == '.') ) ) return 1;
	return 0;
}

static inline int types_f(char *ptr)
{
	if ( (ptr[0] == ' ') || (ptr[0] == '.') ) return 1;
	return 0;
}

static inline int types_124(char *ptr)
{
	if (ptr[0] == ' ') return 1;
	if ( (ptr[0] == 'b') && (ptr[1] == ' ') ) return 1;
	if ( (ptr[0] == 'w') && (ptr[1] == ' ') ) return 1;
	return 0;
}

int isNPS16BitCmd(char *str)
{
	switch ( str[0] ) {
		case 'a':
		    switch ( str[2] ) {
		    	case 'a':
		    		if ( ( strncmp(str,"adadd",5) == 0) && ( types_48_f(&str[5]) != 0 ) ) return 5;
		    		break;
		    	case 'c':
					if ( ( strncmp(str,"adcb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
					if ( ( strncmp(str,"arcl",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
		    		break;
		    	case 'd':
		    		if ( ( strncmp(str,"aadd",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
					if ( ( strncmp(str,"addl",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
					if ( ( strncmp(str,"addb",4) == 0) && ( types_f(&str[4]) != 0 ) ) {
						if ( str[-1] != 'a' ) return 4; /* not relevant for 'aaddb' */
						break;
					}
					if ( ( strncmp(str,"andl",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
					if ( ( strncmp(str,"andab",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
					if ( ( strncmp(str,"andb",4) == 0) && ( types_f(&str[4]) != 0 ) ) {
						if ( str[-1] != 'a' ) return 4; /* not relevant for 'aandb' */
						break;
					}
					if ( ( strncmp(str,"ardc",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
		    		break;
		    	case 'i':
					if ( ( strncmp(str,"ari",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
					if ( ( strncmp(str,"aric",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
		    		break;
		    	case 'n':
					if ( ( strncmp(str,"aand",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
					break;
		    	case 'o':
					if ( ( strncmp(str,"axor",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
					break;
		    	case 'r':
		    		if ( ( strncmp(str,"aor",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
		    		break;
		    	case 's':
					if ( ( strncmp(str,"atst",4) == 0) && ( types_124_f(&str[4]) != 0 ) ) return 4;
					break;
				default:
					break;
		    }
			break;
		case 'b':
			if ( ( strncmp(str,"bdlen",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			break;
		case 'c':
			if ( ( strncmp(str,"cp16",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"cp32",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( strncmp(str,"cpssta ",7) == 0) return 6;
			if ( strncmp(str,"cpskey ",7) == 0) return 6;
			if ( strncmp(str,"cpsctx ",7) == 0) return 6;
			if ( strncmp(str,"cpsiv ",6) == 0) return 5;
			if ( strncmp(str,"cpsmac ",7) == 0) return 6;
			if ( ( strncmp(str,"cntbb",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			if ( ( strncmp(str,"calcsd",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
			if ( ( strncmp(str,"calcbsd",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
			if ( ( strncmp(str,"calckey",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
                        if ( ( strncmp(str,"cinit",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cminit",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"crd",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
                        if ( ( strncmp(str,"cwrdb",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cwrde",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"crst",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"cincr",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cdecr",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cincr1",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"cdecr1",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"cdecrc",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"cdincr",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"cbset",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cbclr",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cbwr",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"cbrd",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"cbcswp",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( strncmp(str,"cftch.di ",8) == 0) return 8;
                        if ( ( strncmp(str,"cgetc",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cchkc",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"cld",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
                        if ( ( strncmp(str,"cmld",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"cst",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
                        if ( ( strncmp(str,"cmst",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"cwcfg",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			if ( ( strncmp(str,"cwchk",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			break;
		case 'd':
			if ( ( strncmp(str,"div",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
    		if ( ( strncmp(str,"divm",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"decode",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
#if 1 /* only test for Gal */
			if ( ( strncmp(str,"decode1",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
#endif
			if ( ( strncmp(str,"decr",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			break;
		case 'e':
			if ( ( strncmp(str,"exc",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
			if ( ( strncmp(str,"ext4b",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			if ( ( strncmp(str,"encode",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
#if 1 /* only test for Gal */
			if ( ( strncmp(str,"encode0",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
			if ( ( strncmp(str,"encode1",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
#endif
			if ( ( strncmp(str,"encr",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( strncmp(str,"expskey ",8) == 0) return 7;
			break;
		case 'f':
			if ( ( strncmp(str,"fxorb",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
#if 1 /* only test for Gal */
			if ( ( strncmp(str,"fbset",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			if ( ( strncmp(str,"fbclr",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
#endif
			break;
                case 'g':
                        if ( ( strncmp(str,"gcm",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
			if ( ( strncmp(str,"gensiv",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        break;
                case 'h':
                        if ( ( strncmp(str,"hmac",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        break;
		case 'i':
			if ( ( strncmp(str,"ins4b",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			if ( ( strncmp(str,"imxb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			break;
    	case 'm':
			if ( strncmp(str,"mov",3) == 0) {
				switch ( str[3] ) {
			        case 'b':   // movb & movh & movl
			        	if ( ( strncmp(str,"movbi",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			        case 'h':
			        case 'l':
			        	if ( ( str[4] == ' ' ) || ( str[4] == '.' ) ) return 4; break;
			        case '2': // mov2b &mov3b & mov4b
			        case '3':
			        case '4':
			        	if ( str[4] == 'b' ) return 5; break;
				}
				break;
			}
			if ( ( strncmp(str,"mcmp",4) == 0)  && ( types_f(&str[4]) != 0 ) )return 4;
			if ( ( strncmp(str,"mrgb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"mod",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
			if ( ( strncmp(str,"mxb",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
			break;

		case 'n':
			if ( ( strncmp(str,"notb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			break;
		case 'o':
			if ( ( strncmp(str,"orl",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
			if ( ( strncmp(str,"orab",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"orb",3) == 0) && ( types_f(&str[3]) != 0 ) ) {
			    if ( str[-1] != 'a' ) return 3; /* not relevant for 'aorb' */
			    break;
		    }
			break;
                case 'p':
                        if ( ( strncmp(str,"pcinit",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"pcincr",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"pcdecr",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"pccl",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
                        if ( ( strncmp(str,"pcrprt",6) == 0) && ( types_f(&str[6]) != 0 ) ) return 6;
                        if ( ( strncmp(str,"pcrcycl",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
                        if ( ( strncmp(str,"pcdincr",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
                        if ( ( strncmp(str,"pcdcl",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
                        if ( ( strncmp(str,"pcdrprt",7) == 0) && ( types_f(&str[7]) != 0 ) ) return 7;
                        if ( ( strncmp(str,"pcdrcycl",8) == 0) && ( types_f(&str[8]) != 0 ) ) return 8;
                        break;
		case 'q':
			if ( strncmp(str,"qcmp.",5) == 0) return 4;
			break;
		case 's':
			if ( ( strncmp(str,"subl",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"subb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"sbcb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"shrb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"shlb",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
			if ( ( strncmp(str,"shash",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			break;
		case 'u':
			if ( ( strncmp(str,"uip",3) == 0) && ( types_f(&str[3]) != 0 ) ) return 3;
			//if ( strncmp(str,"uip ",3) == 0) return 3;
			break;
		case 'w':
			if ( ( strncmp(str,"wxorb",5) == 0) && ( types_f(&str[5]) != 0 ) ) return 5;
			break;
		case 'x':
			switch(str[1]) {
				case 'e':
					if ( ( strncmp(str,"xex",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
					break;
				case 'l':
					if ( ( strncmp(str,"xld",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
					break;
				case 'o':
					if ( ( strncmp(str,"xorb",4) == 0) && ( types_f(&str[4]) != 0 ) ) {
					    char c = str[-1];
						if ( ( c != 'a' ) && ( c != 'f' ) && ( c != 'w' ) ) return 4; /* not relevant for 'axorb','fxorb','wxorb' */
					    break;
				    }
					if ( ( strncmp(str,"xorl",4) == 0) && ( types_f(&str[4]) != 0 ) ) return 4;
					break;
				case 's':
					if ( ( strncmp(str,"xst",3) == 0) && ( types_124_f(&str[3]) != 0 ) ) return 3;
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
	return 0;
}
#endif //#ifdef ARC_NPS_CMDS
