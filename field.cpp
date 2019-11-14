#include "field.h"

Field::Field()
{
  for(int j = 0; j < height; ++j)
    for(int i = 0; i < width; ++i)
      {
        _fieldGame[j][i] = 0; ///< пустые клетки поля
      }
}

Field::~Field()
{}

void Field::eraseLines()
{
  std::cout << "eraseLines()" << std::endl;
  int counter;
  for(int j = height - 1; j >= 0;)
    {
      counter = 0;
      for(int i = 0; i < width; ++i)
        {
          if(_fieldGame[j][i])
            ++counter;
        }
      if(width == counter)
        {
          for(int k = j; k > 0; --k) ///< смещаем всё что выше
            {
              for(int t = 0; t < width; ++t)
                {
                  _fieldGame[k][t] = _fieldGame[k - 1][t];
                }
            }
          ///< занулили верхнюю строчку
          for(int i = 0; i < width; ++i)
            {
              _fieldGame[0][i] = 0;
            }

           _score +=_scoreDelLine;

        }
      else
        {
          --j; ///< если ничего не сделано, то переходим к следующей строчке (двигаемся вверх)
        }
    }
}

int touchX(const Figure & fig)
{
  int touchx = width / 2 - fig.width / 2;
  return touchx;
}

int touchY(const Figure & fig)
{
///  Q_UNUSED(fig);
  int touchy = 0;
  return touchy;
}

///< проверка каждой клетки
bool Field::canDown()
{
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        if(_figure->mask[j][i])
          {
            if(_y + j + 1 >= height)
              return false;

            if(_fieldGame[_y + j + 1][_x + i])
              return false; ///не можем двинуть фигуру вниз
          }
      }
  return true;
}

void Field::moveDown()
{
  if(canDown())
    {
      ++_y;
      std::cout << "CAN DOWN" << std::endl;
    }
  else
    {
      std::cout << "CAN NOT DOWN" << std::endl;
      for(int i = 0; i < _figure->width; ++i)
        for(int j = 0; j < _figure->height; ++j)
          {
            if(_figure->mask[j][i])
              _fieldGame[_y + j][_x + i] = 1;
          }
      std::cout << "FOR DID" << std::endl;
      delete _figure;
      std::cout << "called  delete _figure;" << std::endl;
      _figure = nullptr;
      eraseLines();
    }

  //printf("movedown ret\n");
}

bool Field::moveLeft()
{
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        if(_figure->mask[j][i])
          {
            if(_x + i - 1 < 0)
              return false; ///< не можем двинуть фигуру влево

            if(_fieldGame[_y + j][_x + i - 1])
              return false; ///< поле занято -> не можем сдвинуть
          }
      }

  --_x;
  return true;
}

bool Field::moveRight()
{
  for(int i = 0; i < 4; ++i)
    for(int j = 0; j < 4; ++j)
      {
        if(_figure->mask[j][i])
          {
            if(_x + i + 1 >= width)
              return false;

            if(_fieldGame[_y + j][_x + i + 1])
              return false; ///не можем двинуть фигуру вправо
          }
      }

  ++_x;
  return true;
}

bool Field::canAddFigure(const Figure & figure)
{
  for(int i = 0; i < figure.width; ++i)
  {
    int border = -1;
    for(int j = figure.height - 1; j >= 0; --j)
    {
      if(figure.mask[j][i])
      {
        border = j;
      }
    }

    for(int j = border; j >= 0; --j)
    {
        //_figure->mask[j][i]
        if(_fieldGame[touchY(figure)+j][touchX(figure)+i])
          return false;
    }
  }
  return true;
}

void Field::insertFigure(Figure * figure)
{
  _y = touchY(*figure);
  _x = touchX(*figure);
  _figure = figure;
}

bool Field::isActiveFigureOnField()
{
  return _figure != nullptr;
}

void Field::printField() const
{

  std::cout << "SCORE: " << _score << " |" << std::endl;

  char _tempFieldGame[height][width];

  for(int j = 0; j < height; ++j)
  {
      for(int i = 0; i < width; ++i)
      {
        _tempFieldGame[j][i] = _fieldGame[j][i] ? 'X' : '.';
      }
  }

  if (_figure != nullptr) {
    for(int j = 0; j < _figure->height; ++j)
      {
        for(int i = 0; i < _figure->width; ++i)
          {
            if(_figure->mask[j][i])
            {
              _tempFieldGame[_y+j][_x+i]= '*'; //cell of current figure
            }
          }
      }
  }
  std::cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<std::endl;
  for(int j = 0; j < height; ++j)
  {
      std::cout<< j << "\t";
      for(int i = 0; i < width; ++i)
      {
        std::cout << _tempFieldGame[j][i];
      }
    std::cout << std::endl;
   }
}

void Field::rotateFigure()
{
    Figure * oldFigure = _figure;
    _figure = new Figure(_figure->rotate());
    delete oldFigure;
}

unsigned int Field::score() const
{
  return _score;
}
