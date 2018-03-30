#include "MyOpenGLWidget.h"

MyOpenGLWidget::MyOpenGLWidget()
{
}

MyOpenGLWidget::MyOpenGLWidget(QWidget * p) : QOpenGLWidget(p)
{
	startTimer(1);
}

void MyOpenGLWidget::paintEvent(QPaintEvent * e)
{
	image = ToQimage(0, this->width(), this->height());

	QPainter painter;
	painter.begin(this);
	painter.drawImage(QPoint(0, 0), image);
	painter.end();
}

void MyOpenGLWidget::timerEvent(QTimerEvent * e)
{
	this->update();
}


MyOpenGLWidget::~MyOpenGLWidget()
{
}
