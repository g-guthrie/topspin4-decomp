/* 0x882A6528: under the VdHSIOCalibrationLock critical section, runs VdRetrainEDRAM (worker first when async), and while it asks for more space flushes (fn_88292A78) and feeds it 0x1000-word chunks reserved in the command buffer; returns 1 */
/* Matched on /O1 plain only (agT, v.py chk). */
typedef struct Buf { char pad[0x30]; unsigned int *cur; } Buf;
extern void *__imp_VdHSIOCalibrationLock;
void KeEnterCriticalRegion(void);
void KeLeaveCriticalRegion(void);
void RtlEnterCriticalSection(void *cs);
void RtlLeaveCriticalSection(void *cs);
void VdRetrainEDRAMWorker(int a);
int VdRetrainEDRAM(void *ctx, unsigned int **ptr, unsigned int size, unsigned int *used, char *scratch, unsigned int scratch_size);
unsigned int *ts4_buf_reserve_words_882911D0(Buf *b, unsigned int words);
void fn_88292A78(Buf *b);
int ts4_retrain_edram_882A6528(Buf *b, void *ctx, int async)
{
    unsigned int *ptr;
    unsigned int used;
    char scratch[0x800];
    int r;
    KeEnterCriticalRegion();
    RtlEnterCriticalSection(__imp_VdHSIOCalibrationLock);
    if (async)
        VdRetrainEDRAMWorker(0);
    used = 0;
    ptr = 0;
    r = VdRetrainEDRAM(ctx, &ptr, 0x1000, &used, scratch, 0x800);
    if (r) {
        if (!async)
            fn_88292A78(b);
        do {
            ptr = ts4_buf_reserve_words_882911D0(b, 0x1000) + 1;
            r = VdRetrainEDRAM(ctx, &ptr, 0x1000, &used, scratch, 0x800);
            ptr--;
            b->cur = ptr;
            fn_88292A78(b);
        } while (r);
    }
    RtlLeaveCriticalSection(__imp_VdHSIOCalibrationLock);
    KeLeaveCriticalRegion();
    return 1;
}
