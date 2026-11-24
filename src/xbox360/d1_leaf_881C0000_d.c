/* Swing_DLL.xex 0x881CCAA0-0x881CE8F4, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_881CCD90(void *);
extern int fn_881CEB10(void *);

int ts4_forward_if_set_else_zero_881CCAA0(void *object)
{
    if (object != 0) {
        return fn_881CCD90(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881CE8E0(void *object)
{
    if (object != 0) {
        return fn_881CEB10(object);
    }
    return 0;
}
