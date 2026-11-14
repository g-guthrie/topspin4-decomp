/* Swing_DLL.xex 0x881507F0-0x88150878, executable version 0.0.0.3. */
typedef unsigned int u32;
struct entry { u32 pad; u32 key; };
struct vec { struct entry **first; struct entry **last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
void ts4_vec_remove_key_881507F0(struct vec *v, u32 key)
{
    struct entry **p = v->first;
    if (p != v->last) {
        do {
            if ((*p)->key == key) {
                struct entry **next = p + 1;
                if (next != v->last) {
                    fn_88562DC0(p, next, (u32)((char *)v->last - (char *)next));
                }
                v->last = v->last - 1;
                return;
            }
            p++;
        } while (p != v->last);
    }
}
