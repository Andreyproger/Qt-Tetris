#include "figure.h"
#include <algorithm>
#include <iostream>


//class vector2d
//{
//    QVector2D
//    void rotate()
//    {
//        std::swap(_x,_y);
//    }
//    int _x;
//    int _y;
//}



//vector2d(const vector2d&)
//std::vector<vector2d>

Figure::Figure()
{}

Figure::Figure(bool newMask[4][4])
{
  //пробегаемся по ячейкам и находим самую правую
  int rightX = -1;
  int bottomY = -1;
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        mask[i][j] = newMask[i][j];
        if(newMask[i][j])
          {

            rightX = std::max(rightX, j);
            bottomY = std::max(bottomY,i);
          }
      }

  width = rightX + 1;
  height = bottomY + 1;
}

Figure::Figure(const Figure & fig)
{
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        this->mask[i][j] = fig.mask[i][j];
      }
  this->height = fig.height;
  this->width = fig.width;
}

Figure Figure::rotate()
{
  bool newMask[4][4];
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        newMask[i][3 - j] = this->mask[j][i];
      }
  Figure(newMask).printFigure(); /// todo delete
  return Figure(newMask);
  //сдвиг к левому верхнему углу
  int minX = 3;
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        if(newMask[j][i])
          {
            minX = std::min(j , minX);
          }
      }

  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      newMask[i][j] = newMask[i][(j+minX) % 4]; /// остаток от деления(кольцо вычетов по модулю 4)

  Figure(newMask).printFigure();

  return Figure(newMask);
}

//печать маски фигуры
void Figure::printFigure()
{
    for(int j = 0; j < height; j++)
    {
        for(int i = 0; i < width; i++)
        {
            std::cout << this->mask[j][i];
        }
        std::cout << std::endl;
    }
}

Figure::~Figure()
{}
