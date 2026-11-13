/* Swing_DLL.xex 0x88418520-0x8841FF9C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_8841AAC8(void *, int);
extern void fn_8841ABD8(void *, int);
extern void fn_8841ED08(void *);
extern void fn_8841FDB8(void *);
extern void fn_884235C0(void *);
extern void fn_885690C8(void *);
extern void fn_885690E0(void *);
extern char lbl_8803A308[];
extern char lbl_8803A310[];
extern char lbl_8803C474[];
extern char lbl_8803DA3C[];

char *ts4_global_address_8841AA68(void)
{
    return lbl_8803A310;
}

void ts4_forward_with_0_8841AAC0(void *object)
{
    fn_8841AAC8(object, 0);
}

void ts4_forward_with_0_8841ABD0(void *object)
{
    fn_8841ABD8(object, 0);
}

void ts4_set_table_0_8841B478(char *object)
{
    *(char **)(object) = lbl_8803DA3C;
}

void ts4_forward_8841B488(void *object)
{
    fn_885690E0(object);
}

void ts4_forward_8841B490(void *object)
{
    fn_885690C8(object);
}

void ts4_forward_adjusted_8_8841C118(char *object)
{
    fn_884235C0(object + 0x8);
}

void ts4_field_8_vcall_10_8841D460(char *object)
{
    typedef void (*method)(void *object);
    void *target = *(void **)(object + 0x8);
    (*(method **)target)[4](target);
}
