typedef struct ByteVec { char *first; char *last; void *alloc; } ByteVec;
typedef struct Obj { void *vt; char m4[0x38]; ByteVec bytes; } Obj;
extern char lbl_880F2120[], lbl_880F3458[];
extern void *lbl_88D45B38;
void ts4_object_finalize(ByteVec *v);
void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, char *p, void *a);
void fn_885651F8(char *p);
void fn_882609C8(void *m);
static __inline void bytevec_tidy(ByteVec *v)
{
    char *b;
    ts4_object_finalize(v);
    b = v->first;
    if (b) {
        if (lbl_88D45B38)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, b, v->alloc);
        else
            fn_885651F8(b);
    }
}
void fn_88737B40(Obj *o)
{
    o->vt = lbl_880F2120;
    bytevec_tidy(&o->bytes);
    o->vt = lbl_880F3458;
    fn_882609C8(o->m4);
}
