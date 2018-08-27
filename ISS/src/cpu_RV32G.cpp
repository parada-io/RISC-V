#include <iostream>
#include <cmath>
#include <stdint.h>
#include "stdio.h"
//#include <sys/types.h> 
#include "cpu_RV32G.h"
#include "subset_RV32I.h"
#include "subset_M.h"
#include "subset_A.h"
#include "subset_F.h"
#include "mem.h"


	void init() {

		pc = 0;
		ri = 0;
	}

	void fetch () {
		
		ri = lw(pc, 0);
        pc_sincronous = pc;
        pc = pc + 4;
		std::cout << "pc:" << std::hex << (pc - 4) << std::endl;
		std::cout << "ri:" << std::hex << ri << std::endl;	
	}

	void decode(){

		opcode = ri & 0x7F;
		rd = (ri >> 7) & 0x1F;
		funct3 = (ri >> 12) & 0x7;
		rs1 = (ri >> 15) & 0x1F;
		rs2 = (ri >> 20) & 0x1F;
		funct7 = (ri >> 25) & 0x7F;
		shamt = (ri >> 20) & 0x1F;
		rl = (ri >> 25) & 0x1;
		aq = (ri >> 26) & 0x1;
		funct5 = (ri >> 27) & 0x1F;

		immI = (ri >> 20) & 0xFFF; //extender sinal
		immI = extend_signal(immI, 11);
		immS = ((ri >> 7) & 0x1F) | ((ri >> 20) & 0xFE0); //extender sinal
		immS = extend_signal(immS, 11);
		immSB = ((ri >> 7) & 0x1E) | ((ri >> 20) & 0x7E0) | ((ri << 4) & 0x800) | ((ri >> 19) & 0x1000); // Extender Sinal
		immSB = extend_signal(immSB, 12);
		immU = ((ri >> 12) & 0xFFFFF);
        immUJ = ((ri >> 20) & 0x7FE) | ((ri >> 9) & 0x800) | (ri & 0xFF000) | ((ri >> 11) & 0x100000);
		immUJ = extend_signal(immUJ, 20);

		std::cout << "opcode:" << std::hex << opcode << std::endl;
		std::cout << "rd:" <<std::hex << rd << std::endl;
		std::cout << "rs1:" <<std::hex << rs1 << std::endl;
		std::cout << "rs2:" <<std::hex << rs2 << std::endl;
		std::cout << "funct3:" <<std::hex << funct3 << std::endl;
		std::cout << "funct7:" <<std::hex << funct7 << std::endl;
		std::cout << "funct5:" <<std::hex << funct5 << std::endl;
		std::cout << "shamt:" <<std::hex << shamt << std::endl;
		std::cout << "rl:" <<std::hex << rl << std::endl;
		std::cout << "aq:" <<std::hex << aq << std::endl;
		std::cout << "immI:" <<std::hex << immI << std::endl;
		std::cout << "immS:" <<std::hex << immS << std::endl;
		std::cout << "immSB:" <<std::hex << immSB << std::endl;
		std::cout << "immU:" <<std::hex << immU << std::endl;
		std::cout << "immUJ:" <<std::hex << immUJ << std::endl;
		

	}


	uint32_t extend_signal(uint32_t data, uint32_t pos_MSB){

		if(((data >> pos_MSB) & 0x1) == 1){
			return (data | 0xFFFFFFFF << pos_MSB);
		}
		else{
			return (data & 0xFFFFFFFF >> (31 - pos_MSB));
		}
	}


	//void debug_decode() {
	//	cout << "PC = " << pc << endl;
	//	cout << "opcode = " << opcode << " rs = " << rs << " rt = " << rt << " rd = " << rd << " shamt = " << shamt << " funct = " << funct << endl;
	//}


	void dump_breg() {
		printf("Banco de Registradores:\n");
		for (int i=0; i<32; i++) {
			printf("BREG[%2d] = \t%8d \t\t\t%8x\n", i, breg[i], breg[i]);
		}
	}


	void dump_mem(int start, int end, char format) {
		switch (format) {
			case 'h':
			case 'H':
				for (uint32_t i = start; i <= end; i+=4)
					printf("%x \t%x\n", i, lw(i, 0));
				break;
			case 'd':
			case 'D':
				for (int i = start; i <= end; i+=4)
					printf("%x \t%d\n", i, lw(i, 0));
				break;
			default:
			break;
		}
	}


	int load_mem(const char *fn, int start) {
		FILE *fptr;
		int *m_ptr = mem + (start>>2);  
		int size = 0;
	
		fptr = fopen(fn, "rb");

		if (!fptr) {
			printf("Arquivo nao encontrado!");
			return -1;
		}

		else {
			while (!feof(fptr)) {
				fread(m_ptr, 4, 1, fptr);
				std::cout << std::hex << mem[size] << std::endl;
				mem[size] = ((mem[size] & 0xFF000000) >> 24) | ((mem[size] & 0x00FF0000) >> 8) | ((mem[size] & 0x0000FF00) << 8) | ((mem[size] & 0x000000FF) << 24); //gambiarra para concertar endianess
				std::cout << std::hex << mem[size] << std::endl;
				m_ptr++;
				size++;
			}
			fclose(fptr);
		}
		return size;
	}


	void step() {

		breg[0] = 0;
		fetch();
		decode();
    	execute();
        breg[0] = 0;
	}


	void run() {
		
        //init();
		while (pc < DATA_SEGMENT_START) 
		step();
	}


	void execute(){

	int64_t u;
	char*c;

	breg[0] = 0;
	
	switch (opcode) {


		case(OP_BRANCH):
			switch(funct3){

                case(BEQ): if(breg[rs1] == breg[rs2]) pc += immSB;
                    std::cout << "foi BEQ" << std::endl;
				break;
                case(BNE): if(breg[rs1] != breg[rs2]) pc += immSB;
				break;
                case(BLT): if(breg[rs1] < breg[rs2]) pc += immSB;
				break;
                case(BGE): if(breg[rs1] >= breg[rs2]) pc += immSB;
				break;
                case(BLTU): if((unsigned)breg[rs1] < (unsigned)breg[rs2]) pc += immSB;
				break;
                case(BGEU): if((unsigned)breg[rs1] >= (unsigned)breg[rs2]) pc += immSB;
				break;
				default:break;
			}

		case(OP_LOAD):

			switch(funct3){
				case(LB): breg[rd] = lb(breg[rs1], immI);
				break;
				case(LH): breg[rd] = lh(breg[rs1], immI);
				break;
				case(LW): breg[rd] = lw(breg[rs1], immI);
				break;
				case(LBU): breg[rd] = lbu(breg[rs1], immI);
				break;
				case(LHU): breg[rd] = lhu(breg[rs1], immI);
				break;
				default:break;
			}

		case(OP_STORE):
			switch(funct3){
				case(SB): sb(breg[rs1], immS, breg[rs2]);
				break;
				case(SH): sh(breg[rs1], immS, breg[rs2]);
				break;
				case(SW): sw(breg[rs1], immS, breg[rs2]);
				break;
				default:break;
			}

		case(OP_IMM):
			switch(funct3){
				case(ADDI): breg[rd] = (breg[rs1] + immI);
				std::cout << "foi add_imediato!" << std::endl;
				std::cout << breg[rd] << std::endl;
				break;
				case(SLTI): breg[rd] = (breg[rs1] < immI);
				break;
				case(SLTIU): breg[rd] = ((unsigned)breg[rs1] < (unsigned)immI);
				break;
				case(XORI):	breg[rd] = breg[rs1] ^ immI;
				break;
				case(ORI): breg[rd] = breg[rs1] | immI;
				break;
				case(ANDI): breg[rd] = breg[rs1] & immI;
				break;
				case(SLLI): breg[rd] = breg[rs1] << shamt;
				break;
				case(SRLI_SRAI):
					switch(funct7){
						case(SRLI_7): breg[rd] = breg[rs1] >> (uint32_t)shamt;
						break;
						case(SRAI_7): breg[rd] = breg[rs1] >> shamt;
						break;
						default:break;
					}
				break;
				default:break;
			}
		break;
		case(OP_REG):
			if(funct7 == M_7){
				switch(funct3){
					case(MUL):
						u = breg[rs1]*breg[rs2];
						breg[rd] = (uint32_t)(u & 0xFFFFFFFF);
					break;
					case(MULH):
						u = breg[rs1]*breg[rs2];
						breg[rd] = (uint32_t)((u >> 32) & 0xFFFFFFFF);
					break;
					case(MULHSU):
						u = breg[rs1]*(unsigned)breg[rs2];
						breg[rd] = (uint32_t)((u >> 32) & 0xFFFFFFFF);
					break;
					case(MULHU):
						u = (unsigned)breg[rs1]*(unsigned)breg[rs2];
						breg[rd] = (uint32_t)((u >> 32) & 0xFFFFFFFF);
					break;
					case(DIV):
						breg[rd] = breg[rs1]/breg[rs2];
					break;
					case(DIVU):
						breg[rd] = (unsigned)breg[rs1]/(unsigned)breg[rs2];
					break;
					case(REM):
						breg[rd] = breg[rs1]%breg[rs2];
					break;
					case(REMU):
						breg[rd] = (unsigned)breg[rs1]%(unsigned)breg[rs2];
					break;
					default:break;
				}
			break;
			}
			else{
				switch(funct3){
					case(SLL): breg[rd] = breg[rs1] << (breg[rs2] & 0x1F);
					break;
					case(SLT): breg[rd] = (breg[rs1] < breg[rs2]);
					break;
					case(SLTU): breg[rd] = ((unsigned)breg[rs1] < (unsigned)breg[rs2]);
					break;
					case(XOR): breg[rd] = breg[rs1] ^ breg[rs2];
					break;
					case(OR): breg[rd] = breg[rs1] | breg[rs2];
					break;
					case(AND): breg[rd] = breg[rs1] & breg[rs2];
					break;
					case(ADD_SUB):
						switch(funct7){
							case(ADD_7): breg[rd] = breg[rs1] + breg[rs2];
							std::cout << "foi add!" << std::endl;
							std::cout << breg[rd] << std::endl;
							break;
							case(SUB_7): breg[rd] = breg[rs1] - breg[rs2];
							break;
						}
					break;
					case(SRL_SRA):
						switch(funct7){
							case(SRL_7): breg[rd] = breg[rs1] >> (uint32_t)(breg[rs2] & 0x1F);
							break;
							case(SRA_7): breg[rd] = breg[rs1] >> (breg[rs2] & 0x1F);
							break;
						}
					break;
					default:break;
				}
			break;
			}

		case(OP_FENCE):
			switch(funct3){
				case(FENCE):
				break;
				case(FENCE_I):
				break;
				default:break;
			}

		case(OP_CSR):
			switch(funct3){
				case(CSRRW): csrrw();
				break;
				case(CSRRS): csrrs();
				break;
				case(CSRRC): csrrc();
				break;
				case(CSRRWI):
				break;
				case(CSRRSI):
				break;
				case(CSRRCI):
				break;
				case(ECALL_EBREAK):
					switch(funct7){
						case(ECALL_7):
						break;
						case(EBREAK_7):
						break;
						default:break;
					}
				break;
				default:break;
			}

		case(OP_A):
			switch(funct5){
				case(LR_W): lr_w(breg[rs1]);
				break;
				case(SC_W): sc_w(breg[rs1]);
				break;
				case(AMOSWAP_W): amoswap_w(breg[rs1], breg[rs2]);
				break;
				case(AMOADD_W): amoadd_w(breg[rs1], breg[rs2]);
				break;
				case(AMOXOR_W): amoxor_w(breg[rs1], breg[rs2]);
				break;
				case(AMOAND_W): amoand_w(breg[rs1], breg[rs2]);
				break;
				case(AMOOR_W): amoor_w(breg[rs1], breg[rs2]);
				break;
				case(AMOMIN_W): amomin_w(breg[rs1], breg[rs2]);
				break;
				case(AMOMAX_W): amomax_w(breg[rs1], breg[rs2]);
				break;
				case(AMOMINU_W): amominu_w(breg[rs1], breg[rs2]);
				break;
				case(AMOMAXU_W): amomaxu_w(breg[rs1], breg[rs2]);
				break;
				default:break;
			}

		case(OP_F):
			switch(funct7){
				case(FADD_S_7): fp_breg[rd] = fp_breg[rs1] + fp_breg[rs2];
				break;
				case(FSUB_S_7): fp_breg[rd] = fp_breg[rs1] - fp_breg[rs2];
				break;
				case(FMUL_S_7): fp_breg[rd] = fp_breg[rs1]*fp_breg[rs2];
				break;
				case(FDIV_S_7): fp_breg[rd] = fp_breg[rs1] / fp_breg[rs2];
				break;
				case(FSQRT_S_7): fp_breg[rd] = sqrt(fp_breg[rs1]);
				break;
				case(FMINMAX_S_7):
					switch(funct3){
						case(FEQ_S): breg[rd] = (fp_breg[rs1] == fp_breg[rs2]);
						break;
						case(FLT_S): breg[rd] = (fp_breg[rs1] < fp_breg[rs2]);
						break;
						case(FLE_S): fp_breg[rd] = (fp_breg[rs1] <= fp_breg[rs2]);
						break;
						default:break;
					}
				break;
				case(FCOMPARE_7):
					switch(funct3){
						case(FMIN_S): fp_breg[rd] = min(fp_breg[rs1], fp_breg[rs2]);
						break;
						case(FMAX_S): fp_breg[rd] = max(fp_breg[rs1], fp_breg[rs2]);
						break;
						default:break;
					}
				break;
				case(FCVT_W_S_7): fp_breg[rd] = (float)breg[rs1];
				break;
				case(FCVT_S_W_7): breg[rd] = (uint32_t)fp_breg[rs1];
				break;
				default:break;
			}
		
		case(LUI): breg[rd] = (immU << 12);
		break;

        case(AUIPC):  breg[rd] = ((immU << 12) + (pc - 4));
		break;

        case(JAL): pc += (immUJ); (breg[rd] = (pc + 4));
		break;

		case(JALR): pc = ((immI + breg[rs1]) & 0xFFFFFFFE);
		break;
		
		default:
		std::cout << "foi default!" << std::endl;
		std::cout << std::endl;
		break;
	}
}

	
