/* Swing_DLL.xex 0x8819B3F8: ReleaseBuffer: sets the header length (12 bytes before the characters) to the C-string length of the buffer, or 0 when it is null, and writes the terminator there.
 * /Oc. A hand-written length loop (no clrrwi) rather than the strlen intrinsic. */
typedef struct StrHeader { int length; int reserved[2]; } StrHeader;
typedef struct ScriptString { char *chars; } ScriptString;

static __inline int cstr_length(const char *s)
{
    const char *e = s;
    while (*e++)
        ;
    return e - s - 1;
}

void fn_8819B3F8(ScriptString *self)
{
    char *p = self->chars;
    int n = p ? cstr_length(p) : 0;
    ((StrHeader *)p)[-1].length = n;
    self->chars[n] = 0;
}
