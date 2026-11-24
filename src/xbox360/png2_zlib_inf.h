/* Derived from zlib 1.1.4 (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: the subset of zlib.h / zutil.h / zconf.h used by the inflate side of the second statically
 * linked zlib 1.1.4 copy (infblock.c, infcodes.c, inftrees.c, infutil.c, inffast.c; built with /Os).
 * Non-DEBUG build: the Trace and Assert macros expand to nothing. */
#ifndef PNG2_ZLIB_INF_H
#define PNG2_ZLIB_INF_H

#define OF(args) args
#define FAR
#define local static

typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;
typedef Byte Bytef;
typedef char charf;
typedef int intf;
typedef uInt uIntf;
typedef uLong uLongf;
typedef void *voidpf;
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;

typedef voidpf (*alloc_func)(voidpf opaque, uInt items, uInt size);
typedef void (*free_func)(voidpf opaque, voidpf address);

typedef struct z_stream_s {
    Bytef *next_in;   /* +0x00 */
    uInt avail_in;    /* +0x04 */
    uLong total_in;   /* +0x08 */
    Bytef *next_out;  /* +0x0C */
    uInt avail_out;   /* +0x10 */
    uLong total_out;  /* +0x14 */
    char *msg;        /* +0x18 */
    struct internal_state *state; /* +0x1C */
    alloc_func zalloc; /* +0x20 */
    free_func zfree;  /* +0x24 */
    voidpf opaque;    /* +0x28 */
    int data_type;    /* +0x2C */
    uLong adler;      /* +0x30 */
    uLong reserved;   /* +0x34 */
} z_stream;
typedef z_stream *z_streamp;

#define Z_OK            0
#define Z_STREAM_END    1
#define Z_NEED_DICT     2
#define Z_ERRNO        (-1)
#define Z_STREAM_ERROR (-2)
#define Z_DATA_ERROR   (-3)
#define Z_MEM_ERROR    (-4)
#define Z_BUF_ERROR    (-5)
#define Z_NULL 0
#define Z_NO_FLUSH      0
#define Z_PARTIAL_FLUSH 1
#define Z_SYNC_FLUSH    2
#define Z_FULL_FLUSH    3
#define Z_FINISH        4
#define Z_DEFLATED      8
#define PRESET_DICT 0x20 /* preset dictionary flag in zlib header */

typedef uLong (*check_func)(uLong check, const Bytef *buf, uInt len);

#define ZALLOC(strm, items, size) (*((strm)->zalloc))((strm)->opaque, (items), (size))
#define ZFREE(strm, addr) (*((strm)->zfree))((strm)->opaque, (voidpf)(addr))
#define TRY_FREE(s, p) {if (p) ZFREE(s, p);}

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
#define zmemcpy memcpy

#define Assert(cond, msg)
#define Trace(x)
#define Tracev(x)
#define Tracevv(x)
#define Tracec(c, x)
#define Tracecv(c, x)

/* zlib's error messages; this build reaches them through these labels instead of string literals. */
extern const char lbl_880DFA28[]; /* "invalid block type" */
extern const char lbl_880DFA3C[]; /* "invalid stored block lengths" */
extern const char lbl_880DFA5C[]; /* "too many length or distance symbols" */
extern const char lbl_880DFA9C[]; /* "invalid bit length repeat" */
extern const char lbl_880DFAEC[]; /* "invalid literal/length code" */
extern const char lbl_880DFB08[]; /* "invalid distance code" */
extern const char lbl_88028A00[]; /* "incomplete dynamic bit lengths tree" */
extern const char lbl_88028A24[]; /* "oversubscribed dynamic bit lengths tree" */
extern const char lbl_88028A4C[]; /* "incomplete literal/length tree" */
extern const char lbl_88028A6C[]; /* "oversubscribed literal/length tree" */
extern const char lbl_88028A90[]; /* "empty distance tree with lengths" */
extern const char lbl_88028AB4[]; /* "incomplete distance tree" */
extern const char lbl_88028AD0[]; /* "oversubscribed distance tree" */
extern const char lbl_880DFB40[]; /* "incorrect header check" */
extern const char lbl_880DFB58[]; /* "unknown compression method" */
extern const char lbl_880DFB74[]; /* "invalid window size" */
extern const char lbl_880DFBB8[]; /* "incorrect data check" */
extern const char lbl_880DFC58[]; /* "need dictionary" */

#endif
