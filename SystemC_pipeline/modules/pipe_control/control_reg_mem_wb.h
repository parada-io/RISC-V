#ifndef CONTROL_REG_MEM_WB_H
#define CONTROL_REG_MEM_WB_H

#include "systemc.h"

SC_MODULE(control_reg_mem_wb){

    sc_in<sc_logic> in_reg_write;
    sc_in<sc_logic> in_mem_to_reg;

    sc_logic reg_write;
    sc_logic mem_to_reg;

    sc_out<sc_logic> out_reg_write;
    sc_out<sc_logic> out_mem_to_reg;

    sc_in<bool> clk;
    sc_out<bool> call_out;

    bool flag_setup_protect = true;


    SC_CTOR(control_reg_mem_wb){

        SC_METHOD(toggle);
        sensitive << clk.pos();
    }

    void toggle();

};

#endif // CONTROL_REG_MEM_WB_H
