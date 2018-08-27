#include <iostream>
#include <stdint.h>
//#include <sys/types.h> 
#include "cpu_RV32G.h"
#include "subset_RV32I.h"


void csrrw(void){
	if(rs1 != ZERO){
		uint32_t transfer_aux = csr;
		csr = rs1;
		rs1 = transfer_aux;
	}
}

void csrrs(void){
	if(rs1 != ZERO){
		uint32_t transfer_aux = rs1;
		rs1 = csr;
		csr = rs1 | transfer_aux;
	}
}

void csrrc(void){
	if(rs1 != ZERO){
		uint32_t transfer_aux = rs1;
		rs1 = csr;
		csr = ~rs1 & transfer_aux;
	}
}


