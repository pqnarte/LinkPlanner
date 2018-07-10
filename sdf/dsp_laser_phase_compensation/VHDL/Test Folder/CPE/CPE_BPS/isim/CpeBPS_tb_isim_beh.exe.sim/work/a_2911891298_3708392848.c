/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/DecisionCircuit4QAM.vhd";



static void work_a_2911891298_3708392848_p_0(char *t0)
{
    unsigned char t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    int t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned char t20;
    unsigned char t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;

LAB0:    xsi_set_current_line(43, ng0);
    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t4 = (2 + 12);
    t5 = (t4 - 1);
    t6 = (t5 - 13);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((unsigned char *)t2);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t4 = (2 + 12);
    t5 = (t4 - 1);
    t6 = (t5 - 13);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((unsigned char *)t2);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 1)
        goto LAB10;

LAB11:    t1 = (unsigned char)0;

LAB12:    if (t1 != 0)
        goto LAB8;

LAB9:    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t4 = (2 + 12);
    t5 = (t4 - 1);
    t6 = (t5 - 13);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((unsigned char *)t2);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 1)
        goto LAB15;

LAB16:    t1 = (unsigned char)0;

LAB17:    if (t1 != 0)
        goto LAB13;

LAB14:    t2 = (t0 + 1512U);
    t3 = *((char **)t2);
    t4 = (2 + 12);
    t5 = (t4 - 1);
    t6 = (t5 - 13);
    t7 = (t6 * -1);
    t8 = (1U * t7);
    t9 = (0 + t8);
    t2 = (t3 + t9);
    t10 = *((unsigned char *)t2);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 1)
        goto LAB20;

LAB21:    t1 = (unsigned char)0;

LAB22:    if (t1 != 0)
        goto LAB18;

LAB19:    xsi_set_current_line(52, ng0);
    t2 = (t0 + 6748);
    t12 = (t0 + 4016);
    t13 = (t12 + 56U);
    t22 = *((char **)t13);
    t23 = (t22 + 56U);
    t24 = *((char **)t23);
    memcpy(t24, t2, 2U);
    xsi_driver_first_trans_fast(t12);

LAB3:    t2 = (t0 + 3920);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(44, ng0);
    t22 = (t0 + 6740);
    t24 = (t0 + 4016);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 2U);
    xsi_driver_first_trans_fast(t24);
    goto LAB3;

LAB5:    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t14 = (2 + 12);
    t15 = (t14 - 1);
    t16 = (t15 - 13);
    t17 = (t16 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((unsigned char *)t12);
    t21 = (t20 == (unsigned char)2);
    t1 = t21;
    goto LAB7;

LAB8:    xsi_set_current_line(46, ng0);
    t22 = (t0 + 6742);
    t24 = (t0 + 4016);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 2U);
    xsi_driver_first_trans_fast(t24);
    goto LAB3;

LAB10:    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t14 = (2 + 12);
    t15 = (t14 - 1);
    t16 = (t15 - 13);
    t17 = (t16 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((unsigned char *)t12);
    t21 = (t20 == (unsigned char)3);
    t1 = t21;
    goto LAB12;

LAB13:    xsi_set_current_line(48, ng0);
    t22 = (t0 + 6744);
    t24 = (t0 + 4016);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 2U);
    xsi_driver_first_trans_fast(t24);
    goto LAB3;

LAB15:    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t14 = (2 + 12);
    t15 = (t14 - 1);
    t16 = (t15 - 13);
    t17 = (t16 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((unsigned char *)t12);
    t21 = (t20 == (unsigned char)3);
    t1 = t21;
    goto LAB17;

LAB18:    xsi_set_current_line(50, ng0);
    t22 = (t0 + 6746);
    t24 = (t0 + 4016);
    t25 = (t24 + 56U);
    t26 = *((char **)t25);
    t27 = (t26 + 56U);
    t28 = *((char **)t27);
    memcpy(t28, t22, 2U);
    xsi_driver_first_trans_fast(t24);
    goto LAB3;

LAB20:    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t14 = (2 + 12);
    t15 = (t14 - 1);
    t16 = (t15 - 13);
    t17 = (t16 * -1);
    t18 = (1U * t17);
    t19 = (0 + t18);
    t12 = (t13 + t19);
    t20 = *((unsigned char *)t12);
    t21 = (t20 == (unsigned char)2);
    t1 = t21;
    goto LAB22;

}

static void work_a_2911891298_3708392848_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(58, ng0);

LAB3:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    t1 = (t0 + 4080);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 3936);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2911891298_3708392848_init()
{
	static char *pe[] = {(void *)work_a_2911891298_3708392848_p_0,(void *)work_a_2911891298_3708392848_p_1};
	xsi_register_didat("work_a_2911891298_3708392848", "isim/CpeBPS_tb_isim_beh.exe.sim/work/a_2911891298_3708392848.didat");
	xsi_register_executes(pe);
}
