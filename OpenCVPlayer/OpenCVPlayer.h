#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_OpenCVPlayer.h"
#include "OpenCVPlay.h"


class OpenCVPlayer : public QMainWindow
{
	Q_OBJECT

public:
	OpenCVPlayer(QWidget *parent = Q_NULLPTR);
	void openCam();

private:
	/*OpenCVPlay play;*/
	Ui::OpenCVPlayerClass ui;
};
