import numpy as np
import cv2

cap = cv2.VideoCapture(0)
#fourcc = cv2.VideoWriter_fourcc('M','J','P','G')
fourcc = cv2.cv.CV_FOURCC('M','J','P','G')
fps = 30
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))

#framesize = (720,480)
out = cv2.VideoWriter('out.avi',fourcc,fps,(frame_width,frame_height))
while (cap.isOpened()):  
     ret,frame = cap.read()
     out.write(frame)
     cv2.imshow('vid',frame)
     if cv2.waitKey(1) & 0xFF == ord('q'):
        break

out.release()
cap.release()
cv2.destroyAllWindows()


