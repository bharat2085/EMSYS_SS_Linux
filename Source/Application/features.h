#ifndef FEATURES_H
#define FEATURES_H

#include "msg.h"




extern void doAction_sslc(Msg *);
extern void doAction_duke(Msg *);
extern void doAction_playtones(Msg *);
extern void doAction_glassOpacCntrl(Msg *);
extern void doAction_rtc(Msg *);
extern void doAction_appsAlerts(Msg *);


extern void doAction_fwUpdate(Msg *);
extern void doAction_SystemInfo(Msg *);
extern void doAction_fwReboot(Msg *);
#endif
