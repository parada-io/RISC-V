#ifndef TB_ALU_H
#define TB_ALU_H

#include "tb_alu.h"
#include "systemc.h"

SC_MODULE(tb_alu){

    sc_in<sc_int<64>> x;
    sc_in<sc_logic> zero;

    sc_out<sc_int<64>> a;
    sc_out<sc_int<64>> b;
    sc_out<sc_int<6>> shamt;
    sc_out<sc_int<4>> alu_control;

    bool aux_zero;

    SC_CTOR(tb_alu){
       SC_THREAD(tb_alu_exec);
    }

    void tb_alu_exec();
    void tb_alu_print();

};



#endif // TESTBENCH_ALU_H
