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
  Figure lineFig = line;
  _vecFigure.push_back(lineFig);
  _vecFigure.push_back(lineFig.rotate());

  bool j[4][4] = {
    {1,1,0,0},
    {1,0,0,0},
    {1,0,0,0},
    {0,0,0,0},
  };
  Figure jFig = j;
  _vecFigure.push_back(jFig);
  _vecFigure.push_back(jFig.rotate());
  _vecFigure.push_back(jFig.rotate());
  _vecFigure.push_back(jFig.rotate()); 

  bool t[4][4] = {
    {1,0,0,0},
    {1,1,0,0},
    {1,0,0,0},
    {0,0,0,0},
  };
  Figure tFig = t;
  _vecFigure.push_back(tFig);
  _vecFigure.push_back(tFig.rotate());
  _vecFigure.push_back(tFig.rotate());
  _vecFigure.push_back(tFig.rotate());

  bool l[4][4] = {
    {1,0,0,0},
    {1,0,0,0},
    {1,1,0,0},
    {0,0,0,0},
  };

  Figure lFig = l;
  _vecFigure.push_back(lFig);
  _vecFigure.push_back(lFig.rotate());
  _vecFigure.push_back(lFig.rotate());
  _vecFigure.push_back(lFig.rotate());

  bool q[4][4] = {
    {1,1,0,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  Figure qFig = q;
  _vecFigure.push_back(qFig);

  bool z[4][4] = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  Figure zFig = z;
  _vecFigure.push_back(zFig);
  _vecFigure.push_back(zFig.rotate());
  _vecFigure.push_back(zFig.rotate());
  _vecFigure.push_back(zFig.rotate());

  bool s[4][4] = {
    {0,1,1,0},
    {1,1,0,0},
    {0,0,0,0},
    {0,0,0,0},
  };

  Figure sFig = s;
  _vecFigure.push_back(sFig);
  _vecFigure.push_back(sFig.rotate());
  _vecFigure.push_back(sFig.rotate());
  _vecFigure.push_back(sFig.rotate());
}

GameTetrix::~GameTetrix()
{}

void GameTetrix::start()
{
  auto figure = _vecFigure[rand()%_vecFigure.size()];
  _field.insertFigure(new Figure(figure));
  _field.printField();
  std::cout << std::endl;

  // char seq[] = { 'a', 'a', 'a', 'd', 'd', 's', 's', 's',
  //                's', 's', 's', 's', 's', 's', 's', 's',
  //                's', 's', 's', 's', 's', 's', 's', 's'};
  int i = 0;

  bool gamePlay = true;
  while(gamePlay)
    {

      srand(time(NULL));
      char input = getch();

      //system("clear");

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

           case 'e':
            std::cout << std::endl << "In case 'e': ROTATE" << std::endl << std::endl;
            _field.rotateFigure();
            break;

           case 'q':
            gamePlay = false;
            break;
        }
      #if defined(_WIN32) || defined(_WIN64)
            system("cls");
      #elif defined(_linux)
            system("clear");
      #endif
      printf("printfield\n");
      _field.printField();
      std::cout << std::endl;

      if(_field.isActiveFigureOnField())
        continue;

      figure = _vecFigure[rand()%_vecFigure.size()];

      gamePlay = _field.canAddFigure(figure);

      if(gamePlay) {
        Figure * newFigure = new Figure(figure);
        _field.insertFigure(newFigure);
        //_field.moveDown();
      }
      else
      {
        std::cout << "GAME OVER";
        gamePlay = false;
        break;
      }
      _field.moveDown();
    }
}