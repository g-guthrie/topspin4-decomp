/* R6: net/session slot update (Swing_DLL.xex 0x889xxxxx). */
typedef unsigned int u32;
typedef unsigned char u8;

extern char lbl_880D9874;

typedef struct Ts4NetSlot {
    u8 active;          /* 0x00 */
    u8 pad1[0xF];
    u32 value_10;       /* 0x10 */
    u32 value_14;       /* 0x14 */
    u8 pad18[0x60 - 0x18];
    u8 pending;         /* 0x60 */
    u8 pad61[0x74 - 0x61];
    u32 handle;         /* 0x74 */
    u8 pad78[8];
} Ts4NetSlot; /* 0x80 bytes */

typedef struct Ts4NetSlotOwner {
    u8 pad0[0x1F];
    u8 locked;          /* 0x1f */
    u8 pad20[2];
    u8 use_alt;         /* 0x22 */
    u8 pad23[1];
    Ts4NetSlot slots[4]; /* 0x24 */
    u8 pad_after[0x2C8 - 0x24 - 4 * 0x80];
    u32 reset_2c8;      /* 0x2c8 */
} Ts4NetSlotOwner;

void fn_88908958(Ts4NetSlotOwner *owner, Ts4NetSlot *slot);
void fn_88908870(Ts4NetSlotOwner *owner, Ts4NetSlot *slot, int which);
void fn_889087F0(Ts4NetSlotOwner *owner, Ts4NetSlot *slot, int which);
void fn_88907570(Ts4NetSlotOwner *owner, u32 handle, void *text, u32 value);

/* Swing_DLL.xex 0x88908B80: process each of the four active slots, with two modes selected by the flag arguments. */
void ts4_net_update_slots_88908B80(Ts4NetSlotOwner *owner, u8 mode_a, u8 mode_b)
{
    Ts4NetSlot *slot = owner->slots;
    u32 remaining;

    for (remaining = 4; remaining != 0; remaining--, slot++) {
        if (slot->active == 0) {
            continue;
        }
        if (mode_a) {
            fn_88908958(owner, slot);
            if (mode_b) {
                fn_88908870(owner, slot, 0);
                fn_88908870(owner, slot, 1);
            }
        } else {
            owner->reset_2c8 = 0;
            if (owner->locked == 0 && slot->pending != 0) {
                slot->pending = 0;
                fn_88907570(owner, slot->handle, &lbl_880D9874,
                            owner->use_alt ? slot->value_14 : slot->value_10);
            }
            if (mode_b) {
                fn_889087F0(owner, slot, 0);
                fn_889087F0(owner, slot, 1);
            }
        }
    }
}
