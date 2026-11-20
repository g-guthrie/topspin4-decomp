/* Swing_DLL.xex 0x88611E38-0x88611F0C, executable version 0.0.0.3. */

typedef unsigned int u32;

typedef struct Ts4KindRegistry {
    unsigned char reserved[0x2AC];
    u32 *begin;
    u32 *end;
} Ts4KindRegistry;

extern Ts4KindRegistry *lbl_88D45B1C;

int ts4_registry_has_kind_88611E38(int kind)
{
    Ts4KindRegistry *registry = lbl_88D45B1C;
    u32 *end = registry->end;
    u32 *current;

    int result = 0;

    for (current = registry->begin; end != current; current++) {
        u32 id = *current;
        int found = 0;

        if (id == 0x99F5620Bu) {
            found = 0;
        } else if (id == 0x14588B45u) {
            found = 2;
        } else if (id == 0x93CAE023u) {
            found = 3;
        } else if (id == 0xBC7C2723u) {
            found = 4;
        } else if (id == 0xC9A1C481u) {
            found = 5;
        } else if (id == 0x3F34A24Du) {
            found = 1;
        }
        if (found == kind) {
            result = 1;
            break;
        }
    }
    return result;
}
