/*
 * Copyright (c) 2007 Massachusetts Institute of Technology
 *
 * See the file COPYING for license information.
 *
 */

#include <ifftw.h>

#ifdef FFTW_SINGLE 
#define MAX_N 8192
#define REQUIRE_N_MULTIPLE_OF 4
#define VL 2
#else
#define MAX_N 4096
#define REQUIRE_N_MULTIPLE_OF 1
#define VL 1
#endif

#define MAX_PLAN_LEN 5
#define MAX_NSPE 16

struct spu_radices {
     signed char r[MAX_PLAN_LEN];
};

struct cell_iodim {
     int n0;  /* lower bound, n0 <= n */
     int n1;  /* upper bound, n < n1 */

     /* strides expressed in bytes  */
     int is_bytes;
     int os_bytes;

     /* derivative of M w.r.t. this dimension, for twiddle problems */
     int dm;
};

struct dft_context {
     struct spu_radices r;
     /* strides expressed in bytes  */
     int n, is_bytes, os_bytes;
     struct cell_iodim v[2];
     int sign;
     int Wsz_bytes;

     /* pointers, converted to ulonglong */
     unsigned long long xi, xo;
     unsigned long long W;

     /* optional twiddles for dftw */
     unsigned long long Ww;
};

struct transpose_context {
     unsigned long long A;
     int n;
     int s0_bytes;
     int s1_bytes;
     int nspe;
     int my_id;
};

struct copy_context {
     unsigned long long I;
     unsigned long long O;
     int n, v;
     int is_bytes, os_bytes;
     int ivs_bytes, ovs_bytes;
     int nspe;
     int my_id;
};

/* operations that the SPE's can execute */

enum spu_op {
     FFTW_SPE_DFT,
     FFTW_SPE_TRANSPOSE,
     FFTW_SPE_COPY,
     FFTW_SPE_EXIT
};

struct spu_context {
     union spu_context_u {
	  struct dft_context dft;
	  struct transpose_context transpose;
	  struct copy_context copy;
	  /* possibly others */
     } u;

     char pad[15 -
	      (((sizeof(union spu_context_u) + 
		 sizeof(enum spu_op)
		 + sizeof(int)) - 1) 
	       & 15)];
     volatile int done;
     enum spu_op op;
};

extern const struct spu_radices 
   X(spu_radices)[(MAX_N/REQUIRE_N_MULTIPLE_OF) + 1];

void X(dft_direct_cell_register)(planner *p);
void X(ct_cell_direct_register)(planner *p);

void *X(cell_aligned_malloc)(size_t n);

void X(cell_activate_spes)(void);
void X(cell_deactivate_spes)(void);

int X(cell_nspe)(void);
void X(cell_set_nspe)(int n);

struct spu_context *X(cell_get_ctx)(int spe);
void X(cell_spe_awake_all)(void);
void X(cell_spe_wait_all)(void);

#define FITS_IN_INT(x) ((x) == (int)(x))
