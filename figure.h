#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
  Figure();
  Figure(bool mask[4][4]);
  Figure(const Figure &);
  ~Figure();

  int height;
  int width;
  bool mask[4][4];

  Figure rotate(); // возвращает копию, чтобы не портили исходную фигуру
  void rotateFigure();
  void printFigure();
};

#endif // FIGURE_H
