/* Loader_DLL.xex 0x83104830-0x83104960, executable version 0.0.0.3. */
extern char lbl_830010A0[];
extern void ts4l_call_seq_fn_83140430_831404E8(void *obj, int v);
extern char lbl_830010A8[];
extern void ts4l_call_seq_fn_83140430_83140530(void *obj, int v);
extern char lbl_830010B8[];
extern void ts4l_call_seq_fn_83140430_831405C0(void *obj, int v);
extern int ts4l_forward_varargs_833E4550(const char *s, const char *fmt, int *out);

long ts4l_parse_int_set_83104830(const char *s, void *obj)
{
    int v;

    if (ts4l_forward_varargs_833E4550(s, lbl_830010A0, &v) < 1) {
        return 0x80300003;
    }
    ts4l_call_seq_fn_83140430_831404E8(obj, v);
    return 0;
}

long ts4l_parse_int_set_83104890(const char *s, void *obj)
{
    int v;

    if (ts4l_forward_varargs_833E4550(s, lbl_830010A8, &v) < 1) {
        return 0x80300003;
    }
    ts4l_call_seq_fn_83140430_83140530(obj, v);
    return 0;
}

long ts4l_parse_int_set_83104960(const char *s, void *obj)
{
    int v;

    if (ts4l_forward_varargs_833E4550(s, lbl_830010B8, &v) < 1) {
        return 0x80300003;
    }
    ts4l_call_seq_fn_83140430_831405C0(obj, v);
    return 0;
}
