/* 
Created on Thu Apr 11 12:37:20 2019

@author: brijesh Gupta

*/

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;
vector<Mat>channels;
Mat hist_image;
Mat src;
Mat dst;
int main(int argc, char**argv)
{
	Mat image=imread(argv[1],cv::IMREAD_COLOR);
	src=image;
	cvtColor(image, image, COLOR_BGR2GRAY);
	equalizeHist(image,dst);
	imshow("input",image);
	imshow("output",dst);
	imwrite("hist_gray_img.jpg",dst);
	cvtColor(src,hist_image,COLOR_BGR2HSV);
	split(hist_image,channels);
	equalizeHist(channels[0],channels[0]);
	merge(channels,hist_image);
	imshow("channel0",channels[0]);
	imshow("output",hist_image);
	imwrite("hist_eql.jpg",hist_image);
	waitKey(0);
}