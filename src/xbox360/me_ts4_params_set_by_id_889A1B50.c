/* Swing_DLL.xex 0x889A1B50: Stores value into the int field selected by a 0x1000xxxx parameter id (8 ids); unknown ids are ignored.
 * /Oc. Case order follows the target's block order (agAE rule); the first argument is unused. */
typedef struct Params {
    unsigned char pad[0x5c];
    int p5c, p60, p64, p68;   /* 0x5c..0x68 */
    unsigned char pad6c[4];
    int p70;                  /* 0x70 */
    unsigned char pad74[0x90 - 0x74];
    int p90, p94;             /* 0x90, 0x94 */
    unsigned char pad98[4];
    int p9c;                  /* 0x9c */
} Params;

void fn_889A1B50(void *ctx, Params *p, unsigned int id, int value)
{
    switch (id) {
    case 0x1000001E: p->p90 = value; break;
    case 0x1000001D: p->p94 = value; break;
    case 0x10000057: p->p60 = value; break;
    case 0x10000058: p->p64 = value; break;
    case 0x10000059: p->p70 = value; break;
    case 0x1000008D: p->p5c = value; break;
    case 0x10000081: p->p9c = value; break;
    case 0x1000005C: p->p68 = value; break;
    }
}
