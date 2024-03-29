#ifndef GAMETETRIX_H
#define GAMETETRIX_H

#include "figure.h"
#include "field.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <time.h>
//      #if defined(_WIN32) || defined(_WIN64)
        #include <conio.h>
//#elif defined(_linux)
//#include <curses.h>


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

public:
  GameTetrix();
  ~GameTetrix();

  void start();
};

#endif // GAMETETRIX_H
