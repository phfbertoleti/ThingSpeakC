# ThingSpeakC
Upload data to ThingSpeak in C (socket level HTTP req).

Instructions (for Linux users): clone this repo, type the command make (so, It'll compile the program) and have fun!

To execute the program, some parameters are needed on its call (key and data to be sent, in this order). For example:

./ThingSpeakC E4AKR731LNBQ67EW 1 5 10

It will send field1=1, field2=5 and field3=10 data to ThingSpeak's channel corresponding to E4AKR731LNBQ67EW key (in this case, the channel https://thingspeak.com/channels/118265 ). So, to send data to your own channel, just change the key, change the data and have fun!

IMPORTANT: this program only works with integer type data.
