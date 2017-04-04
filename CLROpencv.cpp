//============================================================================
// Name        : CLROpencv.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <opencv2/opencv.hpp>
#include "FaceDetect/CLRFace.h"
using namespace std;

int main() {
	cv::Mat frame = cv::imread("/home/clover/workspace/TOOLS/opencv-3.1.0/samples/data/lena.jpg");
	cv::Mat face = cv::imread("/home/clover/workspace/faceDataset/jaffe/KA.AN1.39.tiff");
	cv::VideoCapture cap = cv::VideoCapture(0);
	CLRFace *a_face = new CLRFace("/home/clover/workspace/TOOLS/opencv-3.1.0/data/haarcascades/haarcascade_frontalface_default.xml");
	std::vector<cv::Rect> faceVector;
	cv::Mat faceMat;
	//cap.set(6, 2);
	//cap.set(3, 752);
	//cap.set(4, 480);
	/*
	if (cap.isOpened()) {
		for (;;) {
			cap >> frame;
			a_face->detectFase(frame, faceVector, faceMat);
			cv::imshow("face", faceMat);
			cv::imshow("image", frame);
			cv::waitKey(1);

		}
	} else {
		std::cout << "cap err" << std::endl;
	}
	*/
	cv::imshow("image", face);
	a_face->detectFase(face, faceVector, faceMat);
	cv::imshow("face", faceMat);

	cv::waitKey(0);
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
