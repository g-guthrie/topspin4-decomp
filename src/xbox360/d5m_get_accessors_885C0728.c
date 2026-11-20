/* Swing_DLL.xex 0x885C0728-0x885C07D8, executable version 0.0.0.3. */
typedef void (*ts4_fn)(void);
extern void ts4_set_885BFDE8(void);
extern void ts4_get_885BFD40(void);
extern void ts4_get_885BFD50(void);
extern void ts4_get_u8_off2_885BFD68(void);
extern void fn_885BFE48(void);
extern void fn_885BFE90(void);
extern void fn_885BFE20(void);
extern void fn_885BFD90(void);
extern void fn_885BFAF0(void);
extern void ts4_store_u24_be_885BFDF8(void);

void ts4_get_accessors_885C0728(ts4_fn *getter, ts4_fn *setter, int id)
{
    switch (id) {
    case 0x3d:
        *setter = ts4_set_885BFDE8;
        *getter = ts4_get_885BFD40;
        break;
    case 0:
        *setter = fn_885BFE48;
        *getter = fn_885BFE90;
        break;
    case 0x4e:
        *setter = fn_885BFE20;
        *getter = ts4_get_u8_off2_885BFD68;
        break;
    case 0x5e:
        *setter = ts4_store_u24_be_885BFDF8;
        *getter = ts4_get_885BFD50;
        break;
    default:
        *setter = fn_885BFD90;
        *getter = fn_885BFAF0;
        break;
    }
}
