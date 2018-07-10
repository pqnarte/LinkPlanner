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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/SymbolSelection.vhd";
extern char *IEEE_P_0774719531;
extern char *WORK_P_0335708415;

unsigned char ieee_p_0774719531_sub_1742983514_2162500114(char *, char *, char *, char *, char *);
unsigned char ieee_p_0774719531_sub_2698860368_2162500114(char *, char *, char *, char *, char *);


static void work_a_2907929106_3708392848_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    unsigned char t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    unsigned char t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;
    unsigned char t24;
    char *t25;
    char *t27;
    char *t28;

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 6784);
    t4 = xsi_mem_cmp(t1, t2, 2U);
    if (t4 == 1)
        goto LAB3;

LAB8:    t5 = (t0 + 6786);
    t7 = xsi_mem_cmp(t5, t2, 2U);
    if (t7 == 1)
        goto LAB4;

LAB9:    t8 = (t0 + 6788);
    t10 = xsi_mem_cmp(t8, t2, 2U);
    if (t10 == 1)
        goto LAB5;

LAB10:    t11 = (t0 + 6790);
    t13 = xsi_mem_cmp(t11, t2, 2U);
    if (t13 == 1)
        goto LAB6;

LAB11:
LAB7:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 6856);
    t3 = (t0 + 2608U);
    t5 = *((char **)t3);
    t3 = (t5 + 0);
    memcpy(t3, t1, 4U);

LAB2:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 2608U);
    t2 = *((char **)t1);
    t1 = (t0 + 3992);
    t3 = (t1 + 56U);
    t5 = *((char **)t3);
    t6 = (t5 + 56U);
    t8 = *((char **)t6);
    memcpy(t8, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);
    t1 = (t0 + 3912);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(45, ng0);
    t15 = (t0 + 1352U);
    t16 = *((char **)t15);
    t15 = (t0 + 6656U);
    t17 = ((WORK_P_0335708415) + 1288U);
    t18 = *((char **)t17);
    t17 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t16, t15, t18, t17);
    if (t19 == 1)
        goto LAB16;

LAB17:    t14 = (unsigned char)0;

LAB18:    if (t14 != 0)
        goto LAB13;

LAB15:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1288U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB21;

LAB22:    t14 = (unsigned char)0;

LAB23:    if (t14 != 0)
        goto LAB19;

LAB20:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1288U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB26;

LAB27:    t14 = (unsigned char)0;

LAB28:    if (t14 != 0)
        goto LAB24;

LAB25:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 6804);
    t3 = (t0 + 2608U);
    t5 = *((char **)t3);
    t3 = (t5 + 0);
    memcpy(t3, t1, 4U);

LAB14:    goto LAB2;

LAB4:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1288U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB32;

LAB33:    t14 = (unsigned char)0;

LAB34:    if (t14 != 0)
        goto LAB29;

LAB31:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1288U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB37;

LAB38:    t14 = (unsigned char)0;

LAB39:    if (t14 != 0)
        goto LAB35;

LAB36:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1288U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4476U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB42;

LAB43:    t14 = (unsigned char)0;

LAB44:    if (t14 != 0)
        goto LAB40;

LAB41:    xsi_set_current_line(62, ng0);
    t1 = (t0 + 6820);
    t3 = (t0 + 2608U);
    t5 = *((char **)t3);
    t3 = (t5 + 0);
    memcpy(t3, t1, 4U);

LAB30:    goto LAB2;

LAB5:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB48;

LAB49:    t14 = (unsigned char)0;

LAB50:    if (t14 != 0)
        goto LAB45;

LAB47:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB53;

LAB54:    t14 = (unsigned char)0;

LAB55:    if (t14 != 0)
        goto LAB51;

LAB52:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB58;

LAB59:    t14 = (unsigned char)0;

LAB60:    if (t14 != 0)
        goto LAB56;

LAB57:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 6836);
    t3 = (t0 + 2608U);
    t5 = *((char **)t3);
    t3 = (t5 + 0);
    memcpy(t3, t1, 4U);

LAB46:    goto LAB2;

LAB6:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB64;

LAB65:    t14 = (unsigned char)0;

LAB66:    if (t14 != 0)
        goto LAB61;

LAB63:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB69;

LAB70:    t14 = (unsigned char)0;

LAB71:    if (t14 != 0)
        goto LAB67;

LAB68:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 6656U);
    t3 = ((WORK_P_0335708415) + 1528U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 4508U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB74;

LAB75:    t14 = (unsigned char)0;

LAB76:    if (t14 != 0)
        goto LAB72;

LAB73:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 6852);
    t3 = (t0 + 2608U);
    t5 = *((char **)t3);
    t3 = (t5 + 0);
    memcpy(t3, t1, 4U);

LAB62:    goto LAB2;

LAB12:;
LAB13:    xsi_set_current_line(46, ng0);
    t25 = (t0 + 6792);
    t27 = (t0 + 2608U);
    t28 = *((char **)t27);
    t27 = (t28 + 0);
    memcpy(t27, t25, 4U);
    goto LAB14;

LAB16:    t20 = (t0 + 1512U);
    t21 = *((char **)t20);
    t20 = (t0 + 6672U);
    t22 = ((WORK_P_0335708415) + 1408U);
    t23 = *((char **)t22);
    t22 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t21, t20, t23, t22);
    t14 = t24;
    goto LAB18;

LAB19:    xsi_set_current_line(48, ng0);
    t12 = (t0 + 6796);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB14;

LAB21:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1408U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB23;

LAB24:    xsi_set_current_line(50, ng0);
    t12 = (t0 + 6800);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB14;

LAB26:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1408U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB28;

LAB29:    xsi_set_current_line(56, ng0);
    t12 = (t0 + 6808);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB30;

LAB32:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB34;

LAB35:    xsi_set_current_line(58, ng0);
    t12 = (t0 + 6812);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB30;

LAB37:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB39;

LAB40:    xsi_set_current_line(60, ng0);
    t12 = (t0 + 6816);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB30;

LAB42:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB44;

LAB45:    xsi_set_current_line(66, ng0);
    t12 = (t0 + 6824);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB46;

LAB48:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB50;

LAB51:    xsi_set_current_line(68, ng0);
    t12 = (t0 + 6828);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB46;

LAB53:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB55;

LAB56:    xsi_set_current_line(70, ng0);
    t12 = (t0 + 6832);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB46;

LAB58:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1648U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4524U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB60;

LAB61:    xsi_set_current_line(76, ng0);
    t12 = (t0 + 6840);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB62;

LAB64:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1408U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB66;

LAB67:    xsi_set_current_line(78, ng0);
    t12 = (t0 + 6844);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB62;

LAB69:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1408U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB71;

LAB72:    xsi_set_current_line(80, ng0);
    t12 = (t0 + 6848);
    t16 = (t0 + 2608U);
    t17 = *((char **)t16);
    t16 = (t17 + 0);
    memcpy(t16, t12, 4U);
    goto LAB62;

LAB74:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 6672U);
    t9 = ((WORK_P_0335708415) + 1408U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 4492U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB76;

}


extern void work_a_2907929106_3708392848_init()
{
	static char *pe[] = {(void *)work_a_2907929106_3708392848_p_0};
	xsi_register_didat("work_a_2907929106_3708392848", "isim/DecisionCircuit16QAM_tb_isim_beh.exe.sim/work/a_2907929106_3708392848.didat");
	xsi_register_executes(pe);
}
