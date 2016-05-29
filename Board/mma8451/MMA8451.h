/***********************************************************************************************
/                            MMA8451加速度驱动函数----h文件
/-----------------------------------------------------------------------------------------------
/----淘宝：驰瑞纵横电子科技			http://crzongheng.taobao.com
/----版本：V1.0	
/----时间：2015-7-21
/----说明：IIC总线通信
***********************************************************************************************/

#ifndef _MMA8451_H_
#define _MMA8451_H_

//#include "common.h"

//***************************************宏定义变量*********************************************

#define MMA845x_IIC_ADDRESS       0x3a


//MMA8451寄存器地址
#define MMA8451_REG_STATUS         0x00    //状态寄存器
#define MMA8451_REG_OUTX_MSB       0x01    //14位采样结果高8位[7:0]
#define MMA8451_REG_OUTX_LSB       0x02    //14位采样结果低6位[7:2]
#define MMA8451_REG_OUTY_MSB       0x03    //14位采样结果高8位[7:0]
#define MMA8451_REG_OUTY_LSB       0x04    //14位采样结果低6位[7:2]
#define MMA8451_REG_OUTZ_MSB       0x05    //14位采样结果高8位[7:0]
#define MMA8451_REG_OUTZ_LSB       0x06    //14位采样结果低6位[7:2]
#define MMA8451_REG_SYSMOD         0x0B    //当前系统模式
#define MMA8451_REG_WHOAMI         0x0D    //设备ID寄存器
#define MMA8451_REG_CTRL_REG1      0x2A    //系统控制寄存器1
#define MMA8451_REG_CTRL_REG2      0x2B    //系统控制寄存器2

//MMA8451功能参数
#define MMA8451_DEV_ADDR   0x1D //Normally,can range 0x08 to 0xEF
#define MMA8451_DEV_WRITE  MMA8451_DEV_ADDR<<1 | 0x00
#define MMA8451_DEV_READ   MMA8451_DEV_ADDR<<1 | 0x01
#define MMA8451_DEV_ID     0x1A   //MMA8451设备ID

//MMA8451 STATUS寄存器 寄存器位
#define MMA8451_STATUS_X_READY   0x01
#define MMA8451_STATUS_Y_READY   0x02
#define MMA8451_STATUS_Z_READY   0x04
#define MMA8451_STATUS_XYZ_READY 0x08
#define MMA8451_STATUS_X_OW      0x10
#define MMA8451_STATUS_Y_OW      0x20
#define MMA8451_STATUS_Z_OW      0x40
#define MMA8451_STATUS_XYZ_OW    0x80

//定义SCL Bus Speed取值，外设总线为50Mhz时的计算结果
#define MMA8451_SCL_50KHZ                   (0x33) 
#define MMA8451_SCL_100KHZ                  (0x2B)  
#define MMA8451_SCL_150KHZ                  (0x28)
#define MMA8451_SCL_200KHZ                  (0x23)
#define MMA8451_SCL_250KHZ                  (0x21)
#define MMA8451_SCL_300KHZ                  (0x20)
#define MMA8451_SCL_400KHZ                  (0x17)  


extern short int ACC_X, ACC_Y, ACC_Z;

//***************************************函数声明***********************************************

unsigned char MMA8451_readbyte(unsigned char address);
void MMA8451_writebyte(unsigned char address, unsigned char thedata);
void MMA8451_Init();
short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr);
void MMA8451_XYZ();


#endif

//****************************************END***************************************************
