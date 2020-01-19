from flask import Flask, render_template, request, json
from flask_cors import CORS
import simpleaudio as sa
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types
import os
from google.oauth2 import service_account


credentials = service_account.Credentials.from_service_account_file(
    "./static/decent-vial-265513-0c956eb7477c.json")

app = Flask(__name__)
CORS(app)
client = speech.SpeechClient(credentials=credentials)

transcript_lst = ['']

@app.route('/', methods=['GET'])
def hello_world():
    return render_template('index.html', transcript=transcript_lst[0]), 200


@app.route('/', methods=['POST'])
def hello_world_post():
    fs_blob = request.files['data']
    file = fs_blob.stream.read()
    sa.play_buffer(file, 1, 2, 44100)

    audio = types.RecognitionAudio(content=file)
    config = types.RecognitionConfig(
        encoding=enums.RecognitionConfig.AudioEncoding.LINEAR16,
        language_code='en-US')

    # Detects speech in the audio file
    response = client.recognize(config, audio)
    for result in response.results:
        transcript = result.alternatives[0].transcript
        print('Transcript: {}'.format(result.alternatives[0].transcript))
        transcript_lst[0] = transcript
    return render_template('index.html', transcript=transcript_lst[0]), 200


@app.route('/transcript/')
def get_transcript():
    return json.jsonify({
        'transcript': transcript_lst[0]
    })


if __name__ == '__main__':
    app.run(debug=True)
