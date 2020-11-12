# xbee_api
更改xbee.c outbuff[5~12] -> address of gateway(receiver) 較不會掉包
address of gateway(receiver) 可透過 XCTU 的 addressing中的SH,SL得知 (若SH少一個byte 前面補0x00)
