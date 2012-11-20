/******************************************************Copyright (c)**************************************************
**                                              ��������ֹһ�п��ܵĸ���Ե��
**
**                                             E-Mail: ChinaFengliang@163.com
**
**---------File Information-------------------------------------------------------------------------------------------
** File name:            main.c
** Last version:         V1.00
** Descriptions:         Ӧ���ļ�.
** Hardware platform:    can_repeater
** SoftWare platform:    ChinaOS
**
**--------------------------------------------------------------------------------------------------------------------
** Created by:           Feng Liang
** Created date:         2011��12��13��  17:10:22
** Version:              V1.00
** Descriptions:         The original version
**
**--------------------------------------------------------------------------------------------------------------------
** Modified by: 
** Modified date:
** Version:
** Descriptions:
**
*********************************************************************************************************************/

/*********************************************************************************************************************
                                                    ͷ�ļ���
*********************************************************************************************************************/
#include    <ChinaOS.h>
#include    "./thread_1/thread_1.h"
#include    "./thread_2/thread_2.h"

/*********************************************************************************************************************
                                                    �궨����
*********************************************************************************************************************/
/* ����� ----------------------------------------------------------------------------------------------------------*/


/*********************************************************************************************************************
                                                    ���Ͷ�����
*********************************************************************************************************************/
/* �������� --------------------------------------------------------------------------------------------------------*/


/*********************************************************************************************************************
                                                  ȫ�ֱ���������
*********************************************************************************************************************/
/* ϵͳ�������� ----------------------------------------------------------------------------------------------------*/
static const char Welcome[] = "\
\t\t\t\t++++++++++++++++++++++++++++++++++\r\n\
\t\t\t\t ++++++++++++++++++++++++++++++++++\r\n\
\t\t\t\t  ++++++++++++++++++++++++++++++++++\r\n\
\t\t\t\t                                 +++\r\n\
\t\t\t\t    +++++++++++++++++++++++++++  +++\r\n\
\t\t\t\t    +++++++++++++++++++++++++++  +++\r\n\
\t\t\t\t    +++                          +++\r\n\
\t\t\t\t    +++          ++++++++++++++++++\r\n\
\t\t\t\t    +++          +++++++++++++++++\r\n\
\t\t\t\t    +++          ++++++++++++++++\r\n\
\t\t\t\t    +++\r\n\
\t\t\t\t    ++++++++++++++++++++++++++++++++++\r\n\
\t\t\t\t    +++++++++++++++++++++++++++++++++++\r\n\
\t\t\t\t    ++++++++++++++++++++++++++++++++++++\r\n\
\r\n\
\t\t\t\t      ��������ֹһ�п��ܵĸ���Ե��!\r\n";

/*********************************************************************************************************************
** Function name:           welcome
** Descriptions:            ��ʾ��������
** Input parameters:
** Output parameters:
** Returned value:          ==OK : �����ɹ�
**                          !=OK : ����ʧ��(����������Ϣ)
**--------------------------------------------------------------------------------------------------------------------
** Created by:              Fengliang
** Created Date:            2010-9-6  11:25:7
** Test recorde:            
**--------------------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Test recorde:
*********************************************************************************************************************/
static int welcome(void)
{
    printc(12);                                                             /* ����                                 */
    prints(Welcome);                                                        /* ��ʾ��ӭ��Ϣ                         */

    return OK;
}

/*********************************************************************************************************************
** Function name:           main
** Descriptions:            ���߳�
** Input parameters:        pOption : �̲߳���
** Output parameters:       
** Returned value:          ==OK : �����ɹ�
**                          !=OK : ����ʧ��(����������Ϣ)
**--------------------------------------------------------------------------------------------------------------------
** Created by:              Fengliang
** Created Date:            2011-6-17  11:32:22
** Test recorde:            
**--------------------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Test recorde: 
*********************************************************************************************************************/
int main(void *pOption)
{
    welcome();                                                              /* ��ʾ��������                         */

    labour("thread_1", thread_1, NULL, 1000, 8);                            /* �����߳�1                            */
    labour("thread_2", thread_2, NULL, 1000, 9);                            /* �����߳�2                            */

    while (1)
    {
        led2.on();
        sleep(500);
        led2.off();
        sleep(500);
    }
}

/*********************************************************************************************************************
                                                    END OF FILE
*********************************************************************************************************************/
