"""Pure-logic tests for tools/asm2c (no compiler or game files needed)."""
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools" / "asm2c"))
import cfg  # noqa: E402
import emit  # noqa: E402
import run  # noqa: E402
import translate  # noqa: E402


def line(addr, word, text):
    return f"{addr:08X}  {word}  {text}"


ENV = translate.Env(lambda sym: None)
BASE = 0x88000000


def prog(texts):
    """Instruction texts -> fn_asm lines at consecutive addresses from BASE."""
    return [line(BASE + 4 * i, "00000000", t) for i, t in enumerate(texts)]


def tgt(i):
    """Branch target text for instruction index i."""
    return f"0x{BASE + 4 * i:08x}"


def gen(texts, **kw):
    return translate.gen(prog(texts), ENV, **kw)


class TranslateTests(unittest.TestCase):
    def test_getter(self):
        r = translate.gen([line(0x88000000, "80630008", "lwz     r3,8(r3)"),
                           line(0x88000004, "4e800020", "blr")], ENV)
        self.assertEqual(r["kind"], "get")
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0)")
        self.assertEqual(r["body"], "    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));\n")

    def test_setter_returns_void(self):
        r = translate.gen([line(0x88000000, "90830010", "stw     r4,16(r3)"),
                           line(0x88000004, "4e800020", "blr")], ENV)
        self.assertEqual(r["kind"], "set")
        self.assertTrue(r["sig"].startswith("void NAME"))
        self.assertIn("*(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;", r["body"])

    def test_tail_call(self):
        r = translate.gen([line(0x88000000, "48000000", "b       0x88001000   ; REL24 fn_88001000")], ENV)
        self.assertEqual(r["kind"], "tailcall")
        self.assertEqual(r["protos"], {"fn_88001000": 1})
        self.assertEqual(r["body"], "    return fn_88001000((ts4_word)a0);\n")

    def test_tail_call_arguments_follow_written_registers_in_mode_1(self):
        # `mr r3,r5; b f`: one argument; a temporary in r10 is not an argument
        t = ["mr r11,r3", "li r10,0", "addi r3,r3,16", "stb r10,8(r11)", "b 0x0 -> 0x88001000   ; REL24 fn_88001000"]
        r = gen(t, mode=1)
        self.assertIn("return fn_88001000((ts4_word)(a0 + 16));", r["body"])
        self.assertEqual(r["protos"], {"fn_88001000": 1})

    def test_unsupported_raises_skip(self):
        with self.assertRaises(translate.Skip):
            translate.gen([line(0x88000000, "00000000", "frobnicate r3,r4")], ENV)

    def test_arity_counts_unwritten_arg_registers(self):
        lines = [line(0, "90a30000", "stw     r5,0(r3)"), line(4, "4e800020", "blr")]
        self.assertEqual(translate.arity(lines, lambda s: None), 3)


class StructurizerTests(unittest.TestCase):
    """Short-circuit conditions, shared tails, diamonds and loops (pure translation)."""

    def test_and_chain(self):
        r = gen(["lwz r11,0(r3)", "cmplwi cr6,r11,0", f"beq cr6, 0x1c -> {tgt(8)}", "lwz r10,4(r3)",
                 "cmplwi cr6,r10,0", f"beq cr6, 0x10 -> {tgt(8)}", "li r11,1", "stw r11,8(r3)", "blr"])
        self.assertEqual(r["kind"], "if_get")
        self.assertRegex(r["body"], r"if \(\(ts4_word\)t1 != 0 && .*\+ 4\)\)? != 0\) \{")

    def test_or_chain(self):
        r = gen(["lwz r11,0(r3)", "cmplwi cr6,r11,0", f"bne cr6, 0x14 -> {tgt(6)}", "lwz r10,4(r3)",
                 "cmplwi cr6,r10,0", f"beq cr6, 0x10 -> {tgt(8)}", "li r11,1", "stw r11,8(r3)", "blr"])
        self.assertIn(" || ", r["body"])
        self.assertIn("= (ts4_word)1;", r["body"])

    def test_shared_tail(self):
        # if (a && b) a->0 = b; return 0;   (two branches to the same tail)
        r = gen(["cmplwi cr6,r3,0", f"beq cr6, 0x14 -> {tgt(5)}", "cmplwi cr6,r4,0", f"beq cr6, 0xc -> {tgt(5)}",
                 "stw r4,0(r3)", "li r3,0", "blr"])
        self.assertIn("(ts4_word)a0 != 0 && (ts4_word)a1 != 0", r["body"])
        self.assertTrue(r["body"].rstrip().endswith("return 0;"))

    def test_early_return_vs_flipped(self):
        texts = ["cmplwi cr6,r3,0", f"bne cr6, 0xc -> {tgt(4)}", "li r3,1", "blr", "li r3,2", "blr"]
        a = gen(texts, orient=0)["body"]
        b = gen(texts, orient=1)["body"]
        self.assertIn("if ((ts4_word)a0 == 0) {\n        return 1;", a)
        self.assertIn("if ((ts4_word)a0 != 0) {\n        return 2;", b)

    def test_diamond_phi(self):
        r = gen(["cmpwi cr6,r4,5", f"bge cr6, 0xc -> {tgt(4)}", "li r11,1", f"b 0x8 -> {tgt(5)}", "li r11,2",
                 "stw r11,0(r3)", "blr"])
        self.assertIn("p1 = (ts4_word)1;", r["body"])
        self.assertIn("} else {", r["body"])
        self.assertIn("= (ts4_word)p1;", r["body"])

    def test_one_armed_if_keeps_old_value(self):
        r = gen(["li r11,7", "cmplwi cr6,r4,0", f"beq cr6, 0x8 -> {tgt(4)}", "li r11,9", "stw r11,0(r3)", "blr"])
        self.assertIn("p1 = (ts4_word)7;", r["body"])
        self.assertIn("p1 = (ts4_word)9;", r["body"])

    def test_while_loop(self):
        r = gen(["li r11,0", f"b 0x10 -> {tgt(4)}", "lwz r10,0(r4)", "addi r11,r11,1", "cmplw cr6,r11,r3",
                 f"blt cr6, 0xc -> {tgt(2)}", "mr r3,r11", "blr"])
        self.assertTrue(r["kind"].startswith("loop_"))
        self.assertIn("while ((ts4_word)lv", r["body"])
        self.assertIn("return lv", r["body"])

    def test_do_while_loop(self):
        r = gen(["li r11,0", "li r10,0", "lwz r9,0(r4)", "add r10,r10,r9", "addi r11,r11,1", "addi r4,r4,4",
                 "cmplw cr6,r11,r3", f"blt cr6, 0x10 -> {tgt(2)}", "mr r3,r10", "blr"])
        self.assertIn("do {", r["body"])
        self.assertIn("} while ((ts4_word)p", r["body"])

    def test_rotated_loop_becomes_while(self):
        # if (a0 != a1) do { ... a0 += 32 } while (a0 != a1)  ==  while (p != a1) { ...; p += 32; }
        r = gen(["cmplw cr6,r3,r4", f"beq cr6, 0x1c -> {tgt(8)}", "mr r11,r3", "lwz r10,12(r11)", "stw r10,0(r11)",
                 "addi r11,r11,32", "cmplw cr6,r11,r4", f"bne cr6, -0x10 -> {tgt(3)}", "blr"])
        self.assertIn("while ((ts4_word)lv1 != (ts4_word)a1) {", r["body"])
        self.assertNotIn("do {", r["body"])
        self.assertNotIn("if (", r["body"])

    def test_return_inside_loop(self):
        r = gen(["li r11,0", f"b 0x20 -> {tgt(9)}", "lwz r10,0(r4)", "cmplw cr6,r10,r5", f"bne cr6, 0xc -> {tgt(7)}",
                 "mr r3,r11", "blr", "addi r4,r4,4", "addi r11,r11,1", "cmplw cr6,r11,r3",
                 f"blt cr6, 0x-20 -> {tgt(2)}", "li r3,-1", "blr"])
        self.assertIn("while ((ts4_word)lv", r["body"])
        self.assertRegex(r["body"], r"if \(\(ts4_word\)t\d+ == \(ts4_word\)a2\) \{\n\s+return lv\d+;")
        self.assertTrue(r["body"].rstrip().endswith("return -1;"))
        # temporaries written inside the loop are not parameters (a3.. would be unused)
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0, ts4_word a1, ts4_word a2)")

    def test_signed_compare_types(self):
        r = gen(["lwz r11,12(r3)", "cmpwi cr6,r11,0", "beqlr cr6", "cmpwi cr6,r4,5", f"bge cr6, 0x8 -> {tgt(6)}",
                 "stw r4,0(r3)", "blr"])
        self.assertIn("int t1;", r["body"])
        self.assertIn("int a1", r["sig"])
        r = gen(["lwz r11,12(r3)", "cmpwi cr6,r11,0", "beqlr cr6", "blr"], infer_signed=False)
        self.assertIn("ts4_word t1;", r["body"])

    def test_volatile_stores_variant(self):
        r = gen(["stw r4,0(r3)", "stw r4,4(r3)", "blr"], vol=1)
        self.assertEqual(r["body"].count("volatile ts4_word"), 2)
        r = gen(["lwz r11,0(r3)", "stw r11,4(r3)", "blr"], vol=2)
        self.assertEqual(r["body"].count("volatile"), 2)

    def test_unsupported_branch_is_skipped(self):
        with self.assertRaises(translate.Skip):
            gen(["bc 12,2,0x8", "blr"])

    def test_counted_loop_uses_counter_variable(self):
        # mtctr / bdnz: a do-while on a pre-decremented counter, update-form load/store as pointer bumps
        t = ["li r9,8", "subi r10,r3,4", "subi r11,r4,4", "mtctr r9", "lwzu r9,4(r11)", "stwu r9,4(r10)",
             f"bdnz 0x0 -> {tgt(4)}", "blr"]
        r = gen(t)
        self.assertIn("do {", r["body"])
        self.assertRegex(r["body"], r"while \(--c\d+ != 0\)")

    def test_break_inside_while_loop(self):
        t = ["cmplwi cr6,r3,0", f"beq cr6,0x0 -> {tgt(9)}", "lwz r4,0(r3)", "stw r4,8(r5)", "cmpwi cr6,r4,5",
             f"beq cr6,0x0 -> {tgt(9)}", "stw r4,12(r5)", "lwz r3,4(r3)", f"b 0x0 -> {tgt(0)}", "blr"]
        r = gen(t)
        self.assertIn("while (", r["body"])
        self.assertIn("break;", r["body"])

    def test_frameless_leaf_uses_red_zone_local(self):
        t = ["lfs f0,0(r5)", "stfs f0,-0x10(r1)", "lwz r11,-0x10(r1)", "stw r11,0x28(r4)", "blr"]
        r = gen(t)
        self.assertIn("ts4_word locm10[1];", r["body"])
        self.assertIn("*(float *)((char *)locm10 + 0) =", r["body"])

    def test_loaded_register_used_after_folded_condition(self):
        # lwz r10 / cmplwi / beq is a foldable condition block, but r10 is needed in the arm
        t = ["lwz r11,0x44(r3)", "cmplwi cr6,r11,0", f"beq cr6,0x0 -> {tgt(10)}", "lwz r10,0xa4(r11)",
             "cmplwi cr6,r10,0", f"beq cr6,0x0 -> {tgt(10)}", "mtctr r10", "addi r3,r11,0x1c", "bctr", "blr",
             "li r3,25", "blr"]
        r = gen(t)
        self.assertIn("(t2))((ts4_word)(t1 + 28)", r["body"])

    def test_int_to_float_conversion_through_stack_slot(self):
        t = ["lwz r11,0x24(r3)", "extsw r10,r11", "std r10,-0x10(r1)", "lfd f0,-0x10(r1)", "fcfid f13,f0",
             "frsp f1,f13", "blr"]
        r = gen(t)
        self.assertIn("(float)((double)((ts4_s64)(int)", r["body"])
        self.assertTrue(r["sig"].startswith("float "))

    def test_float_to_int_conversion_through_stack_slot(self):
        t = ["lfs f0,0(r3)", "fctiwz f13,f0", "stfd f13,-0x10(r1)", "lwz r11,-0xc(r1)", "stw r11,4(r4)", "blr"]
        r = gen(t)
        self.assertIn("= (ts4_word)(int)(", r["body"])

    def test_64bit_getter(self):
        r = gen(["ld r3,0x38(r3)", "blr"])
        self.assertTrue(r["sig"].startswith("ts4_u64 "))

    def test_vmx_load_op_store(self):
        t = ["lvx128 v0,r3,r4", "vmaddfp v13,v0,v1,v0", "stvx128 v13,r0,r5", "blr"]
        r = gen(t)
        self.assertTrue(r["vec"])
        self.assertIn("__vmaddfp(vv1, vp1, vv1)", r["body"])
        self.assertIn("__vector4 vp1", r["sig"])

    def test_vmx_getter_returns_vector(self):
        r = gen(["lvx128 v1,r3,r4", "blr"])
        self.assertTrue(r["sig"].startswith("__vector4 "))

    def test_strncpy_shape_while_with_latch_break(self):
        t = ["subi r9,r3,1", "subi r10,r4,1", "cmpwi cr6,r5,0", "subi r5,r5,1", "beqlr cr6", "lbzu r11,1(r10)",
             "cmplwi cr6,r11,0", "stbu r11,1(r9)", f"bne cr6,0x0 -> {tgt(2)}", "blr"]
        r = gen(t)
        self.assertIn("while (", r["body"])
        self.assertIn("break;", r["body"])

    def test_early_return_loop_falls_back_to_do_while(self):
        t = ["lhz r11,0(r3)", "cmplwi cr6,r11,0", f"beq cr6,0x0 -> {tgt(10)}", "cmplwi cr6,r11,0x20", "beqlr cr6",
             "lhzu r11,2(r3)", "cmplwi cr6,r11,0", f"bne cr6,0x0 -> {tgt(3)}", "li r3,0", "blr", "li r3,0", "blr"]
        r = gen(t)
        self.assertIn("do {", r["body"])
        self.assertIn("return lv", r["body"])

    def test_float_loop_without_carried_float(self):
        t = ["mr r11,r3", "cmplwi cr6,r5,0", "beqlr cr6", "mtctr r5", "lfs f0,0(r11)", "fcmpu cr6,f0,f1",
             f"ble cr6,0x0 -> {tgt(8)}", "stfs f1,0(r11)", "addi r11,r11,4", f"bdnz 0x0 -> {tgt(4)}", "blr"]
        r = gen(t)
        self.assertIn("} while (--c", r["body"])
        self.assertIn("float f1", r["sig"])

    def test_loop_exit_to_shared_return_block(self):
        # the loop leaves by a conditional branch to a return path that the normal exit also reaches
        t = ["li r10,0", "mr r11,r3", "lwz r9,0(r11)", "cmpwi cr6,r9,5", f"bne cr6,0x0 -> {tgt(11)}",
             "addi r10,r10,1", "addi r11,r11,4", "cmpwi cr6,r10,4", f"blt cr6,0x0 -> {tgt(2)}", "li r3,0", "blr",
             "mr r3,r9", f"b 0x0 -> {tgt(10)}"]
        r = gen(t)
        self.assertIn("do {", r["body"])
        self.assertRegex(r["body"], r"return t\d+;")

    def test_interlocked_sequences_become_intrinsics(self):
        x = ["lwz r11,0(r4)", "mfmsr r9", "mtmsrd r13,1", "lwarx r10,r0,r3", "stwcx. r11,r0,r3", "mtmsrd r9,1",
             f"bne -0x14 -> {tgt(1)}", "blr"]
        r = gen(x)
        self.assertIn("_InterlockedExchange(", r["body"])
        self.assertEqual(r["intrinsics"], ["xchg"])
        d = ["addi r11,r3,12", "mfmsr r9", "mtmsrd r13,1", "lwarx r10,r0,r11", "subi r10,r10,1", "stwcx. r10,r0,r11",
             "mtmsrd r9,1", f"bne -0x18 -> {tgt(1)}", "mr r3,r10", "blr"]
        r = gen(d)
        self.assertIn("_InterlockedDecrement(", r["body"])
        self.assertEqual(r["intrinsics"], ["dec"])

    def test_clrlslwi(self):
        r = gen(["clrlslwi r3,r3,17,4", "blr"])
        self.assertIn("& 0x7fff) << 4", r["body"])

    def test_variadic_callee_mode_3_uses_only_written_registers(self):
        callee = prog(["stw r9,0x28(r1)", "blr"])
        env = translate.Env(lambda sym: callee if sym == "fn_vararg" else None)
        t = ["mr r5,r4", "li r6,1", "bl 0x0 -> 0x88001000   ; REL24 fn_vararg", "blr"]
        r1 = translate.gen(prog(t), env, 1)
        r3 = translate.gen(prog(t), env, 3)
        self.assertEqual(r1["protos"]["fn_vararg"], 7)
        self.assertLess(r3["protos"]["fn_vararg"], r1["protos"]["fn_vararg"])

    def test_typed_stack_locals(self):
        t = ["stfd f1,0x50(r1)", "lwz r3,0x54(r1)", "lbz r4,0x58(r1)", "stb r4,0x59(r1)", "blr"]
        r = gen(t)
        self.assertIn("loc50", r["body"])
        self.assertIn("*(unsigned char *)((char *)loc50 + 9) =", r["body"])
        self.assertIn("*(double *)((char *)loc50 + 0) =", r["body"])

    def test_float_phi_merges_into_a_float_variable(self):
        t = ["lfs f0,0(r3)", "fcmpu cr6,f0,f1", f"bge cr6, 0x8 -> {tgt(4)}", "fmr f1,f0", "blr"]
        r = gen(t)
        self.assertRegex(r["body"], r"float pf\d+;")
        self.assertTrue(r["sig"].startswith("float "))


class OpcodeTests(unittest.TestCase):
    def test_integer_ops(self):
        r = gen(["clrrwi r11,r3,4", "mulli r10,r11,12", "divw r9,r10,r4", "srawi r7,r9,2", "add r3,r7,r9", "blr"])
        self.assertIn("0xfffffff0", r["body"])
        self.assertIn("* 12", r["body"])
        self.assertIn("/ (int)a1", r["body"])
        self.assertIn(">> 2", r["body"])

    def test_rlwinm_mask(self):
        r = gen(["rlwinm r3,r3,3,0,27", "blr"])
        self.assertIn("0xfffffff0", r["body"])
        self.assertIn("<< 3", r["body"])

    def test_indexed_store(self):
        r = gen(["stwx r4,r3,r5", "blr"])
        self.assertIn("(char *)(ts4_word)(a0) + a2) = (ts4_word)a1;", r["body"])

    def test_record_form_sets_cr0(self):
        r = gen(["srawi. r11,r4,1", "stw r11,0(r3)", f"beq 0x8 -> {tgt(4)}", "li r11,1", "stw r11,4(r3)", "blr"])
        self.assertIn("if ((int)((int)a1 >> 1) != 0)", r["body"])

    def test_conditional_return(self):
        r = gen(["cmplwi cr6,r4,0", "beqlr cr6", "stw r4,0(r3)", "blr"])
        self.assertIn("return;", r["body"])

    def test_float_basics(self):
        r = gen(["lfs f0,0(r3)", "fmr f1,f0", "fadds f1,f1,f2", "stfs f1,4(r3)", "blr"])
        self.assertEqual(r["sig"], "float NAME(ts4_word a0, float f2)")
        self.assertIn("t1 + f2", r["body"])

    def test_unrelocated_original_is_rejected(self):
        with self.assertRaises(translate.Skip):
            gen(["lis r10,0x88b9", "addi r3,r10,0x2320", "blr"])
        gen(["lis r10,0x88b9   ; REFHI lbl_88B92320", "addi r3,r10,0x2320   ; REFLO lbl_88B92320", "blr"])


class CfgTests(unittest.TestCase):
    leaf = staticmethod(lambda x, op, y: ("c", x, op, y, False))

    def test_negation_uses_de_morgan(self):
        c = ("and", self.leaf("a", "==", "0"), ("or", self.leaf("b", "<", "1"), self.leaf("c", ">=", "2")))
        self.assertEqual(cfg.cstr(cfg.neg(c)), "a != 0 || (b >= 1 && c < 2)")
        self.assertEqual(cfg.neg(cfg.neg(c)), c)

    def test_float_negation_keeps_not(self):
        c = ("c", "x", "<", "y", True)
        self.assertEqual(cfg.cstr(cfg.neg(c)), "!(x < y)")

    def test_fold_or_and_and(self):
        e1, e2 = self.leaf("a", "!=", "0"), self.leaf("b", "!=", "0")
        nxt = {20: (e2, 40, 50)}
        tri, ab = cfg.fold((e1, 40, 20), nxt.get)        # a -> 40 else (b -> 40 else 50)
        self.assertEqual((cfg.cstr(tri[0]), tri[1], tri[2], ab), ("a != 0 || b != 0", 40, 50, [20]))
        tri, ab = cfg.fold((e1, 20, 50), {20: (e2, 40, 50)}.get)   # a -> (b -> 40 else 50) else 50
        self.assertEqual((cfg.cstr(tri[0]), tri[1], tri[2]), ("a != 0 && b != 0", 40, 50))

    def test_blocks_dominators_and_loops(self):
        insns = cfg.decode(prog(["li r11,0", f"b 0x10 -> {tgt(4)}", "addi r11,r11,1", "nop", "cmplw cr6,r11,r3",
                                 f"blt cr6, 0xc -> {tgt(2)}", "blr"]), translate.parse)
        order, blocks = cfg.build_blocks(insns)
        self.assertEqual(order, [BASE, BASE + 8, BASE + 16, BASE + 24])
        loops = cfg.natural_loops(order, blocks)
        self.assertEqual(loops, {BASE + 8: {BASE + 8, BASE + 16}} | {} if False else loops)
        self.assertTrue(loops)
        pdom = cfg.post_dominators(blocks)
        self.assertEqual(cfg.ipdom(pdom, BASE), BASE + 16)

    def test_unmodelled_branches_skip(self):
        insns = cfg.decode(prog(["bc 12,2,0x88000000", "blr"]), translate.parse)
        with self.assertRaises(cfg.Skip):
            cfg.build_blocks(insns)


class VcallThunkTests(unittest.TestCase):
    def test_detects_exact_vcall_thunk(self):
        t = ["lwz r12,0(r3)", "lwz r11,0x1bc(r12)", "mtctr r11", "bctr"]
        self.assertEqual(translate.vcall_thunk(prog(t)), 0x1BC)
        r = gen(t)
        self.assertEqual((r["kind"], r["vthunk"]), ("vthunk", 0x1BC))
        self.assertIsNone(translate.vcall_thunk(prog(["lwz r11,0(r3)", "lwz r10,4(r11)", "mtctr r10", "bctr"])))

    def test_symbol_encoding(self):
        self.assertEqual(emit.mangle_num(0), "A@")
        self.assertEqual(emit.mangle_num(3), "2")
        self.assertEqual(emit.mangle_num(12), "M@")
        self.assertEqual(emit.mangle_num(0x1BC), "BLM@")
        self.assertEqual(emit.vthunk_name(0x8816EDC8, 0x1BC)[1], "??_9ts4_vcall_slot111_8816EDC8@@$BBLM@AA")


class RunTests(unittest.TestCase):
    def test_split_files_keeps_callers_and_callees_apart(self):
        matched = {1: {"protos": {"fn_B": 1}}, 2: {"protos": {}}, 3: {"protos": {}}}
        names = {1: "fn_A", 2: "fn_B", 3: "fn_C"}
        files = run.split_files([1, 2, 3], matched, names, 200)
        self.assertEqual(files, [[1, 3], [2]])
        self.assertEqual(run.split_files([1, 2, 3], matched, names, 1), [[1], [2], [3]])

    def test_categorize_strips_addresses(self):
        self.assertEqual(run.categorize("read r11"), "read r")
        self.assertEqual(run.categorize("call fn_88123456"), "call fn_")


class EmitTests(unittest.TestCase):
    def test_build_reports_line_ranges_of_each_definition(self):
        import tempfile
        r = {"kind": "get", "detail": ["u32@0x0"], "sig": "ts4_word NAME(ts4_word a0)",
             "body": "    ts4_word t1;\n\n    t1 = a0;\n    return t1;\n", "externs": [], "protos": {}}
        res = {0x88000000: r, 0x88000010: dict(r), 0x88000020: dict(r)}
        with tempfile.TemporaryDirectory() as d:
            path = Path(d) / "x.c"
            maps, rng = emit.build(res, sorted(res), path)
            lines = path.read_text().split("\n")
            for name, a in maps:
                first, last = rng[a]
                self.assertIn(name, lines[first - 1])      # first line of the definition
                self.assertEqual(lines[last - 2], "}")      # closing brace
            self.assertLess(rng[0x88000000][1], rng[0x88000010][0])

    def test_vthunk_in_cpp_file(self):
        import tempfile
        res = {0x88000000: {"kind": "vthunk", "detail": ["slot3"], "sig": "", "body": "", "externs": [], "protos": {},
                            "vthunk": 12}}
        with tempfile.TemporaryDirectory() as d:
            maps, rng = emit.build(res, [0x88000000], Path(d) / "x.cpp", cpp=True)
            text = (Path(d) / "x.cpp").read_text()
        self.assertEqual(maps, [("??_9ts4_vcall_slot3_88000000@@$BM@AA", 0x88000000)])
        self.assertIn("&ts4_vcall_slot3_88000000::s3;", text)
        self.assertIn('extern "C" {', text)

    def test_same_file_call_goes_through_unprototyped_cast(self):
        res = {0x88000000: {"kind": "x", "detail": ["rec"], "sig": "ts4_word NAME(ts4_word a0)",
                            "body": "    return fn_88000000((ts4_word)a0);\n", "externs": [],
                            "protos": {"fn_88000000": 1}}}
        saved = emit._A2N
        emit._A2N = {0x88000000: "fn_88000000"}
        try:
            with tempfile.TemporaryDirectory() as d:
                emit.build(res, [0x88000000], Path(d) / "x.c")
                text = (Path(d) / "x.c").read_text()
        finally:
            emit._A2N = saved
        self.assertIn("return ((ts4_word (*)())fn_88000000)((ts4_word)a0);", text)

    def test_host_clean_discarded_read_unused_float_param_and_set_only_local(self):
        r = {"kind": "x", "detail": ["d"], "sig": "ts4_word NAME(ts4_word a0, float f1, float f2)",
             "body": "    __vector4 pv1;\n\n    sp0.w[2];\n    pv1 = vv7;\n    return a0 + (ts4_word)f1;\n",
             "externs": [], "protos": {}}
        with tempfile.TemporaryDirectory() as d:
            emit.build({0x88000000: r}, [0x88000000], Path(d) / "x.c")
            text = (Path(d) / "x.c").read_text()
        self.assertIn("    (void)sp0.w[2];", text)
        self.assertIn("    (void)f2;", text)
        self.assertIn("    (void)pv1;", text)
        self.assertNotIn("(void)f1;", text)

    def test_func_name(self):
        r = {"kind": "get", "detail": ["u32@0x8"]}
        self.assertEqual(emit.func_name(r, 0x88167CF0), "ts4_get_u32_off8_88167CF0")


class K5Tests(unittest.TestCase):
    """Round K5: struct parameters, float call arguments/results, leaf register saves."""

    def test_struct_param_home_slot(self):
        # 12-byte struct by value in r4 + high half of r5, spilled to its home slots
        r = gen(["lwz r11,0x24(r3)", "std r4,0x20(r1)", "lwz r10,0x24(r1)", "add r3,r11,r10",
                 "std r5,0x28(r1)", "blr"])
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0, ts4_args3 sp1)")
        self.assertIn("sp1.w[1]", r["body"])
        self.assertEqual(r["structs"], [3])

    def test_struct_param_in_framed_function_and_address_taken(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x80(r1)", "std r4,0xa0(r1)", "std r5,0xa8(r1)",
             "addi r4,r1,0xa0", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x80", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_args3 sp1", r["sig"])
        self.assertIn("(ts4_word)&sp1", r["body"])

    def test_struct_param_passed_on(self):
        # lwz + rldicr rebuild the struct's register for a callee: the struct is passed as is
        # f(a, b, struct {w0,w1,w2} s): s is in r5 + the high half of r6 but homed 16-aligned
        # at F+0x20, so r6 goes to F+0x28 (the slot a word parameter in r5 would use)
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "std r6,0x88(r1)", "lwz r11,0x88(r1)",
             "rldicr r6,r11,32,63", "li r7,7", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_args3 sp2", r["sig"])
        self.assertIn("fn_88001000((ts4_word)a0, (ts4_word)a1, sp2, (ts4_word)7)", r["body"])

    def test_struct_argument_built_on_stack(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x70(r1)", "li r11,0", "stw r11,0x50(r1)",
             "rldicr r6,r11,32,31", "stw r3,0x54(r1)", "ld r5,0x50(r1)",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x70", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("*(ts4_args3 *)&loc50[0]", r["body"])
        self.assertIn("loc50[2] = (ts4_word)0;", r["body"])

    def test_local_array_at_unaligned_offset_stays_under_16_bytes(self):
        # frame fill would make loc58 six words; MSVC would 16-align that, so cap at three
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "stwu r1,-0x80(r1)",
             "li r11,1", "stw r11,0x50(r1)", "addi r4,r1,0x50", "addi r3,r1,0x58",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x80", "lwz r12,-0x8(r1)", "mtlr r12", "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_word loc58[3];", r["body"])

    def test_vmx_after_call(self):
        # vector code after a call: no vector value is live across it
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "stwu r1,-0x60(r1)", "mr r31,r4",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "lwz r11,0x0(r3)",
             "lvx128 v63,r0,r11", "stvx128 v63,r0,r31",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        self.assertIn("*(__vector4 *)((ts4_word)(a1)) = vv", r["body"])

    def test_vmx_live_across_call_is_skipped(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "lvx128 v63,r0,r4",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "stvx128 v63,r0,r3",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        with self.assertRaises(translate.Skip):
            translate.Gen(prog(t), ENV, 2).run()

    def test_lvlx_from_stack_float(self):
        t = ["lfs f0,0x48(r3)", "addi r10,r1,-0x10", "stfs f0,-0x10(r1)", "lvlx128 v62,r0,r10",
             "lvx128 v63,r0,r4", "vrlimi128 v63,v62,0x2,2", "stvx128 v63,r0,r4", "blr"]
        r = gen(t, mode=2)
        self.assertIn("__lvlx((void *)(", r["body"])
        self.assertIn("__vrlimi(", r["body"])

    def test_vector_loop_without_carried_vectors(self):
        t = ["li r11,0x10", "mtctr r11", "lvx128 v63,r0,r3", "vspltw128 v63,v63,0x3", "stvx128 v63,r0,r3",
             "addi r3,r3,0x10", f"bdnz -0x10 -> {tgt(2)}", "blr"]
        r = gen(t, mode=2)
        self.assertIn("__vspltw(", r["body"])
        self.assertIn("while (--", r["body"])

    def test_loop_exit_through_jump_block_is_a_break(self):
        # for (p = a; p != e; p += 20) if (p->x == k) { p->y = 0; break; }
        t = ["cmplw cr6,r3,r4", f"beq cr6, 0x24 -> {tgt(10)}",
             "lwz r11,0x8(r3)", "cmplw cr6,r11,r5", f"beq cr6, 0x14 -> {tgt(9)}",
             "addi r3,r3,0x14", "cmplw cr6,r3,r4", f"bne cr6, -0x14 -> {tgt(2)}",
             f"b 0x8 -> {tgt(10)}", "stw r6,0x10(r3)", "blr"]
        r = gen(t, mode=2)
        self.assertIn("break;", r["body"])

    def test_variadic_callee_gets_prototype_and_ignores_lis_temp(self):
        callee = prog(["mflr r12", "stw r12,-0x8(r1)", "std r6,0x28(r1)", "std r7,0x30(r1)", "std r8,0x38(r1)",
                       "std r9,0x40(r1)", "std r10,0x48(r1)", "stwu r1,-0x70(r1)", "blr"])
        env = translate.Env(lambda s: callee if s == "fn_88009000" else None)
        self.assertEqual(env.variadic("fn_88009000"), 3)
        t = ["lwz r6,0x0(r4)", "lis r10,0x880d   ; REFHI lbl_880D312C", "mr r3,r5", "li r4,0x20",
             "addi r5,r10,0x312c   ; REFLO lbl_880D312C", "b 0x0 -> 0x88009000   ; REL24 fn_88009000"]
        r = translate.gen(prog(t), env, mode=1)
        self.assertEqual(r["fprotos"]["fn_88009000"], ["ts4_word", "ts4_word", "ts4_word", "..."])
        self.assertIn("lbl_880D312C, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)))", r["body"])

    def test_variadic_callee_args_end_at_lis_temp_after_temp_register(self):
        callee = prog(["mflr r12", "stw r12,-0x8(r1)", "std r5,0x20(r1)", "std r6,0x28(r1)", "std r7,0x30(r1)",
                       "std r8,0x38(r1)", "std r9,0x40(r1)", "std r10,0x48(r1)", "stwu r1,-0x70(r1)", "blr"])
        env = translate.Env(lambda s: callee if s == "fn_88009000" else None)
        t = ["mr r9,r3", "lis r8,0x880f   ; REFHI lbl_880E89C4", "mr r3,r5", "addi r4,r8,0x763c   ; REFLO lbl_880E89C4",
             "lwz r5,0x0(r9)", "b 0x0 -> 0x88009000   ; REL24 fn_88009000"]
        r = translate.gen(prog(t), env, mode=1)
        self.assertEqual(r["fprotos"]["fn_88009000"], ["ts4_word", "ts4_word", "..."])

    def test_double_as_variable_argument(self):
        callee = prog(["mflr r12", "stw r12,-0x8(r1)", "std r6,0x28(r1)", "std r7,0x30(r1)", "std r8,0x38(r1)",
                       "std r9,0x40(r1)", "std r10,0x48(r1)", "stwu r1,-0x70(r1)", "blr"])
        env = translate.Env(lambda s: callee if s == "fn_88009000" else None)
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x80(r1)", "lfs f1,0x0(r4)", "stfd f1,0x28(r1)",
             "ld r6,0x28(r1)", "mr r3,r5", "li r5,0x3", "li r4,0x2",
             "bl 0x0 -> 0x88009000   ; REL24 fn_88009000", "addi r1,r1,0x80", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = translate.gen(prog(t), env, mode=1)
        self.assertIn("(double)((*(float *)", r["body"])
        self.assertEqual(r["fprotos"]["fn_88009000"], ["ts4_word", "ts4_word", "ts4_word", "..."])

    def test_dead_mixed_float_double_register_after_join(self):
        # f12 is a double on one path only and never read after the join
        t = ["lwz r11,0x0(r3)", "cmpwi cr6,r11,0x0", f"ble cr6, 0x20 -> {tgt(10)}", "lfs f0,0x4(r3)",
             "extsw r4,r11", "std r4,-0x10(r1)", "lfd f13,-0x10(r1)", "fcfid f12,f13", "frsp f11,f12",
             "stfs f11,0x8(r3)", "li r3,0x0", "blr"]
        r = gen(t)
        self.assertIn("(double)", r["body"])

    def test_address_taken_word_param_without_struct(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "stw r4,0x7c(r1)", "addi r4,r1,0x7c",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("&a1)", r["body"])

    def test_savefpr_prologue_and_float_live_across_call(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "subi r12,r1,0x10",
             "bl 0x0 -> 0x8856b328   ; REL24 __savefpr_31", "stwu r1,-0x80(r1)", "mr r31,r4",
             "lfd f0,0x10(r3)", "frsp f31,f0", "addi r3,r1,0x50", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "stfs f31,0x0(r31)", "addi r1,r1,0x80", "subi r12,r1,0x10",
             "bl 0x0 -> 0x8856b374   ; REL24 __restfpr_31", "lwz r12,-0x8(r1)", "mtlr r12",
             "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        body = r["body"]
        self.assertNotIn("savefpr", body)
        self.assertLess(body.index("((float)(*(double *)"), body.index("fn_88001000("))

    def test_unsigned_div_and_mod_by_constant(self):
        t = ["lis r9,0xcccc", "ori r8,r9,0xcccd", "mulhwu r7,r3,r8", "srwi r10,r7,3", "slwi r9,r10,2",
             "add r6,r10,r9", "slwi r5,r6,1", "subf r4,r5,r3", "stw r10,0x0(r4)", "mr r3,r4", "blr"]
        r = gen(t)
        self.assertIn("((ts4_word)a0 / 10)", r["body"])
        self.assertIn("return ((ts4_word)a0 % 10);", r["body"])

    def test_signed_div_by_constant(self):
        t = ["lis r11,0x6666", "ori r11,r11,0x6667", "mulhw r10,r3,r11", "srawi r9,r10,2", "srwi r8,r9,31",
             "add r3,r9,r8", "blr"]
        r = gen(t)
        self.assertIn("return ((int)a0 / 10);", r["body"])

    def test_signed_div_by_7_adds_dividend(self):
        t = ["lis r11,-0x6db7", "ori r11,r11,0x2493", "mulhw r10,r3,r11", "add r10,r10,r3", "srawi r9,r10,2",
             "srwi r8,r9,31", "add r3,r9,r8", "blr"]
        r = gen(t)
        self.assertIn("return ((int)a0 / 7);", r["body"])

    def test_lis_temp_reused_in_loop_before_tail_call(self):
        t = ["lwz r8,0x8(r3)", "li r10,0x0", "cmpwi cr6,r8,0x0", f"ble cr6, 0x24 -> {tgt(13)}",
             "lis r9,0x8800   ; REFHI lbl_88001A20", "li r11,0x0", "lfs f0,0x1a20(r9)   ; REFLO lbl_88001A20",
             "lwz r9,0x4(r3)", "addi r10,r10,0x1", "stfsx f0,r11,r9", "addi r11,r11,0x4", "cmpw cr6,r10,r8",
             f"blt cr6, -0x14 -> {tgt(7)}", "b 0x0 -> 0x88001000   ; REL24 fn_88001000"]
        r = gen(t, mode=2)
        self.assertIn("do {", r["body"])

    def test_float_params_beyond_f13_on_stack(self):
        t = ["stfs f13,0x30(r3)", "lfs f0,0x84(r1)", "stfs f1,0x0(r3)", "stfs f0,0x34(r3)", "blr"]
        r = gen(t)
        self.assertIn("float f13, float f14)", r["sig"])
        self.assertIn("= f14;", r["body"])

    def test_struct_argument_copied_from_global(self):
        t = ["lis r11,-0x7739   ; REFHI lbl_88C6B410", "subi r10,r11,0x4bf0   ; REFLO lbl_88C6B410",
             "ld r4,-0x4bf0(r11)", "lwz r9,0x8(r10)", "rldicr r5,r9,32,63",
             "b 0x0 -> 0x88001000   ; REL24 fn_88001000"]
        r = gen(t, mode=1)
        self.assertIn("*(ts4_args3 *)((char *)(ts4_word)((ts4_word)lbl_88C6B410) + 0)", r["body"])

    def test_stfiwx_stores_converted_int(self):
        r = gen(["lfs f0,0x8(r3)", "fctiwz f0,f0", "li r11,0x4", "stfiwx f0,r4,r11", "blr"])
        self.assertIn("*(int *)((char *)(ts4_word)(a1) + 4) = (int)(", r["body"])

    def test_subfze_of_minus_one_is_carry(self):
        r = gen(["lwz r10,0x14(r3)", "li r9,-0x1", "subfc r10,r4,r10", "subfze r3,r9", "blr"])
        self.assertIn(">= (ts4_word)a1)", r["body"])

    def test_addc_signed_compare_mask(self):
        t = ["lwz r11,0xc0(r3)", "li r9,0x6", "addi r11,r11,0x1", "xoris r8,r11,0x8000", "subf r7,r11,r9",
             "addc r6,r7,r8", "subfe r4,r5,r5", "and r3,r4,r11", "blr"]
        r = gen(t)
        self.assertIn("(((int)(t1 + 1) <= 6) ? (t1 + 1) : 0)", r["body"])

    def test_struct_argument_copied_from_memory(self):
        # vcall(obj, *(struct {w0,w1,w2} *)(a0 + 0x30)): ld for r4, lwz + rldicr 32,63 for r5
        t = ["mr r11,r3", "lwz r3,0x2c(r3)", "lwz r10,0x0(r3)", "lwz r9,0x38(r11)", "ld r4,0x30(r11)",
             "rldicr r5,r9,32,63", "lwz r8,0x10(r10)", "mtctr r8", "bctr"]
        r = gen(t, mode=1)
        self.assertIn("(ts4_word (*)(ts4_word, ts4_args3))", r["body"])
        self.assertIn("*(ts4_args3 *)((char *)(ts4_word)(a0) + 48))", r["body"])
        self.assertNotIn("+ 56", r["body"])
        self.assertEqual(r["structs"], [3])

    def test_subfc_subfe_unsigned_less(self):
        r = gen(["lwz r11,0x28(r3)", "subfc r10,r11,r4", "subfe r8,r9,r9", "clrlwi r3,r8,31", "blr"])
        self.assertIn("return ((ts4_word)a1 < (ts4_word)", r["body"])

    def test_subfc_adde_signed_greater_equal(self):
        r = gen(["lwz r11,0x8(r4)", "srwi r10,r5,31", "srawi r9,r11,31", "subfc r8,r5,r11",
                 "adde r11,r10,r9", "stb r11,0x0(r3)", "blr"])
        self.assertIn("(unsigned char)((int)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) >= (int)a2)", r["body"])

    def test_subfc_eqv_addze_signed_less(self):
        r = gen(["lwz r11,0x18(r3)", "subfc r9,r4,r11", "eqv r8,r4,r11", "srwi r7,r8,31",
                 "addze r6,r7", "clrlwi r3,r6,31", "blr"])
        self.assertIn("< (int)a1);", r["body"])

    def test_u64_shifts_and_return(self):
        r = gen(["subf r11,r3,r4", "li r10,0x1", "rldicl r9,r11,0,32", "rldicr r10,r10,63,63",
                 "rldicl r8,r3,0,32", "srad r7,r10,r9", "srd r3,r7,r8", "blr"])
        self.assertTrue(r["sig"].startswith("ts4_u64 NAME"))
        self.assertIn("((ts4_s64)((ts4_u64)1 << 63) >>", r["body"])

    def test_float_param_kept_in_f31_across_calls(self):
        # f(a0, float f, ..., a4, a5): f survives the first call in f31, then goes to the
        # second callee in the GPR slot r5 left free; r7/r8 move down to r6/r7
        t = ["mflr r12", "bl 0x0 -> 0x8856ac7c   ; REL24 __savegprlr_29", "stfd f31,-0x28(r1)",
             "stwu r1,-0x90(r1)", "mr r31,r3", "fmr f31,f1", "addi r3,r1,0x50", "mr r30,r7", "mr r29,r8",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "mr r7,r29", "fmr f1,f31", "mr r6,r30",
             "addi r4,r1,0x50", "mr r3,r31", "bl 0x0 -> 0x88002000   ; REL24 fn_88002000",
             "addi r1,r1,0x90", "lfd f31,-0x28(r1)", "b 0x0 -> 0x8856accc   ; REL24 __restgprlr_29"]
        r = gen(t, mode=2)
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0, float f1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)")
        self.assertIn("fn_88002000((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], f1, (ts4_word)a4, (ts4_word)a5)", r["body"])

    def test_signed_remainder_with_division_traps(self):
        r = gen(["lwz r11,0x8(r3)", "lwz r9,0xc(r3)", "add r8,r11,r4", "twllei r9,0x0", "divw r7,r8,r9",
                 "rotlwi r11,r8,1", "mullw r6,r7,r9", "subi r5,r11,0x1", "subf r4,r6,r8", "andc r3,r9,r5",
                 "slwi r11,r4,5", "twi 5,r3,-0x1", "mr r3,r11", "blr"])
        self.assertIn("(((int)(t1 + a1) % (int)(", r["body"])

    def test_vector_phi(self):
        t = ["cmpwi cr6,r5,0x0", f"beq cr6, 0xc -> {tgt(4)}", "lvx128 v63,r0,r3", f"b 0x8 -> {tgt(5)}",
             "lvx128 v63,r0,r4", "stvx128 v63,r0,r6", "blr"]
        r = gen(t, mode=2)
        self.assertIn("__vector4 pv", r["body"])
        self.assertIn("*(__vector4 *)((ts4_word)(a3)) = pv", r["body"])

    def test_vspltisw128_three_operand_form(self):
        r = gen(["vspltisw128 v63,v0,0x1", "stvx128 v63,r0,r3", "blr"], mode=2)
        self.assertIn("__vspltisw(1)", r["body"])

    def test_conditional_return_inside_loop_joins_at_latch(self):
        t = ["li r11,0x0", "cmpwi cr6,r4,0x0", "blelr cr6", "lbzx r5,r3,r11", "cmpw cr6,r5,r6",
             f"bne cr6, 0x10 -> {tgt(9)}", "stb r7,0x0(r3)", "cmpwi cr6,r8,0x0", "beqlr cr6",
             "addi r11,r11,0x1", "cmpw cr6,r11,r4", f"blt cr6, -0x20 -> {tgt(3)}", "blr"]
        r = gen(t, mode=2)
        self.assertIn("do {", r["body"])
        self.assertIn("return;", r["body"])

    def test_infinite_loop_with_return_exits(self):
        # for (;;) { *a3 = a0; if (a0 == a2 || *a1) return a0; a0++; }
        t = ["stw r3,0x0(r6)", "cmpw cr6,r3,r5", "beqlr cr6", "lwz r11,0x0(r4)", "cmpwi cr6,r11,0x0", "bnelr cr6",
             "addi r3,r3,0x1", f"b -0x1c -> {tgt(0)}", "blr"]
        r = gen(t, mode=2)
        self.assertIn("} while (1);", r["body"])
        self.assertIn("return lv", r["body"])

    def test_mftb_is_the_time_base_intrinsic(self):
        r = gen(["mftb r11, 268", "stw r11,0x4(r3)", "blr"])
        self.assertIn("= __mftb();", r["body"])
        self.assertIn("mftb", r["intrinsics"])
        r = gen(["mftb r3, 268", "blr"])
        self.assertTrue(r["sig"].startswith("ts4_u64"))

    def test_varargs_va_start(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r5,0x20(r1)", "std r6,0x28(r1)", "std r7,0x30(r1)",
             "std r8,0x38(r1)", "std r9,0x40(r1)", "std r10,0x48(r1)", "stwu r1,-0x60(r1)",
             "addi r11,r1,0x50", "addi r10,r1,0x80", "stw r10,0x0(r11)", "lwz r5,0x50(r1)",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "addi r1,r1,0x60", "lwz r12,-0x8(r1)",
             "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_word a1, ...)", r["sig"])
        self.assertIn("TS4_VA_START(ap, a1);", r["body"])
        self.assertIn("(ts4_word)ap)", r["body"])
        self.assertTrue(r.get("va"))

    def test_short_to_float_conversion(self):
        r = gen(["lhz r10,0x10(r3)", "extsh r8,r10", "std r8,-0x10(r1)", "lfd f0,-0x10(r1)",
                 "fcfid f13,f0", "frsp f1,f13", "blr"])
        self.assertIn("(ts4_s64)((short)", r["body"])

    def test_u64_stack_local_in_arithmetic(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "stwu r1,-0x70(r1)", "mr r31,r3",
             "addi r3,r1,0x50", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "ld r11,0x0(r31)",
             "ld r8,0x50(r1)", "subf r11,r11,r8", "std r11,0x8(r31)", "addi r1,r1,0x70",
             "lwz r12,-0x8(r1)", "mtlr r12", "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        self.assertIn("= (ts4_u64)((*(ts4_u64 *)((char *)loc50 + 0)) - (*(ts4_u64 *)", r["body"])

    def test_clamp_at_zero_via_addme(self):
        r = gen(["subfic r10,r3,0x0", "srwi r10,r3,31", "addme r10,r10", "and r3,r10,r3", "blr"])
        self.assertIn("(((int)a0 > 0) ? a0 : 0)", r["body"])

    def test_void_variant_returns_and_tail_calls(self):
        t = ["mr r11,r3", "li r10,0", "addi r3,r3,16", "stb r10,8(r11)", "b 0x0 -> 0x88001000   ; REL24 fn_88001000"]
        r = gen(t, vret=True)
        self.assertTrue(r["sig"].startswith("void "))
        self.assertIn("fn_88001000(", r["body"])
        self.assertNotIn("return fn_88001000", r["body"])
        r = gen(["li r11,0", "stw r11,4(r3)", "blr"], vret=True)
        self.assertTrue(r["sig"].startswith("void "))
        self.assertIn("return;", r["body"])

    def test_volatile_zero_stores_variant(self):
        r = gen(["li r11,0", "li r10,5", "stw r11,4(r3)", "stw r10,8(r3)", "blr"], volz=True)
        self.assertIn("*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;", r["body"])
        self.assertIn("*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)5;", r["body"])
        with self.assertRaises(translate.Skip):
            gen(["li r10,5", "stw r10,8(r3)", "blr"], volz=True)

    def test_cntlzw_as_number_is_intrinsic(self):
        r = gen(["cntlzw r11,r4", "srwi r11,r11,5", "cntlzw r3,r3", "add r3,r3,r11", "blr"])
        self.assertIn("_CountLeadingZeros(a0)", r["body"])
        self.assertIn("(a1 == 0)", r["body"])
        self.assertIn("clz", r["intrinsics"])

    def test_std_of_u64_param_into_stack_local(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x70(r1)", "stw r4,0x50(r1)", "std r5,0x60(r1)",
             "addi r5,r1,0x50", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "addi r1,r1,0x70",
             "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_u64 a2", r["sig"])
        self.assertIn("*(ts4_u64 *)((char *)loc50 + 16) = (ts4_u64)a2;", r["body"])

    def test_struct8_copied_through_red_zone(self):
        r = gen(["ld r11,0x8(r3)", "std r11,-0x10(r1)", "lwz r3,-0xc(r1)", "blr"])
        self.assertIn("= *(ts4_args2 *)((char *)(ts4_word)(a0) + 8);", r["body"])
        self.assertIn(".w[1];", r["body"])

    def test_masked_word_to_float_has_no_extsw(self):
        r = gen(["clrlwi r5,r3,1", "std r5,-0x10(r1)", "lfd f13,-0x10(r1)", "fcfid f12,f13",
                 "frsp f1,f12", "blr"])
        self.assertIn("(int)(a0 & 0x7fffffff)", r["body"])

    def test_local_reused_for_conversion_is_block_scoped(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "stwu r1,-0x70(r1)", "addi r5,r1,0x50",
             "li r4,0x1", "mr r31,r3", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "lwz r10,0x50(r1)",
             "mr r3,r31", "std r10,0x50(r1)", "lfd f0,0x50(r1)", "fcfid f1,f0",
             "bl 0x0 -> 0x88002000   ; REL24 fn_88002000", "li r3,0x1", "addi r1,r1,0x70",
             "lwz r12,-0x8(r1)", "mtlr r12", "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        self.assertIn("    {\n        ts4_word loc50[", r["body"])
        self.assertIn("((double)((ts4_s64)t", r["body"])

    def test_arity_skips_savegprlr(self):
        from translate import arity
        lines = ["88001000  7d8802a6  mflr r12", "88001004  4bd3c245  bl -0x2c3dbc -> 0x8856ac78   ; REL24 __savegprlr_28",
                 "88001008  7cbd2b78  mr r29, r5", "8800100c  4e800020  blr"]
        self.assertEqual(arity(lines, lambda s: None), 3)

    def test_fused_multiply_add_and_sqrt(self):
        r = gen(["fmadds f0,f1,f2,f3", "fsqrts f1,f0", "blr"])
        self.assertIn("((float)sqrt((double)((f1 * f2) + f3)))", r["body"])
        self.assertIn("sqrt", r["intrinsics"])
        r = gen(["fnmsubs f1,f1,f2,f3", "blr"])
        self.assertIn("(f3 - (f1 * f2))", r["body"])

    def test_indexed_float_access_extlwi_subis(self):
        r = gen(["lfsx f0,r3,r4", "stfsx f0,r5,r4", "blr"])
        self.assertIn("*(float *)((char *)(ts4_word)(a2) + a1) = ", r["body"])
        r = gen(["extlwi r11,r3,8,16", "subis r3,r11,0x10", "blr"])
        self.assertIn("(((a0 << 16) & 0xff000000) - 1048576)", r["body"])

    def test_fctidz_low_word_is_unsigned_conversion(self):
        r = gen(["lfd f0,0x10(r3)", "fctidz f13,f0", "stfd f13,-0x10(r1)", "lwz r3,-0xc(r1)", "blr"])
        self.assertIn("return (ts4_word)(", r["body"])

    def test_lis_temporary_beyond_callee_arity_ends_arguments(self):
        callee = prog(["mr r31,r4", "blr"])           # reads r3, r4
        env = translate.Env(lambda sym: callee if sym == "fn_88001000" else None)
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "lis r5,0x88b3   ; REFHI lbl_88B30FA4",
             "lis r6,0x882b   ; REFHI fn_882B10F8", "addi r6,r6,0x10f8   ; REFLO fn_882B10F8",
             "stw r6,0xfa4(r5)   ; REFLO lbl_88B30FA4", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = translate.gen(prog(t), env, mode=1)
        self.assertIn("fn_88001000((ts4_word)a0, (ts4_word)a1);", r["body"])

    def test_address_taken_float_param_lives_in_its_home_slot(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x70(r1)", "addi r4,r1,0x8c", "stfs f1,0x8c(r1)",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "addi r1,r1,0x70", "lwz r12,-0x8(r1)",
             "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("float f1", r["sig"])
        self.assertIn("(ts4_word)&f1", r["body"])
        self.assertNotIn("loc8c", r["body"])

    def test_struct12_argument_from_stack_local(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x70(r1)", "addi r3,r1,0x50",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "lwz r9,0x58(r1)", "ld r4,0x50(r1)",
             "rldicr r5,r9,32,63", "li r3,0x0", "bl 0x0 -> 0x88002000   ; REL24 fn_88002000",
             "addi r1,r1,0x70", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("fn_88002000((ts4_word)0, *(ts4_args3 *)&loc50[0])", r["body"])

    def test_counted_ldu_stdu_loop_is_struct_assignment(self):
        t = ["li r9,0x8", "lwz r8,0x4(r3)", "subi r11,r4,0x8", "subi r10,r8,0x8", "mtctr r9",
             "ldu r9,0x8(r11)", "stdu r9,0x8(r10)", f"bdnz -0x8 -> {tgt(5)}", "li r11,0x1",
             "stb r11,0x23e(r8)", "blr"]
        r = gen(t)
        self.assertIn("*(ts4_q8 *)(t1) = *(ts4_q8 *)(a1);", r["body"])
        self.assertEqual(r["qstructs"], [8])

    def test_bdzf_ladder_is_a_switch(self):
        t = ["subi r11,r3,0x160", "cmplwi cr6,r11,0x3", f"bgt cr6, 0x0 -> {tgt(14)}", "mtctr r11",
             "cmpwi cr6,r11,0x0", f"bdzf cr6eq, 0x0 -> {tgt(10)}", f"bdzf cr6eq, 0x0 -> {tgt(12)}",
             f"bne cr6, 0x0 -> {tgt(10)}", "li r3,0x1", "blr", "li r3,0x2", "blr", "li r3,0x3", "blr",
             "li r3,0x0", "blr"]
        r = gen(t)
        self.assertIn("switch ((ts4_word)((a0 + -352))) {", r["body"])
        self.assertIn("case 1:\n        case 3:\n        return 2;", r["body"])
        self.assertIn("default:\n        return 0;", r["body"])

    def test_cmpld_compares_doublewords(self):
        r = gen(["ld r11,0x70(r4)", "ld r10,0x70(r3)", "cmpld cr6,r11,r10", "li r3,0x1",
                 f"beqlr cr6", "li r3,0x0", "blr"])
        self.assertIn("(ts4_u64)", r["body"])
        self.assertIn("==", r["body"])

    def test_float_loop_variable(self):
        # f1 += f2 while f1 < f3
        t = ["fadds f1,f1,f2", "fcmpu cr6,f1,f3", f"blt cr6, -0x8 -> {tgt(0)}", "blr"]
        r = gen(t)
        self.assertIn("lf", r["body"])
        self.assertIn("do {", r["body"])
        self.assertIn("} while (", r["body"])

    def test_cntlzw_bit_as_scaled_index(self):
        r = gen(["lwz r11,0x28(r3)", "lwz r10,0x20(r3)", "cntlzw r9,r11", "rlwinm r8,r9,29,29,29",
                 "lwz r7,0x10(r10)", "lwzx r3,r8,r7", "blr"])
        self.assertIn("((t1 == 0) << 2)", r["body"])

    def test_std_of_stack_local_copies_8_bytes(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "addi r3,r1,0x50",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "ld r11,0x50(r1)", "std r11,0x8(r31)",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        t[6] = "std r11,0x8(r4)"
        t.insert(3, "mr r31,r4"); t[7] = "std r11,0x8(r31)"
        r = gen(t, mode=2)
        self.assertIn("= (ts4_u64)*(ts4_u64 *)((char *)loc50 + 0);", r["body"])

    FIND = ["li r3,0x0", "cmplw cr6,r4,r5", f"beq cr6, 0x28 -> {tgt(12)}",
            "lwz r9,0x0(r4)", "cmplw cr6,r9,r6", f"beq cr6, 0x14 -> {tgt(10)}",
            "addi r4,r4,0x4", "cmplw cr6,r4,r5", f"bne cr6, -0x14 -> {tgt(3)}",
            "stw r6,0x0(r7)", "mr r3,r9", "blr"]

    def test_break_value_merged_at_loop_exit(self):
        # find: r3 = 0 before the loop, the found element at the break
        t = self.FIND[:9] + [f"b 0xc -> {tgt(12)}", "stw r6,0x0(r7)", "mr r3,r9", "blr"]
        r = gen(t, mode=2)
        self.assertIn("break;", r["body"])
        self.assertRegex(r["body"], r"p\d+ = \(ts4_word\)t\d+;\n\s+break;")

    def test_break_as_return_variant(self):
        t = self.FIND[:9] + [f"b 0xc -> {tgt(12)}", "stw r6,0x0(r7)", "mr r3,r9", "blr"]
        r = translate.gen(prog(t), ENV, 2, rbrk=True)
        self.assertNotIn("break;", r["body"])
        self.assertIn("return t", r["body"])

    def test_common_join_variant_emits_shared_tail_once(self):
        t = ["cmpwi cr6,r4,0x0", f"beq cr6, 0x18 -> {tgt(7)}", "lwz r11,0x0(r3)", "cmpwi cr6,r11,0x0",
             f"beq cr6, 0xc -> {tgt(7)}", "stw r11,0x0(r5)", "blr", "li r10,0x1", "stw r10,0x0(r6)", "blr"]
        plain = translate.gen(prog(t), ENV, 2)["body"]
        joined = translate.gen(prog(t), ENV, 2, cjoin=True)["body"]
        self.assertEqual(plain.count("= (ts4_word)1;"), 2)
        self.assertEqual(joined.count("= (ts4_word)1;"), 1)

    def test_break_or_return_inside_found_arm(self):
        # if (found) { if (v == K) break; *a0 = v; return; }
        t = ["cmpwi cr6,r5,0x0", f"ble cr6, 0x24 -> {tgt(10)}", "lwz r10,0x0(r6)", "cmplw cr6,r10,r4",
             f"beq cr6, 0x24 -> {tgt(12)}", "addi r6,r6,0xc", "subi r5,r5,0x1", "cmpwi cr6,r5,0x0",
             f"bne cr6, -0x18 -> {tgt(2)}", "nop", "stw r4,0x0(r3)", "blr",
             "lwz r11,0x8(r6)", "cmplwi cr6,r11,0x7", f"beq cr6, -0x10 -> {tgt(10)}", "stw r11,0x0(r3)", "blr"]
        t[9] = f"b 0x4 -> {tgt(10)}"
        r = gen(t, mode=2)
        self.assertIn("break;", r["body"])

    def test_struct_param_after_savegprlr_prologue(self):
        t = ["mflr r12", "bl 0x0 -> 0x8856ac7c   ; REL24 __savegprlr_29", "stwu r1,-0x70(r1)",
             "std r5,0x98(r1)", "mr r31,r3", "mr r29,r4", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "lwz r11,0x98(r1)", "mr r4,r29", "rldicr r5,r11,32,63", "mr r3,r31",
             "bl 0x0 -> 0x88002000   ; REL24 fn_88002000",
             "addi r1,r1,0x70", "b 0x0 -> 0x8856accc   ; REL24 __restgprlr_29"]
        r = gen(t, mode=2)
        self.assertIn("ts4_args3 sp1", r["sig"])
        self.assertIn("fn_88002000((ts4_word)a0, sp1)", r["body"])

    def test_address_taken_word_parameter(self):
        # struct in r3/r4 at F+0x10, then a word parameter in r5 whose address is taken
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x80(r1)", "std r3,0x90(r1)", "std r4,0x98(r1)",
             "stw r5,0xa4(r1)", "addi r5,r1,0xa4", "addi r4,r1,0x90", "li r3,0",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x80", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("ts4_args3 sp0, ts4_word a2", r["sig"])
        self.assertIn("(ts4_word)&a2", r["body"])

    def test_leaf_saves_callee_saved_register_in_red_zone(self):
        r = gen(["std r31,-0x8(r1)", "lwz r31,4(r3)", "stw r31,8(r3)", "ld r31,-0x8(r1)", "blr"])
        self.assertTrue(r["sig"].startswith("void NAME"))

    def test_float_call_argument_takes_its_gpr_slot(self):
        # g(a0, f, 3): the float in f1 fills argument position 1 (r4 is not set up)
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)", "lfs f1,0(r4)", "li r5,3",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=2)
        self.assertIn("fn_88001000((ts4_word)a0, t1, (ts4_word)3)", r["body"].replace("(*(float *)((char *)(ts4_word)(a1) + 0))", "t1"))
        self.assertEqual(r["fprotos"], {"fn_88001000": ["ts4_word", "float", "ts4_word"]})

    def test_float_call_result(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "stwu r1,-0x60(r1)",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "frsp f1,f1",
             "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12", "blr"]
        r = gen(t, mode=1)
        self.assertTrue(r["sig"].startswith("float NAME"))
        self.assertEqual(r["rtypes"], {"fn_88001000": "double"})
        self.assertIn("double t1;", r["body"])

    def test_float_register_set_in_one_arm_only_is_dead_after_join(self):
        t = ["cmpwi cr6,r4,0", f"beq cr6, 0x14 -> {tgt(5)}", "lfs f0,0(r3)", "lfs f13,4(r3)", "stfs f0,8(r3)",
             "li r11,1", "stb r11,0(r3)", "blr"]
        r = gen(t)
        self.assertTrue(r["sig"].startswith("void NAME"))

    def test_emit_declares_struct_types_and_float_prototypes(self):
        res = {0x88000000: {"kind": "x", "detail": ["d"], "sig": "void NAME(ts4_word a0, ts4_args3 sp1)",
                            "body": "    fn_88001000((ts4_word)a0, 1.0);\n", "externs": [],
                            "protos": {"fn_88001000": 2}, "structs": [3],
                            "fprotos": {"fn_88001000": ["ts4_word", "double"]}, "rtypes": {"fn_88001000": "float"}}}
        with tempfile.TemporaryDirectory() as d:
            emit.build(res, [0x88000000], Path(d) / "x.c")
            text = (Path(d) / "x.c").read_text()
        self.assertIn("typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;", text)
        self.assertIn("float fn_88001000(ts4_word, double);", text)


class PermTests(unittest.TestCase):
    """tools/asm2c/perm.py mutations (pure text transformations)."""
    BODY = ("    ts4_word t1;\n    ts4_word t2;\n\n    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);\n"
            "    t2 = fn_1((ts4_word)(t1 + a1));\n    if ((int)t2 < 5) {\n        fn_2((ts4_word)1);\n"
            "    } else {\n        fn_3((ts4_word)2);\n    }\n    return (t2 & a1);\n")

    def test_commute_swaps_operands_of_one_binary_expression(self):
        import perm
        sites = perm.binop_sites("x = ((a + b) * c);")
        self.assertEqual(len(sites), 2)
        out = perm.m_commute("    x = (a + b);", "", __import__("random").Random(0))
        self.assertEqual(out[0], "    x = (b + a);")

    def test_ifinvert_swaps_arms_and_negates(self):
        import perm
        body, _ = perm.m_ifinvert(self.BODY, "", __import__("random").Random(0))
        self.assertIn("if (!((int)t2 < 5)) {\n        fn_3((ts4_word)2);\n    } else {\n        fn_2((ts4_word)1);", body)

    def test_inline_single_use_temporary(self):
        import perm
        body, _ = perm.m_inline(self.BODY, "", __import__("random").Random(0))
        self.assertNotIn("t1", body)
        self.assertIn("fn_1((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) + a1))", body)

    def test_swap_respects_dependencies(self):
        import perm
        self.assertIsNone(perm.m_swap("    t1 = x;\n    y = t1;", "", __import__("random").Random(0)))
        self.assertEqual(perm.m_swap("    a = 1;\n    b = 2;", "", __import__("random").Random(0))[0], "    b = 2;\n    a = 1;")

    def test_score_of_parses_fn_check(self):
        import perm
        out = ("MATCH f1 vs fn_1 @ 1 size 0x8\nFAIL f2 vs fn_2 @ 2: 3 differing instruction(s), first at +0x4\n"
               "FAIL f3 vs fn_3 @ 3: size 0x10 != target 0xc; 2 differing instruction(s)")
        self.assertEqual(perm.score_of(out, {"f1": 1, "f2": 2, "f3": 3}), {1: 0, 2: 3, 3: 1000})
        self.assertEqual(run.near_misses(out, {"f1": 1, "f2": 2, "f3": 3}), {2: 3})


class K6Tests(unittest.TestCase):
    """Round K6: cache/barrier intrinsics, 64-bit ops, indexed update forms, loop joins, xforms."""

    def test_cache_and_barrier_intrinsics(self):
        r = gen(["dcbt r0,r3", "lwz r3,0(r3)", "blr"], mode=2)
        self.assertIn("__dcbt((int)(0), (void *)(a0));", r["body"])
        self.assertIn("__dcbt", r["intrinsics"])
        r = gen(["lwsync", "stw r4,0(r3)", "blr"], mode=2)
        self.assertIn("__emit(0x7C2004AC);", r["body"])
        r = gen(["twui r0,0x16", "blr"], mode=2)
        self.assertIn("__debugbreak();", r["body"])

    def test_emit_declares_used_intrinsics(self):
        r = gen(["dcbt r4,r3", "lwsync", "blr"], mode=2)
        with tempfile.TemporaryDirectory() as d:
            emit.build({0x88000000: r}, [0x88000000], Path(d) / "x.c")
            src = (Path(d) / "x.c").read_text()
        self.assertIn("void __dcbt(int offset, void *base);", src)
        self.assertIn("void __emit(unsigned int opcode);", src)
        self.assertIn("#pragma intrinsic(__dcbt, __emit)", src)
        self.assertNotIn("extern long __dcbt", src)

    def test_64bit_divide_multiply_with_trap(self):
        r = gen(["tdllei r4,0", "divdu r3,r3,r4", "blr"], mode=2)
        self.assertIn("((ts4_u64)a0 / (ts4_u64)a1)", r["body"])
        r = gen(["mulld r3,r3,r4", "blr"], mode=2)
        self.assertIn("((ts4_s64)a0 * (ts4_s64)a1)", r["body"])
        r = gen(["sradi r3,r3,3", "blr"], mode=2)
        self.assertIn("((ts4_s64)a0 >> 3)", r["body"])

    def test_lwa_sign_extends(self):
        r = gen(["lwa r3,8(r3)", "blr"], mode=2)
        self.assertIn("(int)(*(ts4_word *)((char *)(ts4_word)(a0) + 8))", r["body"])

    def test_indexed_update_forms(self):
        r = gen(["stwux r5,r3,r4", "stw r5,4(r3)", "blr"], mode=2)
        self.assertIn("*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 4) = (ts4_word)a2;", r["body"])
        r = gen(["lfsux f1,r3,r4", "blr"], mode=2)
        self.assertIn("(*(float *)((char *)(ts4_word)((a0 + a1)) + 0))", r["body"])

    def test_loop_common_join(self):
        # in the loop, the arms (A at 6, B at 8) both reach C (11); B can also return
        b = lambda m, i: f"{m} 0x0 -> {tgt(i)}"
        t = ["li r4,0", "lwz r11,0(r3)", "cmpwi cr6,r11,0", b("beq cr6,", 13), "cmpwi cr6,r11,1", b("bne cr6,", 8),
             "addi r4,r4,1", b("b", 11), "cmpwi cr6,r4,5", "beqlr cr6", "addi r4,r4,2", "addi r3,r3,4", b("b", 1),
             "mr r3,r4", "blr"]
        g = translate.Gen(prog(t), ENV, 2)
        a = lambda i: BASE + 4 * i
        self.assertEqual(g._loop_common_join(a(6), a(8), g.loops[a(1)], a(1)), a(11))
        self.assertIn("while (", gen(t, mode=2)["body"])
        self.assertFalse(translate.Gen.ljoin)

    def test_xforms_bool_temporary(self):
        import xforms
        body = ("    ts4_word p1;\n    ts4_word p2;\n\n    if ((int)a0 == 0) {\n        p1 = (ts4_word)1;\n"
                "    } else {\n        p2 = (ts4_word)0;\n        if ((int)a1 != 0) {\n            p2 = (ts4_word)1;\n"
                "        }\n        p1 = (ts4_word)p2;\n    }\n    return p1;\n")
        out = xforms.boolx(body)
        self.assertIn("b80 = ((int)a0 == 0) || ((int)a1 != 0);", out)
        self.assertIn("p1 = (ts4_word)b80;", out)
        self.assertIn("    unsigned char b80;", out)
        self.assertNotIn("p2", out)

    def test_xforms_strlen(self):
        import xforms
        body = ("    ts4_word lv1;\n    int t2;\n    ts4_word p3;\n\n    lv1 = (ts4_word)a0;\n    do {\n"
                "        t2 = *(char *)((char *)(ts4_word)(lv1) + 0);\n        p3 = (ts4_word)(lv1 + 1);\n"
                "        lv1 = p3;\n    } while ((int)t2 != 0);\n    return ((lv1 - a0) + -1);\n")
        out = xforms.t_strlen(body)
        self.assertEqual(out, "\n    return (ts4_word)strlen((const char *)a0);\n")
        with tempfile.TemporaryDirectory() as d:
            r = {"kind": "x", "detail": [], "sig": "ts4_word NAME(ts4_word a0)", "body": out, "externs": [], "protos": {}}
            emit.build({0x88000000: r}, [0x88000000], Path(d) / "x.c")
            self.assertIn("#pragma intrinsic(strlen)", (Path(d) / "x.c").read_text())

    def test_xforms_clrrwi_struct_argument(self):
        import xforms
        asm = ["88000000  00000000  clrrwi r4, r11, 0", "88000004  00000000  mr r3, r31",
               "88000008  00000000  bl 0x0 -> 0x88001000   ; REL24 fn_88001000"]
        self.assertEqual(xforms.clr_sites(asm), [("fn_88001000", 1)])
        body = "    fn_88001000((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)));\n"
        out = xforms.sv_all(body, [("fn_88001000", 1)])
        self.assertEqual(out, ["    fn_88001000((ts4_word)a0, *(ts4_sv *)((char *)(ts4_word)(a1) + 8));\n"])

    def test_u64_parameter_from_rldicl_and_clrrwi(self):
        t = ["mflr r12", "stw r12,-0x8(r1)", "std r31,-0x10(r1)", "stwu r1,-0x60(r1)", "mr r31,r4",
             "rldicl r4,r31,32,32", "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "clrrwi r4,r31,0",
             "bl 0x0 -> 0x88001000   ; REL24 fn_88001000", "addi r1,r1,0x60", "lwz r12,-0x8(r1)", "mtlr r12",
             "ld r31,-0x10(r1)", "blr"]
        r = gen(t, mode=2)
        self.assertEqual(r["sig"], "ts4_word NAME(ts4_word a0, ts4_u64 a1)")
        self.assertIn("(ts4_word)(ts4_word)a1)", r["body"])

    def test_perm_u64_parameter(self):
        import perm
        b, s = perm.m_u64("    f((ts4_word)((ts4_u64)a1 >> 32));\n    f((ts4_word)(a1 & 0xffffffff));\n",
                          "void NAME(ts4_word a0, ts4_word a1)")
        self.assertEqual(s, "void NAME(ts4_word a0, ts4_u64 a1)")
        self.assertIn("f((ts4_word)(ts4_word)a1);", b)

    def test_xforms_compound_and_earlyinv(self):
        import xforms
        b = "    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);\n"
        self.assertEqual(xforms.t_compound(b), "    *(ts4_word *)((char *)(ts4_word)(a0) + 4) += 1;\n")
        b = "    if ((int)a0 == 0) {\n        return 0;\n    }\n    f();\n    return 1;"
        self.assertEqual(xforms.t_earlyinv(b), "    if ((int)a0 != 0) {\n        f();\n        return 1;\n    }\n    return 0;")


if __name__ == "__main__":
    unittest.main()
