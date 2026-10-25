#!/usr/bin/env python3
"""Portable independent full-object exact checker for the frozen publication packet.

Read-only: verifies flat retail PE, all source/header hashes, full target/rebuilt
COFF extents, effective PPC relocations, and exact pdata. Objdiff similarity is
never an acceptance criterion. Receipt is create-new and is not shipped.
"""
from __future__ import annotations
import argparse, ast, hashlib, json, re, struct, sys, traceback
from collections import Counter, defaultdict
from pathlib import Path
import ppc_exact_coff as P

ck=P.ck; sha=P.sha; IMAGE_BASE=0x88000000
PE_SHA_ALLOWED={
    "7b92548a9c2158b78928e0e3b31760e341aad6cbccf58a7112da761125c4b936",  # historical T02 flat image
    "d78f393eb434b283040f002cd5346b0a70732df8b1fc0798c7a0be8546f27997",  # reproducible Jeff extraction/flattening
}
TOOL_SHA={"xex":"dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44",
"jeff":"c3bece150b9c88e2a052955646a21a777d2d9dd15689ba05b4ad265c0dec83c4",
"objdiff":"97f906acf83442040e3624688341f821238db367c9dba7585213d301216310d2",
"compiler":"6c27181a805dee13d0c9515efc00812d92f9c504cd1158eaf1f338d9f651f198"}

def pdata_catalog(flat):
    pe = struct.unpack_from("<I", flat, 0x3c)[0]
    ck(flat[pe:pe+4] == b"PE\0\0", "PE signature")
    opt = pe + 24
    ck(struct.unpack_from("<I", flat, opt+28)[0] == IMAGE_BASE, "PE image base")
    rva, length = struct.unpack_from("<II", flat, opt+96+3*8)
    ck(length % 8 == 0 and rva+length <= len(flat), "pdata directory bounds")
    found, spans = {}, []
    for off in range(0, length, 8):
        begin, packed = struct.unpack_from(">II", flat, rva+off)
        size = ((packed >> 8) & 0x3fffff) * 4
        ck(size > 0 and begin not in found, "duplicate/zero retail pdata")
        found[begin] = {"entry_va": IMAGE_BASE+rva+off, "packed": packed, "size": size}
        spans.append((begin, begin+size))
    return found, sorted(spans)

def strict_pdata(c, symbol, addr, size, expected, target):
    sections = [s for s in c["sections"] if s["name"] == ".pdata"]
    if expected is None:
        ck(all(not s["data"] and not s["rel"] for s in sections), "unexpected pdata section")
        return {"present": False}
    ck(len(sections) == 1, "pdata section count")
    section = sections[0]
    ck(len(section["data"]) == 8 and len(section["rel"]) == 1, "pdata entry/relocation count")
    off, idx, kind = section["rel"][0]
    ck(off == 0 and kind == 2, "pdata begin relocation must be ADDR32 at zero")
    sym = c["symbols"].get(idx)
    ck(sym is not None and sym["name"] == symbol and sym["storage"] == 2 and sym["type"] & 0x20 and sym["section"] > 0, "pdata relocation target symbol")
    ck(c["sections"][sym["section"]-1]["name"] == ".text", "pdata symbol section")
    begin = struct.unpack_from(">I", section["data"], 0)[0]
    packed = struct.unpack_from(">I", section["data"], 4)[0]
    ck(packed == expected["packed"] and expected["size"] == size, "pdata packed size/flags")
    ck(begin == (addr if target else 0), "pdata raw begin/addend")
    ck(sym["value"] == 0, "pdata function symbol offset")
    return {"present": True, "raw_begin": begin, "packed": packed, "entry_va": expected["entry_va"], "relocation_kind": kind, "normalized_addend": 0}

def full_extent(S, c, symbol, size, target):
    # The one-address manifest requires one function per target and rebuilt object.
    # The reviewed parser checks the next function and exact .text end, including
    # any padding. Any nonzero symbol offset or trailing padding is held.
    data, off, rel = S.text_extent(c, symbol, size, target=True)
    ck(off == 0 and len(data) == size, "not a complete one-function object")
    ck(len(c["sections"]) >= 1, "empty COFF")
    return data, off, rel

def bound_aliases(target_rel, base_rel, target_symbols, base_symbols, known):
    """Bind only fn_XXXXXXXX branch aliases to an independently named target VA."""
    mapping=dict(known); aliases=[]
    t_by_slot={(off,kind):idx for off,idx,kind in target_rel if kind==6}
    ck(len(t_by_slot)==sum(kind==6 for _,_,kind in target_rel),"duplicate target branch relocation slot")
    for off,idx,kind in base_rel:
        if kind!=6:continue
        name=base_symbols[idx]["name"]
        if name in mapping:continue
        ck(re.fullmatch(r"fn_[0-9A-F]{8}",name) is not None,"unresolved noncanonical branch alias")
        ck((off,kind) in t_by_slot,"alias lacks matching target relocation")
        target_name=target_symbols[t_by_slot[(off,kind)]]["name"]
        ck(target_name in known and known[target_name]==int(name[3:],16),"alias address differs from independently named target")
        mapping[name]=known[target_name]
        aliases.append({"offset":off,"base_name":name,"target_name":target_name,"resolved_va":mapping[name]})
    return mapping, aliases

def check_row(S, flat, catalog, spans, names, unit, obj, build):
    source = unit["source"]
    ck(re.fullmatch(r"src/xbox360/matched/local_20261025/[0-9A-Fa-f]{2}/fn_[0-9A-Fa-f]{8}\.c", source) is not None, "unexpected source path")
    ck(len(unit["symbols"]) == 1 and not unit.get("headers"), "not a header-free one-address unit")
    symbol, size = next(iter(unit["symbols"].items()))
    ck(re.fullmatch(r"fn_[0-9A-Fa-f]{8}", symbol) is not None and source.endswith(symbol+".c"), "source/symbol binding")
    addr = int(symbol[3:], 16)
    ck(names.get(symbol) == addr, "symbols.txt address binding")
    ck(isinstance(size, int) and size > 0 and size % 4 == 0, "invalid size")
    ck(not any(lo < addr < hi for lo, hi in spans), "inside retail pdata interval")
    expected = catalog.get(addr)
    ck(expected is None or expected["size"] == size, "retail pdata size")
    expected_range = None if expected is None else [f"0x{expected['entry_va']:08X}", f"0x{expected['entry_va']+8:08X}"]
    ck(unit["pdata_range"] == expected_range, "manifest/retail pdata slot binding")
    ck(obj["metadata"]["source_path"] == source, "objdiff source binding")
    target, base = Path(obj["target_path"]).resolve(), Path(obj["base_path"]).resolve()
    ck(target.is_relative_to(build) and base.is_relative_to(build), "object outside fresh build")
    ck(target.name == unit["object"] and symbol in obj["name"], "object filename/name binding")
    ck(target.is_file() and base.is_file(), "target/base object missing")
    tc, bc = S.coff(target), S.coff(base)
    tcode, toff, trel = full_extent(S, tc, symbol, size, True)
    bcode, boff, brel = full_extent(S, bc, symbol, size, False)
    retail = P.pe_read(flat, addr, size)
    ck(tcode == retail, "full target extent differs from flat retail PE")
    base_names,aliases=bound_aliases(trel,brel,tc["symbols"],bc["symbols"],names)
    te, tm, tp = S.normalize(tcode, toff, trel, tc["symbols"], names, addr, True)
    be, bm, bp = S.normalize(bcode, boff, brel, bc["symbols"], base_names, addr, False)
    ck(tm == bm, "relocation-masked instruction bytes differ")
    ck(te == be, "effective relocation target/addend differs")
    strict_pdata(tc, symbol, addr, size, expected, True)
    strict_pdata(bc, symbol, addr, size, expected, False)
    return {"symbol": symbol, "address": f"0x{addr:08X}", "size": size, "source_sha256": unit["source_sha256"], "target_object_sha256": tc["sha256"], "base_object_sha256": bc["sha256"], "target_code_sha256": hashlib.sha256(tcode).hexdigest(), "base_code_sha256": hashlib.sha256(bcode).hexdigest(), "relocations": len(te), "ref_pairs_target": len(tp), "ref_pairs_base": len(bp), "alias_bindings":aliases,"pdata_present": expected is not None, "status": "EXACT_FULL_RAW_RELOC_PDATA"}

def ext_defs(c):
    return [s for s in c["symbols"].values() if s["section"] > 0 and s["storage"] == 2 and s["type"] & 0x20]

def seed_registry(repo, names):
    """Merge pinned source symbol registry; reject any conflicting address."""
    out=dict(names)
    for line in (repo/"config/54540859/symbols.seed.txt").read_text(encoding="utf-8").splitlines():
        m=re.match(r"^(\S+) = \.([A-Za-z0-9_]+):0x([0-9A-Fa-f]+);",line)
        if m:
            name,section,addr=m.groups();va=int(addr,16)
            ck(name not in out or out[name]==va,"conflicting seed symbol VA")
            out[name]=va
    return out

def symmetric_aliases(trel,brel,tsyms,bsyms,known):
    tnames=dict(known);bnames=dict(known);aliases=[]
    t={(o,k):tsyms[i]["name"] for o,i,k in trel if k!=18}
    b={(o,k):bsyms[i]["name"] for o,i,k in brel if k!=18}
    ck(len(t)==sum(k!=18 for _,_,k in trel) and len(b)==sum(k!=18 for _,_,k in brel),"duplicate relocation slot")
    for slot,tname in t.items():
        bname=b.get(slot)
        if bname is None:continue
        if tname not in tnames and bname in bnames:
            m=re.fullmatch(r"(?:fn|lbl)_([0-9A-F]{8})",tname)
            ck(m is not None and int(m.group(1),16)==bnames[bname],"target alias registry/slot mismatch")
            tnames[tname]=bnames[bname];aliases.append({"side":"target","slot":slot,"alias":tname,"canonical":bname,"va":tnames[tname]})
        if bname not in bnames and tname in tnames:
            m=re.fullmatch(r"(?:fn|lbl)_([0-9A-F]{8})",bname)
            ck(m is not None and int(m.group(1),16)==tnames[tname],"base alias registry/slot mismatch")
            bnames[bname]=tnames[tname];aliases.append({"side":"base","slot":slot,"alias":bname,"canonical":tname,"va":bnames[bname]})
    return tnames,bnames,aliases

def text_piece(S, c, symbol, size):
    defs = [s for s in ext_defs(c) if s["name"] == symbol]
    ck(len(defs) == 1, f"{symbol}: external function definition count")
    s = defs[0]; section = c["sections"][s["section"]-1]
    ck(section["name"] == ".text", "function not in text")
    begin = s["value"]; end = begin+size
    ck(end <= len(section["data"]), "truncated function code")
    # All function symbols, including static helpers, establish boundaries.
    later = [x["value"] for x in c["symbols"].values() if x["section"] == s["section"] and x["type"] & 0x20 and x["value"] > begin]
    boundary = min(later, default=len(section["data"]))
    ck(boundary == end, f"{symbol}: code boundary/padding differs from declared length: +{boundary-begin} versus {size}")
    rel = [(off-begin, idx, typ) for off, idx, typ in section["rel"] if begin <= off < end]
    ck(all(off >= 0 and off+4 <= size and off%4 == 0 for off,_,_ in rel), "invalid code relocation offset")
    return section["data"][begin:end], begin, rel

def pdata_entry(c, symbol, address, size, retail, target):
    secs = [s for s in c["sections"] if s["name"] == ".pdata"]
    if not secs:
        ck(retail is None, "missing expected pdata section")
        return {"present": False}
    matches = []
    for sec_index, sec in enumerate(secs):
        ck(len(sec["data"])%8 == 0, "mis-sized pdata section")
        ck(len(sec["rel"]) == len(sec["data"])//8, "pdata relocation count")
        for off, idx, kind in sec["rel"]:
            ck(off%8 == 0 and kind == 2 and idx in c["symbols"], "pdata relocation kind/slot/symbol")
            sym = c["symbols"][idx]
            ck(sym["section"]>0 and sym["type"]&0x20 and c["sections"][sym["section"]-1]["name"]==".text", "pdata targets nonfunction")
            if sym["name"] == symbol: matches.append((sec_index,off,idx))
    ck(len(matches) == (1 if retail else 0), "function pdata entry presence/count")
    if retail is None: return {"present": False}
    sec_index, off, idx = matches[0]
    sec = secs[sec_index]
    raw, packed = struct.unpack_from(">II", sec["data"], off)
    ck(packed == retail["packed"] and retail["size"] == size, "pdata packed size/flags")
    ck(raw == (address if target else 0), "pdata relocation raw begin/addend")
    return {"present": True, "pdata_section_index": sec_index, "section_offset": off, "packed": packed, "raw_begin": raw, "relocation_kind": 2, "relocation_target": symbol, "normalized_addend": 0}

def check(S, flat, pdata, spans, names, repo, build, unit, obj):
    source = unit["source"]
    ck(obj["metadata"].get("source_path") == source, "objdiff source binding")
    ck((repo/source).is_file() and sha(repo/source) == unit["source_sha256"], "source SHA")
    for name, digest in unit["headers"].items():
        ck((repo/name).is_file() and sha(repo/name) == digest, f"header SHA: {name}")
    ck(set(unit["extra_flags"]) <= {"/O1", "/TP"}, "unreviewed compile flags")
    target, base = Path(obj["target_path"]).resolve(), Path(obj["base_path"]).resolve()
    ck(target.is_relative_to(build) and base.is_relative_to(build), "object outside fresh build")
    ck(target.name == Path(source).with_suffix(".obj").name and base.name == unit["object"] and target.is_file() and base.is_file(), "object binding/missing")
    tc, bc = S.coff(target), S.coff(base)
    required = set(unit["symbols"])
    ck({x["name"] for x in ext_defs(tc)} == required, "target external function inventory")
    ck({x["name"] for x in ext_defs(bc)} == required, "base external function inventory")
    rows = []
    for symbol, size in unit["symbols"].items():
        ck(re.fullmatch(r"fn_[0-9A-F]{8}", symbol) is not None, "noncanonical symbol")
        addr = int(symbol[3:],16)
        ck(names.get(symbol) == addr, "symbols.txt binding")
        ck(size > 0 and size%4 == 0, "invalid function size")
        ck(not any(lo < addr < hi for lo,hi in spans), "retail pdata interior")
        expected = pdata.get(addr)
        ck(expected is None or expected["size"] == size, "retail pdata packed length")
        tcode, toff, trel = text_piece(S, tc, symbol, size)
        bcode, boff, brel = text_piece(S, bc, symbol, size)
        ck(tcode == S.pe_read(flat, addr, size), "target/flat retail full extent")
        tnames,bnames,aliases=symmetric_aliases(trel,brel,tc["symbols"],bc["symbols"],names)
        te, tm, tp = S.normalize(tcode,toff,trel,tc["symbols"],tnames,addr,True)
        be, bm, bp = S.normalize(bcode,boff,brel,bc["symbols"],bnames,addr,False)
        ck(tm == bm and te == be, "masked code/effective relocation target or addend")
        pt = pdata_entry(tc,symbol,addr,size,expected,True)
        pb = pdata_entry(bc,symbol,addr,size,expected,False)
        ck(pt["present"] == pb["present"], "pdata target/base presence")
        rows.append({"symbol":symbol,"address":f"0x{addr:08X}","size":size,"source":source,"source_sha256":unit["source_sha256"],"target_object_sha256":tc["sha256"],"base_object_sha256":bc["sha256"],"target_code_sha256":hashlib.sha256(tcode).hexdigest(),"base_code_sha256":hashlib.sha256(bcode).hexdigest(),"target_offset":toff,"base_offset":boff,"relocations":len(te),"ref_pairs_target":len(tp),"ref_pairs_base":len(bp),"alias_bindings":aliases,"pdata_present":pt["present"],"status":"EXACT_FULL_RAW_RELOC_PDATA"})
    return rows

def literal_published_units(repo):
    """Read the existing public source inventory as AST data, never execute it."""
    path=repo/"tools/matching.py"
    tree=ast.parse(path.read_text(encoding="utf-8"),filename=str(path))
    assignments=[node for node in tree.body if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id=="MATCHING_UNITS" for t in node.targets)]
    ck(len(assignments)==1,"published matching unit literal count")
    rows=ast.literal_eval(assignments[0].value)
    ck(isinstance(rows,tuple) and len(rows)==213 and sum(len(x["symbols"]) for x in rows)==2397,"published matching inventory count")
    return rows

def check_source_binding(repo,build,source,unit,binding,obj,inputs_files):
    base=Path(obj["base_path"]).resolve();relative=(build/binding["object"]).resolve()
    ck(base==relative and base.is_relative_to(build),"source/base object path binding")
    ck(base.name==unit["object"] and binding["extra_flags"]==unit.get("extra_flags",[]),"source object/profile binding")
    digest=sha(base)
    ck(binding["object_sha256"]==digest,"source object digest binding")
    ck(binding["source_sha256"]==inputs_files[source]==sha(repo/source),"source input digest binding")

def check_reproduction_hash_fields(inputs,receipt,inputs_digest,split_digest,runner_digest):
    ck(receipt.get("inputs_sha256")==inputs_digest,"reproduction inputs file digest")
    ck(split_digest is not None and receipt.get("jeff_split_config_sha256")==split_digest,"reproduction split config digest")
    ck(inputs.get("runner_sha256")==runner_digest,"reproduction runner digest")
    ck(inputs.get("repo_files_sha256",{}).get("tools/matching.py")==runner_digest,"reproduction runner input digest")

def validate_provenance(repo,build,objdiff,report_path,project,core,other):
    inputs_path=build/"INPUTS.json";inputs=json.loads(inputs_path.read_text(encoding="utf-8"))
    repro_path=build/"REPRODUCTION-RECEIPT.json";private_path=build/"BUILD-RECEIPT.json"
    if repro_path.exists():
        ck(not private_path.exists(),"ambiguous two receipt modes")
        mode="public-reproduction";path=repro_path
        receipt=json.loads(path.read_text(encoding="utf-8"))
        ck(receipt.get("schema")=="matching-source-reproduction/1" and receipt.get("exit_code")==0,"reproduction receipt schema/status")
        ck(receipt.get("cleanup_scope")=="sequential child commands completed; whole descendant cleanup not inspected","reproduction cleanup scope")
        ck(receipt.get("base_flags")==["/nologo","/c","/O2","/Oi"],"compiler base profile")
        ck(receipt.get("objdiff_project_sha256")==sha(objdiff) and receipt.get("objdiff_report_sha256")==sha(report_path),"reproduction project/report binding")
        split_config=build/"split/config.json"
        check_reproduction_hash_fields(inputs,receipt,sha(inputs_path),sha(split_config) if split_config.is_file() else None,sha(repo/"tools/matching.py"))
        expected=list(literal_published_units(repo))+list(core["units"])+list(other["units"])
        ck(len(expected)==11598,"expected source unit count")
        by_source={u["source"]:u for u in expected}
        ck(len(by_source)==len(expected),"duplicate expected source")
        bindings=receipt.get("source_object_bindings",[])
        ck(len(bindings)==len(expected),"source-object binding count")
        binding_by_source={x["source"]:x for x in bindings}
        ck(set(binding_by_source)==set(by_source),"source-object binding inventory")
        project_by_source={x["metadata"].get("source_path"):x for x in project["units"] if x.get("base_path")}
        ck(set(project_by_source)==set(by_source),"full project base-source inventory")
        inputs_files=inputs.get("repo_files_sha256",{})
        header_paths={p.relative_to(repo).as_posix() for p in (repo/"src/xbox360").rglob("*.h")}
        config_paths={p.relative_to(repo).as_posix() for p in (repo/"config").rglob("*") if p.is_file()}
        ck(set(inputs_files)==set(by_source)|header_paths|config_paths|{"tools/matching.py"},"full source/header/config/runner input closure")
        for source,unit in by_source.items():
            binding=binding_by_source[source];obj=project_by_source[source]
            check_source_binding(repo,build,source,unit,binding,obj,inputs_files)
        for relative,digest in inputs_files.items():
            ck(sha(repo/relative)==digest,"source/header/config/runner changed from reproduction input")
        compiler=Path(inputs["pins"]["compiler"]["path"])
        companions={p.name:sha(p) for p in compiler.parent.glob("*.dll")}
        ck(companions==inputs.get("compiler_companions_sha256"),"compiler companion closure")
    else:
        mode="private-job";path=private_path
        receipt=json.loads(path.read_text(encoding="utf-8"))
        ck(receipt.get("exit_code")==0 and receipt.get("active_descendants_after_parent")==0 and not receipt.get("cleanup_failure"),"fresh private build did not complete cleanly")
    for key,expected in TOOL_SHA.items():
        pin=inputs["pins"][key]
        ck(pin["sha256"]==expected and sha(Path(pin["path"]))==expected,f"private tool/input pin: {key}")
    if mode=="public-reproduction":
        wrapper=inputs["pins"].get("wrapper")
        ck(wrapper is not None and sha(Path(wrapper["path"]))==wrapper["sha256"],"wrapper pin")
    return mode,path,inputs_path

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--repo",type=Path,required=True)
    ap.add_argument("--pe",type=Path,required=True)
    ap.add_argument("--objdiff",type=Path,required=True)
    ap.add_argument("--out",type=Path,required=True)
    a=ap.parse_args(); repo=a.repo.resolve(); objdiff=a.objdiff.resolve(); build=objdiff.parents[1]
    ck(not a.out.exists(),"receipt already exists")
    pe_sha=sha(a.pe)
    ck(pe_sha in PE_SHA_ALLOWED,"flat retail PE hash")
    flat=a.pe.read_bytes(); pdata,spans=pdata_catalog(flat)
    symbols=repo/"config/54540859/symbols.txt"; seed=repo/"config/54540859/symbols.seed.txt"; names,_=P.symbols_index(symbols); names=seed_registry(repo,names)
    core_path=repo/"config/54540859/local_20261025_units.json"
    other_path=repo/"config/54540859/remaining_20261025_units.json"
    core=json.loads(core_path.read_text(encoding="utf-8"))
    other=json.loads(other_path.read_text(encoding="utf-8"))
    ck(core["schema"]=="exact-code-units/1" and core["count"]==11368 and len(core["units"])==11368,"core manifest count/schema")
    ck(other["schema"]=="remaining-exact-units/1" and other["count"]==28 and len(other["units"])==17 and sum(len(x["symbols"]) for x in other["units"])==28,"remaining manifest count/schema")
    requested={}
    for unit in core["units"]+other["units"]:
        ck(unit["source"] not in requested,"duplicate source across packets")
        requested[unit["source"]]=unit
    intervals=[]
    for unit in requested.values():
        for symbol,size in unit["symbols"].items():
            addr=int(symbol[3:],16); intervals.append((addr,addr+size,symbol))
    intervals.sort()
    ck(len(intervals)==11396 and all(intervals[i][1]<=intervals[i+1][0] for i in range(len(intervals)-1)),"duplicate/overlap function interval")
    report_path=objdiff.parent/"report.json"
    ck(report_path.is_file() and report_path.stat().st_size>0,"objdiff report missing")
    project=json.loads(objdiff.read_text(encoding="utf-8"))
    mode,receipt_path,inputs_path=validate_provenance(repo,build,objdiff,report_path,project,core,other)
    objs={}
    for obj in project["units"]:
        source=obj["metadata"].get("source_path")
        if source in requested:
            ck(source not in objs,"duplicate objdiff source")
            objs[source]=obj
    ck(set(objs)==set(requested),"objdiff/requested source inventory")
    core_rows=[];other_rows=[];held=[]
    for i,unit in enumerate(core["units"],1):
        try:
            source=repo/unit["source"]
            ck(source.is_file() and sha(source)==unit["source_sha256"],"core source SHA")
            core_rows.append(check_row(P,flat,pdata,spans,names,unit,objs[unit["source"]],build))
        except Exception as e:
            held.append({"packet":"core","source":unit.get("source"),"functions":list(unit.get("symbols",{})),"error":repr(e),"trace":traceback.format_exc(limit=2)})
        if i%1000==0:print(json.dumps({"core_processed":i,"exact":len(core_rows),"held_units":len(held)}),flush=True)
    for unit in other["units"]:
        try:other_rows.extend(check(P,flat,pdata,spans,names,repo,build,unit,objs[unit["source"]]))
        except Exception as e:held.append({"packet":"remaining","source":unit.get("source"),"functions":list(unit.get("symbols",{})),"error":repr(e),"trace":traceback.format_exc(limit=2)})
    # Entire fresh object tree, including already-published sources: a duplicate
    # external function definition would make an otherwise exact unit unsafe to link.
    definitions=defaultdict(set);object_hashes={};missing=[]
    for obj in project["units"]:
        path_text=obj.get("base_path")
        if not path_text:continue
        path=Path(path_text).resolve()
        ck(path.is_relative_to(build),"project base object outside fresh build")
        if not path.is_file():missing.append(str(path));continue
        if path in object_hashes:continue
        c=P.coff(path);object_hashes[path]=c["sha256"]
        for s in c["symbols"].values():
            if s["section"]>0 and s["storage"]==2 and s["type"]&0x20:
                definitions[s["name"]].add(str(path))
    duplicates={k:sorted(v) for k,v in definitions.items() if len(v)>1}
    ck(not missing,"missing rebuilt project object")
    alias_events=[binding for row in core_rows for binding in row["alias_bindings"]]
    alias_summary={}
    for b in alias_events:
        key=f"{b['base_name']} -> {b['target_name']} @ 0x{b['resolved_va']:08X}"
        alias_summary[key]=alias_summary.get(key,0)+1
    result={"schema":"portable-independent-full-object-exact/1","requested_functions":11396,
        "core_exact":len(core_rows),"remaining_exact":len(other_rows),"held_functions":11396-len(core_rows)-len(other_rows),
        "held_units":held,"duplicate_external_function_definitions":duplicates,
        "project_rebuilt_object_count":len(object_hashes),
        "core_alias_event_count":len(alias_events),"core_alias_summary":alias_summary,
        "inputs":{"flat_pe_sha256":pe_sha,"allowed_flat_pe_sha256":sorted(PE_SHA_ALLOWED),"symbols_sha256":sha(symbols),"symbols_seed_sha256":sha(seed),"core_manifest_sha256":sha(core_path),"remaining_manifest_sha256":sha(other_path),"objdiff_project_sha256":sha(objdiff),"objdiff_report_sha256":sha(report_path),"receipt_mode":mode,"reproduction_or_build_receipt_sha256":sha(receipt_path),"build_inputs_sha256":sha(inputs_path),"tool_input_sha256":TOOL_SHA,"reviewer_program_sha256":sha(Path(__file__))},
        "core_rows":core_rows,"remaining_rows":other_rows}
    with a.out.open("x",encoding="utf-8",newline="\n") as f:json.dump(result,f,sort_keys=True,indent=2);f.write("\n")
    print(json.dumps({"out":str(a.out),"sha256":sha(a.out),"core_exact":len(core_rows),"remaining_exact":len(other_rows),"held_functions":result["held_functions"],"duplicate_functions":len(duplicates)}))
    return 0 if result["held_functions"]==0 and not duplicates else 1

if __name__=="__main__":sys.exit(main())
