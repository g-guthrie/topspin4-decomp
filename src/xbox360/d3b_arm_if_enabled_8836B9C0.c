/* Swing_DLL.xex 0x8836B9C0-0x8836BA58, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Cfg { char pad[0x188]; unsigned flags; } Cfg;
typedef struct Obj { char pad[0x108]; Cfg *cfg; char pad2[8]; void *target; unsigned char armed; } Obj;
int fn_883A7EC8(Obj *self, void *target, u64 arg);

int ts4_arm_if_enabled_8836B9C0(Obj *self, int unused, unsigned arg)
{
    (void)unused;
    if (self->target == 0) return 0x25;
    if (self->cfg->flags & 1) {
        if (fn_883A7EC8(self, self->target, arg) == 0) return 0x21;
        self->armed = 1;
    }
    return 0;
}
