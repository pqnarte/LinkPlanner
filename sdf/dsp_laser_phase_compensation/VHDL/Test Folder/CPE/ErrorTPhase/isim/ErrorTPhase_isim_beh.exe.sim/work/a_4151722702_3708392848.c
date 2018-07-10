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


static void work_a_4151722702_3708392848_p_0(char *t0)
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
    char *t29;
    char *t30;
    char *t31;

LAB0:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1672U);
    t2 = *((char **)t1);
    t1 = (t0 + 7260);
    t4 = xsi_mem_cmp(t1, t2, 2U);
    if (t4 == 1)
        goto LAB3;

LAB8:    t5 = (t0 + 7262);
    t7 = xsi_mem_cmp(t5, t2, 2U);
    if (t7 == 1)
        goto LAB4;

LAB9:    t8 = (t0 + 7264);
    t10 = xsi_mem_cmp(t8, t2, 2U);
    if (t10 == 1)
        goto LAB5;

LAB10:    t11 = (t0 + 7266);
    t13 = xsi_mem_cmp(t11, t2, 2U);
    if (t13 == 1)
        goto LAB6;

LAB11:
LAB7:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 7332);
    t3 = (t0 + 4296);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t3);

LAB2:    t1 = (t0 + 4200);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(48, ng0);
    t15 = (t0 + 1352U);
    t16 = *((char **)t15);
    t15 = (t0 + 7120U);
    t17 = ((WORK_P_0335708415) + 1888U);
    t18 = *((char **)t17);
    t17 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t16, t15, t18, t17);
    if (t19 == 1)
        goto LAB16;

LAB17:    t14 = (unsigned char)0;

LAB18:    if (t14 != 0)
        goto LAB13;

LAB15:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 1888U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB21;

LAB22:    t14 = (unsigned char)0;

LAB23:    if (t14 != 0)
        goto LAB19;

LAB20:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 1888U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB26;

LAB27:    t14 = (unsigned char)0;

LAB28:    if (t14 != 0)
        goto LAB24;

LAB25:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 7280);
    t3 = (t0 + 4296);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t3);

LAB14:    goto LAB2;

LAB4:    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 1888U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB32;

LAB33:    t14 = (unsigned char)0;

LAB34:    if (t14 != 0)
        goto LAB29;

LAB31:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 1888U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB37;

LAB38:    t14 = (unsigned char)0;

LAB39:    if (t14 != 0)
        goto LAB35;

LAB36:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 1888U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8024U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB42;

LAB43:    t14 = (unsigned char)0;

LAB44:    if (t14 != 0)
        goto LAB40;

LAB41:    xsi_set_current_line(65, ng0);
    t1 = (t0 + 7296);
    t3 = (t0 + 4296);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t3);

LAB30:    goto LAB2;

LAB5:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB48;

LAB49:    t14 = (unsigned char)0;

LAB50:    if (t14 != 0)
        goto LAB45;

LAB47:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB53;

LAB54:    t14 = (unsigned char)0;

LAB55:    if (t14 != 0)
        goto LAB51;

LAB52:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB58;

LAB59:    t14 = (unsigned char)0;

LAB60:    if (t14 != 0)
        goto LAB56;

LAB57:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 7312);
    t3 = (t0 + 4296);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t3);

LAB46:    goto LAB2;

LAB6:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB64;

LAB65:    t14 = (unsigned char)0;

LAB66:    if (t14 != 0)
        goto LAB61;

LAB63:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB69;

LAB70:    t14 = (unsigned char)0;

LAB71:    if (t14 != 0)
        goto LAB67;

LAB68:    t1 = (t0 + 1352U);
    t2 = *((char **)t1);
    t1 = (t0 + 7120U);
    t3 = ((WORK_P_0335708415) + 2128U);
    t5 = *((char **)t3);
    t3 = ((WORK_P_0335708415) + 8056U);
    t19 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t2, t1, t5, t3);
    if (t19 == 1)
        goto LAB74;

LAB75:    t14 = (unsigned char)0;

LAB76:    if (t14 != 0)
        goto LAB72;

LAB73:    xsi_set_current_line(85, ng0);
    t1 = (t0 + 7328);
    t3 = (t0 + 4296);
    t5 = (t3 + 56U);
    t6 = *((char **)t5);
    t8 = (t6 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 4U);
    xsi_driver_first_trans_fast(t3);

LAB62:    goto LAB2;

LAB12:;
LAB13:    xsi_set_current_line(49, ng0);
    t25 = (t0 + 7268);
    t27 = (t0 + 4296);
    t28 = (t27 + 56U);
    t29 = *((char **)t28);
    t30 = (t29 + 56U);
    t31 = *((char **)t30);
    memcpy(t31, t25, 4U);
    xsi_driver_first_trans_fast(t27);
    goto LAB14;

LAB16:    t20 = (t0 + 1512U);
    t21 = *((char **)t20);
    t20 = (t0 + 7136U);
    t22 = ((WORK_P_0335708415) + 2008U);
    t23 = *((char **)t22);
    t22 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t21, t20, t23, t22);
    t14 = t24;
    goto LAB18;

LAB19:    xsi_set_current_line(51, ng0);
    t12 = (t0 + 7272);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB14;

LAB21:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2008U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB23;

LAB24:    xsi_set_current_line(53, ng0);
    t12 = (t0 + 7276);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB14;

LAB26:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2008U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB28;

LAB29:    xsi_set_current_line(59, ng0);
    t12 = (t0 + 7284);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB30;

LAB32:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB34;

LAB35:    xsi_set_current_line(61, ng0);
    t12 = (t0 + 7288);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB30;

LAB37:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB39;

LAB40:    xsi_set_current_line(63, ng0);
    t12 = (t0 + 7292);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB30;

LAB42:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB44;

LAB45:    xsi_set_current_line(69, ng0);
    t12 = (t0 + 7300);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB46;

LAB48:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB50;

LAB51:    xsi_set_current_line(71, ng0);
    t12 = (t0 + 7304);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB46;

LAB53:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB55;

LAB56:    xsi_set_current_line(73, ng0);
    t12 = (t0 + 7308);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB46;

LAB58:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2248U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8072U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB60;

LAB61:    xsi_set_current_line(79, ng0);
    t12 = (t0 + 7316);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB62;

LAB64:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2008U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB66;

LAB67:    xsi_set_current_line(81, ng0);
    t12 = (t0 + 7320);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB62;

LAB69:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2008U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_2698860368_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB71;

LAB72:    xsi_set_current_line(83, ng0);
    t12 = (t0 + 7324);
    t16 = (t0 + 4296);
    t17 = (t16 + 56U);
    t18 = *((char **)t17);
    t20 = (t18 + 56U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 4U);
    xsi_driver_first_trans_fast(t16);
    goto LAB62;

LAB74:    t6 = (t0 + 1512U);
    t8 = *((char **)t6);
    t6 = (t0 + 7136U);
    t9 = ((WORK_P_0335708415) + 2008U);
    t11 = *((char **)t9);
    t9 = ((WORK_P_0335708415) + 8040U);
    t24 = ieee_p_0774719531_sub_1742983514_2162500114(IEEE_P_0774719531, t8, t6, t11, t9);
    t14 = t24;
    goto LAB76;

}

static void work_a_4151722702_3708392848_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(94, ng0);

LAB3:    t1 = (t0 + 1992U);
    t2 = *((char **)t1);
    t1 = (t0 + 4360);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 4216);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_4151722702_3708392848_init()
{
	static char *pe[] = {(void *)work_a_4151722702_3708392848_p_0,(void *)work_a_4151722702_3708392848_p_1};
	xsi_register_didat("work_a_4151722702_3708392848", "isim/ErrorTPhase_isim_beh.exe.sim/work/a_4151722702_3708392848.didat");
	xsi_register_executes(pe);
}
