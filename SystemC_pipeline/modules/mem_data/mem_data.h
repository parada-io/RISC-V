#ifndef MEM_DATA_H
#define MEM_DATA_H

#define MEM_DATA_SIZE 8192

#include "systemc.h"
#include <string>

SC_MODULE(mem_data){

sc_in<sc_bv<64>> address;
sc_in<sc_bv<64>> data_input;

sc_out<sc_bv<64>> data_output;

sc_in<bool> read_data_sig;
sc_in<bool> write_data_sig;

sc_bv<64> mem[MEM_DATA_SIZE];

    SC_CTOR(mem_data){
        SC_METHOD(read_data);
        sensitive << read_data_sig.pos();
        SC_METHOD(write_data);
        sensitive << write_data_sig.pos();
    }

    void read_data();
    void write_data();
    void flash(std::string o_filename);

};


#endif // MEM_DATA_H
