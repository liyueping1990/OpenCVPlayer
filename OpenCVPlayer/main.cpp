#include "OpenCVPlayer.h"
#include <QtWidgets/QApplication>
//OpenCVPlay play;
int main(int argc, char *argv[])
{
	//play.OpenCam();
	//play.ShowCam();
	QApplication a(argc, argv);
	OpenCVPlayer w;
	w.show();
	return a.exec();
}
