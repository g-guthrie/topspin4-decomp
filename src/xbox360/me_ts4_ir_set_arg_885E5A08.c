/* 0x885E5A08: xgraphics IR instruction: asserts arg < 6 (irinst.cpp line 251), then records the argument, its type (+0xC) and value (+0x20) in the three per-argument arrays */
/* Matched on /O1 (agAH). /O1; assert strings are the lbl_880B4540 format, the expression and the file name. */
typedef unsigned int u32;
extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern char lbl_880B4540[], lbl_880BD1D4[], lbl_880BD0D8[];
typedef struct Arg { char p[0xc]; void *type; char p2[0x10]; void *value; } Arg;
typedef struct Inst { char p[0x1c]; Arg *args[7]; void *types[6]; void *values[6]; } Inst;
void fn_885E5A08(Inst *in, int arg, Arg *a)
{
    if (arg >= 5 + 1)
        fn_885DC838(0, lbl_880B4540, lbl_880BD1D4, lbl_880BD0D8, 0xfb);
    in->values[arg] = a->value;
    in->types[arg] = a->type;
    in->args[arg] = a;
}
