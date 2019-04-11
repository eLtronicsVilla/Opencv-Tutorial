/* 
Created on Thu Apr 11 13:27:20 20191
@author: brijesh Gupta

*/

#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;
int main(int argc,char **argv)
{
	Mat image=imread(argv[1],1);
	Mat dst;
	cvtColor(image,image,COLOR_BGR2GRAY);
	threshold(image,dst,127,255,THRESH_BINARY);
	imwrite("thresh_binary.jpg",dst);
	threshold(image,dst,127,255,THRESH_BINARY_INV);
	imwrite("thresh_binary_inv.jpg",dst);
	threshold(image,dst,127,255,THRESH_TRUNC);
	imwrite("thesh_trunc.jpg",dst);
	threshold(image,dst,127,255,THRESH_TOZERO);
	imwrite("thresh_tozero.jpg",dst);
	threshold(image,dst,127,255,THRESH_TOZERO_INV);
	imwrite("thresh_tozero_inv.jpg",dst);
	adaptiveThreshold(image,dst,255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,5,10);
	imwrite("adaptive_thresh_binary.jpg",dst);
	adaptiveThreshold(image,dst,255,ADAPTIVE_THRESH_GAUSSIAN_C,THRESH_BINARY,17,2);
	imwrite("adaptive_thresh_gaussian.jpg",dst);
	imshow("input",image);
	imshow("output",dst);
	waitKey(0);
}
