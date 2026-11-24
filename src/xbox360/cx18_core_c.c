/* CW18 part c: script callback and small flow-database helpers (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cx18LuaCtx { u32 pad[0x6c / 4]; u32 **state; } Cx18LuaCtx;
typedef struct Cx18LuaArg { Cx18LuaCtx *ctx; } Cx18LuaArg;
typedef struct Cx18Flags { u8 on; } Cx18Flags;
typedef struct Cx18Game { u8 pad[0x24]; Cx18Flags *flags; } Cx18Game;
extern Cx18Game *lbl_88D459E8;
extern double ts4_lua_tonumber_88822420(u32 *obj, u32 idx);
extern void fn_8884FC28(void *game, int value, int flag);

/* 0x88853D30: script callback; when the game's flag byte is 1, forward argument 1 as an integer */
u32 ts4_script_cb_88853D30(void *unused, Cx18LuaArg *a)
{
    u32 **s = a->ctx->state;
    int value = (int)ts4_lua_tonumber_88822420(*s, 1);
    (void)unused;
    if (lbl_88D459E8->flags->on == 1) fn_8884FC28(lbl_88D459E8, value, 0);
    return 0;
}

/* ---- self-relative slot table found through ts4_hash_find_null_888689F8: 0x40-byte slots, flag byte at +0x3c ---- */
extern int *ts4_hash_find_null_888689F8(u32 idx);

/* 0x88868FA8: flag byte of slot idx in the found table, or 0 when there is none */
u8 ts4_slot_flag_88868FA8(u32 idx)
{
    u8 result = 0;
    int *t = ts4_hash_find_null_888689F8(idx);
    if (t != 0) result = *((u8 *)t + (idx * 0x40 + *t) + 0x3c);
    return result;
}

/* ---- record with a self-relative name at +8 (the "own = &field; name = off != -1 ? base + off : default" idiom) ---- */
typedef struct Cx18NamedRec { u8 pad0[8]; int name_off; u32 fc; } Cx18NamedRec;
typedef struct Cx18NamedOut { u8 pad0[4]; u32 f4; } Cx18NamedOut;
extern const char lbl_880C1320[];
extern void fn_8885B4A8(Cx18NamedRec *self, Cx18NamedOut *out);
extern void fn_88852498(const char *name, Cx18NamedOut *out);

/* 0x8885E200: fill the output from the record, then format its name and copy the word at +0xc */
void ts4_named_rec_fill_8885E200(Cx18NamedRec *self, Cx18NamedOut *out)
{
    const char *name;
    int *own;
    fn_8885B4A8(self, out);
    own = &self->name_off;
    name = *own != -1 ? (char *)own + *own : lbl_880C1320;
    fn_88852498(name, out);
    out->f4 = self->fc;
}
