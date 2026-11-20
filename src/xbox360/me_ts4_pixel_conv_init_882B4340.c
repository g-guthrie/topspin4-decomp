/* Swing_DLL.xex 0x882B4340: initialises a pixel converter: validates the filter flags (low word 1..5, no bits above 0x7FFFFF),
 * copies the dither/clamp bits into both surface descriptors, wraps them as readers (fn_882C0B88), then tries each converter
 * back end in turn; logs and returns E_FAIL when none fits or allocation fails, 0x8876086C on bad flags. agAD: /O1. */
typedef struct Codec { const struct CodecVt *vt; } Codec;
typedef struct CodecVt { void (*destroy)(Codec *c, int free_it); } CodecVt;
typedef struct Desc { char pad[0x40]; unsigned int f40, f44, f48; } Desc;
typedef struct Conv { Codec *dst; Codec *src; unsigned int flags; } Conv;
extern const char lbl_88001B54[], lbl_88001B38[], lbl_88001B20[], lbl_880DD80C[];
Codec *fn_882C0B88(Desc *d);
int fn_882B6DB8(Codec *src, Codec *dst);
int fn_882B1548(Conv *c);
int fn_882B16D8(Conv *c);
int fn_882B1820(Conv *c);
int fn_882B1A88(Conv *c);
int fn_882B1CC0(Conv *c);
int fn_882B21B0(Conv *c);
int fn_882B27B0(Conv *c);
int fn_882B2B48(Conv *c);
int fn_882B3C08(Conv *c);
int fn_882B3420(Conv *c);
void ts4_call_seq_RtlInitAnsiString_88582148(const char *msg);

int fn_882B4340(Conv *c, Desc *src, Desc *dst, unsigned int flags)
{
    int hr;
    const char *msg;
    c->flags = flags;
    c->dst = 0;
    c->src = 0;
    if (!(flags & 0xffff) || (flags & 0xffff) > 5 || (flags & 0xff800000)) {
        ts4_call_seq_RtlInitAnsiString_88582148(lbl_88001B20);
        ts4_call_seq_RtlInitAnsiString_88582148(lbl_880DD80C);
        return (int)0x8876086C;
    }
    dst->f48 = flags & 0x200000;
    src->f48 = flags & 0x400000;
    src->f40 = flags & 0x80000;
    src->f44 = flags & 0x100000;
    c->src = fn_882C0B88(src);
    if (c->src) {
        c->dst = fn_882C0B88(dst);
        if (c->dst) {
            hr = fn_882B6DB8(c->src, c->dst);
            if (hr < 0)
                goto done;
            if (fn_882B1548(c) >= 0 || fn_882B16D8(c) >= 0 || fn_882B1820(c) >= 0 || fn_882B1A88(c) >= 0 ||
                fn_882B1CC0(c) >= 0 || fn_882B21B0(c) >= 0 || fn_882B27B0(c) >= 0 || fn_882B2B48(c) >= 0 ||
                fn_882B3C08(c) >= 0 || fn_882B3420(c) >= 0) {
                hr = 0;
                goto done;
            }
            msg = lbl_88001B54;
            goto fail;
        }
    }
    msg = lbl_88001B38;
fail:
    ts4_call_seq_RtlInitAnsiString_88582148(msg);
    ts4_call_seq_RtlInitAnsiString_88582148(lbl_880DD80C);
    hr = (int)0x80004005;
done:
    if (c->src) {
        c->src->vt->destroy(c->src, 1);
        c->src = 0;
    }
    if (c->dst) {
        c->dst->vt->destroy(c->dst, 1);
        c->dst = 0;
    }
    return hr;
}
