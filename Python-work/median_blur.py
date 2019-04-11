import numpy as np
import cv2
#median blur - unlike the method 'averaging' that I used in median blur instead of replacing the central pixel of image with neighbourhood pixel, in this case we are going to replace the pixel with the median of neighbouring pixels.Median blur is used to remove noise in an image.

pic = cv2.imread('akshay.jpg')
kernel = 3
median = cv2.medianBlur(pic,kernel)
cv2.imshow('median_blur',median)
cv2.waitKey(0)
cv2.destroyAllWindows()

