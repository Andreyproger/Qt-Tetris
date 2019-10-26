//#include "widget.h"

//#include <QApplication>
//#include <QtDebug>

#include <iostream>
#include "gametetrix.h"
using namespace std;

int main(int argc, char *argv[])
{
  std::cout << "started\n";
  GameTetrix tetrix;

  tetrix.start();
  //system("pause");
  return 0;
}
//    QApplication a(argc, argv);
//    Widget w;
//    w.show();

//    return a.exec();
