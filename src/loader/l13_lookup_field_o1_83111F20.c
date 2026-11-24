/* Loader_DLL.xex 0x83111F20-0x83113010, executable version 0.0.0.3. */
extern int lbl_8352F7E8;
extern int lbl_8352F7EC;
extern int lbl_8352F7F0;
extern int lbl_8352F7A8;
extern char *fn_83111448(void *self, int key);

long ts4l_lookup_field_83111F20(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7E8);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0x4);
    return 0;
}

long ts4l_lookup_field_83112230(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7EC);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0x4);
    return 0;
}

long ts4l_lookup_field_83112298(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7F0);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0x4);
    return 0;
}

long ts4l_lookup_field_83112E80(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7A8);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0x11c);
    return 0;
}

long ts4l_lookup_field_83112F58(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7A8);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0xe8);
    return 0;
}

long ts4l_lookup_field_83113010(void *self, int *out)
{
    char *r;

    if (out == 0) {
        return 0x80070057;
    }
    r = fn_83111448(self, lbl_8352F7A8);
    if (r == 0) {
        return 0x80300016;
    }
    *out = *(int *)(r + 0xec);
    return 0;
}
