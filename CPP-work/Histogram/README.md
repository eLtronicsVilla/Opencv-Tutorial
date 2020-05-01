# Histogram

In simple word Histogram is an approximate representation of the distribution of numerical or categorical data.

## Image- Histogram

In image processing Histogram is a frequency distribution of pixel intensity value. It is a graphical representation of pixel intencity value (bins) and occurance (frequency ) of that value.

## Normalization 

Normalization is a common practice with histofram to get a better representation.
We divide the histogram component by the number of pixel of histogram image representing the frequency value.We cn also divide by total number of pixel in the image to get number between 0 and 1.

## Uses for Histogram

1) Image Inhancement
2) Image Statistics
3) Image Compression
4) Image segmentation

## Histogram Equalization

Histogram equalization is the process for increasing the contrast in the image by spreading the histogram out to be approximately uniformly distributed.

Histogram equalization achieves by using transfer function.If image is gray scale (intensity value range 0-255) , we first convert it in range 0-1 by dividing the value by dimention(m*n) of image.Then we can map it one by one pixel.Again we convert it in range 0-256 value. The trasfer function  is strictly monotonically increasing function. 

Histogram can be used for contrast streching for the image.

## Opencv API's

 void calcHist(const Mat* images, int nimages, const int* channels, InputArray mask, OutputArray hist, int dims, const int* histSize, const float** ranges, bool uniform=true, bool accumulate=false )
 
 Parameters:	

    images – Source arrays. They all should have the same depth, CV_8U or CV_32F , and the same size. Each of them can have an arbitrary number of channels.   
    nimages – Number of source images.    
    channels – List of the dims channels used to compute the histogram. The first array channels are numerated from 0 to images[0].channels()-1 , the second array channels are counted from images[0].channels() to images[0].channels() + images[1].channels()-1, and so on.    
    mask – Optional mask. If the matrix is not empty, it must be an 8-bit array of the same size as images[i] . The non-zero mask elements mark the array elements counted in the histogram.   
    hist – Output histogram, which is a dense or sparse dims -dimensional array.    
    dims – Histogram dimensionality that must be positive and not greater than CV_MAX_DIMS (equal to 32 in the current OpenCV version).    
    histSize – Array of histogram sizes in each dimension.     
    ranges – Array of the dims arrays of the histogram bin boundaries in each dimension. When the histogram is uniform ( uniform =true), then for each dimension i it is enough to specify the lower (inclusive) boundary L_0 of the 0-th histogram bin and the upper (exclusive) boundary U_{\texttt{histSize}[i]-1} for the last histogram bin histSize[i]-1 . That is, in case of a uniform histogram each of ranges[i] is an array of 2 elements. When the histogram is not uniform ( uniform=false ), then each of ranges[i] contains histSize[i]+1 elements: L_0, U_0=L_1, U_1=L_2, ..., U_{\texttt{histSize[i]}-2}=L_{\texttt{histSize[i]}-1}, U_{\texttt{histSize[i]}-1} . The array elements, that are not between L_0 and U_{\texttt{histSize[i]}-1} , are not counted in the histogram.      
    uniform – Flag indicating whether the histogram is uniform or not (see above).    
    accumulate – Accumulation flag. If it is set, the histogram is not cleared in the beginning when it is allocated. This feature enables you to compute a single histogram from several sets of arrays, or to update the histogram in time.   
    
 void cv::normalize 	( 	InputArray  	src, InputOutputArray  	dst,	double  	alpha = 1,double  	beta = 0,int  	norm_type = NORM_L2,	int  	dtype = -1,	InputArray  	mask = noArray() ) 	
 
 Parameters
 
    src -	input array.
    dst -	output array of the same size as src .
    alpha- 	norm value to normalize to or the lower range boundary in case of the range normalization.
    beta -	upper range boundary in case of the range normalization; it is not used for the norm normalization.
    norm_type -	normalization type (see cv::NormTypes).
    dtype -	when negative, the output array has the same type as src; otherwise, it has the same number of channels as src and the depth =CV_MAT_DEPTH(dtype).
    mask-	optional operation mask. 
