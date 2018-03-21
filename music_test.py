import sys, os
#f = open('youtube_omxplayer.txt','r')
#url = f.readline()
#f.close()
#print url
#os.system('omxplayer -b ' + url)

url=os.system('youtube-dl -g https://www.youtube.com/watch?v=LG8wAehRuYA')
os.system('omxplayer -o hdmi '+ str(url))
