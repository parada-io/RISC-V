#ifndef SUBSET_RV32I_H
#define SUBSET_RV32I_H

#include <iostream>
using namespace std;


enum RV32I_OPCODES {


	//rv32i
	LUI = 0x37, AUIPC = 0x17,
	JAL = 0x6F, JALR = 0x67,
	OP_BRANCH = 0X63, OP_LOAD = 0X03,
	OP_STORE = 0x23, OP_IMM = 0X13, 
	OP_REG = 0X33, OP_FENCE = 0X0F,
	OP_CSR = 0X73

/*
	LUI = 0x37, AUIPC = 0x17,
	JAL = 0x6F, JALR = 0x67,
	BEQ = 0x63, BNE = 0x63,
	BLT = 0x63, BGE = 0x63,
	BLTU = 0x63, BGEU = 0x63,
	LB = 0x03, LH = 0x03,
	LW = 0x03, LBU = 0x03,
	LHU = 0x03, SB = 0x03,
	SH = 0x03, SW = 0x03,
	ADDI = 0x13, SLTI = 0x13,
	SLTIU = 0x13, XORI = 0x13,
	ORI = 0x13, ANDI = 0x13,
	SLLI = 0x13, SRLI = 0x13,
	SRAI = 0x13, ADD = 0x33,
	SUB = 0x33, SLL = 0x33,
	SLT = 0x33, SLTU = 0x33,
	XOR = 0x33, SRL = 0x33,
	SRA = 0x33, OR = 0x33,
	AND = 0x33, FENCE = 0x0F,
	FENCE_I = 0X0F, ECALL = 0x73,
	EBREAK = 0x73, CSRRW = 0x73,
	CSRRS = 0x73, CSRRC = 0x73,
	CSRRWI = 0x73, CSRRSI = 0x73,
	CSRRCI = 0x73
*/	

};


enum RV32I_FUNCT3 { 

	//subconjunto RV32I	
	//JALR_3 = 0x0,
	BEQ = 0x0, BNE = 0x1,
	BLT = 0x4, BGE = 0x5,
	BLTU = 0x6, BGEU = 0x7,
	LB = 0x0, LH = 0x1,
	LW = 0x2, LBU = 0x4,
	LHU = 0x5, SB = 0x0,
	SH = 0x1, SW = 0x2,
	ADDI = 0x0, SLTI = 0x2,
	SLTIU = 0x3, XORI = 0x4,
	ORI = 0x6, ANDI = 0x7,
	SLLI = 0x1, SRLI_SRAI = 0x5,
	ADD_SUB = 0x0, SLL = 0x1,
	SLT = 0x2, SLTU = 0x3,
	XOR = 0x4, SRL_SRA = 0x5,
	OR = 0x6, AND = 0x7,
	FENCE = 0x0, FENCE_I = 0X1,
	ECALL_EBREAK = 0x0, CSRRW = 0x1, 
	CSRRS = 0x2, CSRRC = 0x3,
	CSRRWI = 0x5, CSRRSI = 0x6,
	CSRRCI = 0x7,

};

enum RV32I_FUNCT7 { 
	
	//subconjunto RV32I
	SLLI_7 = 0x00, SRLI_7 = 0x00,
	SRAI_7 = 0x20, ADD_7 = 0x00,
	SUB_7 = 0x20, SLL_7 = 0x00,
	SLT_7 = 0x00, SLTU_7 = 0x00,
	XOR_7 = 0x00, SRL_7 = 0x00,
	SRA_7 = 0x20, OR_7 = 0x00,
	AND_7 = 0x00, ECALL_7 = 0x00,
	EBREAK_7 = 0x01,

};



enum INT_REGISTERS {

	ZERO = 0, 	ra = 1,		sp = 2,		gp = 3, 
	tp = 4,		t0 = 5,		t1 = 6,		t2 = 7, 
	fp = 8,		s1 = 9,		a0 = 10,	a1 = 11, 
	a2 = 12,	a3 = 13,	a4 = 14,	a5 = 15, 
	a6 = 16,	a7 = 17,	s2 = 18,	s3 = 19, 
    s4 = 20,	s5 = 21,	s6 = 22,	S7 = 23,
    s8 = 24,	s9 = 25,	s10 = 26,	s11 = 27,
	t8 = 28,	t9 = 29,	t10 = 30,	t11 = 31 

};

extern int32_t breg[32];


void csrrw(void);
void csrrs(void);
void csrrc(void);

#endif


