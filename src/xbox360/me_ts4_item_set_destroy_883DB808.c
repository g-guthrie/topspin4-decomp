/* 0x883DB808: detaches and resets every item of the array at +0x10 (count +8), frees the array, releases the object at +0x14 (vtable slot 3) and frees the set itself */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the first item error; the released object is read into a local (the member form adds a clrrwi). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039444[];
typedef struct D D;
typedef struct DVt { void *f[3]; void (*release)(D *d); } DVt;
struct D { DVt *vt; };
typedef struct T { char pad[8]; unsigned int n; int pc; void **items; D *d; } T;
int ts4_if_get_u32_offa8_883C6DE8(void *o);
int fn_883CD3F0(void *o, int a, int b, int c);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_item_set_destroy_883DB808(T *t)
{
    unsigned int i;
    int r;
    if (t->items) {
        for (i = 0; i < t->n; ++i) {
            if (t->items[i]) {
                r = ts4_if_get_u32_offa8_883C6DE8(t->items[i]);
                if (r) return r;
                r = fn_883CD3F0(t->items[i], 0, 1, 0);
                if (r) return r;
            }
        }
        fn_88315F10(lbl_88B3302C->heap, t->items, lbl_88039444, 0x5d);
    }
    { D *d = t->d; if (d) d->vt->release(d); }
    fn_88315F10(lbl_88B3302C->heap, t, lbl_88039444, 0x65);
    return 0;
}
