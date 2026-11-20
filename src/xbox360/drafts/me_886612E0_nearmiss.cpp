/* NEAR MISS 0x886612E0 (agentA2, C++ real virtuals): 32 -> 29 off on LTCG (30 plain /Oc). submit is a real virtual
   (slot 6). Residue: target loads player into r11 then a mr r29 copy across fn_8826ACB8; we load straight into r31.
   Tried 8 variants (prop/refresh inline helpers, q alias, LTCG). */
typedef unsigned int ts4_u32;
struct Ts4Swing { unsigned char pad_000[0x438]; float blend_a; float blend_b; unsigned char pad_440[0x840 - 0x440];
    unsigned char pose[0xD84 - 0x840]; float timer; unsigned char pad_d88[0xDAC - 0xD88]; unsigned char active; };
struct Ts4Player;
struct Ts4PoseSink { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void submit(void *pose, Ts4Player *p); };
struct Ts4PoseHost { unsigned char pad_00[0xC]; Ts4PoseSink *sink; };
struct Ts4SlotRecord { unsigned char pad_00[0xD0]; unsigned char flag; unsigned char pad_d1[0x140 - 0xD1]; };
struct Ts4SlotTable { unsigned char pad_000[0x104]; int slots_rel; };
struct Ts4SlotOwner { unsigned char pad_00[0x44]; Ts4SlotTable *table; };
struct Ts4Player { unsigned char pad_00[0x14]; int slot; unsigned char pad_18[0x48 - 0x18]; Ts4SlotOwner *slots;
    unsigned char pad_4c[0x74 - 0x4C]; Ts4Swing *swing; unsigned char pad_78[0x94 - 0x78]; unsigned char props[0xB0 - 0x94]; Ts4PoseHost *host; };
struct Ts4SwingCtl { unsigned char pad_00[0x1C]; Ts4Player *player; };
extern "C" unsigned char fn_8826ACB8(void *props, ts4_u32 *key);

struct Key { ts4_u32 h; Key(ts4_u32 x) : h(x) {} };
static inline unsigned char prop(Ts4Player *q, ts4_u32 h) { ts4_u32 key = h; return fn_8826ACB8(q->props, &key); }
static inline Ts4SlotRecord *rec(Ts4Player *q) { int *rel = &q->slots->table->slots_rel; return (Ts4SlotRecord *)((char *)rel + (*rel + q->slot * 0x140)); }
extern "C" void ts4_swing_reset_886612E0(Ts4SwingCtl *self)
{
    Ts4Player *p = self->player;
    p->host->sink->submit(p->swing->pose, p);
    { Ts4Player *q = self->player; int *rel = &q->slots->table->slots_rel;
      unsigned char v = prop(q, 0xA6A1B2AEu);
      ((Ts4SlotRecord *)((char *)rel + (*rel + q->slot * 0x140)))->flag = v; }
    { Ts4Swing *s = self->player->swing; s->timer = 0.0f; s->active = 0; }
    { Ts4Swing *s = self->player->swing; s->blend_a = 0.0f; s->blend_b = 0.0f; }
}
/* ---- previous C draft ----
/* near-miss: 32 off, size 0xb4 vs 0xb8 (target keeps player in r11 then mr r29 copy; register roles differ) *_/
/* ME: reset a player's swing state and refresh its slot flag (pick.py throughput). Swing_DLL.xex 0x886612E0 *_/
typedef unsigned int ts4_u32;
struct Ts4Swing {
    unsigned char pad_000[0x438];
    float blend_a;                   /* +0x438 *_/
    float blend_b;                   /* +0x43C *_/
    unsigned char pad_440[0x840 - 0x440];
    unsigned char pose[0xD84 - 0x840]; /* +0x840 *_/
    float timer;                     /* +0xD84 *_/
    unsigned char pad_d88[0xDAC - 0xD88];
    unsigned char active;            /* +0xDAC *_/
*/
