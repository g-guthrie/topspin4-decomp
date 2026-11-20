/* CW18 LTCG route, context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int Cx18Up;
#else
typedef unsigned long Cx18Up;
#endif

extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern void *ts4_memset(void *dst, int c, u32 n);
extern void ts4_format_save_dir_88866980(u32 id, char *out, u32 size);
extern const char lbl_880D9BF4[];
extern const char lbl_880DFE48[];

/* 0x888677D0: build the save-dir text for the id and format it with a fixed suffix into the output */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_format_save_name_888677D0(u32 id, char *out)
{
    char tmp[0x200];
    ts4_memset(tmp, 0, 0x200);
    ts4_format_save_dir_88866980(id, tmp, 0x200);
    ts4_format_text(out, 0x200, lbl_880D9BF4, tmp, lbl_880DFE48);
}

extern void ts4_format_save_name_888677D0(u32 id, char *out);
extern void fn_888F0EF0(char *text, u32 arg, u32 id);
extern const char lbl_880D1EE0[];

/* 0x8886B1B0: build the save-name text for the id, format it with the argument into the destination and optionally register it */
void ts4_format_save_entry_8886B1B0(u32 id, char *dst, u32 size, u32 arg, u8 register_it)
{
    char tmp[0x200];
    ts4_memset(tmp, 0, 0x200);
    ts4_format_save_name_888677D0(id, tmp);
    ts4_format_text(dst, size, lbl_880D1EE0, tmp, arg);
    if (register_it) fn_888F0EF0(tmp, arg, id);
}

extern const char lbl_880DFE40[];

/* 0x88867E68: build the save-dir text for the id, format it with the number, then format that with the last argument into the destination */
void ts4_format_save_path_entry_88867E68(u32 id, u32 number, char *dst, u32 size, u32 arg)
{
    char path[0x200];
    char dir[0x200];
    ts4_memset(path, 0, 0x200);
    ts4_memset(dir, 0, 0x200);
    ts4_format_save_dir_88866980(id, dir, 0x200);
    ts4_format_text(path, 0x200, lbl_880DFE40, dir, number);
    ts4_format_text(dst, size, lbl_880D1EE0, path, arg);
}

extern void *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void fn_886220F8(void *svc, void *p);
extern void fn_886223B0(void *svc, void *p, const char *text);

/* 0x88868148: build the save path text for the object and tell the service about its +8 member */
void ts4_announce_save_path_88868148(char *self, u32 number)
{
    char path[0x200];
    char dir[0x200];
    char *member;
    ts4_memset(dir, 0, 0x200);
    ts4_format_save_dir_88866980((u32)(Cx18Up)self, dir, 0x200);
    ts4_format_text(path, 0x200, lbl_880DFE40, dir, number);
    {
        void *svc = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
        member = self + 8;
        fn_886220F8(svc, member);
    }
    {
        void *svc2 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
        fn_886223B0(svc2, member, path);
    }
}

/* ---- 0x5c-byte entry vector of the global (entry id at +0, value at +0xc) ---- */
typedef struct Cx18Ent { u32 id; u32 pad4; u32 pad8; u32 val; u8 pad10[0x4c]; } Cx18Ent;
typedef struct Cx18EntOwner { u8 pad0[0x5c]; Cx18Ent *begin; Cx18Ent *end; } Cx18EntOwner;
typedef struct Cx18Text { u32 s; u32 pad[3]; } Cx18Text;
extern Cx18EntOwner *lbl_88D459DC;
extern void *lbl_88D45A04;
extern void fn_8816D1A8(Cx18Text *t);
extern u8 fn_887EF650(void *g, u32 a, u32 b, Cx18Text *t);
extern void ts4_destroy_owned_object(u32 s);

#ifdef _MSC_VER
#define CX18_INL static __forceinline
#else
#define CX18_INL static inline
#endif
CX18_INL u8 ent_get_val(Cx18EntOwner *o, u32 id, u32 *out)
{
    Cx18Ent *p;
    for (p = o->begin; p != o->end; p++)
        if (p->id == id) break;
    if (p != o->end) {
        *out = p->val;
        return 1;
    }
    return 0;
}

/* 0x8886A350: look up the value of the entry with this key and ask the service to format it into the destination */
u8 ts4_format_entry_text_8886A350(char *dst, u32 key, u32 arg)
{
    u32 val = 0;
    u8 ok;
    u8 found;
    void *g;
    Cx18Text t;
    found = ent_get_val(lbl_88D459DC, key, &val);
    if (!found) return 0;
    g = lbl_88D45A04;
    fn_8816D1A8(&t);
    ok = fn_887EF650(g, val, arg, &t);
    if (ok) ts4_format_text(dst, 0x200, (const char *)(Cx18Up)t.s);
    ts4_destroy_owned_object(t.s);
    return ok;
}
