typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlInitializeCriticalSection(Ts4CriticalSection *section);

void fn_88884518(Ts4CriticalSection *section)
{
    RtlInitializeCriticalSection((Ts4CriticalSection *)((char *)section + 4));
}