#ifndef TB_MEM_INST_H
#define TB_MEM_INST_H

#include "systemc.h"
#include "mem_inst.h"

SC_MODULE(tb_mem_inst){

    sc_out<sc_bv<64>> address;
    sc_in<sc_bv<64>> mem_inst_output;

    sc_out<bool> get_inst;

    SC_CTOR(tb_mem_inst){

        SC_THREAD(dump_mem);

    }

    void dump_mem();

};

#endif // MEM_INST_TB_H
