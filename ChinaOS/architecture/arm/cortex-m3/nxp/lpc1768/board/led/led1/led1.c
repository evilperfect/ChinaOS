/******************************************************Copyright (c)**************************************************
**                                              ��������ֹһ�п��ܵĸ���Ե��
**
**                                             E-Mail: ChinaFengliang@163.com
**
**---------File Information-------------------------------------------------------------------------------------------
** File name:            led1.c
** Last version:         V1.00
** Descriptions:         led1ָʾ�������ļ�.
** Hardware platform:    lpc1768֮pin(2.6)
** SoftWare platform:    ChinaOS
**
**--------------------------------------------------------------------------------------------------------------------
** Created by:           Fengliang
** Created date:         2010��10��13��  14:10:22
** Version:              V1.00
** Descriptions:         ռ����Դ: pin 2.6
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
#include    <include/OS_macro.h>
#include    <include/OS_types.h>
#include    <libuary/ioport.h>
#include    "../../../lpc17xx.h"
#include    "./led1.h"

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



/*********************************************************************************************************************
** Function name:           led_1_setup
** Descriptions:            ��װָʾ��
** Input parameters:        none
** Output parameters:       none
** Returned value:          ==OS_OK : �����ɹ�
**                          !=OS_OK : ����ʧ��(����������Ϣ)
**--------------------------------------------------------------------------------------------------------------------
** Created by:              Fengliang
** Created Date:            2010-10-13  14:30:0
** Test recorde:
**--------------------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Test recorde:
*********************************************************************************************************************/
static STATUS led_1_setup(void)
{
	/* led D307 ��������: p2.6 */
	dword_clr_bits(PINSEL4, 3ul<<12);										/* ��������p2.6����: GPIO 				*/
	dword_set_bits(FIO2DIR, 1ul<<6);										/* ��������p2.6����: ���				*/

    return OS_OK;
}

/*********************************************************************************************************************
** Function name:           led_1_on
** Descriptions:            ��ָʾ��
** Input parameters:        none
** Output parameters:       none
** Returned value:          none
**--------------------------------------------------------------------------------------------------------------------
** Created by:              Fengliang
** Created Date:            2010-10-13  14:30:35
** Test recorde:
**--------------------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Test recorde:
*********************************************************************************************************************/
static void led_1_on(void)
{
  	write_dword(FIO2CLR, 1ul << 6);                                    		/* ��ָʾ��                           */
}

/*********************************************************************************************************************
** Function name:           led_1_off
** Descriptions:            �ر�ָʾ��
** Input parameters:        none
** Output parameters:       none
** Returned value:          none
**--------------------------------------------------------------------------------------------------------------------
** Created by:              Fengliang
** Created Date:            2010-10-13  14:30:43
** Test recorde:
**--------------------------------------------------------------------------------------------------------------------
** Modified by:
** Modified date:
** Test recorde:
*********************************************************************************************************************/
static void led_1_off(void)
{
    write_dword(FIO2SET, 1ul << 6);                                     	/* �ر�ָʾ��                           */
}

/*********************************************************************************************************************
                                                    �豸������
*********************************************************************************************************************/
const CLASS_LED led1 =                                                     	/* �豸: ָʾ��                         */
{
    led_1_setup,
    led_1_on,
    led_1_off,
};

/*********************************************************************************************************************
                                                    END OF FILE
*********************************************************************************************************************/
