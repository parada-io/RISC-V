#ifndef TSYS_CONTROL_H
#define TSYS_CONTROL_H

#include "systemc.h"
#include "control_logic.h"
#include "control_reg_ex_mem.h"
#include "control_reg_id_ex.h"
#include "control_reg_mem_wb.h"
#include "test_feed_control.h"

SC_MODULE(tsys_control){

    control_logic log;
    control_reg_id_ex id_ex;
    control_reg_ex_mem ex_mem;
    control_reg_mem_wb mem_wb;
    test_feed_control tb;

    sc_signal<sc_bv<7>> tb_log_opcode;

    sc_signal<sc_bv<2>> log_id_alu_op;
    sc_signal<sc_logic> log_id_alu_src;
    sc_signal<sc_logic> log_id_branch;
    sc_signal<sc_logic> log_id_mem_read;
    sc_signal<sc_logic> log_id_mem_write;
    sc_signal<sc_logic> log_id_reg_write;
    sc_signal<sc_logic> log_id_mem_to_reg;

    sc_signal<sc_logic> ex_branch;
    sc_signal<sc_logic> ex_mem_read;
    sc_signal<sc_logic> ex_mem_write;
    sc_signal<sc_logic> ex_reg_write;
    sc_signal<sc_logic> ex_mem_to_reg;

    sc_signal<sc_logic> mem_reg_write;
    sc_signal<sc_logic> mem_mem_to_reg;

    sc_signal<bool> call_tb_log;
    sc_signal<bool> call_log_id;
    sc_signal<bool> call_ex;
    sc_signal<bool> call_mem;
    //sc_out<bool> out_kickstart;

    sc_signal<sc_bv<2>> dummy_alu_op;
    sc_signal<sc_logic> dummy_alu_src;
    sc_signal<sc_logic> dummy_branch;
    sc_signal<sc_logic> dummy_mem_read;
    sc_signal<sc_logic> dummy_mem_write;
    sc_signal<sc_logic> dummy_mem_to_reg;
    sc_signal<sc_logic> dummy_reg_write;

    //sc_in<sc_logic> in_dummy;
    //sc_in<sc_bv<2>> in_dummy_bv;

    sc_clock clock;
    //sc_signal<bool> kickstart;
    //sc_signal<sc_logic> clk;


    SC_CTOR(tsys_control): tb("tb"), log("log"), id_ex("id_ex"), ex_mem("ex_mem"), mem_wb("mem_wb"), clock("clock", 1, SC_NS, 0.5, 0, SC_NS, true){

        //kickstart = false;

        tb.out_opcode(tb_log_opcode);
        tb.call_in(call_tb_log);

        log.in_opcode(tb_log_opcode);
        log.out_alu_op(log_id_alu_op);
        log.out_alu_src(log_id_alu_src);
        log.out_branch(log_id_branch);
        log.out_mem_read(log_id_mem_read);
        log.out_mem_write(log_id_mem_write);
        log.out_reg_write(log_id_reg_write);
        log.out_mem_to_reg(log_id_mem_to_reg);
        log.call_out(call_tb_log);
        log.call_in(call_log_id);

        id_ex.in_alu_op(log_id_alu_op);
        id_ex.in_alu_src(log_id_alu_src);
        id_ex.in_branch(log_id_branch);
        id_ex.in_mem_read(log_id_mem_read);
        id_ex.in_mem_write(log_id_mem_write);
        id_ex.in_reg_write(log_id_reg_write);
        id_ex.in_mem_to_reg(log_id_mem_to_reg);
        id_ex.call_out(call_log_id);

        id_ex.out_branch(ex_branch);
        id_ex.out_mem_read(ex_mem_read);
        id_ex.out_mem_write(ex_mem_write);
        id_ex.out_reg_write(ex_reg_write);
        id_ex.out_mem_to_reg(ex_mem_to_reg);
        id_ex.call_in(call_ex);

        ex_mem.in_branch(ex_branch);
        ex_mem.in_mem_read(ex_mem_read);
        ex_mem.in_mem_write(ex_mem_write);
        ex_mem.in_reg_write(ex_reg_write);
        ex_mem.in_mem_to_reg(ex_mem_to_reg);
        ex_mem.call_out(call_ex);

        ex_mem.out_reg_write(mem_reg_write);
        ex_mem.out_mem_to_reg(mem_mem_to_reg);
        ex_mem.call_in(call_mem);

        mem_wb.in_reg_write(mem_reg_write);
        mem_wb.in_mem_to_reg(mem_mem_to_reg);
        mem_wb.call_out(call_mem);
        mem_wb.clk(clock);
        //out_kickstart(kickstart);

        id_ex.out_alu_op(dummy_alu_op);
        id_ex.out_alu_src(dummy_alu_src);
        ex_mem.out_branch(dummy_branch);
        ex_mem.out_mem_read(dummy_mem_read);
        ex_mem.out_mem_write(dummy_mem_write);
        mem_wb.out_mem_to_reg(dummy_mem_to_reg);
        mem_wb.out_reg_write(dummy_reg_write);

       // kickstart = true;


        //id_ex.clock(clock);
        //ex_mem.clock(clock);

        //in_dummy_bv(dummy_bv);
        //in_dummy(dummy_bool);
    }
};


#endif // TSYS_CONTROL_H
