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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/Min_Array/Min_Array_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_2592010699;

char *ieee_p_2592010699_sub_3293060193_503743352(char *, char *, char *, char *, unsigned char );
char *ieee_p_2592010699_sub_393209765_503743352(char *, char *, char *, char *);


static void work_a_3869088691_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 3864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 4496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3672);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 4496);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(86, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3672);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3869088691_2372691052_p_1(char *t0)
{
    char t5[16];
    char t14[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t6;
    char *t7;
    int t8;
    unsigned int t9;
    int t10;
    char *t11;
    int64 t12;
    int64 t13;
    int t15;

LAB0:    t1 = (t0 + 4112U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2960U);
    t3 = (t0 + 8293);
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
    std_textio_file_open1(t2, t3, t5, (unsigned char)0);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 2856U);
    t3 = (t0 + 8367);
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
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 8441);
    *((int *)t2) = 0;
    t3 = (t0 + 8445);
    *((int *)t3) = 3;
    t8 = 0;
    t10 = 3;

LAB4:    if (t8 <= t10)
        goto LAB5;

LAB7:    xsi_set_current_line(121, ng0);

LAB15:    *((char **)t1) = &&LAB16;

LAB1:    return;
LAB5:    xsi_set_current_line(106, ng0);
    t4 = (t0 + 3920);
    t6 = (t0 + 2960U);
    t7 = (t0 + 3208U);
    std_textio_readline(STD_TEXTIO, t4, t6, t7);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 3920);
    t3 = (t0 + 3208U);
    t4 = (t0 + 2288U);
    t6 = *((char **)t4);
    t4 = (t0 + 7972U);
    std_textio_read4(STD_TEXTIO, t2, t3, t6, t4);
    xsi_set_current_line(109, ng0);
    t2 = (t0 + 2288U);
    t3 = *((char **)t2);
    t2 = (t0 + 7972U);
    t4 = ieee_p_2592010699_sub_393209765_503743352(IEEE_P_2592010699, t5, t3, t2);
    t6 = (t0 + 2528U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    t11 = (t5 + 12U);
    t9 = *((unsigned int *)t11);
    t9 = (t9 * 1U);
    memcpy(t6, t4, t9);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2528U);
    t3 = *((char **)t2);
    t2 = (t0 + 4560);
    t4 = (t2 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t11 = *((char **)t7);
    memcpy(t11, t3, 32U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(112, ng0);
    t2 = (t0 + 2168U);
    t3 = *((char **)t2);
    t12 = *((int64 *)t3);
    t13 = (1 * t12);
    t2 = (t0 + 3920);
    xsi_process_wait(t2, t13);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB6:    t2 = (t0 + 8441);
    t8 = *((int *)t2);
    t3 = (t0 + 8445);
    t10 = *((int *)t3);
    if (t8 == t10)
        goto LAB7;

LAB12:    t15 = (t8 + 1);
    t8 = t15;
    t4 = (t0 + 8441);
    *((int *)t4) = t8;
    goto LAB4;

LAB8:    xsi_set_current_line(114, ng0);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t2 = (t0 + 7956U);
    t4 = ieee_p_2592010699_sub_3293060193_503743352(IEEE_P_2592010699, t5, t3, t2, (unsigned char)0);
    t6 = (t0 + 2408U);
    t7 = *((char **)t6);
    t6 = (t7 + 0);
    t11 = (t5 + 12U);
    t9 = *((unsigned int *)t11);
    t9 = (t9 * 1U);
    memcpy(t6, t4, t9);
    xsi_set_current_line(116, ng0);
    t2 = (t0 + 3920);
    t3 = (t0 + 3136U);
    t4 = (t0 + 2408U);
    t6 = *((char **)t4);
    memcpy(t14, t6, 1U);
    t4 = (t0 + 7988U);
    std_textio_write2(STD_TEXTIO, t2, t3, t14, t4, (unsigned char)0, 0);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 3920);
    t3 = (t0 + 2856U);
    t4 = (t0 + 3136U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t4);
    goto LAB6;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB13:    goto LAB2;

LAB14:    goto LAB13;

LAB16:    goto LAB14;

}


extern void work_a_3869088691_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3869088691_2372691052_p_0,(void *)work_a_3869088691_2372691052_p_1};
	xsi_register_didat("work_a_3869088691_2372691052", "isim/Min_Array_tb_isim_beh.exe.sim/work/a_3869088691_2372691052.didat");
	xsi_register_executes(pe);
}
