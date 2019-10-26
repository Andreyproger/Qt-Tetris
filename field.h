#ifndef FIELD_H
#define FIELD_H
#include <figure.h>
#include <iostream>

const int width  = 10;
const int height = 15;

class Field
{
public:
  Field();
  ~Field();

  void moveDown();
  bool moveLeft();
  bool moveRight();

  void insertFigure(Figure * figure);
  bool canAddFigure(const Figure & figure);
  bool isActiveFigureOnField();
  void printField();

private:
  bool canDown();
  void eraseLines();
  int _fieldGame[height][width];

  Figure * _figure; ///< текущая фигура

  ///< вверхняя левая точка (координаты)
  int _x;       ///< по горизонтали
  int _y;       ///< по вертикали
};

#endif // FIELD_H
