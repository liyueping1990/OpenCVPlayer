#pragma once
#include <mutex>
#include <opencv2\highgui.hpp>
#include "QImage"

class OpenCVPlay
{
public:
	OpenCVPlay();
	virtual ~OpenCVPlay();

	static OpenCVPlay* getInstance()
	{
		OpenCVPlay oplay;
		return &oplay;
	}

	bool OpenCam();
	void DecodCam();
	QImage ToQimage();

protected:
	cv::VideoCapture mVideoCap;
	cv::Mat mPic;
	QImage mQimage;
	std::mutex mMutex;
	std::thread mThread;
};

