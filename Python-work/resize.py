import numpy as np
import cv2

img = cv2.imread('input.jpg',3)  # load a color image - of 3 channel
#cv2.imshow('output',img)   # show the image on screen window , window automatically fit to the window size
r = 300.0/img.shape[1]  #find the aspect ratio 
dim1 = (300,int(img.shape[0]*r)) # set the dimention width and height (300x300 - with Aspect ratio)
dim2 = (300,300) # set the dimention width and height - without Aspect ratio
new_img_ar = cv2.resize(img,dim1,interpolation = cv2.INTER_AREA)
new_img = cv2.resize(img,dim2,interpolation = cv2.INTER_AREA)
cv2.imshow('output',new_img)
cv2.imwrite("resized_image_with_AR.jpg",new_img_ar)
cv2.imwrite("resized_image.jpg",new_img)
cv2.waitKey(0)           # waitkey is a keyboard binding function.It's argument is the time in milliseconds.
cv2.destroyAllWindows()
