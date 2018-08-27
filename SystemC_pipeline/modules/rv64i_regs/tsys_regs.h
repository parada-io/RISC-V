#ifndef TSYS_REGS_H
#define TSYS_REGS_H
#include "systemc.h"
#include "rv64i_regs.h"
#include "tb_regs.h"

SC_MODULE(tsys_regs){

    rv64i_regs reg_bank;
    tb_regs tb;

    sc_signal<sc_bv<64>> write_data;
    sc_signal<sc_bv<5>> rs1;
    sc_signal<sc_bv<5>> rs2;
    sc_signal<sc_bv<5>> rd;

    sc_signal<sc_bv<64>> read_data1;
    sc_signal<sc_bv<64>> read_data2;

    sc_signal<bool> control_read;
    sc_signal<bool> control_write;

    SC_CTOR(tsys_regs): reg_bank("reg_bank"), tb("tb"){

        reg_bank.write_data(write_data);
        reg_bank.rs1(rs1);
        reg_bank.rs2(rs2);
        reg_bank.rd(rd);
        reg_bank.read_data1(read_data1);
        reg_bank.read_data2(read_data2);
        reg_bank.control_read(control_read);
        reg_bank.control_write(control_write);


        tb.write_data(write_data);
        tb.rs1(rs1);
        tb.rs2(rs2);
        tb.rd(rd);
        tb.read_data1(read_data1);
        tb.read_data2(read_data2);
        tb.control_read(control_read);
        tb.control_write(control_write);

    }
};

#endif // TSYS_REGS_H
