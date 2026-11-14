/* Loader_DLL.xex 0x8344CFC0-0x8344D048, executable version 0.0.0.3. */
typedef unsigned long u32;
typedef struct Ts4lCinfo Ts4lCinfo;
typedef struct { void *(*alloc)(Ts4lCinfo *c, int pool, u32 size); } Ts4lMem;
typedef struct {
    void *f0; void *f4; void *f8; void *fc; u32 f10; u32 f14; u32 f18;
} Ts4lObj;
struct Ts4lCinfo { u32 p0; Ts4lMem *mem; char pad[0x1b8 - 8]; Ts4lObj *obj; };
extern void fn_8344CDF8(void);
extern void ts4l_get_u32_off1b8_8344CF28(void);
extern void ts4l_get_fn_8344CAC0_8344CD88(void);
extern void ts4_get_u32_off1b8_8344CFA8(void);
void ts4l_init_obj_8344CFC0(Ts4lCinfo *c)
{
    Ts4lObj *o = (Ts4lObj *)c->mem->alloc(c, 0, 0x1c);
    c->obj = o;
    o->f0 = (void *)fn_8344CDF8;
    o->f4 = (void *)ts4l_get_u32_off1b8_8344CF28;
    o->f8 = (void *)ts4l_get_fn_8344CAC0_8344CD88;
    o->fc = (void *)ts4_get_u32_off1b8_8344CFA8;
    o->f10 = 0;
    o->f14 = 0;
    o->f18 = 1;
}
