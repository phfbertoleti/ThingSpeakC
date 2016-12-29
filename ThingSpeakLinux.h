/*
Module: Header - Communication with ThingSpeak (on Linux) via TCP Socket
Author:  Pedro Bertoleti
Date:   05/2016
*/

//defines
#define THINGSPEAK_OFFLINE_ERROR     0
#define THINGSPEAK_CONNECTION_ERROR  1
#define OPEN_SOCKET_ERROR            2
#define PARAMS_ERROR                 3
#define SEND_OK                      4

//global prototypes
char SendDataToThingSpeak(int FieldNo, float * FieldArray, char * Key, int SizeOfKey);
