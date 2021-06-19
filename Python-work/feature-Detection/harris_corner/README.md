## Feature Detection
To identify any object , we need some known feature to describe about that object.These feature can be shape,size,edge,corners,color,etc.
In an image finding a surface is more difficult than finding edge and finding corner is more easy than finding edge.
So I can say that corner is one of the most important feature to identify the object.

Types of Image features:
1. Edges
2. Corners (known as interest points)
3. Blobs (known as region of interest)

# How do we find good feature(corners)?

In an image , corner represents by intersection of two edges. At this intersection point direction of the edge is changed.Hence gradient of image in both direction has high variation. Look for the region which have maximum variation when moved (by a small amount) in all region around it.This process is called feature detection.
A computer also should describe the region around the feature so that it can find it in other images. So called description is called Feature Description. 
Once you have feature in an image and feature description, you can build a meaningful object of it.

# Harris Corner Detection 

It basically finds the difference in intensity for a displacement of (u,v) in all direction.

![](images/fig1.png)

The window function is either a rectangular window or a gaussian window to give weights to pixel underneath.

We have to maximise the function E(u,v) for corner detection.To maximise second term , apply Taylor Expansion. You will get below equation:

![](images/fig4.png)

![](images/fig2.png)

![](images/fig3.png)

# Harris Corner Detector in OpenCV

OpenCV has the function cv.cornerHarris() for this purpose. Its arguments are:

    img - Input image. It should be grayscale and float32 type.
    blockSize - It is the size of neighbourhood considered for corner detection
    ksize - Aperture parameter of the Sobel derivative used.

# Corner with SubPixel Accuracy

You may need to find the corners with maximum accuracy. OpenCV comes with a function cv.cornerSubPix() which further refines the corners detected with sub-pixel accuracy.