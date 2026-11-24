/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family OS2: Expat xmlrole.c internalSubset (switch with a jump table; one function per file). */
#include "d8ex_xmlrole.h"

#ifdef _MSC_VER
#define OS2_KW_UNUSED
#else
#define OS2_KW_UNUSED __attribute__((unused))
#endif

extern int ts4_if_addr_fn_888A2210_888A2380 HPARAMS;
extern int ts4_if_get_u32_off10_888A1A90 HPARAMS;
extern int ts4_if_get_u32_off10_888A1988 HPARAMS;
extern int ts4_if_get_u32_off10_888A1D50 HPARAMS;
extern int ts4_if_get_u32_off10_888A23F8 HPARAMS;

#define ASCII_A 0x41
#define ASCII_B 0x42
#define ASCII_C 0x43
#define ASCII_D 0x44
#define ASCII_E 0x45
#define ASCII_F 0x46
#define ASCII_G 0x47
#define ASCII_H 0x48
#define ASCII_I 0x49
#define ASCII_J 0x4A
#define ASCII_K 0x4B
#define ASCII_L 0x4C
#define ASCII_M 0x4D
#define ASCII_N 0x4E
#define ASCII_O 0x4F
#define ASCII_P 0x50
#define ASCII_Q 0x51
#define ASCII_R 0x52
#define ASCII_S 0x53
#define ASCII_T 0x54
#define ASCII_U 0x55
#define ASCII_V 0x56
#define ASCII_W 0x57
#define ASCII_X 0x58
#define ASCII_Y 0x59
#define ASCII_Z 0x5A
#define ASCII_a 0x61
#define ASCII_b 0x62
#define ASCII_c 0x63
#define ASCII_d 0x64
#define ASCII_e 0x65
#define ASCII_f 0x66
#define ASCII_g 0x67
#define ASCII_h 0x68
#define ASCII_i 0x69
#define ASCII_j 0x6A
#define ASCII_k 0x6B
#define ASCII_l 0x6C
#define ASCII_m 0x6D
#define ASCII_n 0x6E
#define ASCII_o 0x6F
#define ASCII_p 0x70
#define ASCII_q 0x71
#define ASCII_r 0x72
#define ASCII_s 0x73
#define ASCII_t 0x74
#define ASCII_u 0x75
#define ASCII_v 0x76
#define ASCII_w 0x77
#define ASCII_x 0x78
#define ASCII_y 0x79
#define ASCII_z 0x7A
#define ASCII_0 0x30
#define ASCII_1 0x31
#define ASCII_2 0x32
#define ASCII_3 0x33
#define ASCII_4 0x34
#define ASCII_5 0x35
#define ASCII_6 0x36
#define ASCII_7 0x37
#define ASCII_8 0x38
#define ASCII_9 0x39
#define ASCII_TAB 0x09
#define ASCII_SPACE 0x20
#define ASCII_EXCL 0x21
#define ASCII_QUOT 0x22
#define ASCII_AMP 0x26
#define ASCII_APOS 0x27
#define ASCII_MINUS 0x2D
#define ASCII_PERIOD 0x2E
#define ASCII_COLON 0x3A
#define ASCII_SEMI 0x3B
#define ASCII_LT 0x3C
#define ASCII_EQUALS 0x3D
#define ASCII_GT 0x3E
#define ASCII_LSQB 0x5B
#define ASCII_RSQB 0x5D
#define ASCII_UNDERSCORE 0x5F
static const char OS2_KW_UNUSED KW_ANY[] = {ASCII_A, ASCII_N, ASCII_Y, '\0'};
static const char OS2_KW_UNUSED KW_ATTLIST[] = {ASCII_A, ASCII_T, ASCII_T, ASCII_L, ASCII_I, ASCII_S, ASCII_T, '\0'};
static const char OS2_KW_UNUSED KW_CDATA[] = {ASCII_C, ASCII_D, ASCII_A, ASCII_T, ASCII_A, '\0'};
static const char OS2_KW_UNUSED KW_DOCTYPE[] = {ASCII_D, ASCII_O, ASCII_C, ASCII_T, ASCII_Y, ASCII_P, ASCII_E, '\0'};
static const char OS2_KW_UNUSED KW_ELEMENT[] = {ASCII_E, ASCII_L, ASCII_E, ASCII_M, ASCII_E, ASCII_N, ASCII_T, '\0'};
static const char OS2_KW_UNUSED KW_EMPTY[] = {ASCII_E, ASCII_M, ASCII_P, ASCII_T, ASCII_Y, '\0'};
static const char OS2_KW_UNUSED KW_ENTITIES[] = {ASCII_E, ASCII_N, ASCII_T, ASCII_I, ASCII_T, ASCII_I, ASCII_E, ASCII_S,
    '\0'};
static const char OS2_KW_UNUSED KW_ENTITY[] = {ASCII_E, ASCII_N, ASCII_T, ASCII_I, ASCII_T, ASCII_Y, '\0'};
static const char OS2_KW_UNUSED KW_FIXED[] = {ASCII_F, ASCII_I, ASCII_X, ASCII_E, ASCII_D, '\0'};
static const char OS2_KW_UNUSED KW_ID[] = {ASCII_I, ASCII_D, '\0'};
static const char OS2_KW_UNUSED KW_IDREF[] = {ASCII_I, ASCII_D, ASCII_R, ASCII_E, ASCII_F, '\0'};
static const char OS2_KW_UNUSED KW_IDREFS[] = {ASCII_I, ASCII_D, ASCII_R, ASCII_E, ASCII_F, ASCII_S, '\0'};
static const char OS2_KW_UNUSED KW_IGNORE[] = {ASCII_I, ASCII_G, ASCII_N, ASCII_O, ASCII_R, ASCII_E, '\0'};
static const char OS2_KW_UNUSED KW_IMPLIED[] = {ASCII_I, ASCII_M, ASCII_P, ASCII_L, ASCII_I, ASCII_E, ASCII_D, '\0'};
static const char OS2_KW_UNUSED KW_INCLUDE[] = {ASCII_I, ASCII_N, ASCII_C, ASCII_L, ASCII_U, ASCII_D, ASCII_E, '\0'};
static const char OS2_KW_UNUSED KW_NDATA[] = {ASCII_N, ASCII_D, ASCII_A, ASCII_T, ASCII_A, '\0'};
static const char OS2_KW_UNUSED KW_NMTOKEN[] = {ASCII_N, ASCII_M, ASCII_T, ASCII_O, ASCII_K, ASCII_E, ASCII_N, '\0'};
static const char OS2_KW_UNUSED KW_NMTOKENS[] = {ASCII_N, ASCII_M, ASCII_T, ASCII_O, ASCII_K, ASCII_E, ASCII_N, ASCII_S,
    '\0'};
static const char OS2_KW_UNUSED KW_NOTATION[] = {ASCII_N, ASCII_O, ASCII_T, ASCII_A, ASCII_T, ASCII_I, ASCII_O, ASCII_N,
      '\0'};
static const char OS2_KW_UNUSED KW_PCDATA[] = {ASCII_P, ASCII_C, ASCII_D, ASCII_A, ASCII_T, ASCII_A, '\0'};
static const char OS2_KW_UNUSED KW_PUBLIC[] = {ASCII_P, ASCII_U, ASCII_B, ASCII_L, ASCII_I, ASCII_C, '\0'};
static const char OS2_KW_UNUSED KW_REQUIRED[] = {ASCII_R, ASCII_E, ASCII_Q, ASCII_U, ASCII_I, ASCII_R, ASCII_E, ASCII_D,
    '\0'};
static const char OS2_KW_UNUSED KW_SYSTEM[] = {ASCII_S, ASCII_Y, ASCII_S, ASCII_T, ASCII_E, ASCII_M, '\0'};
/* Swing_DLL.xex 0x888A2458 (full KW_* set of xmlrole.c in upstream order: the compiler picks the base register from the symbol table, so every static must exist) */
int os2_xmlrole_internal_subset_888A2458 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 0;
    case 16: /* XML_TOK_DECL_OPEN */
        if (D8_NAME_MATCHES(enc, ptr + 2 * enc->min_bytes_per_char, end, KW_ENTITY)) {
            state->handler = ts4_if_addr_fn_888A2210_888A2380;
            return 11;
        }
        if (D8_NAME_MATCHES(enc, ptr + 2 * enc->min_bytes_per_char, end, KW_ATTLIST)) {
            state->handler = ts4_if_get_u32_off10_888A1A90;
            return 33;
        }
        if (D8_NAME_MATCHES(enc, ptr + 2 * enc->min_bytes_per_char, end, KW_ELEMENT)) {
            state->handler = ts4_if_get_u32_off10_888A1988;
            return 39;
        }
        if (D8_NAME_MATCHES(enc, ptr + 2 * enc->min_bytes_per_char, end, KW_NOTATION)) {
            state->handler = ts4_if_get_u32_off10_888A1D50;
            return 17;
        }
        break;
    case 11: /* XML_TOK_PI */
        return 55;
    case 13: /* XML_TOK_COMMENT */
        return 56;
    case 28: /* XML_TOK_PARAM_ENTITY_REF */
        return 60;
    case 26: /* XML_TOK_CLOSE_BRACKET */
        state->handler = ts4_if_get_u32_off10_888A23F8;
        return 3;
    }
    D8_COMMON(state, tok);
}
