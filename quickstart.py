from __future__ import print_function
#-*- coding: utf-8 -*-

# =================================================
# import => module
# =================================================
import os
import httplib2
import datetime
import time
import io
import sys
reload(sys)
sys.setdefaultencoding('utf-8')
if not hasattr(sys, 'argv'):
    sys.argv  = ['']

import unicodedata
    
# =================================================
# from & import => module
# =================================================
from googleapiclient import sample_tools
from oauth2client import tools
from oauth2client.file import Storage
from oauth2client import client
from apiclient import discovery

if not hasattr(sys,'argv'):
    sys.argv=[]
import json

try:
    import argparse
    flags = argparse.ArgumentParser(parents=[tools.argparser]).parse_args()
except ImportError:
    flags = None

Dbug = False

# If modifying these scopes, delete your previously saved credentials
# at ~/.credentials/calendar-python-quickstart.json
SCOPES = 'https://www.googleapis.com/auth/calendar.readonly' 
#CLIENT_SECRET_FILE = '/media/ark/sub/smartmirror/calendar/quick_google/calendar_key.json'
CLIENT_SECRET_FILE = './master_key.json'    # api사용시 
APPLICATION_NAME = 'Google Calendar API Python Quickstart'

# =================================================
# get calendar credentials 
# =================================================
def get_credentials():
    """Gets valid user credentials from storage.
    If nothing has been stored, or if the stored credentials are invalid,
    the OAuth2 flow is completed to obtain the new credentials.
    Returns:
        Credentials, the obtained credential.
    """
    home_dir = os.path.expanduser('~')
    credential_dir = os.path.join(home_dir, '.credentials')
    if not os.path.exists(credential_dir):
        os.makedirs(credential_dir)
    credential_path = os.path.join(credential_dir,
                                   'calendar-python-quickstart.json')

    store = Storage(credential_path)
    credentials = store.get()
    if not credentials or credentials.invalid:
        flow = client.flow_from_clientsecrets(CLIENT_SECRET_FILE, SCOPES)
        flow.user_agent = APPLICATION_NAME
        if flags:
            credentials = tools.run_flow(flow, store, flags)
        else: # Needed only for compatibility with Python 2.6
            credentials = tools.run(flow, store)
        print('Storing credentials to ' + credential_path)
    return credentials


# =================================================
# nowDate == calendarDate check
# =================================================
def time_check(calendar_day):
    """
    time compare
    nowDate == input_date:calendar_day return True
    nowDate != input_date:calendar_day return False
    """
    now = datetime.datetime.now()
    nowDate = now.strftime('%Y-%m-%d') #datetime.datetime.now() 

    if nowDate in calendar_day:
        return True
    else:
        return False


# =================================================
# get calendar info
# =================================================
def get_calendar_info():
    """
    Shows basic usage of the Google Calendar API.
    Creates a Google Calendar API service object and outputs a list of the next
    10 events on the user's calendar.
    """
    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time
    print('Getting the upcoming 10 events')
    eventsResult = service.events().list(
        calendarId='primary', timeMin=now, maxResults=10, singleEvents=True,
        orderBy='startTime').execute()
    events = eventsResult.get('items', [])

    if not events:
        print('No upcomming events found')
    for event in events:
        start = event['start'].get('dateTime',event['start'].get('date'))
        print(start, event['summary'])

# =================================================
# calendar standard time the day event  get
# 당일 일정 확인
# =================================================
def get_eventTodayList_standnowtime():

    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    page_token = None
    event_mintime = datetime.datetime.today().isoformat() + 'Z' # 'Z' indicates UTC time

    # list 타입을 string타입으로 변환
    theday_list = datetime.date.today().strftime("%Y-%m-%d").split('-') # result type list
    theday = "-".join(theday_list)  # cobverting list -> string 

    # 당일 전체 일정을 가져오기 위한 시간 설정
    event_mintime = theday+"T00:00:00Z"
    event_maxtime = theday+"T23:59:59Z"

    if Dbug:
        print("today : ",theday, "type:",type(theday))
        print("mintime :\t\t" ,event_mintime, "type : ",type(event_mintime))

    # ================================================================
    # timeMin,timeMax format 
    # RFC3339 : ex)2018-02-09T07:02:06.440759Z
    # timeMin parameter defolt format  ex)2018-02-10T00:00:00Z(yyyy-mm-ddThh:mm:ssZ || 2018-02-09 16:24:39.060761)
    # ================================================================
    eventsResult = service.events().list(
        calendarId='primary', timeMin=event_mintime, timeMax=event_maxtime,
        maxResults=10, singleEvents=True,
        orderBy='startTime').execute()
    events = eventsResult.get('items', [])

    if not events:
        print('No upcoming events found')
    for event in events:
        # json 타입으로 반환된 결과 값에서 날짜와 일정이름만 출력되도록 설정
        start = event['start'].get('dateTime',event['start'].get('date'))
        print(start, event['summary'])

    return None

# =================================================
# test functin   
# =================================================
def get_list():

    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    page_token = None
    event_mintime = datetime.datetime.today().isoformat() + 'Z' # 'Z' indicates UTC time

    theday_list = datetime.date.today().strftime("%Y-%m-%d").split('-') # result type list
    theday = "-".join(theday_list)  # cobverting list -> string

    event_mintime = theday+"T00:00:00Z"
#   print("time - min : ", event_mintime)
    event_maxtime = theday+"T23:59:59Z"
#   print("time - max : ", event_maxtime)

    if Dbug:
        print("today : ",theday, "type:",type(theday))
        print("mintime :\t\t" ,event_mintime, "type : ",type(event_mintime))

    # ================================================================
    # timeMin,timeMax format 
    # RFC3339 : ex)2018-02-09T07:02:06.440759Z
    # timeMin parameter defolt format  ex)2018-02-10T00:00:00Z(yyyy-mm-ddThh:mm:ssZ || 2018-02-09 16:24:39.060761)
    # ================================================================
    eventsResult = service.events().list(
        calendarId='primary', timeMin=event_mintime, timeMax=event_maxtime,
        maxResults=10, singleEvents=True,
        orderBy='startTime').execute()
    events = eventsResult.get('items', [])
    
    print("======================================================")
    print("                     python start                     ")
    print("======================================================")

    time_event = None

    if not events:
        print('No upcoming events found')
    for event in events:
        start = event['start'].get('dateTime',event['start'].get('date'))
        buf = start+" "+event['summary']+"/"
        if time_event is None:
            time_event = buf
        else:
            time_event += buf
        print("start,event\t: ", start, event['summary'])
        print("buf \t\t: ",buf)

    print("======================================================")
    print("                     py event list finish")
    print("======================================================")
    print("time_event : ",time_event)
    print("py start            : ",start)
    print("py event['summary'] : ",event['summary'])
    print("py event['summary'] : ",type(event['summary']))
    print("py type start : ",type(isinstance(start,(str, basestring))),"event['summary'] : ",type(event['summary']))
    
    return time_event

# =================================================
# check calendar event jsonformat and save file
# =================================================
def check_calendar_jsonformat():
    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    page_token = None

    event_list = json.dumps(events, inden =4) 
    f = open ("calendar_event.txt",'w')
    f.write(event_list)
    f.close()
    print(json.dumps(eventsResult, indent=4), eventsResult['summary'])

# =================================================
# calendar the day event get 
# =================================================
def standard_theday_event():
    credentials = get_credentials()
    http = credentials.authorize(httplib2.Http())
    service = discovery.build('calendar', 'v3', http=http)

    page_token = None
    event_mintime = datetime.datetime.today().isoformat() + 'Z' # 'Z' indicates UTC time
    print("event_mintime : " ,event_mintime, "type : ",type(event_mintime))

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time
    print("datetime.utcnow() : ",now, "type-now : ",type(now))


def main():
#   Dbug = 0
#   print(time_check("2018-02-04"))
#   get_calendar_info()
    get_eventTodayList_standnowtime()
    if Dbug is 1:
        get_list()

if __name__ == '__main__':
    main()
