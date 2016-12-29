/*
	Example of using ThingSpeak on Linux
	Author: Pedro Bertoleti
	Date: 05/2016
*/

#include <stdio.h>
#include <stdlib.h>
#include "ThingSpeakLinux.h"

//Test channel: https://thingspeak.com/channels/118265
//Key used for test channel: E4AKR731LNBQ67EW

int main (int argc, char *argv[])
{
	float FieldsArray[argc-1];
	int i;
		
    //arguments:
	//argv's index  -   description
	//0                 not used
	//1                 key of a ThingSpeak's channel (which you desire to send data)
	//2 ...             data to be sent to ThingSpeak's channel
	//
	//IMPORTANT: here, all data sent must be integer type numbers (this api does not support other types)
	
	
	//copying data arguments
	for(i=2;i<argc; i++)
		FieldsArray[i-2]=atof(argv[i]);
	
	//send data to channel.
	SendDataToThingSpeak(argc-2, &FieldsArray[0],argv[1],sizeof(argv[1]));
	
	//All done! If there was no network error, open channel on your favorite browser and check it out!
}
