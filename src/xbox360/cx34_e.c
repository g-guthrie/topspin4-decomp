/* CW34 part e: functions with a constant divide (built with /Oc), 0x888C0000-0x888D8000. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_I32(p, o) (*(int *)((char *)(p) + (o)))
#define CX34_PTR(p, o) (*(char **)((char *)(p) + (o)))

extern char *lbl_88D45B0C;
extern u32 ts4_get_u32__imp_KeTimeStampBundle_8857B830(void);
extern void ts4_data_add_half_saturating_88656848(char *obj, int id, u32 amount, u32 flag);

/* 0x888C3A40: credit the minutes elapsed since the last stamp to the current stat, then restamp */
void ts4_credit_elapsed_minutes_888C3A40(char *self)
{
    if (lbl_88D45B0C != 0) {
        if (CX34_I32(self, 0x1c) != 0x37) {
            u32 now = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
            u32 d = (now - CX34_U32(self, 0x20)) / 60000u;
            ts4_data_add_half_saturating_88656848(lbl_88D45B0C, CX34_I32(self, 0x1c), (u16)d, 0);
        }
        CX34_U32(self, 0x20) = ts4_get_u32__imp_KeTimeStampBundle_8857B830();
    }
}
