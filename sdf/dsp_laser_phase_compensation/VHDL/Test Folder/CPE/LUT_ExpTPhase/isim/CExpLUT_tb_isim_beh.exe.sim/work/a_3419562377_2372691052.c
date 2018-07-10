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
extern char *STD_TEXTIO;
static const char *ng1 = "mif_file";
extern char *STD_STANDARD;
extern char *IEEE_P_1242562249;
static const char *ng4 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Basic Functions/LutExpTPhase.vhd";
extern char *IEEE_P_2592010699;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


char *work_a_3419562377_2372691052_sub_300287447_4163069965(char *t1, char *t2, char *t3)
{
    char t4[328];
    char t5[24];
    char t20[8];
    char t23[32];
    char t32[32];
    char t46[16];
    char *t0;
    char *t6;
    char *t7;
    unsigned int t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t21;
    char *t22;
    char *t24;
    char *t25;
    int t26;
    unsigned int t27;
    char *t28;
    int t29;
    char *t30;
    char *t31;
    char *t33;
    char *t34;
    char *t35;
    char *t36;
    char *t37;
    char *t38;
    unsigned char t39;
    char *t40;
    int t41;
    int t42;
    int t43;
    char *t44;
    char *t45;
    unsigned int t47;
    unsigned int t48;

LAB0:    t6 = ((STD_TEXTIO) + 3440);
    t7 = (t3 + 12U);
    t8 = *((unsigned int *)t7);
    t8 = (t8 * 1U);
    t9 = (t4 + 4U);
    t10 = xsi_create_file_variable_in_buffer(0, ng1, t6, t2, t8, 1);
    *((char **)t9) = t10;
    t11 = (t4 + 12U);
    t12 = ((STD_TEXTIO) + 3280);
    t13 = (t11 + 56U);
    *((char **)t13) = t12;
    t14 = (t11 + 40U);
    *((char **)t14) = 0;
    t15 = (t11 + 64U);
    *((int *)t15) = 1;
    t16 = (t11 + 48U);
    *((char **)t16) = 0;
    t17 = (t4 + 84U);
    t18 = ((STD_STANDARD) + 384);
    t19 = (t17 + 88U);
    *((char **)t19) = t18;
    t21 = (t17 + 56U);
    *((char **)t21) = t20;
    *((int *)t20) = 0;
    t22 = (t17 + 80U);
    *((unsigned int *)t22) = 4U;
    t24 = (t23 + 0U);
    t25 = (t24 + 0U);
    *((int *)t25) = 0;
    t25 = (t24 + 4U);
    *((int *)t25) = 3;
    t25 = (t24 + 8U);
    *((int *)t25) = 1;
    t26 = (3 - 0);
    t27 = (t26 * 1);
    t27 = (t27 + 1);
    t25 = (t24 + 12U);
    *((unsigned int *)t25) = t27;
    t25 = (t23 + 16U);
    t28 = (t25 + 0U);
    *((int *)t28) = 7;
    t28 = (t25 + 4U);
    *((int *)t28) = 0;
    t28 = (t25 + 8U);
    *((int *)t28) = -1;
    t29 = (0 - 7);
    t27 = (t29 * -1);
    t27 = (t27 + 1);
    t28 = (t25 + 12U);
    *((unsigned int *)t28) = t27;
    t28 = (t4 + 204U);
    t30 = (t1 + 4592);
    t31 = (t28 + 88U);
    *((char **)t31) = t30;
    t33 = (t28 + 56U);
    *((char **)t33) = t32;
    xsi_type_set_default_value(t30, t32, 0);
    t34 = (t28 + 64U);
    t35 = (t30 + 80U);
    t36 = *((char **)t35);
    *((char **)t34) = t36;
    t37 = (t28 + 80U);
    *((unsigned int *)t37) = 32U;
    t38 = (t5 + 4U);
    t39 = (t2 != 0);
    if (t39 == 1)
        goto LAB3;

LAB2:    t40 = (t5 + 12U);
    *((char **)t40) = t3;
    t41 = (4 - 1);
    t42 = 0;
    t43 = t41;

LAB4:    if (t42 <= t43)
        goto LAB5;

LAB7:    t6 = (t28 + 56U);
    t7 = *((char **)t6);
    t39 = (32U != 32U);
    if (t39 == 1)
        goto LAB9;

LAB10:    t0 = xsi_get_transient_memory(32U);
    memcpy(t0, t7, 32U);

LAB1:    xsi_access_variable_delete(t11);
    t6 = (t4 + 4U);
    t7 = *((char **)t6);
    xsi_delete_file_variable(t7);
    return t0;
LAB3:    *((char **)t38) = t2;
    goto LAB2;

LAB5:    t44 = (t4 + 4U);
    t45 = *((char **)t44);
    std_textio_readline(STD_TEXTIO, (char *)0, t45, t11);
    t6 = (t17 + 56U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    std_textio_read10(STD_TEXTIO, (char *)0, t11, t6);
    t6 = (t17 + 56U);
    t7 = *((char **)t6);
    t26 = *((int *)t7);
    t6 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t46, t26, 8);
    t9 = (t28 + 56U);
    t10 = *((char **)t9);
    t29 = (t42 - 0);
    t8 = (t29 * 1);
    xsi_vhdl_check_range_of_index(0, 3, 1, t42);
    t27 = (8U * t8);
    t47 = (0 + t27);
    t9 = (t10 + t47);
    t12 = (t46 + 12U);
    t48 = *((unsigned int *)t12);
    t48 = (t48 * 1U);
    memcpy(t9, t6, t48);

LAB6:    if (t42 == t43)
        goto LAB7;

LAB8:    t26 = (t42 + 1);
    t42 = t26;
    goto LAB4;

LAB9:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB10;

LAB11:;
}

static void work_a_3419562377_2372691052_p_0(char *t0)
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
    char *t11;
    char *t12;
    int t13;
    int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    char *t20;
    int t21;
    int t22;
    int t23;
    int t24;
    unsigned int t25;
    char *t26;
    int t27;
    int t28;
    unsigned int t29;
    unsigned int t30;
    char *t31;

LAB0:    xsi_set_current_line(54, ng4);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    xsi_set_current_line(62, ng4);
    t1 = (t0 + 2528U);
    t3 = *((char **)t1);
    t1 = (t0 + 4032);
    t4 = (t1 + 56U);
    t8 = *((char **)t4);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 32U);
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(63, ng4);
    t1 = (t0 + 2648U);
    t3 = *((char **)t1);
    t1 = (t0 + 4096);
    t4 = (t1 + 56U);
    t8 = *((char **)t4);
    t11 = (t8 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 32U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3952);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(55, ng4);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(56, ng4);
    t7 = (4 - 1);
    t3 = (t0 + 7312);
    *((int *)t3) = 0;
    t8 = (t0 + 7316);
    *((int *)t8) = t7;
    t9 = 0;
    t10 = t7;

LAB8:    if (t9 <= t10)
        goto LAB9;

LAB11:    goto LAB6;

LAB9:    xsi_set_current_line(57, ng4);
    t11 = (t0 + 2288U);
    t12 = *((char **)t11);
    t11 = (t0 + 7312);
    t13 = *((int *)t11);
    t14 = (t13 - 0);
    t15 = (t14 * 1);
    xsi_vhdl_check_range_of_index(0, 3, 1, *((int *)t11));
    t16 = (8U * t15);
    t17 = (0 + t16);
    t18 = (t12 + t17);
    t19 = (t0 + 2528U);
    t20 = *((char **)t19);
    t19 = (t0 + 7312);
    t21 = *((int *)t19);
    t22 = (t21 + 1);
    t23 = (t22 * 8);
    t24 = (t23 - 1);
    t25 = (31 - t24);
    t26 = (t0 + 7312);
    t27 = *((int *)t26);
    t28 = (t27 * 8);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t24, t28, -1);
    t29 = (t25 * 1U);
    t30 = (0 + t29);
    t31 = (t20 + t30);
    memcpy(t31, t18, 8U);
    xsi_set_current_line(58, ng4);
    t1 = (t0 + 2408U);
    t3 = *((char **)t1);
    t1 = (t0 + 7312);
    t7 = *((int *)t1);
    t13 = (t7 - 0);
    t15 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 3, 1, *((int *)t1));
    t16 = (8U * t15);
    t17 = (0 + t16);
    t4 = (t3 + t17);
    t8 = (t0 + 2648U);
    t11 = *((char **)t8);
    t8 = (t0 + 7312);
    t14 = *((int *)t8);
    t21 = (t14 + 1);
    t22 = (t21 * 8);
    t23 = (t22 - 1);
    t25 = (31 - t23);
    t12 = (t0 + 7312);
    t24 = *((int *)t12);
    t27 = (t24 * 8);
    xsi_vhdl_check_range_of_slice(31, 0, -1, t23, t27, -1);
    t29 = (t25 * 1U);
    t30 = (0 + t29);
    t18 = (t11 + t30);
    memcpy(t18, t4, 8U);

LAB10:    t1 = (t0 + 7312);
    t9 = *((int *)t1);
    t3 = (t0 + 7316);
    t10 = *((int *)t3);
    if (t9 == t10)
        goto LAB11;

LAB12:    t7 = (t9 + 1);
    t9 = t7;
    t4 = (t0 + 7312);
    *((int *)t4) = t9;
    goto LAB8;

}


void ieee_p_2592010699_sub_3130575329_503743352();

extern void work_a_3419562377_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3419562377_2372691052_p_0};
	static char *se[] = {(void *)work_a_3419562377_2372691052_sub_300287447_4163069965};
	xsi_register_didat("work_a_3419562377_2372691052", "isim/CExpLUT_tb_isim_beh.exe.sim/work/a_3419562377_2372691052.didat");
	xsi_register_executes(pe);
	xsi_register_subprogram_executes(se);
	xsi_register_resolution_function(1, 2, (void *)ieee_p_2592010699_sub_3130575329_503743352, 5);
}
