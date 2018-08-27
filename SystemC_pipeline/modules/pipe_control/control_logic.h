#ifndef CONTROL_LOGIC_H
#define CONTROL_LOGIC_H

#include "systemc.h"

SC_MODULE(control_logic){



    sc_in<sc_bv<7>> in_opcode;

    sc_bv<7> opcode;

    sc_out<sc_bv<2>> out_alu_op;
    sc_out<sc_logic> out_alu_src;
    sc_out<sc_logic> out_branch;
    sc_out<sc_logic> out_mem_read;
    sc_out<sc_logic> out_mem_write;
    sc_out<sc_logic> out_reg_write;
    sc_out<sc_logic> out_mem_to_reg;

    sc_bv<2> alu_op;
    sc_logic alu_src;
    sc_logic branch;
    sc_logic mem_read;
    sc_logic mem_write;
    sc_logic reg_write;
    sc_logic mem_to_reg;


    sc_in<bool> call_in;
    sc_out<bool> call_out;

    bool flag_setup_protect = true;

    SC_CTOR(control_logic){

        SC_METHOD(encode);
        sensitive << call_in;
    }

    void encode();

};

#endif // CONTROL_LOGIC_H
