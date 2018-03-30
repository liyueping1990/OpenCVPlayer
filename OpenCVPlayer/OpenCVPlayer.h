#pragma once
#include <map>
#include <vector>
#include <QtWidgets/QMainWindow>
#include "ui_OpenCVPlayer.h"
#include "OpenCVPlay.h"

typedef std::vector<OpenCVPlay*> PlayList;
class OpenCVPlayer : public QMainWindow
{
	Q_OBJECT

public:
	OpenCVPlayer(QWidget *parent = Q_NULLPTR);
	void resizeEvent(QResizeEvent *e);

	
public slots:
	void openCam();

private:
	/*OpenCVPlay play;*/
	Ui::OpenCVPlayerClass ui;
};
