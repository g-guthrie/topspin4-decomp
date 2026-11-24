/* 0x883E5E00: clears the u64 out; in modes 1-3 calls the source slot-6 flush, then stores the target slot-11 u64 position */
/* Matched on /O1 (agAH). The target vtable is read into a local before the flush call. */
typedef struct Tgt Tgt;
typedef struct TgtVt { void *f[11]; unsigned __int64 (*position)(Tgt *t); } TgtVt;
struct Tgt { TgtVt *vt; };
typedef struct Src Src;
typedef struct SrcVt { void *f[6]; void (*flush)(Src *s); } SrcVt;
struct Src { SrcVt *vt; };
typedef struct T { char p[8]; Tgt *tgt; char p2[4]; Src *src; char p3[0x1c]; int mode; } T;
int fn_883E5E00(T *t, unsigned __int64 *out)
{
    *out = 0;
    if (t->mode == 1 || t->mode == 2 || t->mode == 3) {
        TgtVt *vt = t->tgt->vt;
        t->src->vt->flush(t->src);
        *out = vt->position(t->tgt);
    }
    return 0;
}
