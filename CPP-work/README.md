## Image_Blurring

# 1)Gaussian Blurring:    

Gaussian blurring is highly effective in removing gaussian noise from the image.

Parameters: (src	input image. dst output image. ksize	Gaussian kernel size. sigma	Gaussian standard deviation both x and y direction.)

# 2)Median Blurring:      

It takes median of all the pixels under kernel area and central element is replaced with this median value.
This is highly effective against salt-and-pepper noise in the images.

Parameters: src	input image. dst output image. ksize	linear size; it must be odd and greater than 1, for example: 3, 5, 7 ...

# 3)Bilateral Filtering: 

It is highly effective in noise removal while keeping edges sharp.

Parameters: src	input image. dst output image. ksize	Filter size. sigmaColor Filter sigma in the color space. sigmaSpace Filter sigma in the coordinate space.

## Morphological Dilation and Erosion 

# 1)Dilation:

It increases the white region in the image or size of foreground object increases.

# 2)Erosion:

Simply white region decreases in the image. 
It is useful for removing small white noises,detach two connected objects etc.

# 3)Opening:
Erosion followed by dilation.It is useful in removing noise

# 4)Closing:
Dilation followed by Erosion.
It is useful in closing small holes inside the foreground objects

# 5)Morphological Gradient:
It is the difference between dilation and erosion of an image.

# 6)Top Hat: 
It is the difference between input image and Opening of the image.

# 7)Black Hat:It is the difference between the closing of the image and input image.

Application level:    

- Eliminate noise in the image (Removing noise).

- Isolation of individual elements and joining disparate elements in an image.

->Finding the essence of the largest object or the smallest area (Finding of brightness bumps or holes in an image)

## Histogram Equalization    

Histogram Equalization is a image processing technique used to improve contrast in images.

# canny edge detection:

Canny( detected_edges, detected_edges, lowThreshold, highThresold, kernel_size );

- Remove the noise in the image with a 5x5 Gaussian filter.

- Finding Intensity Gradient of the Image:Filtered with sobel kernel in both x an y direction(we get gradient and direction)

- Non-maximum Suppression:To remove any unwanted pixels which may not constitute the edge and preserves the edges.

# Threshoding :

- Input image is converted into binary image.

- If pixel value is greater than a threshold value, it is assigned one value (may be white), else it is assigned another value (may be black).

- In normal thresoding,we used a global value as threshold value. But it may not be good in all the conditions where image has different lighting conditions in different areas.

- In that case, we go for adaptive thresholding. In this, the algorithm calculate the threshold for a small regions of the image.

- So we get different thresholds for different regions of the same image and it gives us better results for images with varying illumination.

# color conversions:

GrayScale image:

- convert our image from BGR(3 channels) to Grayscale format(single channel).

- Reduces the number of operation when we doing on Grayimage compare to BGR image.

# HSV conversion:

- HSV colour space also has 3 channels: the Hue, the Saturation and the Value, or intensity.

1)The Hue channel represents the "colour"(0-180).

2)The saturation channel is the "amount" of colour(0-255) .

3)value or intensity is the brightness of the colour(255).

