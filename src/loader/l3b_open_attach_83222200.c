/* Loader_DLL.xex 0x83222200-0x832235E0, executable version 0.0.0.3.
 * Open the attached device (virtual slot 14), then attach it (slot 17). */

typedef struct Ts4lDev Ts4lDev;
typedef struct {
    char pad[0x38];
    int (*open)(Ts4lDev *, int);
} Ts4lDevVt;
struct Ts4lDev {
    Ts4lDevVt *vt;
};
typedef struct Ts4lOwner Ts4lOwner;
typedef struct {
    char pad[0x44];
    int (*attach)(Ts4lOwner *, Ts4lDev *);
} Ts4lOwnerVt;
struct Ts4lOwner {
    Ts4lOwnerVt *vt;
    char pad[0x30];
    Ts4lDev *dev;
};

int ts4l_open_and_attach_83222200(Ts4lOwner *o)
{
    int r = 0;
    if (o->dev != 0) {
        r = o->dev->vt->open(o->dev, 1);
        if (r >= 0)
            r = o->vt->attach(o, o->dev);
    }
    return r;
}

int ts4l_open_and_attach_832235E0(Ts4lOwner *o)
{
    int r = 0;
    if (o->dev != 0) {
        r = o->dev->vt->open(o->dev, 1);
        if (r >= 0)
            r = o->vt->attach(o, o->dev);
    }
    return r;
}
