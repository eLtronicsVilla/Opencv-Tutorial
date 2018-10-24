import cv2
import numpy as np

pic = cv2.imread('akshay.jpg')
rows = pic.shape[1]
cols = pic.shape[0]
center = (cols/2,rows/2)
angle = 45  #45 degree angle rotation
M = cv2.getRotationMatrix2D(center,angle,1) # 3rd argument is scale for size,if scale =2 this image will be bigger size
rotate = cv2.warpAffine(pic,M,(cols,rows))
cv2.imshow('rotated',rotate)

cv2.waitKey(0)
cv2.destroyAllWindows()
