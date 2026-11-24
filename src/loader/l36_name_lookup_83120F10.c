/* Loader_DLL.xex 0x83120F10-0x83120FA4, executable version 0.0.0.3. */
typedef unsigned int u32;
struct NameEnt { const void *name; int value; u32 pad8; u32 padc; };
struct NameTab { char pad[0x24]; struct NameEnt *ents; int count; };
struct NameOwner { char pad[0xe4]; struct NameTab *tab; };
extern int fn_833E4108(const void *a, const void *b);

long ts4l_name_lookup_83120F10(struct NameOwner *o, const void *name, int *out)
{
    struct NameTab *t;
    int i;
    *out = -1;
    t = o->tab;
    if (t != 0) {
        for (i = 0; i < t->count; i++) {
            if (fn_833E4108(name, t->ents[i].name) == 0) {
                *out = o->tab->ents[i].value;
                break;
            }
            t = o->tab;
        }
    }
    return 0;
}
