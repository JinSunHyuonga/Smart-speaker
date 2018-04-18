# Smart-speaker
Smart-speaker project

 #################  설치 매뉴얼  #################

해당 코드는 Raspberry pi3에 Raspbian을 설치하였으며 Linux 4.9.63-v7+ 버전에 최적화 되어 있다.
Raspbian 설치 후 각 코드 실행을 위해서는 인터넷을 통해 여러 파일 설치가 필요하다.

1.	Python 3.x
sudo apt-get install python3
-	터미널 창에서 해당 명령어 실행
-	Raspbian에는 기본적으로 Python 2.x 버전이 설치 되어 있지만 3.x 도 설치해 주는 것이 좋다.

2.	Google Speeck API 
https://cloud.google.com/speech/docs/quickstart
-	아이디 생성, API 사용요청, 인증키 설정을 해야한다.

3.	omxplayer
sudo apt-get install omxplayer
-	터미널 창에서 해당 명령어 실행
-	기본 플레이어가 있지만 MP3 실행을 위해 필요하다.

4.	Youtube-dl
sudo curl -L https://yt-dl.org/downloads/latest/youtube-dl -o /usr/local/bin/youtube-dl
sudo chmod a+rx /usr/local/bin/youtube-dl
-	터미널 창에서 해당 명령어 실행
-	유튜브 동영상만 바로 플레이 할 수 있는 주소를 준다.

5.	Youtube API
npm install youtube-node
-	터미널 창에서 해당 명령어 실행
-	기존 Google Speeck API 에서 만든 인증정보 활용

6.	Xerces
https://xerces.apache.org/xerces-c/install-3.html
-	해당 사이트를 통해 다운 및 설치
-	날씨에 대한 XML파일을 파싱하여 원하는 정보만 추출 할 수 있다.

7.	Clova Speech Synthesis
https://developers.naver.com/products/clova/tts
-	해당 사이트 접속 후 API 신청 및 설정을 통해 네이버 TTS 실행 준비를 해야한다.

#####################################################################################

실행영상
https://www.youtube.com/watch?v=cWK4_8pFB3s&feature=youtu.be

일일 업무 계획 & 진행상황 (3월 둘째주)                                                    
단어 추출 & 실행  (진선형)
1. stt 받아 단어 추출 하기(이름, 유튜브, 날씨)
http://blog.naver.com/PostView.nhn?blogId=vosej_v&logNo=50176084445&redirect=Dlog&widgetTypeCall=true
2. 유튜브 실행
https://kldp.org/node/135183 system 함수 이용
http://cosmosproject2015.tistory.com/231 파이썬 컴파일
utf8 메모장 저장 - https://stackoverflow.com/questions/9942594/unicodeencodeerror-ascii-codec-cant-encode-character-u-xa0-in-position-20?noredirect=1&lq=1
3. 날씨 실행
4. 날씨 말해주기
메인 파일 컴파일 - g++ $(pkg-config --cflags --libs python-2.7) main.cpp -o main -pthread

일정 & TTS연동 (최민영)
calendar 일정 확인
일정->tts로 일정 전달. TTS api 작업 시작
금일 일정 mp3파일로 저장 및 스피커 출력까지
stt
stt 샘플코드 성공 - 음성입력 -> 텍스트로 출력까지
3. 이슈
파이썬 GIL
4. 전체경로
일정 python 경로
키파일 사용시 변경 후 사용할 것


일일 업무 계획 & 진행상황 (3월 첫째주)
단어 추출 & 실행  (진선형)
1. 명령어 틀 짜기
파이 + 
유튜브 = **틀어줘, **들려줘, **노래, **음악 (쓰레드 빼서 돌리기)
	-  노래&음악 + 다음, 이전 , 다른 (if 유뷰트실행이 1 이라면)
날씨 = 날씨, (지역.도시단위)날씨 (쓰레드 빼서 돌리기 & 현재-온도tmp,하늘sky,강수확률pop, 풍속ws)
정지 - 멈춰, 그만, 정지
종료 - 프로그램 종료 
2. SHM - Parsing프로그램과 연동
일일 업무 계획 & 진행상황 (2월 넷째주)
텐서플로우, 깃허브 (진선형)
1. 텐서플로우
https://tensorflowkorea.gitbooks.io/tensorflow-kr/content/
2. 깃허브
oh my zsh - https://github.com/robbyrussell/oh-my-zsh
공부 - https://www.youtube.com/watch?v=JEY3X64gX4Q
내코드 - https://github.com/JinSunHyuonga/Smart-speaker
코드에 구글, 네이버 인증키 들어 있으니 테스트 및 공유시 한도초과 안나게 조심!!
calendar (최민영)
embedding python
python에서 실행후 프린트 하던것을 c++에서 프린트 하도록 (데이타 전달.)
python->cpp 당일 일정 전달
일일 업무 계획 & 진행상황 (2월 셋째주)
파이썬 (진선형)
1. 파이썬 공부
https://wikidocs.net/book/1
구글일정(최민영)
1. 당일 일정확인 - 파이썬
일일 업무 계획 & 진행상황 (2월 둘째주)
스마트미러 API 붙이기  (진선형)
1. 유튜브 넣기
주소로 노래틀기 - http://www.ismoothblog.com/2016/10/watch-youtube-videos-on-raspberry-pi.html
유튜브 api - https://developers.google.com/youtube/v3/docs/search/list?hl=ko
파이썬 키워드별 검색 - https://developers.google.com/youtube/v3/code_samples/python?hl=ko#search_by_keyword
유튜브api 서치 - https://stackoverflow.com/questions/30643742/access-youtube-api-using-keyword-in-python
유튜브 키 값 - https://www.youtube.com/watch?v=JbWnRhHfTDA
파서 - https://dojang.io/mod/page/view.php?id=724

일일 업무 계획 & 진행상황 (2월 첫째주)
스마트미러 API 붙이기 (진선형)
1. 날씨 기능 넣기
기상청 - http://www.weather.go.kr/weather/lifenindustry/sevice_rss.jsp
json 코딩도장 - https://dojang.io/mod/page/view.php?id=724
xerces 설치 - http://blog.naver.com/endfirst/30079766547
xerces 터미널 예제 - http://xerces.apache.org/xerces-c/samples-3.html
xerces 소스(SAX2) 예제2 - http://xerces.apache.org/xerces-c/program-3.html
xerces DOM 예제 - http://www.yolinux.com/TUTORIALS/XML-Xerces-C.html
g++ -g -Wall -pedantic -lxerces-c weatherxml.cpp -DMAIN_TEST -o weatherxml
xml 공부 - http://www.infopub.co.kr/info/ebook/pdf/8054-493.pdf
리눅스에서 가장 보편적으로 사용하는 아파치의 xerces 사용
SAX 방식이 빠르긴하나 한글 인식이 안되어 DOM 형식사용
포인트 오류가 있어 MALLOC_CHECK_=0 으로 실행해야함
------------------------------------------------------------------------------------
구글일정 생성,추가,리스트확인 진행(최민영)
1. 캘린더 api
list : google calendar api - list
2.  python embedding
일일 업무 계획 & 진행상황 (1월 25~6일)
스마트미러 메인틀 제작 (진선형)
1. cpp - python 연동 코드분석
python embedding 공부 - http://kukuta.tistory.com/83
연동 및 자료 전달 방법 - https://1986hz.blog.me/30170530432
2. 실행 메뉴 작성 및  단어별 동작 틀 제작 - 나중에 하나씩 기능 넣어가며 만들기
------------------------------------------------------------------------------------
c++ 스터디 (이정남)
음성입력장치 및 블루투스 출력장치 자동 설정(이정남)
1. 블루투스 설정을 위한 pulse audio 구성코드가 c++로 되어있어서 c++추가 스터디 필요


일일 업무 계획 & 진행상황 (1월 24일)
구글 stt 실행 (진선형)
1. 구글 스피치  한번더 확인
그대로 안됨 인증 문제가 아닌듯.
2. 아이디 삐꾸난거 아마존 빼고 구글 스피치 실행 - http://youagain.tistory.com/8
https://stackoverflow.com/questions/47527868/importerror-cannot-import-name-opentype-on-new-installation
에러나서 위에거 설치후 실행하니 됨. ** STT 성공 **
3. c++과 python 연동하기 http://dovetail.tistory.com/53
4. 말할 때만 녹음 하는 방법 찾기
mike Sound visualizer c++ - https://github.com/TimArt/3DAudioVisualizers
------------------------------------------------------------------------------------
c++ 스터디 (이정남)
음성입력 기능 구현 + 음성입력 기능 stt로 연결 (이정남)
1. 음성입력 프로그램  기능추가
마이크 입력 신호가 없으면 비어있는 .wav파일 생성후 종료
마이크 입력이 끝난 후 더 이상 신호가 없으면 종료
생성된 파일명은 stt.wav로 저장됨
컴파일 시 옵션 -lasound -> ALSA lib 가 설치되어 있어야함 -> 공유문서에 설명
gcc -o 실행파일 소스파일 -lasound

------------------------------------------------------------------------------------


일일 업무 계획 & 진행상황 (1월 23일)
구글 stt 실행 (진선형)
1. 네이버 stt 돌리기 - https://blog.naver.com/roboholic84/221134044966
안드로이드로 돌려야함, 라즈베리에서 돌리기에 너무 무거움
2. 아마존 alexa 이용 해볼 예정 - http://youagain.tistory.com/8
pip2 connected 에러 발생
https://github.com/alexa/alexa-avs-sample-app/wiki/Raspberry-Pi - 알렉사 깃
http://cafe.naver.com/openiot/225 - 알랙사
알렉사도 아이디가 잘못 되었다고 나옴
3. api client 를 통해 구글 스피치 성공 - https://blog.naver.com/chandong83/220826470486
실험중 

일일 업무 계획 & 진행상황 (1월 22일)
구글 stt 실행 (진선형)
1. google speech 와 cloud speech 권한문제 구글그룹과 스택에 문의 확인
확인해보기
2. 블루투스 마이크 연결 되는지 확인
블루투스는 안되는듯 마이크 유선 챙겨오기
3. 구글 stt 쉘통해 돌아오는 값이 안나오는 부분 확인
진행이 제대로 되는 듯 하나 한글 값이 안옴
4. iaml(대화), mecab(자연어처리) 설치 - http://cafe.naver.com/openiot/225
@@ SpeechRecognition 으로 하면 STT 가 실행됨.
------------------------------------------------------------------------------------
c++ 스터디 (이정남)ㅎ------------------------------------------------------------------------------------

일일 업무 계획 & 진행상황 (1월 17일)
구글 stt 실행 (진선형)
1. flac 파일을 이용하여 클라우드 speech 돌려보기
ffmpeg -i input.mp3 output.flac 으로 flac변경 후 실행해보기 & 음성 듣기
PC에서만 되고 이거 깔아야 함 - https://blog.naver.com/cursehands/60206117807
라즈베리에서 flac 파일로 변환은 가능한데 바로 돌리는건 힘들다고 함
구글 클라우드 스피치로 인공지능 가능한지 확인 
참조 -  http://ghost.rivario.com/siri-hyungnaenaegi/
2. google speech 와 cloud speech 권한문제 구글그룹과 스택에 문의
https://stackoverflow.com/questions/48295115/raspberry-google-speech-permission
https://groups.google.com/forum/?fromgroups#!forum/google-cloud-dev
3. 쉘을 통해 키값을 던져주는 것은 잘 돌아감
https://www.youtube.com/watch?v=0B3jugS8pC4
내용을 받는데 인식을 못함, 스피커 문제인지, 코드 문제인지 확인
-----------------------------------------------------------------------------------
stt cpp 샘플 인스톨 최민영
진행사항일지-githubwiki

일일 업무 계획 & 진행상황 (1월 16일)
구글 stt 실행 (진선형)
1. C++ pulgin 설치 - https://github.com/hyperledger/iroha/issues/75
GRPC 설치 부분에서 똑같이 막힘
2. google stt C++ 샘플 돌리기 (cloud 와 json을 이용한 STT)  - https://cloud.google.com/speech/docs/quickstart#make_a_speech_api_request
참조 1 - https://brunch.co.kr/@sunghyunlim/24
참조 2 - http://www.makewith.co/page/project/1088/story/2749/
구글 클라우드 STT 성공 일반 STT 실패시 이것도 고려해봐야 할듯
참조 - http://ghost.rivario.com/siri-hyungnaenaegi/
녹음 설정 - rec -c 1 -t flac -r 16000 test.flac / arecord -D plughw:0,0 -d 10 test.wav
------------------------------------------------------------------------------------
최민영 - https://github.com/smartmirror-prj/smartmirror/wiki/%EB%9D%BC%EC%A6%88%EB%B2%A0%EB%A6%AC%EB%A5%BC-%ED%99%9C%EC%9A%A9%ED%95%9C-Smart-Mirror

라즈베리 라즈비안 설치
구글 speech c++ sample install
   ------------------------------------------------------------------------------------f
구글 stt 실행 (나진솔)
15일 이어서 오류 작업
1. 라즈베리파이 audio device setting 에서 세팅이 되어 있지 않았음. (bcm2835 alsa 설정)
2. 녹음 됨, 텍스트화 하는 과정에서 에러발생, API 키값이 잘못 되었다고 판단됨.

------------------------------------------------------------------------------------
음성입력 기능 구현 + 음성입력 기능 stt로 연결 (이정남)
음성입력장치 및 블루투스 출력장치 자동 설정(이정남)
음성입력 기능 stt 연결을 위한 C++ 스터디
장치 자동 설정을 위한 자료조사 -> pulseaudio pavucontrol을 이용하여 장치의 입출력 상태 설정 -> 소스코드 분석 필요
라즈비안 태스크바에 있는 출력장치 선택을 자동 설정 할 수 있도록 조사

next step 음성입력 기능 구현 -> .flac 포맷으로 녹음 파일 생성되도록 녹음 프로그램 수정

일일 업무 계획 & 진행상황 (1월 15일)

구글 stt 실행 (진선형)
1. google stt 실행을 위한 c++ 용 grpc 설치가 안되어 python 으로 시도 (c++와 python이 연동 됨으로 음성 부분만 python 사용해도 좋을듯.
루비통해 설치 - 아래거 하다가 오류보고 앞에 sudo 붙여서 설치
https://github.com/grpc/grpc/tree/master/src/ruby
-- https://grpc.io/docs/quickstart/python.html#download-the-example
예제 잘 돌아감
2. python 구글 api 돌리기 - @@ Python 용 GRPC를 설치해도 안돌아가는걸보니 이문제가 아닌듯
attempt to connect to server failed  이라고 계속 뜸 해결이 안됨
구글 플렛폼에 요청오류라고 나오기는 함
------------------------------------------------------------------------------------
google speech -  gRPC(최민영)
speech API 사용관련 gRPC에 대해 검색이 나오는 중. 현재
 gRPC는 구글에서 발표하였고 HTTP 기반 원격 함수 호출을 해주는 즉, RPC(Remote Procedure Call) 프레임워크 정도 확인이 되었고 추가적으로 사용방법등은 스터디가 필요하여 자료 조사 중
참고 링크 
정리 링크 : https://github.com/smartmirror-prj/smartmirror/wiki/%EB%9D%BC%EC%A6%88%EB%B2%A0%EB%A6%AC%EB%A5%BC-%ED%99%9C%EC%9A%A9%ED%95%9C-Smart-Mirror
------------------------------------------------------------------------------------
구글 stt 실행 (나진솔)
1. https://www.youtube.com/watch?v=0B3jugS8pC4&t=664s 이용하여 stt 실행하려 했으나 
ALSA lib pcm_hw.c:1667:(_snd_pcm_hw_open) Invalid value for card
arecord: main:722: audio open error: No such file or directory
두가지 오류를 해결하지 못함. 
해결시도	a. https://webcam.io/blog/raspberry-pi-network-camera.html 에서 웹캠 Setup
b. https://zedic.com/raspberry-pi-usb-webcam-built-in-microphone/ HD3000 웹캠 맞는 Setup 실시
	c. arecord 기능 확인 및 녹음테스트 -> wav파일로 녹음가능 그러나 잡음심함.
	d. aplay 기능을 통해 녹음된 파일재생 테스트 -> 안됨.

일일 업무 계획 & 진행상황 (1월 12일)

구글 stt 실행 (진선형)
1. grpc 설치 - make shared_cxx 메이크, 오류 부분  makefile 에서 삭제 등 해보았지만 되지 않아 포기
https://github.com/grpc/grpc/blob/master/INSTALL.md
설치할 수 있는 다른 루트 찾을 예정
------------------------------------------------------------------------------------
음성입력 기능 구현 + stt로 연결 (이정남)
음성입력 알고리즘 - ALSA 레코딩 프로그램 소스코드 스터디 및 수정
수정한 소스 실행 테스트 및 코드 추가 스터디


일일 업무 계획 & 진행상황 (1월 11일)

구글 stt 실행 (진선형)
1. 구글 speech 아이디 오류 문제 해결
오류 - /tmp/jack-1000/default/jack_0 failed (err=No such file or directory) - 무시하면됨
녹음하기 - http://bluexmas.tistory.com/574
스노우보이 음성테스트 - https://blog.naver.com/chandong83/221130223424
@@bazel, protobuf, pycamera, H264, FFMPEG 등. 여러 드라이버 설치@@
-- 스노우보이 음성 잡기@@@@@
2. https://grpc.io/docs/quickstart/cpp.html
grpc 설치 오류!!
------------------------------------------------------------------------------------

음성입력 기능 구현 + stt로 연결 (이정남)
음성입력 알고리즘 - ALSA 레코딩 프로그램 소스코드 스터디 및 수정
음성입력을 stt로 전달하는 방법 조사 -> .raw 오디오 포맷으로 구글 스피치 API로 전달
.raw 오디오 포맷 생성에 관한 스터디 및 레코딩 프로그램 소스코드 수정
wav 포맷을 raw 포맷으로 -> https://www.hellomico.com/getting-started/convert-audio-to-raw/




일일 업무 계획 & 진행상황 (1월 10일)

구글 stt 실행 (진선형)
1. 구글 stt 돌려보기 & c나 c++ 연동하기.
export 키 받기 - https://cloud.google.com/speech/docs/quickstart
http://cafe.naver.com/openrt/16903
export 후 위 내용 깃으로 받아 실행시 접속요청은 되나 진행 오류남.
------------------------------------------------------------------------------------
음성입력 기능 구현 + stt로 연결 (이정남)
음성입력 알고리즘 - ALSA 레코딩 프로그램 소스코드 스터디 및 수정
음성 입력 신호의 진폭을 모니터링하는 알고리즘 스터디
모니터링한 값을 얻어 코드를 수정할 수 있도록 코드 정리
입력 받은 음성 데이터를 .wav 포맷으로 저장하는 알고리즘 스터디

일일 업무 계획 & 진행상황 (1월 9일)

돌려보고 구조 파악하기 (진선형)
1. 파이썬 대화하기(구글 stt, 네이버 tts)
http://cafe.naver.com/openrt/16903
네이버 tts 성공
구글 stt는 오류남.
2. 구글 어시스턴트 파이썬으로 돌리기
http://blog.naver.com/PostView.nhn?blogId=chandong83&logNo=221081942490&parentCategoryNo=&categoryNo=65&viewDate=&isShowPopularPosts=false&from=postView
실패-
------------------------------------------------------------------------------------
음성입력 기능 구현 + stt로 연결 (이정남)
음성입력 알고리즘 - ALSA 레코딩 프로그램 소스코드 스터디 및 수정
음성 입력 시간 수정 가능하도록 코딩 완료  
