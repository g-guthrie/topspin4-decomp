# RC2: tests for the instruction forms added to XenonRecomp (tools/recomp/patches).
# Xenia test format. Vector registers are written [element0, element1, element2, element3]
# (element 0 = most significant word in memory order). Expected values are worked by hand
# from the PowerPC AS / AltiVec / VMX128 definitions; CR results are read back with mfcr or
# mfocrf because the XenonRecomp test mode does not compare CR fields directly.

# ---- CTR branches with a CR condition
test_bdzf_taken:
  #_ REGISTER_IN r4 1
  mtctr r4
  cmpwi cr6, r4, 5
  li r3, 1
  bdzf 4*cr6+eq, 1f
  li r3, 2
1:
  mfctr r5
  blr
  #_ REGISTER_OUT r3 1
  #_ REGISTER_OUT r5 0

test_bdzf_ctr_nonzero:
  #_ REGISTER_IN r4 2
  mtctr r4
  cmpwi cr6, r4, 5
  li r3, 1
  bdzf 4*cr6+eq, 1f
  li r3, 2
1:
  mfctr r5
  blr
  #_ REGISTER_OUT r3 2
  #_ REGISTER_OUT r5 1

test_bdzf_cond_true:
  #_ REGISTER_IN r4 1
  mtctr r4
  cmpwi cr6, r4, 1
  li r3, 1
  bdzf 4*cr6+eq, 1f
  li r3, 2
1:
  blr
  #_ REGISTER_OUT r3 2

test_bdnzt_taken:
  #_ REGISTER_IN r4 2
  mtctr r4
  cmpwi cr1, r4, 5
  li r3, 1
  bdnzt 4*cr1+lt, 1f
  li r3, 2
1:
  blr
  #_ REGISTER_OUT r3 1

test_bdnzf_gt_bit:
  #_ REGISTER_IN r4 2
  mtctr r4
  cmpwi cr1, r4, 5
  li r3, 1
  bdnzf 4*cr1+gt, 1f
  li r3, 2
1:
  blr
  #_ REGISTER_OUT r3 1

test_bdnzf_lt_bit_not_taken:
  #_ REGISTER_IN r4 2
  mtctr r4
  cmpwi cr1, r4, 5
  li r3, 1
  bdnzf 4*cr1+lt, 1f
  li r3, 2
1:
  blr
  #_ REGISTER_OUT r3 2

# ---- loads and stores with update
test_lhzu:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  lhzu r3, 2(r4)
  blr
  #_ REGISTER_OUT r3 0x3344
  #_ REGISTER_OUT r4 0x10001002

test_lhzux:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 4
  lhzux r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x5566
  #_ REGISTER_OUT r4 0x10001004

test_lhau:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  lhau r3, 8(r4)
  blr
  #_ REGISTER_OUT r3 0xFFFFFFFFFFFF8001
  #_ REGISTER_OUT r4 0x10001008

test_lhaux:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001004
  #_ REGISTER_IN r5 4
  lhaux r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0xFFFFFFFFFFFF8001
  #_ REGISTER_OUT r4 0x10001008

test_lbzux:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 3
  lbzux r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x44
  #_ REGISTER_OUT r4 0x10001003

test_lwzux:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 4
  lwzux r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x55667788
  #_ REGISTER_OUT r4 0x10001004

test_ldux:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10000ff8
  #_ REGISTER_IN r5 8
  ldux r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x1122334455667788
  #_ REGISTER_OUT r4 0x10001000

test_lfsu:
  #_ MEMORY_IN 10001000 3f c0 00 00 40 20 00 00 3f f8 00 00 00 00 00 00
  #_ REGISTER_IN r4 0x10000ffc
  lfsu f1, 4(r4)
  blr
  #_ REGISTER_OUT f1 1.5
  #_ REGISTER_OUT r4 0x10001000

test_lfsux:
  #_ MEMORY_IN 10001000 3f c0 00 00 40 20 00 00 3f f8 00 00 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 4
  lfsux f1, r4, r5
  blr
  #_ REGISTER_OUT f1 2.5
  #_ REGISTER_OUT r4 0x10001004

test_lfdu:
  #_ MEMORY_IN 10001000 3f c0 00 00 40 20 00 00 3f f8 00 00 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  lfdu f1, 8(r4)
  blr
  #_ REGISTER_OUT f1 1.5
  #_ REGISTER_OUT r4 0x10001008

test_lfdux:
  #_ MEMORY_IN 10001000 3f c0 00 00 40 20 00 00 3f f8 00 00 00 00 00 00
  #_ REGISTER_IN r4 0x10001004
  #_ REGISTER_IN r5 4
  lfdux f1, r4, r5
  blr
  #_ REGISTER_OUT f1 1.5
  #_ REGISTER_OUT r4 0x10001008

test_sthu:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN r3 0x1234ABCD
  #_ REGISTER_IN r4 0x10001000
  sthu r3, 2(r4)
  blr
  #_ REGISTER_OUT r4 0x10001002
  #_ MEMORY_OUT 10001000 CCCCABCD CCCCCCCC CCCCCCCC CCCCCCCC

test_sthux:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN r3 0x1234ABCD
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 6
  sthux r3, r4, r5
  blr
  #_ REGISTER_OUT r4 0x10001006
  #_ MEMORY_OUT 10001000 CCCCCCCC CCCCABCD CCCCCCCC CCCCCCCC

test_stbux:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN r3 0x12345678
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 1
  stbux r3, r4, r5
  blr
  #_ REGISTER_OUT r4 0x10001001
  #_ MEMORY_OUT 10001000 CC78CCCC CCCCCCCC CCCCCCCC CCCCCCCC

test_stdux:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN r3 0x0102030405060708
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 8
  stdux r3, r4, r5
  blr
  #_ REGISTER_OUT r4 0x10001008
  #_ MEMORY_OUT 10001000 CCCCCCCC CCCCCCCC 01020304 05060708

test_stfsu:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN f1 2.0
  #_ REGISTER_IN r4 0x10001000
  stfsu f1, 4(r4)
  blr
  #_ REGISTER_OUT r4 0x10001004
  #_ MEMORY_OUT 10001000 CCCCCCCC 40000000 CCCCCCCC CCCCCCCC

test_stfsux:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN f1 -1.5
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 12
  stfsux f1, r4, r5
  blr
  #_ REGISTER_OUT r4 0x1000100c
  #_ MEMORY_OUT 10001000 CCCCCCCC CCCCCCCC CCCCCCCC BFC00000

test_stfdu:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN f1 1.5
  #_ REGISTER_IN r4 0x10000ff8
  stfdu f1, 8(r4)
  blr
  #_ REGISTER_OUT r4 0x10001000
  #_ MEMORY_OUT 10001000 3FF80000 00000000 CCCCCCCC CCCCCCCC

test_stfdux:
  #_ MEMORY_IN 10001000 cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc cc
  #_ REGISTER_IN f1 1.5
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 8
  stfdux f1, r4, r5
  blr
  #_ REGISTER_OUT r4 0x10001008
  #_ MEMORY_OUT 10001000 CCCCCCCC CCCCCCCC 3FF80000 00000000

test_lhbrx:
  #_ MEMORY_IN 10001000 11 22 33 44 55 66 77 88 80 01 3f c0 00 00 00 00
  #_ REGISTER_IN r4 0x10001000
  #_ REGISTER_IN r5 2
  lhbrx r3, r4, r5
  blr
  #_ REGISTER_OUT r3 0x4433

# ---- condition register logic, mtcrf / mtocrf / mfocrf
test_cror:
  #_ REGISTER_IN r4 0x80000020
  mtcrf 0xff, r4
  cror 4*cr1+eq, lt, 4*cr6+eq
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x82000020

test_crorc:
  #_ REGISTER_IN r4 0
  mtcrf 0xff, r4
  crorc 4*cr1+eq, 4*cr1+eq, 4*cr5+lt
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x02000000

test_crand_crandc_crxor:
  #_ REGISTER_IN r4 0xC0000000
  mtcrf 0xff, r4
  crand 4*cr2+lt, lt, gt
  crandc 4*cr2+gt, lt, 4*cr7+so
  crxor 4*cr2+eq, lt, gt
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0xC0C00000

test_crnor_creqv_crnand:
  #_ REGISTER_IN r4 0x80000000
  mtcrf 0xff, r4
  crnor 4*cr3+lt, gt, eq
  creqv 4*cr3+gt, lt, gt
  crnand 4*cr3+eq, lt, lt
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x80080000

test_crset_crclr_crnot_crmove:
  #_ REGISTER_IN r4 0x0000000F
  mtcrf 0xff, r4
  crset 4*cr4+lt
  crclr 4*cr7+lt
  crnot 4*cr4+gt, 4*cr7+gt
  crmove 4*cr4+eq, 4*cr7+eq
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x0000A007

test_mtcrf_one_field:
  #_ REGISTER_IN r4 0
  #_ REGISTER_IN r5 0xFFFFFFFF
  mtcrf 0xff, r4
  mtcrf 0x02, r5
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x000000F0

test_mtocrf:
  #_ REGISTER_IN r4 0
  #_ REGISTER_IN r5 0xFFFFFFFF
  mtcrf 0xff, r4
  mtocrf 0x40, r5
  mfcr r3
  blr
  #_ REGISTER_OUT r3 0x0F000000

test_mfocrf_cr6:
  #_ REGISTER_IN r4 0xA50000A0
  mtcrf 0xff, r4
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0xA0

test_mfocrf_cr0:
  #_ REGISTER_IN r4 0xA50000A0
  mtcrf 0xff, r4
  mfocrf r3, 0x80
  blr
  #_ REGISTER_OUT r3 0xA0000000

# ---- VMX / VMX128
test_vcmpbfp128:
  #_ REGISTER_IN v4 [3F800000, C0400000, 40A00000, 7FC00000]
  #_ REGISTER_IN v5 [40000000, 40000000, 40000000, 40000000]
  vcmpbfp128 v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [00000000, 40000000, 80000000, C0000000]

test_vcmpbfp128_rc_out:
  #_ REGISTER_IN v4 [3F800000, C0400000, 40A00000, 7FC00000]
  #_ REGISTER_IN v5 [40000000, 40000000, 40000000, 40000000]
  vcmpbfp128. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT v3 [00000000, 40000000, 80000000, C0000000]

test_vcmpbfp128_rc_in:
  #_ REGISTER_IN v4 [3F800000, C0000000, 40000000, 80000000]
  #_ REGISTER_IN v5 [40000000, 40000000, 40000000, 40000000]
  vcmpbfp128. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0x20
  #_ REGISTER_OUT v3 [00000000, 00000000, 00000000, 00000000]

test_vcmpbfp:
  #_ REGISTER_IN v4 [3F800000, C0400000, 40A00000, 7FC00000]
  #_ REGISTER_IN v5 [40000000, 40000000, 40000000, 40000000]
  vcmpbfp v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [00000000, 40000000, 80000000, C0000000]

test_vsel128:
  #_ REGISTER_IN v3 [FFFFFFFF, 00000000, FF00FF00, 0F0F0F0F]
  #_ REGISTER_IN v4 [11111111, 11111111, 11111111, 11111111]
  #_ REGISTER_IN v5 [22222222, 22222222, 22222222, 22222222]
  vsel128 v3, v4, v5, v3
  blr
  #_ REGISTER_OUT v3 [22222222, 11111111, 22112211, 12121212]

test_vcfpuxws128:
  #_ REGISTER_IN v4 [3FC00000, BF800000, 4F000000, 7FC00000]
  vcfpuxws128 v3, v4, 1
  blr
  #_ REGISTER_OUT v3 [00000003, 00000000, FFFFFFFF, 00000000]

test_vaddsws:
  #_ REGISTER_IN v4 [7FFFFFFF, 80000000, 00000001, FFFFFFFB]
  #_ REGISTER_IN v5 [00000001, FFFFFFFF, 00000002, 00000003]
  vaddsws v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [7FFFFFFF, 80000000, 00000003, FFFFFFFE]

test_vaddsbs:
  #_ REGISTER_IN v4 [7F80017F, 00000000, 00000000, 00000000]
  #_ REGISTER_IN v5 [01FF0101, 00000000, 00000000, 00000000]
  vaddsbs v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [7F80027F, 00000000, 00000000, 00000000]

test_vsububm:
  #_ REGISTER_IN v4 [00010203, 00000000, 00000000, 00000000]
  #_ REGISTER_IN v5 [01010101, 00000000, 00000000, 00000000]
  vsububm v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [FF000102, 00000000, 00000000, 00000000]

test_vsubuwm:
  #_ REGISTER_IN v4 [00000000, 00000005, 00000000, 00000000]
  #_ REGISTER_IN v5 [00000001, 00000003, 00000000, 00000000]
  vsubuwm v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [FFFFFFFF, 00000002, 00000000, 00000000]

test_vminub:
  #_ REGISTER_IN v4 [00FF7F80, 00000000, 00000000, 00000000]
  #_ REGISTER_IN v5 [80808080, 00000000, 00000000, 00000000]
  vminub v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [00807F80, 00000000, 00000000, 00000000]

test_vmaxub:
  #_ REGISTER_IN v4 [00FF7F80, 00000000, 00000000, 00000000]
  #_ REGISTER_IN v5 [80808080, 00000000, 00000000, 00000000]
  vmaxub v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [80FF8080, 00000000, 00000000, 00000000]

test_vcmpgtsh_rc:
  #_ REGISTER_IN v4 [0001FFFF, 80007FFF, 00000000, 00000000]
  #_ REGISTER_IN v5 [00000000, 00000000, 00000000, 00000000]
  vcmpgtsh. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT v3 [FFFF0000, 0000FFFF, 00000000, 00000000]

test_vcmpgtsw_rc_all:
  #_ REGISTER_IN v4 [00000001, 00000002, 00000003, 7FFFFFFF]
  #_ REGISTER_IN v5 [00000000, 00000000, 80000000, 00000000]
  vcmpgtsw. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0x80
  #_ REGISTER_OUT v3 [FFFFFFFF, FFFFFFFF, FFFFFFFF, FFFFFFFF]

test_vcmpequh_rc_none:
  #_ REGISTER_IN v4 [00010002, 00030004, 00050006, 00070008]
  #_ REGISTER_IN v5 [00000000, 00000000, 00000000, 00000000]
  vcmpequh. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0x20
  #_ REGISTER_OUT v3 [00000000, 00000000, 00000000, 00000000]

test_vcmpgtuh_rc:
  #_ REGISTER_IN v4 [FFFF0000, FFFF0000, FFFF0000, FFFF0000]
  #_ REGISTER_IN v5 [00010000, 00010000, 00010000, 00010000]
  vcmpgtuh. v3, v4, v5
  mfocrf r3, 0x02
  blr
  #_ REGISTER_OUT r3 0
  #_ REGISTER_OUT v3 [FFFF0000, FFFF0000, FFFF0000, FFFF0000]

test_vsrab:
  #_ REGISTER_IN v4 [807F40FF, 00000000, 00000000, 00000000]
  #_ REGISTER_IN v5 [01010709, 00000000, 00000000, 00000000]
  vsrab v3, v4, v5
  blr
  #_ REGISTER_OUT v3 [C03F00FF, 00000000, 00000000, 00000000]
