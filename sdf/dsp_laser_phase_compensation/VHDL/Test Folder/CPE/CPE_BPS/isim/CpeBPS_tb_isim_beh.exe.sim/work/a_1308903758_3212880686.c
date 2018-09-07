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
static const char *ng0 = "C:/netxpto/Celestino/sdf/dsp_laser_phase_compensation/VHDL/Final Folder/Min_Array.vhd";
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
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    char *t12;
    char *t13;
    int t14;
    int t15;
    int t16;
    int t17;
    int t18;
    int t19;
    int t20;
    int t21;
    char *t22;
    char *t23;
    char *t24;
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

LAB0:    xsi_set_current_line(32, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3712);
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
    t3 = (t0 + 1352U);
    t7 = *((char **)t3);
    t8 = (16 - 1);
    t9 = (31 - t8);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t3 = (t7 + t11);
    t12 = (t0 + 2168U);
    t13 = *((char **)t12);
    t12 = (t13 + 0);
    memcpy(t12, t3, 16U);
    xsi_set_current_line(35, ng0);
    t1 = xsi_get_transient_memory(1U);
    memset(t1, 0, 1U);
    t3 = t1;
    memset(t3, (unsigned char)2, 1U);
    t4 = (t0 + 2288U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    memcpy(t4, t1, 1U);
    xsi_set_current_line(36, ng0);
    t8 = (2 - 1);
    t1 = (t0 + 6483);
    *((int *)t1) = 1;
    t3 = (t0 + 6487);
    *((int *)t3) = t8;
    t14 = 1;
    t15 = t8;

LAB8:    if (t14 <= t15)
        goto LAB9;

LAB11:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 2288U);
    t3 = *((char **)t1);
    t1 = (t0 + 3792);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t12 = (t7 + 56U);
    t13 = *((char **)t12);
    memcpy(t13, t3, 1U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(45, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t3 = t1;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 2168U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    memcpy(t4, t1, 16U);
    xsi_set_current_line(47, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t3 = t1;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 2408U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    memcpy(t4, t1, 16U);
    goto LAB6;

LAB9:    xsi_set_current_line(37, ng0);
    t4 = (t0 + 1352U);
    t7 = *((char **)t4);
    t4 = (t0 + 6483);
    t16 = *((int *)t4);
    t17 = (t16 + 1);
    t18 = (t17 * 16);
    t19 = (t18 - 1);
    t9 = (31 - t19);
    t12 = (t0 + 6483);
    t20 = *((int *)t12);
    t21 = (t20 * 16);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t19, t21, -1);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t13 = (t7 + t11);
    t22 = (t0 + 2408U);
    t23 = *((char **)t22);
    t22 = (t23 + 0);
    t24 = (t0 + 6483);
    t25 = *((int *)t24);
    t26 = (t25 + 1);
    t27 = (t26 * 16);
    t28 = (t27 - 1);
    t29 = (t0 + 6483);
    t30 = *((int *)t29);
    t31 = (t30 * 16);
    t32 = (t31 - t28);
    t33 = (t32 * -1);
    t33 = (t33 + 1);
    t34 = (1U * t33);
    memcpy(t22, t13, t34);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 2168U);
    t3 = *((char **)t1);
    t1 = (t0 + 6348U);
    t4 = (t0 + 2408U);
    t7 = *((char **)t4);
    t4 = (t0 + 6380U);
    t2 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t3, t1, t7, t4);
    if (t2 != 0)
        goto LAB12;

LAB14:
LAB13:
LAB10:    t1 = (t0 + 6483);
    t14 = *((int *)t1);
    t3 = (t0 + 6487);
    t15 = *((int *)t3);
    if (t14 == t15)
        goto LAB11;

LAB15:    t8 = (t14 + 1);
    t14 = t8;
    t4 = (t0 + 6483);
    *((int *)t4) = t14;
    goto LAB8;

LAB12:    xsi_set_current_line(39, ng0);
    t12 = (t0 + 1352U);
    t13 = *((char **)t12);
    t12 = (t0 + 6483);
    t8 = *((int *)t12);
    t16 = (t8 + 1);
    t17 = (t16 * 16);
    t18 = (t17 - 1);
    t9 = (31 - t18);
    t22 = (t0 + 6483);
    t19 = *((int *)t22);
    t20 = (t19 * 16);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t18, t20, -1);
    t10 = (t9 * 1U);
    t11 = (0 + t10);
    t23 = (t13 + t11);
    t24 = (t0 + 2168U);
    t29 = *((char **)t24);
    t24 = (t29 + 0);
    t35 = (t0 + 6483);
    t21 = *((int *)t35);
    t25 = (t21 + 1);
    t26 = (t25 * 16);
    t27 = (t26 - 1);
    t36 = (t0 + 6483);
    t28 = *((int *)t36);
    t30 = (t28 * 16);
    t31 = (t30 - t27);
    t33 = (t31 * -1);
    t33 = (t33 + 1);
    t34 = (1U * t33);
    memcpy(t24, t23, t34);
    xsi_set_current_line(40, ng0);
    t1 = (t0 + 6483);
    t3 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t37, *((int *)t1), 1);
    t4 = (t0 + 2288U);
    t7 = *((char **)t4);
    t4 = (t7 + 0);
    t12 = (t37 + 12U);
    t9 = *((unsigned int *)t12);
    t9 = (t9 * 1U);
    memcpy(t4, t3, t9);
    goto LAB13;

}


extern void work_a_1308903758_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1308903758_3212880686_p_0};
	xsi_register_didat("work_a_1308903758_3212880686", "isim/CpeBPS_tb_isim_beh.exe.sim/work/a_1308903758_3212880686.didat");
	xsi_register_executes(pe);
}
