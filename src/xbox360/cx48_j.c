/* CW48 part j: owner-child walk, own file so callers keep an external call. */
typedef unsigned int u32;
typedef unsigned char u8;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
extern void fn_88771868(void *obj, u32 key);

/* 0x88773A18: for each child whose id at +0x24 equals *key, either notify it or copy the default from its record */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void fn_88773A18(char *self, u32 *key)
{
    char *o = *(char **)(self + 0x10);
    if (o != 0) {
        int n = (int)(W(o, 0x44) - W(o, 0x40)) >> 2;
        if (n > 0) {
            u32 i = 0;
            int cnt = n;
            do {
                char *e;
                u32 k = *key;
                e = *(char **)(*(char **)(*(char **)(self + 0x10) + 0x40) + i);
                if (k == W(e, 0x24)) {
                    char *rec = *(char **)e;
                    if (rec != 0) {
                        if (B(rec, 0x30) == 1) fn_88771868(e, 0xfebb7184u);
                        else W(e, 0xc) = W(rec, 0x34);
                    }
                }
                i += 4;
            } while (--cnt != 0);
        }
    }
}
