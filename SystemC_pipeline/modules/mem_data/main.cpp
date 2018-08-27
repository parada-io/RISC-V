#include "systemc.h"
#include "tsys_mem_data.h"
#include "tb_mem_data.h"

int sc_main(int argc, char *argv[]){

    tsys_mem_data sys("sys");

    sys.mem_d.flash("testdata.data");

    std::cout << "INICIO DA SIMULACAO DA MEMORIA DE DADOS:" << endl;
    sc_start(500, SC_US);

    return 0;


}
