/* W10A: run-length index builder over a value array (Swing_DLL.xex 0x886C9808). LTCG route. */
typedef struct A18V { unsigned short *begin, *end; } A18V;
typedef struct A18W { unsigned *begin, *end; } A18W;
typedef struct A18Src { unsigned char pad[0xc]; unsigned *w0c; } A18Src;
typedef struct A18O { unsigned char pad[0x18]; A18W w18; unsigned w20; A18V v24; } A18O;
extern unsigned short *fn_88263730(A18V *v);
extern unsigned *ts4_vector_push_slot_882630A0(A18W *w);
void ts4_build_runs_886C9808(A18O *s, unsigned short *out, unsigned first, unsigned last, A18Src *src)
{
    A18V *v = &s->v24;
    out[0] = (unsigned short)(((char *)v->end - (char *)v->begin) >> 2);
    if (first != last) {
        unsigned *q = src->w0c;
        unsigned cur = *q;
        unsigned idx = first;
        q = q + 1;
        *fn_88263730(v) = (unsigned short)idx;
        *ts4_vector_push_slot_882630A0(&s->w18) = cur;
        idx++;
        while (idx != last) {
            unsigned next = *q;
            if (next != cur) {
                unsigned short i16 = (unsigned short)idx;
                v->end[-1] = i16;
                *fn_88263730(v) = i16;
                *ts4_vector_push_slot_882630A0(&s->w18) = next;
                cur = next;
            }
            idx++;
            q++;
        }
        v->end[-1] = (unsigned short)idx;
    }
    out[1] = (unsigned short)(((char *)v->end - (char *)v->begin) >> 2);
}
