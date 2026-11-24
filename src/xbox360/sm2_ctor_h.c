/* SM2: small constructors / initializers that store a vtable pointer and default fields. */
extern char lbl_880F4340[];
extern char lbl_880C0FEC[];
extern char lbl_880898DC[];
extern char lbl_88089D90[];
extern char lbl_88084C94[];
extern char lbl_880D75FC[];
extern const float lbl_88001A68;
extern const float lbl_88001A20;
extern const float g_ts4_script_constants[];

#define W(o) (*(volatile unsigned *)(p + (o)))
#define WV(o) (*(volatile unsigned *)(p + (o)))
#define F(o) (*(float *)(p + (o)))
#define H(o) (*(unsigned short *)(p + (o)))
#define B(o) (*(unsigned char *)(p + (o)))

void ts4_init_object_vt_880F4340_8867B968(char *p)
{
    *(void *volatile *)p = lbl_880F4340;
    W(4) = 0; W(8) = 0; W(0xc) = 0; W(0x10) = 0; W(0x14) = 0;
    W(0x1c) = 0; W(0x20) = 0; W(0x24) = 0; W(0x28) = 0; W(0x2c) = 0;
    W(0x34) = 0;
}
