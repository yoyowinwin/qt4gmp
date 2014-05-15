#include <QApplication>
#include "qtgmp.hpp"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QtGMP *win=new QtGMP();
    win->resize(500, 500);
    win->setWindowTitle("GMP in Qt(大数运算库的Qt界面)");
    win->setFocusPolicy(Qt::StrongFocus);
    win->show();

    return app.exec();
}
