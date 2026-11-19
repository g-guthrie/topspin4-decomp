/* near miss 0x8865D3C0 (plain route, /Oc): size 0x2c4 against 0x2c8. 5 real instruction differences: 18 after
 * alignment, the rest are branch displacements shifted by the one missing instruction. 4 by mnemonic.
 * Behaviour: controller update. Returns if the flags block is already finished (f93). Asks the controller for a
 * pick (virtual slot 8) on the current hash. For hash 0x22703895, or when the layout record is armed, it sets all
 * the finished flags, sets the object's side index (1 - side->f64, or layout->f44), writes the slot timer (7 when
 * the option byte is set, else opts->f1d4) and clears the other slot's timer, then refreshes (slot 7).
 * Otherwise it decides `ok` from the pick, the side's current pick and the 0xC9238771 hash. If ok it runs slots 16,
 * 14 and 7 and copies `want` into the object; if not, it resets both to -1.
 * Residue: the pair of slot addresses. The target reads h->rel once, makes a copy (`mr r11,r7`) and computes
 * a = (i*24 + rel) + h and b = (h - i*24) + rel. Every source form tried (separate expressions, base pointer,
 * (1-i) index, accessor helper) gives one normal form: b = (rel - i*24) + h, with no copy. */
typedef unsigned char u8;
struct Hash { unsigned int h; };
struct Lay { char p[0x40]; u8 f40; char q[3]; int f44; };
struct Flags { char p[0x91]; u8 f91, f92, f93, f94, f95; char q[0x328 - 0x96]; u8 f328; char r; u8 f32a; };
struct Opts { char p[0x1d4]; int f1d4; char q[0x1e0 - 0x1d8]; u8 f1e0; };
struct Side { char p[0x54]; int f54; char q[0x64 - 0x58]; int f64; char r[0xcc - 0x68]; u8 fcc; char s[0xd4 - 0xcd]; u8 fd4, fd5, fd6; };
struct Ctx { char p[0x28]; Lay *f28; char q[0x30 - 0x2c]; Flags *f30; char r[0x38 - 0x34]; Opts *f38; char s[0x44 - 0x3c]; Side *f44; Hash *f48; };
struct Slot { char p[0xc]; int fc; char q[0x18 - 0x10]; };
struct Rel { int rel; };
struct Obj { char p[9]; u8 f9; char q[0x24 - 0xa]; Rel f24; char r[0x47 - 0x28]; u8 f47; int f48; };
struct Ctl {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6();
    virtual void refresh(); virtual int pick(Hash *h); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12();
    virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16();
    Ctx *ctx; Obj *obj; int want;
};
extern "C" void ts4_ctl_update_8865D3C0(Ctl *s)
{
    int r;
    u8 isA;
    if (s->ctx->f30->f93) return;
    r = s->pick(s->ctx->f48);
    isA = 0x22703895 == s->ctx->f48->h;
    if (isA || s->ctx->f28->f40) {
        s->ctx->f30->f92 = 1;
        s->ctx->f30->f91 = 1;
        s->ctx->f30->f93 = 1;
        s->ctx->f44->fcc = 1;
        s->ctx->f44->fd4 = 1;
        s->ctx->f44->fd5 = 1;
        s->ctx->f44->fd6 = 1;
        if (isA) s->obj->f48 = 1 - s->ctx->f44->f64;
        else if (s->ctx->f28->f40) s->obj->f48 = s->ctx->f28->f44;
        s->obj->f47 = 1;
        {
            Ctx *c = s->ctx;
            Obj *o = s->obj;
            Rel *h = &o->f24;
            int i = o->f48;
            Slot *a = (Slot *)((char *)h + (i * 24 + h->rel));
            Slot *b2 = (Slot *)((char *)h - i * 24 + h->rel) + 1;
            a->fc = c->f38->f1e0 ? 7 : c->f38->f1d4;
            b2->fc = 0;
        }
        s->refresh();
        return;
    }
    {
        u8 ok = 1;
        Flags *l = s->ctx->f30;
        if (l->f32a) {
            u8 b;
            if (r == -1 || r == s->ctx->f44->f54 || !l->f328) b = 1; else b = 0;
            l->f95 = b;
            if (b) {
                if (!s->obj->f9 && !s->ctx->f38->f1e0) ok = 0;
            } else if (s->ctx->f48->h == 0xC9238771) ok = 0;
        } else {
            l->f95 = 0;
        }
        if (ok) {
            s->s16();
            s->s14();
            s->refresh();
            s->obj->f48 = s->want;
        } else {
            s->obj->f48 = -1;
            s->want = -1;
        }
    }
}
