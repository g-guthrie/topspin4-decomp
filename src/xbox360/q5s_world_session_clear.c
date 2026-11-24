/*
 * 0x88890CB0: tears down a pres session record {ref, count, lists} (called from 887F2C48 and 88890DB0).
 * Releases the shared object at +0 (if its shared flag is set, drop one reference and call its deleting
 * destructor, slot 0, with 1 when it reaches zero), clears the pointer, empties each of the `count`
 * pair vectors (STLport clear() = erase(begin(), end())) and frees the vector array with the array
 * delete: count word before the data, element destructors in reverse order, then operator delete[].
 * The same record's lists are edited by 0x888905C0 (q5s_world_pair_lists.cpp).
 * LTCG route. The `session` copy of the parameter (and which of the two names each access uses) is load-bearing:
 * without it the vector address comes out
 * as `add r8,offset,lists` instead of `add r8,lists,offset` (found by tools/regalloc_mutate.py, family alias).
 */
typedef unsigned int u32;

typedef struct Ts4WorldShared {
    void (**vt)(struct Ts4WorldShared *, int);   /* slot 0: deleting destructor */
    unsigned short shared;                       /* +0x04 V 88890CB0 (cf. ctor 888907A0 setting +6 = 1) */
    short refs;                                  /* +0x06 V 88890CB0 888907A0 */
} Ts4WorldShared;

typedef struct Ts4WorldPair {
    u32 a;
    u32 b;
} Ts4WorldPair;

typedef struct Ts4WorldPairVec {
    Ts4WorldPair *first;
    Ts4WorldPair *last;
    Ts4WorldPair *end_cap;
} Ts4WorldPairVec;

typedef struct Ts4WorldSession {
    Ts4WorldShared *ref;                         /* +0x00 V 88890CB0 */
    u32 count;                                   /* +0x04 V 88890CB0 */
    Ts4WorldPairVec *lists;                      /* +0x08 V 88890CB0 888905C0 */
} Ts4WorldSession;

void ts4_destroy_owned_object(void *p);
void ts4_registry_dispatch_888860A0(void *p);

static Ts4WorldPair *world_pair_copy(Ts4WorldPair *first, Ts4WorldPair *last, Ts4WorldPair *result)
{
    int n;
    for (n = last - first; n > 0; --n) {
        *result = *first;
        ++first;
        ++result;
    }
    return result;
}

void ts4_pres_session_clear_88890CB0(Ts4WorldSession *self)
{
    Ts4WorldSession *session = self;
    Ts4WorldShared *r = self->ref;
    u32 i, n;
    if (r->shared) {
        if (--r->refs == 0)
            r->vt[0](r, 1);
    }
    session->ref = 0;
    n = session->count;
    for (i = 0; i < n; i++) {
        Ts4WorldPairVec *v = &session->lists[i];
        v->last = world_pair_copy(v->last, v->last, v->first);
    }
    if (session->lists) {
        u32 *hdr = (u32 *)session->lists - 1;
        int k = (int)*hdr;
        Ts4WorldPairVec *e = self->lists + k;
        while (--k >= 0) {
            --e;
            if (e->first)
                ts4_destroy_owned_object(e->first);
        }
        ts4_registry_dispatch_888860A0(hdr);
    }
}
