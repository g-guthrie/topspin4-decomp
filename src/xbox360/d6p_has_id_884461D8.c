/* Swing_DLL.xex 0x884461D8-0x88446224, executable version 0.0.0.3. */
typedef struct Ts4IdVec { unsigned *ids; int count; } Ts4IdVec;
typedef struct Ts4Holder { char pad[0x10]; Ts4IdVec *vec; } Ts4Holder;
static int ts4_find_idx(Ts4IdVec *v, unsigned id)
{
    int i;
    for (i = 0; i < v->count; i++) {
        if (v->ids[i] == id) {
            return i;
        }
    }
    return -1;
}
void ts4_has_id_884461D8(char *out, Ts4Holder *h, unsigned id)
{
    *out = (char)(ts4_find_idx(h->vec, id) >= 0);
}
