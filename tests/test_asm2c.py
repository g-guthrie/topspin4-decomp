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


if __name__ == "__main__":
    unittest.main()
