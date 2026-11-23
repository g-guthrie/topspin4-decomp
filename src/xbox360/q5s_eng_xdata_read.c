/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): XData record readers (q5s eng).
 * Route: LTCG (/Oc), context src/xbox360/pp1_pool_primer.c. Spec: work/specs/Q5S/q5s_eng_xdata_read.json.
 *
 * Each XData record class has a 5-slot vtable {dtor (ts4_dtor_vtable_only_882871E0), ?, write, read, ?}.
 * Slot 2 (ts4_write_*, matched in d2d_*.c) serializes the payload fields that follow the 12-byte record
 * header; slot 3 (here) reads them back in the same order:
 *     u32 read(Record *self, const u8 *src, u32 *remaining)
 * Each field fails the whole read (0) when fewer bytes remain than the field needs; on success the consumed
 * byte count is subtracted from *remaining and 1 is returned. Field layouts mirror the writers.
 *
 * Codegen: the per-field bounds check, load/store and `*n -= size` live in one inlined helper that updates a
 * local count through a pointer; the caller advances a local cursor and finishes with `*rem -= p - src`.
 * Open-coding the check (or keeping the count by value) gives `mr r11,r3` and the field store scheduled
 * after `li r3,1` / the next compare.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

static int ts4_xread_u16(u16 *out, const u8 *p, u32 *n)
{
    if (*n < 2)
        return 0;
    *out = *(const u16 *)p;
    *n -= 2;
    return 1;
}

static int ts4_xread_u32(u32 *out, const u8 *p, u32 *n)
{
    if (*n < 4)
        return 0;
    *out = *(const u32 *)p;
    *n -= 4;
    return 1;
}

static int ts4_xread_u64(u64 *out, const u8 *p, u32 *n)
{
    if (*n < 8)
        return 0;
    *out = *(const u64 *)p;
    *n -= 8;
    return 1;
}

typedef struct Ts4XRecU16 {
    u8 pad0[0xc];                                  /* vtable + record header */
    u16 value;                                     /* +0x0C */
} Ts4XRecU16;

typedef struct Ts4XRecU32 {
    u8 pad0[0xc];
    u32 value;                                     /* +0x0C */
} Ts4XRecU32;

typedef struct Ts4XRecU16U32 {
    u8 pad0[0xc];
    u16 a;                                         /* +0x0C */
    u32 b;                                         /* +0x10 */
} Ts4XRecU16U32;

typedef struct Ts4XRecSixU16 {
    u8 pad0[0xc];
    u16 a, b, c, d, e, f;                          /* +0x0C..+0x16 */
} Ts4XRecSixU16;

/* Swing_DLL.xex 0x885FA290: slot 3 of vtable 0x880F9820 (ts4_write_u16_field_c_885FBF10). */
u32 ts4_read_u16_field_c_885FA290(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA018: slot 3 of vtable 0x880F985C (ts4_write_u16_field_c_885FBD58). */
u32 ts4_read_u16_field_c_885FA018(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F9CA0: slot 3 of vtable 0x880F98D4 (ts4_write_u16_field_c_885FBB40). */
u32 ts4_read_u16_field_c_885F9CA0(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x886016A0: slot 3 of vtable 0x880F94FC (ts4_write_u16_field_c_88601E00). */
u32 ts4_read_u16_field_c_886016A0(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88602BF0: slot 3 of vtable 0x880F9484 (ts4_write_u16_field_c_88603350). */
u32 ts4_read_u16_field_c_88602BF0(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB7E8: slot 3 of vtable 0x880F95A0 (ts4_write_u16_field_c_885FCB78). */
u32 ts4_read_u16_field_c_885FB7E8(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB330: slot 3 of vtable 0x880F962C (ts4_write_u16_field_c_885FC868). */
u32 ts4_read_u16_field_c_885FB330(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA4C0: slot 3 of vtable 0x880F97BC (ts4_write_u16_field_c_885FC0D8). */
u32 ts4_read_u16_field_c_885FA4C0(Ts4XRecU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->value, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x886013C8: slot 3 of vtable 0x880F954C (ts4_write_u32_field_c_88601C78). */
u32 ts4_read_u32_field_c_886013C8(Ts4XRecU32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->value, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB778: slot 3 of vtable 0x880F95B4 (ts4_write_u32_field_c_885FCB28). */
u32 ts4_read_u32_field_c_885FB778(Ts4XRecU32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->value, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FAD38: slot 3 of vtable 0x880F96B8 (ts4_write_u32_field_c_885FC540). */
u32 ts4_read_u32_field_c_885FAD38(Ts4XRecU32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->value, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FAB40: slot 3 of vtable 0x880F9708 (ts4_write_u32_field_c_885FC450). */
u32 ts4_read_u32_field_c_885FAB40(Ts4XRecU32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->value, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA9C8: slot 3 of vtable 0x880F9730 (ts4_write_u32_field_c_885FC388). */
u32 ts4_read_u32_field_c_885FA9C8(Ts4XRecU32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->value, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88600B20: slot 3 of vtable 0x880F9578 (ts4_write_u16_u32_fields_88600BB8). */
u32 ts4_read_u16_u32_fields_88600B20(Ts4XRecU16U32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->b, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB3A0: slot 3 of vtable 0x880F9618 (ts4_write_u16_u32_fields_885FC8B8). */
u32 ts4_read_u16_u32_fields_885FB3A0(Ts4XRecU16U32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->b, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB298: slot 3 of vtable 0x880F9640 (ts4_write_u16_u32_fields_885FC810). */
u32 ts4_read_u16_u32_fields_885FB298(Ts4XRecU16U32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->b, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA828: slot 3 of vtable 0x880F9758 (ts4_write_u16_u32_fields_885FC2B8). */
u32 ts4_read_u16_u32_fields_885FA828(Ts4XRecU16U32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->b, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F5568: slot 3 of vtable 0x880F9A78 (ts4_write_u16_u32_fields_885F6488). */
u32 ts4_read_u16_u32_fields_885F5568(Ts4XRecU16U32 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->b, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FAA38: slot 3 of vtable 0x880F971C (ts4_write_six_u16_fields_885FC3D8). */
u32 ts4_read_six_u16_fields_885FAA38(Ts4XRecSixU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->b, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->d, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->e, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA8C0: slot 3 of vtable 0x880F9744 (ts4_write_six_u16_fields_885FC310). */
u32 ts4_read_six_u16_fields_885FA8C0(Ts4XRecSixU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->b, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->d, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->e, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F99E0: slot 3 of vtable 0x880F9910 (ts4_write_six_u16_fields_885FB9F0). */
u32 ts4_read_six_u16_fields_885F99E0(Ts4XRecSixU16 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->b, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->d, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->e, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88604458: slot 3 of vtable 0x880F90DC; mirrors ts4_write_record_88604488. */
typedef struct Ts4XRec_88604458 { u8 pad10[16]; u64 f10; } Ts4XRec_88604458;
u32 ts4_read_record_88604458(Ts4XRec_88604458 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u64(&self->f10, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88603208: slot 3 of vtable 0x880F9420; mirrors ts4_write_record_886035F0. */
typedef struct Ts4XRec_88603208 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u8 pad14[2]; u32 f14; u16 f18; u16 f1a; u32 f1c; u32 f20; } Ts4XRec_88603208;
u32 ts4_read_record_88603208(Ts4XRec_88603208 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f1c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88603170: slot 3 of vtable 0x880F9434; mirrors ts4_write_record_88603598. */
typedef struct Ts4XRec_88603170 { u8 pad0[0xc]; u32 fc; u16 f10; } Ts4XRec_88603170;
u32 ts4_read_record_88603170(Ts4XRec_88603170 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88602FC0: slot 3 of vtable 0x880F9448; mirrors ts4_write_record_886034F0. */
typedef struct Ts4XRec_88602FC0 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; } Ts4XRec_88602FC0;
u32 ts4_read_record_88602FC0(Ts4XRec_88602FC0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1e, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f24, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88602E80: slot 3 of vtable 0x880F945C; mirrors ts4_write_record_88603468. */
typedef struct Ts4XRec_88602E80 { u8 pad0[0xc]; u32 fc; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } Ts4XRec_88602E80;
u32 ts4_read_record_88602E80(Ts4XRec_88602E80 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88602C60: slot 3 of vtable 0x880F9470; mirrors ts4_write_record_886033A0. */
typedef struct Ts4XRec_88602C60 { u8 pad0[0xc]; u16 fc; u16 fe; u32 f10; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; u32 f34; u32 f38; u32 f3c; u32 f40; u32 f44; } Ts4XRec_88602C60;
u32 ts4_read_record_88602C60(Ts4XRec_88602C60 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f1c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f24, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f28, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f2c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f30, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f34, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f38, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f3c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f40, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f44, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601B00: slot 3 of vtable 0x880F94AC; mirrors ts4_write_record_88601FF8. */
typedef struct Ts4XRec_88601B00 { u8 pad0[0xc]; u32 fc; u16 f10; } Ts4XRec_88601B00;
u32 ts4_read_record_88601B00(Ts4XRec_88601B00 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601900: slot 3 of vtable 0x880F94C0; mirrors ts4_write_record_88601F38. */
typedef struct Ts4XRec_88601900 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u16 f1e; u32 f20; u32 f24; u32 f28; u32 f2c; u32 f30; } Ts4XRec_88601900;
u32 ts4_read_record_88601900(Ts4XRec_88601900 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1e, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f24, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f28, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f2c, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f30, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601850: slot 3 of vtable 0x880F94D4; mirrors ts4_write_record_88601ED8. */
typedef struct Ts4XRec_88601850 { u8 pad0[0xc]; u32 fc; u32 f10; u16 f14; } Ts4XRec_88601850;
u32 ts4_read_record_88601850(Ts4XRec_88601850 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601710: slot 3 of vtable 0x880F94E8; mirrors ts4_write_record_88601E50. */
typedef struct Ts4XRec_88601710 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u32 f18; u32 f1c; } Ts4XRec_88601710;
u32 ts4_read_record_88601710(Ts4XRec_88601710 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f1c, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x886015B8: slot 3 of vtable 0x880F9510; mirrors ts4_write_record_88601D90. */
typedef struct Ts4XRec_886015B8 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u8 pad14[2]; u32 f14; u32 f18; } Ts4XRec_886015B8;
u32 ts4_read_record_886015B8(Ts4XRec_886015B8 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601508: slot 3 of vtable 0x880F9524; mirrors ts4_write_record_88601D30. */
typedef struct Ts4XRec_88601508 { u8 pad0[0xc]; u16 fc; u8 pad10[2]; u32 f10; u32 f14; } Ts4XRec_88601508;
u32 ts4_read_record_88601508(Ts4XRec_88601508 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601438: slot 3 of vtable 0x880F9538; mirrors ts4_write_record_88601CC8. */
typedef struct Ts4XRec_88601438 { u8 pad0[0xc]; u32 fc; u32 f10; u32 f14; u16 f18; } Ts4XRec_88601438;
u32 ts4_read_record_88601438(Ts4XRec_88601438 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x88601270: slot 3 of vtable 0x880F9560; mirrors ts4_write_record_88601BE8. */
typedef struct Ts4XRec_88601270 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; } Ts4XRec_88601270;
u32 ts4_read_record_88601270(Ts4XRec_88601270 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB5E8: slot 3 of vtable 0x880F95DC; mirrors ts4_write_record_885FCA70. */
typedef struct Ts4XRec_885FB5E8 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u8 pad18[2]; u32 f18; u8 pad20[4]; u64 f20; } Ts4XRec_885FB5E8;
u32 ts4_read_record_885FB5E8(Ts4XRec_885FB5E8 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u64(&self->f20, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB538: slot 3 of vtable 0x880F95F0; mirrors ts4_write_record_885FCA10. */
typedef struct Ts4XRec_885FB538 { u8 pad0[0xc]; u16 fc; u8 pad10[2]; u32 f10; u16 f14; } Ts4XRec_885FB538;
u32 ts4_read_record_885FB538(Ts4XRec_885FB538 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FB200: slot 3 of vtable 0x880F9654; mirrors ts4_write_record_885FC7B8. */
typedef struct Ts4XRec_885FB200 { u8 pad0[0xc]; u32 fc; u16 f10; } Ts4XRec_885FB200;
u32 ts4_read_record_885FB200(Ts4XRec_885FB200 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FAF98: slot 3 of vtable 0x880F967C; mirrors ts4_write_record_885FC668. */
typedef struct Ts4XRec_885FAF98 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u8 pad20[2]; u32 f20; u16 f24; } Ts4XRec_885FAF98;
u32 ts4_read_record_885FAF98(Ts4XRec_885FAF98 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f24, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FAE20: slot 3 of vtable 0x880F9690; mirrors ts4_write_record_885FC5D0. */
typedef struct Ts4XRec_885FAE20 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; u16 f16; u16 f18; u16 f1a; u16 f1c; u8 pad20[2]; u32 f20; } Ts4XRec_885FAE20;
u32 ts4_read_record_885FAE20(Ts4XRec_885FAE20 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f18, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1a, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f1c, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f20, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA778: slot 3 of vtable 0x880F976C; mirrors ts4_write_record_885FC258. */
typedef struct Ts4XRec_885FA778 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; } Ts4XRec_885FA778;
u32 ts4_read_record_885FA778(Ts4XRec_885FA778 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA690: slot 3 of vtable 0x880F9780; mirrors ts4_write_record_885FC1E8. */
typedef struct Ts4XRec_885FA690 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u16 f12; u16 f14; } Ts4XRec_885FA690;
u32 ts4_read_record_885FA690(Ts4XRec_885FA690 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f12, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA5E0: slot 3 of vtable 0x880F9794; mirrors ts4_write_record_885FC188. */
typedef struct Ts4XRec_885FA5E0 { u8 pad0[0xc]; u32 fc; u32 f10; u32 f14; } Ts4XRec_885FA5E0;
u32 ts4_read_record_885FA5E0(Ts4XRec_885FA5E0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA530: slot 3 of vtable 0x880F97A8; mirrors ts4_write_record_885FC128. */
typedef struct Ts4XRec_885FA530 { u8 pad0[0xc]; u32 fc; u32 f10; u16 f14; } Ts4XRec_885FA530;
u32 ts4_read_record_885FA530(Ts4XRec_885FA530 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u32(&self->fc, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885FA3A0: slot 3 of vtable 0x880F97E4; mirrors ts4_write_record_885FC040. */
typedef struct Ts4XRec_885FA3A0 { u8 pad0[0xc]; u16 fc; u16 fe; u32 f10; } Ts4XRec_885FA3A0;
u32 ts4_read_record_885FA3A0(Ts4XRec_885FA3A0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F9E08: slot 3 of vtable 0x880F9898; mirrors ts4_write_record_885FBC20. */
typedef struct Ts4XRec_885F9E08 { u8 pad0[0xc]; u16 fc; u16 fe; u32 f10; u32 f14; u64 f18; u64 f20; } Ts4XRec_885F9E08;
u32 ts4_read_record_885F9E08(Ts4XRec_885F9E08 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u64(&self->f18, p, &n))
        return 0;
    p += 8;
    if (!ts4_xread_u64(&self->f20, p, &n))
        return 0;
    p += 8;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F9BD0: slot 3 of vtable 0x880F98E8; mirrors ts4_write_record_885FBAD8. */
typedef struct Ts4XRec_885F9BD0 { u8 pad0[0xc]; u16 fc; u8 pad10[2]; u32 f10; u16 f14; u16 f16; } Ts4XRec_885F9BD0;
u32 ts4_read_record_885F9BD0(Ts4XRec_885F9BD0 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f10, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u16(&self->f14, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f16, p, &n))
        return 0;
    p += 2;
    *rem -= p - src;
    return 1;
}

/* Swing_DLL.xex 0x885F9AE8: slot 3 of vtable 0x880F98FC; mirrors ts4_write_record_885FBA68. */
typedef struct Ts4XRec_885F9AE8 { u8 pad0[0xc]; u16 fc; u16 fe; u16 f10; u8 pad14[2]; u32 f14; u32 f18; } Ts4XRec_885F9AE8;
u32 ts4_read_record_885F9AE8(Ts4XRec_885F9AE8 *self, const u8 *src, u32 *rem)
{
    const u8 *p = src;
    u32 n = *rem;
    if (!ts4_xread_u16(&self->fc, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->fe, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u16(&self->f10, p, &n))
        return 0;
    p += 2;
    if (!ts4_xread_u32(&self->f14, p, &n))
        return 0;
    p += 4;
    if (!ts4_xread_u32(&self->f18, p, &n))
        return 0;
    p += 4;
    *rem -= p - src;
    return 1;
}
