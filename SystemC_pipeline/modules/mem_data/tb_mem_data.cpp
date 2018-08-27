#include "systemc.h"
#include "tb_mem_data.h"
#include "mem_data.h"
#include "tsys_mem_data.h"

void tb_mem_data::test_mem(){

    read_data_sig = false;
    write_data_sig = false;

    extern mem_data mem_d;

    uint64 test_data[20] =
            {0xe407dcaa37ea7f1c,
            0xba00a8e5e10c5a98,
            0x30aabcae444a2575,
            0xb214b63c50aee4b0,
            0x50ad0a15b6d1b532,
            0xb3b4f0548b7495e7,
            0x0faf844a9e759e97,
            0x5ba0a302c5bfe939,
            0x04a9cb88d4803654,
            0xe3619caee2bd3403,
            0x397f968c391f3401,
            0x44bd3320f66262ec,
            0xc13870ad4209fde3,
            0x110f8913ec0a7386,
            0x9b7db92e465c5065,
            0xd688db36c0e625a4,
            0xa46ff80e16ef1b56,
            0x19f0164ddaaa3f38,
            0x574e4aaca8b40c30,
            0xe92404e06d5efc3b};

    std::cout << "A funcao test_mem foi chamada" << std:: endl;

    std::cout << "Inicio do primeiro loop de leitura" << std::endl;

    read_data_sig = false;

    for(int i = 0; i < 20; i++){

        wait(1, SC_PS);
        address.write(i);
        wait(1, SC_PS);
        read_data_sig = true;
        wait(1, SC_PS);
        read_data_sig = false;
        std::cout << "O conteudo lido da posicao de memoria\t" << i << "\te:\t" << std::hex << (sc_int<64>)data_output.read() << std::endl;

    }

    wait(1, SC_PS);

    std::cout << "Inicio do loop de escrita" << std::endl;

    for(int i = 0; i < 20; i++){

        address.write(i);
        data_input.write(test_data[i]);
        wait(1, SC_PS);
        write_data_sig = true;
        wait(1, SC_PS);
        write_data_sig = false;

    }

    wait(1, SC_PS);

    std::cout << "Inicio do segundo loop de leitura" << std::endl;

    for(int i = 0; i < 20; i++){

        address.write(i);
        wait(1, SC_PS);
        read_data_sig = true;
        wait(1, SC_PS);
        read_data_sig = false;
        std::cout << "O conteudo lido da posicao de memoria\t" << i << "\te:\t" << std::hex << (sc_int<64>)data_output.read() << std::endl;

    }

}

