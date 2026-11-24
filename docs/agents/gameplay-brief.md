# Gameplay decompilation brief (adds to docs/agents/matching-brief.md)

The user's priority: extract Top Spin 4's gameplay (ball physics, shots, reach/interception,
volleys, swing planning, rules) as readable, correct C so it can later be ported to other
platforms. Read docs/gameplay-map.md for the subsystem map and your work package.

Rules on top of AGENT_BRIEF.md:
- Goal 1: byte-exact matches via tools/fn_check.py (same spec workflow, specs in your
  work/specs/<FAMILY>/ dir). Matching proves correctness.
- Goal 2: for functions you understand but cannot get to match within reasonable effort,
  write a readable C draft to src/xbox360/drafts/<prefix>_<topic>.c (not compiled into the
  matching build) with the original address, a behaviour summary, and what differs. Drafts
  must still reflect the real logic; mark uncertain parts with `/* ? */`.
- Name functions, struct fields and parameters by gameplay meaning when evidence supports
  it (strings, XData paths, call context); otherwise by role. Keep evidence in comments.
- Put shared struct/type definitions for your package in src/xbox360/<prefix>_types.h.
- tools/fn_asm.py now decodes VMX128 vector instructions (lvx128, vmaddfp128, ...); the
  compiler emits those from __vector4 intrinsics. Vector-heavy functions are hard to match:
  prioritize understanding + drafts for them.
- Also append findings (structs, field meanings, call chains, per-frame order, data file
  dependencies) to work/gameplay-notes/<prefix>.md so they can be merged into
  docs/gameplay-map.md later.
- Final report: matched functions/bytes, drafts written, key gameplay facts learned.
