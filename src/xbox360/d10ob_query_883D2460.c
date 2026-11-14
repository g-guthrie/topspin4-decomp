/* Swing_DLL.xex 0x883D2460-0x883D24F0, executable version 0.0.0.3. */
typedef struct Ob { void **vt; } Ob;
extern char lbl_88039148[];
int fn_88329868(void *a, void *b);

int ts4_query_883D2460(char *o, void *name, void **out)
{
    Ob **slot = (Ob **)(o + 0x809c);
    if (*slot == 0)
        return 0x1f;
    if (name == 0 || out == 0)
        return 0x25;
    if (fn_88329868(name, lbl_88039148) == 0) {
        *out = *slot;
        return 0;
    }
    return ((int (*)(void *, void *, void *))(*slot)->vt[1])(*slot, name, out);
}
