#ifndef TB_MEM_DATA_H
#define TB_MEM_DATA_H

#include "systemc.h"
#include "mem_data.h"

SC_MODULE(tb_mem_data){

    sc_out<sc_bv<64>> address;
    sc_out<sc_bv<64>> data_input;
    sc_in<sc_bv<64>> data_output;

    sc_out<bool>read_data_sig;
    sc_out<bool> write_data_sig;

    SC_CTOR(tb_mem_data){

        SC_THREAD(test_mem);

    }

    void test_mem();

};

#endif // TB_MEM_DATA_H
