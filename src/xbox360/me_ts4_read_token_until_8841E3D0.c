/* Swing_DLL.xex 0x8841E3D0: reads up to n characters from the stream at +8 into buf (after fn_8841DC90), stopping at end
 * (-1, returns -1) or at the terminator stop (writes a NUL and returns the count). agO: plain and LTCG. */
typedef struct Reader { char pad[8]; void *stream; } Reader;
void fn_8841DC90(void *stream);
int ts4_if_get_u32_off0_8841AD18(void *stream);

int fn_8841E3D0(Reader *r, char *buf, int n, char stop)
{
    int i;
    int c;
    fn_8841DC90(r->stream);
    for (i = 0; i < n; i++) {
        c = ts4_if_get_u32_off0_8841AD18(r->stream);
        if (c == -1 || c == stop) {
            buf[i] = 0;
            return i;
        }
        buf[i] = (char)c;
    }
    return -1;
}
