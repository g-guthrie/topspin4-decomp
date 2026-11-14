/* Swing_DLL.xex band3 stream read and write helpers, executable version 0.0.0.3. */
struct TS4Stream;
#define TS4_AT(self, offset) ((void *)((char *)(self) + (offset)))
#define TS4_VAL(self, offset) (*(unsigned int *)((char *)(self) + (offset)))
struct TS4Stream *fn_88936BB0(struct TS4Stream *stream, void *value);
struct TS4Stream *fn_88938F38(struct TS4Stream *stream, void *value);
struct TS4Stream *fn_88939288(struct TS4Stream *stream, void *value, unsigned int extra);
struct TS4Stream *fn_88939470(struct TS4Stream *stream, void *value, unsigned int extra);
struct TS4Stream *fn_889395D8(struct TS4Stream *stream, void *value);
struct TS4Stream *fn_88939840(struct TS4Stream *stream, void *value);

void ts4_stream_sequence_889184D8(void *self, struct TS4Stream *stream)
{
    fn_88936BB0(fn_88936BB0(stream, TS4_AT(self, 0x42c)), TS4_AT(self, 0x42d));
}




void ts4_stream_sequence_889A7950(void *self, struct TS4Stream *stream)
{
    fn_88936BB0(fn_889395D8(stream, TS4_AT(self, 0x42c)), TS4_AT(self, 0x430));
}

void ts4_stream_sequence_889A7990(void *self, struct TS4Stream *stream)
{
    fn_88936BB0(fn_889395D8(stream, TS4_AT(self, 0x42c)), TS4_AT(self, 0x430));
}


