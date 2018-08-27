#include <iostream>
#include "mainwindow.h"
#include <QApplication>
#include "defs.h"
#include "cpu_RV32G.h"


int main(int argc, char *argv[])
{
    
    load_mem("init_exec.bin", 0);
    //load_mem(init_data, 8192);
    std::cout << "Secao de texto da memoria (inicio):\n";
    dump_mem(0, 100, 'h');
    init();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    dump_breg();
    std::cout << "Secao de texto na memoria (fim):\n";
    dump_mem(0, 100, 'h');


    return a.exec();
}
