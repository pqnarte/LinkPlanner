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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Average_Ncylce.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3972351953;
extern char *IEEE_P_0774719531;

char *ieee_p_0774719531_sub_767668596_2162500114(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
double ieee_p_3972351953_sub_1147618771_2984157535(char *, double );
double ieee_p_3972351953_sub_528838134_2984157535(char *, double );


static void work_a_3336222013_3212880686_p_0(char *t0)
{
    char t43[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    int t11;
    int t12;
    int t13;
    int t14;
    int t15;
    int t16;
    unsigned int t17;
    int t18;
    int t19;
    unsigned int t20;
    unsigned int t21;
    char *t22;
    char *t23;
    int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    int t29;
    int t30;
    int t31;
    int t32;
    char *t33;
    int t34;
    int t35;
    int t36;
    unsigned int t37;
    unsigned int t38;
    double t39;
    double t40;
    double t41;
    double t42;
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

LAB0:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3592);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(33, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(34, ng0);
    t3 = xsi_get_transient_memory(18U);
    memset(t3, 0, 18U);
    t7 = t3;
    memset(t7, (unsigned char)2, 18U);
    t8 = (t0 + 2168U);
    t9 = *((char **)t8);
    t8 = (t9 + 0);
    memcpy(t8, t3, 18U);
    xsi_set_current_line(35, ng0);
    t10 = (3 - 1);
    t1 = (t0 + 6178);
    *((int *)t1) = 0;
    t3 = (t0 + 6182);
    *((int *)t3) = t10;
    t11 = 0;
    t12 = t10;

LAB8:    if (t11 <= t12)
        goto LAB9;

LAB11:    xsi_set_current_line(42, ng0);
    t1 = (t0 + 2168U);
    t3 = *((char **)t1);
    t10 = (16 - 1);
    t39 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 3.0000000000000000);
    t40 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t39);
    t2 = (t40 >= 0);
    if (t2 == 1)
        goto LAB23;

LAB24:    t42 = (t40 - 0.50000000000000000);
    t11 = ((int)(t42));

LAB25:    t12 = (t10 + t11);
    t13 = (t12 - 2);
    t17 = (17 - t13);
    t44 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 3.0000000000000000);
    t45 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t44);
    t6 = (t45 >= 0);
    if (t6 == 1)
        goto LAB28;

LAB29:    t48 = (t45 - 0.50000000000000000);
    t14 = ((int)(t48));

LAB30:    t15 = (t14 - 2);
    xsi_vhdl_check_range_of_slice(17, 0, -1, t13, t15, -1);
    t20 = (t17 * 1U);
    t21 = (0 + t20);
    t1 = (t3 + t21);
    t16 = (16 - 1);
    t49 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 3.0000000000000000);
    t50 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t49);
    t51 = (t50 >= 0);
    if (t51 == 1)
        goto LAB33;

LAB34:    t54 = (t50 - 0.50000000000000000);
    t18 = ((int)(t54));

LAB35:    t19 = (t16 + t18);
    t24 = (t19 - 2);
    t55 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 3.0000000000000000);
    t56 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t55);
    t57 = (t56 >= 0);
    if (t57 == 1)
        goto LAB38;

LAB39:    t60 = (t56 - 0.50000000000000000);
    t29 = ((int)(t60));

LAB40:    t30 = (t29 - 2);
    t31 = (t30 - t24);
    t25 = (t31 * -1);
    t25 = (t25 + 1);
    t26 = (1U * t25);
    t61 = (16U != t26);
    if (t61 == 1)
        goto LAB43;

LAB44:    t4 = (t0 + 3672);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t22 = *((char **)t9);
    memcpy(t22, t1, 16U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB6;

LAB9:    xsi_set_current_line(36, ng0);
    t4 = (t0 + 1352U);
    t7 = *((char **)t4);
    t4 = (t0 + 6178);
    t13 = *((int *)t4);
    t14 = (t13 + 1);
    t15 = (t14 * 16);
    t16 = (t15 - 1);
    t17 = (47 - t16);
    t8 = (t0 + 6178);
    t18 = *((int *)t8);
    t19 = (t18 * 16);
    xsi_vhdl_check_range_of_slice(47, 0, -1, t16, t19, -1);
    t20 = (t17 * 1U);
    t21 = (0 + t20);
    t9 = (t7 + t21);
    t22 = (t0 + 2288U);
    t23 = *((char **)t22);
    t24 = (16 - 1);
    t25 = (17 - t24);
    t26 = (t25 * 1U);
    t27 = (0 + t26);
    t22 = (t23 + t27);
    t28 = (t0 + 6178);
    t29 = *((int *)t28);
    t30 = (t29 + 1);
    t31 = (t30 * 16);
    t32 = (t31 - 1);
    t33 = (t0 + 6178);
    t34 = *((int *)t33);
    t35 = (t34 * 16);
    t36 = (t35 - t32);
    t37 = (t36 * -1);
    t37 = (t37 + 1);
    t38 = (1U * t37);
    memcpy(t22, t9, t38);
    xsi_set_current_line(37, ng0);
    t39 = ieee_p_3972351953_sub_528838134_2984157535(IEEE_P_3972351953, 3.0000000000000000);
    t40 = ieee_p_3972351953_sub_1147618771_2984157535(IEEE_P_3972351953, t39);
    t2 = (t40 >= 0);
    if (t2 == 1)
        goto LAB16;

LAB17:    t42 = (t40 - 0.50000000000000000);
    t10 = ((int)(t42));

LAB18:    t13 = (16 + t10);
    t14 = (t13 - 1);
    t1 = (t0 + 6186);
    *((int *)t1) = 16;
    t3 = (t0 + 6190);
    *((int *)t3) = t14;
    t15 = 16;
    t16 = t14;

LAB12:    if (t15 <= t16)
        goto LAB13;

LAB15:    xsi_set_current_line(40, ng0);
    t1 = (t0 + 2168U);
    t3 = *((char **)t1);
    t1 = (t0 + 6056U);
    t4 = (t0 + 2288U);
    t7 = *((char **)t4);
    t4 = (t0 + 6056U);
    t8 = ieee_p_0774719531_sub_767668596_2162500114(IEEE_P_0774719531, t43, t3, t1, t7, t4);
    t9 = (t0 + 2168U);
    t22 = *((char **)t9);
    t9 = (t22 + 0);
    t23 = (t43 + 12U);
    t17 = *((unsigned int *)t23);
    t20 = (1U * t17);
    memcpy(t9, t8, t20);

LAB10:    t1 = (t0 + 6178);
    t11 = *((int *)t1);
    t3 = (t0 + 6182);
    t12 = *((int *)t3);
    if (t11 == t12)
        goto LAB11;

LAB22:    t10 = (t11 + 1);
    t11 = t10;
    t4 = (t0 + 6178);
    *((int *)t4) = t11;
    goto LAB8;

LAB13:    xsi_set_current_line(38, ng0);
    t4 = (t0 + 1352U);
    t7 = *((char **)t4);
    t4 = (t0 + 6178);
    t18 = *((int *)t4);
    t19 = (t18 + 1);
    t24 = (t19 * 16);
    t29 = (t24 - 1);
    t30 = (t29 - 47);
    t17 = (t30 * -1);
    xsi_vhdl_check_range_of_index(47, 0, -1, t29);
    t20 = (1U * t17);
    t21 = (0 + t20);
    t8 = (t7 + t21);
    t6 = *((unsigned char *)t8);
    t9 = (t0 + 2288U);
    t22 = *((char **)t9);
    t9 = (t0 + 6186);
    t31 = *((int *)t9);
    t32 = (t31 - 17);
    t25 = (t32 * -1);
    xsi_vhdl_check_range_of_index(17, 0, -1, *((int *)t9));
    t26 = (1U * t25);
    t27 = (0 + t26);
    t23 = (t22 + t27);
    *((unsigned char *)t23) = t6;

LAB14:    t1 = (t0 + 6186);
    t15 = *((int *)t1);
    t3 = (t0 + 6190);
    t16 = *((int *)t3);
    if (t15 == t16)
        goto LAB15;

LAB21:    t10 = (t15 + 1);
    t15 = t10;
    t4 = (t0 + 6186);
    *((int *)t4) = t15;
    goto LAB12;

LAB16:    t5 = (t40 >= 2147483647);
    if (t5 == 1)
        goto LAB19;

LAB20:    t41 = (t40 + 0.50000000000000000);
    t10 = ((int)(t41));
    goto LAB18;

LAB19:    t10 = 2147483647;
    goto LAB18;

LAB23:    t5 = (t40 >= 2147483647);
    if (t5 == 1)
        goto LAB26;

LAB27:    t41 = (t40 + 0.50000000000000000);
    t11 = ((int)(t41));
    goto LAB25;

LAB26:    t11 = 2147483647;
    goto LAB25;

LAB28:    t46 = (t45 >= 2147483647);
    if (t46 == 1)
        goto LAB31;

LAB32:    t47 = (t45 + 0.50000000000000000);
    t14 = ((int)(t47));
    goto LAB30;

LAB31:    t14 = 2147483647;
    goto LAB30;

LAB33:    t52 = (t50 >= 2147483647);
    if (t52 == 1)
        goto LAB36;

LAB37:    t53 = (t50 + 0.50000000000000000);
    t18 = ((int)(t53));
    goto LAB35;

LAB36:    t18 = 2147483647;
    goto LAB35;

LAB38:    t58 = (t56 >= 2147483647);
    if (t58 == 1)
        goto LAB41;

LAB42:    t59 = (t56 + 0.50000000000000000);
    t29 = ((int)(t59));
    goto LAB40;

LAB41:    t29 = 2147483647;
    goto LAB40;

LAB43:    xsi_size_not_matching(16U, t26, 0);
    goto LAB44;

}


extern void work_a_3336222013_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3336222013_3212880686_p_0};
	xsi_register_didat("work_a_3336222013_3212880686", "isim/AverageN_IT_tb_isim_beh.exe.sim/work/a_3336222013_3212880686.didat");
	xsi_register_executes(pe);
}
