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
static const char *ng0 = "C:/netxpto/Celestino/sdf/dsp_laser_phase_compensation/VHDL/Basic Functions/Expander_NSigned.vhd";
extern char *IEEE_P_2592010699;



static void work_a_1625662130_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    int t4;
    unsigned int t5;
    unsigned int t6;
    unsigned int t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;

LAB0:    xsi_set_current_line(60, ng0);

LAB3:    t1 = (t0 + 1560U);
    t2 = *((char **)t1);
    t3 = (2 + 24);
    t4 = (t3 - 1);
    t5 = (28 - t4);
    t6 = (t5 * 1U);
    t7 = (0 + t6);
    t1 = (t2 + t7);
    t8 = (t0 + 4608);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 2U);
    xsi_driver_first_trans_fast(t8);

LAB2:    t13 = (t0 + 4496);
    *((int *)t13) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1625662130_3212880686_p_1(char *t0)
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

LAB0:    xsi_set_current_line(74, ng0);

LAB3:    t1 = (t0 + 1560U);
    t2 = *((char **)t1);
    t3 = (24 - 1);
    t4 = (28 - t3);
    t5 = (t4 * 1U);
    t6 = (0 + t5);
    t1 = (t2 + t6);
    t7 = (t0 + 4672);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 14U);
    xsi_driver_first_trans_fast(t7);

LAB2:    t12 = (t0 + 4512);
    *((int *)t12) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1625662130_3212880686_p_2(char *t0)
{
    char t4[16];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned char t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(76, ng0);

LAB3:    t1 = (t0 + 1880U);
    t2 = *((char **)t1);
    t1 = (t0 + 2040U);
    t3 = *((char **)t1);
    t5 = ((IEEE_P_2592010699) + 4024);
    t6 = (t0 + 7632U);
    t7 = (t0 + 7648U);
    t1 = xsi_base_array_concat(t1, t4, t5, (char)97, t2, t6, (char)97, t3, t7, (char)101);
    t8 = (2U + 14U);
    t9 = (16U != t8);
    if (t9 == 1)
        goto LAB5;

LAB6:    t10 = (t0 + 4736);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t1, 16U);
    xsi_driver_first_trans_fast_port(t10);

LAB2:    t15 = (t0 + 4528);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    goto LAB2;

LAB5:    xsi_size_not_matching(16U, t8, 0);
    goto LAB6;

}


extern void work_a_1625662130_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1625662130_3212880686_p_0,(void *)work_a_1625662130_3212880686_p_1,(void *)work_a_1625662130_3212880686_p_2};
	xsi_register_didat("work_a_1625662130_3212880686", "isim/CpeBPS_tb_isim_beh.exe.sim/work/a_1625662130_3212880686.didat");
	xsi_register_executes(pe);
}
