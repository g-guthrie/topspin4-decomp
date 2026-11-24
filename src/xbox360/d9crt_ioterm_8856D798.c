/* Swing_DLL.xex 0x8856D798-0x8856D81C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _ioterm. */
typedef struct IoInfo {
    char data[0x48];
} IoInfo;
extern IoInfo *lbl_88D4E000[64];
extern void fn_885651F8(void *p);

void ts4_crt_ioterm_8856D798(void)
{
    IoInfo **pp;
    IoInfo *pio;
    for (pp = lbl_88D4E000; (long)pp < (long)(lbl_88D4E000 + 64); pp++) {
        if (*pp != 0) {
            for (pio = *pp; pio < *pp + 32; pio++)
                ;
            fn_885651F8(*pp);
            *pp = 0;
        }
    }
}
