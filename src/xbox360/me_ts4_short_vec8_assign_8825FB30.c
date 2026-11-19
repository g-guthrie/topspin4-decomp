/* Swing_DLL.xex 0x8825FB30: vector<u16> with an 8-entry inline buffer: operator= (grow into the buffer, shrink copy, or split copy then append).
 * /Oc. Dinkumware assign shape; size test written size(s) >= n for the cmplw operand order. */
typedef struct ShortVec8 { unsigned short *first; unsigned short *last; unsigned short buf[8]; unsigned short *end; } ShortVec8;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline void copy_shorts(const unsigned short *first, const unsigned short *last, unsigned short *dest)
{
    if (last != first) fn_88562DC0(dest, first, (char *)last - (char *)first);
}

static __inline unsigned int sv_size(const ShortVec8 *v) { return v->last - v->first; }

ShortVec8 *fn_8825FB30(ShortVec8 *s, const ShortVec8 *r)
{
    if (r != s) {
        unsigned int n = sv_size(r);
        if (n > (unsigned int)(s->end - s->first)) {
            unsigned short *p = s->buf;
            copy_shorts(r->first, r->last, p);
            s->first = p;
            s->end = p + n;
        } else if (sv_size(s) >= n) {
            copy_shorts(r->first, r->last, s->first);
        } else {
            copy_shorts(r->first, r->first + sv_size(s), s->first);
            copy_shorts(r->first + sv_size(s), r->last, s->last);
        }
        s->last = s->first + n;
    }
    return s;
}
