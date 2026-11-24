/* 0x887F7678: returns the first non-null object in the pointer vector at +0x34/+0x38 whose id (+0x20) equals *key,
 * or 0.
 * Matched (/Oc plain): the target loads o->id first but compares `cmplw key,id`. The id is a one-word struct copied
 * into a block local, which keeps its load first while the compare follows the written order. */
typedef struct Ts4ObjId { unsigned int id; } Ts4ObjId;
typedef struct Ts4IdObj { char pad_00[0x20]; Ts4ObjId id; } Ts4IdObj;
typedef struct Ts4IdObjVec { Ts4IdObj **begin; Ts4IdObj **end; } Ts4IdObjVec;
typedef struct Ts4IdObjOwner { char pad_00[0x34]; Ts4IdObjVec v; } Ts4IdObjOwner;

static unsigned int ts4_idvec_size(Ts4IdObjVec *v) { return v->end - v->begin; }

Ts4IdObj *ts4_find_object_by_id_887F7678(Ts4IdObjOwner *s, const Ts4ObjId *key)
{
    unsigned int i, n = ts4_idvec_size(&s->v);
    for (i = 0; i < n; i++) {
        Ts4IdObj *o = s->v.begin[i];
        if (o) {
            Ts4ObjId k;
            k = o->id;
            if (key->id == k.id)
                return o;
        }
    }
    return 0;
}
