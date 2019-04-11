import numpy as np
import cv2

pic =np.zeros((500,500,3),dtype='uint8')
font = cv2.FONT_HERSHEY_DUPLEX
cv2.putText(pic,'Brijesh',(100,100),font,3,(255,0,255),4)
cv2.imshow('output',pic)
cv2.waitKey(0)
cv2.destroyAllWindows()

