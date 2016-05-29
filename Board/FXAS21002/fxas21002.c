/***********************************************************************************************
/                            FXAS21002陀螺仪驱动函数----C文件
/-----------------------------------------------------------------------------------------------
/----淘宝：驰瑞纵横电子科技      http://crzongheng.taobao.com
/----版本：V1.0  
/----时间：2015-7-21
/----说明：IIC总线通信
***********************************************************************************************/

#include "FXAS21002.h"

#include "IMU_IIC.h"

//*************************************** 宏定义 ***********************************************

//***************************************定义变量***********************************************
//全局变量
short int Gyro_FXAS21002_X, Gyro_FXAS21002_Y, Gyro_FXAS21002_Z;//加速度三轴的值

//***************************************  函数  ***********************************************   
/*
************************************************************************************************
*函数：void fxas_delay(unsigned short int k)
*参数：k：延时大小
*返回：0
*功能：延时
************************************************************************************************
*/
void fxas_delay(unsigned short int k)
{
    unsigned char i;	 

    while(--k)
    {
        for(i = 0;i < 100;i++); //延时时间长短，0--255可选
    }
}
/*
************************************************************************************************
*函数：unsigned char FXAS21002_readbyte(unsigned char address)
*参数：address：地址
*返回：读到的数据
*功能：读取FXAS21002的1个字节
************************************************************************************************
*/
unsigned char FXAS21002_readbyte(unsigned char address)
{
	unsigned char ret;
	IIC_start();		//启动
	IIC_send_byte(FXAS21002_IIC_ADDRESS);	//写入设备ID及写信号
	IIC_send_byte(address);	//X地址
	IIC_start();		//重新发送开始
	IIC_send_byte(FXAS21002_IIC_ADDRESS+1);	//写入设备ID及读信
	ret = IIC_read_byte();	//读取一字节
	IIC_stop();

	return ret;
}
/*
************************************************************************************************
*函数：void FXAS21002_writebyte(unsigned char address, unsigned char thedata)
*参数：address：地址；thedata：写入的数据
*返回：0
*功能：写入FXAS21002的1个字节
************************************************************************************************
*/
void FXAS21002_writebyte(unsigned char address, unsigned char thedata)
{
	IIC_start();		//启动
	IIC_send_byte(FXAS21002_IIC_ADDRESS);	//写入设备ID及写信号
	IIC_send_byte(address);	//X地址
	IIC_send_byte(thedata);	//写入设备ID及读信
	IIC_stop();
}
/*
************************************************************************************************
*函数：short int FXAS21002_GetResult(unsigned char Status, unsigned char Regs_Addr)
*参数：Status：数据寄存器状态；Regs_Addr：数据寄存器地址
*返回：加速度值（short int）
*功能：读FXAS21002角速度输出
************************************************************************************************
*/
short int FXAS21002_GetResult(unsigned char Status, unsigned char Regs_Addr) 
{
  unsigned char      ret = 0;
  unsigned short int cnt = 0;
  short int          result,temp;

  if(Regs_Addr > FXAS21002_OUT_Z_LSB)
    return 0;

  // 等待转换完成并取出值
  while(!(ret & Status))
  {
    ret = FXAS21002_readbyte(FXAS21002_DR_STATUS);
    if(++cnt > 500)
      break;
  }

  result = FXAS21002_readbyte(Regs_Addr);
  temp   = FXAS21002_readbyte(Regs_Addr + 1);
  result = result << 8;
  result = result|temp;

  return result >> 2;
}
/*
************************************************************************************************
*函数：FXAS21002_XYZ()
*参数：0
*返回：三轴的加速度值（short int）
*功能：读取3轴角速度
************************************************************************************************
*/
void FXAS21002_XYZ()
{
    Gyro_FXAS21002_X = FXAS21002_GetResult(FXAS21002_DR_STATUS, FXAS21002_OUT_X_MSB);
    Gyro_FXAS21002_Y = FXAS21002_GetResult(FXAS21002_DR_STATUS, FXAS21002_OUT_Y_MSB);
    Gyro_FXAS21002_Z = FXAS21002_GetResult(FXAS21002_DR_STATUS, FXAS21002_OUT_Z_MSB);
}
/*
************************************************************************************************
*函数：void FXAS21002_Init()
*参数：0
*返回：三轴的加速度值（short int）
*功能：初始化FXAS21002,具体参数参考手册
************************************************************************************************
*/
void FXAS21002_Init()
{
   while(FXAS21002_readbyte(FXAS21002_WHO_AM_I)!=0xD7);
   fxas_delay(10);
   FXAS21002_writebyte(FXAS21002_CTRL_REG1, 0x00);
   fxas_delay(10);
   FXAS21002_writebyte(FXAS21002_CTRL_REG0, 0x00);
   fxas_delay(10);
   FXAS21002_writebyte(FXAS21002_CTRL_REG1, 0x02);
   fxas_delay(10);
}
//****************************************END***************************************************
