#define CMD_GET_STATUS 0
#define CMD_WRITE_CRED 1
#define CMD_READ_CRED 2
#define CMD_CLEAR_CRED 3
#define CMD_RESET_MODEM 6
#define CMD_GET_BATTERY_STATUS 7
#define CMD_GET_BATTERY_SOC 8
#define CMD_GET_LIGHT_LEVEL 10
#define CMD_GET_TEMPERATURE 11
#define CMD_GET_LIGHT_SENSOR_STATE 12
#define CMD_GET_LIGHT_SENSOR_PARAMS 13
#define CMD_SET_LIGHT_SENSOR_PARAMS 14

#define CMD_PING 20
#define CMD_ACTIVATE_PDP 21
#define CMD_DEACTIVATE_PDP 22 
#define CMD_OPEN_TCP 23
#define CMD_CLOSE_TCP 24
#define CMD_OPEN_SEC_TCP 25
#define CMD_CLOSE_SEC_TCP 26
#define CMD_TCP_READ 27
#define CMD_TCP_WRITE 28
#define CMD_TCP_SEC_READ 29
#define CMD_TCP_SEC_WRITE 30
#define CMD_UPDATE_RTC 31
#define CMD_GET_SIG_QTY 32

#define CMD_MQTT_CONNECT 80
#define CMD_MQTT_PUBLISH 81
#define CMD_MQTT_SUBSCRIBE 82
#define CMD_MQTT_UNSUBSCRIBE 83
#define CMD_MQTT_PING 84
#define CMD_MQTT_DISCONNECT 85

#define CMD_RES_OFFSET 100

#define CMD_MQTT_CONNECTACK 180
#define CMD_MQTT_PUBLISHACK 181
#define CMD_MQTT_SUBSCRIBEACK 182
#define CMD_MQTT_UNSUBSCRIBEACK 183
#define CMD_MQTT_PINGRESP 184

//TODO
//--NOT Implemented
#define CMD_SET_RECONN_ATTEMP 33
#define CMD_SET_REINIT_4G 34
//--

//--NOT Tested
#define CMD_GPS_ENABLE 40
#define CMD_GPS_DISABLE 41
#define CMD_GPS_GET_STATUS 42
#define CMD_GPS_GET_LOCATION 43

#define CMD_GPS_ENABLEACK 140
#define CMD_GPS_DISABLEACK 141
#define CMD_GPS_GET_STATUSACK 142
#define CMD_GPS_GET_LOCATIONACK 143
//--