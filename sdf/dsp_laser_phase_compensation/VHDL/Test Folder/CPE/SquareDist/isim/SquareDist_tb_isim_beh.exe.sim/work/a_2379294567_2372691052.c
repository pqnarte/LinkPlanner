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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/SquareDist/SquareDist_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
char *ieee_p_2592010699_sub_3293060193_503743352(char *, char *, char *, char *, unsigned char );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_2379294567_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 6152U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 6784);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 3208U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 5960);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 6784);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 3208U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 5960);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_2379294567_2372691052_p_1(char *t0)
{
    char t5[16];
    char t43[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    int t10;
    int t11;
    int t12;
    int t13;
    int t14;
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
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    int64 t28;
    int64 t29;
    int t30;
    int t31;
    int t32;
    int t33;
    char *t34;
    int t35;
    int t36;
    int t37;
    char *t38;
    char *t39;
    int t40;
    int t41;
    char *t42;

LAB0:    t1 = (t0 + 6400U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 4616U);
    t3 = (t0 + 13344);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 1;
    t7 = (t6 + 4U);
    *((int *)t7) = 73;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (73 - 1);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    std_textio_file_open1(t2, t3, t5, (unsigned char)0);
    xsi_set_current_line(121, ng0);
    t2 = (t0 + 4720U);
    t3 = (t0 + 13417);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 1;
    t7 = (t6 + 4U);
    *((int *)t7) = 73;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (73 - 1);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    std_textio_file_open1(t2, t3, t5, (unsigned char)0);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 4824U);
    t3 = (t0 + 13490);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 1;
    t7 = (t6 + 4U);
    *((int *)t7) = 74;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (74 - 1);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    std_textio_file_open1(t2, t3, t5, (unsigned char)1);
    xsi_set_current_line(127, ng0);
    t2 = (t0 + 5032U);
    t3 = (t0 + 13564);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 1;
    t7 = (t6 + 4U);
    *((int *)t7) = 81;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (81 - 1);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    std_textio_file_open1(t2, t3, t5, (unsigned char)1);
    xsi_set_current_line(130, ng0);
    t8 = (8 - 1);
    t2 = (t0 + 13645);
    *((int *)t2) = 0;
    t3 = (t0 + 13649);
    *((int *)t3) = t8;
    t10 = 0;
    t11 = t8;

LAB4:    if (t10 <= t11)
        goto LAB5;

LAB7:    xsi_set_current_line(180, ng0);

LAB25:    *((char **)t1) = &&LAB26;

LAB1:    return;
LAB5:    xsi_set_current_line(132, ng0);
    t12 = (1 - 1);
    t4 = (t0 + 13653);
    *((int *)t4) = 0;
    t6 = (t0 + 13657);
    *((int *)t6) = t12;
    t13 = 0;
    t14 = t12;

LAB8:    if (t13 <= t14)
        goto LAB9;

LAB11:    xsi_set_current_line(148, ng0);
    t2 = (t0 + 3568U);
    t3 = *((char **)t2);
    t2 = (t0 + 6848);
    t4 = (t2 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t15 = *((char **)t7);
    memcpy(t15, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t2 = (t0 + 6912);
    t4 = (t2 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t15 = *((char **)t7);
    memcpy(t15, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 13661);
    t4 = (t0 + 6976);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t15 = (t7 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 13669);
    t4 = (t0 + 7040);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t15 = (t7 + 56U);
    t16 = *((char **)t15);
    memcpy(t16, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(155, ng0);
    t2 = (t0 + 3208U);
    t3 = *((char **)t2);
    t28 = *((int64 *)t3);
    t29 = (1 * t28);
    t2 = (t0 + 6208);
    xsi_process_wait(t2, t29);

LAB15:    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB6:    t2 = (t0 + 13645);
    t10 = *((int *)t2);
    t3 = (t0 + 13649);
    t11 = *((int *)t3);
    if (t10 == t11)
        goto LAB7;

LAB22:    t8 = (t10 + 1);
    t10 = t8;
    t4 = (t0 + 13645);
    *((int *)t4) = t10;
    goto LAB4;

LAB9:    xsi_set_current_line(136, ng0);
    t7 = (t0 + 6208);
    t15 = (t0 + 4616U);
    t16 = (t0 + 5208U);
    std_textio_readline(STD_TEXTIO, t7, t15, t16);
    xsi_set_current_line(137, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 4720U);
    t4 = (t0 + 5280U);
    std_textio_readline(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 5208U);
    t4 = (t0 + 3328U);
    t6 = *((char **)t4);
    t4 = (t6 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(139, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 5280U);
    t4 = (t0 + 3448U);
    t6 = *((char **)t4);
    t4 = (t6 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 3328U);
    t3 = *((char **)t2);
    t8 = *((int *)t3);
    t12 = (2 + 6);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t5, t8, t12);
    t4 = (t0 + 3568U);
    t6 = *((char **)t4);
    t4 = (t0 + 13653);
    t17 = *((int *)t4);
    t18 = (t17 + 1);
    t19 = (2 + 6);
    t20 = (t18 * t19);
    t21 = (t20 - 1);
    t9 = (7 - t21);
    t7 = (t0 + 13653);
    t22 = (2 + 6);
    t23 = *((int *)t7);
    t24 = (t23 * t22);
    xsi_vhdl_check_range_of_slice(7, 0, -1, t21, t24, -1);
    t25 = (t9 * 1U);
    t26 = (0 + t25);
    t15 = (t6 + t26);
    t16 = (t5 + 12U);
    t27 = *((unsigned int *)t16);
    t27 = (t27 * 1U);
    memcpy(t15, t2, t27);
    xsi_set_current_line(142, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t8 = *((int *)t3);
    t12 = (2 + 6);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t5, t8, t12);
    t4 = (t0 + 3688U);
    t6 = *((char **)t4);
    t4 = (t0 + 13653);
    t17 = *((int *)t4);
    t18 = (t17 + 1);
    t19 = (2 + 6);
    t20 = (t18 * t19);
    t21 = (t20 - 1);
    t9 = (7 - t21);
    t7 = (t0 + 13653);
    t22 = (2 + 6);
    t23 = *((int *)t7);
    t24 = (t23 * t22);
    xsi_vhdl_check_range_of_slice(7, 0, -1, t21, t24, -1);
    t25 = (t9 * 1U);
    t26 = (0 + t25);
    t15 = (t6 + t26);
    t16 = (t5 + 12U);
    t27 = *((unsigned int *)t16);
    t27 = (t27 * 1U);
    memcpy(t15, t2, t27);

LAB10:    t2 = (t0 + 13653);
    t13 = *((int *)t2);
    t3 = (t0 + 13657);
    t14 = *((int *)t3);
    if (t13 == t14)
        goto LAB11;

LAB12:    t8 = (t13 + 1);
    t13 = t8;
    t4 = (t0 + 13653);
    *((int *)t4) = t13;
    goto LAB8;

LAB13:    xsi_set_current_line(157, ng0);
    t8 = (1 - 1);
    t2 = (t0 + 13677);
    *((int *)t2) = 0;
    t3 = (t0 + 13681);
    *((int *)t3) = t8;
    t12 = 0;
    t13 = t8;

LAB17:    if (t12 <= t13)
        goto LAB18;

LAB20:    xsi_set_current_line(171, ng0);
    t2 = (t0 + 2152U);
    t3 = *((char **)t2);
    t2 = (t0 + 12776U);
    t4 = ieee_p_2592010699_sub_3293060193_503743352(IEEE_P_2592010699, t5, t3, t2, (unsigned char)0);
    t6 = (t0 + 4048U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    t15 = (t5 + 12U);
    t9 = *((unsigned int *)t15);
    t9 = (t9 * 1U);
    memcpy(t6, t4, t9);
    xsi_set_current_line(173, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 5496U);
    t4 = (t0 + 4048U);
    t6 = *((char **)t4);
    memcpy(t43, t6, 4U);
    t4 = (t0 + 12824U);
    std_textio_write2(STD_TEXTIO, t2, t3, t43, t4, (unsigned char)0, 0);
    xsi_set_current_line(174, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 5032U);
    t4 = (t0 + 5496U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t4);
    goto LAB6;

LAB14:    goto LAB13;

LAB16:    goto LAB14;

LAB18:    xsi_set_current_line(163, ng0);
    t4 = (t0 + 1992U);
    t6 = *((char **)t4);
    t4 = (t0 + 13677);
    t14 = *((int *)t4);
    t17 = (t14 + 1);
    t18 = (2 + 14);
    t19 = (t17 * t18);
    t20 = (t19 - 1);
    t9 = (15 - t20);
    t7 = (t0 + 13677);
    t21 = (2 + 14);
    t22 = *((int *)t7);
    t23 = (t22 * t21);
    xsi_vhdl_check_range_of_slice(15, 0, -1, t20, t23, -1);
    t25 = (t9 * 1U);
    t26 = (0 + t25);
    t15 = (t6 + t26);
    t16 = (t0 + 13677);
    t24 = *((int *)t16);
    t30 = (t24 + 1);
    t31 = (2 + 14);
    t32 = (t30 * t31);
    t33 = (t32 - 1);
    t34 = (t0 + 13677);
    t35 = (2 + 14);
    t36 = *((int *)t34);
    t37 = (t36 * t35);
    t38 = (t5 + 0U);
    t39 = (t38 + 0U);
    *((int *)t39) = t33;
    t39 = (t38 + 4U);
    *((int *)t39) = t37;
    t39 = (t38 + 8U);
    *((int *)t39) = -1;
    t40 = (t37 - t33);
    t27 = (t40 * -1);
    t27 = (t27 + 1);
    t39 = (t38 + 12U);
    *((unsigned int *)t39) = t27;
    t41 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t15, t5);
    t39 = (t0 + 3808U);
    t42 = *((char **)t39);
    t39 = (t42 + 0);
    *((int *)t39) = t41;
    xsi_set_current_line(165, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 5352U);
    t4 = (t0 + 3808U);
    t6 = *((char **)t4);
    t8 = *((int *)t6);
    std_textio_write5(STD_TEXTIO, t2, t3, t8, (unsigned char)0, 0);
    xsi_set_current_line(166, ng0);
    t2 = (t0 + 6208);
    t3 = (t0 + 4824U);
    t4 = (t0 + 5352U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t4);

LAB19:    t2 = (t0 + 13677);
    t12 = *((int *)t2);
    t3 = (t0 + 13681);
    t13 = *((int *)t3);
    if (t12 == t13)
        goto LAB20;

LAB21:    t8 = (t12 + 1);
    t12 = t8;
    t4 = (t0 + 13677);
    *((int *)t4) = t12;
    goto LAB17;

LAB23:    goto LAB2;

LAB24:    goto LAB23;

LAB26:    goto LAB24;

}


extern void work_a_2379294567_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2379294567_2372691052_p_0,(void *)work_a_2379294567_2372691052_p_1};
	xsi_register_didat("work_a_2379294567_2372691052", "isim/SquareDist_tb_isim_beh.exe.sim/work/a_2379294567_2372691052.didat");
	xsi_register_executes(pe);
}
