/* 
Created on Thu Apr 11 13:10:20 2019

@author: brijesh Gupta

*/

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
 
using namespace cv;
using namespace std;

Mat image,dst;
int erosion_size = 1; 
int main(int argc, const char** argv)
{
  image = imread(argv[1], cv::IMREAD_COLOR);
  cvtColor(image, image, COLOR_BGR2GRAY);
  Mat element = getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),cv::Point(erosion_size, erosion_size) );
  //reduces white region
  erode(image,dst,element);
  imwrite("erode.jpg",dst); 
  //increases the white region
  dilate(image,dst,element);
  imwrite("dilate.jpg",dst);
  //diff of dilation and ersion
  morphologyEx(image,dst,MORPH_GRADIENT, element);
  imwrite("morph_gradient.jpg",dst);
  //ersion followed by dilation
  morphologyEx(image,dst,MORPH_OPEN,element);
  imwrite("morph_open.jpg",dst);
  //dilation followed by erosion
  morphologyEx(image,dst,MORPH_CLOSE,element); 
  imwrite("morph_close.jpg",dst);
  //diff between opening image and input image
  morphologyEx(image,dst,MORPH_TOPHAT,element);
  imwrite("morph_tophat.jpg",dst);
  //diff b/w closing and input image
  morphologyEx(image,dst,MORPH_BLACKHAT,element);
  imwrite("morph_blackhat.jpg",dst);
  morphologyEx(image,dst,MORPH_HITMISS,element);
  imwrite("morph_hitmiss.jpg",dst);
  namedWindow( "Display window", WINDOW_AUTOSIZE );
  imshow( "Display window", image );
  waitKey(0);
  return 0;
}