/* NEAR MISS (agBD, 2 off): twin of 888D7230 with event hash 0xAD796EEF; same load-order issue. */
typedef struct Ev { unsigned int a; unsigned int hash; unsigned int id; int c; unsigned int d; int e; float f0, f1, f2; unsigned char b; unsigned int g; float w; } Ev;
typedef struct St { char pad[0x26c]; unsigned int hash; } St;
typedef struct Obj { char pad[0x1c]; void *h; char p1[0x40]; St *st; char p2[0xcc]; unsigned int cur; char p3[7]; unsigned char busy; char p4[4]; unsigned char on; } Obj;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
void fn_888CC9D8(Obj *o, Ev *e);
void fn_888D72F0(Obj *o, unsigned int *id)
{
    Ev e;
    if (o->h && o->on && o->st->hash == 0x39A2A9F0 && !o->busy && *id != o->cur) {
        e.id = *id;
        e.a = 0;
        e.f0 = lbl_8814B440;
        e.c = -1;
        e.f1 = lbl_8814B440;
        e.d = 0;
        e.f2 = lbl_8814B440;
        e.e = -1;
        e.w = g_ts4_script_constants[0];
        e.b = 0;
        e.g = 0;
        e.hash = 0xAD796EEF;
        fn_888CC9D8(o, &e);
    }
}
