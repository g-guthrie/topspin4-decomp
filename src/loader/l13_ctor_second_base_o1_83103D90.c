/* Loader_DLL.xex 0x83103D90-0x831090A8, executable version 0.0.0.3. */
extern void fn_8315D190(void *p);
extern void fn_8315D1F0(void *p);
extern void fn_8315D260(void *p);
extern void fn_8315D2C0(void *p);
extern void fn_8315D388(void *p);
extern void fn_8315D400(void *p);
extern void fn_8315D470(void *p);

void *ts4l_ctor_second_base_83103D90(char *self)
{
    char *b = self + 4;

    fn_8315D190(b);
    *(int *)(self + 0xac) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_83103F10(char *self)
{
    char *b = self + 4;

    fn_8315D1F0(b);
    *(int *)(self + 0xb8) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_83103FF0(char *self)
{
    char *b = self + 4;

    fn_8315D260(b);
    *(int *)(self + 0xac) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_831040B8(char *self)
{
    char *b = self + 4;

    fn_8315D2C0(b);
    *(int *)(self + 0xa8) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_831042F0(char *self)
{
    char *b = self + 4;

    fn_8315D388(b);
    *(int *)(self + 0xb4) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_83104520(char *self)
{
    char *b = self + 4;

    fn_8315D400(b);
    *(int *)(self + 0xb4) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}

void *ts4l_ctor_second_base_831090A8(char *self)
{
    char *b = self + 4;

    fn_8315D470(b);
    *(int *)(self + 0xb4) = 0;
    if (b != 0) {
        *(unsigned *)(b + 8) |= 1;
    }
    return self;
}
