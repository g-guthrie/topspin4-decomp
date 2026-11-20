/* Swing_DLL.xex 0x8818AB30-0x8818AB44, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_8818AB48(void *);

int ts4_forward_if_set_else_zero_8818AB30(void *object)
{
    if (object != 0) {
        return fn_8818AB48(object);
    }
    return 0;
}
