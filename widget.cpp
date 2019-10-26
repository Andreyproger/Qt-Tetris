#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>

const int shiftX = 10; ///< движение вниз
const int shiftY = 7; ///< движение влево/вправо

int dx = 5;
int dy = 5;

bool newFigure = false;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(Tomove()));
    timer->start(750);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::keyPressEvent(QKeyEvent *e)
{
    qDebug() << e->text();
}

QRect Widget::goDown()
{
    QRect rect(0, 0, 30, 30);
    //double x = dx;
    //double y = y;
    rect.moveTo(QPoint(dx, dy));
    //dx += shiftX;
    dy += shiftY; ///< движение вниз
    return rect;
}

void Widget::paintEvent(QPaintEvent * event)
{
    Q_UNUSED(event);

    QPainter * paint = new QPainter(this);
    paint->drawRect(goDown()); // drawEllipse(80,80,60,60);
}

void Widget::Tomove()
{
    //goDown();
    update();
}
