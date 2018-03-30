#include "OpenCVPlayer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

	QApplication a(argc, argv);
	OpenCVPlayer w;
	w.show();
	return a.exec();
}
