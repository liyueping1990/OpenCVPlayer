#pragma once
#include <mutex>
#include <map>
#include <opencv2\highgui.hpp>
#include "QImage"


class OpenCVPlay
{
public:
	OpenCVPlay();
	virtual ~OpenCVPlay();

	bool OpenCam(int id);
	QImage ToQimage(int w = 0, int h = 0);
	void CloseCam();
	int mPlayID = 0;
	bool isOpen = false;

protected:
	void DecodCam();
	cv::VideoCapture mVideoCap;
	cv::Mat mPic;
	QImage mQimage;
	std::mutex mMutex;
	std::thread mThread;
};

