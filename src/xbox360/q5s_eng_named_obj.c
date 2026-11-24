/* q5s eng: named object reset (LTCG). */
#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef unsigned int u32;
typedef unsigned char u8;

extern char lbl_880C1320[]; /* default name string */
extern void ts4_vec204_move_tail_881B9148(void *p);

typedef struct EngNamedObj {
    u8 pad0[8];
    u8 flag;          /* 0x08 */
    u8 pad9[7];
    u8 sub[0x18];     /* 0x10: container reset by ts4_vec204_move_tail_881B9148 */
    u32 w28;
    u32 w2c;
    u32 w30;
    u32 kind;         /* 0x34 */
    char name[0x3c];  /* 0x38: bounded copy, 0x3b chars + NUL */
} EngNamedObj;

static __forceinline void eng_name_copy(char *dst, const char *src, u32 cap)
{
    char *end = dst + cap;
    while (dst != end && *src != 0)
        *dst++ = *src++;
    *dst = 0;
}

void ts4_named_obj_reset_8861E2E0(EngNamedObj *self)
{
    self->w28 = 0;
    self->w2c = 0;
    self->w30 = 0;
    self->kind = 2;
    eng_name_copy(self->name, lbl_880C1320, sizeof(self->name) - 1);
    self->flag = 0;
    ts4_vec204_move_tail_881B9148(self->sub);
}
