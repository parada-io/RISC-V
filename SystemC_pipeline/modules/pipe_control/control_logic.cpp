#include "systemc.h"
#include "control_logic.h"

void control_logic::encode(){

    if(flag_setup_protect){
        std::cout << "Chamada de comportamento indefinido à Logica de Controle." << std::endl;
        flag_setup_protect = false;
        goto end_f;
    }

    std::cout << "CALL -> logica de controle." << std::endl;

    call_out = !(call_out);
    //wait(1, SC_PS);

    opcode = in_opcode;

    std::cout << "Operacao atual\t" << std::hex << opcode << std::endl;

    alu_op[0] = (~opcode[6] & opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (opcode[6] & opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2]);

    alu_op[1] = (~opcode[6] & ~opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & ~opcode[5] & opcode[4] & opcode[3] & ~opcode[2])
            | (~opcode[6] & opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & opcode[5] & opcode[4] & opcode[3] & ~opcode[2])
            | (opcode[6] & ~opcode[5] & ~opcode[4] & opcode[3] & ~opcode[2]);


    alu_src = (~opcode[6] & ~opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & ~opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2]);

    branch = (opcode[6] & opcode[5] & ~opcode[4]);

    mem_read = (~opcode[6] & ~opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2]);

    mem_write = (~opcode[6] & opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2]);

    mem_to_reg = (~opcode[6] & opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2]);

    reg_write = (~opcode[6] & ~opcode[5] & ~opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & ~opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & ~opcode[5] & opcode[4] & opcode[3] & ~opcode[2])
            | (~opcode[6] & opcode[5] & opcode[4] & ~opcode[3] & ~opcode[2])
            | (~opcode[6] & opcode[5] & opcode[4] & opcode[3] & ~opcode[2]);;


    out_alu_op = alu_op;
    out_alu_src = alu_src;
    out_branch = branch;
    out_mem_read = mem_read;
    out_mem_write = mem_write;
    out_mem_to_reg = mem_to_reg;
    out_reg_write = reg_write;

    std::cout << "SAIDAS DA LOGICA DE CONTROLE:" << std::endl;

    std::cout << "alu_op:  \t" << alu_op[1] << alu_op[0] << std::endl;
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
