typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlLeaveCriticalSection(Ts4CriticalSection *section);

void fn_889328E8(Ts4CriticalSection *section)
{
    RtlLeaveCriticalSection((Ts4CriticalSection *)((char *)section + 0x54));
}