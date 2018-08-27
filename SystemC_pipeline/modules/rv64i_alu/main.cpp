//#include <QCoreApplication>
#include "systemc.h"
#include "tsys_alu.h"

int sc_main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    tsys_alu sys("sys");

    sc_trace_file* trace_file = sc_create_vcd_trace_file("wave_alu");

    trace_file->set_time_unit(1.0, SC_US);
    sc_trace(trace_file, sys.a, "a");
    sc_trace(trace_file, sys.b, "b");
    sc_trace(trace_file, sys.shamt, "shamt");
    sc_trace(trace_file, sys.alu_control, "alu_control");
    sc_trace(trace_file, sys.x, "x");
    sc_trace(trace_file, sys.zero, "zero");

    std::cout << "INICIO DA SIMULACAO DA ALU:" << endl;
    sc_start(100, SC_US);

    sc_close_vcd_trace_file(trace_file);
    std::cout << " Arquivo wave.vcd criado com sucesso" << std::endl;

    return 0;

}
