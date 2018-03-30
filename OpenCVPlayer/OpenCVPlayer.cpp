#include "OpenCVPlayer.h"

PlayList playLists;

QImage ToQimage(int id, int w, int h)
{
	QImage image;
	for (size_t i = 0; i < playLists.size(); i++)
	{
		if (playLists[i]->mPlayID == id)
		{
			image = playLists[i]->ToQimage(w, h);
			break;
		}
	}
	return image;
}

OpenCVPlay* play = new OpenCVPlay;

OpenCVPlayer::OpenCVPlayer(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);	
}

void OpenCVPlayer::openCam()
{
	if (play->isOpen)
	{
		play->CloseCam();
		playLists.clear();
		ui.pushButton->setText("Open Cam");
	}
	else
	{
		play->OpenCam(0);
		playLists.push_back(play);
		ui.pushButton->setText("Close Cam");
	}
}


void OpenCVPlayer::resizeEvent(QResizeEvent * e)
{
	ui.myOpenGLWidget->resize(this->width(), this->height() - 100);
	ui.pushButton->move(this->width() / 2, this->height() - 80);
}
