#pragma once
#include <QtWidgets\qwidget.h>
#include <qopenglwidget.h>
#include <qpainter.h>
#include "OpenCvPlay.h"

extern QImage ToQimage(int id, int w, int h);

class MyOpenGLWidget : public QOpenGLWidget
{
public:
	MyOpenGLWidget();
	MyOpenGLWidget(QWidget *p = nullptr);
	void paintEvent(QPaintEvent *e);
	void timerEvent(QTimerEvent *e);
	virtual ~MyOpenGLWidget();

private:
	int mPlayID;
	QImage image;
};