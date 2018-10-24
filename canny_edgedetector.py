import numpy as np
import cv2

pic = cv2.imread('akshay.jpg')
thresholdvalue1 = 50 #within this range all value will go to 0 , meaning black
thresholdvalue2 = 100  #all value above going to set to 1 - white

canny = cv2.Canny(pic,thresholdvalue1,thresholdvalue2)  # edges around the image
cv2.imshow('edge',canny)
cv2.waitKey(0)
cv2.destroyAllWindows()


