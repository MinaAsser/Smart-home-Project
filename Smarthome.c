#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "UART_Int.h"
#include "smarthome priv .h"
#include "smarthome_interface.h"

//u8 usernames[10[20]] = {"user0" , "user1", "user2","user3","user4","user5","user6","user7","user8","user9"};
//u8 Passwords[10][4]={"0000","1111","2222","3333","4444","5555","6666","7777","8888","9999"};

u8 username1[10] = {"mina"};
u8 username2[10] = {"Kiro"};
u8 username3[10] = {"ahlam"};
u8 username4[10] = {"hema"};
u8 username5[10] = {"layla"};
u8 username6[10] = {"mona"};
u8 username7[10] = {"ali"};
u8 username8[10] = {"morad"};
u8 username9[10] = {"andraw"};
u8 username10[10] = {"mario"};

static u8 pass1[3]={"1a"};
static u8 pass2[3]={"2b"};
static u8 pass3[3]={"3c"};
static u8 pass4[3]={"4d"};
static u8 pass5[3]={"5e"};
static u8 pass6[3]={"6f"};
static u8 pass7[3]={"7g"};
static u8 pass8[3]={"8h"};
static u8 pass9[3]={"9i"};
static u8 pass10[3]={"10j"};


void Smart_homeInit(void){
	DIO_VidSetPinDirection(Smart_Home_PORT, User_Pin , Output);
	DIO_VidSetPinDirection(Smart_Home_PORT, Error_Pin,Output);
	DIO_VidSetPinDirection(Smart_Home_PORT, Alarm_Pin,Output);
	DIO_VidSetPinDirection(Smart_Home_PORT, Door_Pin ,Output);





}
void Smart_LedOn(void){
DIO_VidSetPinValue(Smart_Home_PORT, User_Pin , PinHigh);
}
void Smart_Ledoff(void){
DIO_VidSetPinValue(Smart_Home_PORT, User_Pin , PinLow);
}

void Smarthome_Error(void){

	DIO_VidSetPinValue(Smart_Home_PORT, Error_Pin , PinHigh);

}


u8 Checkusername(u8 *Local_u8Var)
{
	u8 counter=0;
	u8 ret_flag=0;
	u8 flag1=0;
	u8 flag2=0;
	u8 flag3=0;
	u8 flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0;
	for(counter=0;counter<=20;counter++)
	{
		if(Local_u8Var[counter]==username1[counter] && (*(username1+counter))!='\0')
		{
	//check but the name isnt end
		}
		else if(Local_u8Var[counter]==username1[counter] && (*(username1+counter))=='\0')
		{
			flag1=1;

			break;
			// the name end there is null
		}
		else
		{
			break;
			// two name arent identical
		}
	}
	//check the sec name
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username2[counter] && (*(username2+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username2[counter] && (*(username2+counter))=='\0')
		{
			flag2=2;

			break;
		}
		else
		{
			break;
		}
	}
	//check 3 name
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username3[counter] && (*(username3+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username3[counter] && (*(username3+counter))=='\0')
		{
			flag3=3;

			break;
		}
		else
		{
			break;
		}
	}
	//*********4name
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username4[counter] && (*(username4+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username4[counter] && (*(username4+counter))=='\0')
		{
			flag4=4;

			break;
		}
		else
		{
			break;
		}
	}
	//**************************5555
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username5[counter] && (*(username5+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username5[counter] && (*(username5+counter))=='\0')
		{
			flag5=5;

			break;
		}
		else
		{
			break;
		}
	}
	//********************666
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username6[counter] && (*(username6+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username6[counter] && (*(username6+counter))=='\0')
		{
			flag6=6;

			break;
		}
		else
		{
			break;
		}
	}
	//*******7
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username7[counter] && (*(username7+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username7[counter] && (*(username7+counter))=='\0')
		{
			flag7=7;

			break;
		}
		else
		{
			break;
		}
	}
	//******8
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username8[counter] && (*(username8+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username8[counter] && (*(username8+counter))=='\0')
		{
			flag8=8;

			break;
		}
		else
		{
			break;
		}
	}
	//***9
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username9[counter] && (*(username9+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username9[counter] && (*(username9+counter))=='\0')
		{
			flag9=9;

			break;
		}
		else
		{
			break;
		}
	}
	//***10
	for(counter=0;counter<=20;counter++)
	{
	if(Local_u8Var[counter]==username10[counter] && (*(username10+counter))!='\0')
		{

		}
		else if(Local_u8Var[counter]==username10[counter] && (*(username10+counter))=='\0')
		{
			flag10=10;
			break;
		}
		else
		{
			break;
		}
	}
	//**
	if(flag1==1)
	{
		ret_flag=1;
	}
	if(flag2==2)
	{
		ret_flag=2;
	}
	if(flag3==3)
	{
		ret_flag=3;
	}
	if(flag4==4)
	{
		ret_flag=4;
	}
	if(flag5==5)
	{
		ret_flag=5;
	}
	if(flag6==6)
	{
		ret_flag=6;
	}
	if(flag7==7)
	{
		ret_flag=7;
	}
	if(flag8==8)
	{
		ret_flag=8;
	}
	if(flag9==9)
	{
		ret_flag=9;
	}
	if(flag10==10)
	{
		ret_flag=10;
	}

	return ret_flag;
	}
u8 check_password(u8*arr,u8 flag)
{
	u8 flag1=0;
	u8 flag2=0;
	u8 flag3=0;
	u8 flag4=0,flag5=0,flag6=0,flag7=0,flag8=0,flag9=0,flag10=0;
	u8 green_flag=0;
	u8 counter=0;

	for(counter=0;counter<=3;counter++)
	{
		if(arr[counter]==pass1[counter] && (*(pass1+counter))!='\0')
		{

		}
		else if(arr[counter]==pass1[counter] && (*(pass1+counter))=='\0')
		{
			flag1=1;
			break;
		}
		else
		{
			break;
		}
	}
	//----------------------------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass2[counter] && (*(pass2+counter))!='\0')
			{

			}
			else if(arr[counter]==pass2[counter] && (*(pass2+counter))=='\0')
			{
				flag2=2;

				break;
			}
			else
			{
				break;
			}
		}
	//-------------------------------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass3[counter] && (*(pass3+counter))!='\0')
			{

			}
			else if(arr[counter]==pass3[counter] && (*(pass3+counter))=='\0')
			{
				flag3=3;

				break;
			}
			else
			{
				break;
			}
		}
	//-------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass4[counter] && (*(pass4+counter))!='\0')
			{

			}
			else if(arr[counter]==pass4[counter] && (*(pass4+counter))=='\0')
			{
				flag4=4;

				break;
			}
			else
			{
				break;
			}
		}
	//----------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass5[counter] && (*(pass5+counter))!='\0')
			{

			}
			else if(arr[counter]==pass5[counter] && (*(pass5+counter))=='\0')
			{
				flag5=5;

				break;
			}
			else
			{
				break;
			}
		}
	//-----------------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass6[counter] && (*(pass6+counter))!='\0')
			{

			}
			else if(arr[counter]==pass6[counter] && (*(pass6+counter))=='\0')
			{
				flag6=6;

				break;
			}
			else
			{
				break;
			}
		}
	//-------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass7[counter] && (*(pass7+counter))!='\0')
			{

			}
			else if(arr[counter]==pass7[counter] && (*(pass7+counter))=='\0')
			{
				flag7=7;

				break;
			}
			else
			{
				break;
			}
		}
	//--------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass8[counter] && (*(pass8+counter))!='\0')
			{

			}
			else if(arr[counter]==pass8[counter] && (*(pass8+counter))=='\0')
			{
				flag8=8;

				break;
			}
			else
			{
				break;
			}
		}
	//------------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass9[counter] && (*(pass9+counter))!='\0')
			{

			}
			else if(arr[counter]==pass9[counter] && (*(pass9+counter))=='\0')
			{
				flag9=9;

				break;
			}
			else
			{
				break;
			}
		}
	//------------------------------------------------------------------------
	for(counter=0;counter<=3;counter++)
		{
			if(arr[counter]==pass10[counter] && (*(pass10+counter))!='\0')
			{

			}
			else if(arr[counter]==pass10[counter] && (*(pass10+counter))=='\0')
			{
				flag10=10;

				break;
			}
			else
			{
				break;
			}
		}
	if(flag1==1&&flag==1)
	{
		green_flag=1;
	}
	else if(flag2==2&&flag==2)
	{
		green_flag=2;
	}
	else if(flag3==3&&flag==3)
	{
		green_flag=3;
	}
	else if(flag4==4&&flag==4)
	{
		green_flag=4;
	}
	else if(flag5==5&&flag==5)
	{
		green_flag=5;
	}
	else if(flag6==6&&flag==6)
	{
		green_flag=6;
	}
	else if(flag7==7&&flag==7)
	{
		green_flag=7;
	}
	else if(flag8==8&&flag==8)
	{
		green_flag=8;
	}
	else if(flag9==9&&flag==9)
	{
		green_flag=9;
	}
	else if(flag10==10&&flag==10)
	{
		green_flag=10;
	}

	return green_flag;
	}

















/*
void Smart_Check_Name(char *user,char x[][20],int *u,int *user_number)
{
int Local_UsersCounter , Local_Element_Count = 0;

for(Local_UsersCounter = 0 ; Local_UsersCounter<4 ; Local_UsersCounter++)
            {
	          while(user[Local_Element_Count]== x[Local_UsersCounter][Local_Element_Count])
	      	{
	        	  if(x[Local_UsersCounter][Local_Element_Count])
	        {
	        		  *u = 1;
	      	*user_number = Local_UsersCounter;
	      	}
	          Local_Element_Count ++;
            }
         }
}

 void Smart_Get_password(u8 *password)
{
	u8 value ;
	int h=0;
				 do {
					 if (UART_RecieveChar(&value)== OK)
					 {
				       password[h]=value;
				       UART_SendChar(value);
					   h++;
					 }
	                 }while(h!=4);
				 UART_SendString("\n\n");
}

int Smart_Check_password(u8 *password,u8 pass[][4],s32 user_number)
{
	int h=0;
	int u=0;
				 while (password[h]== pass[user_number][h])
				 			    {
				 			     u++;
				 			     h++;
				 			    }
				 return u ;
}





*/
