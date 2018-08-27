#include "systemc.h"
#include "tb_mem_inst.h"
#include "mem_inst.h"

void tb_mem_inst::dump_mem(){

    get_inst.write(false);

    std::cout << "A funcao dump_mem foi chamada" << std:: endl;

    for(int i = 0; i < 20; i++){

        address.write(i);
        wait(1, SC_PS);
        get_inst = true;
        wait(1, SC_PS);
        get_inst = false;
        std::cout << "O conteudo lido da posicao de memoria\t" << i << "\te:\t" << std::hex << (sc_int<64>)mem_inst_output.read() << std::endl;

    }

}

