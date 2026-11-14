/* Swing_DLL.xex 0x8861A460-0x8861A4EC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct {
    u32 key;
    char text[0x1ff + 1];
    u32 extra;
} ts4_keyed_name;
extern void *ts4_memset(void *p, int v, u32 n);
extern void ts4_normalize_dir_path_88606978(void *buf, const char *name);
extern u32 fn_88608590(u32 a, void *buf);

void ts4_keyed_name_init_8861A460(ts4_keyed_name *self, const char *name, const char *text, u32 extra)
{
    char buf[0x200];
    char *d;
    char *end;
    const char *s;
    char c;

    ts4_memset(buf, 0, 0x200);
    ts4_normalize_dir_path_88606978(buf, name);
    self->key = fn_88608590(0, buf);
    d = self->text;
    end = d + 0x1ff;
    for (s = text; d != end; ++d, ++s) {
        c = *s;
        if (c == 0)
            break;
        *d = c;
    }
    *d = 0;
    self->extra = extra;
}
