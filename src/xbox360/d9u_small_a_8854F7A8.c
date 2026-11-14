/* Swing_DLL.xex 0x8854F7A8-0x88609C4C, executable version 0.0.0.3. */
typedef struct Ts4Rec16 { float a, b, c, d; } Ts4Rec16;
typedef struct Ts4RecVec { Ts4Rec16 *data; int count; } Ts4RecVec;
void ts4_recvec_sub_d_8854F7A8(Ts4RecVec *v, float f)
{
    int i;
    for (i = 0; i < v->count; ++i) {
        v->data[i].d = v->data[i].d - f;
    }
}
typedef struct Ts4IntTab { int *data; int pad; int n; } Ts4IntTab;
void ts4_inttab_clear_885E7A90(Ts4IntTab *t)
{
    int i;
    for (i = 0; i < t->n + 1; ++i) {
        t->data[i] = -1;
    }
    t->pad = 0;
}
typedef struct Ts4Rec12 { int a, b, c; } Ts4Rec12;
typedef struct Ts4Cursor { Ts4Rec12 *begin; Ts4Rec12 *end; char pad[0x818]; int cur; } Ts4Cursor;
Ts4Rec12 *ts4_cursor_next_88609C08(Ts4Cursor *c)
{
    Ts4Rec12 *r = 0;
    c->cur = c->cur + 1;
    if ((c->end - c->begin) > c->cur) { r = c->begin + c->cur; }
    return r;
}
