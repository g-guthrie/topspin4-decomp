/* Swing_DLL.xex 0x88152480-0x88210FD8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObject {
    void **vtable;
} Ts4VObject;


typedef struct Ts4LimitGuard {
    u8 pad[0xc];
    int flag;
} Ts4LimitGuard;

u8 ts4_check_limit_80_88152480(Ts4LimitGuard *self, u32 count)
{
    u8 ok = count <= 0x80;
    if (!ok) {
        if (self->flag == 0) {
            self->flag = 1;
        }
    }
    return ok;
}

u8 ts4_check_limit_4b0_88157200(Ts4LimitGuard *self, u32 count)
{
    u8 ok = count <= 0x4b0;
    if (!ok) {
        if (self->flag == 0) {
            self->flag = 1;
        }
    }
    return ok;
}

u8 ts4_check_limit_400_8816DB00(Ts4LimitGuard *self, u32 count)
{
    u8 ok = count <= 0x400;
    if (!ok) {
        if (self->flag == 0) {
            self->flag = 1;
        }
    }
    return ok;
}

typedef struct Ts4SlotCaller {
    u8 pad[0x10];
    Ts4VObject *target;
} Ts4SlotCaller;

typedef struct Ts4PairKey {
    u32 first;
    u32 second;
} Ts4PairKey;

u8 ts4_pair_differs_881876A0(Ts4PairKey *self, Ts4PairKey *other)
{
    return other->first != self->first || other->second != self->second;
}

typedef struct Ts4FloatOps {
    u8 pad[0x14];
    float *values;
} Ts4FloatOps;

void ts4_float_sub_88179580(Ts4FloatOps *self, int *args)
{
    int *indices = (int *)((char *)args + args[0]);
    float *values = self->values;
    values[indices[2]] = values[indices[0]] - values[indices[1]];
}

void ts4_float_div_881795B8(Ts4FloatOps *self, int *args)
{
    int *indices = (int *)((char *)args + args[0]);
    float *values = self->values;
    values[indices[2]] = values[indices[0]] / values[indices[1]];
}
