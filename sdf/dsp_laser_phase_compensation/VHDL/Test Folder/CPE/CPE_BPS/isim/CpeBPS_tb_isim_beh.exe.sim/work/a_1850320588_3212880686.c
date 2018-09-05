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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/FindROMadrr.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1850320588_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    int t11;
    int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    char *t20;
    char *t21;
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

LAB0:    xsi_set_current_line(29, ng0);
    t1 = (t0 + 1312U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(34, ng0);
    t1 = (t0 + 2448U);
    t3 = *((char **)t1);
    t1 = (t0 + 3832);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t14 = *((char **)t8);
    memcpy(t14, t3, 2U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3752);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(30, ng0);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(31, ng0);
    t3 = (t0 + 1032U);
    t7 = *((char **)t3);
    t3 = (t0 + 1192U);
    t8 = *((char **)t3);
    t3 = (t0 + 6224U);
    t9 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t8, t3);
    t10 = (t9 + 1);
    t11 = (t10 * 2);
    t12 = (t11 - 1);
    t13 = (3 - t12);
    t14 = (t0 + 1192U);
    t15 = *((char **)t14);
    t14 = (t0 + 6224U);
    t16 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t15, t14);
    t17 = (t16 * 2);
    xsi_vhdl_check_range_of_slice(3, 0, -1, t12, t17, -1);
    t18 = (t13 * 1U);
    t19 = (0 + t18);
    t20 = (t7 + t19);
    t21 = (t0 + 2448U);
    t22 = *((char **)t21);
    t21 = (t22 + 0);
    t23 = (t0 + 1192U);
    t24 = *((char **)t23);
    t25 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t24, t3);
    t26 = (t25 + 1);
    t27 = (t26 * 2);
    t28 = (t27 - 1);
    t23 = (t0 + 1192U);
    t29 = *((char **)t23);
    t30 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t29, t14);
    t31 = (t30 * 2);
    t32 = (t31 - t28);
    t33 = (t32 * -1);
    t33 = (t33 + 1);
    t34 = (1U * t33);
    memcpy(t21, t20, t34);
    goto LAB6;

}


extern void work_a_1850320588_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1850320588_3212880686_p_0};
	xsi_register_didat("work_a_1850320588_3212880686", "isim/CpeBPS_tb_isim_beh.exe.sim/work/a_1850320588_3212880686.didat");
	xsi_register_executes(pe);
}
