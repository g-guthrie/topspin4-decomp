/* 0x883DD7A0: decrements the counts of n ids (fn_883DC3C0 with -1) and, on success, forwards to ts4_fmod_soundbank_unload_entries_883DD5E8.
   LTCG only (agT): this kept in r7 across fn_883DC3C0; sibling caller 883DD558 in context stops the -1 being propagated. */
typedef struct T T;
int fn_883DC3C0(T *t, const int *ids, int n, int delta);
int ts4_fmod_soundbank_unload_entries_883DD5E8(T *t, const int *ids, int n);
int ts4_release_ids_then_update_883DD7A0(T *t, const int *ids, int n)
{
    int r = fn_883DC3C0(t, ids, n, -1);
    if (r)
        return r;
    return ts4_fmod_soundbank_unload_entries_883DD5E8(t, ids, n);
}
