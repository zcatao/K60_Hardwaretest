/***********************************************************************************************
/                            MMA8451加速度驱动函数----C文件
/-----------------------------------------------------------------------------------------------
/----淘宝：驰瑞纵横电子科技      http://crzongheng.taobao.com
/----版本：V1.0  
/----时间：2015-7-21
/----说明：IIC总线通信
***********************************************************************************************/

#include "MMA8451.h"

#include "IMU_IIC.h"

//*************************************** 宏定义 ***********************************************

//***************************************定义变量***********************************************
//全局变量
short int ACC_X, ACC_Y, ACC_Z;//加速度三轴的值

//***************************************  函数  ***********************************************   
/*
************************************************************************************************
*函数：void mma_delay(unsigned short int k)
*参数：k：延时大小
*返回：0
*功能：延时
************************************************************************************************
*/
void mma_delay(unsigned short int k)
{
    unsigned char i;

    while(--k)
    {
       for(i = 0;i < 100;i++); //延时时间长短，0--255可选
    }
}
/*
************************************************************************************************
*函数：unsigned char MMA8451_readbyte(unsigned char address)
*参数：address：地址
*返回：读到的数据
*功能：读取MMA8451的1个字节
************************************************************************************************
*/
unsigned char MMA8451_readbyte(unsigned char address)
{
	unsigned char ret;
	IIC_start();		//启动
	IIC_send_byte(MMA845x_IIC_ADDRESS);	//写入设备ID及写信号
	IIC_send_byte(address);	//X地址
	IIC_start();		//重新发送开始
	IIC_send_byte(MMA845x_IIC_ADDRESS+1);	//写入设备ID及读信
	ret = IIC_read_byte();	//读取一字节
	IIC_stop();

	return ret;
}
/*
************************************************************************************************
*函数：void MMA8451_writebyte(unsigned char address, unsigned char thedata)
*参数：address：地址；thedata：写入的数据
*返回：0
*功能：写入MMA8451的1个字节
************************************************************************************************
*/
void MMA8451_writebyte(unsigned char address, unsigned char thedata)
{
	IIC_start();		//启动
	IIC_send_byte(MMA845x_IIC_ADDRESS);	//写入设备ID及写信号
	IIC_send_byte(address);	//X地址
	IIC_send_byte(thedata);	//写入设备ID及读信
	IIC_stop();
}
/*
************************************************************************************************
*函数：short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr)
*参数：Status：数据寄存器状态；Regs_Addr：数据寄存器地址
*返回：加速度值（short int）
*功能：读MMA8451加速度输出
************************************************************************************************
*/ 
short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr) 
{
  unsigned char      ret = 0;
  unsigned short int cnt = 0;
  short int          result,temp;
  
  if(Regs_Addr > MMA8451_REG_OUTZ_LSB)
    return 0;
  
  // 等待转换完成并取出值 
  while(!(ret & Status)) 
  {
    ret = MMA8451_readbyte( MMA8451_REG_STATUS);
    if(++cnt > 500)
      break;
  }
  
  result = MMA8451_readbyte( Regs_Addr);
  temp   = MMA8451_readbyte( Regs_Addr+1);
  result = result << 8;
  result = result|temp;
  
  return result >> 2;
}
/*
************************************************************************************************
*函数：void MMA8451_XYZ()
*参数：0
*返回：三轴的加速度值（short int）
*功能：读取3轴角速度
************************************************************************************************
*/
void MMA8451_XYZ()
{
    ACC_X = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTX_MSB);
    ACC_Y = MMA8451_GetResult(MMA8451_STATUS_Y_READY, MMA8451_REG_OUTY_MSB);
    ACC_Z = MMA8451_GetResult(MMA8451_STATUS_X_READY, MMA8451_REG_OUTZ_MSB);	
}
/*
************************************************************************************************
*函数：void MMA8451_Init()
*参数：0
*返回：0
*功能：初始化L3G4200,具体参数参考手册
************************************************************************************************
*/
void MMA8451_Init()
{	
  while(MMA8451_readbyte(MMA8451_REG_WHOAMI)!=0x1a);
	mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_SYSMOD,0x00);	   //默认模式Standby Mode
	mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_CTRL_REG2,0x02); //High Resolution
    mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_CTRL_REG1,0x01); //主动模式,800HZ
	
}
//****************************************END***************************************************