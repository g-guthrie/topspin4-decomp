/* CX30 part e: Pam core small functions, third pass. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

/* 0x8860DDF8: release the owned objects in the slot table at +0xec (12-byte slots, up to +0x164): call slot 5, delete through slot 0, clear the slot; stops at the first empty slot; does nothing without the object at +0xf4 */
typedef struct Cx30Ob { struct Cx30ObV *vt; } Cx30Ob;
typedef struct Cx30ObV { void (*f0)(Cx30Ob *, u32); u32 pad[4]; void (*f14)(Cx30Ob *); } Cx30ObV;
typedef struct Cx30Slot { u32 f0; u32 f4; Cx30Ob *obj; } Cx30Slot;
typedef struct Cx30Slots2 { u8 pad[0xec]; Cx30Slot it[10]; } Cx30Slots2;
void ts4_slots_release_all_8860DDF8(Cx30Slots2 *o)
{
    Cx30Slot *p;
    Cx30Slot *e;
    if (*(u32 *)((u8 *)o + 0xf4) != 0) {
        e = (Cx30Slot *)((u8 *)o + 0x164);
        p = (Cx30Slot *)((u8 *)o + 0xec);
        if (p < e) {
            do {
                Cx30Ob *b = p->obj;
                if (b == 0) break;
                b->vt->f14(b);
                b = p->obj;
                if (b) b->vt->f0(b, 1);
                p->obj = 0;
                p->f0 = 0;
                p++;
            } while (p < e);
        }
    }
}
