/* Loader_DLL.xex 0x8315F298-0x8315F2FC, executable version 0.0.0.3. */

typedef struct ts4l_id_value {
    unsigned id;
    float value;
} ts4l_id_value;

/* Compare two id/value arrays element by element; 1 when identical. */
int ts4l_id_value_arrays_equal_8315F298(int n, ts4l_id_value *a, int n2, ts4l_id_value *b)
{
    int i;
    if (n != n2) return 0;
    for (i = 0; i < n; i++) {
        if (a[i].id != b[i].id) return 0;
        if (a[i].value != b[i].value) return 0;
    }
    return 1;
}
