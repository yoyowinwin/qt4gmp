//Your comment will always be highly valued,MY EMAIL: wayne.winged@gmail.com

#ifndef QTGMP_HPP
#define QTGMP_HPP

#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

class QtGMP : public QWidget
{
    Q_OBJECT
public:
    QtGMP(QWidget * parent = 0);
    ~QtGMP();
public slots:
    void mulAB();
    void powAB();
    void fac();
    void nprime();
    void gcd();
    void lcm();
private:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QTextEdit *textEdit;

};

#endif // QTGMP_HPP
