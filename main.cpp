//Your comment will always be highly valued,MY EMAIL: wayne.winged@gmail.com

#include <QApplication>
#include "qtgmp.hpp"
#include <QTextStream>
#include <fstream>
#include <iostream>

#include <QTextCodec>

QCoreApplication* createApplication(int &argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
        if (!qstrcmp(argv[i], "-no-gui"))
            return new QCoreApplication(argc, argv);
    return new QApplication(argc, argv);
}


int main(int argc, char* argv[])
{
   QScopedPointer<QCoreApplication> app(createApplication(argc, argv));

	if (qobject_cast<QApplication *>(app.data())) {
	std::cout<<"GUI"<<std::endl;
		QTextCodec *codec = QTextCodec::codecForName("GB2312");
		QtGMP *win=new QtGMP();
		win->resize(500, 500);
		win->setWindowTitle(codec->toUnicode("GMP in Qt(大数运算库的Qt界面)"));
		win->show();	
		
    } else {
		std::cout<<"Non GUI"<<std::endl;
		std::ofstream out("output.txt");
		// QTextStream out(stdout);
		out<<"\nGMP is Great!!!  Qt is Great!!!\nenjoy this demo GMP Qt Widget:\n";
		}
	
	std::cout<<"quiting.........\n";
	return app->exec();
}
