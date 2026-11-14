/* Loader_DLL.xex 0x830AE870-0x830AEAA0, executable version 0.0.0.3. */

typedef struct ts4l_gres {
    unsigned int flags;     /* 0x00 */
    unsigned int pad04;
    unsigned int owner;     /* 0x08 */
    unsigned char pad0c[0x0C];
    unsigned int addr18;    /* 0x18 */
    unsigned int size1c;    /* 0x1C */
    unsigned int addr20;    /* 0x20 */
    unsigned char pad24[0x08];
    unsigned int addr2c;    /* 0x2C */
    unsigned int addr30;    /* 0x30 */
} ts4l_gres;

extern char __imp_VdGlobalDevice[];
extern char __imp_VdGlobalXamDevice[];
extern unsigned int lbl_8354494C;

extern int KeGetCurrentProcessType(void);
extern void fn_830BB598(unsigned int dev, unsigned int owner, int kind, int zero);
extern void fn_8340D830(unsigned int addr, unsigned int tag);
extern void fn_830D2B48(unsigned int a, unsigned int b);
extern void ts4l_if_call_seq_u32_off98_830CD8B0(ts4l_gres *r);
extern void ts4l_if_call_seq_u32_off6c_830D2560(ts4l_gres *r);

#define NOTIFY(kind) \
    if (r->owner != 0 && dev != 0) \
        fn_830BB598(dev, r->owner, (kind), 0)

void ts4l_gres_release_830AE870(ts4l_gres *r)
{
    unsigned int dev;
    unsigned int a;

    if (KeGetCurrentProcessType() == 2)
        dev = **(unsigned int **)__imp_VdGlobalXamDevice;
    else
        dev = **(unsigned int **)__imp_VdGlobalDevice;

    switch (r->flags & 0xF) {
    case 4:
        if (r->flags & 0x40000000u)
            break;
        if (r->flags & 0x80000000u)
            fn_830D2B48(r->size1c & 0xFFFu, r->addr2c / 0x1400u);
        if (r->addr20 & 1u)
            lbl_8354494C = 0;
        break;
    case 3:
        NOTIFY(13);
        a = r->addr30 & ~0xFFFu;
        fn_8340D830(r->addr20 & ~0xFFFu, 0xB1800000u);
        fn_8340D830(a, 0xB1800000u);
        break;
    case 1:
        NOTIFY(9);
        fn_8340D830(r->addr18 & ~3u, 0xB1800000u);
        break;
    case 2:
        NOTIFY(11);
        fn_8340D830(r->addr18, 0xB1800000u);
        break;
    case 6:
        NOTIFY(7);
        fn_8340D830(r->addr20, 0xB1800000u);
        break;
    case 7:
        NOTIFY(8);
        fn_8340D830(r->addr18, 0xB1800000u);
        break;
    case 8:
        NOTIFY(17);
        fn_8340D830(r->addr18, 0xB1800000u);
        break;
    case 9:
        NOTIFY(15);
        ts4l_if_call_seq_u32_off98_830CD8B0(r);
        break;
    case 10:
        NOTIFY(21);
        ts4l_if_call_seq_u32_off6c_830D2560(r);
        break;
    default:
        break;
    }
    fn_8340D830((unsigned int)(unsigned long)r, 0x24800000u);
}
