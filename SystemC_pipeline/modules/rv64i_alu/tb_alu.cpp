#include "systemc.h"
#include <cstdlib>
#include "tb_alu.h"
#include "rv64i_alu.h"

void tb_alu::tb_alu_exec(){

    std::cout << "TEST BENCH EXEC" << std::endl;

    wait(10, SC_US);
    for(int i = 0; i < 8; i++){

        std::cout << "TEST BENCH EXEC LOOP" << std::endl;

        if(i == 6){
            a.write(99);
            b.write(99);
            shamt.write(20);
            alu_control.write(i);
        }
        else{
            long long int rand_input;
            rand_input = rand() % 0xFFFFFFFFFFFFFFFF;
            a.write(rand_input);
            rand_input = rand() % 0xFFFFFFFFFFFFFFFF;
            b.write(rand_input);
            rand_input =  rand() % 0xFFFFFF;
            shamt.write(13);
            alu_control.write(i);
        }
        wait(10, SC_US);
        //if(x.read() == 0){aux_zero = true;}
        //else{aux_zero = false;}
        tb_alu_print();

    }

}

void tb_alu::tb_alu_print(){

    std::cout << "TEST BENCH PRINT" << std::endl;

    int aux = alu_control.read();

    std:: cout << "__________________________________________________________" << std::endl;
    std::cout << "Operacao:\t" << std::hex << (ALU_CODES)aux << std::endl;
    std::cout << "Entradas:\ta: " << std::hex << a.read() << "\tb: " << b.read() << "\tshamt: " << shamt.read() << std::endl;
    std::cout << "Saidas:\t\tx: " << std::hex << x.read() << "\tzero: " << zero.read() << std::endl;

}
