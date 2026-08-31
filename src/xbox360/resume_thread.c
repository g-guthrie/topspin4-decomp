typedef unsigned int u32;
typedef int s32;

extern s32 NtResumeThread(void *thread, u32 *previous_count);
extern void ts4_record_status(s32 status);

/* Swing_DLL.xex 0x8857C888. */
s32 ts4_resume_thread(void *thread)
{
    u32 previous_count;
    s32 status = NtResumeThread(thread, &previous_count);

    if (status < 0) {
        ts4_record_status(status);
        previous_count = (u32)-1;
    }
    return (s32)previous_count;
}
