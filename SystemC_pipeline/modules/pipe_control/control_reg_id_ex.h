#ifndef CONTROL_REG_ID_EX_H
#define CONTROL_REG_ID_EX_H

#include "systemc.h"

SC_MODULE(control_reg_id_ex){

    sc_in<sc_bv<2>> in_alu_op;
    sc_in<sc_logic> in_alu_src;
    sc_in<sc_logic> in_branch;
    sc_in<sc_logic> in_mem_read;
    sc_in<sc_logic> in_mem_write;
    sc_in<sc_logic> in_reg_write;
    sc_in<sc_logic> in_mem_to_reg;

    sc_bv<2> alu_op;
    sc_logic alu_src;
    sc_logic branch;
    sc_logic mem_read;
    sc_logic mem_write;
    sc_logic reg_write;
    sc_logic mem_to_reg;

    sc_out<sc_bv<2>> out_alu_op;
    sc_out<sc_logic> out_alu_src;
    sc_out<sc_logic> out_branch;
    sc_out<sc_logic> out_mem_read;
    sc_out<sc_logic> out_mem_write;
    sc_out<sc_logic> out_reg_write;
    sc_out<sc_logic> out_mem_to_reg;

    sc_in<bool> call_in;
    sc_out<bool> call_out;

    bool flag_setup_protect = true;


    //sc_in<bool> clock;


    SC_CTOR(control_reg_id_ex){

        SC_METHOD(toggle);
        sensitive << call_in;
    }

    void toggle();

};


#endif // CONTROL_REG_ID_EX_H
