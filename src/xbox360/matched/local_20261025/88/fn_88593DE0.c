typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void RtlTryEnterCriticalSection(Ts4CriticalSection *section);

void fn_88593DE0(Ts4CriticalSection *section)
{
    RtlTryEnterCriticalSection((Ts4CriticalSection *)((char *)section + 4));
}