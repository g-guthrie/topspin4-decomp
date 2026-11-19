/* Swing_DLL.xex 0x886CE860: resizes a Rec* vector to countA+countB from a self-relative info block, then points each slot at consecutive 0x8C-byte records.
 * /Oc. resize inline with the zero default passed by value (_Insert_n fn_88281CA8, memmove fn_88562DC0). */
typedef struct Rec { unsigned char pad[0x8c]; } Rec;
typedef struct RelHdr { int rel; } RelHdr;
typedef struct Info { unsigned char p0[0x14]; unsigned int index; unsigned int countA; unsigned char p1[0x18]; unsigned int countB; } Info;
typedef struct Data { unsigned char p0[0x14]; RelHdr info; unsigned char p1[0x50 - 0x18]; RelHdr recs; } Data;
typedef struct Self { unsigned char p0[0xc]; Data *data; } Self;
typedef struct RecVec { Rec **first; Rec **last; Rec **end; } RecVec;
void fn_88281CA8(RecVec *v, Rec **where, unsigned int count, Rec *const *val);
void *fn_88562DC0(void *dst, const void *src, unsigned int n);

static __inline Info *info_of(RelHdr *h) { return (Info *)((char *)h + h->rel); }

static __inline Rec **copy_ptrs(Rec **first, Rec **last, Rec **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Rec **)fn_88562DC0(dest, first, n);
        return (Rec **)((char *)dest + n);
    }
}

static __inline void resize(RecVec *v, unsigned int n, Rec *val)
{
    unsigned int size = v->last - v->first;
    if (n < size)
        v->last = copy_ptrs(v->last, v->last, v->first + n);
    else
        fn_88281CA8(v, v->last, n - size, &val);
}

void fn_886CE860(Self *s, RecVec *v)
{
    Info *a = info_of(&s->data->info);
    Info *b = info_of(&s->data->info);
    unsigned int n = a->countB + b->countA;
    if (n != 0) {
        RelHdr *h = &s->data->recs;
        Rec *r = (Rec *)((char *)h + (b->index * 0x8c + h->rel));
        unsigned int i;
        resize(v, n, 0);
        for (i = 0; i < n; i++) v->first[i] = &r[i];
    }
}
