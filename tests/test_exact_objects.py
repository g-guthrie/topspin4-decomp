"""Synthetic negative controls for the portable exact-object verifier.

No SDK/game files or bytes are used. The two PPC words form a generic toy body.
"""
import struct
import sys
import unittest
from pathlib import Path
from unittest.mock import patch

sys.path.insert(0,str(Path(__file__).resolve().parents[1]/"tools"))
import ppc_exact_coff as P
import verify_exact_objects as V

A="fn_88001000"; B="fn_88001008"; VA=0x88001000; VB=0x88001008
CODE=struct.pack(">II",0x60000000,0x4e800020)
PACKED=0x40000200
RETAIL={"entry_va":0x88002000,"packed":PACKED,"size":8}

def object_pair():
    return {"sections":[{"name":".text","data":CODE,"rel":[]},
                        {"name":".text","data":CODE,"rel":[]},
                        {"name":".pdata","data":struct.pack(">II",0,PACKED),"rel":[(0,0,2)]},
                        {"name":".pdata","data":struct.pack(">II",0,PACKED),"rel":[(0,1,2)]}],
            "symbols":{0:{"name":A,"value":0,"section":1,"storage":2,"type":0x20},
                       1:{"name":B,"value":0,"section":2,"storage":2,"type":0x20}}}

class ExactObjectNegative(unittest.TestCase):
    def test_distinct_sections_and_strict_pdata(self):
        c=object_pair()
        self.assertEqual(V.text_piece(P,c,B,8)[0],CODE)
        self.assertEqual(V.pdata_entry(c,B,VB,8,RETAIL,False)["pdata_section_index"],1)
        c["sections"][3]["rel"]=[(0,1,6)]
        with self.assertRaises(ValueError):V.pdata_entry(c,B,VB,8,RETAIL,False)

    def test_padding_and_truncation(self):
        c=object_pair();c["sections"][0]["data"]+=b"\0"*4
        with self.assertRaises(ValueError):V.text_piece(P,c,A,8)
        c=object_pair();c["sections"][0]["data"]=CODE[:4]
        with self.assertRaises(ValueError):V.text_piece(P,c,A,8)

    def test_effective_relocation_addend(self):
        syms={0:{"name":A}};names={A:VA}
        target=struct.pack(">I",VA+12)
        good=struct.pack(">I",12)
        bad=struct.pack(">I",16)
        te,tm,_=P.normalize(target,0,[(0,0,2)],syms,names,VA,True)
        ge,gm,_=P.normalize(good,0,[(0,0,2)],syms,names,VA,False)
        be,bm,_=P.normalize(bad,0,[(0,0,2)],syms,names,VA,False)
        self.assertEqual((te,tm),(ge,gm))
        self.assertNotEqual(te,be)
        self.assertEqual(tm,bm)

    def test_unknown_relocation_and_pdata_begin(self):
        with self.assertRaises(ValueError):P.normalize(CODE[:4],0,[(0,0,99)],{0:{"name":A}},{A:VA},VA,False)
        c=object_pair();c["sections"][2]["data"]=struct.pack(">II",4,PACKED)
        with self.assertRaises(ValueError):V.pdata_entry(c,A,VA,8,RETAIL,False)

    def test_wrong_relocation_target_and_packed_flags(self):
        c=object_pair();c["sections"][2]["rel"]=[(0,1,2)]
        with self.assertRaises(ValueError):V.pdata_entry(c,A,VA,8,RETAIL,False)
        c=object_pair();c["sections"][2]["data"]=struct.pack(">II",0,PACKED^1)
        with self.assertRaises(ValueError):V.pdata_entry(c,A,VA,8,RETAIL,False)

    def test_branch_alias_requires_named_target_same_va(self):
        target={0:{"name":"canonical_call"}};base={0:{"name":A}}
        mapping,events=V.bound_aliases([(0,0,6)],[(0,0,6)],target,base,{"canonical_call":VA})
        self.assertEqual(mapping[A],VA)
        self.assertEqual(len(events),1)
        with self.assertRaises(ValueError):
            V.bound_aliases([(0,0,6)],[(0,0,6)],target,base,{"canonical_call":VA+4})
        with self.assertRaises(ValueError):
            V.bound_aliases([(4,0,6)],[(0,0,6)],target,base,{"canonical_call":VA})

    def test_data_alias_requires_same_slot_and_registry_va(self):
        target={0:{"name":"lbl_88001000"}};base={0:{"name":"canonical_data"}}
        t,b,events=V.symmetric_aliases([(0,0,16)],[(0,0,16)],target,base,{"canonical_data":VA})
        self.assertEqual(t["lbl_88001000"],VA)
        self.assertEqual(len(events),1)
        with self.assertRaises(ValueError):
            V.symmetric_aliases([(0,0,16)],[(0,0,16)],target,base,{"canonical_data":VA+4})
        t,b,events=V.symmetric_aliases([(0,0,16)],[(4,0,16)],target,base,{"canonical_data":VA})
        self.assertEqual(events,[])

    def test_reproduction_binding_rejects_swapped_object_or_profile(self):
        root=Path("C:/synthetic-exact-fixture");repo=root/"repo";build=root/"build"
        source="src/toy.c";obj=build/"toy.obj"
        with patch.object(V,"sha",side_effect=lambda p:"a"*64 if Path(p)==obj else "b"*64):
            unit={"object":"toy.obj","extra_flags":["/O1"]}
            binding={"object":"toy.obj","object_sha256":"a"*64,"source_sha256":"b"*64,"extra_flags":["/O1"]}
            entry={"base_path":str(obj)};inputs={source:"b"*64}
            V.check_source_binding(repo,build,source,unit,binding,entry,inputs)
            bad=dict(binding,object="other.obj")
            with self.assertRaises(ValueError):V.check_source_binding(repo,build,source,unit,bad,entry,inputs)
            bad=dict(binding,extra_flags=[])
            with self.assertRaises(ValueError):V.check_source_binding(repo,build,source,unit,bad,entry,inputs)
            bad=dict(binding,object_sha256="0"*64)
            with self.assertRaises(ValueError):V.check_source_binding(repo,build,source,unit,bad,entry,inputs)

    def test_reproduction_receipt_rejects_corrupt_input_pins(self):
        good="a"*64;bad="b"*64
        inputs={"runner_sha256":good,"repo_files_sha256":{"tools/matching.py":good}}
        receipt={"inputs_sha256":good,"jeff_split_config_sha256":good}
        V.check_reproduction_hash_fields(inputs,receipt,good,good,good)
        with self.assertRaises(ValueError):V.check_reproduction_hash_fields(inputs,receipt,bad,good,good)
        with self.assertRaises(ValueError):V.check_reproduction_hash_fields(inputs,receipt,good,None,good)
        with self.assertRaises(ValueError):V.check_reproduction_hash_fields(inputs,receipt,good,bad,good)
        with self.assertRaises(ValueError):V.check_reproduction_hash_fields(inputs,receipt,good,good,bad)
        altered={**inputs,"repo_files_sha256":{"tools/matching.py":bad}}
        with self.assertRaises(ValueError):V.check_reproduction_hash_fields(altered,receipt,good,good,good)

if __name__=="__main__":unittest.main()
