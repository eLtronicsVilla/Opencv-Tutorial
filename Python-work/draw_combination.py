import numpy as np
import cv2

img = np.zeros((500,500,3),np.uint8)
cv2.rectangle(img, (0,0), (500,150), (123,200,98),3,lineType=8,shift=0)
cv2.line(img,(350,350),(500,350),(0,0,255))
color = (255,0,255)
cv2.circle(img,(250,250),80,color)
font = cv2.FONT_HERSHEY_DUPLEX
cv2.putText(img,'Brijesh',(100,100),font,3,(255,0,255),4)
cv2.ellipse(img,(256,256),(100,50),0,0,180,255,-1)
pts = np.array([[10,5],[20,30],[70,20],[50,1]],np.int32)
pts = pts.reshape((-1,1,2))
cv2.polylines(img,[pts],True,(0,255,255))
cv2.imshow('output',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
