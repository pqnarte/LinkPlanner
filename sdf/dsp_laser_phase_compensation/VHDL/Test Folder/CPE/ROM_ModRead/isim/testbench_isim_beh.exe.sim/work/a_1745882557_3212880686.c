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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/ArrayN2ArrayM.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1745882557_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    int t7;
    char *t8;
    int t9;
    int t10;
    int t11;
    char *t12;
    char *t13;
    int t14;
    int t15;
    char *t16;
    char *t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    char *t24;
    char *t25;
    int t26;
    int t27;
    int t28;
    int t29;
    int t30;
    int t31;
    unsigned int t32;
    int t33;
    int t34;
    unsigned int t35;
    unsigned int t36;
    int t37;
    int t38;
    int t39;
    int t40;
    int t41;
    int t42;
    int t43;
    unsigned int t44;
    unsigned int t45;

LAB0:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1312U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3872);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(35, ng0);
    t7 = (2 - 1);
    t3 = (t0 + 6571);
    *((int *)t3) = 0;
    t8 = (t0 + 6575);
    *((int *)t8) = t7;
    t9 = 0;
    t10 = t7;

LAB8:    if (t9 <= t10)
        goto LAB9;

LAB11:    goto LAB6;

LAB9:    xsi_set_current_line(36, ng0);
    t11 = (4 - 1);
    t12 = (t0 + 6579);
    *((int *)t12) = 0;
    t13 = (t0 + 6583);
    *((int *)t13) = t11;
    t14 = 0;
    t15 = t11;

LAB12:    if (t14 <= t15)
        goto LAB13;

LAB15:    xsi_set_current_line(40, ng0);
    t1 = (t0 + 2568U);
    t3 = *((char **)t1);
    t1 = (t0 + 6571);
    t7 = *((int *)t1);
    t11 = (t7 - 1);
    t20 = (t11 * -1);
    t21 = (8U * t20);
    t22 = (0U + t21);
    t4 = (t0 + 3952);
    t8 = (t4 + 56U);
    t12 = *((char **)t8);
    t13 = (t12 + 56U);
    t16 = *((char **)t13);
    memcpy(t16, t3, 8U);
    xsi_driver_first_trans_delta(t4, t22, 8U, 0LL);

LAB10:    t1 = (t0 + 6571);
    t9 = *((int *)t1);
    t3 = (t0 + 6575);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB11;

LAB17:    t7 = (t9 + 1);
    t9 = t7;
    t4 = (t0 + 6571);
    *((int *)t4) = t9;
    goto LAB8;

LAB13:    xsi_set_current_line(37, ng0);
    t16 = (t0 + 1032U);
    t17 = *((char **)t16);
    t16 = (t0 + 6579);
    t18 = *((int *)t16);
    t19 = (t18 - 3);
    t20 = (t19 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, *((int *)t16));
    t21 = (4U * t20);
    t22 = (0 + t21);
    t23 = (t17 + t22);
    t24 = (t0 + 2448U);
    t25 = *((char **)t24);
    t24 = (t25 + 0);
    memcpy(t24, t23, 4U);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 2448U);
    t3 = *((char **)t1);
    t1 = (t0 + 6571);
    t7 = *((int *)t1);
    t11 = (t7 + 1);
    t18 = (t11 * 2);
    t19 = (t18 - 1);
    t20 = (3 - t19);
    t4 = (t0 + 6571);
    t26 = *((int *)t4);
    t27 = (t26 * 2);
    xsi_vhdl_check_range_of_slice(3, 0, -1, t19, t27, -1);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t8 = (t3 + t22);
    t12 = (t0 + 2568U);
    t13 = *((char **)t12);
    t12 = (t0 + 6579);
    t28 = *((int *)t12);
    t29 = (t28 + 1);
    t30 = (t29 * 2);
    t31 = (t30 - 1);
    t32 = (7 - t31);
    t16 = (t0 + 6579);
    t33 = *((int *)t16);
    t34 = (t33 * 2);
    xsi_vhdl_check_range_of_slice(7, 0, -1, t31, t34, -1);
    t35 = (t32 * 1U);
    t36 = (0 + t35);
    t17 = (t13 + t36);
    t23 = (t0 + 6571);
    t37 = *((int *)t23);
    t38 = (t37 + 1);
    t39 = (t38 * 2);
    t40 = (t39 - 1);
    t24 = (t0 + 6571);
    t41 = *((int *)t24);
    t42 = (t41 * 2);
    t43 = (t42 - t40);
    t44 = (t43 * -1);
    t44 = (t44 + 1);
    t45 = (1U * t44);
    memcpy(t17, t8, t45);

LAB14:    t1 = (t0 + 6579);
    t14 = *((int *)t1);
    t3 = (t0 + 6583);
    t15 = *((int *)t3);
    if (t14 == t15)
        goto LAB15;

LAB16:    t7 = (t14 + 1);
    t14 = t7;
    t4 = (t0 + 6579);
    *((int *)t4) = t14;
    goto LAB12;

}


extern void work_a_1745882557_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1745882557_3212880686_p_0};
	xsi_register_didat("work_a_1745882557_3212880686", "isim/testbench_isim_beh.exe.sim/work/a_1745882557_3212880686.didat");
	xsi_register_executes(pe);
}