/* agAX draft, 887311F8. Route: LTCG, ext cpp, ctx ["flags(/Ob1):src/xbox360/cx44_b.c", src/xbox360/fam6_w_cpp_000.cpp].
   The same body in C with plain stub callees (d1/rs/g1) matched every instruction word under LTCG with
   ctx flags(/Ob1):src/xbox360/cx44_b.c; only the callee names differed. The LTCG view of
   ts4_rec12_vec_equal_886EDC28 is what keeps v->first in r28 with the r29 byte-offset induction (plain /Oc: 7 off,
   r27/r28 swap). With the real C++ member callee the LTCG link fails: fam6_w_cpp_000.cpp needs __imp_VdGlobal*
   (skipped by the stub pass), and without that context the regex in tools/fn_check_ltcg.py reads the demangled
   C++ "unresolved external symbol" message as `"public:` so the mangled member never gets a stub. */
/* 0x887311F8: find a record set equal to `key` in a vector of 0x14-byte entries; on a hit, release the
   last entry and shrink the vector to n = count-1 and return the hit index; on a miss refresh key->x10. */
struct RecVec { char *first; char *last; };
struct ts4_obj_88719EB0 { char b[0x14]; void ts4_if_call_seq_u32_off10_88719EB0(); };
struct RecSetVec { ts4_obj_88719EB0 *first; ts4_obj_88719EB0 *last; };
struct RecSetKey { RecVec recs; char pad[8]; unsigned x10; };
extern "C" unsigned char ts4_rec12_vec_equal_886EDC28(RecVec *a, RecVec *b);
extern "C" unsigned ts4_if_call_seq_fn_88714730_882225E0(RecSetVec *v, unsigned n);
extern "C" unsigned fn_88291068(char *recs);
extern "C" unsigned recset_vec_find_or_trim_887311F8(RecSetVec *v, RecSetKey *key)
{
    unsigned i;
    unsigned n = (v->last - v->first) - 1;
    for (i = 0; i < n; i++) {
        if (ts4_rec12_vec_equal_886EDC28(&key->recs, (RecVec *)&v->first[i])) {
            v->first[n].ts4_if_call_seq_u32_off10_88719EB0();
            ts4_if_call_seq_fn_88714730_882225E0(v, n);
            return i;
        }
    }
    if (i == n)
        key->x10 = fn_88291068(key->recs.first);
    return n;
}
