typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlLeaveCriticalSection(Ts4CriticalSection *section);

void fn_88593DE8(Ts4CriticalSection *section)
{
    RtlLeaveCriticalSection((Ts4CriticalSection *)((char *)section + 4));
}