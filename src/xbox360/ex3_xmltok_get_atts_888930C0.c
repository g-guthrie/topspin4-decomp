/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */
#include "r3_xmltok.h"

typedef struct ex3_xml_attribute {
    const char *name;       /* +0x00 */
    const char *value_ptr;  /* +0x04 */
    const char *value_end;  /* +0x08 */
    char normalized;        /* +0x0C */
} ex3_xml_attribute;

/* Locate the attributes of a start tag: fills name/value ranges for up to atts_max attributes and returns
 * the attribute count (Expat normal_getAtts). Swing_DLL.xex 0x888930C0 */
int ts4_xmltok_normal_get_atts_888930C0(const struct ts4_xml_normal_encoding *enc, const char *ptr, int atts_max,
                                        ex3_xml_attribute *atts)
{
    enum { other, in_name, in_value } state = in_name;
    int n_atts = 0;
    int open = 0;

    for (ptr += 1;; ptr += 1) {
        switch (enc->type[(unsigned char)*ptr]) {
#define EX3_START_NAME                         \
    if (state == other) {                      \
        if (n_atts < atts_max) {               \
            atts[n_atts].name = ptr;           \
            atts[n_atts].normalized = 1;       \
        }                                      \
        state = in_name;                       \
    }
        case TS4_BT_LEAD2:
            EX3_START_NAME
            ptr += 2 - 1;
            break;
        case TS4_BT_LEAD3:
            EX3_START_NAME
            ptr += 3 - 1;
            break;
        case TS4_BT_LEAD4:
            EX3_START_NAME
            ptr += 4 - 1;
            break;
        case TS4_BT_NONASCII:
        case TS4_BT_NMSTRT:
        case TS4_BT_HEX:
            EX3_START_NAME
            break;
#undef EX3_START_NAME
        case TS4_BT_QUOT:
            if (state != in_value) {
                if (n_atts < atts_max)
                    atts[n_atts].value_ptr = ptr + 1;
                state = in_value;
                open = TS4_BT_QUOT;
            } else if (open == TS4_BT_QUOT) {
                state = other;
                if (n_atts < atts_max)
                    atts[n_atts].value_end = ptr;
                n_atts++;
            }
            break;
        case TS4_BT_APOS:
            if (state != in_value) {
                if (n_atts < atts_max)
                    atts[n_atts].value_ptr = ptr + 1;
                state = in_value;
                open = TS4_BT_APOS;
            } else if (open == TS4_BT_APOS) {
                state = other;
                if (n_atts < atts_max)
                    atts[n_atts].value_end = ptr;
                n_atts++;
            }
            break;
        case TS4_BT_AMP:
            if (n_atts < atts_max)
                atts[n_atts].normalized = 0;
            break;
        case TS4_BT_S:
            if (state == in_name)
                state = other;
            else if (state == in_value && n_atts < atts_max && atts[n_atts].normalized &&
                     (ptr == atts[n_atts].value_ptr || *ptr != ' ' || ptr[1] == ' ' ||
                      enc->type[(unsigned char)ptr[1]] == open))
                atts[n_atts].normalized = 0;
            break;
        case TS4_BT_CR:
        case TS4_BT_LF:
            if (state == in_name)
                state = other;
            else if (state == in_value && n_atts < atts_max)
                atts[n_atts].normalized = 0;
            break;
        case TS4_BT_GT:
        case TS4_BT_SOL:
            if (state != in_value)
                return n_atts;
            break;
        default:
            break;
        }
    }
}
