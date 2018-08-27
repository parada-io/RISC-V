#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void update_ui();
    void setTable();
    void HighlightLine();
    void on_Button_Step_clicked();
    void check_mem_debug();

    //void on_pushButton_2_clicked();
    void on_Button_Salvar_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_Button_Reset_clicked();

private:
    Ui::MainWindow *ui;
    const char* hexORdec;

};

#endif // MAINWINDOW_H
