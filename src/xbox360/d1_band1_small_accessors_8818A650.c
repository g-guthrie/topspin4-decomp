/* Swing_DLL.xex 0x8818A650-0x88210FD8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4VObject {
    void **vtable;
} Ts4VObject;

extern void RtlEnterCriticalSection(void *section);
extern void RtlLeaveCriticalSection(void *section);
extern void fn_88193438(void *self);
extern void fn_88193840(void *self);
extern int ts4_tailcall_fn_88582F30_8857A128(void *p);
extern void fn_881E19C0(void);
extern void fn_881DFE70(void);
extern void fn_881E0258(void);
extern u32 fn_881CCEE0(void);

typedef struct Ts4Forwarder34 {
    u8 pad[0x34];
    long target;
} Ts4Forwarder34;

typedef struct Ts4Holder4 {
    u8 pad[4];
    void *child;
} Ts4Holder4;

typedef struct Ts4Range7C {
    u8 pad[0x7c];
    u32 begin;
    u8 pad2[0x10];
    u32 length;
} Ts4Range7C;

u8 ts4_in_range_88197D30(Ts4Range7C *self, u32 value)
{
    return value >= self->begin && value < self->begin + self->length;
}
