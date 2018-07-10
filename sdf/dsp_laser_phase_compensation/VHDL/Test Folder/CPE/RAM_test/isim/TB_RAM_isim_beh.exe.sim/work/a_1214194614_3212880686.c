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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/RAM_Nsample.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1214194614_3212880686_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    int t10;
    char *t11;
    int t12;
    int t13;
    char *t14;
    char *t15;
    int t16;
    int t17;
    int t18;
    int t19;
    unsigned int t20;
    char *t21;
    int t22;
    int t23;
    unsigned int t24;
    unsigned int t25;
    char *t26;
    char *t27;
    char *t28;
    char *t29;
    int t30;
    int t31;
    int t32;
    int t33;
    char *t34;
    int t35;
    int t36;
    int t37;
    unsigned int t38;
    unsigned int t39;
    int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    char *t44;
    int t45;
    int t46;
    int t47;
    int t48;
    char *t49;
    int t50;
    int t51;
    int t52;
    unsigned int t53;
    unsigned int t54;
    char *t55;
    int t56;
    int t57;
    int t58;
    int t59;
    char *t60;
    int t61;
    int t62;
    int t63;
    unsigned int t64;
    unsigned int t65;

LAB0:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 1472U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 4600);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(34, ng0);
    t3 = (t0 + 1672U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(35, ng0);
    t3 = (t0 + 1832U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB8;

LAB10:
LAB9:    goto LAB6;

LAB8:    xsi_set_current_line(36, ng0);
    t10 = (2 - 1);
    t3 = (t0 + 8108);
    *((int *)t3) = 0;
    t11 = (t0 + 8112);
    *((int *)t11) = t10;
    t12 = 0;
    t13 = t10;

LAB11:    if (t12 <= t13)
        goto LAB12;

LAB14:    goto LAB9;

LAB12:    xsi_set_current_line(37, ng0);
    t14 = (t0 + 1032U);
    t15 = *((char **)t14);
    t14 = (t0 + 8108);
    t16 = *((int *)t14);
    t17 = (t16 + 1);
    t18 = (t17 * 2);
    t19 = (t18 - 1);
    t20 = (3 - t19);
    t21 = (t0 + 8108);
    t22 = *((int *)t21);
    t23 = (t22 * 2);
    xsi_vhdl_check_range_of_slice(3, 0, -1, t19, t23, -1);
    t24 = (t20 * 1U);
    t25 = (0 + t24);
    t26 = (t15 + t25);
    t27 = (t0 + 3048U);
    t28 = *((char **)t27);
    t27 = (t28 + 0);
    t29 = (t0 + 8108);
    t30 = *((int *)t29);
    t31 = (t30 + 1);
    t32 = (t31 * 2);
    t33 = (t32 - 1);
    t34 = (t0 + 8108);
    t35 = *((int *)t34);
    t36 = (t35 * 2);
    t37 = (t36 - t33);
    t38 = (t37 * -1);
    t38 = (t38 + 1);
    t39 = (1U * t38);
    memcpy(t27, t26, t39);
    xsi_set_current_line(38, ng0);
    t1 = (t0 + 3048U);
    t3 = *((char **)t1);
    t1 = (t0 + 1192U);
    t4 = *((char **)t1);
    t1 = (t0 + 7956U);
    t10 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t4, t1);
    t16 = (t10 + 1);
    t17 = (t16 * 2);
    t18 = (t17 - 1);
    t7 = (t0 + 1192U);
    t11 = *((char **)t7);
    t7 = (t0 + 7956U);
    t19 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t11, t7);
    t22 = (t19 * 2);
    t23 = (t22 - t18);
    t20 = (t23 * -1);
    t20 = (t20 + 1);
    t24 = (1U * t20);
    t2 = (t24 != 2U);
    if (t2 == 1)
        goto LAB15;

LAB16:    t14 = (t0 + 8108);
    t30 = *((int *)t14);
    t31 = (t30 - 1);
    t25 = (t31 * -1);
    t38 = (8U * t25);
    t39 = (0U + t38);
    t32 = (4 * 2);
    t33 = (t32 - 1);
    t15 = (t0 + 1192U);
    t21 = *((char **)t15);
    t35 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t21, t1);
    t36 = (t35 + 1);
    t37 = (t36 * 2);
    t40 = (t37 - 1);
    t41 = (t33 - t40);
    t42 = (1U * t41);
    t43 = (t39 + t42);
    t15 = (t0 + 4696);
    t26 = (t15 + 56U);
    t27 = *((char **)t26);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t34 = (t0 + 1192U);
    t44 = *((char **)t34);
    t45 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t44, t1);
    t46 = (t45 + 1);
    t47 = (t46 * 2);
    t48 = (t47 - 1);
    t34 = (t0 + 1192U);
    t49 = *((char **)t34);
    t50 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t49, t7);
    t51 = (t50 * 2);
    t52 = (t51 - t48);
    t53 = (t52 * -1);
    t53 = (t53 + 1);
    t54 = (1U * t53);
    memcpy(t29, t3, t54);
    t34 = (t0 + 1192U);
    t55 = *((char **)t34);
    t56 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t55, t1);
    t57 = (t56 + 1);
    t58 = (t57 * 2);
    t59 = (t58 - 1);
    t34 = (t0 + 1192U);
    t60 = *((char **)t34);
    t61 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t60, t7);
    t62 = (t61 * 2);
    t63 = (t62 - t59);
    t64 = (t63 * -1);
    t64 = (t64 + 1);
    t65 = (1U * t64);
    xsi_driver_first_trans_delta(t15, t43, t65, 0LL);

LAB13:    t1 = (t0 + 8108);
    t12 = *((int *)t1);
    t3 = (t0 + 8112);
    t13 = *((int *)t3);
    if (t12 == t13)
        goto LAB14;

LAB17:    t10 = (t12 + 1);
    t12 = t10;
    t4 = (t0 + 8108);
    *((int *)t4) = t12;
    goto LAB11;

LAB15:    xsi_size_not_matching(t24, 2U, 0);
    goto LAB16;

}

static void work_a_1214194614_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    int t5;
    unsigned int t6;
    unsigned int t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;

LAB0:    xsi_set_current_line(45, ng0);

LAB3:    t1 = (t0 + 2152U);
    t2 = *((char **)t1);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t1 = (t0 + 7972U);
    t4 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t3, t1);
    t5 = (t4 - 1);
    t6 = (t5 * -1);
    xsi_vhdl_check_range_of_index(1, 0, -1, t4);
    t7 = (8U * t6);
    t8 = (0 + t7);
    t9 = (t2 + t8);
    t10 = (t0 + 4760);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    memcpy(t14, t9, 8U);
    xsi_driver_first_trans_fast_port(t10);

LAB2:    t15 = (t0 + 4616);
    *((int *)t15) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_1214194614_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1214194614_3212880686_p_0,(void *)work_a_1214194614_3212880686_p_1};
	xsi_register_didat("work_a_1214194614_3212880686", "isim/TB_RAM_isim_beh.exe.sim/work/a_1214194614_3212880686.didat");
	xsi_register_executes(pe);
}
