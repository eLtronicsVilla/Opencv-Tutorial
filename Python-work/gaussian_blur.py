import numpy as np
import cv2

pic = cv2.imread('akshay.jpg')

matrix = (7,7)

blur = cv2.GaussianBlur(pic,matrix,0) #sigmaX is src,ksize,sigmaX,dst=None,borderType =None -, sigma here is standard deviation
cv2.imshow('blurred',blur) #here bluring is much more smaller than averaging because it include the neighbouring pixels to compute the average , in other blurring technique averages, it only compute the center pixel to compute the average, but in this case , gaussian add more weights to compute the average
cv2.waitKey(0)
cv2.destroyAllWIndows()
