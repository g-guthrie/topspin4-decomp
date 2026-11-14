/* Swing_DLL.xex 0x88164ED0-0x8822C808, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Svc { struct SvcVtbl *vt; } Svc;
struct SvcVtbl { void *s[44]; void (*run)(Svc *, void *, void *, u32, u32, u32, u32); };
typedef struct In { Svc *svc; u32 tag; } In;
typedef struct Out { u32 f0, f4, f8; } Out;

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_88164ED0(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x3, 0x4, 0x4);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_88165088(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x7, 0x4, 0x4);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x8, 0x4, 0x4);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_88180F88(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x14, 0xc, 0x4);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_88188950(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x14, 0x2, 0x2);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_88219DD8(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x14, 0x1, 0x4);
    }
    return out;
}

/* Resets the output range to empty and, if the source service is usable, runs it with fixed options. */
void *ts4_init_range_and_run_service_8822C808(Out *out, In *in, u32 a)
{
    Svc *s;
    u32 bad = 0;
    out->f0 = 0;
    out->f8 = 0;
    out->f4 = 0xFFFFF;
    s = in->svc;
    if (!s || in->tag == 0xFFFFF) {
        bad = 1;
    }
    if (!(bad & 0xff)) {
        s->vt->run(s, in, out, a, 0x14, 0x48, 0x4);
    }
    return out;
}
