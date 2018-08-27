#include "systemc.h"
#include "mem_data.h"
#include <fstream>
#include <string>
#include <sstream>

void mem_data::read_data(){

    std::cout << "A funcao read_data foi chamada" << std::endl;

    sc_int<64> addr = (sc_int<64>)address.read();

    std::cout << mem[addr] << std::endl;    

    if((addr >= 0) && (addr < MEM_DATA_SIZE)){
        std::cout << mem[addr] << std::endl;
        data_output.write(mem[addr]);
    }
    else{
        cout << "Endereco de memoria para leitura invalido." << endl;
    }
}

void mem_data::write_data(){

    std::cout << "A funcao write_data foi chamada" << std::endl;

    sc_int<64> addr = (sc_int<64>)address.read();

    if((addr >= 0) && (addr < MEM_DATA_SIZE)){
        mem[addr] = data_input.read();
    }
    else{
        std::cout << "Endereco de memoria para escrita invalido." << std::endl;
    }
}


void mem_data::flash(std::string o_filename){

        std::cout << "ENTROU NA FUNCAO FLASH." << std::endl;
        ifstream fp;
        char inst_s[8];
        //uint64 inst;
        uint64 _addr = 0;
        std::stringstream ss;

        std::cout << o_filename <<  std::endl;
        fp.open(o_filename, ios::binary);
        std::cout << "Arquivo aberto?" << fp.is_open() <<  std::endl;
        while(fp.read(inst_s, 8)){
            mem[_addr] = 0x0;
            for(int i = 0; i < 8; i++){
                uint64 aux = ((uint64)inst_s[i] & 0x00000000000000FF);
                mem[_addr] = (mem[_addr] | (aux << (( 7 - i)*8)));
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
