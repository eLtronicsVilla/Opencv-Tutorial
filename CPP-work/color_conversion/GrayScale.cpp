/* 
Created on Thu Apr 11 12:50:34 2019

@author: brijesh Gupta

*/

#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs/imgcodecs.hpp"
#include <iostream>
using namespace std;
using namespace cv;
int main(int argc,char **argv)
{
	Mat image;
	Mat gray_image,hsv;
	image = imread( argv[1], 1 );
	//absdiff(img2,img1,diff);
	cvtColor(image,gray_image,COLOR_BGR2GRAY);
	cvtColor(image, hsv, COLOR_BGR2HSV);
	imwrite( "hsv.jpg", hsv);
	namedWindow("Grayimage",WINDOW_NORMAL);
	imshow( "Grayimage", gray_image );
	imshow("hsv",hsv);
	waitKey(0);
	return 0;
}
