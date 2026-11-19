/* Swing_DLL.xex 0x8815CFA8: uninitialized_copy over 48-byte entries {Mat key, string name, string value, flag}.
 * /Oc near miss, 3 off: the zero stores of the second string (+0x20) are scheduled end-first. Sibling of 8815CAD0/8815D230 (matched). */
typedef struct Str { char *first; char *last; char *end; } Str;
typedef struct FVec { float *first; float *last; float *end; } FVec;
typedef struct Mat { unsigned int w; unsigned int h; FVec v; } Mat;
typedef struct Entry { Mat key; Str name; Str value; unsigned char flag; } Entry;
Mat *ts4_mat_copy_88159180(Mat *m, const Mat *src);
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
    ts4_mat_copy_88159180(&e->key, &val->key);
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

Entry *fn_8815CFA8(const Entry *first, const Entry *last, Entry *dest)
{
    for (; first != last; ++dest, ++first) construct(dest, first);
    return dest;
}
