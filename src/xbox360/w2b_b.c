#include "w2b_types.h"
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

extern const char lbl_880F35BC[];

struct W2bNameList { w2b_u32 pad[3]; const char ***names; w2b_u32 count; };
struct W2bNameHolder { struct W2bNameList *list; };
struct W2bNameOwner { char pad[0x24]; struct W2bNameHolder *holder; };

/* Swing_DLL.xex 0x88645200 */
int ts4_find_name_index_88645200(struct W2bNameOwner *self)
{
    struct W2bNameList *l = self->holder->list;
    unsigned i;
    int r = -1;
    for (i = 0; i < l->count; i++) {
        if (strcmp(*l->names[i], lbl_880F35BC) == 0) {
            r = i;
            break;
        }
    }
    return r;
}
