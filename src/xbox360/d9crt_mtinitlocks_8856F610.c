/* Swing_DLL.xex 0x8856F610-0x8856F690, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _mtinitlocks. */
typedef struct LockEntry {
    void *lock;
    int kind;
} LockEntry;
typedef struct CritSec {
    char data[0x1c];
} CritSec;
extern LockEntry lbl_88C31510[36];
extern CritSec lbl_88D2E5B0[];
extern int fn_8856F578(CritSec *cs, int spin);

int ts4_crt_mtinitlocks_8856F610(void)
{
    int locknum = 0;
    LockEntry *e = lbl_88C31510;
    CritSec *pcs = lbl_88D2E5B0;
    for (; (long)e < (long)(lbl_88C31510 + 36); e++, locknum++) {
        if (e->kind == 1) {
            e->lock = pcs++;
            if (!fn_8856F578((CritSec *)e->lock, 4000)) {
                lbl_88C31510[locknum].lock = 0;
                return 0;
            }
        }
    }
    return 1;
}
