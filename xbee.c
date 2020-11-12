#include<string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include"xbee.h"
//pack a message to a standard xbee frame, return lens of frame
int xbee_frame(unsigned char *msg, int len,  unsigned char *outBuff){
	unsigned char checksum = 0;

	outBuff[0] = 0x7E; //start byte
	outBuff[1] = 0x00;
	outBuff[2] = (unsigned char)(len+14);

	outBuff[3] = 0x10;	//transmit request
	outBuff[4] = 0x01;	//frame ID

	outBuff[5] = 0x00;	//dest adr  00..0FFFF->broadcast
	outBuff[6] = 0x13;
	outBuff[7] = 0xA2;
	outBuff[8] = 0x00;
	outBuff[9] = 0x41;
	outBuff[10] = 0x89;
	outBuff[11] = 0x6E;
	outBuff[12] = 0x8B;

	outBuff[13] = 0xFF;
	outBuff[14] = 0xFE;		//16bit d address

	outBuff[15] = 0x00;
	outBuff[16] = 0x00;


	memcpy(&outBuff[17],msg,len);

	for(int i=3;i<len+17;i++){
		checksum += outBuff[i];
	}

	outBuff[len+17] = 0xFF - checksum;
	return len+18;
}

