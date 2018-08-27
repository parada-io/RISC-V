#ifndef SUBSET_F_H
#define SUBSET_F_H

#include <iostream>
using namespace std;



enum F_OPCODES {

	//subconjunto F
	OP_F = 0x53,

};

enum F_FUNCT3 { 

	//subconjnunto F
	FMIN_S = 0X0, FMAX_S = 0X1,
	FEQ_S = 0X2, FLT_S = 0X1,
	FLE_S = 0X0

};

enum F_FUNCT7 { 
	
	//subconjunto F
	FADD_S_7 = 0X00, FSUB_S_7 = 0X04,
	FMUL_S_7 = 0X08, FDIV_S_7 = 0X0C,
	FSQRT_S_7 = 0X2C, FMINMAX_S_7 = 0X14,
	FCOMPARE_7 = 0X50, FCVT_W_S_7 = 0X60,
	FCVT_S_W_7 = 0X68

};

enum FP_REGISTERS {

	f0 = 0, 	f1 = 1,		f2 = 2,		f3 = 3, 
	f4 = 4,		f5 = 5,		f6 = 6,		f7 = 7, 
	f8 = 8,		f9 = 9,		f10 = 10,	f11 = 11, 
	f12 = 12,	f13 = 13,	f14 = 14,	f15 = 15, 
	f16 = 16,	f17 = 17,	f18 = 18,	f19 = 19, 
	f20 = 20,	f21 = 21,	f22 = 22,	f23 = 23, 
	f24 = 24,	f25 = 25,	f26 = 26,	f27 = 27, 
	f28 = 28,	f29 = 29,	f30 = 30,	f31 = 31 

};

extern float fp_breg[32];


#endif