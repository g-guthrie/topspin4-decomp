/* Swing_DLL.xex 0x88236708: operator+(const char *s, const FixedString &b) for the 256-byte inline-buffer string: empty result, buffer view for strlen(s) + size(b) + 1 (881A5210), terminate, append s then b (8816CF48).
 * /Oc. The inline store is copied from an uninitialised local (the target memcpys 0x100 bytes from the stack). `(int)strlen(s)` gives the clrrwi. */
typedef struct FixedStore { char bytes[0x100]; } FixedStore;
typedef struct FixedString { char *first; char *last; FixedStore store; char *end; } FixedString;
unsigned int strlen(const char *s);
void ts4_buffer_view_init_881A5210(FixedString *self, unsigned int n);
FixedString *ts4_fixed_string_append_8816CF48(FixedString *self, const char *from, const char *to);

static __inline void fixed_string_append(FixedString *self, const char *from, const char *to)
{
    if (from != to)
        ts4_fixed_string_append_8816CF48(self, from, to);
}

FixedString *fn_88236708(FixedString *r, const char *s, const FixedString *b)
{
    unsigned int len = (int)strlen(s);
    unsigned int n = len + (b->last - b->first);
    FixedStore store; /* default allocator state, copied uninitialised as in the original */
    r->first = 0;
    r->last = 0;
    r->store = store;
    r->end = 0;
    ts4_buffer_view_init_881A5210(r, n + 1);
    *r->last = 0;
    fixed_string_append(r, s, s + len);
    fixed_string_append(r, b->first, b->last);
    return r;
}
