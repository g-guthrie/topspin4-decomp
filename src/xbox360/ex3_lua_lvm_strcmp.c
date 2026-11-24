/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: Lua 5.0 style lvm.c l_strcmp (string order that handles embedded zeros). */

typedef struct ex3_tstring {
    char head[0x14];       /* common header, hash, reserved */
    unsigned int len;      /* +0x14 string length */
    char str[1];           /* +0x18 characters */
} ex3_tstring;

int ts4_tailcall_fn_8856A048_8856A0C0(const char *a, const char *b); /* strcoll */
#ifdef _MSC_VER
extern unsigned int strlen(const char *s);
#else
#include <string.h>
#endif

/* Compare two Lua strings with strcoll, continuing past embedded NUL bytes (lvm.c l_strcmp).
 * Swing_DLL.xex 0x8880C2B0 */
int ex3_l_strcmp_8880C2B0(const ex3_tstring *ls, const ex3_tstring *rs)
{
    const char *l = ls->str;
    unsigned int ll = ls->len;
    const char *r = rs->str;
    unsigned int lr = rs->len;
    for (;;) {
        int temp = ts4_tailcall_fn_8856A048_8856A0C0(l, r);
        if (temp != 0)
            return temp;
        else {
            unsigned int len = strlen(l);
            if (len == lr)
                return (len == ll) ? 0 : 1;
            else if (len == ll)
                return -1;
            len++;
            l += len;
            ll -= len;
            r += len;
            lr -= len;
        }
    }
}
