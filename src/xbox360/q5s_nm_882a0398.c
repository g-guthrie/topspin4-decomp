/* Swing_DLL.xex 0x882A0398: handler of the "{BeginCaptureFileCreation}" tag (registered by fn_882A0468).
 * Parses the argument with atoi (ts4_tailcall_fn_88564B00_88564770 = strtol(s, 0, 10)), caps it at 0x27FD8
 * with a MIN macro that evaluates the parse twice, stores it in the capture size global and returns 1.
 * Built /O1: the 64-bit unsigned MIN operand is what gives the extsw on the second parse result. */

extern int ts4_tailcall_fn_88564B00_88564770(const char *s);
extern int lbl_88C45E84; /* capture file size */

#define TS4_CAPTURE_SIZE_MAX 0x27FD8
#define TS4_MIN(a, b) ((a) < (b) ? (a) : (b))

int ts4_tag_begin_capture_file_creation_882A0398(const char *arg)
{
    lbl_88C45E84 = (int)TS4_MIN((unsigned long long)ts4_tailcall_fn_88564B00_88564770(arg), TS4_CAPTURE_SIZE_MAX);
    return 1;
}
