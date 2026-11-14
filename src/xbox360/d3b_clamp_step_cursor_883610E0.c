/* Swing_DLL.xex 0x883610E0-0x88361164, executable version 0.0.0.3. */
typedef struct Inner { char pad[0x1cc]; unsigned char flags; char pad2[3]; int cur; } Inner;
typedef struct Obj { Inner *p; char pad[0x27c]; int limit; unsigned char step; } Obj;
int ts4_clamp_step_cursor_883610E0(Obj *t)
{
    Inner *p = t->p;
    int cur = p->cur;
    if (cur < t->limit) {
        p->cur += t->step << 2;
        if (p->cur > t->limit) {
            p->cur = t->limit;
            p->flags |= 1;
            return 0;
        }
    } else if (cur > t->limit) {
        p->cur -= t->step << 2;
        if (p->cur < t->limit) p->cur = t->limit;
    }
    p->flags |= 1;
    return 0;
}
