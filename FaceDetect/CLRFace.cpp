/*
 * CLRFace.cpp
 *
 *  Created on: 2017年3月31日
 *      Author: clover
 */

#include "CLRFace.h"
#include <opencv2/opencv.hpp>

CLRFace::CLRFace(std::string haarFaceYmlFilePath) {
	// TODO Auto-generated constructor stub
	mFaceCascade.load(haarFaceYmlFilePath);
	mFaceVector.clear();
}

CLRFace::~CLRFace() {
	// TODO Auto-generated destructor stub
}

void CLRFace::detectFase( const cv::Mat& frame, std::vector<cv::Rect>& faceVector, cv::Mat& resultDisplay )
{
	cv::Mat gray;
	faceVector.clear();
	if(frame.channels() != 1){
		cv::cvtColor(frame, gray, CV_RGB2GRAY);
		//cv::imshow("gray", gray);
		cv::equalizeHist(gray, gray);
		//cv::imshow("equalizeHist gray", gray);
	}else
		gray = frame.clone();

	mFaceCascade.detectMultiScale(gray, mFaceVector, 1.1, 3);
	resultDisplay = frame.clone();

	for(int i=0;i < mFaceVector.size(); i++){
		cv::rectangle(resultDisplay, mFaceVector[i], cv::Scalar(0,255,0));
	}
}
