/* Q5 batch K (Opus A): small gameplay helper proven EQUIVALENT with tools/fn_equiv.py on b215
 * (TS4_MATCHING_DIR=work/matching-b215, /Oc). It carries its byte gap to the target. */
typedef unsigned int u32;
typedef struct Q5Str { char *b; char *e; char *c; } Q5Str;
typedef struct Q5Str16 { char *b; char *e; char *c; void *alloc; } Q5Str16;
typedef u32 (*Q5PrintFn)(u32 flags, const char *text);
typedef struct Q5PrintHook { char pad[0x2af4]; Q5PrintFn print; } Q5PrintHook;
typedef struct Q5Engine2CC { char pad[0x2cc]; Q5PrintHook *hook; } Q5Engine2CC;
typedef struct Q5Logger { char pad[0x34]; Q5Str prefix; } Q5Logger;
extern Q5Engine2CC *lbl_88D45B1C;
extern void ts4_assign_formatted_text(Q5Str *dst, const char *text);
extern Q5Str *fn_88163300(Q5Str *out, const Q5Str *a, const Q5Str *b);
extern void *ts4_if_call_seq_u32_off0_8816D140(Q5Str16 *self, Q5Str *s);
extern u32 fn_8857E4E0(u32 flags, const char *text);
extern void ts4_destroy_owned_object(void *p);
/* Swing_DLL.xex 0x88888CF8: print prefix + text through the engine's print hook (+0x2cc, slot +0x2af4), or 8857E4E0
 * when there is none; flags 4 for mode 1, else 8 */
/* byte-gap: 6 off (perm not run); stack slot order of the joined and converted strings, the cached text register, and cmpwi on the hook test */
void ts4_log_prefixed_88888CF8(Q5Logger *self, const char *text, int mode)
{
    Q5Str s;
    Q5Str joined;
    Q5Str16 out;
    char *t;
    Q5PrintHook *hook;
    u32 flags = mode == 1 ? 4 : 8;
    ts4_assign_formatted_text(&s, text);
    ts4_if_call_seq_u32_off0_8816D140(&out, fn_88163300(&joined, &self->prefix, &s));
    ts4_destroy_owned_object(joined.b);
    ts4_destroy_owned_object(s.b);
    t = out.b;
    hook = lbl_88D45B1C->hook;
    if (hook == 0)
        fn_8857E4E0(flags, t);
    else
        hook->print(flags, t);
    ts4_destroy_owned_object(t);
}
