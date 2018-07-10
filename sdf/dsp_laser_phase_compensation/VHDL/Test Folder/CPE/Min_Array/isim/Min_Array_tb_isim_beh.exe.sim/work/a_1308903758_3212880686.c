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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Min_Array.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_0774719531;
extern char *IEEE_P_1242562249;

unsigned char ieee_p_0774719531_sub_2698860368_2162500114(char *, char *, char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1308903758_3212880686_p_0(char *t0)
{
    char t37[16];
    char *t1;
    char *t2;
    int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int t6;
    char *t7;
    char *t8;
    unsigned char t9;
    unsigned char t10;
    unsigned char t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    int t17;
    int t18;
    int t19;
    int t20;
    int t21;
    int t22;
    int t23;
    int t24;
    int t25;
    int t26;
    int t27;
    int t28;
    char *t29;
    int t30;
    int t31;
    int t32;
    unsigned int t33;
    unsigned int t34;
    char *t35;
    char *t36;

LAB0:    xsi_set_current_line(31, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t3 = (16 - 1);
    t4 = (31 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 2328U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 16U);
    xsi_set_current_line(33, ng0);
    t1 = (t0 + 992U);
    t9 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t9 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4000);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(34, ng0);
    t2 = (t0 + 1192U);
    t7 = *((char **)t2);
    t10 = *((unsigned char *)t7);
    t11 = (t10 == (unsigned char)3);
    if (t11 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(35, ng0);
    t2 = xsi_get_transient_memory(1U);
    memset(t2, 0, 1U);
    t8 = t2;
    memset(t8, (unsigned char)2, 1U);
    t12 = (t0 + 4096);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 1U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(36, ng0);
    t3 = (2 - 1);
    t1 = (t0 + 6787);
    *((int *)t1) = 1;
    t2 = (t0 + 6791);
    *((int *)t2) = t3;
    t17 = 1;
    t18 = t3;

LAB8:    if (t17 <= t18)
        goto LAB9;

LAB11:    xsi_set_current_line(45, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t7 = (t0 + 2328U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 16U);
    xsi_set_current_line(47, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t2 = t1;
    memset(t2, (unsigned char)2, 16U);
    t7 = (t0 + 2448U);
    t8 = *((char **)t7);
    t7 = (t8 + 0);
    memcpy(t7, t1, 16U);
    goto LAB6;

LAB9:    xsi_set_current_line(37, ng0);
    t7 = (t0 + 1352U);
    t8 = *((char **)t7);
    t7 = (t0 + 6787);
    t19 = *((int *)t7);
    t20 = (t19 + 1);
    t21 = (t20 * 16);
    t22 = (t21 - 1);
    t4 = (31 - t22);
    t12 = (t0 + 6787);
    t23 = *((int *)t12);
    t24 = (t23 * 16);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t22, t24, -1);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t13 = (t8 + t6);
    t14 = (t0 + 2448U);
    t15 = *((char **)t14);
    t14 = (t15 + 0);
    t16 = (t0 + 6787);
    t25 = *((int *)t16);
    t26 = (t25 + 1);
    t27 = (t26 * 16);
    t28 = (t27 - 1);
    t29 = (t0 + 6787);
    t30 = *((int *)t29);
    t31 = (t30 * 16);
    t32 = (t31 - t28);
    t33 = (t32 * -1);
    t33 = (t33 + 1);
    t34 = (1U * t33);
    memcpy(t14, t13, t34);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 2328U);
    t2 = *((char **)t1);
    t1 = (t0 + 6668U);
    t7 = (t0 + 2448U);
    t8 = *((char **)t7);
    t7 = (t0 + 6684U);
    t9 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t8, t7);
    if (t9 != 0)
        goto LAB12;

LAB14:
LAB13:
LAB10:    t1 = (t0 + 6787);
    t17 = *((int *)t1);
    t2 = (t0 + 6791);
    t18 = *((int *)t2);
    if (t17 == t18)
        goto LAB11;

LAB15:    t3 = (t17 + 1);
    t17 = t3;
    t7 = (t0 + 6787);
    *((int *)t7) = t17;
    goto LAB8;

LAB12:    xsi_set_current_line(39, ng0);
    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t12 = (t0 + 6787);
    t3 = *((int *)t12);
    t19 = (t3 + 1);
    t20 = (t19 * 16);
    t21 = (t20 - 1);
    t4 = (31 - t21);
    t14 = (t0 + 6787);
    t22 = *((int *)t14);
    t23 = (t22 * 16);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t21, t23, -1);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t15 = (t13 + t6);
    t16 = (t0 + 2328U);
    t29 = *((char **)t16);
    t16 = (t29 + 0);
    t35 = (t0 + 6787);
    t24 = *((int *)t35);
    t25 = (t24 + 1);
    t26 = (t25 * 16);
    t27 = (t26 - 1);
    t36 = (t0 + 6787);
    t28 = *((int *)t36);
    t30 = (t28 * 16);
    t31 = (t30 - t27);
    t33 = (t31 * -1);
    t33 = (t33 + 1);
    t34 = (1U * t33);
    memcpy(t16, t15, t34);
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 6787);
    t2 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t37, *((int *)t1), 1);
    t7 = (t0 + 4096);
    t8 = (t7 + 56U);
    t12 = *((char **)t8);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t2, 1U);
    xsi_driver_first_trans_fast(t7);
    goto LAB13;

}

static void work_a_1308903758_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(51, ng0);

LAB3:    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 4160);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 1U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 4016);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1308903758_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1308903758_3212880686_p_0,(void *)work_a_1308903758_3212880686_p_1};
	xsi_register_didat("work_a_1308903758_3212880686", "isim/Min_Array_tb_isim_beh.exe.sim/work/a_1308903758_3212880686.didat");
	xsi_register_executes(pe);
}
