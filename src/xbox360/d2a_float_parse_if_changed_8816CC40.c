/* Swing_DLL.xex 0x8816CC40-0x8816CC40, executable version 0.0.0.3. */
extern double ts4_tailcall_fn_88564630_885646F0(const char *text);

/* Parses text as a float into *output; returns 1 if the stored value changed. */
int ts4_parse_float_if_changed_8816CC40(void *unused, float *output, const char *text)
{
    float value = (float)ts4_tailcall_fn_88564630_885646F0(text);
    (void)unused;
    if (*output != value) {
        *output = value;
        return 1;
    }
    return 0;
}
