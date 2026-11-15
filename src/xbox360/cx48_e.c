/* CW48 part e: format-text wrappers, plain route. */
typedef unsigned int u32;
extern char g_ts4_tsu_format[];
extern void ts4_format_text(char *buffer, u32 size, const char *format, const char *text, u32 value);
extern u32 fn_88608590(void *a, void *b);

typedef struct Cx48Scratch { char reserved[0x30]; char buffer[0x20]; } Cx48Scratch;

/* 0x88779FD0: format into a stack buffer and store the hash of it */
u32 *ts4_format_hash_store_88779FD0(u32 *out, const char *text, u32 value)
{
    Cx48Scratch scratch;
    ts4_format_text(scratch.buffer, sizeof(scratch.buffer), g_ts4_tsu_format, text + 1, value);
    *out = fn_88608590(0, scratch.buffer);
    return out;
}
