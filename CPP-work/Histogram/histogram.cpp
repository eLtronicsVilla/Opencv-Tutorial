
/* 
Created on Fri May 01 16:04:20 2020
@author: eLtronicsvilla
*/


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;


int histogram2[256];

void hist_plot(Mat img)
{

    // allcoate memory for no of pixels for each intensity value
    int histogram[256];

    // initialize all intensity values to 0
    for (int i = 0; i < 255; i++)
    {
        histogram[i] = 0;
    }

    // calculate the no of pixels for each intensity values
    for (int y = 0; y < img.rows; y++)
        for (int x = 0; x < img.cols; x++)
            histogram[(int)img.at<uchar>(y, x)]++;


    // draw the histograms
    int hist_w = 512; int hist_h = 400;
    int bin_w = cvRound((double)hist_w / 256);

    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));

    // find the maximum intensity element from histogram
    int max = histogram[0];
    for (int i = 1; i < 256; i++) {
        if (max < histogram[i]) {
            max = histogram[i];
        }
    }

    // cumulate the frequency of respective bins
    for (int i = 0; i < 255; i++) {
        histogram2[i] += histogram[i];
    }

    // normalize the histogram between 0 and histImage.rows

    for (int i = 0; i < 255; i++) {
        histogram2[i] = ((double)histogram2[i] / max) * histImage.rows;
    }


    // draw the intensity line for histogram
    for (int i = 1; i < 255; i++)
    {
       /* line(histImage, Point(bin_w * (i), hist_h),
            Point(bin_w * (i), hist_h - histogram2[i]),
            Scalar(0, 0, 0), 1, 8, 0);*/
        line(histImage, Point(bin_w * (i - 1), hist_h - histogram2[i-1]),
            Point(bin_w * (i), hist_h - histogram2[i]),
            Scalar(0, 0, 0), 2, 8, 0);
    }

    // display histogram
    namedWindow("Intensity Histogram", WINDOW_AUTOSIZE);
    imshow("Intensity Histogram", histImage);
    waitKey(5);

}



/** @function main */
int main(int argc, char** argv)
{
    Mat gray,img;

    // initialize all intensity values to 0
    for (int i = 0; i < 255; i++)
    {
        histogram2[i] = 0;
    }
    VideoCapture cap("../../video.mp4");

    if (!cap.isOpened())
    {
        cout << "Could not initialize capturing...\n";
        return 0;
    }


    for (;;)
    {
        cap >> img;

        if (img.empty())
            break;

        // resize(img, img, Size(img.cols / 2, img.rows / 2));
        cvtColor(img, img, COLOR_BGR2GRAY);

       
	// call function for histogram plot
        hist_plot(img);

    }
    // Release video capture
    cap.release();
    // Closes all the frames
    destroyAllWindows();
    return 0;
}


    
