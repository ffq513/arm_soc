/***************************************************\
*			Copy Right(C)���������Ű��Ƽ����޹�˾
*			 All Right Reserved
*
*�ļ����ƣ�IS32U320A_uart.c
*��    �ߣ�
*��    ����V1.0.0
*��    �ڣ�2015.02.05
*�������������IS32U320A������uartͨ�ŵĵײ�����
*�����б�
*			1��
*			2��
*			3��
*��ʷ��¼��
*	1�� ���ڣ�
*		�汾��
*		���ߣ�
*	�޸����ݣ�
*	2��.....
\***************************************************/
#define UART_GLOBAL
#include <string.h>
#include "uart.h"	
#include "XA1707.h"


/***************************************************\
*�������ƣ�Uart0SendData
*�������ܣ����uart1�ӿڷ������ݲ���
*�����������	       
*�����������
*�� �� ֵ����
*����˵����
\***************************************************/
void Uart0SendData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;

	u32WRITE(UART0_TXDATA,(*pData));
	
	do
	{
		tmpreg = u32READ(UART0_CON);
		tmpreg &= TX_BUSY_MASK;	
	}while(tmpreg==TX_BUSY_MASK);
}
/***************************************************\
*�������ƣ�Uart1SendData
*�������ܣ����uart1�ӿڷ������ݲ���
*�����������	       
*�����������
*�� �� ֵ����
*����˵����
\***************************************************/
void Uart1SendData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
	
	u32WRITE(UART1_TXDATA,(*pData));

	do
	{
		tmpreg = u32READ(UART1_CON);
		tmpreg &= TX_BUSY_MASK;	
	}while(tmpreg==TX_BUSY_MASK);
}
/***************************************************\
*�������ƣ�UartReceiveData
*�������ܣ����uart1�ӿڽ������ݲ���
*�����������	       
*�����������
*�� �� ֵ����
*����˵����
\***************************************************/
void Uart0ReceiveData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
//	do
//	{
//		tmpreg = u32READ(UART0_CON);
//		tmpreg &= RX_BUSY_MASK;
//	}while(tmpreg==RX_BUSY_MASK);
	tmpreg = u32READ(UART0_RXDATA);
	*pData = (UINT8)(tmpreg);
}
/***************************************************\
*�������ƣ�Uart1ReceiveData
*�������ܣ����uart1�ӿڽ������ݲ���
*�����������	       
*�����������
*�� �� ֵ����
*����˵����
\***************************************************/
void Uart1ReceiveData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
	
	tmpreg = u32READ(UART1_RXDATA);
	*pData = (UINT8)(tmpreg);
}
/***************************************************\
*�������ƣ�UartProcess
*�������ܣ����uart1�ӿ���Ӧ����
*�����������	       
*�����������
*�� �� ֵ����
*����˵����
\***************************************************/
void UartProcess(unsigned char uartnumber)
{
	
}
