from flask import Flask, render_template, request, json
from flask_cors import CORS
import simpleaudio as sa
from google.cloud import speech
from google.cloud.speech import enums
from google.cloud.speech import types
import os
from google.oauth2 import service_account
from videoSelector import generate_video


credentials = service_account.Credentials.from_service_account_file(
    "./static/config.json")
data = {}
with open('static/config.json') as file:
    data.update(json.load(file))
app = Flask(__name__)
CORS(app)
client = speech.SpeechClient(credentials=credentials)

transcript_lst = ['']
global_dict = {'vids': []}

@app.route('/', methods=['GET'])
def hello_world():
    return render_template('index.html', transcript=transcript_lst[0], vids=global_dict), 200


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

    global_dict['vids'] = generate_video(transcript_lst[0])
    print(global_dict['vids'])
    return render_template('index.html', transcript=transcript_lst[0], vids=global_dict), 200


@app.route('/transcript/')
def get_transcript():
    return json.jsonify({
        'transcript': transcript_lst[0]
    })

@app.route('/vids/')
def get_vids():
    # return json.jsonify({
    #     'vids': global_dict
    # })
    return {'vids': global_dict['vids']}

if __name__ == '__main__':
    app.run(debug=True)
