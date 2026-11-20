/* Swing_DLL.xex 0x883D36D0-0x883D3734, executable version 0.0.0.3. */
unsigned int fn_88565F50(void *buf, unsigned int sz, unsigned int n, void *f);
typedef struct Ts4Ob2Rd { char pad0[0x34]; void *f34; } Ts4Ob2Rd;

int ts4_read_883D36D0(Ts4Ob2Rd *o, void *buf, unsigned int n)
{
    if (o->f34 == 0)
        return 0x13;
    return fn_88565F50(buf, 1, n, o->f34) != n ? 0x13 : 0;
}
