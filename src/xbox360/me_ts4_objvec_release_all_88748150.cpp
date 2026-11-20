struct ts4_obj_88719EB0 { char b[0x14]; void ts4_if_call_seq_u32_off10_88719EB0(); };
struct ObjVec { ts4_obj_88719EB0 *first; ts4_obj_88719EB0 *last; };
extern "C" ts4_obj_88719EB0 *ts4_elt14_erase_range_88226670(ObjVec *v, ts4_obj_88719EB0 *dst, ts4_obj_88719EB0 *last);
extern "C" void ts4_loop_call_seq_u32_off0_8825CD08(ObjVec *v);
extern "C" void ts4_objvec_release_all_88748150(ObjVec *v){ unsigned int i;
 for (i = 0; i < (unsigned int)(v->last - v->first); i++) v->first[i].ts4_if_call_seq_u32_off10_88719EB0();
 ts4_elt14_erase_range_88226670(v, v->first, v->last); ts4_loop_call_seq_u32_off0_8825CD08(v); }