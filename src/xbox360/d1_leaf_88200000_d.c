/* Swing_DLL.xex 0x88204A38-0x8820FBAC, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_88204E00(void *);
extern int ts4_addr_fn_881F7958_88206B20(void *);
extern int fn_882072F0(void *);
extern int ts4_if_addr_fn_881F7958_8820B418(void *);
extern int fn_8820CFB8(void *);
extern int fn_8820F740(void *);
extern int fn_8820FD80(void *);

int ts4_forward_if_set_else_zero_88204A38(void *object)
{
    if (object != 0) {
        return fn_88204E00(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_88206AF8(void *object)
{
    if (object != 0) {
        return ts4_addr_fn_881F7958_88206B20(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_882072C8(void *object)
{
    if (object != 0) {
        return fn_882072F0(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_8820B3F0(void *object)
{
    if (object != 0) {
        return ts4_if_addr_fn_881F7958_8820B418(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_8820C690(void *object)
{
    if (object != 0) {
        return fn_8820CFB8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_8820F558(void *object)
{
    if (object != 0) {
        return fn_8820F740(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_8820FB98(void *object)
{
    if (object != 0) {
        return fn_8820FD80(object);
    }
    return 0;
}
