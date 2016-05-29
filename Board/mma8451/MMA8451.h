/***********************************************************************************************
/                            MMA8451���ٶ���������----h�ļ�
/-----------------------------------------------------------------------------------------------
/----�Ա��������ݺ���ӿƼ�			http://crzongheng.taobao.com
/----�汾��V1.0	
/----ʱ�䣺2015-7-21
/----˵����IIC����ͨ��
***********************************************************************************************/

#ifndef _MMA8451_H_
#define _MMA8451_H_

//#include "common.h"

//***************************************�궨�����*********************************************

#define MMA845x_IIC_ADDRESS       0x3a


//MMA8451�Ĵ�����ַ
#define MMA8451_REG_STATUS         0x00    //״̬�Ĵ���
#define MMA8451_REG_OUTX_MSB       0x01    //14λ���������8λ[7:0]
#define MMA8451_REG_OUTX_LSB       0x02    //14λ���������6λ[7:2]
#define MMA8451_REG_OUTY_MSB       0x03    //14λ���������8λ[7:0]
#define MMA8451_REG_OUTY_LSB       0x04    //14λ���������6λ[7:2]
#define MMA8451_REG_OUTZ_MSB       0x05    //14λ���������8λ[7:0]
#define MMA8451_REG_OUTZ_LSB       0x06    //14λ���������6λ[7:2]
#define MMA8451_REG_SYSMOD         0x0B    //��ǰϵͳģʽ
#define MMA8451_REG_WHOAMI         0x0D    //�豸ID�Ĵ���
#define MMA8451_REG_CTRL_REG1      0x2A    //ϵͳ���ƼĴ���1
#define MMA8451_REG_CTRL_REG2      0x2B    //ϵͳ���ƼĴ���2

//MMA8451���ܲ���
#define MMA8451_DEV_ADDR   0x1D //Normally,can range 0x08 to 0xEF
#define MMA8451_DEV_WRITE  MMA8451_DEV_ADDR<<1 | 0x00
#define MMA8451_DEV_READ   MMA8451_DEV_ADDR<<1 | 0x01
#define MMA8451_DEV_ID     0x1A   //MMA8451�豸ID

//MMA8451 STATUS�Ĵ��� �Ĵ���λ
#define MMA8451_STATUS_X_READY   0x01
#define MMA8451_STATUS_Y_READY   0x02
#define MMA8451_STATUS_Z_READY   0x04
#define MMA8451_STATUS_XYZ_READY 0x08
#define MMA8451_STATUS_X_OW      0x10
#define MMA8451_STATUS_Y_OW      0x20
#define MMA8451_STATUS_Z_OW      0x40
#define MMA8451_STATUS_XYZ_OW    0x80

//����SCL Bus Speedȡֵ����������Ϊ50Mhzʱ�ļ�����
#define MMA8451_SCL_50KHZ                   (0x33) 
#define MMA8451_SCL_100KHZ                  (0x2B)  
#define MMA8451_SCL_150KHZ                  (0x28)
#define MMA8451_SCL_200KHZ                  (0x23)
#define MMA8451_SCL_250KHZ                  (0x21)
#define MMA8451_SCL_300KHZ                  (0x20)
#define MMA8451_SCL_400KHZ                  (0x17)  


extern short int ACC_X, ACC_Y, ACC_Z;

//***************************************��������***********************************************

unsigned char MMA8451_readbyte(unsigned char address);
void MMA8451_writebyte(unsigned char address, unsigned char thedata);
void MMA8451_Init();
short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr);
void MMA8451_XYZ();


#endif

//****************************************END***************************************************