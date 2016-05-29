/***********************************************************************************************
/                            FXAS21002陀螺仪驱动函数----h文件
/-----------------------------------------------------------------------------------------------
/----淘宝：驰瑞纵横电子科技			http://crzongheng.taobao.com
/----版本：V1.0	
/----时间：2015-7-21
/----说明：IIC总线通信
***********************************************************************************************/

#ifndef _FXAS21002_H_
#define _FXAS21002_H_



//***************************************宏定义变量*********************************************

#define	FXAS21002_IIC_ADDRESS   0x42

//FXAS21002寄存器
#define FXAS21002_WHO_AM_I 			    0x0C//default 0xD7
#define FXAS21002_CTRL_REG0 			0x0D
#define FXAS21002_CTRL_REG1 			0x13
#define FXAS21002_CTRL_REG2 			0x14
#define FXAS21002_CTRL_REG3 			0x15
#define FXAS21002_TEMP 				    0x12
#define FXAS21002_STATUS 			    0x00
#define FXAS21002_OUT_X_MSB 			0x01
#define FXAS21002_OUT_X_LSB 			0x02
#define FXAS21002_OUT_Y_MSB 			0x03
#define FXAS21002_OUT_Y_LSB			    0x04
#define FXAS21002_OUT_Z_MSB			    0x05
#define FXAS21002_OUT_Z_LSB			    0x06
#define FXAS21002_DR_STATUS			    0x07
#define FXAS21002_F_STATUS			    0x08
#define FXAS21002_F_SETUP			    0x09
#define FXAS21002_F_EVENT			    0x0A
#define FXAS21002_INT_SRC_FLAG			0x0B
#define FXAS21002_RT_CFG			    0x0E
#define FXAS21002_RT_SRC 			    0x0F
#define FXAS21002_RT_THS 			    0x10
#define FXAS21002_RT_COUNT 			    0x11

extern short int Gyro_FXAS21002_X, Gyro_FXAS21002_Y, Gyro_FXAS21002_Z;

//***************************************函数声明***********************************************

unsigned char FXAS21002_readbyte(unsigned char address);
void FXAS21002_writebyte(unsigned char address, unsigned char thedata);
void FXAS21002_Init();
short int FXAS21002_GetResult(unsigned char Status, unsigned char Regs_Addr);
void FXAS21002_XYZ();


#endif

//****************************************END***************************************************
