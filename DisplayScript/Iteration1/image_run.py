import cv2
img = cv2.imread("../monkey.png")
(h, w) = img.shape[:2]
cv2.imshow("eye", img)
(cx, cy) = (w/2, h/2)
rotation_matrix = cv2.getRotationMatrix2D((cx, cy), 45, 1.0)

rotated = cv2.warpAffine(img, rotation_matrix, (w, h))
cv2.imshow("rotated", rotated)
cv2.waitKey(0)
