#ifndef RV64I_REGS_H
#define RV64I_REGS_H

#include "systemc.h"

SC_MODULE(rv64i_regs){

sc_bv<64> regs[32];

sc_in<sc_bv<64>> write_data;
sc_in<sc_bv<5>> rs1;
sc_in<sc_bv<5>> rs2;
sc_in<sc_bv<5>> rd;

sc_out<sc_bv<64>> read_data1;
sc_out<sc_bv<64>> read_data2;


sc_in<bool> control_read;
sc_in<bool> control_write;


    SC_CTOR(rv64i_regs){

        regs[0] = 0;

        SC_METHOD(read);
        sensitive << control_read.pos();
        SC_METHOD(write);
        sensitive << control_write.pos();

    }

    void write();
    void read();

};



#endif // RV64I_REGS_H
