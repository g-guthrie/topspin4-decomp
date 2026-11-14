/* HS3 hand-matched: loops over relative-offset entry tables (0x887..0x88A). */
#ifdef _MSC_VER
#define HS3_INLINE __forceinline
#else
#define HS3_INLINE static inline
#endif

struct HS3RelHdr {
    volatile int entries_off; /* -1 when empty */
    unsigned count;
};

HS3_INLINE char *hs3_rel_begin(struct HS3RelHdr *h)
{
    int off = h->entries_off;
    char *p = 0;
    if (off != -1)
        p = (char *)h + off;
    return p;
}

HS3_INLINE char *hs3_rel_end(struct HS3RelHdr *h, unsigned stride)
{
    int off = h->entries_off;
    char *p = 0;
    if (off != -1)
        p = (char *)h + off + h->count * stride;
    return p;
}

struct HS3Slot { /* 0xb4-byte slot */
    char pad0[0x60];
    unsigned owner_off60;
    char pad1[0x70 - 0x64];
    char sub70[5];
    unsigned char flag75;
    char pad2[0x98 - 0x76];
    unsigned id98;
    char pad3[0xb4 - 0x9c];
};
struct HS3Blk1c0 { char pad[0x1c0]; struct HS3RelHdr hdr; };
struct HS3Mgr {
    char pad[0xa8];
    struct HS3Blk1c0 *blk;
    char pad2[0x360 - 0xac];
    unsigned char b360;
    unsigned char b361;
};

void fn_887DC570(struct HS3Mgr *mgr, struct HS3Slot *slot);
void fn_887D4360(struct HS3Slot *slot);
void *ts4_find_service(unsigned id);
void fn_887FFDB0(void *svc);
void fn_887D8040(struct HS3Mgr *mgr, void *sub);

/* Store a mode byte, then notify every active slot. */
void ts4_mgr_set_mode_notify_active_887DD4C8(struct HS3Mgr *self, unsigned char mode)
{
    struct HS3RelHdr *h = &self->blk->hdr;
    struct HS3Slot *it, *end;
    self->b360 = mode;
    it = (struct HS3Slot *)hs3_rel_begin(h);
    end = (struct HS3Slot *)hs3_rel_end(h, 0xb4);
    for (; it != end; it++) {
        if (it->flag75)
            fn_887DC570(self, it);
    }
}

/* Decrement the pending counter if set, else notify every active slot. */
void ts4_mgr_tick_or_notify_active_887DD428(struct HS3Mgr *self)
{
    struct HS3RelHdr *h;
    struct HS3Slot *it, *end;
    if (self->b361) {
        self->b361--;
        return;
    }
    h = &self->blk->hdr;
    it = (struct HS3Slot *)hs3_rel_begin(h);
    end = (struct HS3Slot *)hs3_rel_end(h, 0xb4);
    for (; it != end; it++) {
        if (it->flag75)
            fn_887DC570(self, it);
    }
}

/* Process every slot whose flag byte (looked up through its +0x60 offset) is set; true if any. */
int ts4_mgr_process_flagged_slots_887D4B08(struct HS3Mgr *self)
{
    struct HS3RelHdr *h = &self->blk->hdr;
    int any = 0;
    struct HS3Slot *end = (struct HS3Slot *)hs3_rel_end(h, 0xb4);
    struct HS3Slot *it = (struct HS3Slot *)hs3_rel_begin(h);
    for (; it != end; it++) {
        if (*((unsigned char *)self + it->owner_off60 + 0x40)) {
            fn_887D4360(it);
            any = 1;
        }
    }
    return any;
}

/* For every active slot, poke its service (if found) and run the slot update. */
void ts4_mgr_update_active_slots_887D98D0(struct HS3Mgr *self)
{
    struct HS3RelHdr *h = &self->blk->hdr;
    struct HS3Slot *it = (struct HS3Slot *)hs3_rel_begin(h);
    struct HS3Slot *end = (struct HS3Slot *)hs3_rel_end(h, 0xb4);
    for (; it != end; it++) {
        if (it->flag75) {
            void *svc = ts4_find_service(it->id98);
            if (svc)
                fn_887FFDB0(svc);
            fn_887D8040(self, it->sub70);
        }
    }
}

/* Non-volatile header variant, for tables whose offset is loaded once. */
struct HS3RelHdrN {
    int entries_off; /* -1 when empty */
    unsigned count;
};

HS3_INLINE char *hs3n_begin(struct HS3RelHdrN *h)
{
    char *p = 0;
    if (h->entries_off != -1)
        p = (char *)h + h->entries_off;
    return p;
}

HS3_INLINE char *hs3n_end(struct HS3RelHdrN *h, unsigned stride)
{
    char *p = 0;
    if (h->entries_off != -1)
        p = (char *)h + h->entries_off + h->count * stride;
    return p;
}

struct HS3E94 {
    char pad[0x78];
    unsigned key;
    char pad2[0x94 - 0x7c];
};

/* Find the 0x94-byte entry whose +0x78 word equals *key, or 0. */
struct HS3E94 *ts4_reltbl_find_e94_by_key_887FFD40(unsigned *key, struct HS3RelHdrN *h)
{
    struct HS3E94 *result = 0;
    struct HS3E94 *end = (struct HS3E94 *)hs3n_end(h, 0x94);
    struct HS3E94 *begin = (struct HS3E94 *)hs3n_begin(h);
    struct HS3E94 *it = begin;
    if (end != begin) {
        unsigned k = *key;
        for (; end != it; it++) {
            if (k == it->key) {
                result = it;
                break;
            }
        }
    }
    return result;
}

struct HS3E10 {
    unsigned key;
    unsigned b;
    int c;
    int d;
};

/* Index of the 16-byte entry whose first word equals *key, or -1. */
int ts4_reltbl_index_of_e10_88800080(struct HS3RelHdrN *h, unsigned *key)
{
    int result = -1;
    struct HS3E10 *it = (struct HS3E10 *)hs3n_begin(h);
    struct HS3E10 *end = (struct HS3E10 *)hs3n_end(h, 0x10);
    int i = 0;
    if (end != it) {
        unsigned k = *key;
        for (; end != it; it++, i++) {
            if (it->key == k) {
                result = i;
                break;
            }
        }
    }
    return result;
}

/* Index of the 16-byte entry whose first word equals *key, or -1 (second copy). */
int ts4_reltbl_index_of_e10_88800E40(struct HS3RelHdrN *h, unsigned *key)
{
    int result = -1;
    struct HS3E10 *it = (struct HS3E10 *)hs3n_begin(h);
    struct HS3E10 *end = (struct HS3E10 *)hs3n_end(h, 0x10);
    int i = 0;
    if (end != it) {
        unsigned k = *key;
        for (; end != it; it++, i++) {
            if (it->key == k) {
                result = i;
                break;
            }
        }
    }
    return result;
}

struct HS3E8K { int key; int value; };
struct HS3Blk60 { char pad[0x60]; struct HS3RelHdrN hdr; };
struct HS3Owner28 { char pad[0x28]; struct HS3Blk60 *blk; };

/* Value of the first 8-byte entry whose signed key is >= `key`, or 0. */
int ts4_reltbl_lower_bound_value_8883C598(struct HS3Owner28 *owner, int key)
{
    struct HS3RelHdrN *h = &owner->blk->hdr;
    int result = 0;
    struct HS3E8K *end = (struct HS3E8K *)hs3n_end(h, 8);
    struct HS3E8K *begin = (struct HS3E8K *)hs3n_begin(h);
    struct HS3E8K *it = begin;
    if (begin != end) {
        for (; it != end; it++) {
            if (it->key >= key) {
                result = it->value;
                break;
            }
        }
    }
    return result;
}

struct HS3E12 { char pad[5]; unsigned char b5; unsigned char b6; char pad2[5]; };
struct HS3Owner60 { char pad[0x60]; struct HS3RelHdr *tbl; };

/* Set the +5 flag on the Nth entry (counting only entries whose +6 byte is 1). */
void ts4_reltbl_flag_nth_active_8883C608(struct HS3Owner60 *owner, int n)
{
    struct HS3RelHdr *h = owner->tbl;
    int count = 0;
    struct HS3E12 *end = (struct HS3E12 *)hs3_rel_end(h, 12);
    struct HS3E12 *begin = (struct HS3E12 *)hs3_rel_begin(h);
    struct HS3E12 *it = begin;
    if (begin != end) {
        for (; it != end; it++) {
            if (it->b6 == 1) {
                if (n == count) {
                    it->b5 = 1;
                    return;
                }
                count++;
            }
        }
    }
}

struct HS3E14K { char pad[8]; unsigned key; char pad2[8]; };
struct HS3Obj14 { char pad[0x14]; struct HS3RelHdr *tbl; };
struct HS3Globals27c { char pad[0x27c]; unsigned default_value; };
extern struct HS3Globals27c *lbl_88D45B1C;

/* Write the second word of the 0x14-byte entry whose +8 word equals `key`, else the global default. */
void ts4_reltbl_get_value_by_key8_8883CD98(unsigned *out, struct HS3Obj14 *obj, unsigned key)
{
    struct HS3RelHdr *h = obj->tbl;
    struct HS3E14K *end = (struct HS3E14K *)hs3_rel_end(h, 0x14);
    struct HS3E14K *begin = (struct HS3E14K *)hs3_rel_begin(h);
    struct HS3E14K *it = begin;
    if (begin != end) {
        for (; it != end; it++) {
            if (it->key == key) {
                *out = *(unsigned *)((char *)it + 4);
                return;
            }
        }
    }
    *out = lbl_88D45B1C->default_value;
}

struct HS3E10K { char pad[8]; unsigned pad8; unsigned key; };
struct HS3Blk50 { char pad[0x50]; struct HS3RelHdrN hdr; };
struct HS3Owner54 { char pad[0x54]; struct HS3Blk50 *blk; };

/* 2 if the entry with key 0xda554856 has a non-zero self-relative target word, else 1. */
int ts4_reltbl_check_da554856_888430C0(struct HS3Owner54 *owner)
{
    struct HS3RelHdrN *h = &owner->blk->hdr;
    int result = 1;
    struct HS3E10K *end = (struct HS3E10K *)hs3n_end(h, 0x10);
    struct HS3E10K *begin = (struct HS3E10K *)hs3n_begin(h);
    struct HS3E10K *it = begin;
    if (begin != end) {
        for (; it != end; it++) {
            if (it->key == 0xda554856) {
                int off = *(int *)it;
                if (*(int *)((char *)it + off) != 0)
                    result = 2;
                break;
            }
        }
    }
    return result;
}

struct HS3E12Z { unsigned w0; unsigned w4; unsigned char b8; unsigned char b9; char pad[2]; };
struct HS3Blk1c { char pad[0x1c]; struct HS3RelHdr hdr; };
struct HS3Owner24 { char pad[0x24]; struct HS3Blk1c *blk; };

/* Clear the +4 word and the +8/+9 bytes of every 12-byte entry. */
void ts4_reltbl_clear_entries_8883CAD8(struct HS3Owner24 *owner)
{
    struct HS3RelHdr *h = &owner->blk->hdr;
    struct HS3E12Z *end = (struct HS3E12Z *)hs3_rel_end(h, 12);
    struct HS3E12Z *it = (struct HS3E12Z *)hs3_rel_begin(h);
    if (it != end) {
        for (; it != end; it++) {
            it->w4 = 0;
            it->b8 = 0;
            it->b9 = 0;
        }
    }
}

struct HS3E2c { char pad[0x24]; unsigned w24; unsigned w28; };
struct HS3E48 { unsigned key; char pad[0x44]; };
struct HS3E18S { char pad[0x10]; unsigned id; unsigned svc; };
struct HS3Obj1c { char pad[0x1c]; struct HS3RelHdr *tbl; };
struct HS3GlobalsSvc { char pad[0x234]; void *p234; };
extern struct HS3GlobalsSvc *lbl_88D45B1C_svc;

struct HS3RelHdrN *fn_88841D10(void *self);
struct HS3RelHdrN *ts4_hash_find_null_888E1D40(void *self);
struct HS3RelHdrN *fn_88614938(void *svc, void *arg);
void *ts4_find_service(unsigned id);

/* Clear the +0x24/+0x28 words of every 0x2c-byte entry in the hash-null table. */
void ts4_reltbl_clear_pair_888E9678(void *self)
{
    struct HS3RelHdrN *h = ts4_hash_find_null_888E1D40(self);
    struct HS3E2c *end = (struct HS3E2c *)hs3n_end(h, 0x2c);
    struct HS3E2c *it = (struct HS3E2c *)hs3n_begin(h);
    if (it != end) {
        for (; it != end; it++) {
            it->w24 = 0;
            it->w28 = 0;
        }
    }
}

/* Resolve each 0x18-byte entry's service from its id. */
void ts4_reltbl_resolve_services_888C5250(struct HS3Obj1c *self)
{
    struct HS3RelHdr *h = self->tbl;
    struct HS3E18S *end = (struct HS3E18S *)hs3_rel_end(h, 0x18);
    struct HS3E18S *it = (struct HS3E18S *)hs3_rel_begin(h);
    if (end != it) {
        for (; end != it; it++)
            it->svc = (unsigned)(unsigned long)ts4_find_service(it->id);
    }
}

struct HS3Obj8 { char pad[8]; struct HS3RelHdrN hdr; };
struct HS3E8Q { unsigned key; unsigned value; };

/* Index of the 8-byte entry whose first word equals `key`, or -1. */
int ts4_reltbl_index_of_key_889253A0(struct HS3Obj8 *owner, unsigned key)
{
    struct HS3RelHdrN *h = &owner->hdr;
    int result = -1;
    int i = 0;
    struct HS3E8Q *end = (struct HS3E8Q *)hs3n_end(h, 8);
    struct HS3E8Q *begin = (struct HS3E8Q *)hs3n_begin(h);
    struct HS3E8Q *it = begin;
    if (end != begin) {
        for (; end != it; it++, i++) {
            if (key == it->key) {
                result = i;
                break;
            }
        }
    }
    return result;
}

struct HS3Ent18 { char pad[0x14]; unsigned char *p14; char pad2[0x18 - 0x18]; };
struct HS3Ent18b { char pad[0x14]; unsigned char *p14; };
struct HS3Obj1c2 { char pad[0x1c]; struct HS3RelHdr *tbl; };

int fn_888F0B20(void *self, void *entry);

/* For every 0x18-byte entry with a target at +0x14, store the computed byte at target+8. */
void ts4_reltbl_store_computed_byte_888F5650(struct HS3Obj1c2 *self)
{
    struct HS3RelHdr *h = self->tbl;
    struct HS3Ent18b *end = (struct HS3Ent18b *)hs3_rel_end(h, 0x18);
    struct HS3Ent18b *it = (struct HS3Ent18b *)hs3_rel_begin(h);
    if (end != it) {
        for (; end != it; it = (struct HS3Ent18b *)((char *)it + 0x18)) {
            if (it->p14)
                it->p14[8] = (unsigned char)fn_888F0B20(self, it);
        }
    }
}

struct HS3Slot2 {
    char pad[0x2c];
    struct HS3Mgr2Tgt *tgt;
    char pad2[0x74 - 0x30];
    unsigned char b74;
    unsigned char b75;
    char pad3[0xb4 - 0x76];
};
struct HS3Mgr2Tgt { char pad[0x103]; unsigned char b103; };
struct HS3Mgr2 {
    char pad[0xa8];
    struct HS3Blk1c0 *blk;
};

/* True if any slot has both +0x75 and +0x74 flags set. */
int ts4_mgr_any_slot_both_flags_887CFC48(struct HS3Mgr2 *self)
{
    struct HS3RelHdr *h = &self->blk->hdr;
    struct HS3Slot2 *end, *it;
    int result = 0;
    it = (struct HS3Slot2 *)hs3_rel_begin(h);
    end = (struct HS3Slot2 *)hs3_rel_end(h, 0xb4);
    for (; it != end; it++) {
        if (it->b75 && it->b74)
            return 1;
    }
    return result;
}

/* Clear the +0x103 flag on every active slot's target; true if any was set. */
int ts4_mgr_clear_target_flags_887D0020(struct HS3Mgr2 *self)
{
    struct HS3RelHdr *h = &self->blk->hdr;
    int result = 0;
    struct HS3Slot2 *it = (struct HS3Slot2 *)hs3_rel_begin(h);
    struct HS3Slot2 *end = (struct HS3Slot2 *)hs3_rel_end(h, 0xb4);
    if (it != end) {
        for (; it != end; it++) {
            if (it->b75 && it->tgt && it->tgt->b103) {
                result = 1;
                it->tgt->b103 = 0;
            }
        }
    }
    return result;
}

struct HS3E30 { char pad[0x24]; unsigned key; char pad2[0x30 - 0x28]; };
struct HS3Group { struct HS3RelHdrN hdr; char pad[0xd0 - 8]; };
struct HS3GroupTbl { int off; unsigned count; };
struct HS3Owner0xb0 { char pad[0xb0]; struct HS3GroupTbl *groups; };

/* In group `idx`, find the 0x30-byte entry whose +0x24 word equals *key, or 0. */
struct HS3E30 *ts4_groups_find_entry_by_key_887D4C78(struct HS3Owner0xb0 *self, unsigned *key, unsigned idx)
{
    struct HS3GroupTbl *g = self->groups;
    if (g && idx < g->count) {
        struct HS3RelHdrN *h = (struct HS3RelHdrN *)((char *)g + (idx * 0xd0 + g->off));
        struct HS3E30 *it = (struct HS3E30 *)hs3n_begin(h);
        struct HS3E30 *end = (struct HS3E30 *)hs3n_end(h, 0x30);
        if (it != end) {
            unsigned k = *key;
            for (; it != end; it++) {
                if (it->key == k)
                    return it;
            }
        }
    }
    return 0;
}

struct HS3E24 { char pad[0xc]; unsigned w0c; unsigned key10; char pad2[0x24 - 0x14]; };
struct HS3Blk1d0 { char pad[0xc]; unsigned w0c; char pad2[0x1d0 - 0x10]; struct HS3RelHdr hdr; };
struct HS3Mgr1d0 { char pad[0xa8]; struct HS3Blk1d0 *blk; };

/* Pick the entry for *key: prefer one tagged with the block's id, else the first untagged one. */
struct HS3E24 *ts4_reltbl_pick_entry_by_key_887CFF68(struct HS3Mgr1d0 *self, unsigned *key)
{
    struct HS3Blk1d0 *blk = self->blk;
    struct HS3RelHdr *h = &blk->hdr;
    struct HS3E24 *first = 0;
    struct HS3E24 *second = 0;
    struct HS3E24 *it = (struct HS3E24 *)hs3_rel_begin(h);
    struct HS3E24 *end = (struct HS3E24 *)hs3_rel_end(h, 0x24);
    if (it != end) {
        unsigned k = *key;
        for (; it != end; it++) {
            if (k == it->key10) {
                if (it->w0c == 0) {
                    if (!first)
                        first = it;
                } else if (it->w0c == blk->w0c) {
                    if (!second)
                        second = it;
                }
            }
        }
        if (second)
            return second;
    }
    return first;
}

/* Signed lookup in a sorted 8-byte table: positive n finds value of first key >= n, negative n mirrors it. */
int ts4_reltbl_signed_lower_bound_8883D7E8(struct HS3RelHdrN *h, int n)
{
    int result = 0;
    if (n > 0) {
        struct HS3E8K *it = (struct HS3E8K *)hs3n_begin(h);
        struct HS3E8K *end = (struct HS3E8K *)hs3n_end(h, 8);
        if (it != end) {
            for (; it != end; it++) {
                if (it->key >= n)
                    break;
            }
            if (it != end)
                result = it->value;
        }
    } else if (n < 0) {
        struct HS3E8K *it = (struct HS3E8K *)hs3n_begin(h);
        struct HS3E8K *end = (struct HS3E8K *)hs3n_end(h, 8);
        if (it != end) {
            for (; it != end; it++) {
                if (it->key >= -n)
                    break;
            }
            if (it != end)
                result = -it->value;
        }
    }
    return result;
}

struct HS3Tgt64 { char pad[0x47]; unsigned char b47; int w48; };
struct HS3Owner54b { char pad[0x54]; struct HS3Blk50 *blk; char pad2[0x64 - 0x58]; struct HS3Tgt64 *tgt; };

/* Record 0/1 in the target based on the da554856 entry's self-relative flag and the requested mode. */
void ts4_reltbl_record_da554856_mode_88843650(struct HS3Owner54b *owner, unsigned char mode)
{
    struct HS3RelHdrN *h = &owner->blk->hdr;
    int result = 1;
    struct HS3E10K *end = (struct HS3E10K *)hs3n_end(h, 0x10);
    struct HS3E10K *begin = (struct HS3E10K *)hs3n_begin(h);
    struct HS3E10K *it = begin;
    if (begin != end) {
        for (; it != end; it++) {
            if (it->key == 0xda554856) {
                int off = *(int *)it;
                if (*(int *)((char *)it + off) == 0) {
                    if (mode == 0)
                        result = 2;
                } else {
                    if (mode == 1)
                        result = 2;
                }
                break;
            }
        }
    }
    {
        struct HS3Tgt64 *t = owner->tgt;
        t->w48 = result - 1;
        t->b47 = 0;
    }
}
