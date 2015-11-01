#ifndef __msg_h
#define __msg_h

typedef unsigned char uint8;


#define SIZE_STRUCT_MSG 	16

typedef struct{
	uint8 version;
	uint8 devId;
	uint8 appKey;
	uint8 msg_type;

	int feature;
	int msg;
	int param1;
	int param2;

	int response;
	int seqno;

}Msg;




#endif
