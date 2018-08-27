#ifndef DEFS_H
#define DEFS_H
#define MEM_SIZE 20000

//cpu_RV32G
uint32_t 	pc,
			ri,						
			csr,
            fcsr,
            pc_sincronous;

uint32_t	opcode,					
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


//subset_RV32I
int32_t breg[32];

//subset_F
float fp_breg[32];

//memoria
int32_t mem[MEM_SIZE];
int32_t int_mem[MEM_SIZE];
bool reserved[MEM_SIZE];

#endif 
