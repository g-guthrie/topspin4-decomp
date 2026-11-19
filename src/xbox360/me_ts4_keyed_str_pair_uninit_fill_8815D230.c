/* Swing_DLL.xex 0x8815D230: uninitialized_fill_n of count 32-byte entries {key, string name, string value, flag} from one value.
 * /Oc. Same element copy as 8815CAD0; the separate iterator local (Dinkumware _Next) fixes the parameter mr order. */
typedef struct Str { char *first; char *last; char *end; } Str;
typedef struct Entry { unsigned int key; Str name; Str value; unsigned char flag; } Entry;
void ts4_if_call_seq_lbl_880D19E0_8815C9E8(Str *s, unsigned int n);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline char *copy_chars(const char *first, const char *last, char *dest)
{
    if (last == first) {
        return dest;
    } else {
        unsigned int n = (unsigned int)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

static __inline void str_init(Str *s)
{
    s->first = 0;
    s->last = 0;
    s->end = 0;
}

static __inline void str_assign(Str *s, const Str *src)
{
    const char *last = src->last;
    const char *first = src->first;
    char *p;
    ts4_if_call_seq_lbl_880D19E0_8815C9E8(s, last - first + 1);
    p = copy_chars(first, last, s->first);
    s->last = p;
    *p = 0;
}

static __forceinline void entry_copy(Entry *e, const Entry *val)
{
    e->key = val->key;
    str_init(&e->name);
    str_assign(&e->name, &val->name);
    str_init(&e->value);
    str_assign(&e->value, &val->value);
    e->flag = val->flag;
}

static __inline void construct(Entry *p, const Entry *val)
{
    if (p) entry_copy(p, val);
}

Entry *fn_8815D230(Entry *dest, unsigned int count, const Entry *val)
{
    Entry *p = dest;
    for (; count != 0; --count, ++p) construct(p, val);
    return p;
}
