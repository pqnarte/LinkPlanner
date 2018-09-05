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
extern char *IEEE_P_3972351953;
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;
static const char *ng3 = "C:/Users/csmartins/Downloads/rom_vhd.vhd";
extern char *IEEE_P_2592010699;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
double ieee_p_3972351953_sub_2171244304_2984157535(char *, int , double );
double ieee_p_3972351953_sub_773523744_2984157535(char *, double );


char *work_a_0045727239_1516540902_sub_1100358422_2134189630(char *t1)
{
    char t2[368];
    char t9[8];
    char t18[8];
    char t21[32];
    char t30[2048];
    char t42[16];
    char *t0;
    int t4;
    double t5;
    char *t6;
    char *t7;
    char *t8;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    double t15;
    char *t16;
    char *t17;
    char *t19;
    char *t20;
    char *t22;
    char *t23;
    int t24;
    unsigned int t25;
    char *t26;
    int t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    int t38;
    int t39;
    int t40;
    int t41;
    char *t43;
    double t44;
    double t45;
    double t46;
    char *t47;
    double t48;
    double t49;
    double t50;
    char *t51;
    double t52;
    double t53;
    int t54;
    unsigned char t55;
    unsigned char t56;
    double t57;
    double t58;
    char *t59;
    char *t60;
    int t61;
    int t62;
    int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    char *t67;
    unsigned int t68;

LAB0:    t4 = (8 - 2);
    t5 = ieee_p_3972351953_sub_2171244304_2984157535(IEEE_P_3972351953, 2, ((double)(t4)));
    t6 = (t2 + 4U);
    t7 = ((STD_STANDARD) + 472);
    t8 = (t6 + 88U);
    *((char **)t8) = t7;
    t10 = (t6 + 56U);
    *((char **)t10) = t9;
    *((double *)t9) = t5;
    t11 = (t6 + 80U);
    *((unsigned int *)t11) = 8U;
    t12 = (t1 + 1888U);
    t13 = *((char **)t12);
    t14 = *((int *)t13);
    t15 = (1.0000000000000000 / (((double)(t14))));
    t12 = (t2 + 124U);
    t16 = ((STD_STANDARD) + 472);
    t17 = (t12 + 88U);
    *((char **)t17) = t16;
    t19 = (t12 + 56U);
    *((char **)t19) = t18;
    *((double *)t18) = t15;
    t20 = (t12 + 80U);
    *((unsigned int *)t20) = 8U;
    t22 = (t21 + 0U);
    t23 = (t22 + 0U);
    *((int *)t23) = 0;
    t23 = (t22 + 4U);
    *((int *)t23) = 255;
    t23 = (t22 + 8U);
    *((int *)t23) = 1;
    t24 = (255 - 0);
    t25 = (t24 * 1);
    t25 = (t25 + 1);
    t23 = (t22 + 12U);
    *((unsigned int *)t23) = t25;
    t23 = (t21 + 16U);
    t26 = (t23 + 0U);
    *((int *)t26) = 7;
    t26 = (t23 + 4U);
    *((int *)t26) = 0;
    t26 = (t23 + 8U);
    *((int *)t26) = -1;
    t27 = (0 - 7);
    t25 = (t27 * -1);
    t25 = (t25 + 1);
    t26 = (t23 + 12U);
    *((unsigned int *)t26) = t25;
    t26 = (t2 + 244U);
    t28 = (t1 + 3888);
    t29 = (t26 + 88U);
    *((char **)t29) = t28;
    t31 = (t26 + 56U);
    *((char **)t31) = t30;
    xsi_type_set_default_value(t28, t30, 0);
    t32 = (t26 + 64U);
    t33 = (t28 + 80U);
    t34 = *((char **)t33);
    *((char **)t32) = t34;
    t35 = (t26 + 80U);
    *((unsigned int *)t35) = 2048U;
    t36 = (t1 + 1888U);
    t37 = *((char **)t36);
    t38 = *((int *)t37);
    t39 = (t38 - 1);
    t40 = 0;
    t41 = t39;

LAB2:    if (t40 <= t41)
        goto LAB3;

LAB5:    t7 = (t26 + 56U);
    t8 = *((char **)t7);
    t55 = (2048U != 2048U);
    if (t55 == 1)
        goto LAB12;

LAB13:    t0 = xsi_get_transient_memory(2048U);
    memcpy(t0, t8, 2048U);

LAB1:    return t0;
LAB3:    t36 = ((IEEE_P_3972351953) + 1408U);
    t43 = *((char **)t36);
    t44 = *((double *)t43);
    t45 = (2.0000000000000000 * t44);
    t46 = (t45 * (((double)(t40))));
    t36 = (t12 + 56U);
    t47 = *((char **)t36);
    t48 = *((double *)t47);
    t49 = (t46 * t48);
    t50 = ieee_p_3972351953_sub_773523744_2984157535(IEEE_P_3972351953, t49);
    t36 = (t6 + 56U);
    t51 = *((char **)t36);
    t52 = *((double *)t51);
    t53 = (t50 * t52);
    t55 = (t53 >= 0);
    if (t55 == 1)
        goto LAB6;

LAB7:    t58 = (t53 - 0.50000000000000000);
    t54 = ((int)(t58));

LAB8:    t36 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t42, t54, 8);
    t59 = (t26 + 56U);
    t60 = *((char **)t59);
    t61 = (t40 - 0);
    t25 = (t61 * 1);
    xsi_vhdl_check_range_of_index(0, 255, 1, t40);
    t62 = (8 - 1);
    t63 = (0 - t62);
    t64 = (t63 * -1);
    t64 = (t64 + 1);
    t64 = (t64 * 1U);
    t65 = (t64 * t25);
    t66 = (0 + t65);
    t59 = (t60 + t66);
    t67 = (t42 + 12U);
    t68 = *((unsigned int *)t67);
    t68 = (t68 * 1U);
    memcpy(t59, t36, t68);

LAB4:    if (t40 == t41)
        goto LAB5;

LAB11:    t4 = (t40 + 1);
    t40 = t4;
    goto LAB2;

LAB6:    t56 = (t53 >= 2147483647);
    if (t56 == 1)
        goto LAB9;

LAB10:    t57 = (t53 + 0.50000000000000000);
    t54 = ((int)(t57));
    goto LAB8;

LAB9:    t54 = 2147483647;
    goto LAB8;

LAB12:    xsi_size_not_matching(2048U, 2048U, 0);
    goto LAB13;

LAB14:;
}

static void work_a_0045727239_1516540902_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    int t6;
    int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;

LAB0:    xsi_set_current_line(40, ng3);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3312);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(41, ng3);
    t3 = (t0 + 2008U);
    t4 = *((char **)t3);
    t3 = (t0 + 1192U);
    t5 = *((char **)t3);
    t3 = (t0 + 5516U);
    t6 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t5, t3);
    t7 = (t6 - 0);
    t8 = (t7 * 1);
    xsi_vhdl_check_range_of_index(0, 255, 1, t6);
    t9 = (8U * t8);
    t10 = (0 + t9);
    t11 = (t4 + t10);
    t12 = (t0 + 3392);
    t13 = (t12 + 56U);
    t14 = *((char **)t13);
    t15 = (t14 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t11, 8U);
    xsi_driver_first_trans_fast_port(t12);
    goto LAB3;

}


extern void work_a_0045727239_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0045727239_1516540902_p_0};
	static char *se[] = {(void *)work_a_0045727239_1516540902_sub_1100358422_2134189630};
	xsi_register_didat("work_a_0045727239_1516540902", "isim/rom_vhd_isim_beh.exe.sim/work/a_0045727239_1516540902.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
}
