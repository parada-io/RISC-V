#ifndef MEM_INST_H
#define MEM_INST_H

#define MEM_INST_SIZE 8192

#include "systemc.h"
#include <string>

SC_MODULE(mem_inst){

sc_in<sc_bv<64>> address;
sc_out<sc_bv<64>> mem_inst_output;

sc_in<bool> get_inst;

sc_uint<64> mem[MEM_INST_SIZE];

    SC_CTOR(mem_inst){
        SC_METHOD(read_inst);
        sensitive << get_inst.pos();
    }

    void read_inst();
    void flash(std::string o_filename);

};


#endif // MEM_INST_H
