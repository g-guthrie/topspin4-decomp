/* 0x885C3A58: For every bank of the mixer (u16 count at +0x22, 0x6F0-byte banks at +0x140), clears the active flag of the given 0x1C-byte slot and the u16 its link points to. */
/* Matched on /Oc (agAH). Bank taken into a local (Bank *b = &m->banks[i]) to get the add operand order. */
typedef struct Slot { unsigned short active; char pad2[0xa]; unsigned short *link; char pad10[0xc]; } Slot;
typedef struct Bank { char pad[0x1a8]; Slot *slots; char pad1ac[0x6f0 - 0x1ac]; } Bank;
typedef struct Mixer { char pad[0x22]; unsigned short bankCount; char pad24[0x140 - 0x24]; Bank *banks; } Mixer;
void fn_885C3A58(Mixer **pm, int slot)
{
    Mixer *m = *pm;
    int i;
    for (i = 0; i < m->bankCount; i++) {
        Bank *b = &m->banks[i];
        Slot *s = &b->slots[slot];
        s->active = 0;
        *s->link = 0;
    }
}
