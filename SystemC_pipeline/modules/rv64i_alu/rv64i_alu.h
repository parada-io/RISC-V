#ifndef RV64I_ALU_H
#define RV64I_ALU_H
#include "systemc.h"

enum ALU_CODES{AND, OR, ADD, SLL, SRL, SRA, SUB, XOR};

SC_MODULE(rv64i_alu){

    sc_in<sc_int<64>> a;
    sc_in<sc_int<64>> b;
    sc_in<sc_int<6>> shamt;
    sc_in<sc_int<4>> alu_control;

    sc_out<sc_int<64>> x;
    sc_out<sc_logic> zero;

    bool setup_protect = true;

    SC_CTOR(rv64i_alu){

        SC_THREAD(alu_exec);
        sensitive << alu_control;

    }

    void alu_exec();
    void check_zero();
};

#endif // RV32I_ALU_H
