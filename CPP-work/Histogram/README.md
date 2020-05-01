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
