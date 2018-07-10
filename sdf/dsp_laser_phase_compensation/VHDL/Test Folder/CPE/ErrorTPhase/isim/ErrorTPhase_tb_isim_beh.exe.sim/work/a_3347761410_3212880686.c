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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Average_IT.vhd";
extern char *IEEE_P_3972351953;
extern char *IEEE_P_0774719531;

char *ieee_p_0774719531_sub_767668596_2162500114(char *, char *, char *, char *, char *, char *);
double ieee_p_3972351953_sub_1147618771_2984157535(char *, double );
double ieee_p_3972351953_sub_528838134_2984157535(char *, double );


static void work_a_3347761410_3212880686_p_0(char *t0)
{
    char t43[16];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;
    int t11;
    unsigned int t12;
    char *t13;
    int t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    char *t25;
    int t26;
    int t27;
    int t28;
    int t29;
    char *t30;
    int t31;
    int t32;
    int t33;
    unsigned int t34;
    unsigned int t35;
    double t36;
    double t37;
    unsigned char t38;
    unsigned char t39;
    double t40;
    double t41;
    unsigned char t42;
    double t44;
    double t45;
    unsigned char t46;
    double t47;
    double t48;
    double t49;
    double t50;
    unsigned char t51;
    unsigned char t52;
    double t53;
    double t54;
    double t55;
    double t56;
    unsigned char t57;
    unsigned char t58;
    double t59;
    double t60;
    unsigned char t61;

LAB0:    xsi_set_current_line(31, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t3 = (t0 + 1848U);
    t4 = *((char **)t3);
    t3 = (t4 + 0);
    memcpy(t3, t1, 16U);
    xsi_set_current_line(32, ng0);
    t5 = (1 - 1);
    t1 = (t0 + 5596);
    *((int *)t1) = 0;
    t2 = (t0 + 5600);
    *((int *)t2) = t5;
    t6 = 0;
    t7 = t5;

LAB2:    if (t6 <= t7)
        goto LAB3;

LAB5:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 1848U);
    t2 = *((char **)t1);
    t5 = (16 - 1);
    t36 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 1.0000000000000000);
    t37 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t36);
    t38 = (t37 >= 0);
    if (t38 == 1)
        goto LAB17;

LAB18:    t41 = (t37 - 0.50000000000000000);
    t6 = ((int)(t41));

LAB19:    t7 = (t5 + t6);
    t8 = (t7 - 0);
    t12 = (15 - t8);
    t44 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 1.0000000000000000);
    t45 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t44);
    t42 = (t45 >= 0);
    if (t42 == 1)
        goto LAB22;

LAB23:    t48 = (t45 - 0.50000000000000000);
    t9 = ((int)(t48));

LAB24:    t10 = (t9 - 0);
    xsi_vhdl_check_range_of_slice(15, 0, -1, t8, t10, -1);
    t16 = (t12 * 1U);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t11 = (16 - 1);
    t49 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 1.0000000000000000);
    t50 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t49);
    t51 = (t50 >= 0);
    if (t51 == 1)
        goto LAB27;

LAB28:    t54 = (t50 - 0.50000000000000000);
    t14 = ((int)(t54));

LAB29:    t15 = (t11 + t14);
    t21 = (t15 - 0);
    t55 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 1.0000000000000000);
    t56 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t55);
    t57 = (t56 >= 0);
    if (t57 == 1)
        goto LAB32;

LAB33:    t60 = (t56 - 0.50000000000000000);
    t26 = ((int)(t60));

LAB34:    t27 = (t26 - 0);
    t28 = (t27 - t21);
    t22 = (t28 * -1);
    t22 = (t22 + 1);
    t23 = (1U * t22);
    t61 = (16U != t23);
    if (t61 == 1)
        goto LAB37;

LAB38:    t3 = (t0 + 3352);
    t4 = (t3 + 56U);
    t13 = *((char **)t4);
    t18 = (t13 + 56U);
    t19 = *((char **)t18);
    memcpy(t19, t1, 16U);
    xsi_driver_first_trans_fast_port(t3);
    t1 = (t0 + 3272);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(33, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t3 = (t0 + 5596);
    t8 = *((int *)t3);
    t9 = (t8 + 1);
    t10 = (t9 * 16);
    t11 = (t10 - 1);
    t12 = (15 - t11);
    t13 = (t0 + 5596);
    t14 = *((int *)t13);
    t15 = (t14 * 16);
    xsi_vhdl_check_range_of_slice(15, 0, -1, t11, t15, -1);
    t16 = (t12 * 1U);
    t17 = (0 + t16);
    t18 = (t4 + t17);
    t19 = (t0 + 1968U);
    t20 = *((char **)t19);
    t21 = (16 - 1);
    t22 = (15 - t21);
    t23 = (t22 * 1U);
    t24 = (0 + t23);
    t19 = (t20 + t24);
    t25 = (t0 + 5596);
    t26 = *((int *)t25);
    t27 = (t26 + 1);
    t28 = (t27 * 16);
    t29 = (t28 - 1);
    t30 = (t0 + 5596);
    t31 = *((int *)t30);
    t32 = (t31 * 16);
    t33 = (t32 - t29);
    t34 = (t33 * -1);
    t34 = (t34 + 1);
    t35 = (1U * t34);
    memcpy(t19, t18, t35);
    xsi_set_current_line(34, ng0);
    t36 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 1.0000000000000000);
    t37 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t36);
    t38 = (t37 >= 0);
    if (t38 == 1)
        goto LAB10;

LAB11:    t41 = (t37 - 0.50000000000000000);
    t5 = ((int)(t41));

LAB12:    t8 = (16 + t5);
    t9 = (t8 - 1);
    t1 = (t0 + 5604);
    *((int *)t1) = 16;
    t2 = (t0 + 5608);
    *((int *)t2) = t9;
    t10 = 16;
    t11 = t9;

LAB6:    if (t10 <= t11)
        goto LAB7;

LAB9:    xsi_set_current_line(37, ng0);
    t1 = (t0 + 1848U);
    t2 = *((char **)t1);
    t1 = (t0 + 5512U);
    t3 = (t0 + 1968U);
    t4 = *((char **)t3);
    t3 = (t0 + 5512U);
    t13 = ieee_p_0774719531_sub_767668596_2162500114(IEEE_P_0774719531, t43, t2, t1, t4, t3);
    t18 = (t0 + 1848U);
    t19 = *((char **)t18);
    t18 = (t19 + 0);
    t20 = (t43 + 12U);
    t12 = *((unsigned int *)t20);
    t16 = (1U * t12);
    memcpy(t18, t13, t16);

LAB4:    t1 = (t0 + 5596);
    t6 = *((int *)t1);
    t2 = (t0 + 5600);
    t7 = *((int *)t2);
    if (t6 == t7)
        goto LAB5;

LAB16:    t5 = (t6 + 1);
    t6 = t5;
    t3 = (t0 + 5596);
    *((int *)t3) = t6;
    goto LAB2;

LAB7:    xsi_set_current_line(35, ng0);
    t3 = (t0 + 1032U);
    t4 = *((char **)t3);
    t3 = (t0 + 5596);
    t14 = *((int *)t3);
    t15 = (t14 + 1);
    t21 = (t15 * 16);
    t26 = (t21 - 1);
    t27 = (t26 - 15);
    t12 = (t27 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, t26);
    t16 = (1U * t12);
    t17 = (0 + t16);
    t13 = (t4 + t17);
    t42 = *((unsigned char *)t13);
    t18 = (t0 + 1968U);
    t19 = *((char **)t18);
    t18 = (t0 + 5604);
    t28 = *((int *)t18);
    t29 = (t28 - 15);
    t22 = (t29 * -1);
    xsi_vhdl_check_range_of_index(15, 0, -1, *((int *)t18));
    t23 = (1U * t22);
    t24 = (0 + t23);
    t20 = (t19 + t24);
    *((unsigned char *)t20) = t42;

LAB8:    t1 = (t0 + 5604);
    t10 = *((int *)t1);
    t2 = (t0 + 5608);
    t11 = *((int *)t2);
    if (t10 == t11)
        goto LAB9;

LAB15:    t5 = (t10 + 1);
    t10 = t5;
    t3 = (t0 + 5604);
    *((int *)t3) = t10;
    goto LAB6;

LAB10:    t39 = (t37 >= 2147483647);
    if (t39 == 1)
        goto LAB13;

LAB14:    t40 = (t37 + 0.50000000000000000);
    t5 = ((int)(t40));
    goto LAB12;

LAB13:    t5 = 2147483647;
    goto LAB12;

LAB17:    t39 = (t37 >= 2147483647);
    if (t39 == 1)
        goto LAB20;

LAB21:    t40 = (t37 + 0.50000000000000000);
    t6 = ((int)(t40));
    goto LAB19;

LAB20:    t6 = 2147483647;
    goto LAB19;

LAB22:    t46 = (t45 >= 2147483647);
    if (t46 == 1)
        goto LAB25;

LAB26:    t47 = (t45 + 0.50000000000000000);
    t9 = ((int)(t47));
    goto LAB24;

LAB25:    t9 = 2147483647;
    goto LAB24;

LAB27:    t52 = (t50 >= 2147483647);
    if (t52 == 1)
        goto LAB30;

LAB31:    t53 = (t50 + 0.50000000000000000);
    t14 = ((int)(t53));
    goto LAB29;

LAB30:    t14 = 2147483647;
    goto LAB29;

LAB32:    t58 = (t56 >= 2147483647);
    if (t58 == 1)
        goto LAB35;

LAB36:    t59 = (t56 + 0.50000000000000000);
    t26 = ((int)(t59));
    goto LAB34;

LAB35:    t26 = 2147483647;
    goto LAB34;

LAB37:    xsi_size_not_matching(16U, t23, 0);
    goto LAB38;

}


extern void work_a_3347761410_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3347761410_3212880686_p_0};
	xsi_register_didat("work_a_3347761410_3212880686", "isim/ErrorTPhase_tb_isim_beh.exe.sim/work/a_3347761410_3212880686.didat");
	xsi_register_executes(pe);
}
