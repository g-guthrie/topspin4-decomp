typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void fn_885AB8D0(Ts4CriticalSection *section);

void fn_88599FA0(Ts4CriticalSection *section)
{
    fn_885AB8D0((Ts4CriticalSection *)((char *)section + 4));
}