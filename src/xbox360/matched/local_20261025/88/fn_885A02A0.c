typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void fn_885AB0D0(Ts4CriticalSection *section);

void fn_885A02A0(Ts4CriticalSection *section)
{
    fn_885AB0D0((Ts4CriticalSection *)((char *)section + 4));
}