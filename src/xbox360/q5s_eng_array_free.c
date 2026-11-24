/* q5s eng: release an owned object array (vector deleting destructor or raw free) (LTCG). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct EngDObj EngDObj;
typedef struct EngDObjVt { void (*vec_dtor)(EngDObj *o, u32 flags); } EngDObjVt;
struct EngDObj { const EngDObjVt *vt; };

/* 0x10-byte header in front of the array; a nonzero count means the elements need destroying. */
typedef struct EngDHdr { int count; u32 w4, w8, wc; } EngDHdr;

extern void ts4_registry_dispatch_888860A0(void *p);

typedef struct EngDOwner { u8 pad[0x78]; EngDObj *arr; u32 n; } EngDOwner;

void ts4_owner_free_array_882695F8(EngDOwner *self)
{
    EngDObj *a = self->arr;
    if ((long)a != 0) { /* signed compare in the target (cmpwi) */
        EngDHdr *h = (EngDHdr *)a - 1;
        if (h->count)
            a->vt->vec_dtor(a, 3);
        else
            ts4_registry_dispatch_888860A0(h);
        self->arr = 0;
        self->n = 0;
    }
}
