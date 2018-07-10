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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Basic Functions/SubtractorN_Signed.vhd";
extern char *IEEE_P_0774719531;
extern char *IEEE_P_2592010699;

char *ieee_p_0774719531_sub_767740470_2162500114(char *, char *, char *, char *, char *, char *);


static void work_a_2351964920_3212880686_p_0(char *t0)
{
    char t1[16];
    char t12[16];
    char t25[16];
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;
    int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned char t22;
    char *t23;
    char *t24;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    unsigned int t30;
    unsigned int t31;
    unsigned char t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;

LAB0:    xsi_set_current_line(49, ng0);

LAB3:    t2 = (t0 + 1296U);
    t3 = *((char **)t2);
    t4 = (8 - 1);
    t5 = (t4 - 7);
    t6 = (t5 * -1);
    t7 = (1U * t6);
    t8 = (0 + t7);
    t2 = (t3 + t8);
    t9 = *((unsigned char *)t2);
    t10 = (t0 + 1296U);
    t11 = *((char **)t10);
    t13 = ((IEEE_P_2592010699) + 4024);
    t14 = (t0 + 6880U);
    t10 = xsi_base_array_concat(t10, t12, t13, (char)99, t9, (char)97, t11, t14, (char)101);
    t15 = (t0 + 1456U);
    t16 = *((char **)t15);
    t17 = (8 - 1);
    t18 = (t17 - 7);
    t19 = (t18 * -1);
    t20 = (1U * t19);
    t21 = (0 + t20);
    t15 = (t16 + t21);
    t22 = *((unsigned char *)t15);
    t23 = (t0 + 1456U);
    t24 = *((char **)t23);
    t26 = ((IEEE_P_2592010699) + 4024);
    t27 = (t0 + 6896U);
    t23 = xsi_base_array_concat(t23, t25, t26, (char)99, t22, (char)97, t24, t27, (char)101);
    t28 = ieee_p_0774719531_sub_767740470_2162500114(IEEE_P_0774719531, t1, t10, t12, t23, t25);
    t29 = (t1 + 12U);
    t30 = *((unsigned int *)t29);
    t31 = (1U * t30);
    t32 = (9U != t31);
    if (t32 == 1)
        goto LAB5;

LAB6:    t33 = (t0 + 4264);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    t36 = (t35 + 56U);
    t37 = *((char **)t36);
    memcpy(t37, t28, 9U);
    xsi_driver_first_trans_fast(t33);

LAB2:    t38 = (t0 + 4152);
    *((int *)t38) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(9U, t31, 0);
    goto LAB6;

}

static void work_a_2351964920_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;

LAB0:    xsi_set_current_line(62, ng0);

LAB3:    t1 = (t0 + 1776U);
    t2 = *((char **)t1);
    t3 = (9 - 1);
    t4 = (8 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 4328);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 9U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 4168);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_2351964920_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(91, ng0);

LAB3:    t1 = (t0 + 1936U);
    t2 = *((char **)t1);
    t1 = (t0 + 4392);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 9U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 4184);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2351964920_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2351964920_3212880686_p_0,(void *)work_a_2351964920_3212880686_p_1,(void *)work_a_2351964920_3212880686_p_2};
	xsi_register_didat("work_a_2351964920_3212880686", "isim/ErrorTPhase_isim_beh.exe.sim/work/a_2351964920_3212880686.didat");
	xsi_register_executes(pe);
}
