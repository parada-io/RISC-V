#include "systemc.h"
#include "tsys_mem_inst.h"

int sc_main(int argc, char *argv[]){

    tsys_mem_inst sys("sys");

    sys.mem.flash("testfile.bin");

    std::cout << "INICIO DA SIMULACAO DA MEMORIA DE INSTRUCOES:" << endl;
    sc_start(500, SC_US);

    return 0;


}
