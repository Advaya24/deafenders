//webkitURL is deprecated but nevertheless
URL = window.URL || window.webkitURL;

let gumStream;                    //stream from getUserMedia()
let rec;                     //Recorder.js object
let input;                       //MediaStreamAudioSourceNode we'll be recording

// shim for AudioContext when it's not avb.
let AudioContext = window.AudioContext || window.webkitAudioContext;
let audioContext; //audio context to help us record

let recordButton = document.getElementById("recordButton");
let submitButton = document.getElementById("submitButton");
let pauseButton = document.getElementById("pauseButton");
let resetButton = document.getElementById("resetButton");


//add events to those 2 buttons
recordButton.addEventListener("click", startRecording);
submitButton.addEventListener("click", stopRecording);
pauseButton.addEventListener("click", pauseRecording);
resetButton.addEventListener("click", reset);

function reset(){
    document.getElementById("recordingsList").innerHTML = "";
    document.getElementById("video").style.visibility = "hidden";
    document.getElementById("text").innerHTML = "";
}

function startRecording() {
    console.log("recordButton clicked");

    /*
        Simple constraints object, for more advanced audio features see
        https://addpipe.com/blog/audio-constraints-getusermedia/
    */

    let constraints = {audio: true, video: false};

    /*
       Disable the record button until we get a success or fail from getUserMedia()
   */

    recordButton.disabled = true;
    submitButton.disabled = false;
    pauseButton.disabled = false;

    /*
        We're using the standard promise based getUserMedia()
        https://developer.mozilla.org/en-US/docs/Web/API/MediaDevices/getUserMedia
    */

    navigator.mediaDevices.getUserMedia(constraints).then(function (stream) {
        console.log("getUserMedia() success, stream created, initializing Recorder.js ...");

        /*
            create an audio context after getUserMedia is called
            sampleRate might change after getUserMedia is called, like it does on macOS when recording through AirPods
            the sampleRate defaults to the one set in your OS for your playback device

        */
        audioContext = new AudioContext();

        //update the format
        // document.getElementById("formats").innerHTML = "Format: 1 channel pcm @ " + audioContext.sampleRate / 1000 + "kHz"

        /*  assign to gumStream for later use  */
        gumStream = stream;

        /* use the stream */
        input = audioContext.createMediaStreamSource(stream);

        /*
            Create the Recorder object and configure to record mono sound (1 channel)
            Recording 2 channels  will double the file size
        */
        rec = new Recorder(input, {numChannels: 1});

        //start the recording process
        rec.record();

        console.log("Recording started");

    }).catch(function (err) {
        //enable the record button if getUserMedia() fails
        recordButton.disabled = false;
        submitButton.disabled = true;
        pauseButton.disabled = true
    });
}

function pauseRecording() {
    console.log("pauseButton clicked rec.recording=", rec.recording);
    if (rec.recording) {
        //pause
        rec.stop();
        pauseButton.innerHTML = "Resume";
    } else {
        //resume
        rec.record();
        pauseButton.innerHTML = "Pause";

    }
}

function stopRecording() {
    console.log("submitButton clicked");

    //disable the stop button, enable the record too allow for new recordings
    submitButton.disabled = true;
    recordButton.disabled = false;
    pauseButton.disabled = true;

    //reset button just in case the recording is stopped while paused
    pauseButton.innerHTML = "Pause";

    //tell the recorder to stop the recording
    rec.stop();

    //stop microphone access
    gumStream.getAudioTracks()[0].stop();

    //create the wav blob and pass it on to createDownloadLink
    rec.exportWAV(createDownloadLink);
    // document.record.submit();
    // setTimeout(function () {
    //     document.location = "/";
    // }, 500)

}

function createDownloadLink(blob) {

    let url = URL.createObjectURL(blob);
    let au = document.createElement('audio');
    let li = document.createElement('li');
    let link = document.createElement('a');

    //name of .wav file to use during upload and download (without extendion)
    // let filename = new Date().toISOString();
    let filename = "audio";

    //add controls to the <audio> element
    au.controls = true;
    au.src = url;
    // let audio_file = document.createElement('input');
    // audio_file.setAttribute("id","downloadFile");
    // audio_file.appendChild(blob);

    console.log("AU:");

    //save to disk link
    link.href = url;
    link.download = filename + ".wav";
    // link.download = "abc.wav";
    // download forces the browser to donwload the file using the  filename
    link.innerHTML = "Save to disk";
    // console.log(link);
    //add the new audio element to li
    li.appendChild(au);
    // console.log(li);
    //add the filename to the li
    li.appendChild(document.createTextNode(filename + ".wav "));

    //add the save to disk link to li
    li.appendChild(link);
    // console.log(typeof blob);
    //upload link
    let upload = document.createElement('a');
    upload.href = "#";
    upload.innerHTML = "Upload";
    upload.addEventListener("click", function (event) {
        let xhr = new XMLHttpRequest();
        xhr.onload = function (e) {
            if (this.readyState === 4) {
                console.log("Server returned: ", e.target.responseText);
            }
        };
        let fd = new FormData();
        fd.append("audio_data", blob, filename);

        // xhr.open("POST","/static/upload.php",true);
        // xhr.send(fd);
    });
    li.appendChild(document.createTextNode(" "));//add a space in between
    li.appendChild(upload);//add the upload link to li
    let recordingsList = document.getElementById("recordingsList");
    //add the li element to the ol
    recordingsList.appendChild(li);
    let sendFd = new FormData();
    sendFd.append('fname', 'audio.wav');
    sendFd.append('data', blob);
    // let form_data = fd.serialize();
    console.log("form data: " + sendFd);
    // let sf = JSON.stringify(sendFd);
    $.ajax({
        type: 'POST',
        // data: {'fd': sf},
        data: sendFd,
        async: false,
        timeout: 30000,
        url: "/",
        processData: false,
        contentType: false
    }).done(function (data) {
        console.log("Hello " + data);
        // document.record.submit();
    });
    // console.log(i);
}