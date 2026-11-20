/* Shared declarations for the lb3_celt_* sources.
   Derived from CELT 0.6.1 libcelt headers entcode.h, entdec.h, cwrs.h,
   kiss_fft.h, vq.h, bands.h, rate.h, quant_bands.h (BSD license, Copyright
   (c) 2001-2008 Timothy B. Terriberry, (c) 2007-2009 Jean-Marc Valin,
   Xiph.Org Foundation); see THIRD_PARTY_NOTICES.md.
   Float build as linked into FMOD Ex (Swing_DLL.xex). */
#ifndef LB3_CELT_H
#define LB3_CELT_H

#include "aud1_celt.h"

#ifdef _MSC_VER
#define LB3_INLINE __inline
#define LB3_FORCEINLINE __forceinline
#define LB3_NOINLINE __declspec(noinline)
#define LB3_RESTRICT __restrict
#else
#define LB3_INLINE inline
#define LB3_FORCEINLINE inline
#define LB3_NOINLINE
#define LB3_RESTRICT
#endif

typedef celt_int32_t ec_int32;
typedef celt_uint32_t ec_uint32;

/* Simple libogg1-style byte buffer. */
typedef struct ec_byte_buffer {
    unsigned char *buf;
    unsigned char *ptr;
    long storage;
    int resizable;
} ec_byte_buffer;

/* The range decoder state. */
typedef struct ec_dec {
    ec_byte_buffer *buf;
    int rem;
    ec_uint32 rng;
    ec_uint32 dif;
    ec_uint32 nrm;
} ec_dec;

/* entcode.c / entdec.c: other sources refer to these by their placeholder names. */
int fn_883C2F08(ec_uint32 v);                                          /* ec_ilog */
ec_uint32 fn_883B3A08(ec_dec *dec, int bits);                          /* ec_dec_bits */
ec_uint32 lb3_celt_ec_dec_uint_883B3AA8(ec_dec *dec, ec_uint32 ft);    /* ec_dec_uint */
#define ec_ilog fn_883C2F08
#define ec_dec_bits fn_883B3A08
#define ec_dec_uint lb3_celt_ec_dec_uint_883B3AA8

void *_alloca(unsigned int n);

/* Upstream stack_alloc.h with USE_ALLOCA; asserts compiled out. */
#define celt_assert(cond)
#define EC_ILOG(x) ec_ilog(x)
#define ec_byte_bytes(b) ((b)->ptr - (b)->buf)
#define VARDECL(type, var) type *var
#define ALLOC(var, size, type) var = ((type *)_alloca(sizeof(type) * (size)))
#define SAVE_STACK
#define RESTORE_STACK
#define UADD32(a,b) ((a)+(b))
#define abs(x) ((x) < 0 ? -(x) : (x))


/* Float constants shared in the image's constant pool (addresses in
   Swing_DLL.xex); the compiler would otherwise create its own __real@ pool. */
extern const float lbl_88001A20; /* 0.0f */
extern const float lbl_88001A68; /* 1.0f */
extern const float lbl_88001978; /* 0.5f */
extern const float lbl_880291C0; /* 1.f/16384.f */
extern const float lbl_8802B770; /* 0.8f */
extern const float lbl_88035338; /* -7.0f */
extern const double lbl_88035330; /* 0.6931471805599453094 (ln 2) */
extern const float lbl_880352D0[24]; /* eMeans */
double fn_88565118(double x);    /* exp */
#define celt_exp2(x) (fn_88565118(lbl_88035330*(x)))
#define log2Amp(lg) celt_exp2(lg)
#define CHANNELS(mode) ((mode)->nbChannels)
typedef float celt_word32_t;
typedef celt_word32_t celt_ener_t;
#define MULT16_16_Q15(a,b) ((a)*(b))
#define Q15ONE 1.0f


#ifdef _MSC_VER
double sqrt(double x);
#pragma intrinsic(sqrt)
#else
double sqrt(double x);
#endif
#define celt_sqrt(x) ((float)sqrt(x))
#define celt_rcp(x) (1.f/(x))
typedef celt_word16_t celt_norm_t;
typedef celt_word32_t celt_mask_t;
void lb3_celt_decode_pulses_883C2BC8(int *_y, int N, int K, ec_dec *dec);

extern const float lbl_880353E0; /* .70711f */
extern const float lbl_8802E8DC; /* EPSILON, 1e-15f */
#define EPSILON lbl_8802E8DC

#endif
