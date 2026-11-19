/* 0x883D08A8: Finds name in the table (fn_88329868 == 0), resolves its handle with ts4_if_call_seq_fn_88309DB8_88308E18(store, 2, index) and returns ts4_if_call_seq_fn_88309DB8_88308EB8(store, handle, arg). Returns 0x10 if the name is not found. */
/* Matched on /O1 (agAH). A live alias local (self = t) renumbers the base for the lwzx (index, base) order; OP1 rule. */
typedef struct Table { char p0[0x14]; void *store; char p18[0x14]; const char **names; int count; } Table;
extern int fn_88329868(const char *a, const char *b);
extern int ts4_if_call_seq_fn_88309DB8_88308E18(void *store, int kind, int index, int *handle);
extern int ts4_if_call_seq_fn_88309DB8_88308EB8(void *store, int handle, void *arg);
int fn_883D08A8(Table *t, const char *name, void *arg)
{
    Table *self = t;
    int i;
    for (i = 0; i < self->count; i++) {
        if (fn_88329868(self->names[i], name) == 0) {
            int handle;
            ts4_if_call_seq_fn_88309DB8_88308E18(self->store, 2, i, &handle);
            return ts4_if_call_seq_fn_88309DB8_88308EB8(self->store, handle, arg);
        }
    }
    return 0x10;
}
