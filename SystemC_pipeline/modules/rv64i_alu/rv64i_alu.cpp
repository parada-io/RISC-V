#include "rv64i_alu.h"
#include "systemc.h"

void rv64i_alu::alu_exec(){

   //zero = false;

    if(setup_protect){
        std::cout << "Chamada de setup" << std::endl;
        setup_protect = false;
        goto end_f;
    }
    std:: cout << "__________________________________________________________" << std::endl;
    std::cout << "ULA CHAMADA" << std::endl;
    std::cout << "Operacao:" << alu_control.read() << std::endl;
    std::cout << "Entradas:" << a.read() << "\t" << b.read() << std::endl;

    switch(alu_control.read()){

        case AND:
            x = a.read() & b.read();
            check_zero();
        break;
        case OR:
            x = a.read() | b.read();
            check_zero();
        break;
        case ADD:
            x = a.read() + b.read();
            check_zero();
        break;
        case SLL:
            x = a.read() << shamt.read();
            check_zero();
        break;
        case SRL:
            x = a.read() >> shamt.read();
            //check_zero();
        break;
        case SRA:
            x = (a.read() >> shamt.read()) | (a.read() << (64 - shamt.read()));
            //check_zero();
        break;
        case SUB:
            x = a.read() - b.read();
            //wait(10, SC_US)
            //check_zero();
        break;
        case XOR:
            x = a.read() ^ b.read();
            //check_zero();
        break;
        default:
            std::cout << "Codigo de Operacao da ALU invalido" << std::endl;
        break;
    }
    //wait(1, SC_US);
    std::cout << "Saida da Operacao:\t" << x.read() << std::endl;
    if(x.read() == 0){
        zero.write(SC_LOGIC_1);
    }
    else{
        zero.write(SC_LOGIC_0);
    }

    std::cout << " O valor da saida ZERO e :" << zero.read() << std::endl;

    end_f:
    return;
}

void rv64i_alu::check_zero(){

    int a = 10;
    int b = 20;
    int c = 30;
}
