#ifndef SMARTHOME_INTERFACE_H
#define SMARTHOME_INTERFACE_H



#define User_Pin           Pin7
#define Error_Pin          Pin6
#define Alarm_Pin          Pin5
#define Door_Pin           Pin4
#define Smart_Home_PORT    Port_C

void Smart_homeInit(void);
u8 Checkusername(u8 *Local_u8Var);
void Smarthome_Error(void);
//void Smart_Get_password(u8 *password);
//int Smart_Check_password(u8 *password,u8 pass[][4],s32 user_number);


void Smart_Check_Name(char *user,char x[][20],int *u,int *user_number);
u8 check_password(u8*arr,u8 flag);
void Smart_LedOn(void);
void Smart_Ledoff(void);



#endif
