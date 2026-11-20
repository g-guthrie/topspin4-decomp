/* Derived from Expat 2.0 (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family OS2: Expat xmlrole.c attlist8 (default declaration of an attribute: #IMPLIED, #REQUIRED, #FIXED or a literal). */
#include "d8ex_xmlrole.h"

/* Layout stand-ins for the Expat KW_* keyword arrays of xmlrole.c: they are statics of one translation unit, so the
 * compiler addresses them from one base register. Only the relative offsets matter (KW_FIXED 0x880D0594,
 * KW_IMPLIED 0x880D05B8, KW_REQUIRED 0x880D0600); the pads keep the gaps and the user function keeps them alive.
 * Arrays of 0x40 bytes or more are placed last by the compiler, hence two pads of 0x20. */
static const char lbl_880D0594[8] = {'F', 'I', 'X', 'E', 'D'};
static const char os2_kw_pad_059c[0x1c] = {2};
static const char lbl_880D05B8[8] = {'I', 'M', 'P', 'L', 'I', 'E', 'D'};
static const char os2_kw_pad_05c0[0x20] = {3};
static const char os2_kw_pad_05e0[0x20] = {4};
static const char lbl_880D0600[12] = {'R', 'E', 'Q', 'U', 'I', 'R', 'E', 'D'};
int os2_kw_layout_users_888A0C10(void) { return os2_kw_pad_059c[0] + os2_kw_pad_05c0[0] + os2_kw_pad_05e0[0]; }
extern int ts4_xmlrole_attlist1_888A19F0 HPARAMS;
extern int ts4_if_get_u32_off10_888A0BB0 HPARAMS;

/* Swing_DLL.xex 0x888A0C10 */
int os2_xmlrole_attlist8_888A0C10 HPARAMS
{
    switch (tok) {
    case TS4_XML_TOK_PROLOG_S:
        return 33;
    case 20: /* XML_TOK_POUND_NAME */
        if (D8_NAME_MATCHES(enc, ptr + enc->min_bytes_per_char, end, lbl_880D05B8)) {
            state->handler = ts4_xmlrole_attlist1_888A19F0;
            return 35;
        }
        if (D8_NAME_MATCHES(enc, ptr + enc->min_bytes_per_char, end, lbl_880D0600)) {
            state->handler = ts4_xmlrole_attlist1_888A19F0;
            return 36;
        }
        if (D8_NAME_MATCHES(enc, ptr + enc->min_bytes_per_char, end, lbl_880D0594)) {
            state->handler = ts4_if_get_u32_off10_888A0BB0;
            return 33;
        }
        break;
    case 27: /* XML_TOK_LITERAL */
        state->handler = ts4_xmlrole_attlist1_888A19F0;
        return 37;
    }
    D8_COMMON(state, tok);
}
