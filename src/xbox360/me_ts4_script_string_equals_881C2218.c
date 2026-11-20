/* Swing_DLL.xex 0x881C2218: script string == C string: the lengths must match (the header length 12 bytes before the characters vs strlen, 0 for null), then a counted compare (885630C0) must return 0.
 * /Oc. `text ? (int)strlen(text) : 0` gives the clrrwi; the header length is read through an inline accessor. */
typedef struct StrHeader { int length; int reserved[2]; } StrHeader;
typedef struct ScriptString { char *chars; } ScriptString;
unsigned int strlen(const char *s);
int fn_885630C0(const char *a, const char *b, unsigned int n);

static __inline int script_string_length(const ScriptString *s)
{
    return ((const StrHeader *)s->chars)[-1].length;
}

int ts4_script_string_equals(const ScriptString *self, const char *text)
{
    int n = script_string_length(self);
    if (n != (text ? (int)strlen(text) : 0))
        return 0;
    return fn_885630C0(self->chars, text, n) == 0;
}
