# -*- coding: utf-8 -*-
import io
import sys
import os
import json
from six.moves import urllib

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

    # 한글 TTS
    f = open('weather_parsing.txt','r')
    input_kor_str = f.readline()
    f.close()
    koreanTextToSpeech(unicode(input_kor_str))
