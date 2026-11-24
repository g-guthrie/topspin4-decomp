/* nearmiss: 15 off (fn_check_ltcg /Oc --auto-context); the target keeps five dead `mr` copies (r5..r9 of the
   INT_MAX register) before the five stores to owner->0x5c->0x20 +0xB0/B8/C0/E0/E8. Tried: plain stores, chained
   assignment, five locals, static inline set5, context-TU set5 (with and without an extra param), extern const int
   defined in a context TU: all identical. Blocker: the copies look like link-time-inlined argument copies of a
   callee that no longer exists as a function (no matched/unmatched body to include); equiv version exists in
   eq_q5_gameplay_small_b.c. Swing_DLL.xex 0x8866EB80, 60 bytes. */
typedef struct Best { int value; int extra; } Best;
typedef struct Tab { char pad0[0xb0]; Best a, b, c; char padc8[0x18]; Best d, e; } Tab;
typedef struct Holder { char pad0[0x20]; Tab *table; } Holder;
typedef struct Owner { char pad0[0x5c]; Holder *holder; } Owner;

void ts4_move_limits_reset_8866EB80(Owner *self)
{
    Tab *t = self->holder->table;
    t->a.value = 0x7FFFFFFF;
    t->b.value = 0x7FFFFFFF;
    t->c.value = 0x7FFFFFFF;
    t->d.value = 0x7FFFFFFF;
    t->e.value = 0x7FFFFFFF;
}
