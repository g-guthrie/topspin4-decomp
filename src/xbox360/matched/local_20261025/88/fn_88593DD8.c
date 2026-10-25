typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlEnterCriticalSection(Ts4CriticalSection *section);

void fn_88593DD8(Ts4CriticalSection *section)
{
    RtlEnterCriticalSection((Ts4CriticalSection *)((char *)section + 4));
}