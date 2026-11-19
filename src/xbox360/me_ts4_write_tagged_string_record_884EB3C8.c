/* 0x884EB3C8: Writes a string record to the writer stream: i32 len+7, byte 0xC0, i32 tag, u16 len, then the bytes (length capped at 0xFFFF). Returns 0. */
/* Matched on /Oc (agAH). Plain C. */
typedef struct Stream Stream;
typedef struct Writer { char p0[0x10]; Stream *stream; } Writer;
extern int fn_88421338(const char *s);
extern void ts4_stream_write_i32_a_88427418(Stream *s, int v);
extern void ts4_call_slot4_one_byte_88426FA0(Stream *s, unsigned char b);
extern void ts4_stream_write_i16_b_884273E8(Stream *s, unsigned short v);
extern void ts4_get_u32_off8_88427198(Stream *s, const void *data, int n);
int fn_884EB3C8(Writer *w, const char *text, int tag)
{
    int len = fn_88421338(text);
    if (len > 0xFFFF)
        len = 0xFFFF;
    ts4_stream_write_i32_a_88427418(w->stream, len + 7);
    ts4_call_slot4_one_byte_88426FA0(w->stream, 0xC0);
    ts4_stream_write_i32_a_88427418(w->stream, tag);
    ts4_stream_write_i16_b_884273E8(w->stream, (unsigned short)len);
    ts4_get_u32_off8_88427198(w->stream, text, len);
    return 0;
}
