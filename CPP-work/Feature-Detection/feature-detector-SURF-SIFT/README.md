## SIFT ( Scale Invariant feature transform )

It is a feature detection algorithm to detect and describe local feature in image.
It is used for object recognition,robot mapping and navigation,image stiching,3D modeling,gesture recognition and video tracking.

SIFT keypoints of object are first extracted from a set of reference images, and stored in database.
A object is recognized in a new image by comparing each feature from new image to it's database.
Now finding feature based on Euclidean distance of their feature vector.
The subset of keypoints that agree on the object and it's location, scale and orientation in new image are identified to filter out good matches.
