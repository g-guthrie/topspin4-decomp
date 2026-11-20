/* Swing_DLL.xex 0x88331AF8: sets value for the (key, sub) binding in a 32-entry table at +0x24 (12-byte entries); a null value
 * frees the entry (key 0xFF); new keys take the first free entry. agAE: /Oc. */
typedef struct Binding { unsigned char key; unsigned char sub; char pad[2]; void *value; unsigned int extra; } Binding;
typedef struct Map { char pad[0x24]; Binding b[32]; } Map;
int fn_88331AF8(Map *m, unsigned char key, unsigned char sub, void *value)
{
    int i;
    for (i = 0; i < 32; i++) {
        if (m->b[i].key == key && m->b[i].sub == sub) {
            if (value) m->b[i].value = value;
            else m->b[i].key = 0xff;
            return 0;
        }
    }
    for (i = 0; i < 32; i++) {
        if (m->b[i].key == 0xff) {
            m->b[i].key = key;
            m->b[i].sub = sub;
            m->b[i].value = value;
            m->b[i].extra = 0;
            return 0;
        }
    }
    return 0;
}
