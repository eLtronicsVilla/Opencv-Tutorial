//Use the cv::DescriptorExtractor interface in order to find the feature vector correspondent to the keypoints.Specifically :
//
//    Use cv::xfeatures2d::SURFand its function cv::xfeatures2d::SURF::compute to perform the required calculations.
//    Use a cv::DescriptorMatcher to match the features vector
//    Use the function cv::drawMatches to draw the detected matches.


#include <iostream>
#include "opencv2/core.hpp"
#ifdef HAVE_OPENCV_XFEATURES2D
#include "opencv2/highgui.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
using namespace cv;
using namespace cv::xfeatures2d;
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    
    Mat img1 = imread("E:/workspace/WFH/imgg1.png", IMREAD_GRAYSCALE);
    Mat img2 = imread("E:/workspace/WFH/imgg2.png", IMREAD_GRAYSCALE);
    if (img1.empty() || img2.empty())
    {
        cout << "Could not open or find the image!\n" << endl;
        
        return -1;
    }
    //-- Step 1: Detect the keypoints using SURF Detector, compute the descriptors
    int minHessian = 400;
    Ptr<SURF> detector = SURF::create(minHessian);
    std::vector<KeyPoint> keypoints1, keypoints2;
    Mat descriptors1, descriptors2;
    detector->detectAndCompute(img1, noArray(), keypoints1, descriptors1);
    detector->detectAndCompute(img2, noArray(), keypoints2, descriptors2);
    //-- Step 2: Matching descriptor vectors with a brute force matcher
    // Since SURF is a floating-point descriptor NORM_L2 is used
    Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::BRUTEFORCE);
    std::vector< DMatch > matches;
    matcher->match(descriptors1, descriptors2, matches);
    //-- Draw matches
    Mat img_matches;
    drawMatches(img1, keypoints1, img2, keypoints2, matches, img_matches);
    //-- Show detected matches
    imshow("Matches", img_matches);
    waitKey();
    return 0;
}
#else
int main()
{
    std::cout << "This tutorial code needs the xfeatures2d contrib module to be run." << std::endl;
    return 0;
}
#endif
