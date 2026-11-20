/* Loader_DLL.xex 0x83201560-0x832015D0, executable version 0.0.0.3. */
extern void *fn_8340D710(int, int);
typedef struct { volatile int owned; int pad[7]; volatile int tag; int rest[3]; } Rec;
Rec *ts4l_init_record_83201560(Rec *r, unsigned size)
{
    int owned;
    if (r != 0) {
        if (size < 0x30)
            return 0;
        owned = 0;
        goto fill;
    }
    r = (Rec *)fn_8340D710(0x30, 0x248c8000);
    if (r == 0)
        goto done;
    owned = 1;
fill:
    r->tag = -1;
    r->owned = owned;
done:
    return r;
}
