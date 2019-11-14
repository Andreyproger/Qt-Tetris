#include "gametetrix.h"
//#include <QObject>

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
    {1,1,0,0},
    {0,1,1,0},
    {0,0,0,0},
    {0,0,0,0},
  };
  Figure sFig = s;
  _vecFigure.push_back(sFig);
  _vecFigure.push_back(sFig.rotate());
  _vecFigure.push_back(sFig.rotate());
  _vecFigure.push_back(sFig.rotate());

//  _timer = new QTimer();
//  _timer->setInterval(1000);
//  QObject::connect(_timer,
//                   SIGNAL(timeout()),
//                   this,
//                   SLOT()
////                   [this]()
////                    {
////                        _field.printField();
////                    }
//                   );
//  _timer->start();

}

GameTetrix::~GameTetrix()
{}

unsigned int GameTetrix::myRand()
{
    return (static_cast<unsigned int>(rand()) % (_vecFigure.size()));
}

void GameTetrix::start()
{
  auto figure = _vecFigure[myRand()];
  _field.insertFigure(new Figure(figure));
  _field.printField();
  std::cout << std::endl;

  bool gameOver = true;

  while(gameOver)
  {
      char input = char(getchar());
      system("cls");
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
            _field.rotateFigure();
            break;

           default:
            _field.moveDown();
            break;
      }
      //printf("printfield\n");
      _field.printField();
      std::cout << std::endl;

      if(_field.isActiveFigureOnField())
        continue;

      std::cout << "addr";
      figure = _vecFigure[myRand()];
      std::cout << "canAdd";

      gameOver = _field.canAddFigure(figure);

      if(gameOver) {
        Figure * newFigure = new Figure(figure);
        _field.insertFigure(newFigure);
      } else {

        std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        std::cout << "GAME OVER" << std::endl;
        std::cout << "YOUR SCORE: " << _field.score() << " !" << std::endl;
        std::cout << "Press enter to continue...";
        std::cin.get();

        system("pause");

        break;
      }
    }
}
