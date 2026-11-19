/* Swing_DLL.xex 0x8857E4E0: validate flags/text, check the text (8857C8D8), then route it to the direct or buffered writer
 * /O1 CRT-area; ANSI_STRING init as length = (u16)strlen then maximumLength = length */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct AnsiString {
    u16 length;
    u16 maximumLength;
    const char *buffer;
} AnsiString;

typedef struct SinkInfo { u32 pad0; int active; } SinkInfo;

typedef struct OutputState {
    u8 pad000[0x8];
    SinkInfo *sink;        /* +0x008 */
    u8 pad00C[0xA8];
    int enabled;           /* +0x0B4 */
    u8 pad0B8[0xC];
    int direct;            /* +0x0C4 */
    u8 pad0C8[0x74];
    u32 mode;              /* +0x13C */
    u32 pending;           /* +0x140 */
} OutputState;

extern OutputState lbl_88D2ECB8;
int fn_8857C8D8(AnsiString *s);
u32 fn_8857E230(u32 flags, const char *text);
void fn_8857DA00(u32 flags, const char *text, int len);

u32 fn_8857E4E0(u32 flags, const char *text)
{
    AnsiString s;
    OutputState *st;
    if ((flags & ~0xC) != 0 || flags == 0 || text == 0)
        return 0x57;
    s.buffer = text;
    s.length = (u16)strlen(text);
    s.maximumLength = s.length;
    if (!fn_8857C8D8(&s))
        return 3;
    st = &lbl_88D2ECB8;
    if (st->enabled == 0)
        return 0;
    if (st->pending != 0) {
        st->pending = 0;
        st->mode = 8;
    }
    if (st->sink->active != 0 && st->direct == 0)
        return fn_8857E230(flags, text);
    fn_8857DA00(flags, text, (int)strlen(text));
    return 0;
}
