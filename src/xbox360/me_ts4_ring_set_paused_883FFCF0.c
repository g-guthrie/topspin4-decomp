/* 0x883FFCF0: sets the pause state of a 4-slot ring's device: no-op when unchanged; reads the device time (slot 22); on resume pushes time+offset to every queued item (883E64F8) and rebases the device by the elapsed base, on pause stops each item (883E5E78) and stores the time at dev+0x10; then stores the flag at dev+8. The ring index is a wrap helper written as x < 0 ? x + (1 - x/4)*4 : x - x/4*4 */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef unsigned long long u64;
typedef struct Dev Dev;
typedef struct DevVt {
    void *f0[5];
    unsigned char (*paused)(Dev *d);
    u64 (*base)(Dev *d);
    void *f7[2];
    unsigned int (*offset)(Dev *d);
    void *f10[8];
    void (*set_base)(Dev *d, u64 t);
    void *f19[3];
    int (*now)(Dev *d, u64 *t);
} DevVt;
struct Dev { DevVt *vt; int p4; unsigned char paused; char pad[0x10 - 9]; u64 stamp; };
typedef struct Ring { void *items[4]; int head; unsigned int count; int p18; Dev *dev; } Ring;
static int wrap4(int x) { return x < 0 ? x + (1 - x / 4) * 4 : x - x / 4 * 4; }
void fn_883E64F8(void *it, u64 t);
int ts4_get_u32_offc_883E5E78(void *it);

int fn_883FFCF0(Ring *r, unsigned char on)
{
    u64 now, t;
    unsigned int i;
    void *it;
    int e;
    if (r->dev->vt->paused(r->dev) == on)
        return 0;
    e = r->dev->vt->now(r->dev, &now);
    if (e)
        return e;
    if (!on) {
        t = now + r->dev->vt->offset(r->dev);
        for (i = 0; i < r->count; i++) {
            it = r->items[wrap4(r->head + i)];
            if (it)
                fn_883E64F8(it, t);
        }
        r->dev->vt->set_base(r->dev, t - r->dev->vt->base(r->dev));
    } else {
        for (i = 0; i < r->count; i++) {
            it = r->items[wrap4(r->head + i)];
            if (it)
                ts4_get_u32_offc_883E5E78(it);
        }
        r->dev->stamp = now;
    }
    r->dev->paused = on;
    return 0;
}
