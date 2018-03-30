#include "OpenCVPlay.h"
#include <opencv2/imgproc/imgproc.hpp> 
#pragma comment(lib, "opencv_world341d.lib")


OpenCVPlay::OpenCVPlay()
{
}


OpenCVPlay::~OpenCVPlay()
{
}

bool OpenCVPlay::OpenCam(int id)
{
	mVideoCap.open(id);
	this->mPlayID = id;
	isOpen = mVideoCap.isOpened();
	if (isOpen)
	{
		mThread = std::move(std::thread(&OpenCVPlay::DecodCam, this));
		mThread.detach();
	}
	
	return isOpen;
}


void OpenCVPlay::DecodCam()
{
	while (true || this->isOpen)
	{
		mMutex.lock();
		mVideoCap.read(mPic);
		mMutex.unlock();
		_sleep(1);
	}
}

QImage OpenCVPlay::ToQimage(int w, int h)
{	
	//resize(temImage, dstImage1, Size(temImage.cols / 2, temImage.rows / 2), 0, 0, INTER_LINEAR);
	if (!this->isOpen)
	{
		QImage image;
		return image;
	}

	cv::Mat dstMat;
	if (w == 0 && h == 0)
	{
		dstMat = mPic.clone();
	}
	else
	{
		cv::Size dsize = cv::Size(w, h);
		cv::Mat temp = cv::Mat(dsize, CV_32S);
		cv::resize(mPic, dstMat, dsize);
		//dstMat = temp.clone();
	}


	mMutex.lock();
	// 8-bits unsigned, NO. OF CHANNELS = 1  
	if (dstMat.type() == CV_8UC1)
	{
		QImage image(dstMat.cols, dstMat.rows, QImage::Format_Indexed8);
		// Set the color table (used to translate colour indexes to qRgb values)  
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat  
		uchar *pSrc = dstMat.data;
		for (int row = 0; row < dstMat.rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, dstMat.cols);
			pSrc += dstMat.step;
		}
		mMutex.unlock();
		return image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3  
	else if (dstMat.type() == CV_8UC3)
	{
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)dstMat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, dstMat.cols, dstMat.rows, dstMat.step, QImage::Format_RGB888);
		mMutex.unlock();
		return image.rgbSwapped();
	}
	else if (dstMat.type() == CV_8UC4)
	{
		//qDebug() << "CV_8UC4";
		// Copy input Mat  
		const uchar *pSrc = (const uchar*)dstMat.data;
		// Create QImage with same dimensions as input Mat  
		QImage image(pSrc, dstMat.cols, dstMat.rows, dstMat.step, QImage::Format_ARGB32);
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

void OpenCVPlay::CloseCam()
{
	this->isOpen = false;
	mVideoCap.release();
}
