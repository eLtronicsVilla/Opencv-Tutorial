/* 
Created on Thu Apr 11 12:37:20 2019

@author: brijesh Gupta

*/

/*
Find the contour:-

What is contour:
contour is a curve joining all continous points, having same color or intensity. 
The contours are useful tool for shape analysis and object detection and recognition. 
To determine the number of objects in the image.

Command to execute:
cmake .
make
./find_contour input_image.jpg

*/


#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
Mat src;
Mat gray,edges;
int main(int argc,char **argv)
{
	Mat src= imread(argv[1],1);
	Mat gray, edges;
	cvtColor(src,gray,COLOR_BGR2GRAY);
	GaussianBlur(gray,edges,Size(5,5),1,1);
	Canny(edges,edges,0,30,3);
	imshow("gray",gray);
	imshow("edges",edges);
	imwrite("canny_edge.jpg",edges);
	waitKey(0);
}