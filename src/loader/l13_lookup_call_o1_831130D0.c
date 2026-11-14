/* Loader_DLL.xex 0x831130D0-0x83113D08, executable version 0.0.0.3. */
extern int lbl_8352F7A8;
extern int ts4_get_u32_offf0_831213E0(char *r);
extern int lbl_835310A4;
extern int ts4_get_u32_off18_83121E08(char *r);
extern int ts4_get_u32_off1c_83121E30(char *r);
extern char *fn_83111448(void *self, int key);

long ts4l_lookup_call_831130D0(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7A8);
    if (r == 0) {
        return 0x80300016;
    }
    *out = ts4_get_u32_offf0_831213E0(r);
    return 0;
}

long ts4l_lookup_call_83113C48(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_835310A4);
    if (r == 0) {
        return 0x80300016;
    }
    *out = ts4_get_u32_off18_83121E08(r);
    return 0;
}

long ts4l_lookup_call_83113D08(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_835310A4);
    if (r == 0) {
        return 0x80300016;
    }
    *out = ts4_get_u32_off1c_83121E30(r);
    return 0;
}
