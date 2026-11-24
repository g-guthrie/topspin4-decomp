/* CW48 part f: format-text wrapper, LTCG route (context src/xbox360/cw1_ctx_format_text.c). */
typedef unsigned int u32;
extern char g_ts4_tsu_format[];
extern void ts4_format_text(char *buffer, u32 size, const char *format, const char *text, u32 value);

/* 0x887784E8: format "text + 1, value" into the caller's 0x20-byte buffer, return the buffer */
char *ts4_format_into_887784E8(const char *text, u32 value, char *out)
{
    ts4_format_text(out, 0x20, g_ts4_tsu_format, text + 1, value);
    return out;
}

