import numpy as np
import cv2

img = np.zeros((500,500,3),dtype = 'uint8')

color = (255,0,255)

cv2.circle(img,(250,250),80,color)
cv2.imshow('dark',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
