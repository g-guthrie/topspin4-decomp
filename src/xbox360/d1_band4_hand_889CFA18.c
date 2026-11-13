/* Swing_DLL.xex 0x889CFA18-0x889CFDB4, executable version 0.0.0.3. */

extern double fn_8882EA98(void *, int);
extern void fn_888240B8(void *, double);
extern double fn_88563A38(double, double);
extern double fn_88564D68(double, double);
extern double fn_88564BF8(double, double);
extern double fn_88569BD8(double, int *);

int ts4_binary_889CFBD8(void *x)
{
    double a = fn_8882EA98(x, 2);
    double b = fn_8882EA98(x, 1);
    fn_888240B8(x, fn_88563A38(b, a));
    return 1;
}

int ts4_binary_889CFC78(void *x)
{
    double a = fn_8882EA98(x, 2);
    double b = fn_8882EA98(x, 1);
    fn_888240B8(x, fn_88564D68(b, a));
    return 1;
}

int ts4_binary_889CFD58(void *x)
{
    double a = fn_8882EA98(x, 2);
    double b = fn_8882EA98(x, 1);
    fn_888240B8(x, fn_88564BF8(b, a));
    return 1;
}

int ts4_modf_889CFA18(void *x)
{
    int whole;
    double f = fn_88569BD8(fn_8882EA98(x, 1), &whole);
    fn_888240B8(x, f);
    fn_888240B8(x, (double)whole);
    return 2;
}
