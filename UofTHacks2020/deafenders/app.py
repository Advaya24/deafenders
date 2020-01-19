from flask import Flask, render_template, request
from flask_cors import CORS
import simpleaudio as sa
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types
import os
from google.oauth2 import service_account

credentials = service_account.Credentials.from_service_account_file(
"./static/decent-vial-265513-0c956eb7477c.json")

# import cgi
# from contextlib import closing
# import wave

app = Flask(__name__)
CORS(app)
client = speech.SpeechClient(credentials=credentials)
# client = speech.SpeechClient()
# creds = service_account.Credentials.from_service_account_file("./path/credentials.json")
# client = speech.SpeechClient(credentials=creds


@app.route('/', methods=['GET'])
def hello_world():
    return render_template('index.html'), 200


@app.route('/', methods=['POST'])
def hello_world_post():
    # form = cgi.FieldStorage()
    # fname = form["audio"].filename
    # print(fname)
    # with closing(wave.open(fname, 'r')) as f:
    # form = request.form['form_data']
    # print(form)
    request_variable = request
    # d = ast.literal_eval(request.data)
    # print(repr(d))
    # print(request.data['fd'])
    # print(str(request.form))
    # print(str(request.data))
    # credential_path = "/Desktop/Coding/UofTHacks2020/deafenders/static/decent-vial-265513-0c956eb7477c.json"
    # os.environ['GOOGLE_APPLICATION_CREDENTIALS'] = credential_path
    fs_blob = request.files['data']
    file = fs_blob.stream.read()
    p = sa.play_buffer(file, 1, 2, 44100)
    # p.wait_done()


    audio = types.RecognitionAudio(content=file)
    config = types.RecognitionConfig(
        encoding=enums.RecognitionConfig.AudioEncoding.LINEAR16,
        language_code='en-US')

    # Detects speech in the audio file
    response = client.recognize(config, audio)

    for result in response.results:
        print('Transcript: {}'.format(result.alternatives[0].transcript))
    return 200


if __name__ == '__main__':
    app.run(debug=True)
