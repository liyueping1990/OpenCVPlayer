#include "OpenCVPlay.h"
#pragma comment(lib, "opencv_world341d.lib")


OpenCVPlay::OpenCVPlay()
{
}


OpenCVPlay::~OpenCVPlay()
{
}

bool OpenCVPlay::OpenCam()
{
	mVideoCap.open(0);
	bool isOpen = mVideoCap.isOpened();
	if (isOpen)
	{
		std::thread(&OpenCVPlay::DecodCam, this).join();
	}
	
	return isOpen;
}


void OpenCVPlay::DecodCam()
{
	mMutex.lock();
	mVideoCap.read(mPic);
	cv::imshow("123", mPic);
	mMutex.unlock();
	_sleep(1);
}

void OpenCVPlay::ShowCam()
{
	if (mPic.data)
	{
		cv::imshow("cam", mPic);
		//cv::waitKey(1);
	}	
	else
	{
		DecodCam();
		ShowCam();
	}
}

QImage OpenCVPlay::ToQimage()
{
	mMutex.lock();
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (mPic.type() == CV_8UC1)
	{
		QImage image(mPic.cols, mPic.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = mPic.data;
		for (int row = 0; row < mPic.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, mPic.cols);
			pSrc += mPic.step;
		}
		mMutex.unlock();
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (mPic.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mPic.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mPic.cols, mPic.rows, mPic.step, QImage::Format_RGB888);
		mMutex.unlock();
		return image.rgbSwapped();
	}
	else if (mPic.type() == CV_8UC4)
	{
		//qDebug() << "CV_8UC4";
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)mPic.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, mPic.cols, mPic.rows, mPic.step, QImage::Format_ARGB32);
		mMutex.unlock();
		return image.copy();
	}
	else
	{
		//qDebug() << "ERROR: Mat could not be converted to QImage.";
		mMutex.unlock();
		return QImage();
	}
}
