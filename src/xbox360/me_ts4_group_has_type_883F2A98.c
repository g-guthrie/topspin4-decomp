/* 0x883F2A98: sets *found when any item of owner->f18's list (+0x40) has a desc type (+0x1C) equal to lbl_88039D00 (fn_883297E8); 0x25 for a null found; self unused */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Desc { char pad[0x1c]; const char *type; } Desc;
typedef struct Item { int f0; Link link; char pad[0xc]; Desc *desc; } Item;
typedef struct Group { char pad[0x40]; Link head; } Group;
typedef struct Owner { char pad[0x18]; Group *group; } Owner;
extern const char lbl_88039D00[];
int fn_883297E8(const char *a, const char *b);
int ts4_group_has_type_883F2A98(void *self, Owner *o, unsigned char *found)
{
    Link *n;
    (void)self;
    if (!found)
        return 0x25;
    *found = 0;
    for (n = o->group->head.next; n != &o->group->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        if (it->desc->type && fn_883297E8(it->desc->type, lbl_88039D00) == 0) {
            *found = 1;
            break;
        }
    }
    return 0;
}
