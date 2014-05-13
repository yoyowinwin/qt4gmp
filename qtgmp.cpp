//Your comment will always be highly valued,MY EMAIL: wayne.winged@gmail.com

#include "qtgmp.hpp"
#include <gmp.h>
#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QRegExpValidator>
QtGMP::QtGMP(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *vertical = new QVBoxLayout(parent);
    QHBoxLayout *horizon = new QHBoxLayout();
    QGridLayout *grid = new QGridLayout();

    QLabel *label = new QLabel("A:",parent);
    lineEdit1=new QLineEdit("1234567890");
    QLabel *label2 = new QLabel("B:",parent);
    lineEdit2=new QLineEdit("1800");

    QRegExp rx("\\d+");
    QValidator *validator = new QRegExpValidator(rx, this);
    lineEdit1->setValidator(validator);
    lineEdit1->setValidator(validator);

    horizon->addWidget(label);
    horizon->addWidget(lineEdit1);
    horizon->addWidget(label2);
    horizon->addWidget(lineEdit2);
    QPushButton *pushButton1 = new QPushButton("    A*B     ",parent);
    QPushButton *pushButton2 = new QPushButton("    A^B     ",parent);
    QPushButton *pushButton3 = new QPushButton("    B!      " ,parent);
    QPushButton *pushButton4 = new QPushButton("NextPrime(A)",parent);
    QPushButton *pushButton5 = new QPushButton("  GCD(A,B)  ",parent);
    QPushButton *pushButton6 = new QPushButton("  LCM(A,B)  ",parent);

    grid->addWidget(pushButton1,0,0);
    grid->addWidget(pushButton2,0,1);
    grid->addWidget(pushButton5,1,1);
    grid->addWidget(pushButton6,1,0);
    grid->addWidget(pushButton3,2,1);
    grid->addWidget(pushButton4,2,0);

    vertical->addLayout(horizon);
    textEdit= new QTextEdit("hello,bbs.emath.ac.cn.\nThis is Wayne");
    vertical->addWidget(textEdit);
    vertical->addLayout(grid);
    setLayout(vertical);
    connect(pushButton1, SIGNAL(clicked()),this, SLOT(mulAB()));
    connect(pushButton2, SIGNAL(clicked()),this, SLOT(powAB()));
    connect(pushButton3, SIGNAL(clicked()),this, SLOT(fac()));
    connect(pushButton4, SIGNAL(clicked()),this, SLOT(nprime()));
    connect(pushButton5, SIGNAL(clicked()),this, SLOT(gcd()));
    connect(pushButton6, SIGNAL(clicked()),this, SLOT(lcm()));
}

void QtGMP::mulAB()
{
    QString s("");
    mpz_t aa,bb,cc;
    char *str=0;
    mpz_init(cc);
    mpz_init_set_str(aa,qPrintable(this->lineEdit1->text()),10);
    mpz_init_set_str(bb,qPrintable(this->lineEdit2->text()),10);
    mpz_mul(cc,aa,bb);
    // gmp_printf("A:\t%Zd\nB:\t%Zd\nA*B:\t%Zd\n\n\n",aa,bb,cc);
    s.sprintf("A:\t%s\nB:\t%s\nA*B:\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb),mpz_get_str(str,10,cc));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,cc,'\0');
}
void QtGMP::powAB()
{
    QString s("");
    mpz_t aa,bb,cc;
    char *str=0;
    mpz_init(cc);
    mpz_init_set_str(aa,qPrintable(this->lineEdit1->text()),10);
    mpz_init_set_str(bb,qPrintable(this->lineEdit2->text()),10);
    mpz_pow_ui(cc,aa,mpz_get_ui(bb));
    // gmp_printf("A:\t%Zd\nB:\t%Zd\nA^B:\t%Zd\n\n\n",aa,bb,cc);
    s.sprintf("A:\t%s\nB:\t%s\nA^B:\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb),mpz_get_str(str,10,cc));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,cc,'\0');
}

void QtGMP::fac()
{
    QString s("");
    mpz_t aa,bb;
    char *str=0;
    mpz_init(bb);
    mpz_init_set_str(aa,qPrintable(this->lineEdit2->text()),10);

    mpz_fac_ui(bb,mpz_get_ui(aa));
    // gmp_printf("B!:\t%Zd\nA!:\t%Zd\n\n\n",aa,bb);
    s.sprintf("B:\t%s\nB!:\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,'\0');
}
void QtGMP::nprime()
{
    QString s("");
    mpz_t aa,bb;
    char *str=0;
    mpz_init(bb);
    mpz_init_set_str(aa,qPrintable(this->lineEdit1->text()),10);

    mpz_nextprime(bb,aa);
    //gmp_printf("A:\t%Zd\nNextPrime(A):\t%Zd\n\n\n",aa,bb);
    s.sprintf("A:\t%s\nNextPrime(A):\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,'\0');
}

void QtGMP::gcd()
{
    QString s("");
    mpz_t aa,bb,cc;
    char *str=0;
    mpz_init(cc);
    mpz_init_set_str(aa,qPrintable(this->lineEdit1->text()),10);
    mpz_init_set_str(bb,qPrintable(this->lineEdit2->text()),10);
    mpz_gcd(cc,aa,bb);
    // gmp_printf("A:\t%Zd\nB:\t%Zd\nGCD(A,B):\t%Zd\n\n\n",aa,bb,cc);
    s.sprintf("A:\t%s\nB:\t%s\nGCD(A,B):\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb),mpz_get_str(str,10,cc));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,cc,'\0');
}
void QtGMP::lcm()
{
    //QApplication::aboutQt();
    QString s("");
    mpz_t aa,bb,cc;
    char *str=0;
    mpz_init(cc);
    mpz_init_set_str(aa,qPrintable(this->lineEdit1->text()),10);
    mpz_init_set_str(bb,qPrintable(this->lineEdit2->text()),10);
    mpz_lcm(cc,aa,bb);
    //  gmp_printf("A:\t%Zd\nB:\t%Zd\nLCM(A,B):\t%Zd\n\n\n",aa,bb,cc);
    s.sprintf("A:\t%s\nB:\t%s\nLCM(A,B):\t%s\n",mpz_get_str(str,10,aa),mpz_get_str(str,10,bb),mpz_get_str(str,10,cc));
    this->textEdit->setText(s);
    // mpz_clears(aa,bb,cc,'\0');
}

QtGMP::~QtGMP(){
delete lineEdit1;
delete lineEdit2;
delete textEdit;

}
