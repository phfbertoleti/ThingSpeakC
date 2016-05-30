# ThingSpeakC
Upload data to [ThingSpeak](https://thingspeak.com/) in C (socket level HTTP req).

## Getting Started

### Instructions (for Linux users):

#### Build and Clone

First clone this repo:

```shell
"$ git clone https://github.com/phfbertoleti/ThingSpeakC.git"
```

Then to compile, in the clone directory, type the command __make__

```shell
"$ make"
```

(so, It'll compile the program) and have fun!

#### Execute

To execute the program, some parameters are needed on its call (key and data to be sent, in this order). For example:

```shell
"$ ./ThingSpeakC E4AKR731LNBQ67EW 1 5 10"
```
It will send: 
* field1 = 1, 
* field2 = 5 
* field3 = 10 

To ThingSpeak's channel corresponding to __E4AKR731LNBQ67EW__ key, in this case, the channel [This Channel](https://thingspeak.com/channels/118265 ). 

So, to send data to your own channel, just change the key, change the data and have fun!

__IMPORTANT:__ this program only works with __integer__ type data.


## Author

[__Pedro Bertoleti__](https://github.com/phfbertoleti)
