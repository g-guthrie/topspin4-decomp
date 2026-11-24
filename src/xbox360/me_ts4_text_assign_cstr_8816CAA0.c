/* Swing_DLL.xex 0x8816CAA0: string::assign(const char *s): when s fits in the current size it overwrites the start and erases the rest (881505A8); otherwise it overwrites the whole current contents and appends the remainder (8816C930).
 * /Oc. `s + (int)strlen(s)` gives the clrrwi. */
typedef struct Text { char *p; char *last; char *end; } Text;
unsigned int strlen(const char *s);
void *memcpy(void *dst, const void *src, unsigned int n);
void ts4_if_call_seq_u32_off4_881505A8(Text *t, char *first, char *last); /* erase */
void fn_8816C930(Text *t, const char *first, const char *last); /* append */

void fn_8816CAA0(Text *t, const char *s)
{
    const char *e = s + (int)strlen(s);
    unsigned int n = e - s;
    unsigned int size = t->last - t->p;
    if (n <= size) {
        if (n != 0)
            memcpy(t->p, s, n);
        ts4_if_call_seq_u32_off4_881505A8(t, t->p + n, t->last);
    } else {
        const char *rest;
        if (size != 0)
            memcpy(t->p, s, size);
        rest = s + (t->last - t->p);
        if (rest != e)
            fn_8816C930(t, rest, e);
    }
}
