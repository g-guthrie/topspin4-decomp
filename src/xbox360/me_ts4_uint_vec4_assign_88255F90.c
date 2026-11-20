/* Swing_DLL.xex 0x88255F90: vector<u32> with a 4-entry inline buffer: operator= (grow into the buffer, shrink copy, or split copy then append).
 * /Oc. Same source as 8825FB30 with u32 elements; size test written size(s) >= n. */
typedef struct UintVec4 { unsigned int *first; unsigned int *last; unsigned int buf[4]; unsigned int *end; } UintVec4;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline void copy_uints(const unsigned int *first, const unsigned int *last, unsigned int *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

static __inline unsigned int uv_size(const UintVec4 *v) { return v->last - v->first; }

UintVec4 *fn_88255F90(UintVec4 *s, const UintVec4 *r)
{
    if (r != s) {
        unsigned int n = uv_size(r);
        if (n > (unsigned int)(s->end - s->first)) {
            unsigned int *p = s->buf;
            copy_uints(r->first, r->last, p);
            s->first = p;
            s->end = p + n;
        } else if (uv_size(s) >= n) {
            copy_uints(r->first, r->last, s->first);
        } else {
            copy_uints(r->first, r->first + uv_size(s), s->first);
            copy_uints(r->first + uv_size(s), r->last, s->last);
        }
        s->last = s->first + n;
    }
    return s;
}
