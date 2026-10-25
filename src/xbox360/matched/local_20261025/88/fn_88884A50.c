typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlEnterCriticalSection(Ts4CriticalSection *section);

void fn_88884A50(Ts4CriticalSection *section)
{
    RtlEnterCriticalSection((Ts4CriticalSection *)((char *)section + 4));
}