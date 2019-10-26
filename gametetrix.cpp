#include "gametetrix.h"

GameTetrix::GameTetrix()
{
  //Figure f;
  bool line[4][4] = {
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {1,0,0,0},
  };
  _vecFigure.push_back(line);

  bool j[4][4] = {
    {1,1,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(j);

  bool t[4][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(t);

  bool l[4][4] = {
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(l);

  bool q[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(q);

  bool z[4][4] = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(z);

  bool s[4][4] = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  _vecFigure.push_back(s);
}

GameTetrix::~GameTetrix()
{}

void GameTetrix::start()
{
  auto figure = _vecFigure[uint(rand()) % _vecFigure.size()];
  _field.insertFigure(&figure);
  _field.printField();
  std::cout << std::endl;

  char seq[] = { /*'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a',*/
                 'a', 'a', 'a', 'd', 'd', 'd', 'd', 'd',
                 'd', 'd', 'd', 'd', 'd', 's', 's', 's',
                 's', 's', 's', 's', 's', 's', 's', 's',
                 's', 's', 's', 's', 's', 's', 's', 's',
                 's', 's', 's', 's', 's', 's', 's', 's',
                 's', 's', 's', 's', 's', 's', 's', 's', 's'};
  int i = 0;
  //return;
  while(true)
    {
      //char input = getchar();
      //std::cout << "-" << input << std::endl;
      char input = seq[i++];
      switch(input)
        {
          case 'a':
            _field.moveLeft();
            break;

           case 'd':
            _field.moveRight();
            break;

           case 's':
            _field.moveDown();
            break;
        }
      _field.printField();
      std::cout << std::endl;

      if(_field.isActiveFigureOnField())
        continue;
      std::cout << "addr";
      figure = _vecFigure[uint(rand()) % _vecFigure.size()];
      std::cout << "canAdd";
      if(_field.canAddFigure(figure))
      {
        std::cout << "insFig";
        qDebug() << "insFig";
        figure = _vecFigure[uint(rand()) % _vecFigure.size()];
        _field.insertFigure(&figure);
      }
      else
        {
          std::cout << "GAME OVER";
          break;
        }
    }
}
