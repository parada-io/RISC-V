#include "systemc.h"
#include "tsys_regs.h"

int sc_main(int argc, char *argv[]){

    tsys_regs sys("sys");

    std::cout << "INICIO DA SIMULACAO DO BANCO DE REGISTRADORES:" << endl;
    sc_start(500, SC_US);

    return 0;


}
