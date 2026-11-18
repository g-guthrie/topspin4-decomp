/* 0x88649D10 (LTCG + primer): sync a follow controller with its scene actor. When snapping or nudging: refresh the
   actor, apply the entry offset, copy the actor position (pinned entry) or the animation root position with y = 0
   into s->pos, add the pending nudge to both offset components and clear the nudge flag. When aiming: steer the
   actor's motion toward the stored 3-float aim direction. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#pragma intrinsic(__vsldoi)
static const float kZero = 0.0f;
static __inline __vector4 load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}
typedef struct Entry { char p[0x18]; void *pinned; } Entry;
typedef struct EntryList { char p[8]; Entry **items; } EntryList;
typedef struct EntryHost { char p[4]; EntryList *list; } EntryHost;
typedef struct PosSrc { __vector4 *pos; } PosSrc;
typedef struct Actor { char p[0x50]; __vector4 pos; char q[0x10]; char motion[0x24]; void *anim; char r[0x10]; EntryHost *entries; } Actor;
typedef struct ActorRef { Actor *a; } ActorRef;
typedef struct Scene { char p[0x28]; ActorRef *actor; } Scene;
typedef struct Follow {
    char p[0x1c]; unsigned char snap; unsigned char nudge; unsigned char aim; char p1f;
    int entry; float nudge_amt; float off[2]; float aim_dir[3]; char p3c[8]; Scene *scene; char p48[0x10]; float pos[3];
} Follow;
extern void fn_882694D0(Actor *a, int v);
extern void fn_88647ED0(Actor *a, int entry, float *off);
extern PosSrc *ts4_call_seq_fn_884027D8_88402FD8(void *anim);   /* anim -> current root position */
extern void fn_88646928(void *motion, void *anim, __vector4 dir, float t, int flags);

void ts4_follow_sync_88649D10(Follow *s)
{
    if (s->snap || s->nudge) {
        Actor *a = s->scene->actor->a;
        float *off;
        Vx1Vec v;
        fn_882694D0(a, 0);
        off = s->off;
        fn_88647ED0(a, s->entry, off);
        if (a->entries->list->items[s->entry]->pinned) {
            v.v = a->pos;
        } else {
            PosSrc *ps = ts4_call_seq_fn_884027D8_88402FD8(a->anim);
            v.v = __vrlimi(*ps->pos, __lvlx(&kZero, 0), 4, 3);
        }
        {
            float *p = s->pos;
            p[0] = v.v.v[0];
            p[1] = v.v.v[1];
            p[2] = v.v.v[2];
        }
        if (s->nudge) {
            float k = s->nudge_amt;
            off[0] += k;
            off[1] += k;
        }
        s->nudge = 0;
    }
    if (s->aim) {
        Actor *a = s->scene->actor->a;
        fn_88646928(a->motion, a->anim, load3(s->aim_dir), kZero, 0);
    }
}
