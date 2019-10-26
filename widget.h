#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>

#include <QDebug>

//#include <thread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent *);

    QRect goDown();

    QTimer * timer;

public slots:
    void Tomove();

protected:
    void keyPressEvent(QKeyEvent * e);

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H
