/* NEAR MISS (agAD, b167): /O1, 6 off: ref.p is loaded into r3 and copied to r30; the target loads it straight into r30. */
/* Swing_DLL.xex 0x883EA6C0: reports the memory used by a loaded set to the accounting sink (fn_8832EDB0(sink, 1, 2, bytes)):
 * the 0x28-byte header, the 0x1C-byte entries (each resolved through slot 2 into a reference whose object reports itself through
 * slot 1, released through slot 7), the 0x18-byte objects at +0x18/+0x24 (slot 1) and the 0xC-byte tables at +0x1C with
 * their word arrays. agAD: /O1. */
typedef struct Obj { const struct ObjVt *vt; } Obj;
typedef struct ObjVt { void *s0; int (*report)(Obj *o, void *sink); void *s2, *s3, *s4, *s5, *s6; void (*release)(Obj *o); } ObjVt;
typedef struct Ent { const struct EntVt *vt; char pad[0x1c - 4]; } Ent;
typedef struct EntVt { void *s0, *s1; void *(*target)(Ent *e); } EntVt;
typedef struct Ref { const void *vt; int pad; Obj *p; } Ref;
typedef struct Tab { int pad; unsigned int count; void *words; } Tab;
typedef struct Set { char pad[0x10]; Ent *ents; unsigned int nents; Obj *a; Tab *tabs; unsigned int ntabs; Obj *b; } Set;
extern const void *lbl_880398A0[];
void fn_8832EDB0(void *sink, int a, int b, unsigned int size);
Ref *ts4_if_addr_lbl_880398A0_883E7498(Ref *r, void *target);

int fn_883EA6C0(Set *s, void *sink)
{
    unsigned int i;
    int r;
    fn_8832EDB0(sink, 1, 2, 0x28);
    if (s->ents) {
        fn_8832EDB0(sink, 1, 2, s->nents * 0x1c);
        for (i = 0; i < s->nents; i++) {
            Ent *e = &s->ents[i];
            Ref ref;
            Obj *p;
            ts4_if_addr_lbl_880398A0_883E7498(&ref, e->vt->target(e));
            p = ref.p;
            if (p) {
                r = p->vt->report(p, sink);
                if (r) {
                    p->vt->release(p);
                    return r;
                }
            }
            ref.vt = lbl_880398A0;
            if (p)
                p->vt->release(p);
        }
    }
    if (s->a) {
        fn_8832EDB0(sink, 1, 2, 0x18);
        r = s->a->vt->report(s->a, sink);
        if (r)
            return r;
    }
    if (s->tabs) {
        fn_8832EDB0(sink, 1, 2, s->ntabs * 0xc);
        for (i = 0; i < s->ntabs; i++) {
            Tab *t = &s->tabs[i];
            if (t->words)
                fn_8832EDB0(sink, 1, 2, t->count * 4);
        }
    }
    if (s->b) {
        fn_8832EDB0(sink, 1, 2, 0x18);
        r = s->b->vt->report(s->b, sink);
        if (r)
            return r;
    }
    return 0;
}
