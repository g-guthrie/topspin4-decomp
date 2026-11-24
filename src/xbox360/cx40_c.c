/* CW40 part c: UI manager helpers in 0x887D0000-0x88800000 (state machines, lookups). */
typedef unsigned int u32;
typedef unsigned char u8;

/* 0x887EA1E0: find an entry (key hash at +0x14, id at +0x10) in the two pointer ranges at +0x48 and +0x54. */
char *ts4_find_entry_887EA1E0(char *self, u32 *key, int b)
{
    char **p = *(char ***)(self + 0x48);
    char **e = *(char ***)(self + 0x4c);
    char **end1;
    for (; p != e; p++) {
        char *o = *p;
        if (*(u32 *)(o + 0x14) == *key && *(int *)(o + 0x10) == b) break;
    }
    end1 = *(char ** volatile *)(self + 0x4c);
    if (p != end1) return *p;
    p = *(char ***)(self + 0x54);
    e = *(char ***)(self + 0x58);
    for (; p != e; p++) {
        char *o = *p;
        if (*(u32 *)(o + 0x14) == *key && *(int *)(o + 0x10) == b) break;
    }
    if (p != end1) return *p;
    return 0;
}

extern void *ts4_record_value_887E1C50(void *);
extern void *fn_887D73C0(void *);
extern u32 ts4_if_call_seq_u32_off0_887D3C88(void *, void *);
/* 0x887E2BE0: switch the current state hash at +0x4c (0 means re-run the current one). */
void ts4_set_state_887E2BE0(char *self, u32 h)
{
    u32 v = h;
    if (v == 0) {
        v = *(u32 *)(self + 0x4c);
        if (v == 0) return;
        h = v;
    }
    if (v == 0x1DCA7285u) {
        ts4_record_value_887E1C50(self);
    } else if (v == 0x04C901D9u) {
        *(u32 *)(self + 0x4c) = 0x04C901D9u;
        fn_887D73C0(self);
    } else {
        if (ts4_if_call_seq_u32_off0_887D3C88(self, &h) != 0) *(u32 *)(self + 0x4c) = v;
    }
}

extern u32 ts4_find_child_by_id_888AD568(void *, void *);
extern void ts4_mgr_set_mode_notify_active_887DD4C8(void *, int);
extern u8 lbl_88C46A9E;
/* 0x887DF0F8: commit the pending slot at +0x118 (resolve it, flag a change, restore the mode byte). */
u32 ts4_commit_pending_887DF0F8(char *self)
{
    u32 *slot = (u32 *)(self + 0x118);
    if (*slot != 0) {
        u32 r = ts4_find_child_by_id_888AD568(*(void **)(self + 0xd8), slot);
        u32 old = *(u32 *)(self + 0x2e8);
        u8 same;
        u8 saved;
        if (old != 0 && old == r) same = 1; else same = 0;
        *(u32 *)(self + 0x2e8) = r;
        self[0x2ff] = same;
        saved = self[0x360];
        ts4_mgr_set_mode_notify_active_887DD4C8(self, 1);
        {
            u32 k = *slot;
            char *o = *(char **)(self + 0x104);
            self[0x360] = saved;
            self[0x361] = lbl_88C46A9E;
            *(u32 *)(o + 0x6ec) = k;
        }
        self[0x2fd] = 1;
        *slot = 0;
        return 1;
    }
    return 0;
}

typedef struct Cx40Vt14 { void *s[5]; void (*s14)(void *); } Cx40Vt14;
typedef struct Cx40Ent { Cx40Vt14 *vt; char pad[4]; int f8; } Cx40Ent;
typedef struct Cx40Q { char pad[0xc]; u8 b0c; char pad2[0x13]; Cx40Ent **b; Cx40Ent **e; } Cx40Q;
/* 0x887EAF30: mark the queue active (+0xc) and run slot 5 of every entry that is not in state 3 or 4. */
void ts4_queue_activate_887EAF30(Cx40Q *self)
{
    Cx40Ent **p = self->b;
    Cx40Ent **e = self->e;
    volatile u8 t = 1;
    u8 v = t;
    self->b0c = v;
    if (p != e) {
        do {
            Cx40Ent *o = *p;
            if (o->f8 != 4 && o->f8 != 3) o->vt->s14(o);
            p++;
        } while (p != self->e);
    }
}

extern void fn_887E72E0(void *, int, int);
extern u32 fn_887E62A8(void *, void *, u32);
extern void fn_887E0540(void *, void *, u32, u32);
/* 0x887E6478: leave the pending states, then in state 3 either register the slot (returning its result) or set the done flag. */
u32 ts4_enter_state3_887E6478(char *self, u8 a, u32 b)
{
    u32 res = 1;
    if (*(int *)(self + 0x58) == 1) fn_887E72E0(self, 2, 0);
    if (self[0x125] != 0 && *(int *)(self + 0x58) != 3) fn_887E72E0(self, 3, 0);
    if (*(int *)(self + 0x58) == 3) {
        u32 key;
        u32 r;
        self[0x124] = 0;
        if (a != 0) {
            self[0x126] = (u8)res;
            r = fn_887E62A8(*(char **)(self + 0xf8) + 0x58, *(char **)(self + 0xa8) + 0x204, b);
            key = 0xE9F37A3Au;
            fn_887E0540(self, &key, r, 0);
            res = r;
        } else {
            self[0x2cc] = (u8)res;
        }
    }
    return res;
}

/* 0x887EA1A0: true when the hash at +0x18 is not the default hash. */
u32 ts4_hash_is_set_887EA1A0(u32 *self)
{
    return 0xDFA2AFF1u != self[6];
}

typedef struct Cx40Ids { char pad[0x18]; int f18, f1c; char pad2[0x84]; int w[10]; u8 b[10]; } Cx40Ids;
/* 0x887EFEA0: reset the ten id words and ten flag bytes, and both cursor words, to -1/0. */
void ts4_ids_reset_887EFEA0(Cx40Ids *self)
{
    int i;
    for (i = 0; i < 10; i++) {
        self->w[i] = -1;
        self->b[i] = 0;
    }
    self->f18 = -1;
    self->f1c = -1;
}
