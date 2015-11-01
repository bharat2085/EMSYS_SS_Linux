/*
 * alerts.c
 *
 *  Created on: 14/02/2015
 *      Author: bharat
 *
 *      sos sw, ads sensor alerts msg support.
 *      contains alerts handling mechanism.
 */

#include "defs.h"
#ifdef BUILD_FEATURE_ALERTS

#include "msg.h"
#include "fpc.h"



init_alertSystem()
{
//flag && interrupt based.

}




doAction_sendAlerts()
{

}


doAction_clearAlerts()
{

}



void doAction_alerts(Msg* p)
 {
	int cmd;

	 __no_operation();

	 cmd= p->msg;

	switch(cmd)
	{

	case CMD_ACTION_SEND_ALERTS:
		doAction_sendAlerts();
		break;

	case CMD_ACTION_CLEAR_ALERTS:
		doAction_clearAlerts();
		break;

	case CMD_ACTION_SET_TMP_THLD:
		break;

	case CMD_ACTION_SET_SD_THLD:
		break;



	default:
		_no_operation();
		break;

	}



 }




#endif
