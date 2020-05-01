
/* 
Created on Fri May 01 15:34:27 2020
@author: eLtronicsvilla
*/


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/// Global Variables

cv::Mat accumulatedHist = cv::Mat::zeros(1,256,CV_32FC1);


void hist_plot(Mat img)
{
    int histSize = 256;
    float range[] = { 0, 256 }; //the upper boundary is exclusive
    const float* histRange = { range };
    bool uniform = true, accumulate = false;
    Mat hist;
    cv::calcHist(&img, 1, 0, Mat(), hist, 1, &histSize, &histRange, uniform, accumulate);
    
    int hist_w = 512, hist_h = 800;
    int bin_w = cvRound((double)hist_w / histSize);
    
    Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    hist.convertTo(hist, CV_32FC1);
    for (int i = 0; i < histSize; i++) {
        accumulatedHist.at<float>(i) += hist.at<float>(i);
        std::cout << "Accumulated : " << accumulatedHist.at<float>(i) << ", original = " << hist.at<float>(i) << std::endl;
    }
    convertScaleAbs(hist, hist);
    normalize(accumulatedHist, accumulatedHist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    //normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    
    for (int i = 1; i < histSize; i++)
    {
        line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(accumulatedHist.at<float>(i - 1))),
            Point(bin_w * (i), hist_h - cvRound(accumulatedHist.at<float>(i))),
            Scalar(255, 0, 0), 2, 8, 0);
     
    }
    
    imshow("calcHist Demo", histImage);
    waitKey(5); 

}



/** @function main */
int main(int argc, char** argv)
{
    Mat gray;

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


    
