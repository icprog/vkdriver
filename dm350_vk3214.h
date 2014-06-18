//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// Use of this source code is subject to the terms of the Microsoft end-user
// license agreement (EULA) under which you licensed this SOFTWARE PRODUCT.
// If you did not accept the terms of the EULA, you are not authorized to use
// this source code. For a copy of the EULA, please see the LICENSE.RTF on your
// install media.
//
/*++
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Module Name:  

Abstract:

    Platform dependent Serial definitions for TMS320DM320.
    Ingenient Technologies, Inc.

Notes: 
--*/
#ifndef __DM350_VK3214_H_
#define __DM350_VK3214_H_

#include <s3c2440a_base_regs.h>
#include <s3c2440a_uart.h>

/******************************3214**************************************/
#define VK3214_DEBUG       1
#define BULK_BLOCK_BYTE 64   //for bulk test
/*
#define RX_BUF_SIZE 512
typedef struct tag_RX_FIFO
{
	DWORD read;
	DWORD write;
	DWORD len;
	UINT8 buf[RX_BUF_SIZE];
}UART2_RX_FIFO,*P_UART2_RX_FIFO;
*/

typedef struct _COM_DEVICE_
{
    CRITICAL_SECTION Lock;        
    //CRITICAL_SECTION TXcs; 
    HANDLE           hComPollThread;    
    HANDLE           hComChangedEvent;   
    HANDLE           hRecEvent;
    DWORD           timeout;                
    LONG             OpenCount;           
    DWORD          dwIntrtype;
    DWORD      	dwTXIntrtype;
    DWORD          sysIntr;
    BOOL             DeviceRemoved;
    //BYTE             tempbuf[BULK_BLOCK_BYTE];
    //BYTE             writebuff[BULK_BLOCK_BYTE];
   // DWORD          tx_readindex;
   // DWORD          tx_writeindex;
    //DWORD          tx_length;

    BYTE             readbuff[BULK_BLOCK_BYTE*4]; 
    DWORD          readindex;
    DWORD          writeindex;
    DWORD          length;
    DWORD          tmplength;
    DWORD          m_serial_setup;
    DWORD          m_serial_flag;
    DWORD          m_childport;
    volatile PS3C2440A_UART_REG	v_pVKComReg;               //uart2
 } COM_DEVICE, *PCOM_DEVICE;

#define UART2_PA_BASE_ADDRESS       S3C2440A_BASE_REG_PA_UART2 //(0x50008000) 
#define UART2_INPUT_CLOCK              162000000ul
#define VK3214_DEFAULT_BAUD          19200   //9600
#define UART_TRANS_DATA                  (0x1<<5)  // enable ERR interrupt
#define VK3214_MAIN_BAUD               460800 //230400     //460800 //  460800 




#define MYAssert(psd)     if(NULL == psd) RETAILMSG(1, (L"Error input parameter  \r\n"));  return(FALSE)



/******************************3214*************************************/
//#define VKFREQ18          1                   //VK Fosc =1.8432M
//#define VKFREQ36           1                     //VK Fosc =3.6864M
#define VKFREQ73          1                   //VK Fosc =7.3728M
//#define VKFREQ110         1                  //VK Fosc =11.0592M
//#define VKFREQ147         1                  //VK Fosc =14.7456M
 
 


typedef struct
{
     int baudrate;
     UINT8 setvalue;
}VK3214_Baudset, * PVK3214_Baudset;
#ifdef VKFREQ36
VK3214_Baudset const VKbauddata[16] = { {76800, 0x00}, {38400, 0x01},{19200, 0x02},{9600,   0x03},
                                                            {4800,   0x04}, {2400,   0x05},{1200,   0x06},{600,     0x07},
                                                            {230400,0x08}, {115200, 0x09},{57600, 0x0a},{28800, 0x0b},
                                                            {14400, 0x0c},{7200, 0x0d},{3600, 0x0e},{1800, 0x0f}
                                                           };
#endif
#ifdef VKFREQ18
VK3214_Baudset const VKbauddata[16] = { {38400, 0x00}, {19200, 0x01},{9600, 0x02},{4800,   0x03},
                                                           {2400,   0x04}, {1200,   0x05},{600,   0x06},{300,     0x07},
                                                           {115200,0x08}, {57600, 0x09},{28800, 0x0a},{14400, 0x0b},
                                                           {7200, 0x0c},{3600, 0x0d},{1800, 0x0e},{900, 0x0f}
                                                         };
#endif
#ifdef VKFREQ73
VK3214_Baudset const VKbauddata[16] = { {153600, 0x00}, {76800, 0x01},{38400, 0x02},{19200,   0x03},
                                                           {9600,   0x04}, {4800,   0x05},{2400,   0x06},{1200,     0x07},
                                                           {460800,0x08}, {230400, 0x09},{115200, 0x0a},{57600, 0x0b},
                                                           {28800, 0x0c},{14400, 0x0d},{7200, 0x0e},{3600, 0x0f}
                                                         };
#endif
#ifdef VKFREQ110
VK3214_Baudset const VKbauddata[16] = { {230400, 0x00}, {115200, 0x01},{57600, 0x02},{28800,   0x03},
                                                           {14400,   0x04}, {7200,   0x05},{3600,   0x06},{1800,     0x07},
                                                           {691200,0x08}, {345600, 0x09},{172800, 0x0a},{86400, 0x0b},
                                                           {43200, 0x0c},{21600, 0x0d},{10800, 0x0e},{5400, 0x0f}
                                                         };
#endif
#ifdef VKFREQ147
VK3214_Baudset const VKbauddata[16] = { {307200, 0x00}, {153600, 0x01},{76800, 0x02},{38400,   0x03},
                                                           {19200,   0x04}, {9600,   0x05},{4800,   0x06},{2400,     0x07},
                                                           {921600,0x08}, {460800, 0x09},{230400, 0x0a},{115200, 0x0b},
                                                           {57600, 0x0c},{28800, 0x0d},{14400, 0x0e},{7200, 0x0f}
                                                         };
#endif
//*******************************************************************************************
// uart2
#define UFCON_FIXFTL_1         3       //FIFO triger level     0: 1byte, 1: 8bytes, 2: 16bytes, 3: 32bytes
#define UFCON_FIFO_EN          1       //ʹ��FIFO
#define UFCON_RX_EN             1      //RX FIFO RESET
#define UFCON_TX_EN             1      //TX FIFO RESET
 
#define LCR_WLS_2             3     //word length   0: 5bits,  1:6 bits, 2: 7 bits, 3: 8 bits

#define IER_ERBI                1
#define IER_ELSI                1

#define LSR_RXFIFO_ERR      1
#define LSR_OVER_ERR        1
#define LSR_PARITY_ERR      1
#define LSR_FARM_ERR        1
#define LSR_ERR_CASE    ((LSR_OVER_ERR <<1) | (LSR_PARITY_ERR<<2) | (LSR_FARM_ERR<<3))



//*******************************************************************************************
//ȫ�ֻ�����
#define        GCR_GBDEN                               (1<<7)      //0:��ֹ���ݹ㲥  1: ʹ�����ݹ㲥
#define        GCR_IDEL                                  (1<<6)     //0:��������              1: IDEL ģʽ

#define        GMUCR_PAM_2                           (0<<0)    //00: ǿ��0У��   01: ��У��  //10:żУ��        11: ǿ��1 У�� 
#define        GMUCR_STPL                               (0<<2)    //0: 1 λֹͣλ        1:  2 λֹͣλ
#define        GMUCR_PAEN                              (0<<3)   //0��8 λ���ݣ��޴�У��λ��1��9 λ���ݣ�����9λУ��λ��
#define        GMUCR_BAUD_4                           (3<<4)   //baud rate set


#define        GIR_U1IF                                    (1<<0)     //0:�Ӵ���1 ���ж�             1: �Ӵ���1 ���ж�       
#define        GIR_U2IF                                    (1<<1)     //0:�Ӵ���2 ���ж�             1: �Ӵ���2 ���ж�  
#define        GIR_U3IF                                    (1<<2)     //0:�Ӵ���3 ���ж�             1: �Ӵ���3���ж�  
#define        GIR_U4IF                                    (1<<3)     //0:�Ӵ���4 ���ж�             1: �Ӵ���4 ���ж�  

#define        GIR_U1IEN                                   (1<<4)     //0:��ֹ�Ӵ���1 �ж�       1: ʹ���Ӵ���1 �ж�     
#define        GIR_U2IEN                                   (1<<5)     //0:��ֹ�Ӵ���2�ж�       1: ʹ���Ӵ���2 �ж�  
#define        GIR_U3IEN                                   (1<<6)     //0:��ֹ�Ӵ���3 �ж�       1: ʹ���Ӵ���3 �ж�  
#define        GIR_U4IEN                                   (1<<7)    //0:��ֹ�Ӵ���4 �ж�       1: ʹ���Ӵ���4 �ж�  

//*******************************************************************************************
//�Ӵ��ڼĴ���
#define        SCTLR_IREN                                (1<<0)    //0����׼����ģʽ           1����������ģʽ
#define        SCTLR_RBDEN                             (1<<1)    //0����ֹ�Ӵ��ڽ��չ㲥����           1�������Ӵ��ڽ��չ㲥����
#define        SCTLR_MDSEL                             (1<<2)    //0��RS232�շ�ģʽ    1��RS485�շ�ģʽ
#define        SCTLR_UTEN                               (1<<3)    //0����ʹ��   1��ʹ��
#define        SCTLR_BAUD_4                           (3<<4)  
//------------------------------------------------------
#define        SCONR_AVEN                              (1<<0)   //0����ֹ�����ַ�ɼ��������ַ��д��FIFO  1�����������ַ�ɼ��������ַд��FIFO
#define        SCONR_AREN                              (1<<1)   //0����ֹ�����ַ�Զ�ʶ�� 1�����������ַ�Զ�ʶ��   //
#define        SCONR_AOD                               (1<<2)   //0������������������ֽ� 1��ֻ������յ�ַ�ֽ�
#define        SCONR_PAM0_2                          (1<<3)  // ��SFPAEN=1�Ӵ���ǿ��У��ʹ��ʱ��
                                                                               //00��ǿ��0У�� ��01,10��ǿ���û�У�� �� 11��ǿ��1 У��
                                                                              //��SFPAEN=0���Ӵ�����ͨУ��ģʽʱ��
                                                                              //00��0 У�飻 01����У�飻 10��żУ�飻 11��1У��
#define        SCONR_PAM1_2                          (1<<4) 
#define        SCONR_SFPAEN                          (1<<5)   //0����ʹ���Ӵ���ǿ��У�� 1��ʹ���Ӵ���ǿ��У��
#define        SCONR_SPAEN                            (1<<6)  //0����У��λ��8 λ���ݣ�    1����У��λ��9 λ���ݣ�
#define        SCONR_SSTPL                             (1<<7)  //0��1 λֹͣλ                                  1��2 λֹͣλ
//------------------------------------------------------
#define        SFWCR_XVEN                             (0<<0) //0��XON/XOFF�ַ����ɼ�                         1��XON/XOFF�ַ�д��FIFO���������˿ɼ�XOFF
#define        SFWCR_FWCM                            (0<<2) //0���Ӵ����Զ������������     1������
#define        SFWCR_FWCEN                           (0<<3)//RS232 ģʽ��Ч 0����ֹ�Ӵ����Զ��������� 1�������Ӵ����Զ���������
#define        SFWCR_PRTL_2                           (0<<4)//�������ʹ��������  ��RS232ģʽ����Ч����00=1bytes 01= 4bytes 10=8bytes 11= 12bytes
#define        SFWCR_HRTL_2                           (0<<6)//��ͣ���ʹ�������ƣ�RS232ģʽ����Ч����00=3bytes 01= 7bytes 10=11bytes 11= 15bytes
//------------------------------------------------------
#define        SFOCR_RFCL                               (1<<0) //0�����������FIFO ������  1���������FIFO ����������
#define        SFOCR_TFCL                               (1<<1) //0�������TX FIFO   1���������TX FIFO ����������
#define        SFOCR_RFEN                               (1<<2) //����FIFO ʹ�� :   0����ֹ   1��ʹ��
#define        SFOCR_TFEN                               (1<<3) //����FIFO ʹ��:   0����ֹ   1��ʹ��
#define        SFOCR_RFTL_2                            (1<<4) //����FIFO �������?0=1bytes 01= 4bytes 10=8bytes 11=14bytes?
#define        SFOCR_TFTL_2                            (1<<6) //����FIFO ������ƣ� 00=0bytes 01= 4bytes 10=8bytes 11=12bytes

//------------------------------------------------------
#define        SIER_RFIEN                                 (1<<0)//ʹ�ܽ���FIFO �����ж� 0����ֹ1��ʹ��
#define        SIER_TRIEN                                 (1<<1)//����FIFO �����ж�ʹ�� 0����ֹ1��ʹ��
#define        SIER_XFIEN                                 (1<<4)//XOFF�ж�ʹ��λ:   0����ֹ1��ʹ��
#define        SIER_RAIEN                                 (1<<5)//���յ�ַ�ж�ʹ��λ��0����ֹ1��ʹ��
#define        SIER_FOEIEN                               (1<<6)//FIFO ���ݴ����ж�ʹ��λ�� 0����ֹ1��ʹ��
#define        SIER_RXBY                                  (1<<7)//RX_BUSY ״̬λ0����ͨ��RX ����1����ͨ��RX ���ڽ�������

//------------------------------------------------------
#define     SIFR_RFINT                                      (1<<0)  //�Ӵ��ڽ���FIFO �����жϱ�־λ  0���� 1����
#define     SIFR_TFINT                                      (1<<1)  //�Ӵ��ڷ���FIFO �����жϱ�־λ
#define     SIFR_XFINT                                      (1<<4)  //XOFF�жϱ�־λ
#define     SIFR_RAINT                                      (1<<5)  //�Ӵ����Զ���ַʶ���ж�λ
#define     SIFR_FOEINT                                    (1<<6)  //�Ӵ���FIFO ���ݴ����жϱ�־λ

//------------------------------------------------------
#define     SSR_RFEM                                        (1<<0) //�Ӵ��ڽ���FIFO �ձ�־  0��δ��1����
#define     SSR_OE                                            (1<<7) 
#define     SSR_PE                                              (1<<5) 
#define     SSR_FE                                              (1<<6) 
#define     SSR_TFFL                                              (1<<3) 


/*
#define SIER_RFIEN                   1
#define SIER_TRIEN                   1
#define SIER_FOEIEN                   1
#define SIFR_FOEINT                  1
#define SIFR_RFINT                     1
#define SIFR_TFINT                     1

#define SCTLR_UTEN                    1
 
#define  GIR_U1IF                    1
//*/












//Global Register
#define GCR                  1              //0
#define GMUCR              2           //0X30    4800 BADUARTE
#define GIR                   3                //0X30    enable serial1,serial2 interrupt
#define GXOFF              4           
#define GXON                5
//child serial Reg
#define SCTLR               6
#define SCONR              7
#define SFWCR              8
#define SFOCR               9
#define SADR                10   
#define SIER                 11
#define SIFR                 12
#define SSR                  13  
#define SFSR                14
#define SFDR                15  
                   
                                                          //  F = 3.6864 MHZ      F = 1.8432 MHZ     F = 7.3278 MHZ   F = 11.0592 MHZ          
#define VK_GLOABLE_BAUD      0x3        //   9600 bps                     4800                         9600                      28800
#define VK_SERIAL1_BAUD       0x3        //
#define VK_SERIAL2_BAUD       0x3        //
#define VK_SERIAL3_BAUD       0x3        //
#define VK_SERIAL4_BAUD       0x3        //

/******************************3214*************************************/
//extern HANDLE       g_hUartHandle[4];
extern PCOM_DEVICE  ppGlobalDevice[4];
extern DWORD     g_sysIntr ;
extern  DWORD    dwUseCountUARTC;
extern HANDLE     g_hUartIntEvent;

extern BOOL InitializeUart2port(void);
extern void VK3214GlobalInit(void);
extern void Dump_VKReg(void);
extern void ChildSerial_Init(int childserial);
extern BOOL ForemostInitUart(void);
extern void WriteReg(BYTE childSerial,BYTE regindex,BYTE value);
extern BYTE ReadReg(BYTE childSerial,BYTE regindex);
extern BOOL ChangeMainBaud(int const baudrate,PS3C2440A_UART_REG v_pUart2base);

extern BOOL VK3214_Grab(void);
extern BOOL VK3214_Release(void);
extern void InitPortPinMux(void);
extern PVOID VK3214ComAttach(DWORD dwChildSerial ,PCOM_DEVICE pDevice,DWORD irq)     ;     
//extern BOOL VK3214ComDetach( DWORD dwChildSerial  );
extern BOOL  VK3214ComInit(BYTE dwChildPort,PCOM_DEVICE pDevice);
extern void   VK3214ComIntrPorc(PCOM_DEVICE pDevice);

extern DWORD   ComPollThread( LPVOID Context);
extern  BOOL VK3214ComDetach(PCOM_DEVICE pDevice ); // Context )
extern void VK3214ComSetBaudrate( PCOM_DEVICE pDevice,DWORD BaudRate,BYTE ChildPort);
/*extern void  vk3214_int_set(void);*/
extern VOID VK3214SendData(PCOM_DEVICE pDevice,UCHAR TxData);
extern VOID ReadFIFO(PCOM_DEVICE pDevice, BYTE Length);
extern VOID VK3214SendDataFIFO(PCOM_DEVICE pDevice);
extern DWORD VK3214FIFOCheck(PCOM_DEVICE pDevice);
extern VOID VK3214EnableTXInterrupt(PCOM_DEVICE pDevice); 
extern VOID VK3214DisableTXInterrupt(PCOM_DEVICE pDevice);    
extern BYTE GetVK3214IntStatus(PCOM_DEVICE pDevice);
extern void  vk3214_g_int_dis(void);
extern void  vk3214_g_int_en(void);
extern DWORD   ComUartIntThread(LPVOID Context);
extern void ForemostDeInitUart(void);
extern BOOL Wakeup_VK3214(PS3C2440A_UART_REG v_UartBase);


#endif
