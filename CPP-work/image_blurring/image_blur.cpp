/* 
Created on Thu Apr 11 12:37:20 2019

@author: brijesh Gupta

*/


#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include <iostream>
using namespace std;
using namespace cv;
Mat dst;
int main(int argc, const char** argv)
{
	Mat src=imread(argv[1],1);
	GaussianBlur(src, dst, Size(5,5), 1.5, 1.5);
	imwrite("GaussianBlur.jpg",dst);
	bilateralFilter(src,dst,15,80,80);
	imwrite("bilateralFilter.jpg",dst);
	medianBlur(src,dst,5);
	imwrite("medianblur_output.jpg",dst);
	imshow("input",src);
	waitKey(0);
}
