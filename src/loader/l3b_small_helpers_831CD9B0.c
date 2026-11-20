/* Loader_DLL.xex 0x831CD9B0-0x83268718, executable version 0.0.0.3.
 * Small helpers: PCM sub-format GUID builder, gain scaling and a request
 * submit through a virtual call. */

#ifdef _MSC_VER
void *memset(void *, int, unsigned);
#pragma intrinsic(memset)
#else
#include <string.h>
#endif

typedef struct {
    unsigned d1;
    unsigned short d2, d3;
    unsigned char d4[8];
} Ts4lGuid;

#define TS4L_BUILD_GUID(NAME)                \
    void NAME(unsigned short a, Ts4lGuid *g) \
    {                                        \
        g->d1 = a;                           \
        g->d2 = 0;                           \
        g->d3 = 0x10;                        \
        g->d4[0] = 0x80;                     \
        g->d4[1] = 0;                        \
        g->d4[2] = 0;                        \
        g->d4[3] = 0xaa;                     \
        g->d4[4] = 0;                        \
        g->d4[5] = 0x38;                     \
        g->d4[6] = 0x9b;                     \
        g->d4[7] = 0x71;                     \
    }

TS4L_BUILD_GUID(ts4l_make_format_guid_831CD9B0)
TS4L_BUILD_GUID(ts4l_make_format_guid_83268718)

typedef struct {
    float gain;
    int pad;
    float *src;
    int pad2;
    int n;
} Ts4lGain;

#define TS4L_APPLY_GAIN(NAME)                                     \
    int NAME(Ts4lGain *g, float *dst, int *outn)                  \
    {                                                             \
        int i;                                                    \
        for (i = 0; i < g->n; i++)                                \
            dst[i] = g->src[i] * g->gain;                         \
        if (outn != 0)                                            \
            *outn = g->n;                                         \
        return 0;                                                 \
    }

TS4L_APPLY_GAIN(ts4l_apply_gain_831FF670)
TS4L_APPLY_GAIN(ts4l_apply_gain_832734B8)

typedef struct Ts4lObj Ts4lObj;
typedef struct {
    char pad[0x2c];
    int (*submit)(Ts4lObj *, void *);
} Ts4lObjVt;
struct Ts4lObj {
    Ts4lObjVt *vt;
};
typedef struct {
    unsigned a, b, c, d, e, f, g;
} Ts4lRequest28;

#define TS4L_SUBMIT_REQUEST(NAME)                    \
    int NAME(Ts4lObj *o, unsigned x)                 \
    {                                                \
        Ts4lRequest28 z;                             \
        memset(&z, 0, sizeof(z));                    \
        z.a = x;                                     \
        return o->vt->submit(o, &z);                 \
    }

TS4L_SUBMIT_REQUEST(ts4l_submit_request_83221FD0)
TS4L_SUBMIT_REQUEST(ts4l_submit_request_832233B8)
