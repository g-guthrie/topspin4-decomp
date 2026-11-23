# Q5 brief: port-focused decomp, single Opus agent

You are the decompilation agent for Top Spin 4. The game is for Xbox 360: Swing_DLL.xex, built with MSVC 16.00.10224 for PowerPC.
The repo is /home/user/topspin4-decomp. The owner wants a native and browser port, so only gameplay and renderer code matters here. Never work on Havok, FMOD, Bink, XDK or CRT code.

## Read first

1. AGENTS.md.
2. docs/agents/matching-brief.md.
3. docs/agents/codegen-idioms.md.
4. docs/agents/matching-tips.md. Read all of it, and above all the parts below.
   - "Skip-category recipes": clrrwi, int64, cmpld, fcfid, fsel or mfcr, and VMX are NOT blockers.
   - "Class maps".
   - "Automatic permuter".
5. The "equivalent" tier: docs/equivalence-tier.md, sections 1, 2 and 6.

## Setup

Run `export TS4_MATCHING_DIR=$PWD/work/matching-<latest>`, or the highest work/matching-bNN that has a finished log.

| Task | Command |
|---|---|
| Original asm | `python3 tools/fn_asm.py fn_X` |
| Match check | `python3 tools/fn_check.py <src> name=0xADDR [--flags ...]` |
| Match check, LTCG units | `tools/fn_check_ltcg.py ... --context src/xbox360/pp1_pool_primer.c` |
| Automatic permuter | `python3 tools/perm_auto.py <src> name=0xADDR -j 4 --time 300` |
| Equivalence check | `python3 tools/fn_equiv.py <src> name=0xADDR` |

- Use the automatic permuter for misses that are only scheduling or register order.
- The equivalence check runs the original and your C side by side.
- config/54540859/vtables.json gives each virtual function's class siblings and constructor. Use it to type `this`.
- Names and fields are in docs/gameplay/*.md, docs/renderer-map.md, src/xbox360/drafts/ and ref/gameplay/*.c.

## Owner decision (2026-11-23): byte-exact only

**No new equivalent functions.** A function is solved only when it byte-matches (fn_check or fn_check_ltcg says
MATCH). The equivalent tier is closed: the 116 functions already in config/54540859/equivalent.json stay registered
but are work still owed (reports/byte_exact_backlog.md), not finished work. Do not run fn_equiv to finish a
function, do not write eq_* files, do not write `"route": "equiv"` specs. Where older text below mentions the
equivalent route, this section overrides it.

When a match stalls: keep the best attempt as a draft in src/xbox360/drafts/<stem>_nearmiss.c with a
`/* nearmiss: N off (perm best M); blocker */` comment, record it in docs/agents/q5/escalate.json, and move on.
Escalated functions go to a stronger solver for a byte match, never to equivalence.

## Work list

The list is docs/agents/q5/worklist.txt.

**Phase A: one function per sister group, smallest first.** Every function in a group has the same instruction shape.
- When you MATCH a representative, append an entry to docs/agents/q5/templates.json, a JSON list:
  `{"template": "<name>", "addr": "0x...", "source": "src/xbox360/q5_<topic>.c", "flags": [...], "ltcg": false, "sisters": ["0x...", ...], "notes": "what differs between sisters: offsets, constants, callees"}`.
- Haiku agents clone the sisters from those entries. Don't do the sisters yourself.

**Phase B: the remaining gameplay, then renderer, functions.**

**Owner rule: every function on the list gets solved.** No one comes after you. Nothing is skipped, parked, or left "almost solved".

A function counts as solved only when it MATCHES: fn_check (or fn_check_ltcg) passes.

Work each function like this:

1. Work towards MATCH with the recipes, the permuter, and probes of the compiler.
2. If MATCH stalls, try the big levers: decompile the callees first (under LTCG their bodies change this function's codegen), different source structure, C++ instead of C, LTCG contexts, compiler probes.
3. The one exception to finishing is **escalation**: you have done all of the above and made no progress for about 45 minutes.
   - Save the best attempt as a near-miss draft (see the owner decision above).
   - Append it to docs/agents/q5/escalate.json, a JSON list: `{"addr": "0x...", "name": "...", "best_source": "<path to your best attempt>", "state": "N off, first divergence", "tried": "what you tried"}`.
   - Then continue with the next function. The main session hands escalated functions to a stronger solver, so they still get solved.

If a function looks impossible for a tooling reason, report it to main in your hand-in with the evidence, so the tool gets fixed and you can finish the function. Examples: fn_equiv cannot model a hardware register, or an instruction is not decoded.

## Output

**Matched sources.** Put them in src/xbox360/q5_<topic>.c, grouped by what the code does. Each needs a spec at work/specs/Q5/<stem>.json in the same format as the other specs, listing only functions that MATCH.

**Open functions.** There is no failure list. If a function is still open when you hand in, list it in the report with its exact state. You resume it first next time.

## Rules

- **No shortcuts.** No stand-in callee stubs, no knowingly false prototypes, no volatile hacks.
- **No duplicate work.** Before writing a function, grep src/ for its address.
- **Host syntax.**
  - .c files must pass `cc -std=c11 -Wall -Wextra -Werror -Wno-deprecated-non-prototype -fsyntax-only -Isrc/xbox360`.
  - .cpp files must pass `c++ -fsyntax-only -Isrc/xbox360`.
- **Files and git.**
  - Don't run tools/matching.py.
  - Don't commit.
  - Don't edit shared headers except by adding new ones.
  - Never put game data in the repo.
- **Honesty.** A function is matched only if fn_check says so, and nothing else counts.

## Hand-ins and report

**Hand-ins.** About every 90 minutes, or whenever you have added 5 or more template entries, stop and return a progress report. The main session integrates, starts the Haiku cloners and resumes you. Each report gives:
- the spec files ready;
- the counts and bytes matched;
- the template entries you added;
- any new codegen rule worth adding to matching-tips.md.

## Owner decisions (2026-11-22)

- Two Opus agents now share section 2. **Opus A** works from the small end (ascending size, the file order).
  **Opus B** works from the large end (descending size). Before starting a function, claim it atomically:
  `mkdir work/q5/claims/0xADDR` (lowercase hex as in worklist.txt). If mkdir fails, someone has it: skip it.
  Also skip anything already in config/54540859/match.json or equivalent.json.
- (Superseded 2026-11-23: no equivalent route for any size. Large functions are byte-matched too, callees first.)
- Use separate file stems: Opus A `eq_q5a_*` / `q5a_*`, Opus B `eq_q5b_*` / `q5b_*`.

## Since 2026-11-22 (pause notes)

- Pick work with `python3 tools/q5_status.py --next 10` (small end) or `--from-end` (large end); it skips solved, escalated and claimed functions.
- Large unfinished functions have hand-over notes in docs/agents/q5/notes/ and skeleton drafts in src/xbox360/drafts/q5b_*_wip.c. Start there.
- Known duplicates already reconstructed in other files (do not redo): 0x886cb8d0, 0x88660940, 0x8866c1a8, 0x886dc7a8.
- Hand in before your context runs low; a fresh agent from this brief is cheaper than a long one.
