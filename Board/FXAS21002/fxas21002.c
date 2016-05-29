/***********************************************************************************************
/                            FXAS21002��������������----C�ļ�
/-----------------------------------------------------------------------------------------------
/----�Ա��������ݺ���ӿƼ�      http://crzongheng.taobao.com
/----�汾��V1.0  
/----ʱ�䣺2015-7-21
/----˵����IIC����ͨ��
***********************************************************************************************/

#include "FXAS21002.h"

#include "IMU_IIC.h"

//*************************************** �궨�� ***********************************************

//***************************************�������***********************************************
//ȫ�ֱ���
short int Gyro_FXAS21002_X, Gyro_FXAS21002_Y, Gyro_FXAS21002_Z;//���ٶ������ֵ

//***************************************  ����  ***********************************************   
/*
************************************************************************************************
*������void fxas_delay(unsigned short int k)
*������k����ʱ��С
*���أ�0
*���ܣ���ʱ
************************************************************************************************
*/
void fxas_delay(unsigned short int k)
{
    unsigned char i;	 

    while(--k)
    {
        for(i = 0;i < 100;i++); //��ʱʱ�䳤�̣�0--255��ѡ
    }
}
/*
************************************************************************************************
*������unsigned char FXAS21002_readbyte(unsigned char address)
*������address����ַ
*���أ�����������
*���ܣ���ȡFXAS21002��1���ֽ�
************************************************************************************************
*/
unsigned char FXAS21002_readbyte(unsigned char address)
{
	unsigned char ret;
	IIC_start();		//����
	IIC_send_byte(FXAS21002_IIC_ADDRESS);	//д���豸ID��д�ź�
	IIC_send_byte(address);	//X��ַ
	IIC_start();		//���·��Ϳ�ʼ
	IIC_send_byte(FXAS21002_IIC_ADDRESS+1);	//д���豸ID������
	ret = IIC_read_byte();	//��ȡһ�ֽ�
	IIC_stop();

	return ret;
}
/*
************************************************************************************************
*������void FXAS21002_writebyte(unsigned char address, unsigned char thedata)
*������address����ַ��thedata��д�������
*���أ�0
*���ܣ�д��FXAS21002��1���ֽ�
************************************************************************************************
*/
void FXAS21002_writebyte(unsigned char address, unsigned char thedata)
{
	IIC_start();		//����
	IIC_send_byte(FXAS21002_IIC_ADDRESS);	//д���豸ID��д�ź�
	IIC_send_byte(address);	//X��ַ
	IIC_send_byte(thedata);	//д���豸ID������
	IIC_stop();
}
/*
************************************************************************************************
*������short int FXAS21002_GetResult(unsigned char Status, unsigned char Regs_Addr)
*������Status�����ݼĴ���״̬��Regs_Addr�����ݼĴ�����ַ
*���أ����ٶ�ֵ��short int��
*���ܣ���FXAS21002���ٶ����
************************************************************************************************
*/
short int FXAS21002_GetResult(unsigned char Status, unsigned char Regs_Addr) 
{
  unsigned char      ret = 0;
  unsigned short int cnt = 0;
  short int          result,temp;

  if(Regs_Addr > FXAS21002_OUT_Z_LSB)
    return 0;

  // �ȴ�ת����ɲ�ȡ��ֵ
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
*������FXAS21002_XYZ()
*������0
*���أ�����ļ��ٶ�ֵ��short int��
*���ܣ���ȡ3����ٶ�
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
*������void FXAS21002_Init()
*������0
*���أ�����ļ��ٶ�ֵ��short int��
*���ܣ���ʼ��FXAS21002,��������ο��ֲ�
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
