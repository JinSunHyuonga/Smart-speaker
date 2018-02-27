# -*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib
from google.cloud import speech

def transcribe_file_kor(speech_file):
    """Transcribe the given audio file."""
    
    speech_client = speech.Client()

    with io.open(speech_file, 'rb') as audio_file:
        content = audio_file.read()
        audio_sample = speech_client.sample(
            content=content,
            source_uri=None,
            encoding='LINEAR16',
            sample_rate_hertz=16000)

    alternatives = audio_sample.recognize('ko-KR')
    for alternative in alternatives:
		return alternative.transcript
		
def koreanTextToSpeech(korean_string):
	client_id = "TaMbMfsBKEtSzWR8APru"
	client_secret = "dtPHWwkCwG"
	encText = urllib.parse.quote(korean_string.encode("utf-8"))
	data = "speaker=mijin&speed=0&text=" + encText;
	url = "https://openapi.naver.com/v1/voice/tts.bin"
	request = urllib.request.Request(url)
	request.add_header("X-Naver-Client-Id",client_id)
	request.add_header("X-Naver-Client-Secret",client_secret)
	response = urllib.request.urlopen(request, data=data.encode('utf-8'))
	rescode = response.getcode()
	if(rescode==200):
		print("TTS mp3")
		response_body = response.read()
		with open('TTS.mp3', 'wb') as f:
			f.write(response_body)
	else:
		print("Error Code:" + rescode)
	
if __name__ == '__main__':

	# 환경 변수 설정
	os.system("export GOOGLE_APPLICATION_CREDENTIALS=/home/pi/stt1-0f1857b5b0c0.json")
	
	# 인코딩 설정
	reload(sys)
	sys.setdefaultencoding('utf-8')
	
	# 녹음
	os.system("arecord -D plughw:1,0 -f S16_LE -c1 -r16000 -d 3 input.wav")
	print("recording complete!")
	
	# STT 한글
	input_kor_str = transcribe_file_kor('input.wav')
	print(input_kor_str)
	
	# 한글 TTS
	koreanTextToSpeech(unicode(input_kor_str))
	
	# 한글 음성 출력
	os.system("omxplayer TTS.mp3") 	
