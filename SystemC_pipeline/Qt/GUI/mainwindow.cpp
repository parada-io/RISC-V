#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cpu_RV32G.h"
#include "subset_RV32I.h"
#include "mem.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("RISCa Faca");
    ui->txt_editor->setDocumentTitle("buffer.c");
    hexORdec = "%X";
    ui->comboBox->setCurrentText("Hex");
    ui->Display_PC->display(0);
    this->setTable();

    QFile file("exec.txt");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "info", file.errorString());
    }
        QTextStream in(&file);
        ui->Txt_Dash->setText(in.readAll());

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_Button_Step_clicked()
{
    step();
    this->update_ui();
    this->check_mem_debug();
}

void MainWindow::on_Button_Salvar_clicked()
{


}


void MainWindow::on_comboBox_activated(const QString &arg1)
{

}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString _curr_txt = ui->comboBox->currentText();
    if(_curr_txt == "Dec"){
        hexORdec = "%d";
    }
    if(_curr_txt == "Hex"){
        hexORdec = "%X";
    }
    this->update_ui();

}

void MainWindow::setTable(){

    int _i_mem = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 500; j++){
            ui->tableWidget->setItem(j, i, new QTableWidgetItem(mem[_i_mem]));
            _i_mem++;
        }
    }
}

void MainWindow::check_mem_debug(){

    if(mem[5] != 0xff5ff06f){
        std::cout << "MUDOU O ENDERECO 0x14!!!!!" << std::endl;
        std::cout << mem[5] << std::endl;

    }
    if(mem[6] != 0x77652498){
        std::cout << "MUDOU O ENDERECO 0x18!!!!!" << std::endl;
        std::cout << mem[6] << std::endl;

    }

}

void MainWindow::HighlightLine(){

    /*int i = pc/4;
    QTextCursor cursor1(ui->Txt_Dash->document()->findBlockByLineNumber(i));
    QTextBlockFormat TBF1 = cursor1.blockFormat();
    TBF1.setBackground(QBrush(Qt::blue));
    cursor1.setBlockFormat(TBF1);
    ui->textBrowser->setTextCursor(cursor1);*/
}

void MainWindow::update_ui(){

    char aux[12];
    //const char* hexORdex = "%X";

    sprintf(aux, "%X", (pc_sincronous));
    ui->Display_PC->display(aux);

    sprintf(aux, "%X", ri);
    ui->Display_RI->display(aux);

    sprintf(aux, "%X", opcode);
    ui->Display_opcode->display(aux);

    sprintf(aux, "%X", rd);
    ui->Display_rd->display(aux);

    sprintf(aux, "%X", rs1);
    ui->Display_rs1->display(aux);

    sprintf(aux, "%X", rs2);
    ui->Display_rs2->display(aux);

    sprintf(aux, "%X", shamt);
    ui->Display_shamt->display(aux);

    sprintf(aux, "%X", funct3);
    ui->Display_funct3->display(aux);

    sprintf(aux, "%X", funct7);
    ui->Display_funct7->display(aux);

    sprintf(aux, "%X", immI);
    ui->Display_immI->display(aux);

    sprintf(aux, "%X", immS);
    ui->Display_immS->display(aux);

    sprintf(aux, "%X", immSB);
    ui->Display_immSB->display(aux);

    sprintf(aux, "%X", immU);
    ui->Display_immU->display(aux);

    sprintf(aux, "%X", immUJ);
    ui->Display_immUJ->display(aux);

    sprintf(aux, "%X", funct5);
    ui->Display_funct5->display(aux);

    sprintf(aux, "%X", rl);
    ui->Display_rl->display(aux);

    sprintf(aux, "%X", aq);
    ui->Display_aq->display(aux);

    sprintf(aux, hexORdec, breg[0]);
    ui->Display_x0->display(aux);

    sprintf(aux, hexORdec, breg[1]);
    ui->Display_x1->display(aux);

    sprintf(aux, hexORdec, breg[2]);
    ui->Display_x2->display(aux);

    sprintf(aux, hexORdec, breg[3]);
    ui->Display_x3->display(aux);

    sprintf(aux, hexORdec, breg[4]);
    ui->Display_x4->display(aux);

    sprintf(aux, hexORdec, breg[5]);
    ui->Display_x5->display(aux);

    sprintf(aux, hexORdec, breg[6]);
    ui->Display_x6->display(aux);

    sprintf(aux, hexORdec, breg[7]);
    ui->Display_x7->display(aux);

    sprintf(aux, hexORdec, breg[8]);
    ui->Display_x8->display(aux);

    sprintf(aux, hexORdec, breg[9]);
    ui->Display_x9->display(aux);

    sprintf(aux, hexORdec, breg[10]);
    ui->Display_x10->display(aux);

    sprintf(aux, hexORdec, breg[11]);
    ui->Display_x11->display(aux);

    sprintf(aux, hexORdec, breg[12]);
    ui->Display_x12->display(aux);

    sprintf(aux, hexORdec, breg[13]);
    ui->Display_x13->display(aux);

    sprintf(aux, hexORdec, breg[14]);
    ui->Display_x14->display(aux);

    sprintf(aux, hexORdec, breg[15]);
    ui->Display_x15->display(aux);

    sprintf(aux, hexORdec, breg[16]);
    ui->Display_x16->display(aux);

    sprintf(aux, hexORdec, breg[17]);
    ui->Display_x17->display(aux);

    sprintf(aux, hexORdec, breg[18]);
    ui->Display_x18->display(aux);

    sprintf(aux, hexORdec, breg[19]);
    ui->Display_x19->display(aux);

    sprintf(aux, hexORdec, breg[20]);
    ui->Display_x20->display(aux);

    sprintf(aux, hexORdec, breg[21]);
    ui->Display_x21->display(aux);

    sprintf(aux, hexORdec, breg[22]);
    ui->Display_x22->display(aux);

    sprintf(aux, hexORdec, breg[23]);
    ui->Display_x23->display(aux);

    sprintf(aux, hexORdec, breg[24]);
    ui->Display_x24->display(aux);

    sprintf(aux, hexORdec, breg[25]);
    ui->Display_x25->display(aux);

    sprintf(aux, hexORdec, breg[26]);
    ui->Display_x26->display(aux);

    sprintf(aux, hexORdec, breg[27]);
    ui->Display_x27->display(aux);

    sprintf(aux, hexORdec, breg[28]);
    ui->Display_x28->display(aux);

    sprintf(aux, hexORdec, breg[29]);
    ui->Display_x29->display(aux);

    sprintf(aux, hexORdec, breg[30]);
    ui->Display_x30->display(aux);

    sprintf(aux, hexORdec, breg[31]);
    ui->Display_x31->display(aux);

    this->HighlightLine();

}




void MainWindow::on_Button_Reset_clicked()
{
    std::cout << "Dump de memoria para debug" << std::endl;
    dump_mem(0, 100, 'h');

    for(int ind = 0; ind < 32; ind++){
        breg[ind] = 0;
    }
    pc = 0;
    pc_sincronous = 0;
    ri = 0;
    csr = 0;
    fcsr = 0;
    opcode = 0;
    rd = 0;
    rs1 = 0;
    rs2 = 0;
    shamt = 0;
    funct3 = 0;
    funct7 = 0;
    immI = 0;
    immS  = 0;
    immSB = 0;
    immU = 0;
    immUJ = 0;
    funct5 = 0;
    rl = 0;
    aq = 0;


    this->update_ui();
}
