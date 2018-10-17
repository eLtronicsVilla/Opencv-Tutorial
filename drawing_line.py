#drawing the line on image

import numpy as np
import cv2

img = np.zeros((500,500,3), dtype = 'uint8')

cv2.line(img,(350,350),(500,350),(0,0,255))
cv2.imshow('output',img)

cv2.waitKey(0)
cv2.destroyAllWindows()
