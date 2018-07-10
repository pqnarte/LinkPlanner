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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/ErrorTPhase/ErrorTPhase_tb.vhd";
extern char *STD_TEXTIO;
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

char *ieee_p_1242562249_sub_2563015576_1035706684(char *, char *, int , int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_2814885930_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 6512U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 7144);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(78, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 6320);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 7144);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 6320);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_2814885930_2372691052_p_1(char *t0)
{
    char t5[16];
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
    int t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    int t20;
    int t21;
    int t22;
    int t23;
    int t24;
    int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    int64 t29;
    int64 t30;
    int t31;
    int t32;
    int t33;
    int t34;
    int t35;
    int t36;
    int t37;
    char *t38;
    char *t39;
    int t40;
    int t41;
    char *t42;

LAB0:    t1 = (t0 + 6760U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 4976U);
    t3 = (t0 + 14092);
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
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 5080U);
    t3 = (t0 + 14165);
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
    xsi_set_current_line(135, ng0);
    t2 = (t0 + 5184U);
    t3 = (t0 + 14238);
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
    xsi_set_current_line(138, ng0);
    t2 = (t0 + 5392U);
    t3 = (t0 + 14312);
    t6 = (t5 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 1;
    t7 = (t6 + 4U);
    *((int *)t7) = 79;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t8 = (79 - 1);
    t9 = (t8 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    std_textio_file_open1(t2, t3, t5, (unsigned char)1);
    xsi_set_current_line(141, ng0);
    t2 = (t0 + 4648U);
    t3 = *((char **)t2);
    t8 = *((int *)t3);
    t10 = (t8 + 1);
    t2 = (t0 + 14391);
    *((int *)t2) = 0;
    t4 = (t0 + 14395);
    *((int *)t4) = t10;
    t11 = 0;
    t12 = t10;

LAB4:    if (t11 <= t12)
        goto LAB5;

LAB7:    xsi_set_current_line(192, ng0);

LAB25:    *((char **)t1) = &&LAB26;

LAB1:    return;
LAB5:    xsi_set_current_line(143, ng0);
    t13 = (1 - 1);
    t6 = (t0 + 14399);
    *((int *)t6) = 0;
    t7 = (t0 + 14403);
    *((int *)t7) = t13;
    t14 = 0;
    t15 = t13;

LAB8:    if (t14 <= t15)
        goto LAB9;

LAB11:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 3808U);
    t3 = *((char **)t2);
    t2 = (t0 + 7208);
    t4 = (t2 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t16 = *((char **)t7);
    memcpy(t16, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 3928U);
    t3 = *((char **)t2);
    t2 = (t0 + 7272);
    t4 = (t2 + 56U);
    t6 = *((char **)t4);
    t7 = (t6 + 56U);
    t16 = *((char **)t7);
    memcpy(t16, t3, 8U);
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(163, ng0);
    t2 = (t0 + 14407);
    t4 = (t0 + 7336);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t16 = (t7 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(164, ng0);
    t2 = (t0 + 14415);
    t4 = (t0 + 7400);
    t6 = (t4 + 56U);
    t7 = *((char **)t6);
    t16 = (t7 + 56U);
    t17 = *((char **)t16);
    memcpy(t17, t2, 8U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(167, ng0);
    t2 = (t0 + 3448U);
    t3 = *((char **)t2);
    t29 = *((int64 *)t3);
    t30 = (1 * t29);
    t2 = (t0 + 6568);
    xsi_process_wait(t2, t30);

LAB15:    *((char **)t1) = &&LAB16;
    goto LAB1;

LAB6:    t2 = (t0 + 14391);
    t11 = *((int *)t2);
    t3 = (t0 + 14395);
    t12 = *((int *)t3);
    if (t11 == t12)
        goto LAB7;

LAB22:    t8 = (t11 + 1);
    t11 = t8;
    t4 = (t0 + 14391);
    *((int *)t4) = t11;
    goto LAB4;

LAB9:    xsi_set_current_line(147, ng0);
    t16 = (t0 + 6568);
    t17 = (t0 + 4976U);
    t18 = (t0 + 5568U);
    std_textio_readline(STD_TEXTIO, t16, t17, t18);
    xsi_set_current_line(148, ng0);
    t2 = (t0 + 6568);
    t3 = (t0 + 5080U);
    t4 = (t0 + 5640U);
    std_textio_readline(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(149, ng0);
    t2 = (t0 + 6568);
    t3 = (t0 + 5568U);
    t4 = (t0 + 3568U);
    t6 = *((char **)t4);
    t4 = (t6 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 6568);
    t3 = (t0 + 5640U);
    t4 = (t0 + 3688U);
    t6 = *((char **)t4);
    t4 = (t6 + 0);
    std_textio_read10(STD_TEXTIO, t2, t3, t4);
    xsi_set_current_line(152, ng0);
    t2 = (t0 + 3568U);
    t3 = *((char **)t2);
    t8 = *((int *)t3);
    t10 = (2 + 6);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t5, t8, t10);
    t4 = (t0 + 3808U);
    t6 = *((char **)t4);
    t4 = (t0 + 14399);
    t13 = *((int *)t4);
    t19 = (t13 + 1);
    t20 = (2 + 6);
    t21 = (t19 * t20);
    t22 = (t21 - 1);
    t9 = (7 - t22);
    t7 = (t0 + 14399);
    t23 = (2 + 6);
    t24 = *((int *)t7);
    t25 = (t24 * t23);
    xsi_vhdl_check_range_of_slice(7, 0, -1, t22, t25, -1);
    t26 = (t9 * 1U);
    t27 = (0 + t26);
    t16 = (t6 + t27);
    t17 = (t5 + 12U);
    t28 = *((unsigned int *)t17);
    t28 = (t28 * 1U);
    memcpy(t16, t2, t28);
    xsi_set_current_line(153, ng0);
    t2 = (t0 + 3688U);
    t3 = *((char **)t2);
    t8 = *((int *)t3);
    t10 = (2 + 6);
    t2 = ieee_p_1242562249_sub_2563015576_1035706684(IEEE_P_1242562249, t5, t8, t10);
    t4 = (t0 + 3928U);
    t6 = *((char **)t4);
    t4 = (t0 + 14399);
    t13 = *((int *)t4);
    t19 = (t13 + 1);
    t20 = (2 + 6);
    t21 = (t19 * t20);
    t22 = (t21 - 1);
    t9 = (7 - t22);
    t7 = (t0 + 14399);
    t23 = (2 + 6);
    t24 = *((int *)t7);
    t25 = (t24 * t23);
    xsi_vhdl_check_range_of_slice(7, 0, -1, t22, t25, -1);
    t26 = (t9 * 1U);
    t27 = (0 + t26);
    t16 = (t6 + t27);
    t17 = (t5 + 12U);
    t28 = *((unsigned int *)t17);
    t28 = (t28 * 1U);
    memcpy(t16, t2, t28);

LAB10:    t2 = (t0 + 14399);
    t14 = *((int *)t2);
    t3 = (t0 + 14403);
    t15 = *((int *)t3);
    if (t14 == t15)
        goto LAB11;

LAB12:    t8 = (t14 + 1);
    t14 = t8;
    t4 = (t0 + 14399);
    *((int *)t4) = t14;
    goto LAB8;

LAB13:    xsi_set_current_line(169, ng0);
    t8 = (1 - 1);
    t2 = (t0 + 14423);
    *((int *)t2) = 0;
    t3 = (t0 + 14427);
    *((int *)t3) = t8;
    t10 = 0;
    t13 = t8;

LAB17:    if (t10 <= t13)
        goto LAB18;

LAB20:    goto LAB6;

LAB14:    goto LAB13;

LAB16:    goto LAB14;

LAB18:    xsi_set_current_line(175, ng0);
    t4 = (t0 + 1992U);
    t6 = *((char **)t4);
    t4 = (t0 + 14423);
    t14 = *((int *)t4);
    t15 = (t14 + 1);
    t19 = (2 + 14);
    t20 = (t15 * t19);
    t21 = (t20 - 1);
    t9 = (15 - t21);
    t7 = (t0 + 14423);
    t22 = (2 + 14);
    t23 = *((int *)t7);
    t24 = (t23 * t22);
    xsi_vhdl_check_range_of_slice(15, 0, -1, t21, t24, -1);
    t26 = (t9 * 1U);
    t27 = (0 + t26);
    t16 = (t6 + t27);
    t17 = (t0 + 14423);
    t25 = *((int *)t17);
    t31 = (t25 + 1);
    t32 = (2 + 14);
    t33 = (t31 * t32);
    t34 = (t33 - 1);
    t18 = (t0 + 14423);
    t35 = (2 + 14);
    t36 = *((int *)t18);
    t37 = (t36 * t35);
    t38 = (t5 + 0U);
    t39 = (t38 + 0U);
    *((int *)t39) = t34;
    t39 = (t38 + 4U);
    *((int *)t39) = t37;
    t39 = (t38 + 8U);
    *((int *)t39) = -1;
    t40 = (t37 - t34);
    t28 = (t40 * -1);
    t28 = (t28 + 1);
    t39 = (t38 + 12U);
    *((unsigned int *)t39) = t28;
    t41 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t16, t5);
    t39 = (t0 + 4048U);
    t42 = *((char **)t39);
    t39 = (t42 + 0);
    *((int *)t39) = t41;
    xsi_set_current_line(177, ng0);
    t2 = (t0 + 6568);
    t3 = (t0 + 5712U);
    t4 = (t0 + 4048U);
    t6 = *((char **)t4);
    t8 = *((int *)t6);
    std_textio_write5(STD_TEXTIO, t2, t3, t8, (unsigned char)0, 0);
    xsi_set_current_line(178, ng0);
    t2 = (t0 + 6568);
    t3 = (t0 + 5184U);
    t4 = (t0 + 5712U);
    std_textio_writeline(STD_TEXTIO, t2, t3, t4);

LAB19:    t2 = (t0 + 14423);
    t10 = *((int *)t2);
    t3 = (t0 + 14427);
    t13 = *((int *)t3);
    if (t10 == t13)
        goto LAB20;

LAB21:    t8 = (t10 + 1);
    t10 = t8;
    t4 = (t0 + 14423);
    *((int *)t4) = t10;
    goto LAB17;

LAB23:    goto LAB2;

LAB24:    goto LAB23;

LAB26:    goto LAB24;

}


extern void work_a_2814885930_2372691052_init()
{
	static char *pe[] = {(void *)work_a_2814885930_2372691052_p_0,(void *)work_a_2814885930_2372691052_p_1};
	xsi_register_didat("work_a_2814885930_2372691052", "isim/ErrorTPhase_tb_isim_beh.exe.sim/work/a_2814885930_2372691052.didat");
	xsi_register_executes(pe);
}
