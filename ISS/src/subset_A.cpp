#include <iostream>
#include <stdint.h>
//#include <sys/types.h> 
#include "mem.h"
#include "subset_A.h"
#include "cpu_RV32G.h"
#include "subset_RV32I.h"


void lr_w(uint32_t rs1){

	breg[rd] = lw(breg[rs1], 0);
	reserved[breg[rs1]] = true;
	}

void sc_w(uint32_t rs1){

	if(reserved[breg[rs1]] == true){
		sw(breg[rs1], 0, breg[rs2]);
		breg[rs1] = 0;
	}
	else{
		breg[rs1] = 0xFAFAFAFA;
	}
}

void amoswap_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	sw(breg[rs1], 0, breg[rs2]);
	breg[rs2] = breg[rd];
}

void amoadd_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = breg[rs1] + breg[rs2];
	sw(breg[rs1], 0, breg[rd]);
}

void amoand_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = breg[rs1] & breg[rs2];
	sw(breg[rs1], 0, breg[rd]);
}

void amoor_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = breg[rs1] | breg[rs2];
	sw(breg[rs1], 0, breg[rd]);
}

void amoxor_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = breg[rs1] ^ breg[rs2];
	sw(breg[rs1], 0, breg[rd]);
}

void amomax_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = max(breg[rs1], breg[rs2]);
	sw(breg[rs1], 0, breg[rd]);
}

void amomin_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = min(breg[rs1], breg[rs2]);
	sw(breg[rs1], 0, breg[rd]);
}

void amomaxu_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = max((unsigned)breg[rs1], (unsigned)breg[rs2]);
	sw(breg[rs1], 0, breg[rd]);
}

void amominu_w(uint32_t rs1, uint32_t rs2){

	breg[rd] = lw(breg[rs1], 0);
	breg[rd] = min((unsigned)breg[rs1], (unsigned)breg[rs2]);
	sw(breg[rs1], 0, breg[rd]);
}