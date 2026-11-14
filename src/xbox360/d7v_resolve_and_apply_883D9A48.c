/* Swing_DLL.xex 0x883D9A48-0x883D9AD0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4X1Target { char pad[0x60]; u32 flags; } Ts4X1Target;
int fn_883CB130(void *handle, Ts4X1Target **out);
int fn_883D9528(void *self, Ts4X1Target *target, u32 arg, int zero);

int ts4_resolve_and_apply_883D9A48(void *self, void *handle, u32 arg)
{
    Ts4X1Target *target = 0;
    if (handle != 0) {
        int r = fn_883CB130(handle, &target);
        if (r != 0)
            return r;
        if (target != 0 && (target->flags & 1) != 0)
            return 0x57;
    }
    return fn_883D9528(self, target, arg, 0);
}
