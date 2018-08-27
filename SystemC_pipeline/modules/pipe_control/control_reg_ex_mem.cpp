#include "systemc.h"
#include "control_reg_ex_mem.h"

void control_reg_ex_mem::toggle(){

    if(flag_setup_protect){
        std::cout << "Chamada de comportamento indefinido ao Reg. EX/MEM" << std::endl;
        flag_setup_protect = false;
        goto end_f;
    }

    std::cout << "CALL -> Reg EX/MEM." << std::endl;

    call_out = !(call_out);

    /*out_branch = branch;
    out_mem_read = mem_read;
    out_mem_write = mem_write;
    out_reg_write = reg_write;
    out_mem_to_reg = mem_to_reg;

    //call_out = !(call_out);

    branch = in_branch;
    mem_read = in_mem_read;
    mem_write = in_mem_write;
    reg_write = in_reg_write;
    mem_to_reg = in_mem_to_reg;*/

    branch = in_branch;
    mem_read = in_mem_read;
    mem_write = in_mem_write;
    reg_write = in_reg_write;
    mem_to_reg = in_mem_to_reg;

    out_branch = branch;
    out_mem_read = mem_read;
    out_mem_write = mem_write;
    out_reg_write = reg_write;
    out_mem_to_reg = mem_to_reg;

    std::cout << "ESTADO DO REGISTRADOR DE CONTROLE EX/MEM:" << std::endl;

    std::cout << "branch:  \t" << branch << std::endl;
    std::cout << "mem_read:\t" << mem_read << std::endl;
    std::cout << "mem_write:\t" << mem_write << std::endl;
    std::cout << "mem_to_reg:\t" << mem_to_reg << std::endl;
    std::cout << "reg_write:\t" << reg_write << std::endl;

    std::cout << std::endl;

    end_f:
    return;

}
