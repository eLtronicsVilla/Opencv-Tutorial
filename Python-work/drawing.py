#Define the dimention of the image , create the image with numpy arrays ,Create black background by filling the array with zeros.Implement drawing functions.

import numpy as np
import cv2

pic = np.zeros((500,500,3), dtype = 'uint8')

cv2.rectangle(pic, (0,0), (500,150), (123,200,98),3,lineType=8,shift=0)

cv2.imshow('dark',pic)

cv2.waitKey(0)
cv2.destroyAllWindows()
