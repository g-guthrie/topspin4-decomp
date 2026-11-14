/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX5: shared pieces for the 16-bit (UTF-16 big/little endian) Expat tokenizer functions that test
 * XML name characters. The name-class bitmap and page tables are statics of the original translation unit
 * (one base register addresses all three); the contents below are placeholders that only fix the object
 * layout, as in ex3_xmltok_name.c (real tables at 0x880CE9C0, 0x880CEEC0, 0x880CEFC0). */
#ifndef EX5_XMLTOK16_H
#define EX5_XMLTOK16_H

#include "swb2_expat.h"

#ifdef _MSC_VER
#define EX5_UNUSED_DATA
#else
#define EX5_UNUSED_DATA __attribute__((unused))
#endif
static const unsigned char ex5_layout_pad[16] EX5_UNUSED_DATA = {1};
static const unsigned int lbl_880CE9C0[320] = {1};  /* namingBitmap */
static const unsigned char lbl_880CEEC0[256] = {1}; /* nmstrtPages */
static const unsigned char lbl_880CEFC0[256] = {1}; /* namePages */
#ifdef EX5_WITH_CDATA_TABLE
/* The original also addresses the "CDATA[" character table (0x880CFF30) from the same base register. */
static const unsigned char ex5_layout_gap[0xE70] EX5_UNUSED_DATA = {1};
static const unsigned char lbl_880CFF30[8] = {'C', 'D', 'A', 'T', 'A', '['};
#endif

/* Expat UCS2_GET_NAMING */
#ifdef _MSC_VER
#define EX5_FORCEINLINE static __forceinline
#else
#define EX5_FORCEINLINE static inline __attribute__((unused))
#endif

#define EX5_UCS2_NAMING(bitmap, pages, hi, lo) \
    ((bitmap)[((pages)[hi] << 3) + ((lo) >> 5)] & (1u << ((lo) & 0x1F)))

/* Expat BYTE_TYPE for a 2-byte unit given its high and low byte */
#define EX5_UNIT_TYPE(enc, hi, lo) \
    ((hi) == 0 ? (enc)->type[(unsigned char)(lo)] : ts4_xmltok_unicode_byte_type_888927A0(hi, lo))

#define EX5_HI_BIG2(p) ((p)[0])
#define EX5_LO_BIG2(p) ((p)[1])
#define EX5_HI_LITTLE2(p) ((p)[1])
#define EX5_LO_LITTLE2(p) ((p)[0])

/* Expat CHECK_NMSTRT_CASES (16-bit): first character of a name, following the NONASCII->NMSTRT fallthrough */
#define EX5_CHECK_NMSTRT_CASES(HI, LO)                                                                      \
    case SWB_BT_NONASCII:                                                                                    \
        if (!EX5_UCS2_NAMING(lbl_880CE9C0, lbl_880CEEC0, (unsigned char)HI(ptr), (unsigned char)LO(ptr))) {  \
            *next = ptr;                                                                                     \
            return SWB_TOK_INVALID;                                                                          \
        }                                                                                                    \
        /* fall through */                                                                                   \
    case SWB_BT_NMSTRT:                                                                                      \
    case SWB_BT_HEX:                                                                                         \
        ptr += 2;                                                                                            \
        break;                                                                                               \
    case SWB_BT_LEAD2:                                                                                       \
        if (end - ptr < 2)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;                                                                              \
    case SWB_BT_LEAD3:                                                                                       \
        if (end - ptr < 3)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;                                                                              \
    case SWB_BT_LEAD4:                                                                                       \
        if (end - ptr < 4)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;

/* Expat CHECK_NAME_CASES (16-bit): subsequent name characters */
#define EX5_CHECK_NAME_CASES(HI, LO)                                                                        \
    case SWB_BT_NONASCII:                                                                                    \
        if (!EX5_UCS2_NAMING(lbl_880CE9C0, lbl_880CEFC0, (unsigned char)HI(ptr), (unsigned char)LO(ptr))) {  \
            *next = ptr;                                                                                     \
            return SWB_TOK_INVALID;                                                                          \
        }                                                                                                    \
        /* fall through */                                                                                   \
    case SWB_BT_NMSTRT:                                                                                      \
    case SWB_BT_HEX:                                                                                         \
    case SWB_BT_DIGIT:                                                                                       \
    case SWB_BT_NAME:                                                                                        \
    case SWB_BT_MINUS:                                                                                       \
        ptr += 2;                                                                                            \
        break;                                                                                               \
    case SWB_BT_LEAD2:                                                                                       \
        if (end - ptr < 2)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;                                                                              \
    case SWB_BT_LEAD3:                                                                                       \
        if (end - ptr < 3)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;                                                                              \
    case SWB_BT_LEAD4:                                                                                       \
        if (end - ptr < 4)                                                                                   \
            return SWB_TOK_PARTIAL_CHAR;                                                                     \
        *next = ptr;                                                                                         \
        return SWB_TOK_INVALID;

#endif
