/* 0x88335320: Returns 0x25 when both out pointers are null; zeroes the given outs, then forwards to ts4_count_list_flagged_88376A78(impl->list, a, b) when impl (+0x44) and its list (+0x104) exist; else 0. */
/* Matched on /Oc (agAH). Straight-line C; impl read into a local. */
typedef struct Impl { char pad[0x104]; void *list; } Impl;
typedef struct Dev { char pad[0x44]; Impl *impl; } Dev;
int ts4_count_list_flagged_88376A78(void *list, unsigned int *total, unsigned int *flagged);
int fn_88335320(Dev *d, unsigned int *total, unsigned int *flagged)
{
    Impl *impl;
    if (total == 0 && flagged == 0)
        return 0x25;
    if (total != 0)
        *total = 0;
    if (flagged != 0)
        *flagged = 0;
    impl = d->impl;
    if (impl != 0 && impl->list != 0)
        return ts4_count_list_flagged_88376A78(impl->list, total, flagged);
    return 0;
}
