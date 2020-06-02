import cv2
import os.path
import ffmpy
import time

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


def generate_video(input_str) -> list:
    video = VideoSelector()
    word_list = video.convert_string(input_str)
    video_list = []
    if os.path.isfile('static/images/video.mp4'):
        os.remove('static/images/video.mp4')
    for word in word_list:
        path = "static/images/" + word + ".mp4"
        if os.path.isfile(path):
            video_list.append(path)
        else:
            image_folder = 'static/images/'
            video_name = 'video.avi'
            letter_list = []
            for letter in word:
                path2 = "static/images/" + letter + ".jpeg"
                letter_list.append(path2)
            # frame = cv2.imread(letter_list[0])
            # print(frame)
            # height, width, layers = frame.shape
            video = cv2.VideoWriter(video_name, cv2.VideoWriter_fourcc(*'MJPG'),
                                    2, (400, 400))

            for image in letter_list:
                # cv2.imshow('image', cv2.imread(image))
                # key = cv2.waitKey(500)
                video.write(cv2.imread(image))

            # cv2.destroyAllWindows()
            # while(True):
            #     continue
            if os.path.isfile('video.mp4'):
                os.remove('video.mp4')
            video.release()
            ff = ffmpy.FFmpeg(
                inputs={'video.avi': None},
                outputs={'video.mp4': None}
            )
            ff.run()
            os.rename('video.mp4', 'static/images/video.mp4')
            os.remove('video.avi')
            time.sleep(1)
            video_list.append(image_folder + 'video.mp4')
    return video_list


# if __name__ == '__main__':
#     video = VideoSelector()
#     print(generate_video("hello how are you"))
#     word_list = video.convert_string("Hello! how are you goodbye! what")
#     for word in word_list:
#         path = "static/images/" + word + ".mp4"
#         if os.path.isfile(path):
#             print(word)
#             # cap = skvideo.io.vread(path)
#
#             cap = cv2.VideoCapture(path)
#
#             while (cap.isOpened()):
#
#                 # Capture frame-by-frame
#                 ret, frame = cap.read()
#
#                 if ret == True:
#
#                     # Display the resulting frame
#                     cv2.imshow('Frame', frame)
#                     # cv2.resizeWindow('Frame', 600, 580)
#
#                     # Press Q on keyboard to  exit
#                     if cv2.waitKey(10) & 0xFF == ord('q'):
#                         break
#
#                 # Break the loop
#                 else:
#                     break
#         else:
#             image_folder = 'static/images/'
#             video_name = 'video.mp4'
#             letter_list = []
#             for letter in word:
#                 path = "static/images/" + letter + ".jpeg"
#                 letter_list.append(path)
#             # frame = cv2.imread(letter_list[0])
#             # height, width, layers = frame.shape
#             # video = cv2.VideoWriter(video_name, 0, 2, (400, 600))
#
#             for image in letter_list:
#                 cv2.imshow('image', cv2.imread(image))
#                 key = cv2.waitKey(500)
#                 # video.write(cv2.imread(image))
#
#             cv2.destroyAllWindows()

# if __name__ == '__main__':
#     # print(bcp47.languages.keys())
#
            # os.popen(
            #     "ffmpeg -i '{input}' -ac 2 -b:v 2000k -c:a aac -c:v libx264 -b:a 160k -vprofile high -bf 0 -strict experimental -f mp4 '{output}.mp4'".format(
            #         input="static/images/video.avi", output="static/images/video2.mp4"))
