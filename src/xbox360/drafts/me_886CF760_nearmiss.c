/* nearmiss (q5s 2026-11-24): 2 off; addi/lwz of self-relative header; RelHdr::Get / Pose::Init members stay 2, SkelData::Info() gives 7 */
/* agK 2026-11-19: top pads 0-7: 0 pads 2, 1-7 pads 3. */
/* agentA2 2026-11-18: skipped: 18+ helper/volatile spellings already swept, no new idea; still 2. */
/* 0x886CF760 near miss (2 off; sweep 2026-11-18, 10 more (volatile offset/header/pointer reads, restrict/uint base, offset-first): best 3, still 2; 8 more helper spellings reading the offset via the data pointer all fold the addi (7 off), /Oc plain): pose init: stores the model, reserves four 0x9C4 vectors, sets
 * bone_count and resizes the id-pair vector to base+extra entries filled with {-1,-1}. Residue: the game computes
 * the self-relative info pointer as addi r10,data,0x14 + lwz off,0x14(data); our helper reads the offset through
 * the addi result. Taking the data pointer / offset argument folds the addi away (7 off), offset-first add gives 3. */
typedef struct Ts4IdPair { short a, b; } Ts4IdPair;
typedef struct Ts4PairVec { Ts4IdPair *begin; Ts4IdPair *end; Ts4IdPair *cap; } Ts4PairVec;
typedef struct Ts4Vec12 { void *begin, *end, *cap; } Ts4Vec12;
typedef struct Ts4RelHdr { int self_off; } Ts4RelHdr;
typedef struct Ts4SkelInfo { char p[0x14]; int bone_count; int extra_count; char p2[0x34 - 0x1c]; int base_count; } Ts4SkelInfo;
typedef struct Ts4SkelData { char p[0x14]; Ts4RelHdr info; } Ts4SkelData;
typedef struct Ts4SkelRef { char p[8]; Ts4SkelData *data; } Ts4SkelRef;
typedef struct Ts4Model { char p[0x1c]; Ts4SkelRef *skel; } Ts4Model;
typedef struct Ts4Pose {
    void *unk00; Ts4Model *model; Ts4PairVec pairs; Ts4Vec12 v14, v20, v2c;
    short bone_count; char p3a[2]; Ts4Vec12 v3c;
} Ts4Pose;
void ts4_vector12_reserve_9C4_88264E58(Ts4Vec12 *v);
void fn_88264F28(void *object, int size);
void fn_88264C80(Ts4PairVec *v, Ts4IdPair *pos, unsigned n, const Ts4IdPair *fill);
static __inline Ts4SkelInfo *skel_info(Ts4RelHdr *h) { return (Ts4SkelInfo *)((char *)h + h->self_off); }
static __inline void pairs_resize(Ts4PairVec *v, unsigned n, const Ts4IdPair *fill)
{
    unsigned size = (unsigned)(v->end - v->begin);
    if (n < size) {
        Ts4IdPair *first = v->begin + n, *last = v->end;
        Ts4IdPair *d = first, *s = last;
        int k;
        for (k = (int)(v->end - last); k > 0; k--) *d++ = *s++;
        v->end = d;
    } else {
        fn_88264C80(v, v->end, n - size, fill);
    }
}
void ts4_pose_init(Ts4Pose *self, Ts4Model *model)
{
    Ts4IdPair none;
    Ts4SkelInfo *info;
    self->model = model;
    ts4_vector12_reserve_9C4_88264E58(&self->v14);
    fn_88264F28(&self->v20, 0x9c4);
    fn_88264F28(&self->v2c, 0x9c4);
    none.a = -1; none.b = -1;
    info = skel_info(&model->skel->data->info);
    self->bone_count = (short)info->bone_count;
    pairs_resize(&self->pairs, info->base_count + info->extra_count, &none);
    fn_88264F28(&self->v3c, 0x9c4);
}
