typedef struct Ts4CriticalSection Ts4CriticalSection;

extern void RtlEnterCriticalSection(Ts4CriticalSection *section);
extern void RtlLeaveCriticalSection(Ts4CriticalSection *section);

/* Swing_DLL.xex 0x8857D580. */
void ts4_decrement_shared_refcount(
    Ts4CriticalSection *section,
    unsigned char *value
)
{
    if (value != 0) {
        unsigned int count;

        RtlEnterCriticalSection(section);
        count = *(unsigned int *)(value - 4);
        count--;
        *(unsigned short *)(value - 2) = count;
        RtlLeaveCriticalSection(section);
    }
}
