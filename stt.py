# -*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib
from google.cloud import speech

from google.cloud.speech import enums
from google.cloud.speech import types

def google_stt():
    """Transcribe the given audio file."""

    # 환경 변수 설정
    os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/project/work/fork/Smart-speaker/master_key.json")

    # 인코딩 설정
    reload(sys)
    sys.setdefaultencoding('utf-8')

    # 녹음
    os.system("arecord -D plughw:1,0 -f S16_LE -c1 -r16000 -d 3 input.wav")
    #print("recording complete!")

	# start stt
#   speech_client = speech.Client()
    speech_client = speech.SpeechClient()

    with io.open('input.wav', 'rb') as audio_file:
        content = audio_file.read()
        audio = types.RecognitionAudio(content=content)

    config = types.RecognitionConfig(
            encoding = enums.RecognitionConfig.AudioEncoding.LINEAR16,
            sample_rate_hertz = 16000,
            language_code = 'ko-KR')

    response = speech_client.recognize(config, audio)

    for result in response.results: 
        print('Transcript: {}'.format(result.alternatives[0].transcript))
    # [END speech_quickstart]

# =======================================
# before code backup
# =======================================
	
#   with io.open('input.wav', 'rb') as audio_file:
#       content = audio_file.read()
#       audio_sample = speech_client.sample(
#           content=content,
#           source_uri=None,
#           encoding='LINEAR16',
#           sample_rate_hertz=16000)

#   alternatives = audio_sample.recognize('ko-KR')
#   for alternative in alternatives:
#       return alternative.transcript

if __name__ == '__main__':
    google_stt()
