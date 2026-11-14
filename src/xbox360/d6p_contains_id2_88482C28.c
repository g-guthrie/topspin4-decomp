/* Swing_DLL.xex 0x88482C28-0x88482C74, executable version 0.0.0.3. */
typedef struct Ts4Obj { char pad[0x150]; unsigned *ids; int count; } Ts4Obj;
void ts4_contains_id_88482C28(char *out, Ts4Obj *o, unsigned id)
{
    int i;
    for (i = 0; i < o->count; i++) {
        if (o->ids[i] == id) {
            *out = 1;
            return;
        }
    }
    *out = 0;
}
