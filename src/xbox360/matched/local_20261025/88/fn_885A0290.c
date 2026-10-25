typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void fn_885AA820(Ts4CriticalSection *section);

void fn_885A0290(Ts4CriticalSection *section)
{
    fn_885AA820((Ts4CriticalSection *)((char *)section + 4));
}