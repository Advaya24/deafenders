from flask import Flask, render_template, request
from flask_cors import CORS
import simpleaudio as sa
import ast
# import cgi
# from contextlib import closing
# import wave

app = Flask(__name__)
CORS(app)


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
    fs_blob = request.files['data']
    file = fs_blob.stream.read()
    p = sa.play_buffer(file, 1, 2, 44100)
    p.wait_done()
    return 'Hello World!', 200


if __name__ == '__main__':
    app.run(debug=True)
