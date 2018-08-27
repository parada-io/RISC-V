#include "systemc.h"
#include "mem_inst.h"
#include <fstream>
#include <string>
#include <sstream>

void mem_inst::read_inst(){

    std::cout << "A funcao read_inst foi chamada" << std::endl;
    sc_int<64> addr = (sc_int<64>)address.read();

    if((addr >= 0) && (addr < MEM_INST_SIZE)){
        mem_inst_output.write(mem[addr]);
    }
    else{
        cout << "Endereco de memoria Invalido." << endl;
    }

}

void mem_inst::flash(std::string o_filename){

        std::cout << "ENTROU NA FUNCAO FLASH." << std::endl;
        ifstream fp;
        char inst_s[8];
        //uint64 inst;
        uint64 _addr = 0;
        std::stringstream ss;

        std::cout << o_filename <<  std::endl;
        fp.open(o_filename, ios::binary);
        std::cout << "Arquivo aberto?" << fp.is_open() <<  std::endl;
        while(fp.read(inst_s, 4)){
            mem[_addr] = 0x0;
            for(int i = 0; i < 4; i++){
                uint64 aux = ((uint64)inst_s[i] & 0x00000000000000FF);
                mem[_addr] = (mem[_addr] | (aux << (( 3 - i)*8)));
            }
            std::cout << std::hex << mem[_addr] << std::endl;
            _addr++;
        }
        fp.close();


    for(int i = 0; i < 18; i++){

        std::cout << std::hex << mem[i] << std::endl;

    }

    std::cout << " FIM DA FUNCAO FLASH" << std::endl;
}
