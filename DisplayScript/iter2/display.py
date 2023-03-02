import numpy as np
import sys
import cv2
import ctypes
import io
from itertools import cycle
import hashlib
from PIL import Image
SIZE = 3275658
print('bytes', SIZE)


def get_opencv_img_from_buffer(buffer, flags):
    img = Image.frombuffer('RGB', SIZE, buffer)
    #bytes_as_np_array = bytes_as_np_array[138:]
    #print(bytes_as_np_array.reshape(1280,853))
    print('endfunc')
    img.show()
    #return bytes_as_np_array
    return img
    #return cv2.imdecode(bytes_as_np_array, flags)

# Define the memory address of the image data
memory_address = sys.argv[1]
print(memory_address)
hex_address = hex(int(memory_address,16))

#print('hex addy', hex(hex_address))
print(type(memory_address))
#memview = memoryview(bytes(int(memory_address,16)))
#0x0000000000C47020
#byta = bytearray.fromhex(memory_address)
# SIZE IN BYTES
buffer = ctypes.create_string_buffer(SIZE)
print(hex_address)
ctypes.memmove(buffer, hex_address, SIZE)
#print(memview)
bytes_buffer = io.BytesIO(buffer.raw)

# Allocate a numpy array to store the image data
#print('f',get_opencv_img_from_buffer(bytes_buffer,-1))
img_data = get_opencv_img_from_buffer(bytes_buffer,1)
# Copy the image data from the memory address to the numpy array
#np.memcpy(img_data, memory_address, img_data.nbytes)

# Display the image
print(img_data)
cv2.imshow('Image', img_data)
cv2.waitKey(0)
cv2.destroyAllWindows()