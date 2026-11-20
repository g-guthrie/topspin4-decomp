/* Loader_DLL.xex 0x83141E08-0x83133230, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
struct PtrVec { u32 size; u32 cap; void **data; };
struct WStr { u16 *buf; u32 pad; u32 len; };

extern void *fn_83120558(void *p, u32 bytes);
extern void *fn_833E3A30(void *p, int c, u32 n);
extern void *fn_833E3AD0(void *d, const void *s, u32 n);
extern int fn_8311E828(void);

long ts4l_ptrvec_push_83141E08(struct PtrVec *v, void *item)
{
    u32 newcap;
    void **p;
    if (v->size == v->cap) {
        newcap = v->cap + 50;
        p = (void **)fn_83120558(v->data, newcap * 4);
        if (p == 0) return 0x8007000e;
        fn_833E3A30(p + v->cap, 0, 200);
        v->data = p;
        v->cap = newcap;
    }
    v->data[v->size] = item;
    v->size++;
    return 0;
}
