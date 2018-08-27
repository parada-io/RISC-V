#ifndef CPU_RV32G_H
#define CPU_RV32G_H

#include <stdint.h>


enum DATA_TYPE {
	BYTE=4, INTEGER=1
};


extern uint32_t     pc,
                    ri,
					csr,
                    fcsr,
                    pc_sincronous;      //apenas para fins de mostrar o pc na GUI de maneira sincrona



extern uint32_t		opcode,					// codigo da operacao
					rd,
					rs1,
					rs2,
					shamt,
					funct3,
					funct7,
					immI,
					immS,
					immSB,
					immU,
					immUJ,
					funct5,
					rl,
					aq;



void init();
void fetch ();
void debug_decode();
void dump_breg();
void dump_mem(int start, int end, char format);
int load_mem(const char *fn, int start);
void execute ();
void step();
void run();
uint32_t extend_signal(uint32_t data, uint32_t pos_MSB);

#endif
