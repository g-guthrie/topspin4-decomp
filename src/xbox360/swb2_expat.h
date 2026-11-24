/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWB2: shared declarations for the expat-style tokenizer functions
 * (xmltok_impl.c "normal" 8-bit encoding). Layout inferred from the tokenizer
 * code: byte-type table at +0x4c, isInvalid2/3/4 callbacks at +0x164..0x16c. */
#ifndef SWB2_EXPAT_H
#define SWB2_EXPAT_H

typedef struct SwbEnc SwbEnc;
struct SwbEnc {
    char pad0[0x4c];
    unsigned char type[256];                              /* 0x4c */
    int (*isName2)(const SwbEnc *, const char *);         /* 0x14c */
    int (*isName3)(const SwbEnc *, const char *);         /* 0x150 */
    int (*isName4)(const SwbEnc *, const char *);         /* 0x154 */
    int (*isNmstrt2)(const SwbEnc *, const char *);       /* 0x158 */
    int (*isNmstrt3)(const SwbEnc *, const char *);       /* 0x15c */
    int (*isNmstrt4)(const SwbEnc *, const char *);       /* 0x160 */
    int (*isInvalid2)(const SwbEnc *, const char *);      /* 0x164 */
    int (*isInvalid3)(const SwbEnc *, const char *);      /* 0x168 */
    int (*isInvalid4)(const SwbEnc *, const char *);      /* 0x16c */
};

#define SWB_BT_NONXML  0
#define SWB_BT_MALFORM 1
#define SWB_BT_LT      2
#define SWB_BT_AMP     3
#define SWB_BT_RSQB    4
#define SWB_BT_LEAD2   5
#define SWB_BT_LEAD3   6
#define SWB_BT_LEAD4   7
#define SWB_BT_TRAIL   8
#define SWB_BT_CR      9
#define SWB_BT_LF      10
#define SWB_BT_GT      11
#define SWB_BT_QUOT    12
#define SWB_BT_APOS    13
#define SWB_BT_EQUALS  14
#define SWB_BT_QUEST   15
#define SWB_BT_EXCL    16
#define SWB_BT_SOL     17
#define SWB_BT_SEMI    18
#define SWB_BT_NUM     19
#define SWB_BT_LSQB    20
#define SWB_BT_S       21
#define SWB_BT_NMSTRT  22
#define SWB_BT_COLON   23
#define SWB_BT_HEX     24
#define SWB_BT_DIGIT   25
#define SWB_BT_NAME    26
#define SWB_BT_MINUS   27
#define SWB_BT_OTHER   28
#define SWB_BT_NONASCII 29

#define SWB_TOK_INVALID       0
#define SWB_TOK_PARTIAL      (-1)
#define SWB_TOK_PARTIAL_CHAR (-2)

#define SWB_BYTE_TYPE(enc, p) ((enc)->type[(unsigned char)*(p)])

#define SWB_INVALID_LEN_CASE(n, bt, fn)                                  \
    case bt:                                                             \
        if (end - ptr < n) return SWB_TOK_PARTIAL_CHAR;                  \
        if ((enc)->fn((enc), ptr)) { *next = ptr; return SWB_TOK_INVALID; } \
        ptr += n;                                                        \
        break;

#define SWB_INVALID_CASES()                                              \
    SWB_INVALID_LEN_CASE(2, SWB_BT_LEAD2, isInvalid2)                    \
    SWB_INVALID_LEN_CASE(3, SWB_BT_LEAD3, isInvalid3)                    \
    SWB_INVALID_LEN_CASE(4, SWB_BT_LEAD4, isInvalid4)                    \
    case SWB_BT_NONXML:                                                  \
    case SWB_BT_MALFORM:                                                 \
    case SWB_BT_TRAIL:                                                   \
        *next = ptr;                                                     \
        return SWB_TOK_INVALID;


/* UTF-16 variants: byte-type of a 2-byte unit, helper kept out of line in the original. */

#ifdef _MSC_VER
#define SWB_INLINE static __forceinline
#else
#define SWB_INLINE static inline
#endif

/* Expat unicode_byte_type(hi, lo): defined in each translation unit that uses it so the compiler can
 * see the callee's register usage (interprocedural allocation); original lives at 0x888927A0. */
#ifdef _MSC_VER
__declspec(noinline)
#else
__attribute__((unused))
#endif
static int ts4_xmltok_unicode_byte_type_888927A0(char hi, char lo)
{
    switch ((unsigned char)hi) {
    case 0xD8: case 0xD9: case 0xDA: case 0xDB:
        return SWB_BT_LEAD4;
    case 0xDC: case 0xDD: case 0xDE: case 0xDF:
        return SWB_BT_TRAIL;
    case 0xFF:
        switch ((unsigned char)lo) {
        case 0xFF: case 0xFE:
            return SWB_BT_NONXML;
        }
        break;
    }
    return SWB_BT_NONASCII;
}

/* inline copy of the unicode byte-type classification of a little-endian 2-byte unit (p[1] != 0) */
SWB_INLINE int swb_little2_uni_inline(unsigned int raw, const unsigned char *p)
{
    switch ((int)(raw & 0xff)) {
    case 0xd8: case 0xd9: case 0xda: case 0xdb:
        return SWB_BT_LEAD4;
    case 0xdc: case 0xdd: case 0xde: case 0xdf:
        return SWB_BT_TRAIL;
    case 0xff:
        { int lo = p[0]; if (lo >= 0xfe && lo <= 0xff) return SWB_BT_NONXML; }
        break;
    }
    return SWB_BT_NONASCII;
}

/* big-endian variant: high byte first */
SWB_INLINE int swb_big2_uni_inline(unsigned int raw, const unsigned char *p)
{
    switch ((int)(raw & 0xff)) {
    case 0xd8: case 0xd9: case 0xda: case 0xdb:
        return SWB_BT_LEAD4;
    case 0xdc: case 0xdd: case 0xde: case 0xdf:
        return SWB_BT_TRAIL;
    case 0xff:
        { int lo = p[1]; if (lo >= 0xfe && lo <= 0xff) return SWB_BT_NONXML; }
        break;
    }
    return SWB_BT_NONASCII;
}

/* little-endian 2-byte unit byte type, unicode classification left out of line */
#define SWB_LITTLE2_TYPE(enc, p) \
    ((p)[1] == 0 ? (enc)->type[(p)[0]] : ts4_xmltok_unicode_byte_type_888927A0((p)[1], (p)[0]))
#define SWB_LITTLE2_MATCHES(p, c) ((p)[1] == 0 && (p)[0] == (c))

#define SWB_BIG2_TYPE(enc, p) \
    ((p)[0] == 0 ? (enc)->type[(p)[1]] : ts4_xmltok_unicode_byte_type_888927A0((p)[0], (p)[1]))

/* same, for plain (signed) char pointers */
#define SWB_BIG2_TYPE_C(enc, p) \
    ((p)[0] == 0 ? (enc)->type[(unsigned char)(p)[1]] : ts4_xmltok_unicode_byte_type_888927A0((p)[0], (p)[1]))

#endif
