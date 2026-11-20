/* Swing_DLL.xex 0x885A4C28-0x885A4E40, executable version 0.0.0.3. */
typedef void (*ts4_kernel_fn)(void);

extern void fn_885A0550(void);
extern void fn_885A1880(void);
extern void fn_885A0658(void);
extern void fn_885A1C68(void);
extern void fn_885A0830(void);
extern void fn_885A0B18(void);
extern void fn_885A0D58(void);
extern void fn_885A1320(void);
extern void fn_885A2060(void);
extern void fn_885A0398(void);
extern void fn_885A2658(void);
extern void fn_885A3F38(void);
extern void fn_885A2798(void);
extern void fn_885A29C8(void);
extern void fn_885A2D68(void);
extern void fn_885A3100(void);
extern void fn_885A3838(void);
extern void fn_885A4350(void);
extern void fn_885A2440(void);
extern void fn_885A47D0(void);

#define TAIL(X, Y, Z) \
    if (flags & 2) { \
        if ((flags & 1) || (b <= 4 && b != 3 && (flags & 4))) r = Y; \
        else if (b <= 6) r = X; \
        else r = Z; \
    } else { \
        r = Z; \
    }

ts4_kernel_fn ts4_select_kernel_885A4C28(unsigned a, unsigned b, unsigned c, int flags)
{
    ts4_kernel_fn r = 0;
    switch (a) {
    case 7:
        if (b == 1 && c == 2) r = fn_885A0550;
        else if (b == 1 && c == 6) r = (flags & 4) ? fn_885A1880 : fn_885A0658;
        else if (b == 2 && c == 6) r = (flags & 4) ? fn_885A1C68 : fn_885A0830;
        else if (b == 6 && c == 2) r = fn_885A0B18;
        else if (b == 4 && c == 6) r = fn_885A0D58;
        else { TAIL(fn_885A1320, fn_885A2060, fn_885A0398) }
        break;
    case 1:
        if (b == 1 && c == 2) r = fn_885A2658;
        else if (b == 1 && c == 6) r = (flags & 4) ? fn_885A3F38 : fn_885A2798;
        else if (b == 2 && c == 6) r = fn_885A29C8;
        else if (b == 6 && c == 2) r = fn_885A2D68;
        else if (b == 4 && c == 6) r = fn_885A3100;
        else { TAIL(fn_885A3838, fn_885A4350, fn_885A2440) }
        break;
    case 0: case 2: case 3: case 4: case 5: case 6:
        r = fn_885A47D0;
        break;
    }
    return r;
}
