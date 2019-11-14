#ifndef FIELD_H
#define FIELD_H
#include "figure.h"
#include <iostream>
//#include <QtGlobal>

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
  void printField() const;
  void rotateFigure();
  unsigned int score() const;

private:
  bool canDown();
  void eraseLines();
  int _fieldGame[height][width];

  Figure * _figure; ///< текущая фигура

  ///< вверхняя левая точка (координаты) фигуры
  int _x;       ///< по горизонтали
  int _y;       ///< по вертикали
  const int _scoreDelLine = 100;
  unsigned int _score = 0; ///< количество очков в игре
};

#endif // FIELD_H
