/* CW34 part b (LTCG): camera-key derived constructors that keep r5 across the base constructor call. */
typedef unsigned int u32;
typedef unsigned char u8;
#define CX34_U32(p, o) (*(u32 *)((char *)(p) + (o)))
#define CX34_F32(p, o) (*(float *)((char *)(p) + (o)))
#define CX34_U8(p, o) (*(u8 *)((char *)(p) + (o)))
extern float g_ts4_event_value;
extern float g_ts4_script_constants[];
extern char *fn_888AF5C0(char *self);
extern char lbl_880DC930[];
extern char lbl_880DC8A0[];
extern char lbl_880DC810[];
extern char lbl_880DC780[];

/* 0x888B0A70 */
char *ts4_init_key_obj_90_888B0A70(char *self)
{
    fn_888AF5C0(self);
    CX34_U32(self, 0x90) = 0;
    CX34_U32(self, 0) = (u32)(unsigned long)lbl_880DC930;
    return self;
}

/* 0x888B0AB0 */
char *ts4_init_key_obj_84_888B0AB0(char *self)
{
    fn_888AF5C0(self);
    CX34_U32(self, 0x84) = 0;
    CX34_U32(self, 0) = (u32)(unsigned long)lbl_880DC8A0;
    CX34_U32(self, 0x8c) = 0;
    CX34_U32(self, 0x88) = 0;
    CX34_U32(self, 0x90) = 0;
    return self;
}
