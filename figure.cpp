#include "figure.h"

#include <algorithm>

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

Figure Figure::rotate()
{
  bool newMask[4][4];
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        newMask[i][3 - j] = this->mask[j][i];
      }

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
      newMask[i][j] = newMask[i][(j+minX)%4]; /// остаток от деления(кольцо вычетов по модулю 4)
  return Figure(newMask);
}

Figure::~Figure()
{}
