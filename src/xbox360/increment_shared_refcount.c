typedef struct Ts4CriticalSection Ts4CriticalSection;

extern void RtlEnterCriticalSection(Ts4CriticalSection *section);
extern void RtlLeaveCriticalSection(Ts4CriticalSection *section);

/* Swing_DLL.xex 0x8857D528. */
void ts4_increment_shared_refcount(
    Ts4CriticalSection *section,
    unsigned char *value
)
{
    if (value != 0) {
        RtlEnterCriticalSection(section);
        *(unsigned short *)(value - 2) = *(unsigned int *)(value - 4) + 1;
        RtlLeaveCriticalSection(section);
    }
}
