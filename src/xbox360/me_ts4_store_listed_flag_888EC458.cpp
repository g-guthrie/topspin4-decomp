/* 0x888EC458: pick the selector hash (0xC7EFB4C9 for info key 0xF5BF4F97, else 0xB67D10C7), ask whether the member is listed, and store the result byte into the 0x97C5138C entry for that key in the null-hash self-relative table. Matched /Oc .cpp (agBJ). The hash is a one-word class built by a ternary of temporaries (cx14_core_c.c declares the same parameter as u32; same ABI). */
struct Hash { unsigned h; Hash(unsigned x) : h(x) {} };
typedef struct { unsigned name; int x4; unsigned key; unsigned char val; } Ent;
typedef struct { int rel; int n; } Tab;
typedef struct { char p[0xc]; unsigned key; } Info;
extern "C" void *lbl_88D459E0;
extern "C" Info *fn_888E3848(void);
extern "C" unsigned int ts4_member_is_listed_8883DDA0(void *self, int a, Hash k);
extern "C" Tab *ts4_hash_find_null_888E39F8(void);
static Ent *tbegin(Tab *t) { Ent *e = 0; if (t->rel != -1) e = (Ent *)((char *)t + t->rel); return e; }
static Ent *tend(Tab *t) { Ent *e = 0; if (t->rel != -1) e = (Ent *)((char *)t + t->rel) + t->n; return e; }
extern "C" void fn_888EC458(void *o)
{
    unsigned key = fn_888E3848()->key;
    unsigned v;
    Hash k = (key == 0xF5BF4F97) ? Hash(0xC7EFB4C9) : Hash(0xB67D10C7);
    Tab *t;
    Ent *e, *end;
    v = ts4_member_is_listed_8883DDA0(lbl_88D459E0, (int)o, k);
    t = ts4_hash_find_null_888E39F8();
    end = tend(t);
    for (e = tbegin(t); e != end; e++) {
        if (key == e->key && e->name == 0x97C5138C) { e->val = (unsigned char)v; break; }
    }
}
