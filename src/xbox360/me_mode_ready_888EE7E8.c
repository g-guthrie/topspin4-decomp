/* 0x888EE7E8: true when the global object at lbl_88D4591C is absent or not busy (+0x7C), the engine mode (+0x278)
 * is 4 or 2, and fn_8817CA20 reports true (low byte). */
typedef unsigned char u8;
typedef struct Ts4Engine { char pad[0x278]; int mode; } Ts4Engine;
typedef struct Ts4BusyObj { char pad[0x7c]; u8 busy; } Ts4BusyObj;
extern Ts4Engine *lbl_88D45B1C;
extern Ts4BusyObj *lbl_88D4591C;
extern int fn_8817CA20(void);
static u8 not_busy(void)
{
    Ts4BusyObj *o = lbl_88D4591C;
    if (o && o->busy) return 0;
    return 1;
}
u8 ts4_mode_ready_888EE7E8(void)
{
    u8 idle = not_busy();
    int mode = lbl_88D45B1C->mode;
    return idle && (mode == 4 || mode == 2) && (u8)fn_8817CA20();
}
