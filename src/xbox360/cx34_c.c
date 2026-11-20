/* CW34 part c: camera / minigame objects (0x888AA8D0-0x888D8000), plain route. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))
#define CX34_VT(o, slot) ((*(void ***)(o))[(slot) / 4])

extern float lbl_8814B440;
extern void ts4_update_angles_888AD6F0(char *self);

static __inline void cx34_v3(float *d, float *s)
{
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

/* 0x888AEBF8: unless the lock byte +0x14C is set, copy the three position triples and publish them through the pointers at +0x6C/+0x70/+0x74 */
void ts4_publish_position_triples_888AEBF8(char *self)
{
    float zero;
    if (CX34_U8(self, 0x14c) == 0) {
        cx34_v3((float *)(self + 0x2c), (float *)(self + 0x78));
        cx34_v3((float *)(self + 0x38), (float *)(self + 0x84));
        cx34_v3((float *)(self + 0x44), (float *)(self + 0x90));
        zero = lbl_8814B440;
        CX34_F32(self, 0xf0) = zero;
        CX34_F32(self, 0xf4) = zero;
        cx34_v3((float *)CX34_PTR(self, 0x6c), (float *)(self + 0x2c));
        cx34_v3((float *)CX34_PTR(self, 0x70), (float *)(self + 0x38));
        cx34_v3((float *)CX34_PTR(self, 0x74), (float *)(self + 0x44));
        CX34_U8(self, 0x69) = 0;
        CX34_U8(self, 0x68) = CX34_U8(self, 0x9c);
    }
    ts4_update_angles_888AD6F0(self);
}
