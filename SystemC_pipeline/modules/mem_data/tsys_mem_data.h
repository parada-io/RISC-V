#ifndef TSYS_MEM_DATA_H
#define TSYS_MEM_DATA_H

#include "systemc.h"
#include "mem_data.h"
#include "tb_mem_data.h"

SC_MODULE(tsys_mem_data){

    mem_data mem_d;
    tb_mem_data tb;

    sc_signal<sc_bv<64>> address;
    sc_signal<sc_bv<64>> data_input;

    sc_signal<sc_bv<64>> data_output;

    sc_signal<bool> read_data_sig;
    sc_signal<bool> write_data_sig;

    SC_CTOR(tsys_mem_data): mem_d("mem_d"), tb("tb"){

        mem_d.address(address);
        mem_d.data_input(data_input);
        mem_d.data_output(data_output);
        mem_d.read_data_sig(read_data_sig);
        mem_d.write_data_sig(write_data_sig);

        tb.address(address);
        tb.data_input(data_input);
        tb.data_output(data_output);
        tb.read_data_sig(read_data_sig);
        tb.write_data_sig(write_data_sig);
    }
};

#endif // TSYS_MEM_DATA_H
