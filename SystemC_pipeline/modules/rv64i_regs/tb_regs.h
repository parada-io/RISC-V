#ifndef TB_REGS_H
#define TB_REGS_H
#include "systemc.h"

SC_MODULE(tb_regs){

    sc_out<sc_bv<64>> write_data;
    sc_out<sc_bv<5>> rs1;
    sc_out<sc_bv<5>> rs2;
    sc_out<sc_bv<5>> rd;

    sc_in<sc_bv<64>> read_data1;
    sc_in<sc_bv<64>> read_data2;

    sc_out<bool> control_read;
    sc_out<bool> control_write;

    SC_CTOR(tb_regs){

        SC_THREAD(feed_test);
    }

    void feed_test();


};

#endif // TB_REGS_H

