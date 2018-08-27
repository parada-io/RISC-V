#include "systemc.h"
#include "tsys_control.h"

int sc_main(int argc, char *argv[]){

    tsys_control sys("sys");

    sc_trace_file* trace_file = sc_create_vcd_trace_file("wave_control");

    trace_file->set_time_unit(1.0, SC_PS);
    sc_trace(trace_file, sys.tb_log_opcode, "tb_log_opcode");
    sc_trace(trace_file, sys.log_id_alu_op, "log_id_alu_op");
    sc_trace(trace_file, sys.log_id_branch, "log_id_branch");
    sc_trace(trace_file, sys.log_id_mem_read, "log_id_mem_read");
    sc_trace(trace_file, sys.log_id_mem_write, "log_id_mem_write");
    sc_trace(trace_file, sys.log_id_reg_write, "log_id_reg_write");
    sc_trace(trace_file, sys.log_id_mem_to_reg, "log_id_mem_to_reg");
    sc_trace(trace_file, sys.ex_branch, "ex_branch");
    sc_trace(trace_file, sys.ex_mem_read, "ex_mem_read");
    sc_trace(trace_file, sys.ex_mem_write, "ex_mem_write");
    sc_trace(trace_file, sys.ex_reg_write, "ex_reg_write");
    sc_trace(trace_file, sys.ex_mem_to_reg, "ex_mem_to_reg");
    sc_trace(trace_file, sys.mem_reg_write, "mem_reg_write");
    sc_trace(trace_file, sys.mem_mem_to_reg, "mem_mem_to_reg");
    sc_trace(trace_file, sys.call_tb_log, "call_tb_log");
    sc_trace(trace_file, sys.call_log_id, "call_log_id");
    sc_trace(trace_file, sys.call_ex, "call_ex");
    sc_trace(trace_file, sys.call_mem, "call_mem");
    sc_trace(trace_file, sys.dummy_alu_op, "dummy_alu_op");
    sc_trace(trace_file, sys.dummy_alu_src, "dummy_alu_src");
    sc_trace(trace_file, sys.dummy_branch, "dummy_branch");
    sc_trace(trace_file, sys.dummy_mem_read, "dummy_mem_read");
    sc_trace(trace_file, sys.dummy_mem_write, "dummy_mem_write");
    sc_trace(trace_file, sys.dummy_mem_to_reg, "dummy_mem_to_reg");
    sc_trace(trace_file, sys.dummy_reg_write, "dummy_reg_write");
    sc_trace(trace_file, sys.clock, "clock");


    //sc_in<sc_logic> in_dummy;
    //sc_in<sc_bv<2>> in_dummy_bv;

    sc_clock clock;

    std::cout << "INICIO DA SIMULACAO DA UNIDADE DE CONTROLE:" << endl;
    sc_start(70, SC_NS);

    return 0;


}
