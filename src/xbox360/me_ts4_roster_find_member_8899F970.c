/* Swing_DLL.xex 0x8899F970: find a member by id in the local team, then in every team of the roster
 * second search writes found and leaves both loops with goto (the target sets r3 = 0 before the team loop) */
typedef struct Member { char pad[0x80]; int id; } Member;
typedef struct Team { int pad0; Member **first; Member **last; } Team;
typedef struct Roster {
    char pad[0x14];
    Team *local;     /* +0x14 */
    Team **first;    /* +0x18 */
    Team **last;     /* +0x1C */
} Roster;

Member *fn_8899F970(Roster *r, int id)
{
    Team *t = r->local;
    Member **end = t->last;
    Member **it;
    Team **tend;
    Team **ti;
    Member *found;
    for (it = t->first; it != end; it++) {
        if ((*it)->id == id)
            return *it;
    }
    found = 0;
    tend = r->last;
    for (ti = r->first; ti != tend; ti++) {
        t = *ti;
        end = t->last;
        for (it = t->first; it != end; it++) {
            if ((*it)->id == id) {
                found = *it;
                goto done;
            }
        }
    }
done:
    return found;
}
