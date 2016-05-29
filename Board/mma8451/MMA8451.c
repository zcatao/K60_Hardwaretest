/***********************************************************************************************
/                            MMA8451���ٶ���������----C�ļ�
/-----------------------------------------------------------------------------------------------
/----�Ա��������ݺ���ӿƼ�      http://crzongheng.taobao.com
/----�汾��V1.0  
/----ʱ�䣺2015-7-21
/----˵����IIC����ͨ��
***********************************************************************************************/

#include "MMA8451.h"

#include "IMU_IIC.h"

//*************************************** �궨�� ***********************************************

//***************************************�������***********************************************
//ȫ�ֱ���
short int ACC_X, ACC_Y, ACC_Z;//���ٶ������ֵ

//***************************************  ����  ***********************************************   
/*
************************************************************************************************
*������void mma_delay(unsigned short int k)
*������k����ʱ��С
*���أ�0
*���ܣ���ʱ
************************************************************************************************
*/
void mma_delay(unsigned short int k)
{
    unsigned char i;

    while(--k)
    {
       for(i = 0;i < 100;i++); //��ʱʱ�䳤�̣�0--255��ѡ
    }
}
/*
************************************************************************************************
*������unsigned char MMA8451_readbyte(unsigned char address)
*������address����ַ
*���أ�����������
*���ܣ���ȡMMA8451��1���ֽ�
************************************************************************************************
*/
unsigned char MMA8451_readbyte(unsigned char address)
{
	unsigned char ret;
	IIC_start();		//����
	IIC_send_byte(MMA845x_IIC_ADDRESS);	//д���豸ID��д�ź�
	IIC_send_byte(address);	//X��ַ
	IIC_start();		//���·��Ϳ�ʼ
	IIC_send_byte(MMA845x_IIC_ADDRESS+1);	//д���豸ID������
	ret = IIC_read_byte();	//��ȡһ�ֽ�
	IIC_stop();

	return ret;
}
/*
************************************************************************************************
*������void MMA8451_writebyte(unsigned char address, unsigned char thedata)
*������address����ַ��thedata��д�������
*���أ�0
*���ܣ�д��MMA8451��1���ֽ�
************************************************************************************************
*/
void MMA8451_writebyte(unsigned char address, unsigned char thedata)
{
	IIC_start();		//����
	IIC_send_byte(MMA845x_IIC_ADDRESS);	//д���豸ID��д�ź�
	IIC_send_byte(address);	//X��ַ
	IIC_send_byte(thedata);	//д���豸ID������
	IIC_stop();
}
/*
************************************************************************************************
*������short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr)
*������Status�����ݼĴ���״̬��Regs_Addr�����ݼĴ�����ַ
*���أ����ٶ�ֵ��short int��
*���ܣ���MMA8451���ٶ����
************************************************************************************************
*/ 
short int MMA8451_GetResult(unsigned char Status, unsigned char Regs_Addr) 
{
  unsigned char      ret = 0;
  unsigned short int cnt = 0;
  short int          result,temp;
  
  if(Regs_Addr > MMA8451_REG_OUTZ_LSB)
    return 0;
  
  // �ȴ�ת����ɲ�ȡ��ֵ 
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
*������void MMA8451_XYZ()
*������0
*���أ�����ļ��ٶ�ֵ��short int��
*���ܣ���ȡ3����ٶ�
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
*������void MMA8451_Init()
*������0
*���أ�0
*���ܣ���ʼ��L3G4200,��������ο��ֲ�
************************************************************************************************
*/
void MMA8451_Init()
{	
  while(MMA8451_readbyte(MMA8451_REG_WHOAMI)!=0x1a);
	mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_SYSMOD,0x00);	   //Ĭ��ģʽStandby Mode
	mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_CTRL_REG2,0x02); //High Resolution
    mma_delay(10);
	MMA8451_writebyte(MMA8451_REG_CTRL_REG1,0x01); //����ģʽ,800HZ
	
}
//****************************************END***************************************************