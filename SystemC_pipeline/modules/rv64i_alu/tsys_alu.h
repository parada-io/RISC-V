#ifndef TSYS_ALU_H
#define TSYS_ALU_H

#include "systemc.h"
#include "tb_alu.h"
#include "rv64i_alu.h"

SC_MODULE(tsys_alu){

    rv64i_alu alu;
    tb_alu tb;

    sc_signal<sc_int<64>> a;
    sc_signal<sc_int<64>> b;
    sc_signal<sc_int<6>> shamt;
    sc_signal<sc_int<4>> alu_control;

    sc_signal<sc_int<64>> x;
    sc_signal<sc_logic> zero;

    SC_CTOR(tsys_alu): alu("alu"), tb("tb"){

        zero.write(SC_LOGIC_0);

        alu.a(a);
        alu.b(b);
        alu.shamt(shamt);
        alu.alu_control(alu_control);
        alu.x(x);
        alu.zero(zero);

        tb.a(a);
        tb.b(b);
        tb.shamt(shamt);
        tb.alu_control(alu_control);
        tb.x(x);
        tb.zero(zero);

    }
};


#endif // TSYS_ALU_H
