
/**************************************************************************
 * snet.h
 *
 *  created on: Aug 1, 2014
 *      Author: bharat
 ***************************************************************************/
#ifndef SNET_H_
#define SNET_H_

#include "msg.h"

//extern signed short  hSocket ;
typedef unsigned char   uint8;

/*
typedef struct _msg
{
	uint8 feature;
	uint8 cmd;
	uint8 nParam;
	char sParam[];

}Msg;
*/


extern signed char ConnectWithWellKnownAP();
//extern int8 OpenUdpPort_Mgr(long*, int );
extern uint8 receive_msg_from_Mgr( Msg * const );









#endif			//end of header SNET_H_

