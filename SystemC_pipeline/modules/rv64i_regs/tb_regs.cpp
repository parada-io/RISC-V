#include "systemc.h"
#include "tb_regs.h"
#include <cstdlib>

void tb_regs::feed_test(){

    for(int i = 0; i < 32; i++){
        rd.write(i);
        wait(1, SC_US);
        long long int aux = (((long long int)(rand() % 0xFFFFFFFF) << 32) | (long long int)rand());;
        write_data.write(aux);
        control_write.write(true);
        wait(1, SC_US);
        control_write.write(false);

    }

    std::cout << std::endl;

    for(int i = 0; i < 32; i+=2){
        rs1.write((sc_int<6>)i);
        rs2.write((sc_int<6>)(i+1));
        wait(1, SC_PS);
        control_read.write(true);
        wait(1, SC_PS);
        control_read.write(false);
        std::cout << "Valor lido do registrador " << i << ":  \t" << std::hex << read_data1.read() << std::endl;
        std::cout << "Valor lido do registrador " << (i + 1) << ":  \t" << std::hex << read_data2.read() << std::endl;
    }

}
