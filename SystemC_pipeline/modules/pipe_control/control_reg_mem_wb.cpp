#include "systemc.h"
#include "control_reg_mem_wb.h"

void control_reg_mem_wb::toggle(){

    int a;

    if(flag_setup_protect){
        std::cout << "Chamada de comportamento indefinido ao Reg. MEM/WB" << std::endl;
        flag_setup_protect = false;
        goto end_f;
    }


    std::cout << "_________________________________________________________________" << std::endl;
    std::cout << sc_time_stamp() << std::endl;
    std::cout << "CALL -> Reg MEM/WB." << std::endl;

    //call_out = !(call_out);

    //out_reg_write = reg_write;
    //out_mem_to_reg = mem_to_reg;

    std::cout << "Estado anterior do Call Out MEM/WB \t" << call_out << std::endl;
    call_out = !(call_out);
    std::cout << "Estado atual do Call Out MEM/WB \t" << call_out << std::endl;

    reg_write = in_reg_write;
    mem_to_reg = in_mem_to_reg;

    out_reg_write = reg_write;
    out_mem_to_reg = mem_to_reg;

    std::cout << "ESTADO DO REGISTRADOR DE CONTROLE MEM/WB:" << std::endl;

    std::cout << "mem_to_reg:\t" << mem_to_reg << std::endl;
    std::cout << "reg_write:\t" << reg_write << std::endl;

    std::cout << std::endl;

    end_f:
    return;

}
