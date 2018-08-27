#include "systemc.h"
#include "test_feed_control.h"

void test_feed_control::feed(){

    if(flag_setup_protect){
        std::cout << "Chamada de comportamento indefinido ao Reg. EX/MEM" << std::endl;
        flag_setup_protect = false;
        goto end_f;
    }

    std::cout << "CALL -> INST FEED." << std::endl;
    out_opcode = (sc_uint<7>)(test_inst[pos] & 0x0000003F);
    std::cout << "Instrucao alimentada:\t" << std::hex << test_inst[pos] << std::endl;
    std::cout << "Opcode alimentado:\t" << out_opcode.read();

    std::cout << std::endl;
    pos++;

    end_f:
    return;

}
