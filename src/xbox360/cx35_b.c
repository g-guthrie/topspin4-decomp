/* CW35 part b: script handlers and small helpers in 0x88790000-0x887B0000. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct lua_State lua_State;
typedef struct Frame { lua_State **L; int idx; } Frame;
typedef struct Args { void *pad[2]; Frame f1; Frame f2; } Args;
typedef struct Out { int v[2]; } Out;

extern double ts4_lua_tonumber_88822420(lua_State *L, int idx);
extern int ts4_lua_toboolean_88822398(lua_State *L, int idx);
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);
extern void ts4_loop_call_seq_u32_off0_881B1B68(Out *out, void *self, void *p);

typedef struct Cf { char pad[0x1c]; char f1c[0x20]; } Cf;
extern Cf *lbl_88D45A60;

int ts4_script_pick_conf_887AB358(void *self, Args *a)
{
    char *p = lbl_88D45A60->f1c;
    char *q;
    Out o;
    if (ts4_lua_toboolean_88822398(*a->f1.L, a->f1.idx)) {
        q = p + 0x16;
    } else {
        q = p + 6;
    }
    ts4_loop_call_seq_u32_off0_881B1B68(&o, self, q);
    return 1;
}

typedef struct Tbl { u32 off; u32 count; } Tbl;
typedef struct Svc234 { char pad[0x234]; Tbl **p; } Svc234Dummy;
typedef struct Svc { char pad[0x234]; struct Sub *f234; } Svc;
typedef struct Sub { char pad[0x38]; Tbl *t; } Sub;
extern Svc *lbl_88D45B1C;

int ts4_script_row_field_887A7578(void *self, Args *a)
{
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    Tbl *t = lbl_88D45B1C->f234->t;
    char *e = (char *)t + (n * 0xb0 + t->off);
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, *(int *)(e + 0xc));
    }
    return 1;
}

typedef struct Row { char pad[0x10]; int f10; } Row;
extern Row *fn_88614938(void *tbl, int n);

int ts4_script_row_lookup_887A75F0(void *self, Args *a)
{
    int n = (int)ts4_lua_tonumber_88822420(*a->f1.L, a->f1.idx);
    Row *r = fn_88614938(lbl_88D45B1C->f234, n);
    int v;
    if (r) {
        v = r->f10;
    } else {
        v = -1;
    }
    {
        Out o;
        ts4_call_seq_u32_off0_881B1A98(&o, self, v);
    }
    return 1;
}

typedef struct Handle12 { u32 a, b, c; } Handle12;
typedef struct HEnt { char pad[0x44]; char f44[0xc]; char f50[4]; } HEnt;
extern void *lbl_88D458F0;
extern HEnt *ts4_hash_find_881AB900(void *table, u32 hash, Handle12 h);
extern void ts4_rel_array_assign_881ACC00(void *dst, void *src);
extern void fn_881881C8(void *dst, void *src);

u32 ts4_hash_copy_44_88790EE0(void)
{
    Handle12 h;
    HEnt *a, *b;
    h.a = 0; h.b = 0xFFFFF; h.c = 0;
    a = ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14, h);
    h.a = 0; h.b = 0xFFFFF; h.c = 0;
    b = ts4_hash_find_881AB900(lbl_88D458F0, 0xA24E42DC, h);
    ts4_rel_array_assign_881ACC00(a->f44, b->f44);
    return 0;
}

u32 ts4_hash_copy_50_88790F68(void)
{
    Handle12 h;
    HEnt *a, *b;
    h.a = 0; h.b = 0xFFFFF; h.c = 0;
    a = ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14, h);
    h.a = 0; h.b = 0xFFFFF; h.c = 0;
    b = ts4_hash_find_881AB900(lbl_88D458F0, 0xA24E42DC, h);
    fn_881881C8(a->f50, b->f50);
    return 0;
}
