/* Swing_DLL.xex 0x881F2920-0x881F3338, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

extern char *fn_881F5D60(void *key);

void ts4_set_float_field_881F2920(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 4) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F29A8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 8) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2A30(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 12) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2AB8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 16) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2B40(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 20) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2BC8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 24) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2C50(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 28) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2CD8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 32) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2D60(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 36) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2DE8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 40) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2E70(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 44) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2EF8(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 48) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F2F80(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 52) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F3008(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 56) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F3090(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 60) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F3118(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 64) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F31A0(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 68) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F3228(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 72) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F32B0(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 76) = v.i;
    key[35] |= 128;
}

void ts4_set_float_field_881F3338(void *unused, u8 *key, float *value)
{
    union { int i; float f; } v;
    char *slot = fn_881F5D60(key);
    (void)unused;
    v.f = *(volatile float *)((char *)value + 0);
    *(int *)(slot + 80) = v.i;
    key[35] |= 128;
}
