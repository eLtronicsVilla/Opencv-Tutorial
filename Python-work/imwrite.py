#save the image in different formate

import numpy as np
import cv2

img = cv2.imread('akshay.jpg',3)
img = cv2.imwrite('akshay.png',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
