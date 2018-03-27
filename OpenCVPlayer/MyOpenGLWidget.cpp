#include "MyOpenGLWidget.h"

MyOpenGLWidget::MyOpenGLWidget()
{
}

MyOpenGLWidget::MyOpenGLWidget(QWidget * p) : QOpenGLWidget(p)
{
	startTimer(1);
	play.OpenCam();
}

void MyOpenGLWidget::paintEvent(QPaintEvent * e)
{
	image = play.ToQimage();

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
