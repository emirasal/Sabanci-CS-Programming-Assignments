# Emir Asal

internetquota = float(input("Please enter your internet quota (GB): "))
totalvideoview = float(input("Please enter your total video viewing time in minutes: "))
numberofmessages = int(input("Please enter the number of messages you send: "))

video_gb = totalvideoview * 7.7/1024
message_gb = numberofmessages * 1.7/(1024*1024)

remaningquota = internetquota - video_gb - message_gb

totalvideoseconds = remaningquota / (7.7/1024) * 60
videohours = totalvideoseconds // 3600
videominutes = (totalvideoseconds - videohours*3600) // 60
videoseconds = totalvideoseconds - videohours*3600 - videominutes*60



print("Your remaining internet quota is", format(remaningquota, ".2f"), "GB(s).")
print("You can watch video for", int(videohours), "hour(s),", int(videominutes), "minute(s) and", format(videoseconds, ".2f"), "second(s).")
