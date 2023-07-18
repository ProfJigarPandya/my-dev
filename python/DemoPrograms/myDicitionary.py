#Implementing my vocabulary using dictionary data structure
#Replace username and password and proxy server ip with proxy details or comment the code.

import urllib.request as req



vocabulary = dict({'good':'Having desirable or positive qualities especially those suitable for a thing specified','bad':'Things which is not suitable','acceptable':'Something which interests you in keeping with you when offered'})

searchword = input("What are you looking to find meaning of?")
url = "http://www.wdyl.com/profanity?q="+searchword


proxy = req.ProxyHandler({'http': 'http://username:password@x.x.x.x:8080'})
auth = req.HTTPBasicAuthHandler()
opener = req.build_opener(proxy, auth, req.HTTPHandler)
req.install_opener(opener)
urlconn = req.urlopen(url)
profane_response = urlconn.read().decode(urlconn.headers.get_content_charset())
urlconn.close()

print(profane_response)

if 'true' in profane_response:
    print("\n Profanity alert")
elif 'false' in profane_response:
    try:
        if vocabulary[searchword]:
            print (vocabulary[searchword])
    except KeyError:
        print ("Word is not found in program vocabulary")
else:
    print ("No connection established for profanity check")
    
print("Have a nice day")
