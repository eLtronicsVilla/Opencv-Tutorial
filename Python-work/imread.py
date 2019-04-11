import numpy as np
import cv2

img = cv2.imread('akshay.jpg',3)  # load a color image - of 3 channel
cv2.imshow('output',img)   # show the image on screen window , window automatically fit to the window size
cv2.waitKey(0)           # waitkey is a keyboard binding function.It's argument is the time in milliseconds.
cv2.destroyAllWindows()  
'''simply destroy all the window we created, if you want to destroy any specific window , use the function cv2,destroyWindow() where you pass the exact window name as the argument.'''
