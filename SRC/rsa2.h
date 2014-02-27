/*
	rsa2.H - RSAEURO define

	Copyright (c) J.S.A.Kapp 1994 - 1995.

	RSAEURO - RSA Library compatible with RSAREF(tm) 2.0.

	All functions prototypes are the Same as for RSAREF(tm).
	To aid compatiblity the source and the files follow the
	same naming comventions that RSAREF(tm) uses.  This should aid
	direct importing to your applications.

	This library is legal everywhere outside the US.  And should
	NOT be imported to the US and used there.

	All Trademarks Acknowledged.

	Global types and contants file.

	Revision 1.00 - JSAK 23/6/95, Final Release Version
*/

#ifndef _NN_H_
#define _NN_H_

#include "global.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef UINT4 NN_DIGIT;
typedef UINT2 NN_HALF_DIGIT;

#define MAX_RSA_MODULUS_BITS 2048
#define MAX_RSA_MODULUS_LEN ((MAX_RSA_MODULUS_BITS + 7) / 8)

#define NN_DIGIT_BITS 32
#define NN_HALF_DIGIT_BITS 16
#define NN_DIGIT_LEN (NN_DIGIT_BITS / 8)
#define MAX_NN_DIGITS \
  ((MAX_RSA_MODULUS_LEN + NN_DIGIT_LEN - 1) / NN_DIGIT_LEN + 1)
#define MAX_NN_DIGIT 0xffffffff
#define MAX_NN_HALF_DIGIT 0xffff

#define NN_LT   -1
#define NN_EQ   0
#define NN_GT 1

#define LOW_HALF(x) ((x) & MAX_NN_HALF_DIGIT)
#define HIGH_HALF(x) (((x) >> NN_HALF_DIGIT_BITS) & MAX_NN_HALF_DIGIT)
#define TO_HIGH_HALF(x) (((NN_DIGIT)(x)) << NN_HALF_DIGIT_BITS)
#define DIGIT_MSB(x) (unsigned int)(((x) >> (NN_DIGIT_BITS - 1)) & 1)
#define DIGIT_2MSB(x) (unsigned int)(((x) >> (NN_DIGIT_BITS - 2)) & 3)

void NN_Decode PROTO_LIST
  ((NN_DIGIT *, unsigned int, unsigned char *, unsigned int));
void NN_Encode PROTO_LIST
  ((unsigned char *, unsigned int, NN_DIGIT *, unsigned int));

void NN_Assign PROTO_LIST ((NN_DIGIT *, NN_DIGIT *, unsigned int));
//void NN_AssignZero PROTO_LIST ((NN_DIGIT *, unsigned int));
void NN_Assign2Exp PROTO_LIST ((NN_DIGIT *, unsigned int, unsigned int));

NN_DIGIT NN_Add PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));
NN_DIGIT NN_Sub PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));
void NN_Mult PROTO_LIST ((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));
void NN_Div PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int, NN_DIGIT *,
		unsigned int));
NN_DIGIT NN_LShift PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, unsigned int, unsigned int));
NN_DIGIT NN_RShift PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, unsigned int, unsigned int));
NN_DIGIT NN_LRotate PROTO_LIST 
	((NN_DIGIT *, NN_DIGIT *, unsigned int, unsigned int));

void NN_Mod PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, unsigned int, NN_DIGIT *, unsigned int));
void NN_ModMult PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));
void NN_ModExp PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int, NN_DIGIT *,
		unsigned int));
void NN_ModInv PROTO_LIST
	((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));
void NN_Gcd PROTO_LIST ((NN_DIGIT *, NN_DIGIT *, NN_DIGIT *, unsigned int));

int NN_Cmp PROTO_LIST ((NN_DIGIT *, NN_DIGIT *, unsigned int));
int NN_Zero PROTO_LIST ((NN_DIGIT *, unsigned int));
unsigned int NN_Bits PROTO_LIST ((NN_DIGIT *, unsigned int));
unsigned int NN_Digits PROTO_LIST ((NN_DIGIT *, unsigned int));

#define NN_ASSIGN_DIGIT(a, b, digits) {NN_AssignZero (a, digits); a[0] = b;}
#define NN_EQUAL(a, b, digits) (! NN_Cmp (a, b, digits))
#define NN_EVEN(a, digits) (((digits) == 0) || ! (a[0] & 1))

void Rsa(unsigned char* Modul,unsigned int ModulLen,unsigned char* Exp,unsigned int ExpLen,unsigned char* DataIn,unsigned char* DataOut);

#define ByteOrder    1
#define MAX_NN_LEN 64
#define LOW_AHEAD    0
#define HIGH_AHEAD   1

#ifdef __cplusplus
}
#endif

#endif /* _NN_H_ */

