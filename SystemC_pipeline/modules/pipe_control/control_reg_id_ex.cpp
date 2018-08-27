#include "systemc.h"
#include "control_reg_id_ex.h"

void control_reg_id_ex::toggle(){

    if(flag_setup_protect){
        std::cout << "Chamada de comportamento indefinido ao Reg. EX/MEM" << std::endl;
        flag_setup_protect = false;
        goto end_f;
    }

    std::cout << "CALL -> Reg ID/EX." << std::endl;

    call_out= !(call_out);

    /*out_alu_op = alu_op;
    out_alu_src = alu_src;
    out_branch = branch;
    out_mem_read = mem_read;
    out_mem_write = mem_write;
    out_reg_write = reg_write;
    out_mem_to_reg = mem_to_reg;

    //call_out= !(call_out);

    //call_out.write(true);
    //wait(1, SC_PS);
    //call_out.write(false);
    //wait(1, SC_PS);

    alu_op = in_alu_op;
    alu_src = in_alu_src;
    branch = in_branch;
    mem_read = in_mem_read;
    mem_write = in_mem_write;
    reg_write = in_reg_write;
    mem_to_reg = in_mem_to_reg;*/

    alu_op = in_alu_op;
    alu_src = in_alu_src;
    branch = in_branch;
    mem_read = in_mem_read;
    mem_write = in_mem_write;
    reg_write = in_reg_write;
    mem_to_reg = in_mem_to_reg;



    out_alu_op = alu_op;
    out_alu_src = alu_src;
    out_branch = branch;
    out_mem_read = mem_read;
    out_mem_write = mem_write;
    out_reg_write = reg_write;
    out_mem_to_reg = mem_to_reg;



    std::cout << "ESTADO DO REGISTRADOR DE CONTROLE ID/EX:" << std::endl;

    std::cout << "alu_op:\t\t" << alu_op[1] << alu_op[0] << std::endl;
    std::cout << "alu_src:\t" << alu_src << std::endl;
    std::cout << "branch:  \t" << branch << std::endl;
    std::cout << "mem_read:\t" << mem_read << std::endl;
    std::cout << "mem_write:\t" << mem_write << std::endl;
    std::cout << "mem_to_reg:\t" << mem_to_reg << std::endl;
    std::cout << "reg_write:\t" << reg_write << std::endl;

    std::cout << std::endl;

    end_f:
    return;

}
