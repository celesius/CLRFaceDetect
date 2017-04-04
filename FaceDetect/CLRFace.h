/*
 * CLRFace.h
 *
 *  Created on: 2017年3月31日
 *      Author: clover
 */

#ifndef FACEDETECT_CLRFACE_H_
#define FACEDETECT_CLRFACE_H_

#include <opencv2/opencv.hpp>
#include <vector>

class CLRFace {
	cv::CascadeClassifier mFaceCascade;
	std::vector<cv::Rect> mFaceVector;
public:
	CLRFace(std::string haarFaceYmlFilePath);
	virtual ~CLRFace();
	void detectFase(const cv::Mat& frame, std::vector<cv::Rect>& faceVector, cv::Mat& resultDisplay);
};

#endif /* FACEDETECT_CLRFACE_H_ */
