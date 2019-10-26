#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
  Figure();
  Figure(bool mask[4][4]);
  ~Figure();

  int height;
  int width;
  bool mask[4][4];

  Figure rotate(); // возвращает копию, чтобы не портили исходную фигуру

};

#endif // FIGURE_H
