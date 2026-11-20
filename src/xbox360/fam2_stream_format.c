/* FAM2: stream insertion helpers.  Each one formats a single value into a
 * 0x2728-byte stack buffer with a fixed format string, then writes the text
 * to the stream's sink at +0x8 through sink vtable slot 4 (write). */
typedef unsigned int u32;

typedef struct Ts4Sink Ts4Sink;
typedef struct Ts4SinkVtbl {
    void *slot[4];
    void (*write)(Ts4Sink *sink, const char *text, u32 len);
} Ts4SinkVtbl;
struct Ts4Sink {
    Ts4SinkVtbl *vtbl;
};

typedef struct Ts4TextStream {
    u32 f00, f04;
    Ts4Sink *sink;
} Ts4TextStream;

extern void ts4_forward_varargs_88421058(char *buf, u32 size, const char *fmt, ...);
extern u32 fn_88421338(const char *buf);

#define TS4_STREAM_FORMAT_T(A, T, FMT) \
extern const char FMT[]; \
Ts4TextStream *ts4_stream_format_##A(Ts4TextStream *self, T value) \
{ \
    char buf[0x2728]; \
    Ts4Sink *sink; \
    ts4_forward_varargs_88421058(buf, sizeof(buf), FMT, value); \
    sink = self->sink; \
    sink->vtbl->write(sink, buf, fn_88421338(buf)); \
    return self; \
}


TS4_STREAM_FORMAT_T(8841CF08, u32, lbl_8803DDDC)
TS4_STREAM_FORMAT_T(8841D1A8, u32, lbl_880D72A0)
TS4_STREAM_FORMAT_T(8841D210, u32, lbl_880D5854)
TS4_STREAM_FORMAT_T(8841D2E0, u32, lbl_8803DDE0)
TS4_STREAM_FORMAT_T(8841D348, u32, lbl_880D6B60)
TS4_STREAM_FORMAT_T(8841D0D8, short, lbl_880D72A0)
TS4_STREAM_FORMAT_T(8841D140, unsigned short, lbl_880D5854)
TS4_STREAM_FORMAT_T(8841D278, double, lbl_880D5858)

/* Insert a C string; a null pointer prints as the 6-character "(null)". */
#define TS4_STREAM_PUT_CSTR(stream, s) \
    do { \
        Ts4Sink *sink_ = (stream)->sink; \
        if (s) \
            sink_->vtbl->write(sink_, (s), fn_88421338(s)); \
        else \
            sink_->vtbl->write(sink_, lbl_88029198, 6); \
    } while (0)

extern const char lbl_88029198[];
extern const char g_ts4_true_string[];
extern const char lbl_880D1B30[];

Ts4TextStream *ts4_stream_bool_8841CF70(Ts4TextStream *self, char value)
{
    const char *s = value ? g_ts4_true_string : lbl_880D1B30;
    TS4_STREAM_PUT_CSTR(self, s);
    return self;
}
