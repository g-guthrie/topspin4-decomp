/* Swing_DLL.xex 0x887795C0: notify the global manager, owner sub-object, then manager again (twin ts4_client_register_88211418) */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cw10Mgr { const struct Cw10MgrVt *vt; } Cw10Mgr;
typedef struct Cw10Sub { const struct Cw10SubVt *vt; } Cw10Sub;
typedef struct Cw10Owner { u8 pad[0xc]; u32 wc; u8 pad2[4]; Cw10Sub sub; } Cw10Owner;
typedef struct Cw10Client { u8 pad[0x24]; Cw10Owner *owner; } Cw10Client;
struct Cw10MgrVt { void *s0[9]; void (*f9)(Cw10Mgr *); void *s1[7]; void (*f17)(Cw10Mgr *, u32, Cw10Owner *); };
struct Cw10SubVt { void *s0[11]; void (*f11)(Cw10Sub *, Cw10Client *); };
extern Cw10Mgr *lbl_88D41F80;
void ts4_client_register_887795C0(Cw10Client *self)
{
    lbl_88D41F80->vt->f9(lbl_88D41F80);
    self->owner->sub.vt->f11(&self->owner->sub, self);
    lbl_88D41F80->vt->f17(lbl_88D41F80, self->owner->wc, self->owner);
}
