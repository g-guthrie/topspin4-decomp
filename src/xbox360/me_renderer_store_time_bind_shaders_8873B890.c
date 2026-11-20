/* 0x8873B890: renderer: store counter/frequency as float at +0x15634, then under the global lock at Sys+0x154 bind shaders (0x2A, 0x56) on the device at +0x15720. */

typedef struct Lock Lock;
typedef struct { void *f0; void (*lock)(Lock *); void (*unlock)(Lock *); } LockVt;
struct Lock { LockVt *vt; };
typedef struct { char p0[0x154]; Lock lock; } Sys;
typedef struct { char p0[0x15634]; float counter_seconds; char p1[0x15720 - 0x15638]; void *dev; } Obj;
extern Sys *lbl_88D45A4C;
void fn_8857AFF0(long long *count);
void fn_8857B010(long long *freq);
void fn_882910E8(void *dev, unsigned int vs, unsigned int ps);
void fn_8873B890(Obj *o)
{
    long long a, b;
    Sys *s;
    fn_8857AFF0(&a);
    fn_8857B010(&b);
    s = lbl_88D45A4C;
    o->counter_seconds = (float)((double)a / (double)b);
    s->lock.vt->lock(&s->lock);
    fn_882910E8(o->dev, 0x2a, 0x56);
    s->lock.vt->unlock(&s->lock);
}
