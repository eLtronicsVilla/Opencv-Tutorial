import numpy as np
import cv2

pic =cv2.imread('akshay.jpg')
cols = pic.shape[1]
rows = pic.shape[0] #define the shape of the image

M = np.float32([[1,0,-150],[0,1,-70]]) # we are going to shift 150 pixels to the left along x-axis abd 70 pixel up along the y-axis

#M = np.float32([[1,0,150],[0,1,70]]) # we are going to shift 150 pixels to the right along x-axis abd 70 pixel down along the y-axis
shifted = cv2.warpAffine(pic,M,(cols,rows))
cv2.imshow('shifted',shifted)

cv2.waitKey(0)
cv2.destroyAllWindows()

