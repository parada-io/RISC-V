#ifndef SUBSET_A_H
#define SUBSET_A_H


enum A_OPCODES {

	OP_A = 0x2F,
	
};

enum A_FUNCT5 { 

	LR_W = 0X02, SC_W = 0X03,
	AMOSWAP_W = 0X01, AMOADD_W = 0X00,
	AMOXOR_W = 0X04, AMOAND_W = 0X0C,
	AMOOR_W = 0X08, AMOMIN_W = 0X10,
	AMOMAX_W = 0X14, AMOMINU_W = 0X18,
	AMOMAXU_W = 0X1C

};


void lr_w(uint32_t rs1);
void sc_w(uint32_t rs1);
void amoswap_w(uint32_t rs1, uint32_t rs2);
void amoadd_w(uint32_t rs1, uint32_t rs2);
void amoand_w(uint32_t rs1, uint32_t rs2);
void amoor_w(uint32_t rs1, uint32_t rs2);
void amoxor_w(uint32_t rs1, uint32_t rs2);
void amomax_w(uint32_t rs1, uint32_t rs2);
void amomin_w(uint32_t rs1, uint32_t rs2);
void amomaxu_w(uint32_t rs1, uint32_t rs2);
void amominu_w(uint32_t rs1, uint32_t rs2);

#endif