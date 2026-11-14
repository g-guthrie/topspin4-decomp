/* Loader_DLL.xex 0x83112130-0x83166248, executable version 0.0.0.3. */
typedef struct b1_ent { char pad[0xc]; unsigned long a; unsigned long b; } b1_ent;
extern unsigned long lbl_8352F7C4;
extern b1_ent *fn_83111448(void *, unsigned long);

int ts4l_lookup_pair_83112130(void *self, unsigned long *a, unsigned long *b)
{
    b1_ent *e;
    if (a == 0 || b == 0) {
        return 0x80070057;
    }
    *a = 0;
    *b = 0;
    if ((e = fn_83111448(self, lbl_8352F7C4)) == 0) {
        return 0x80300016;
    }
    *a = e->a;
    *b = e->b;
    return 0;
}
extern void fn_83166068(void *, int *, int *, int);

void ts4l_rect_scale_norm_831661B8(void *self, int x, int y, int w, int h, int *r)
{
    int t[4];
    int a;
    int b;
    int c;
    int x2;
    int y2;
    x2 = x + w;
    y2 = y + h;
    t[0] = x << 4;
    t[1] = y << 4;
    t[2] = x2 << 4;
    t[3] = y2 << 4;
    fn_83166068(self, t, r, 2);
    a = r[0];
    b = r[2];
    if (a > b) {
        r[0] = b;
        r[2] = a;
    }
    if (r[1] > r[3]) {
        c = r[1];
        r[1] = r[3];
        r[3] = c;
    }
}
