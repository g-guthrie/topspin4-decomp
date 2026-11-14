/* Swing_DLL.xex 0x881908B8-0x88197F8C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_881908F8(void *);
extern int fn_881928F8(void *);
extern int fn_88197958(void *);
extern int fn_88197F90(void *);

int ts4_forward_if_set_else_zero_881908B8(void *object)
{
    if (object != 0) {
        return fn_881908F8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881928E0(void *object)
{
    if (object != 0) {
        return fn_881928F8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_88197940(void *object)
{
    if (object != 0) {
        return fn_88197958(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_88197F78(void *object)
{
    if (object != 0) {
        return fn_88197F90(object);
    }
    return 0;
}
