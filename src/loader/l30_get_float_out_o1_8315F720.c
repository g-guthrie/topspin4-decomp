/* Loader_DLL.xex 0x8315F720-0x8315F888, executable version 0.0.0.3. */
extern int fn_831621C8(int p, float *out);
extern int fn_83162280(int p, float *out);
extern int fn_83162328(int p, float *out);
extern int fn_831623D0(int p, float *out);
extern int fn_83162428(int p, float *out);
extern int fn_83162560(int p, float *out);

float ts4l_get_float_out_o1_8315F720(int *self)
{
    float val;
    int r;
    r = fn_831621C8(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}

float ts4l_get_float_out_o1_8315F768(int *self)
{
    float val;
    int r;
    r = fn_83162280(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}

float ts4l_get_float_out_o1_8315F7B0(int *self)
{
    float val;
    int r;
    r = fn_83162328(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}

float ts4l_get_float_out_o1_8315F7F8(int *self)
{
    float val;
    int r;
    r = fn_831623D0(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}

float ts4l_get_float_out_o1_8315F840(int *self)
{
    float val;
    int r;
    r = fn_83162428(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}

float ts4l_get_float_out_o1_8315F888(int *self)
{
    float val;
    int r;
    r = fn_83162560(self[1], &val);
    if (r != 0) {
        self[0] = r;
    }
    return val;
}
