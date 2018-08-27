#ifndef TSYS_MEM_INST_H
#define TSYS_MEM_INST_H

#include "systemc.h"
#include "mem_inst.h"
#include "tb_mem_inst.h"

SC_MODULE(tsys_mem_inst){

    mem_inst mem;
    tb_mem_inst tb;

    sc_signal<sc_bv<64>> address;
    sc_signal<sc_bv<64>> mem_inst_output;

    sc_signal<bool> get_inst;

    SC_CTOR(tsys_mem_inst): mem("mem"), tb("tb"){

        mem.address(address);
        mem.mem_inst_output(mem_inst_output);
        mem.get_inst(get_inst);

        tb.address(address);
        tb.mem_inst_output(mem_inst_output);
        tb.get_inst(get_inst);

    }

};

#endif // TSYS_MEM_INST_H
