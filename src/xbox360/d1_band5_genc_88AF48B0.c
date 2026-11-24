/* Swing_DLL.xex 0x88AF48B0-0x88AFAC70, executable version 0.0.0.3. */

extern void fn_8843AE88(void *buffer);
extern void fn_884430E8(void *buffer, int flag);
extern void fn_884748C0(void *buffer, int flag);
extern void ts4_hk_finish_loaded_object_88437200(void);
extern void ts4_if_call_seq_fn_884430E8_88437B28(void);
extern void ts4_hk_finish_loaded_object_88437C50(void);
extern void ts4_hk_finish_loaded_object_88438190(void);
extern void ts4_if_call_seq_fn_884748C0_88469918(void);
extern void ts4_hk_finish_loaded_object_884A1230(void);
extern void ts4_hk_finish_loaded_object_884A13F0(void);
extern void ts4_hk_finish_loaded_object_884A1578(void);
extern void ts4_hk_finish_loaded_object_884A1830(void);
extern char lbl_88044D70[];
extern char lbl_88044DE0[];
extern char lbl_88044E10[];
extern char lbl_88044E74[];
extern char lbl_880455D0[];
extern char lbl_88046704[];
extern char lbl_880467B8[];
extern char lbl_880467C8[];
extern char lbl_880468F4[];
extern char lbl_880800E8[];
extern char lbl_880807C8[];
extern char lbl_88080874[];
extern char lbl_88080C2C[];
extern char lbl_88084948[];
extern char lbl_88087AD4[];
extern char lbl_88087BDC[];
extern char lbl_88087C60[];
extern char lbl_88087E8C[];
extern void ts4_vcall0_thunk_884371E8(void);
extern void ts4_vcall0_thunk_88437B10(void);
extern void ts4_vcall0_thunk_88437C38(void);
extern void ts4_vcall0_thunk_88438178(void);
extern void ts4_vcall0_thunk_88469900(void);
extern void ts4_vcall0_thunk_884A1218(void);
extern void ts4_vcall0_thunk_884A13D8(void);
extern void ts4_vcall0_thunk_884A1560(void);
extern void ts4_vcall0_thunk_884A1818(void);
extern int lbl_88D232B4;
extern int lbl_88D23584;
extern int lbl_88D235C4;
extern int lbl_88D237D4;
extern int lbl_88D24BB0;
extern int lbl_88D25A64;
extern int lbl_88D25AD4;
extern int lbl_88D25B14;
extern int lbl_88D25BC4;

void ts4_init_static_88AF48B0(void)
{
    char local[64];
    int *base = &lbl_88D232B4;
    fn_8843AE88(local);
    lbl_88D232B4 = (int)(long)lbl_880468F4;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_88437200;
    base[2] = (int)(long)ts4_vcall0_thunk_884371E8;
    base[3] = (int)(long)lbl_880800E8;
}

void ts4_init_static_88AF5098(void)
{
    char local[96];
    int *base = &lbl_88D23584;
    fn_884430E8(local, 0);
    lbl_88D23584 = (int)(long)lbl_880467C8;
    base[1] = (int)(long)ts4_if_call_seq_fn_884430E8_88437B28;
    base[2] = (int)(long)ts4_vcall0_thunk_88437B10;
    base[3] = (int)(long)lbl_880807C8;
}

void ts4_init_static_88AF5160(void)
{
    char local[256];
    int *base = &lbl_88D235C4;
    fn_8843AE88(local);
    lbl_88D235C4 = (int)(long)lbl_880467B8;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_88437C50;
    base[2] = (int)(long)ts4_vcall0_thunk_88437C38;
    base[3] = (int)(long)lbl_88080874;
}

void ts4_init_static_88AF5758(void)
{
    char local[48];
    int *base = &lbl_88D237D4;
    fn_8843AE88(local);
    lbl_88D237D4 = (int)(long)lbl_88046704;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_88438190;
    base[2] = (int)(long)ts4_vcall0_thunk_88438178;
    base[3] = (int)(long)lbl_88080C2C;
}

void ts4_init_static_88AF8318(void)
{
    char local[512];
    int *base = &lbl_88D24BB0;
    fn_884748C0(local, 0);
    lbl_88D24BB0 = (int)(long)lbl_880455D0;
    base[1] = (int)(long)ts4_if_call_seq_fn_884748C0_88469918;
    base[2] = (int)(long)ts4_vcall0_thunk_88469900;
    base[3] = (int)(long)lbl_88084948;
}

void ts4_init_static_88AFA7A8(void)
{
    char local[64];
    int *base = &lbl_88D25A64;
    fn_8843AE88(local);
    lbl_88D25A64 = (int)(long)lbl_88044E74;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_884A1230;
    base[2] = (int)(long)ts4_vcall0_thunk_884A1218;
    base[3] = (int)(long)lbl_88087AD4;
}

void ts4_init_static_88AFA8F8(void)
{
    char local[64];
    int *base = &lbl_88D25AD4;
    fn_8843AE88(local);
    lbl_88D25AD4 = (int)(long)lbl_88044E10;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_884A13F0;
    base[2] = (int)(long)ts4_vcall0_thunk_884A13D8;
    base[3] = (int)(long)lbl_88087BDC;
}

void ts4_init_static_88AFA9D0(void)
{
    char local[192];
    int *base = &lbl_88D25B14;
    fn_8843AE88(local);
    lbl_88D25B14 = (int)(long)lbl_88044DE0;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_884A1578;
    base[2] = (int)(long)ts4_vcall0_thunk_884A1560;
    base[3] = (int)(long)lbl_88087C60;
}

void ts4_init_static_88AFAC70(void)
{
    char local[64];
    int *base = &lbl_88D25BC4;
    fn_8843AE88(local);
    lbl_88D25BC4 = (int)(long)lbl_88044D70;
    base[1] = (int)(long)ts4_hk_finish_loaded_object_884A1830;
    base[2] = (int)(long)ts4_vcall0_thunk_884A1818;
    base[3] = (int)(long)lbl_88087E8C;
}
