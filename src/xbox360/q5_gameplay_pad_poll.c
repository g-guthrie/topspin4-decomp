/* Q5 gameplay: controller poll; refresh the cached input state and the connected flag. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Q5PadState {     /* XINPUT_STATE layout: packet number + 12-byte gamepad */
    u32 packet;
    char gamepad[0xc];
} Q5PadState;
typedef struct Q5Pad {
    char pad0[4];
    Q5PadState state;           /* +0x04 */
    u32 port;                   /* +0x14 */
    char pad18[4];
    u8 connected;               /* +0x1c */
} Q5Pad;

/* 0x8857B170: XInputGetState-style wrapper, tail-calls XamInputGetState(port, 1, state); 0 on success. */
extern u32 ts4_tailcall_XamInputGetState_8857B170(u32 port, Q5PadState *state);

/* Swing_DLL.xex 0x88884C88 */
void ts4_pad_poll_88884C88(Q5Pad *self)
{
    self->connected = 0 == ts4_tailcall_XamInputGetState_8857B170(self->port, &self->state);
}
