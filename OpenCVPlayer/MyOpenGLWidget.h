#pragma once
#include <QtWidgets\qwidget.h>
#include <qopenglwidget.h>
#include <qpainter.h>
#include "OpenCvPlay.h"

class MyOpenGLWidget : public QOpenGLWidget
{
public:
	MyOpenGLWidget();
	MyOpenGLWidget(QWidget *p = nullptr);
	void paintEvent(QPaintEvent *e);
	void timerEvent(QTimerEvent *e);
	virtual ~MyOpenGLWidget();

private:
	OpenCVPlay play;
	QImage image;
};