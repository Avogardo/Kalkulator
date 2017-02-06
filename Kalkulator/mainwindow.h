#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QClipboard>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    void wpiszliczbe(QString text );
    void operacja();
    void keyReleaseEvent(QKeyEvent *e);

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_P0_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();

    void on_Pwyczysc_clicked();

    void on_Pprzecinek_clicked();

    void on_Pdodawanie_clicked();

    void on_Prownasie_clicked();

    void on_Podejmowanie_clicked();

    void on_Pmnozenie_clicked();

    void on_Pdzielenie_clicked();

    void on_Pmem_clicked();

    void on_Pmemclear_clicked();

private:
    Ui::MainWindow *ui;

    enum operation
    {
     dodawanie,
     odejmowanie,
     mnozenie,
     dzielenie,
     idl
    };

    double a;
    double b;
    bool lewa;
    bool prawa;
    int ope;
    double pamiec;
    bool przecinek;
    bool czystyobraz;
};

#endif // MAINWINDOW_H
