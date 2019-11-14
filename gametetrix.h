#ifndef GAMETETRIX_H
#define GAMETETRIX_H

//#ifdef NAME_MACROS

//#endif

#ifdef UnixClean
        system("cls");
#endif

#ifdef WinClean
        system("clear");
#endif


#include "figure.h"
#include "field.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iostream>

//#include <QTimer>

///Figure
///= {
///      {1,0,0,0},
///      {1,0,0,0},
///      {1,0,0,0},
///      {1,0,0,0}
///};

///.mask = {
///  {1,0,0,0},
///  {1,0,0,0},
///  {1,0,0,0},
///  {1,0,0,0}},

///управление стрелочками
class GameTetrix
{
  //определить базовые фигуры
private:
  std::vector<Figure> _vecFigure;
  Field _field;

//  QTimer * _timer;

public:
  GameTetrix();
  ~GameTetrix();

  void start();

//private slots:
//    void updateTime();

private:
    unsigned int myRand();


};

#endif // GAMETETRIX_H
