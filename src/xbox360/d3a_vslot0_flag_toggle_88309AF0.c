/* Swing_DLL.xex 0x88309AF0-0x883361E8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int (*ts4_slot_fn)(void *, u32);
#define TS4_SLOT(self, off) (*(ts4_slot_fn *)(*(u8 **)(self) + (off)))
#define TS4_FLAG(self, off) (*((u8 *)(self) + (off)))


/* Calls a virtual setter, then latches or clears a flag byte. */
int ts4_vslot0_flag_toggle_88309AF0(void *self, u32 arg)
{
    int r;
    if (arg) {
        if (TS4_FLAG(self, 0x1bc)) return 0;
        r = TS4_SLOT(self, 0)(self, arg);
        if (r) return r;
        TS4_FLAG(self, 0x1bc) = 1;
    } else {
        r = TS4_SLOT(self, 0)(self, 0);
        if (r) return r;
        TS4_FLAG(self, 0x1bc) = 0;
    }
    return 0;
}


/* Calls a virtual setter, then latches or clears a flag byte. */
int ts4_vslot0_flag_toggle_8830D1D0(void *self, u32 arg)
{
    int r;
    if (arg) {
        if (TS4_FLAG(self, 0x10)) return 0;
        r = TS4_SLOT(self, 0)(self, arg);
        if (r) return r;
        TS4_FLAG(self, 0x10) = 1;
    } else {
        r = TS4_SLOT(self, 0)(self, 0);
        if (r) return r;
        TS4_FLAG(self, 0x10) = 0;
    }
    return 0;
}


/* Calls a virtual setter, then latches or clears a flag byte. */
int ts4_vslot0_flag_toggle_8830E098(void *self, u32 arg)
{
    int r;
    if (arg) {
        if (TS4_FLAG(self, 0x64)) return 0;
        r = TS4_SLOT(self, 0)(self, arg);
        if (r) return r;
        TS4_FLAG(self, 0x64) = 1;
    } else {
        r = TS4_SLOT(self, 0)(self, 0);
        if (r) return r;
        TS4_FLAG(self, 0x64) = 0;
    }
    return 0;
}


/* Calls a virtual setter, then latches or clears a flag byte. */
int ts4_vslot0_flag_toggle_8832E778(void *self, u32 arg)
{
    int r;
    if (arg) {
        if (TS4_FLAG(self, 0x4)) return 0;
        r = TS4_SLOT(self, 0)(self, arg);
        if (r) return r;
        TS4_FLAG(self, 0x4) = 1;
    } else {
        r = TS4_SLOT(self, 0)(self, 0);
        if (r) return r;
        TS4_FLAG(self, 0x4) = 0;
    }
    return 0;
}


/* Calls a virtual setter, then latches or clears a flag byte. */
int ts4_vslot0_flag_toggle_88336160(void *self, u32 arg)
{
    int r;
    if (arg) {
        if (TS4_FLAG(self, 0x14)) return 0;
        r = TS4_SLOT(self, 0)(self, arg);
        if (r) return r;
        TS4_FLAG(self, 0x14) = 1;
    } else {
        r = TS4_SLOT(self, 0)(self, 0);
        if (r) return r;
        TS4_FLAG(self, 0x14) = 0;
    }
    return 0;
}
