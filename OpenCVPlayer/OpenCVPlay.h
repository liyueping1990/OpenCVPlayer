#pragma once
#include <mutex>
#include <opencv2\highgui.hpp>
#include "QImage"

class OpenCVPlay
{
public:
	OpenCVPlay();
	virtual ~OpenCVPlay();

	bool OpenCam();
	void DecodCam();
	void ShowCam();
	QImage ToQimage();

protected:
	cv::VideoCapture mVideoCap;
	cv::Mat mPic;
	QImage mQimage;
	std::mutex mMutex;
};

