/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * See the file COPYING for license information.
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Nov 10 20:33:44 EST 2008 */

#include "codelet-dft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_notw_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name n1fv_20 -include n1f.h */

/*
 * This function contains 104 FP additions, 50 FP multiplications,
 * (or, 58 additions, 4 multiplications, 46 fused multiply/add),
 * 71 stack variables, 4 constants, and 40 memory accesses
 */
#include "n1f.h"

static void n1fv_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     INT i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V TU, TI, TP, TX, TM, TW, TT, TF;
	  {
	       V T3, Tm, T1r, T13, Ta, TN, TH, TA, TG, Tt, Th, TO, T1u, T1C, T1n;
	       V T1a, T1m, T1h, T1x, T1D, TE, Ti;
	       {
		    V T1, T2, Tk, Tl;
		    T1 = LD(&(xi[0]), ivs, &(xi[0]));
		    T2 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
		    Tk = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
		    Tl = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
		    {
			 V T14, T6, T1c, Tw, Tn, T1f, Tz, T17, T9, To, Tq, T1b, Td, Tr, Te;
			 V Tf, T15, Tp;
			 {
			      V Tx, Ty, T7, T8, Tb, Tc;
			      {
				   V T4, T5, Tu, Tv, T11, T12;
				   T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
				   T5 = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
				   Tu = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
				   Tv = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
				   Tx = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
				   T3 = VSUB(T1, T2);
				   T11 = VADD(T1, T2);
				   Tm = VSUB(Tk, Tl);
				   T12 = VADD(Tk, Tl);
				   T14 = VADD(T4, T5);
				   T6 = VSUB(T4, T5);
				   T1c = VADD(Tu, Tv);
				   Tw = VSUB(Tu, Tv);
				   Ty = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
				   T7 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
				   T8 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
				   T1r = VADD(T11, T12);
				   T13 = VSUB(T11, T12);
			      }
			      Tb = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
			      Tc = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
			      Tn = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
			      T1f = VADD(Tx, Ty);
			      Tz = VSUB(Tx, Ty);
			      T17 = VADD(T7, T8);
			      T9 = VSUB(T7, T8);
			      To = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
			      Tq = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
			      T1b = VADD(Tb, Tc);
			      Td = VSUB(Tb, Tc);
			      Tr = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
			      Te = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
			      Tf = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
			 }
			 Ta = VADD(T6, T9);
			 TN = VSUB(T6, T9);
			 T15 = VADD(Tn, To);
			 Tp = VSUB(Tn, To);
			 TH = VSUB(Tz, Tw);
			 TA = VADD(Tw, Tz);
			 {
			      V T1d, T1v, T18, Ts, T1e, Tg, T16, T1s;
			      T1d = VSUB(T1b, T1c);
			      T1v = VADD(T1b, T1c);
			      T18 = VADD(Tq, Tr);
			      Ts = VSUB(Tq, Tr);
			      T1e = VADD(Te, Tf);
			      Tg = VSUB(Te, Tf);
			      T16 = VSUB(T14, T15);
			      T1s = VADD(T14, T15);
			      {
				   V T1t, T19, T1w, T1g;
				   T1t = VADD(T17, T18);
				   T19 = VSUB(T17, T18);
				   TG = VSUB(Ts, Tp);
				   Tt = VADD(Tp, Ts);
				   T1w = VADD(T1e, T1f);
				   T1g = VSUB(T1e, T1f);
				   Th = VADD(Td, Tg);
				   TO = VSUB(Td, Tg);
				   T1u = VADD(T1s, T1t);
				   T1C = VSUB(T1s, T1t);
				   T1n = VSUB(T16, T19);
				   T1a = VADD(T16, T19);
				   T1m = VSUB(T1d, T1g);
				   T1h = VADD(T1d, T1g);
				   T1x = VADD(T1v, T1w);
				   T1D = VSUB(T1v, T1w);
			      }
			 }
		    }
	       }
	       TE = VSUB(Ta, Th);
	       Ti = VADD(Ta, Th);
	       {
		    V TL, T1k, T1A, Tj, TD, T1E, T1G, TK, TC, T1j, T1z, T1i, T1y, TB;
		    TL = VSUB(TA, Tt);
		    TB = VADD(Tt, TA);
		    T1i = VADD(T1a, T1h);
		    T1k = VSUB(T1a, T1h);
		    T1y = VADD(T1u, T1x);
		    T1A = VSUB(T1u, T1x);
		    Tj = VADD(T3, Ti);
		    TD = VFNMS(LDK(KP250000000), Ti, T3);
		    T1E = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1D, T1C));
		    T1G = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1C, T1D));
		    TK = VFNMS(LDK(KP250000000), TB, Tm);
		    TC = VADD(Tm, TB);
		    T1j = VFNMS(LDK(KP250000000), T1i, T13);
		    ST(&(xo[0]), VADD(T1r, T1y), ovs, &(xo[0]));
		    T1z = VFNMS(LDK(KP250000000), T1y, T1r);
		    ST(&(xo[WS(os, 10)]), VADD(T13, T1i), ovs, &(xo[0]));
		    {
			 V T1p, T1l, T1o, T1q, T1F, T1B;
			 TU = VFNMS(LDK(KP618033988), TG, TH);
			 TI = VFMA(LDK(KP618033988), TH, TG);
			 TP = VFMA(LDK(KP618033988), TO, TN);
			 TX = VFNMS(LDK(KP618033988), TN, TO);
			 ST(&(xo[WS(os, 15)]), VFMAI(TC, Tj), ovs, &(xo[WS(os, 1)]));
			 ST(&(xo[WS(os, 5)]), VFNMSI(TC, Tj), ovs, &(xo[WS(os, 1)]));
			 T1p = VFMA(LDK(KP559016994), T1k, T1j);
			 T1l = VFNMS(LDK(KP559016994), T1k, T1j);
			 T1o = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1n, T1m));
			 T1q = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1m, T1n));
			 T1F = VFNMS(LDK(KP559016994), T1A, T1z);
			 T1B = VFMA(LDK(KP559016994), T1A, T1z);
			 ST(&(xo[WS(os, 14)]), VFMAI(T1q, T1p), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 6)]), VFNMSI(T1q, T1p), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 18)]), VFNMSI(T1o, T1l), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 2)]), VFMAI(T1o, T1l), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 16)]), VFNMSI(T1E, T1B), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 4)]), VFMAI(T1E, T1B), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 12)]), VFMAI(T1G, T1F), ovs, &(xo[0]));
			 ST(&(xo[WS(os, 8)]), VFNMSI(T1G, T1F), ovs, &(xo[0]));
			 TM = VFNMS(LDK(KP559016994), TL, TK);
			 TW = VFMA(LDK(KP559016994), TL, TK);
			 TT = VFNMS(LDK(KP559016994), TE, TD);
			 TF = VFMA(LDK(KP559016994), TE, TD);
		    }
	       }
	  }
	  {
	       V T10, TY, TQ, TS, TJ, TR, TZ, TV;
	       T10 = VFMA(LDK(KP951056516), TX, TW);
	       TY = VFNMS(LDK(KP951056516), TX, TW);
	       TQ = VFMA(LDK(KP951056516), TP, TM);
	       TS = VFNMS(LDK(KP951056516), TP, TM);
	       TJ = VFMA(LDK(KP951056516), TI, TF);
	       TR = VFNMS(LDK(KP951056516), TI, TF);
	       TZ = VFMA(LDK(KP951056516), TU, TT);
	       TV = VFNMS(LDK(KP951056516), TU, TT);
	       ST(&(xo[WS(os, 11)]), VFMAI(TS, TR), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 9)]), VFNMSI(TS, TR), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 19)]), VFMAI(TQ, TJ), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 1)]), VFNMSI(TQ, TJ), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 3)]), VFMAI(TY, TV), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 17)]), VFNMSI(TY, TV), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 7)]), VFMAI(T10, TZ), ovs, &(xo[WS(os, 1)]));
	       ST(&(xo[WS(os, 13)]), VFNMSI(T10, TZ), ovs, &(xo[WS(os, 1)]));
	  }
     }
}

static const kdft_desc desc = { 20, "n1fv_20", {58, 4, 46, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_n1fv_20) (planner *p) {
     X(kdft_register) (p, n1fv_20, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_notw_c -simd -compact -variables 4 -pipeline-latency 8 -n 20 -name n1fv_20 -include n1f.h */

/*
 * This function contains 104 FP additions, 24 FP multiplications,
 * (or, 92 additions, 12 multiplications, 12 fused multiply/add),
 * 53 stack variables, 4 constants, and 40 memory accesses
 */
#include "n1f.h"

static void n1fv_20(const R *ri, const R *ii, R *ro, R *io, stride is, stride os, INT v, INT ivs, INT ovs)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     INT i;
     const R *xi;
     R *xo;
     xi = ri;
     xo = ro;
     for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs), MAKE_VOLATILE_STRIDE(is), MAKE_VOLATILE_STRIDE(os)) {
	  V T3, T1B, Tm, T1i, TG, TN, TO, TH, T13, T16, T1k, T1u, T1v, T1z, T1r;
	  V T1s, T1y, T1a, T1d, T1j, Ti, TD, TB, TL, Tj, TC;
	  {
	       V T1, T2, T1g, Tk, Tl, T1h;
	       T1 = LD(&(xi[0]), ivs, &(xi[0]));
	       T2 = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
	       T1g = VADD(T1, T2);
	       Tk = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
	       Tl = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
	       T1h = VADD(Tk, Tl);
	       T3 = VSUB(T1, T2);
	       T1B = VADD(T1g, T1h);
	       Tm = VSUB(Tk, Tl);
	       T1i = VSUB(T1g, T1h);
	  }
	  {
	       V T6, T18, Tw, T12, Tz, T15, T9, T1b, Td, T11, Tp, T19, Ts, T1c, Tg;
	       V T14;
	       {
		    V T4, T5, Tu, Tv;
		    T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
		    T5 = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
		    T6 = VSUB(T4, T5);
		    T18 = VADD(T4, T5);
		    Tu = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
		    Tv = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
		    Tw = VSUB(Tu, Tv);
		    T12 = VADD(Tu, Tv);
	       }
	       {
		    V Tx, Ty, T7, T8;
		    Tx = LD(&(xi[WS(is, 17)]), ivs, &(xi[WS(is, 1)]));
		    Ty = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
		    Tz = VSUB(Tx, Ty);
		    T15 = VADD(Tx, Ty);
		    T7 = LD(&(xi[WS(is, 16)]), ivs, &(xi[0]));
		    T8 = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
		    T9 = VSUB(T7, T8);
		    T1b = VADD(T7, T8);
	       }
	       {
		    V Tb, Tc, Tn, To;
		    Tb = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
		    Tc = LD(&(xi[WS(is, 18)]), ivs, &(xi[0]));
		    Td = VSUB(Tb, Tc);
		    T11 = VADD(Tb, Tc);
		    Tn = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
		    To = LD(&(xi[WS(is, 19)]), ivs, &(xi[WS(is, 1)]));
		    Tp = VSUB(Tn, To);
		    T19 = VADD(Tn, To);
	       }
	       {
		    V Tq, Tr, Te, Tf;
		    Tq = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
		    Tr = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
		    Ts = VSUB(Tq, Tr);
		    T1c = VADD(Tq, Tr);
		    Te = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
		    Tf = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
		    Tg = VSUB(Te, Tf);
		    T14 = VADD(Te, Tf);
	       }
	       TG = VSUB(Ts, Tp);
	       TN = VSUB(T6, T9);
	       TO = VSUB(Td, Tg);
	       TH = VSUB(Tz, Tw);
	       T13 = VSUB(T11, T12);
	       T16 = VSUB(T14, T15);
	       T1k = VADD(T13, T16);
	       T1u = VADD(T11, T12);
	       T1v = VADD(T14, T15);
	       T1z = VADD(T1u, T1v);
	       T1r = VADD(T18, T19);
	       T1s = VADD(T1b, T1c);
	       T1y = VADD(T1r, T1s);
	       T1a = VSUB(T18, T19);
	       T1d = VSUB(T1b, T1c);
	       T1j = VADD(T1a, T1d);
	       {
		    V Ta, Th, Tt, TA;
		    Ta = VADD(T6, T9);
		    Th = VADD(Td, Tg);
		    Ti = VADD(Ta, Th);
		    TD = VMUL(LDK(KP559016994), VSUB(Ta, Th));
		    Tt = VADD(Tp, Ts);
		    TA = VADD(Tw, Tz);
		    TB = VADD(Tt, TA);
		    TL = VMUL(LDK(KP559016994), VSUB(TA, Tt));
	       }
	  }
	  Tj = VADD(T3, Ti);
	  TC = VBYI(VADD(Tm, TB));
	  ST(&(xo[WS(os, 5)]), VSUB(Tj, TC), ovs, &(xo[WS(os, 1)]));
	  ST(&(xo[WS(os, 15)]), VADD(Tj, TC), ovs, &(xo[WS(os, 1)]));
	  {
	       V T1A, T1C, T1D, T1x, T1G, T1t, T1w, T1F, T1E;
	       T1A = VMUL(LDK(KP559016994), VSUB(T1y, T1z));
	       T1C = VADD(T1y, T1z);
	       T1D = VFNMS(LDK(KP250000000), T1C, T1B);
	       T1t = VSUB(T1r, T1s);
	       T1w = VSUB(T1u, T1v);
	       T1x = VBYI(VFMA(LDK(KP951056516), T1t, VMUL(LDK(KP587785252), T1w)));
	       T1G = VBYI(VFNMS(LDK(KP587785252), T1t, VMUL(LDK(KP951056516), T1w)));
	       ST(&(xo[0]), VADD(T1B, T1C), ovs, &(xo[0]));
	       T1F = VSUB(T1D, T1A);
	       ST(&(xo[WS(os, 8)]), VSUB(T1F, T1G), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 12)]), VADD(T1G, T1F), ovs, &(xo[0]));
	       T1E = VADD(T1A, T1D);
	       ST(&(xo[WS(os, 4)]), VADD(T1x, T1E), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 16)]), VSUB(T1E, T1x), ovs, &(xo[0]));
	  }
	  {
	       V T1n, T1l, T1m, T1f, T1q, T17, T1e, T1p, T1o;
	       T1n = VMUL(LDK(KP559016994), VSUB(T1j, T1k));
	       T1l = VADD(T1j, T1k);
	       T1m = VFNMS(LDK(KP250000000), T1l, T1i);
	       T17 = VSUB(T13, T16);
	       T1e = VSUB(T1a, T1d);
	       T1f = VBYI(VFNMS(LDK(KP587785252), T1e, VMUL(LDK(KP951056516), T17)));
	       T1q = VBYI(VFMA(LDK(KP951056516), T1e, VMUL(LDK(KP587785252), T17)));
	       ST(&(xo[WS(os, 10)]), VADD(T1i, T1l), ovs, &(xo[0]));
	       T1p = VADD(T1n, T1m);
	       ST(&(xo[WS(os, 6)]), VSUB(T1p, T1q), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 14)]), VADD(T1q, T1p), ovs, &(xo[0]));
	       T1o = VSUB(T1m, T1n);
	       ST(&(xo[WS(os, 2)]), VADD(T1f, T1o), ovs, &(xo[0]));
	       ST(&(xo[WS(os, 18)]), VSUB(T1o, T1f), ovs, &(xo[0]));
	  }
	  {
	       V TI, TP, TX, TU, TM, TW, TF, TT, TK, TE;
	       TI = VFMA(LDK(KP951056516), TG, VMUL(LDK(KP587785252), TH));
	       TP = VFMA(LDK(KP951056516), TN, VMUL(LDK(KP587785252), TO));
	       TX = VFNMS(LDK(KP587785252), TN, VMUL(LDK(KP951056516), TO));
	       TU = VFNMS(LDK(KP587785252), TG, VMUL(LDK(KP951056516), TH));
	       TK = VFMS(LDK(KP250000000), TB, Tm);
	       TM = VADD(TK, TL);
	       TW = VSUB(TL, TK);
	       TE = VFNMS(LDK(KP250000000), Ti, T3);
	       TF = VADD(TD, TE);
	       TT = VSUB(TE, TD);
	       {
		    V TJ, TQ, TZ, T10;
		    TJ = VADD(TF, TI);
		    TQ = VBYI(VSUB(TM, TP));
		    ST(&(xo[WS(os, 19)]), VSUB(TJ, TQ), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 1)]), VADD(TJ, TQ), ovs, &(xo[WS(os, 1)]));
		    TZ = VADD(TT, TU);
		    T10 = VBYI(VADD(TX, TW));
		    ST(&(xo[WS(os, 13)]), VSUB(TZ, T10), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 7)]), VADD(TZ, T10), ovs, &(xo[WS(os, 1)]));
	       }
	       {
		    V TR, TS, TV, TY;
		    TR = VSUB(TF, TI);
		    TS = VBYI(VADD(TP, TM));
		    ST(&(xo[WS(os, 11)]), VSUB(TR, TS), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 9)]), VADD(TR, TS), ovs, &(xo[WS(os, 1)]));
		    TV = VSUB(TT, TU);
		    TY = VBYI(VSUB(TW, TX));
		    ST(&(xo[WS(os, 17)]), VSUB(TV, TY), ovs, &(xo[WS(os, 1)]));
		    ST(&(xo[WS(os, 3)]), VADD(TV, TY), ovs, &(xo[WS(os, 1)]));
	       }
	  }
     }
}

static const kdft_desc desc = { 20, "n1fv_20", {92, 12, 12, 0}, &GENUS, 0, 0, 0, 0 };
void X(codelet_n1fv_20) (planner *p) {
     X(kdft_register) (p, n1fv_20, &desc);
}

#endif				/* HAVE_FMA */