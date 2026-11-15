/* 0x886D9AB8 (draft, 1 instruction off: the write-back is `stwx r8,r9,r30` in the target, index-first in ours): one level of the recursive table build: gathers the entries of the range,
 * processes and splits them into runs, then recurses into each produced sub-range at the next level. */
typedef struct Range { unsigned short first; unsigned short last; } Range;
typedef struct Level { int key; int pad; } Level;
typedef struct Obj { Level *levels; unsigned int level_count; char p[0x24 - 8]; Range *ranges; } Obj;
void ts4_gather_table_entries_886C4058(Obj *s, void *o, int a, int b, int c, void *d);
void fn_886D7DB8(Obj *s, int a, int b, void *d);
void ts4_build_runs_886C9808(Obj *s, Range *out, unsigned first, unsigned last, void *src);
void ts4_build_table_level_886D9AB8(Obj *s, void *o, Range *r, unsigned int level, void *src)
{
    int last = r->last;
    int first = r->first;
    ts4_gather_table_entries_886C4058(s, o, first, last, s->levels[level].key, src);
    fn_886D7DB8(s, first, last, src);
    ts4_build_runs_886C9808(s, r, first, last, src);
    if (level + 1 < s->level_count) {
        unsigned int e = r->last;
        unsigned int i = r->first;
        for (; i != e; i++) {
            Range sub = s->ranges[i];
            ts4_build_table_level_886D9AB8(s, o, &sub, level + 1, src);
            s->ranges[i] = sub;
        }
    }
}
