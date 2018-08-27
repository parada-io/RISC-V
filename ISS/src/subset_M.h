#ifndef SUBSET_M_H
#define SUBSET_M_H

#include <iostream>
using namespace std;


enum M_FUNCT7 { 
	
	//subconjunto M
	M_7 = 0x01
	
};

enum M_FUNCT3 { 

	//subconjunto M
	MUL = 0, MULH = 1,
	MULHSU = 2, MULHU = 3,
	DIV = 4, DIVU = 5,
	REM = 6, REMU = 7

};

enum M_OPCODES {

	//subconjunto M
	OP_M = 0x33,

};

#endif