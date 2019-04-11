import numpy as np
import cv2

pic = cv2.imread('akshay.jpg',0)  #load a picture in gray scale
threshold_value = 150 #below 150 pixel value is going to be black
#(T_value,binary_threshold) = cv2.threshold(pic,threshold_value,255,cv2.THRESH_BINARY)
(T_value,binary_threshold) = cv2.threshold(pic,threshold_value,255,cv2.THRESH_BINARY_INV) #opposite is going to be true - below threshold is going to be white
cv2.imshow('binary',binary_threshold)
cv2.imwrite('output_image.jpg',binary_threshold)
cv2.waitKey()
cv2.destroyAllWindows()

