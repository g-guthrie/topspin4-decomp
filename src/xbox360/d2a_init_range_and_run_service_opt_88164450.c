/* Swing_DLL.xex 0x88164450-0x881B2948, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Svc { struct SvcVtbl *vt; } Svc;
struct SvcVtbl { void *s[44]; void (*run)(Svc *, void *, void *, u32, u32, u32, u32); };
typedef struct In { Svc *svc; u32 tag; } In;
typedef struct Out { u32 f0, f4, f8; } Out;

/* As above, with an optional count argument that defaults to 1. */
void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x1;
        }
        s->vt->run(s, in, out, a, 0x1, count, 0x1);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 4. */
void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x4;
        }
        s->vt->run(s, in, out, a, 0x2, count, 0x4);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 4. */
void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x4;
        }
        s->vt->run(s, in, out, a, 0x9, count, 0x4);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 4. */
void *ts4_init_range_and_run_service_opt_88165220(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x4;
        }
        s->vt->run(s, in, out, a, 0x7, count, 0x4);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 12. */
void *ts4_init_range_and_run_service_opt_881652C0(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0xc;
        }
        s->vt->run(s, in, out, a, 0x14, count, 0x4);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 1. */
void *ts4_init_range_and_run_service_opt_88165D80(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x1;
        }
        s->vt->run(s, in, out, a, 0x4, count, 0x1);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 1. */
void *ts4_init_range_and_run_service_opt_88176F70(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x1;
        }
        s->vt->run(s, in, out, a, 0x14, count, 0x1);
    }
    return out;
}

/* As above, with an optional count argument that defaults to 2. */
void *ts4_init_range_and_run_service_opt_881B2948(Out *out, In *in, u32 a, u32 count)
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
        if (count == 0) {
            count = 0x2;
        }
        s->vt->run(s, in, out, a, 0x5, count, 0x2);
    }
    return out;
}
