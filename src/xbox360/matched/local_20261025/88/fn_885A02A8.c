typedef struct Ts4CriticalSection Ts4CriticalSection;
extern void fn_885AA928(Ts4CriticalSection *section);

void fn_885A02A8(Ts4CriticalSection *section)
{
    fn_885AA928((Ts4CriticalSection *)((char *)section + 4));
}