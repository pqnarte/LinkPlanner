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
static const char *ng0 = "C:/Users/csmartins/Dropbox/_PhD/MyWorks/VHDL/Test Folder/CPE/ErrorTPhasev2.vhd";



static void work_a_0798703736_3708392848_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(244, ng0);

LAB3:    t1 = (t0 + 3160U);
    t2 = *((char **)t1);
    t1 = (t0 + 6120);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 2U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 6040);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0798703736_3708392848_init()
{
	static char *pe[] = {(void *)work_a_0798703736_3708392848_p_0};
	xsi_register_didat("work_a_0798703736_3708392848", "isim/CpeBPS_tb_isim_beh.exe.sim/work/a_0798703736_3708392848.didat");
	xsi_register_executes(pe);
}
