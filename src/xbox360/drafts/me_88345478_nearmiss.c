/* 0x88345478: From an interface pointer at +0x1c (null-checked downcast), resets 16 channels (float arrays +0x210/+0x250 to lbl_88001A20, int arrays +0x1d0/+0x290 to 0), clears the byte at +0x170, returns 0. */
/* Near miss (agAH): 3 off on /Oc /Os: the constant is reloaded each pass and the b/a stores swap. On /Oc with the constant in a local the loop body matches but the lfs is scheduled before mtctr (5 off). */
extern const float lbl_88001A20;
typedef struct Mixer {
    char pad0[0x1c];
    void *iface;
    char pad20[0x170 - 0x20];
    unsigned char dirty;
    char pad171[0x1d0 - 0x171];
    int b[16];
    float a[16];
    float c[16];
    int d[16];
} Mixer;
int fn_88345478(void *iface)
{
    Mixer *m = iface ? (Mixer *)((char *)iface - 0x1c) : 0;
    
    int i;
    for (i = 0; i < 16; i++) {
        float one = lbl_88001A20; m->b[i] = 0; m->a[i] = one; m->c[i] = one; m->d[i] = 0;
    }
    m->dirty = 0;
    return 0;
}
