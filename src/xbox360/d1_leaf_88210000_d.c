/* Swing_DLL.xex 0x88213270-0x882138B4, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_887816A0(void *);
extern int fn_887B53E8(void *);
extern int ts4_call_seq_fn_881F1060_887B5CF8(void *);
extern int fn_887B5E20(void *);
extern int fn_887B6808(void *);
extern int fn_887C4558(void *);

int ts4_forward_if_set_else_zero_88213270(void *object)
{
    if (object != 0) {
        return fn_887816A0(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_882132E8(void *object)
{
    if (object != 0) {
        return fn_887B5E20(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_882133D0(void *object)
{
    if (object != 0) {
        return fn_887B6808(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_882134A0(void *object)
{
    if (object != 0) {
        return ts4_call_seq_fn_881F1060_887B5CF8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_88213570(void *object)
{
    if (object != 0) {
        return fn_887B53E8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_882138A0(void *object)
{
    if (object != 0) {
        return fn_887C4558(object);
    }
    return 0;
}
