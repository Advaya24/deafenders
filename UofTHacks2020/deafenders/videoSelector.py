import cv2
import numpy as np
import os.path
import skvideo.io
from cv2.cv2 import ROTATE_90_CLOCKWISE
import bcp47
from PIL import Image

class VideoSelector:
    def __init__(self):
        self.hi = "hello"

    def convert_string(self, string):
        final_string = []
        for word in string.split():
            formatted_word = word.replace('.', '')
            formatted_word = formatted_word.replace('!', '')
            if formatted_word.isalnum() and formatted_word != 'are':
                final_string.append(formatted_word.lower())
        return final_string


if __name__ == '__main__':
    # print(bcp47.languages.keys())
    video = VideoSelector()
    word_list = video.convert_string("Hello! how are you goodbye! what")
    for word in word_list:
        path = "ASL/" + word + ".mp4"
        if os.path.isfile(path):
            print(word)
            # cap = skvideo.io.vread(path)

            cap = cv2.VideoCapture(path)

            while (cap.isOpened()):

                # Capture frame-by-frame
                ret, frame = cap.read()

                if ret == True:

                    # Display the resulting frame
                    cv2.imshow('Frame', frame)
                    # cv2.resizeWindow('Frame', 600, 580)

                    # Press Q on keyboard to  exit
                    if cv2.waitKey(10) & 0xFF == ord('q'):
                        break

                # Break the loop
                else:
                    break
        else:
            image_folder = 'ASL/'
            video_name = 'video.mp4'
            letter_list = []
            for letter in word:
                path = "ASl/" + letter + ".jpeg"
                letter_list.append(path)
            frame = cv2.imread(os.path.join(image_folder, letter_list[0]))
            height, width, layers = frame.shape
            video = cv2.VideoWriter(video_name, 0, 2, (width, height))

            for image in letter_list:
                video.write(cv2.imread(os.path.join(image_folder, image)))

            cv2.destroyAllWindows()
            video.release()








