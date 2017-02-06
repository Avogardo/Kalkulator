#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstring.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     a = 0;
     b = 0;
     pamiec = 0;
     przecinek = false;
     lewa = false;
     prawa = false;
//     ope = this ->NoOperation;
     czystyobraz = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::wpiszliczbe(QString text)
{
    QString oldtext;

    oldtext = ui ->Ekran ->text();

    if(oldtext.length() >= ui->Ekran ->maxLength()) return;
    if(oldtext=="0") oldtext.clear();
    if(czystyobraz)
    {
        oldtext.clear();
        czystyobraz = false;
    }

    oldtext.append(text);
    ui ->Ekran ->setText(oldtext);
}

void MainWindow::operacja()
{
    if(!lewa)
    {
        a=ui ->Ekran ->text().toDouble();
        lewa = true;
        czystyobraz = true;
    }
}

void MainWindow::on_P0_clicked()
{
   MainWindow:: wpiszliczbe("0");
}

void MainWindow::on_P1_clicked()
{
   MainWindow:: wpiszliczbe("1");
}

void MainWindow::on_P2_clicked()
{
    MainWindow:: wpiszliczbe("2");
}

void MainWindow::on_P3_clicked()
{
    MainWindow:: wpiszliczbe("3");
}

void MainWindow::on_P4_clicked()
{
    MainWindow:: wpiszliczbe("4");
}

void MainWindow::on_P5_clicked()
{
    MainWindow:: wpiszliczbe("5");
}

void MainWindow::on_P6_clicked()
{
    MainWindow:: wpiszliczbe("6");
}

void MainWindow::on_P7_clicked()
{
    MainWindow:: wpiszliczbe("7");
}

void MainWindow::on_P8_clicked()
{
    MainWindow:: wpiszliczbe("8");
}

void MainWindow::on_P9_clicked()
{
    MainWindow:: wpiszliczbe("9");
}

void MainWindow::on_Pwyczysc_clicked()
{
    ui ->Ekran ->setText("0");

    a = 0;
    b = 0;
  //  pamiec = 0;
    przecinek = false;
    lewa = false;
    prawa = false;
    czystyobraz = false;
}

void MainWindow::on_Pprzecinek_clicked()
{
    if(przecinek == true) return;
    ui ->Ekran ->setText(ui->Ekran ->text().append("."));
    przecinek = true;
}

void MainWindow::on_Pdodawanie_clicked()
{
    operacja();
    ope = dodawanie;
}

void MainWindow::on_Podejmowanie_clicked()
{
    operacja();
    ope = odejmowanie;
}

void MainWindow::on_Pmnozenie_clicked()
{
    operacja();
    ope = mnozenie;
}

void MainWindow::on_Pdzielenie_clicked()
{
    operacja();
    ope = dzielenie;
}

void MainWindow::on_Prownasie_clicked()
{
    if(!lewa)return;
    b= ui->Ekran ->text().toDouble();
    double g = 0;

    switch (ope)
    {
    case dodawanie:
        g = a + b;
        break;

    case odejmowanie:
        g = a - b;
        break;

    case mnozenie:
        g = a * b;
        break;

    case dzielenie:
       if(b==0)
       {
           ui->Ekran ->setText("Nie / 0");
           return;
       }
       else
       {
        g = a / b;
       }
        break;
    }
    czystyobraz = true;
    a = 0;
    b = 0;
    lewa = false;
    prawa = false;

    ui ->Ekran ->setText(QString::number(g));
}

void MainWindow::on_Pmem_clicked()
{
    pamiec = ui ->Ekran ->text().toDouble();
}

void MainWindow::on_Pmemclear_clicked()
{
    ui ->Ekran ->setText(QString::number(pamiec));
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    if((e->modifiers() & Qt::ControlModifier) == Qt::ControlModifier)
    {
        if(e->key() == Qt::Key_Plus)
        {
            on_Pmem_clicked();
            e->accept();
            return;
        }

        if(e->key() == Qt::Key_Enter)
        {
            on_Pmemclear_clicked();
            e->accept();
            return;
        }
    }

    if(e->matches(QKeySequence::Copy))
    {
     //   QApplication::clipboard()->setText();
        e->accept();
        return;
    }

    switch(e->key())
    {
    case Qt::Key_0:
        on_P0_clicked();
     e->accept();
        break;

    case Qt::Key_1:
        on_P1_clicked();
     e->accept();
        break;

    case Qt::Key_2:
        on_P2_clicked();
     e->accept();
        break;

    case Qt::Key_3:
        on_P3_clicked();
     e->accept();
        break;

    case Qt::Key_4:
        on_P4_clicked();
     e->accept();
        break;

    case Qt::Key_5:
        on_P5_clicked();
     e->accept();
        break;

    case Qt::Key_6:
        on_P6_clicked();
     e->accept();
        break;

    case Qt::Key_7:
        on_P7_clicked();
     e->accept();
        break;

    case Qt::Key_8:
        on_P8_clicked();
     e->accept();
        break;

    case Qt::Key_9:
        on_P9_clicked();
     e->accept();
        break;

    case Qt::Key_Delete:
        on_Pwyczysc_clicked();
     e->accept();
        break;

    case Qt::Key_Enter:
        on_Prownasie_clicked();
        e->accept();
        break;

    case Qt::Key_Plus:
        on_Pdodawanie_clicked();
        e->accept();
        break;

    case Qt::Key_Minus:
        on_Podejmowanie_clicked();
        e->accept();
        break;

    case Qt::Key_multiply:
        on_Pmnozenie_clicked();
        e->accept();
        break;

    case Qt::Key_Asterisk:
        on_Pdzielenie_clicked();
        e->accept();
        break;

    case Qt::Key_Comma:
        on_Pprzecinek_clicked();
        e->accept();
        break;

    }
}




















