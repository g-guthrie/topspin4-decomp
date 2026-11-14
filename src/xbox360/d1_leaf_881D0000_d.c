/* Swing_DLL.xex 0x881D41A8-0x881DDA94, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern int fn_881D4050(void *);
extern int fn_881D4788(void *);
extern int ts4_addr_fn_88206B20_881D58B8(void *);
extern int fn_881D6CA0(void *);
extern int fn_881DBA10(void *);
extern int fn_881DD5E0(void *);
extern int fn_881DDE58(void *);

int ts4_forward_if_set_else_zero_881D41A8(void *object)
{
    if (object != 0) {
        return fn_881D4050(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881D4760(void *object)
{
    if (object != 0) {
        return fn_881D4788(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881D5890(void *object)
{
    if (object != 0) {
        return ts4_addr_fn_88206B20_881D58B8(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881D6C78(void *object)
{
    if (object != 0) {
        return fn_881D6CA0(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881DBAE0(void *object)
{
    if (object != 0) {
        return fn_881DBA10(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881DD4F8(void *object)
{
    if (object != 0) {
        return fn_881DD5E0(object);
    }
    return 0;
}

int ts4_forward_if_set_else_zero_881DDA80(void *object)
{
    if (object != 0) {
        return fn_881DDE58(object);
    }
    return 0;
}
