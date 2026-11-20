/* CX27 part c: game core 0x8820F390-0x88220C18, plain route, /Oc (divides without trap). */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- vector erase (move the tail down, destroy the leftover) ---- */
typedef struct Cx27E38 { u8 b[0x38]; } Cx27E38;
typedef struct Cx27V38 { u32 p0; Cx27E38 *end; } Cx27V38;
extern void fn_881C6168(Cx27E38 *dst, Cx27E38 *src);
extern void ts4_call_seq_fn_881B19A0_881C6008(Cx27E38 *p);

/* 0x882140F0: erase [dst, first) shifting the tail down; returns dst */
Cx27E38 *ts4_vec38_erase_882140F0(Cx27V38 *v, Cx27E38 *dst, Cx27E38 *first)
{
    int n = v->end - first;
    Cx27E38 *p = dst;
    Cx27E38 *q;
    Cx27E38 *e;
    int off;
    if (n > 0) off = (char *)first - (char *)dst;
    while (n > 0) {
        fn_881C6168(p, (Cx27E38 *)((char *)p + off));
        n--;
        p++;
    }
    e = v->end;
    for (q = p; q != e; q++) ts4_call_seq_fn_881B19A0_881C6008(q);
    v->end = p;
    return dst;
}

typedef struct Cx27E214 { u8 b[0x214]; } Cx27E214;
typedef struct Cx27V214 { u32 p0; Cx27E214 *end; } Cx27V214;
extern void ts4_byte_string_assign_881A52D8(Cx27E214 *dst, Cx27E214 *src);

/* 0x88214598 */
Cx27E214 *ts4_vec214_erase_88214598(Cx27V214 *v, Cx27E214 *dst, Cx27E214 *first)
{
    int n = v->end - first;
    Cx27E214 *p = dst;
    Cx27E214 *s = first;
    while (n > 0) {
        ts4_byte_string_assign_881A52D8(p, s);
        *(u32 *)(p->b + 0x20c) = *(u32 *)(s->b + 0x20c);
        *(u32 *)(p->b + 0x210) = *(u32 *)(s->b + 0x210);
        n--;
        p++;
        s++;
    }
    v->end = p;
    return dst;
}

/* ---- clear-from-begin: erase(begin, end) with the tail move inlined ---- */
typedef struct Cx27E5c { u32 id; u8 body[0x54]; u8 f58; u8 f59; u8 pad[2]; } Cx27E5c;
typedef struct Cx27V5c { Cx27E5c *begin; Cx27E5c *end; } Cx27V5c;
extern void ts4_call_seq_u32_off0_882126B8(void *dst, void *src);
extern void ts4_if_call_seq_u32_offc_882124A8(void *p);

/* 0x88213E28 */
void ts4_vec5c_clear_88213E28(Cx27V5c *v)
{
    Cx27E5c *last = v->end;
    Cx27E5c *p = v->begin;
    Cx27E5c *s = last;
    Cx27E5c *q;
    Cx27E5c *e;
    int n = v->end - last;
    while (n > 0) {
        p->id = s->id;
        ts4_call_seq_u32_off0_882126B8(p->body, s->body);
        p->f58 = s->f58;
        p->f59 = s->f59;
        n--;
        p++;
        s++;
    }
    e = v->end;
    for (q = p; q != e; q++) ts4_if_call_seq_u32_offc_882124A8(q->body);
    v->end = p;
}

typedef struct Cx27E40 { u32 id; u32 f4; u8 body[0x34]; u8 f3c; u8 pad[3]; } Cx27E40;
typedef struct Cx27V40 { Cx27E40 *begin; Cx27E40 *end; } Cx27V40;
extern void ts4_vec56_assign_88218E08(void *dst, void *src);
extern void fn_88150600(void *dst, void *src);
extern void ts4_counted_ptr_assign_881C38D0(void *dst, void *src);
extern void fn_88218FE0(void *dst, void *src);
extern void fn_887BA228(void *p);

/* 0x88213C08 */
void ts4_vec40_clear_88213C08(Cx27V40 *v)
{
    Cx27E40 *last = v->end;
    Cx27E40 *p = v->begin;
    Cx27E40 *s = last;
    Cx27E40 *q;
    Cx27E40 *e;
    int n = v->end - last;
    while (n > 0) {
        p->id = s->id;
        p->f4 = s->f4;
        ts4_vec56_assign_88218E08(p->body, s->body);
        fn_88150600(p->body + 0xc, s->body + 0xc);
        fn_88150600(p->body + 0x18, s->body + 0x18);
        ts4_counted_ptr_assign_881C38D0(p->body + 0x24, s->body + 0x24);
        fn_88218FE0(p->body + 0x28, s->body + 0x28);
        p->f3c = s->f3c;
        n--;
        p++;
        s++;
    }
    e = v->end;
    for (q = p; q != e; q++) fn_887BA228(q);
    v->end = p;
}

typedef struct Cx27E134 { u8 str[0x10c]; u32 f10c, f110, f114; u8 f118; u8 pad[3]; u32 f11c, f120, f124, f128, f12c, f130; } Cx27E134;
typedef struct Cx27V134 { Cx27E134 *begin; Cx27E134 *end; } Cx27V134;
extern void ts4_byte_string_assign_8816D090(void *dst, void *src);

/* 0x8821FF40 */
void ts4_vec134_clear_8821FF40(Cx27V134 *v)
{
    Cx27E134 *last = v->end;
    Cx27E134 *p = v->begin;
    Cx27E134 *s = last;
    int n = v->end - last;
    while (n > 0) {
        ts4_byte_string_assign_8816D090(p, s);
        p->f10c = s->f10c;
        p->f110 = s->f110;
        p->f114 = s->f114;
        p->f118 = s->f118;
        p->f11c = s->f11c;
        p->f120 = s->f120;
        p->f124 = s->f124;
        p->f128 = s->f128;
        p->f12c = s->f12c;
        p->f130 = s->f130;
        n--;
        p++;
        s++;
    }
    v->end = p;
}

