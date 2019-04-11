import numpy as np
import cv2

img = np.zeros((500,500,3),np.uint8)
pts = np.array([[10,5],[20,30],[70,20],[50,1]],np.int32)
pts = pts.reshape((-1,1,2))
cv2.polylines(img,[pts],True,(0,255,255))
cv2.imshow('output',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
