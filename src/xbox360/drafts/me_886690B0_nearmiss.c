/* NEAR MISS 0x886690B0: 15 off, base pointer and zero swapped (target base r11, zero r10) over every
 * spelling tried, incl. the group-pointer tip and LTCG. Sibling 0x8865C1F0 has the same issue. */
/* 0x886690B0 (hand match): clears the side's per-point request flags and drops the owner's link.
 * Sibling 0x8865C1F0 clears the same flags without touching the link. */
typedef struct Side {
    char p0[0x96]; unsigned char req_96; unsigned char req_97;
    char p1[0xcc - 0x98]; unsigned char req_cc; unsigned char req_cd; unsigned char req_ce;
    char p2[0xe5 - 0xcf]; unsigned char req_e5;
    char p3[0x160 - 0xe6]; unsigned char req_160; unsigned char req_161; unsigned char req_162; char p4; unsigned char req_164;
    char p5[0x19a - 0x165]; unsigned char req_19a;
} Side;
typedef struct Ctx { char p[0x44]; Side *side; } Ctx;
typedef struct Obj { char p[4]; Ctx *ctx; } Obj;
void ts4_clear_side_requests_and_link_886690B0(Obj *o)
{
    Side *s = o->ctx->side;
    s->req_cc = 0;
    s->req_cd = 0;
    s->req_ce = 0;
    s->req_e5 = 0;
    s->req_96 = 0;
    s->req_97 = 0;
    s->req_19a = 0;
    s->req_160 = 0;
    s->req_161 = 0;
    s->req_162 = 0;
    s->req_164 = 0;
    o->ctx = 0;
}
