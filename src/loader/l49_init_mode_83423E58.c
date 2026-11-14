/* Loader_DLL.xex 0x83423E58-0x83423F10, executable version 0.0.0.3. */
/* Initialise a context for mode 0/1 (allocate buffer) or mode 2 (copy a value). */
typedef struct Ts4lCtx {
    int pad[3];
    int state;
    int value;
    void *buf;
} Ts4lCtx;
extern void *fn_8340D710(unsigned size, unsigned tag);
extern int fn_8343F8F8(int n);
extern int fn_8342AF68(Ts4lCtx *c, int *v, int flag);
int ts4l_init_mode_83423E58(Ts4lCtx *c, int *v, unsigned mode)
{
    int r;
    if (mode == 0 || mode == 1) {
        c->buf = fn_8340D710(0x10000, 0x24810000);
        if (c->buf == 0)
            return (int)0x8007000e;
        r = fn_8342AF68(c, v, mode == 1);
        if (r < 0)
            return r;
        c->state = 1;
        return 0;
    }
    if (mode == 2) {
        r = fn_8343F8F8(0x400);
        if (r < 0)
            return r;
        {
            int t = *v;
            c->state = 2;
            c->value = t;
        }
        return 0;
    }
    return (int)0x80004005;
}
