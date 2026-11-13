/* Swing_DLL.xex 0x881F0B08-0x881FD224, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_881F1060(void *);
extern int fn_881F4108(void *);
extern int fn_881F7958(void *);
extern int fn_881FC068(void *);
extern int fn_881FD7D8(void *);

int ts4_forward_if_set_else_zero_881F0B08(void *object)
{
    if (object != 0) {
        return fn_881F1060(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881F27B8(void *object)
{
    if (object != 0) {
        return fn_881F4108(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881F7940(void *object)
{
    if (object != 0) {
        return fn_881F7958(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881FBF60(void *object)
{
    if (object != 0) {
        return fn_881FC068(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881FD210(void *object)
{
    if (object != 0) {
        return fn_881FD7D8(object);
    }
    return 0;
}
