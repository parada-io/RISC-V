#include "systemc.h"
#include "rv64i_regs.h"

void rv64i_regs::write(){

    regs[0] = 0;
    regs[(sc_int<6>)rd] = write_data.read();
    regs[0] = 0;

    std::cout << "Confirmacao de escrita do valor " << std::hex << regs[(sc_int<6>)rd] << " no registrador " << rd.read() << std::endl;

}

void rv64i_regs::read(){

    read_data1.write(regs[(sc_int<6>)rs1]);
    read_data2.write(regs[(sc_int<6>)rs2]);

}
