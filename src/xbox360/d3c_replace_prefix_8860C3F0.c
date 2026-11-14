/* Swing_DLL.xex 0x8860C3F0-0x8860C474, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4PrefixRule {
    char *from;
    char *to;
    u32 pad;
    u8 remap;
} Ts4PrefixRule;

extern int fn_885630C0(char *a, char *b, u32 n);

/* Prefix match: returns the string itself when the rule is empty, 0 when it does not match, and
   the string rebased onto the rule's replacement range when the rule asks for remapping. */
char *ts4_prefix_rule_apply_8860C3F0(Ts4PrefixRule *r, char *s)
{
    char *res = s;
    if (r->from != r->to) {
        if (fn_885630C0(s, r->from, r->to - r->from) == 0) {
            if (r->remap) res = s - r->from + r->to;
        } else {
            res = 0;
        }
    }
    return res;
}
