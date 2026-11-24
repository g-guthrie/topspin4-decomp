/* Swing_DLL.xex 0x88474078-0x884740C4, executable version 0.0.0.3. */
typedef struct Ts4IdList { unsigned *ids; unsigned short count; } Ts4IdList;
typedef struct Ts4Obj { char pad[0x1F0]; Ts4IdList list; } Ts4Obj;
static int ts4_find_id(Ts4IdList *l, unsigned id)
{
    int i;
    for (i = 0; i < l->count; i++) {
        if (l->ids[i] == id) { return i; }
    }
    return -1;
}
void ts4_clear_id_88474078(Ts4Obj *o, unsigned id)
{
    int idx = ts4_find_id(&o->list, id);
    o->list.ids[idx] = 0;
}
