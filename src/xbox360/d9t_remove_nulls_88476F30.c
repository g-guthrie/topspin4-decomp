/* Swing_DLL.xex 0x88476F30-0x8848CB98, executable version 0.0.0.3. */
typedef struct Ts4PtrVec { unsigned *items; int count; } Ts4PtrVec;
void ts4_remove_nulls_88476F30(Ts4PtrVec *v)
{
    int i;
    for (i = v->count - 1; i >= 0; i--) {
        if (v->items[i] == 0) {
            int j;
            v->count--;
            for (j = i; j < v->count; j++) {
                v->items[j] = v->items[j + 1];
            }
        }
    }
}
void ts4_remove_nulls_88476FA0(Ts4PtrVec *v)
{
    int i;
    for (i = v->count - 1; i >= 0; i--) {
        if (v->items[i] == 0) {
            int j;
            v->count--;
            for (j = i; j < v->count; j++) {
                v->items[j] = v->items[j + 1];
            }
        }
    }
}
void ts4_remove_nulls_8848CB28(Ts4PtrVec *v)
{
    int i;
    for (i = v->count - 1; i >= 0; i--) {
        if (v->items[i] == 0) {
            int j;
            v->count--;
            for (j = i; j < v->count; j++) {
                v->items[j] = v->items[j + 1];
            }
        }
    }
}
