/* CW18 LTCG route, context: src/xbox360/cw1_ctx_format_text.c (varargs shape of ts4_format_text). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern void *ts4_memset(void *dst, int c, u32 n);
extern const char lbl_880D312C[]; /* "%d" */
extern const char lbl_880DFE28[]; /* "Media\\BinData\\Save\\%s\\" */
extern const char lbl_880DFE40[]; /* "%s%u\\" */

extern const char lbl_880D1CEC[]; /* "PlayerCreated%d" */
extern void *fn_88923380(void *out, u32 src);
extern void fn_8884EB98(void *self, const char *name, void *handle);

typedef struct Cx18Svc { u8 pad[0x234]; void *mid; } Cx18Svc;
extern Cx18Svc *lbl_88D45B1C;
typedef struct Cx18Rec { u8 pad[0x10]; int v; } Cx18Rec;
extern Cx18Rec *ts4_pad_record_find_88614938(void *mid, u32 id);
extern void ts4_format_record_value_88865760(u32 id, char *buf, u32 size);
extern void ts4_format_save_dir_88866980(u32 id, char *out, u32 size);

/* 0x88865760: clear the buffer, look up the record for the id and format its value at +0x10 (or -1) as "%d" */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_format_record_value_88865760(u32 id, char *buf, u32 size)
{
    Cx18Rec *r;
    int v;
    ts4_memset(buf, 0, size);
    r = ts4_pad_record_find_88614938(lbl_88D45B1C->mid, id);
    v = r != 0 ? r->v : -1;
    ts4_format_text(buf, size, lbl_880D312C, v);
}

/* 0x88866980: clear the destination, then format "Media\\BinData\\Save\\%s\\" with the record-value text of the id */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_format_save_dir_88866980(u32 id, char *out, u32 size)
{
    char tmp[0x200];
    ts4_format_record_value_88865760(id, tmp, 0x200);
    ts4_memset(out, 0, size);
    ts4_format_text(out, size, lbl_880DFE28, tmp);
}

/* 0x88867848: build the save-dir text for the id, then format "%s%u\\" with it and the number */
void ts4_format_save_path_88867848(u32 id, u32 number, char *out)
{
    char tmp[0x200];
    ts4_memset(tmp, 0, 0x200);
    ts4_format_save_dir_88866980(id, tmp, 0x200);
    ts4_format_text(out, 0x200, lbl_880DFE40, tmp, number);
}

/* 0x88853608: format "PlayerCreated<n>" and register it, converting the second argument through a temporary */
void ts4_register_created_player_88853608(void *self, int n, u32 src)
{
    char name[0x20];
    char tmp[0x10];
    ts4_format_text(name, 0x20, lbl_880D1CEC, n);
    fn_8884EB98(self, name, fn_88923380(tmp, src));
}
