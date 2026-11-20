/* CW40 part g: object list broadcast guarded by a global-state predicate helper. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX40_INL static __forceinline
#else
#define CX40_INL static inline
#endif
typedef struct Cx40GVt { void *s[2]; void (*s8)(void *); } Cx40GVt;
typedef struct Cx40GObj { Cx40GVt *vt; } Cx40GObj;
typedef struct Cx40GState { char pad[0x24]; u32 *p24; } Cx40GState;
extern Cx40GState *lbl_88D45940;

/* the global state exists and its current hash is the "paused" hash */
CX40_INL u8 cx40_state_paused(void)
{
    if (lbl_88D45940 != 0) {
        if (*lbl_88D45940->p24 == 0x165BBDE9u) return 1;
    }
    return 0;
}

/* 0x887FFC20: unless paused, run slot 2 of every object in the list at +0x1c. */
void ts4_broadcast_unless_paused_887FFC20(char *self)
{
    if (!cx40_state_paused()) {
        Cx40GObj **e = *(Cx40GObj ***)(self + 0x20);
        Cx40GObj **b = *(Cx40GObj ***)(self + 0x1c);
        if (e != b) {
            do { (*b)->vt->s8(*b); b++; } while (b != e);
        }
    }
}
