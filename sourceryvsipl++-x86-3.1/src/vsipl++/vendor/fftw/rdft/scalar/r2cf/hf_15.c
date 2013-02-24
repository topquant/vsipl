/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * See the file COPYING for license information.
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Nov 10 20:45:57 EST 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2hc -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -n 15 -dit -name hf_15 -include hf.h */

/*
 * This function contains 184 FP additions, 140 FP multiplications,
 * (or, 72 additions, 28 multiplications, 112 fused multiply/add),
 * 97 stack variables, 6 constants, and 60 memory accesses
 */
#include "hf.h"

static void hf_15(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 28); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 28, MAKE_VOLATILE_STRIDE(rs)) {
	  E T3v, T3E, T3G, T3A, T3y, T3z, T3F, T3B;
	  {
	       E T1G, T3l, T3H, T3k, T1B, Tf, T37, T1y, T2Y, T2M, T2a, T2i, T39, Tz, T2U;
	       E T2t, T1O, T2e, T3a, TT, T10, T2V, T2z, T1V, T2f, T2C, T12, T15, T14, T21;
	       E T1c, T1Y, T13;
	       {
		    E T2I, T1k, T1m, T1p, T1o, T28, T1w, T25, T1n;
		    {
			 E T1, T3i, T9, Tc, Tb, T1D, T7, T1E, Ta, T1j, T1i, T1h;
			 T1 = cr[0];
			 T3i = ci[0];
			 {
			      E T3, T6, T2, T5, T1C, T4, T8;
			      T3 = cr[WS(rs, 5)];
			      T6 = ci[WS(rs, 5)];
			      T2 = W[8];
			      T5 = W[9];
			      T9 = cr[WS(rs, 10)];
			      Tc = ci[WS(rs, 10)];
			      T1C = T2 * T6;
			      T4 = T2 * T3;
			      T8 = W[18];
			      Tb = W[19];
			      T1D = FNMS(T5, T3, T1C);
			      T7 = FMA(T5, T6, T4);
			      T1E = T8 * Tc;
			      Ta = T8 * T9;
			 }
			 {
			      E T1g, T1F, Td, T1f, T3j, Te, T2H;
			      T1g = cr[WS(rs, 9)];
			      T1j = ci[WS(rs, 9)];
			      T1F = FNMS(Tb, T9, T1E);
			      Td = FMA(Tb, Tc, Ta);
			      T1f = W[16];
			      T1i = W[17];
			      T1G = T1D - T1F;
			      T3j = T1D + T1F;
			      T3l = Td - T7;
			      Te = T7 + Td;
			      T2H = T1f * T1j;
			      T1h = T1f * T1g;
			      T3H = T3j + T3i;
			      T3k = FNMS(KP500000000, T3j, T3i);
			      T1B = FNMS(KP500000000, Te, T1);
			      Tf = T1 + Te;
			      T2I = FNMS(T1i, T1g, T2H);
			 }
			 T1k = FMA(T1i, T1j, T1h);
			 {
			      E T1s, T1v, T1r, T1u, T27, T1t, T1l;
			      T1s = cr[WS(rs, 4)];
			      T1v = ci[WS(rs, 4)];
			      T1r = W[6];
			      T1u = W[7];
			      T1m = cr[WS(rs, 14)];
			      T1p = ci[WS(rs, 14)];
			      T27 = T1r * T1v;
			      T1t = T1r * T1s;
			      T1l = W[26];
			      T1o = W[27];
			      T28 = FNMS(T1u, T1s, T27);
			      T1w = FMA(T1u, T1v, T1t);
			      T25 = T1l * T1p;
			      T1n = T1l * T1m;
			 }
		    }
		    {
			 E Tl, T2p, Tn, Tq, Tp, T1M, Tx, T1J, To;
			 {
			      E Th, Tk, T26, T1q, Tg, Tj;
			      Th = cr[WS(rs, 3)];
			      Tk = ci[WS(rs, 3)];
			      T26 = FNMS(T1o, T1m, T25);
			      T1q = FMA(T1o, T1p, T1n);
			      Tg = W[4];
			      Tj = W[5];
			      {
				   E T29, T2J, T1x, T2L;
				   T29 = T26 - T28;
				   T2J = T26 + T28;
				   T1x = T1q + T1w;
				   T2L = T1q - T1w;
				   {
					E T2o, Ti, T2K, T24;
					T2o = Tg * Tk;
					Ti = Tg * Th;
					T2K = FNMS(KP500000000, T2J, T2I);
					T37 = T2I + T2J;
					T24 = FNMS(KP500000000, T1x, T1k);
					T1y = T1k + T1x;
					Tl = FMA(Tj, Tk, Ti);
					T2Y = FMA(KP866025403, T2L, T2K);
					T2M = FNMS(KP866025403, T2L, T2K);
					T2a = FNMS(KP866025403, T29, T24);
					T2i = FMA(KP866025403, T29, T24);
					T2p = FNMS(Tj, Th, T2o);
				   }
			      }
			 }
			 {
			      E Tt, Tw, Ts, Tv, T1L, Tu, Tm;
			      Tt = cr[WS(rs, 13)];
			      Tw = ci[WS(rs, 13)];
			      Ts = W[24];
			      Tv = W[25];
			      Tn = cr[WS(rs, 8)];
			      Tq = ci[WS(rs, 8)];
			      T1L = Ts * Tw;
			      Tu = Ts * Tt;
			      Tm = W[14];
			      Tp = W[15];
			      T1M = FNMS(Tv, Tt, T1L);
			      Tx = FMA(Tv, Tw, Tu);
			      T1J = Tm * Tq;
			      To = Tm * Tn;
			 }
			 {
			      E TF, T2v, TH, TK, TJ, T1T, TR, T1Q, TI;
			      {
				   E TB, TE, T1K, Tr, TA, TD;
				   TB = cr[WS(rs, 12)];
				   TE = ci[WS(rs, 12)];
				   T1K = FNMS(Tp, Tn, T1J);
				   Tr = FMA(Tp, Tq, To);
				   TA = W[22];
				   TD = W[23];
				   {
					E T1N, T2q, Ty, T2s;
					T1N = T1K - T1M;
					T2q = T1K + T1M;
					Ty = Tr + Tx;
					T2s = Tr - Tx;
					{
					     E T2u, TC, T2r, T1I;
					     T2u = TA * TE;
					     TC = TA * TB;
					     T2r = FNMS(KP500000000, T2q, T2p);
					     T39 = T2p + T2q;
					     T1I = FNMS(KP500000000, Ty, Tl);
					     Tz = Tl + Ty;
					     TF = FMA(TD, TE, TC);
					     T2U = FMA(KP866025403, T2s, T2r);
					     T2t = FNMS(KP866025403, T2s, T2r);
					     T1O = FNMS(KP866025403, T1N, T1I);
					     T2e = FMA(KP866025403, T1N, T1I);
					     T2v = FNMS(TD, TB, T2u);
					}
				   }
			      }
			      {
				   E TN, TQ, TM, TP, T1S, TO, TG;
				   TN = cr[WS(rs, 7)];
				   TQ = ci[WS(rs, 7)];
				   TM = W[12];
				   TP = W[13];
				   TH = cr[WS(rs, 2)];
				   TK = ci[WS(rs, 2)];
				   T1S = TM * TQ;
				   TO = TM * TN;
				   TG = W[2];
				   TJ = W[3];
				   T1T = FNMS(TP, TN, T1S);
				   TR = FMA(TP, TQ, TO);
				   T1Q = TG * TK;
				   TI = TG * TH;
			      }
			      {
				   E TW, TZ, T1R, TL, TV, TY;
				   TW = cr[WS(rs, 6)];
				   TZ = ci[WS(rs, 6)];
				   T1R = FNMS(TJ, TH, T1Q);
				   TL = FMA(TJ, TK, TI);
				   TV = W[10];
				   TY = W[11];
				   {
					E T1U, T2w, TS, T2y;
					T1U = T1R - T1T;
					T2w = T1R + T1T;
					TS = TL + TR;
					T2y = TL - TR;
					{
					     E T2B, TX, T2x, T1P;
					     T2B = TV * TZ;
					     TX = TV * TW;
					     T2x = FNMS(KP500000000, T2w, T2v);
					     T3a = T2v + T2w;
					     T1P = FNMS(KP500000000, TS, TF);
					     TT = TF + TS;
					     T10 = FMA(TY, TZ, TX);
					     T2V = FMA(KP866025403, T2y, T2x);
					     T2z = FNMS(KP866025403, T2y, T2x);
					     T1V = FNMS(KP866025403, T1U, T1P);
					     T2f = FMA(KP866025403, T1U, T1P);
					     T2C = FNMS(TY, TW, T2B);
					}
				   }
			      }
			      {
				   E T18, T1b, T17, T1a, T20, T19, T11;
				   T18 = cr[WS(rs, 1)];
				   T1b = ci[WS(rs, 1)];
				   T17 = W[0];
				   T1a = W[1];
				   T12 = cr[WS(rs, 11)];
				   T15 = ci[WS(rs, 11)];
				   T20 = T17 * T1b;
				   T19 = T17 * T18;
				   T11 = W[20];
				   T14 = W[21];
				   T21 = FNMS(T1a, T18, T20);
				   T1c = FMA(T1a, T1b, T19);
				   T1Y = T11 * T15;
				   T13 = T11 * T12;
			      }
			 }
		    }
	       }
	       {
		    E T3I, T3O, T3w, T2d, T3J, T3P, T3x, T3C, T3D, T3f, T3g, T2Q, T2O, T3r, T3q;
		    E T2k, T2m;
		    {
			 E T3b, T1Z, T16, TU;
			 T3I = T39 + T3a;
			 T3b = T39 - T3a;
			 T1Z = FNMS(T14, T12, T1Y);
			 T16 = FMA(T14, T15, T13);
			 T3O = TT - Tz;
			 TU = Tz + TT;
			 {
			      E T1H, T2G, T2h, T3e, T3c, T34, T1W, T32, T30, T33, T2b, T2S, T2R;
			      {
				   E T2W, T22, T1d, T2F, T2E, T36, T2D;
				   T2W = T2U - T2V;
				   T3w = T2U + T2V;
				   T22 = T1Z - T21;
				   T2D = T1Z + T21;
				   T1d = T16 + T1c;
				   T2F = T16 - T1c;
				   T2E = FNMS(KP500000000, T2D, T2C);
				   T36 = T2C + T2D;
				   T2d = FMA(KP866025403, T1G, T1B);
				   T1H = FNMS(KP866025403, T1G, T1B);
				   {
					E T1e, T1X, T38, T2X;
					T1e = T10 + T1d;
					T1X = FNMS(KP500000000, T1d, T10);
					T38 = T36 - T37;
					T3J = T36 + T37;
					T2G = FNMS(KP866025403, T2F, T2E);
					T2X = FMA(KP866025403, T2F, T2E);
					{
					     E T1z, T23, T2Z, T1A;
					     T3P = T1y - T1e;
					     T1z = T1e + T1y;
					     T23 = FNMS(KP866025403, T22, T1X);
					     T2h = FMA(KP866025403, T22, T1X);
					     T3e = FMA(KP618033988, T38, T3b);
					     T3c = FNMS(KP618033988, T3b, T38);
					     T2Z = T2X - T2Y;
					     T3x = T2X + T2Y;
					     T1A = TU + T1z;
					     T34 = TU - T1z;
					     T3C = T1O - T1V;
					     T1W = T1O + T1V;
					     T32 = FNMS(KP618033988, T2W, T2Z);
					     T30 = FMA(KP618033988, T2Z, T2W);
					     cr[0] = Tf + T1A;
					     T33 = FNMS(KP250000000, T1A, Tf);
					     T2b = T23 + T2a;
					     T3D = T23 - T2a;
					}
				   }
			      }
			      {
				   E T2A, T2N, T3d, T35, T2c;
				   T3f = T2t + T2z;
				   T2A = T2t - T2z;
				   T2N = T2G - T2M;
				   T3g = T2G + T2M;
				   T3d = FMA(KP559016994, T34, T33);
				   T35 = FNMS(KP559016994, T34, T33);
				   T2c = T1W + T2b;
				   T2S = T1W - T2b;
				   cr[WS(rs, 3)] = FMA(KP951056516, T3c, T35);
				   ci[WS(rs, 2)] = FNMS(KP951056516, T3c, T35);
				   cr[WS(rs, 6)] = FMA(KP951056516, T3e, T3d);
				   ci[WS(rs, 5)] = FNMS(KP951056516, T3e, T3d);
				   cr[WS(rs, 5)] = T1H + T2c;
				   T2R = FNMS(KP250000000, T2c, T1H);
				   T2Q = FNMS(KP618033988, T2A, T2N);
				   T2O = FMA(KP618033988, T2N, T2A);
			      }
			      {
				   E T2T, T31, T2g, T2j;
				   T2T = FMA(KP559016994, T2S, T2R);
				   T31 = FNMS(KP559016994, T2S, T2R);
				   T2g = T2e + T2f;
				   T3r = T2e - T2f;
				   T3q = T2h - T2i;
				   T2j = T2h + T2i;
				   ci[WS(rs, 3)] = FMA(KP951056516, T30, T2T);
				   ci[0] = FNMS(KP951056516, T30, T2T);
				   ci[WS(rs, 6)] = FMA(KP951056516, T32, T31);
				   cr[WS(rs, 2)] = FNMS(KP951056516, T32, T31);
				   T2k = T2g + T2j;
				   T2m = T2g - T2j;
			      }
			 }
		    }
		    {
			 E T3m, T3s, T3u, T3o, T3h, T2l, T2n, T2P;
			 ci[WS(rs, 4)] = T2d + T2k;
			 T2l = FNMS(KP250000000, T2k, T2d);
			 T3m = FMA(KP866025403, T3l, T3k);
			 T3v = FNMS(KP866025403, T3l, T3k);
			 T3s = FNMS(KP618033988, T3r, T3q);
			 T3u = FMA(KP618033988, T3q, T3r);
			 T2n = FMA(KP559016994, T2m, T2l);
			 T2P = FNMS(KP559016994, T2m, T2l);
			 ci[WS(rs, 1)] = FMA(KP951056516, T2Q, T2P);
			 cr[WS(rs, 7)] = FNMS(KP951056516, T2Q, T2P);
			 cr[WS(rs, 1)] = FMA(KP951056516, T2O, T2n);
			 cr[WS(rs, 4)] = FNMS(KP951056516, T2O, T2n);
			 T3o = T3f - T3g;
			 T3h = T3f + T3g;
			 {
			      E T3S, T3Q, T3K, T3M, T3n, T3p, T3t, T3L, T3R, T3N;
			      cr[WS(rs, 10)] = -(T3h + T3m);
			      T3n = FNMS(KP250000000, T3h, T3m);
			      T3S = FNMS(KP618033988, T3O, T3P);
			      T3Q = FMA(KP618033988, T3P, T3O);
			      T3p = FNMS(KP559016994, T3o, T3n);
			      T3t = FMA(KP559016994, T3o, T3n);
			      ci[WS(rs, 7)] = FMA(KP951056516, T3s, T3p);
			      cr[WS(rs, 13)] = FMS(KP951056516, T3s, T3p);
			      ci[WS(rs, 13)] = FNMS(KP951056516, T3u, T3t);
			      ci[WS(rs, 10)] = FMA(KP951056516, T3u, T3t);
			      T3K = T3I + T3J;
			      T3M = T3I - T3J;
			      ci[WS(rs, 14)] = T3K + T3H;
			      T3L = FNMS(KP250000000, T3K, T3H);
			      T3E = FMA(KP618033988, T3D, T3C);
			      T3G = FNMS(KP618033988, T3C, T3D);
			      T3R = FNMS(KP559016994, T3M, T3L);
			      T3N = FMA(KP559016994, T3M, T3L);
			      ci[WS(rs, 8)] = FMA(KP951056516, T3Q, T3N);
			      cr[WS(rs, 9)] = FMS(KP951056516, T3Q, T3N);
			      ci[WS(rs, 11)] = FMA(KP951056516, T3S, T3R);
			      cr[WS(rs, 12)] = FMS(KP951056516, T3S, T3R);
			      T3A = T3x - T3w;
			      T3y = T3w + T3x;
			 }
		    }
	       }
	  }
	  ci[WS(rs, 9)] = T3y + T3v;
	  T3z = FNMS(KP250000000, T3y, T3v);
	  T3F = FMA(KP559016994, T3A, T3z);
	  T3B = FNMS(KP559016994, T3A, T3z);
	  cr[WS(rs, 14)] = -(FMA(KP951056516, T3E, T3B));
	  cr[WS(rs, 11)] = FMS(KP951056516, T3E, T3B);
	  ci[WS(rs, 12)] = FMA(KP951056516, T3G, T3F);
	  cr[WS(rs, 8)] = FMS(KP951056516, T3G, T3F);
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 15},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 15, "hf_15", twinstr, &GENUS, {72, 28, 112, 0} };

void X(codelet_hf_15) (planner *p) {
     X(khc2hc_register) (p, hf_15, &desc);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2hc -compact -variables 4 -pipeline-latency 4 -n 15 -dit -name hf_15 -include hf.h */

/*
 * This function contains 184 FP additions, 112 FP multiplications,
 * (or, 128 additions, 56 multiplications, 56 fused multiply/add),
 * 65 stack variables, 6 constants, and 60 memory accesses
 */
#include "hf.h"

static void hf_15(R *cr, R *ci, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DK(KP866025403, +0.866025403784438646763723170752936183471402627);
     INT m;
     for (m = mb, W = W + ((mb - 1) * 28); m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 28, MAKE_VOLATILE_STRIDE(rs)) {
	  E T1q, T2Q, Td, T1n, T2T, T3l, T13, T1k, T1l, T2E, T2F, T3j, T1H, T1T, T2k;
	  E T2w, T2f, T2v, T1M, T1U, Tu, TL, TM, T2H, T2I, T3i, T1w, T1Q, T29, T2t;
	  E T24, T2s, T1B, T1R;
	  {
	       E T1, T2R, T6, T1o, Tb, T1p, Tc, T2S;
	       T1 = cr[0];
	       T2R = ci[0];
	       {
		    E T3, T5, T2, T4;
		    T3 = cr[WS(rs, 5)];
		    T5 = ci[WS(rs, 5)];
		    T2 = W[8];
		    T4 = W[9];
		    T6 = FMA(T2, T3, T4 * T5);
		    T1o = FNMS(T4, T3, T2 * T5);
	       }
	       {
		    E T8, Ta, T7, T9;
		    T8 = cr[WS(rs, 10)];
		    Ta = ci[WS(rs, 10)];
		    T7 = W[18];
		    T9 = W[19];
		    Tb = FMA(T7, T8, T9 * Ta);
		    T1p = FNMS(T9, T8, T7 * Ta);
	       }
	       T1q = KP866025403 * (T1o - T1p);
	       T2Q = KP866025403 * (Tb - T6);
	       Tc = T6 + Tb;
	       Td = T1 + Tc;
	       T1n = FNMS(KP500000000, Tc, T1);
	       T2S = T1o + T1p;
	       T2T = FNMS(KP500000000, T2S, T2R);
	       T3l = T2S + T2R;
	  }
	  {
	       E TR, T2c, T18, T2h, TW, T1E, T11, T1F, T12, T2d, T1d, T1J, T1i, T1K, T1j;
	       E T2i;
	       {
		    E TO, TQ, TN, TP;
		    TO = cr[WS(rs, 6)];
		    TQ = ci[WS(rs, 6)];
		    TN = W[10];
		    TP = W[11];
		    TR = FMA(TN, TO, TP * TQ);
		    T2c = FNMS(TP, TO, TN * TQ);
	       }
	       {
		    E T15, T17, T14, T16;
		    T15 = cr[WS(rs, 9)];
		    T17 = ci[WS(rs, 9)];
		    T14 = W[16];
		    T16 = W[17];
		    T18 = FMA(T14, T15, T16 * T17);
		    T2h = FNMS(T16, T15, T14 * T17);
	       }
	       {
		    E TT, TV, TS, TU;
		    TT = cr[WS(rs, 11)];
		    TV = ci[WS(rs, 11)];
		    TS = W[20];
		    TU = W[21];
		    TW = FMA(TS, TT, TU * TV);
		    T1E = FNMS(TU, TT, TS * TV);
	       }
	       {
		    E TY, T10, TX, TZ;
		    TY = cr[WS(rs, 1)];
		    T10 = ci[WS(rs, 1)];
		    TX = W[0];
		    TZ = W[1];
		    T11 = FMA(TX, TY, TZ * T10);
		    T1F = FNMS(TZ, TY, TX * T10);
	       }
	       T12 = TW + T11;
	       T2d = T1E + T1F;
	       {
		    E T1a, T1c, T19, T1b;
		    T1a = cr[WS(rs, 14)];
		    T1c = ci[WS(rs, 14)];
		    T19 = W[26];
		    T1b = W[27];
		    T1d = FMA(T19, T1a, T1b * T1c);
		    T1J = FNMS(T1b, T1a, T19 * T1c);
	       }
	       {
		    E T1f, T1h, T1e, T1g;
		    T1f = cr[WS(rs, 4)];
		    T1h = ci[WS(rs, 4)];
		    T1e = W[6];
		    T1g = W[7];
		    T1i = FMA(T1e, T1f, T1g * T1h);
		    T1K = FNMS(T1g, T1f, T1e * T1h);
	       }
	       T1j = T1d + T1i;
	       T2i = T1J + T1K;
	       {
		    E T1D, T1G, T2g, T2j;
		    T13 = TR + T12;
		    T1k = T18 + T1j;
		    T1l = T13 + T1k;
		    T2E = T2c + T2d;
		    T2F = T2h + T2i;
		    T3j = T2E + T2F;
		    T1D = FNMS(KP500000000, T12, TR);
		    T1G = KP866025403 * (T1E - T1F);
		    T1H = T1D - T1G;
		    T1T = T1D + T1G;
		    T2g = KP866025403 * (T1d - T1i);
		    T2j = FNMS(KP500000000, T2i, T2h);
		    T2k = T2g - T2j;
		    T2w = T2g + T2j;
		    {
			 E T2b, T2e, T1I, T1L;
			 T2b = KP866025403 * (T11 - TW);
			 T2e = FNMS(KP500000000, T2d, T2c);
			 T2f = T2b + T2e;
			 T2v = T2e - T2b;
			 T1I = FNMS(KP500000000, T1j, T18);
			 T1L = KP866025403 * (T1J - T1K);
			 T1M = T1I - T1L;
			 T1U = T1I + T1L;
		    }
	       }
	  }
	  {
	       E Ti, T21, Tz, T26, Tn, T1t, Ts, T1u, Tt, T22, TE, T1y, TJ, T1z, TK;
	       E T27;
	       {
		    E Tf, Th, Te, Tg;
		    Tf = cr[WS(rs, 3)];
		    Th = ci[WS(rs, 3)];
		    Te = W[4];
		    Tg = W[5];
		    Ti = FMA(Te, Tf, Tg * Th);
		    T21 = FNMS(Tg, Tf, Te * Th);
	       }
	       {
		    E Tw, Ty, Tv, Tx;
		    Tw = cr[WS(rs, 12)];
		    Ty = ci[WS(rs, 12)];
		    Tv = W[22];
		    Tx = W[23];
		    Tz = FMA(Tv, Tw, Tx * Ty);
		    T26 = FNMS(Tx, Tw, Tv * Ty);
	       }
	       {
		    E Tk, Tm, Tj, Tl;
		    Tk = cr[WS(rs, 8)];
		    Tm = ci[WS(rs, 8)];
		    Tj = W[14];
		    Tl = W[15];
		    Tn = FMA(Tj, Tk, Tl * Tm);
		    T1t = FNMS(Tl, Tk, Tj * Tm);
	       }
	       {
		    E Tp, Tr, To, Tq;
		    Tp = cr[WS(rs, 13)];
		    Tr = ci[WS(rs, 13)];
		    To = W[24];
		    Tq = W[25];
		    Ts = FMA(To, Tp, Tq * Tr);
		    T1u = FNMS(Tq, Tp, To * Tr);
	       }
	       Tt = Tn + Ts;
	       T22 = T1t + T1u;
	       {
		    E TB, TD, TA, TC;
		    TB = cr[WS(rs, 2)];
		    TD = ci[WS(rs, 2)];
		    TA = W[2];
		    TC = W[3];
		    TE = FMA(TA, TB, TC * TD);
		    T1y = FNMS(TC, TB, TA * TD);
	       }
	       {
		    E TG, TI, TF, TH;
		    TG = cr[WS(rs, 7)];
		    TI = ci[WS(rs, 7)];
		    TF = W[12];
		    TH = W[13];
		    TJ = FMA(TF, TG, TH * TI);
		    T1z = FNMS(TH, TG, TF * TI);
	       }
	       TK = TE + TJ;
	       T27 = T1y + T1z;
	       {
		    E T1s, T1v, T25, T28;
		    Tu = Ti + Tt;
		    TL = Tz + TK;
		    TM = Tu + TL;
		    T2H = T21 + T22;
		    T2I = T26 + T27;
		    T3i = T2H + T2I;
		    T1s = FNMS(KP500000000, Tt, Ti);
		    T1v = KP866025403 * (T1t - T1u);
		    T1w = T1s - T1v;
		    T1Q = T1s + T1v;
		    T25 = KP866025403 * (TJ - TE);
		    T28 = FNMS(KP500000000, T27, T26);
		    T29 = T25 + T28;
		    T2t = T28 - T25;
		    {
			 E T20, T23, T1x, T1A;
			 T20 = KP866025403 * (Ts - Tn);
			 T23 = FNMS(KP500000000, T22, T21);
			 T24 = T20 + T23;
			 T2s = T23 - T20;
			 T1x = FNMS(KP500000000, TK, Tz);
			 T1A = KP866025403 * (T1y - T1z);
			 T1B = T1x - T1A;
			 T1R = T1x + T1A;
		    }
	       }
	  }
	  {
	       E T2C, T1m, T2B, T2K, T2M, T2G, T2J, T2L, T2D;
	       T2C = KP559016994 * (TM - T1l);
	       T1m = TM + T1l;
	       T2B = FNMS(KP250000000, T1m, Td);
	       T2G = T2E - T2F;
	       T2J = T2H - T2I;
	       T2K = FNMS(KP587785252, T2J, KP951056516 * T2G);
	       T2M = FMA(KP951056516, T2J, KP587785252 * T2G);
	       cr[0] = Td + T1m;
	       T2L = T2C + T2B;
	       ci[WS(rs, 5)] = T2L - T2M;
	       cr[WS(rs, 6)] = T2L + T2M;
	       T2D = T2B - T2C;
	       ci[WS(rs, 2)] = T2D - T2K;
	       cr[WS(rs, 3)] = T2D + T2K;
	  }
	  {
	       E T3k, T3m, T3n, T3h, T3p, T3f, T3g, T3q, T3o;
	       T3k = KP559016994 * (T3i - T3j);
	       T3m = T3i + T3j;
	       T3n = FNMS(KP250000000, T3m, T3l);
	       T3f = T1k - T13;
	       T3g = Tu - TL;
	       T3h = FNMS(KP951056516, T3g, KP587785252 * T3f);
	       T3p = FMA(KP587785252, T3g, KP951056516 * T3f);
	       ci[WS(rs, 14)] = T3m + T3l;
	       T3q = T3n - T3k;
	       cr[WS(rs, 12)] = T3p - T3q;
	       ci[WS(rs, 11)] = T3p + T3q;
	       T3o = T3k + T3n;
	       cr[WS(rs, 9)] = T3h - T3o;
	       ci[WS(rs, 8)] = T3h + T3o;
	  }
	  {
	       E T2y, T2A, T1r, T1O, T2p, T2q, T2z, T2r;
	       {
		    E T2u, T2x, T1C, T1N;
		    T2u = T2s - T2t;
		    T2x = T2v - T2w;
		    T2y = FMA(KP951056516, T2u, KP587785252 * T2x);
		    T2A = FNMS(KP587785252, T2u, KP951056516 * T2x);
		    T1r = T1n - T1q;
		    T1C = T1w + T1B;
		    T1N = T1H + T1M;
		    T1O = T1C + T1N;
		    T2p = KP559016994 * (T1C - T1N);
		    T2q = FNMS(KP250000000, T1O, T1r);
	       }
	       cr[WS(rs, 5)] = T1r + T1O;
	       T2z = T2q - T2p;
	       cr[WS(rs, 2)] = T2z - T2A;
	       ci[WS(rs, 6)] = T2z + T2A;
	       T2r = T2p + T2q;
	       ci[0] = T2r - T2y;
	       ci[WS(rs, 3)] = T2r + T2y;
	  }
	  {
	       E T35, T3d, T39, T3a, T38, T3b, T3e, T3c;
	       {
		    E T33, T34, T36, T37;
		    T33 = T1w - T1B;
		    T34 = T1H - T1M;
		    T35 = FMA(KP951056516, T33, KP587785252 * T34);
		    T3d = FNMS(KP587785252, T33, KP951056516 * T34);
		    T39 = T2T - T2Q;
		    T36 = T2v + T2w;
		    T37 = T2s + T2t;
		    T3a = T37 + T36;
		    T38 = KP559016994 * (T36 - T37);
		    T3b = FNMS(KP250000000, T3a, T39);
	       }
	       ci[WS(rs, 9)] = T3a + T39;
	       T3e = T38 + T3b;
	       cr[WS(rs, 8)] = T3d - T3e;
	       ci[WS(rs, 12)] = T3d + T3e;
	       T3c = T38 - T3b;
	       cr[WS(rs, 11)] = T35 + T3c;
	       cr[WS(rs, 14)] = T3c - T35;
	  }
	  {
	       E T2X, T31, T2U, T2P, T2Y, T2Z, T32, T30;
	       {
		    E T2V, T2W, T2N, T2O;
		    T2V = T1T - T1U;
		    T2W = T1Q - T1R;
		    T2X = FNMS(KP587785252, T2W, KP951056516 * T2V);
		    T31 = FMA(KP951056516, T2W, KP587785252 * T2V);
		    T2U = T2Q + T2T;
		    T2N = T2k - T2f;
		    T2O = T24 + T29;
		    T2P = T2N - T2O;
		    T2Y = FMA(KP250000000, T2P, T2U);
		    T2Z = KP559016994 * (T2O + T2N);
	       }
	       cr[WS(rs, 10)] = T2P - T2U;
	       T32 = T2Z + T2Y;
	       ci[WS(rs, 10)] = T31 + T32;
	       ci[WS(rs, 13)] = T32 - T31;
	       T30 = T2Y - T2Z;
	       cr[WS(rs, 13)] = T2X - T30;
	       ci[WS(rs, 7)] = T2X + T30;
	  }
	  {
	       E T2m, T2o, T1P, T1W, T1X, T1Y, T1Z, T2n;
	       {
		    E T2a, T2l, T1S, T1V;
		    T2a = T24 - T29;
		    T2l = T2f + T2k;
		    T2m = FMA(KP951056516, T2a, KP587785252 * T2l);
		    T2o = FNMS(KP587785252, T2a, KP951056516 * T2l);
		    T1P = T1n + T1q;
		    T1S = T1Q + T1R;
		    T1V = T1T + T1U;
		    T1W = T1S + T1V;
		    T1X = KP559016994 * (T1S - T1V);
		    T1Y = FNMS(KP250000000, T1W, T1P);
	       }
	       ci[WS(rs, 4)] = T1P + T1W;
	       T1Z = T1X + T1Y;
	       cr[WS(rs, 4)] = T1Z - T2m;
	       cr[WS(rs, 1)] = T1Z + T2m;
	       T2n = T1Y - T1X;
	       cr[WS(rs, 7)] = T2n - T2o;
	       ci[WS(rs, 1)] = T2n + T2o;
	  }
     }
}

static const tw_instr twinstr[] = {
     {TW_FULL, 1, 15},
     {TW_NEXT, 1, 0}
};

static const hc2hc_desc desc = { 15, "hf_15", twinstr, &GENUS, {128, 56, 56, 0} };

void X(codelet_hf_15) (planner *p) {
     X(khc2hc_register) (p, hf_15, &desc);
}
#endif				/* HAVE_FMA */