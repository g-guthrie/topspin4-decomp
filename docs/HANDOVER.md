# Handover: cloud session to the local agent (2026-11-14)

This note hands the whole project to an agent running on the owner's own computer, which has a real
graphics card, the game files and an emulator. Read it first, then the documents it points to.
`docs/START_HERE.md` is older and its percentages are stale; where they disagree, this note wins.

## 1. What the owner wants

A build of Top Spin 4 that feels identical to the original, with the owner's gameplay retune, running
natively with no emulator and eventually in a web browser. Players supply their own copy of the
game; nothing from the game is committed or distributed (`AGENTS.md`).

Standing owner decisions:

* Animations are not edited. No clip is stretched, sped up, mirrored or re-authored.
* The aim system stays: direction-only stick, nested target boxes, the aim score.
* Movement stays as retail, except: the net rush is buffered instead of refused and needs no sprint
  button; the freeze before the opponent's hit is lifted at the net; the feet are freed earlier after
  volleys and after a groundstroke when heading to the net. The slow first step from rest is left
  alone for now and tried last, as an isolated experiment.
* The fastest forehand is 110 mph, reached almost never. Serves reach about 150 for a specialist.
  Averages stay about where retail has them.
* No new player ratings. Every change maps onto something the engine has, or is a labelled code change.
* Port first, with decomp where the port needs it. Full byte-matching is a background goal.
* Revision 3 of the plan is conservative: aiming and movement are not changed at all. The net-movement
  changes listed above are parked as an optional later pack (`docs/design/retune-plan.html`, "Parked").

## 2. Where each track stands

| Track | State | Read |
|---|---|---|
| Gameplay understanding | Done as far as code reading goes. About 24 checks need the running game. | `docs/gameplay/GAMEPLAY.md`, `TUNING.md`, `OPEN.md` (section 11 = runtime checks R1-R24), `symbols.md` |
| Retune design | Structure fixed. Numbers tuned by simulation over three runs; the spec ends with a "State at handover" section (what the model shows, what is reliable, starting values, what to check first on the real game). Nothing is implemented in the game. | `docs/design/retune-systems.md` (authority for structure), `retune-spec.md` (numbers), `retune-baseline.md` (measured retail) |
| Retune plan for the owner | Published page, revision 2 with later edits; the page source is committed. The design notes above are the record where they differ. | `docs/design/retune-plan.html` |
| Data-only patch set | Cancelled by the owner, who is applying data changes to their own copy locally. A nearly complete draft (grouped patch files and an apply script) was removed from the tree; it is in history at commit `38e12fd` (`tuning/retune-v0/`, `tools/apply_retune.py`) if wanted. | `docs/data-patching.md` |
| Native build | All three modules translate and compile. A scripted, headless run boots through the logos and title screen, reaches the practice ground (court, net, ball machine and player drawn; the player renders as a black silhouette) and then the main menu (scene S4MainMenu). No match yet. The earlier black frames were a host render-target problem on the software renderer, fixed by running with `--render_target_path_vulkan=fsi`. | `docs/recomp-feasibility.md`, `docs/recomp-build.md`, `tools/recomp/` |
| Renderer and front end | Mapped for the port. | `docs/renderer-map.md` (frame order, hand-over, ranked causes of black frames, checks C1-C9), `docs/frontend-map.md` (waits before the menu, how a match starts, pointer chains to ball and players) |
| Byte-matching | 31,937 functions, 3,163,492 of 10,154,036 bytes (31.16%), build b85. Cloud ranges (gameplay 0x88640000-0x886E8000, ball 0x889C0000-0x889C3000) are about 19% matched; the codegen rules found there are at the end of `docs/agents/matching-tips.md`, with notes per rule in `docs/agents/near-misses/`. Small-function re-sweep lists W11_list5-10 were interrupted by the weekly limit (lists 9 and 10 not started). | `docs/decomp-remaining.md`, `docs/ltcg-route.md`, `docs/agents/matching-tips.md`, `docs/agents/near-misses/` |
| Equivalence tier | Checker built and validated. | `docs/equivalence-tier.md` (section 9 = status of the gameplay functions the retune must modify) |

## 3. What to do first on the owner's machine

1. **Build the native game with a real GPU** by following `docs/recomp-build.md`. The cloud container
   had no GPU and drew in software at about 1 frame a second; several workarounds there (offscreen
   swapchain, synchronous shader compile, drawing only every Nth frame) exist only for that reason.
   In the cloud container the black frames turned out to be the host's default render-target path:
   the game reuses one EDRAM base for targets of different pitch and MSAA, and ownership transfers
   between them zeroed the back-buffer copy. `--render_target_path_vulkan=fsi` fixed it there. On a
   real GPU, check whether the default path works or the same flag is needed, and look at the player
   rendering as a black silhouette on the practice ground (`docs/renderer-map.md` lists the draw
   paths and formats to check).
2. **Reach a match.** After START the game is on the practice ground (engine state 4 there is normal,
   not a hang). START again opens the main menu. `docs/frontend-map.md` gives the pad script to an
   exhibition match and an untested direct call. Gate each press on the scene-name watch.
3. (Data changes on the original game are being done by the owner locally; nothing to do here.)
4. **Run the runtime checks** in `docs/gameplay/OPEN.md` section 11 and write the results there.

## 4. The retune, in one paragraph

Each shot answers two questions: how good was the situation (a grade, six rows, with Tee-off on top)
and how well was it executed (timing inside a window). The grade is per shot family: rally
groundstrokes use a penalty score from time set, contact height and incoming pace; returns of serve
are Good by default and are not graded by pace; serves have no grade; volleys are judged against the
net and produce weak balls before errors; smashes ignore height. The window is one scale, the product
of the stroke's rating, the opponent's timing grade (its own input), the grade and reaction time,
kept between 60% and 175% of retail. A power swing is a commitment; an overcharge (10 frames past a
full meter, standing still) is the biggest swing. The put-away becomes how the top grades look.
Shot type scales the grade's effect: flat 100%, topspin 80%, slice and lob 50%.

Open at handover: in the final simulation run the slicer is narrowly the best style and heavy
topspin the weakest (first adjustment to try, untested: slice share of the grade effect from 50%
toward 60-70%, topspin from 80% to 90%); the serve specialist holds about 80% against a 90% target; grade selection `fn_886629C8` now has C proven equivalent, but the timing value `fn_8867DF68` (where the
window scale goes) is typed C that is unverified until a trace comparison runs on the native build
(plan in `docs/agents/near-misses/RT1.failed.md`); whether the grade is known before the swing
commits is unconfirmed.

## 5. What needs code, and how it will be done

Data changes go in through the patch tools. Code changes replace individual functions in the native
build (each translated function can be overridden) or patch the original for emulator testing. The
functions and their status are in `docs/equivalence-tier.md` section 9. Three of them (timing value,
outcome roll, bounce) use vector instructions the equivalence checker cannot run, so they need a
trace comparison on the native build.

## 6. Working rules that have mattered

* Never commit game files, generated translated code, rebuilt archives or keys. Readable value dumps
  go under `data/gameplay/` only, each with its generating command and source sha256. Run
  `python3 tools/check_no_game_data.py` before every commit.
* A function is "matched" only if the matching build says so; "equivalent" is a separate tier and the
  two numbers are never merged.
* After integrating matches, check the integrate step's exit code before anything else runs; a failed
  integrate followed by a commit has happened twice.
* The renaming step breaks files that call one of their own functions through the old placeholder
  name: fix the prototype and mark the callee non-inlinable.
* Game code was built with `/GL` + `/LTCG`, `/Oc` and `/fp:precise`. Middleware was not.
* Simulation results are reliable for direction and rough size, not for match-level balance.

## 7. Things only in the cloud session's scratch space

These are not in the repo and will be lost when the cloud container is reclaimed, unless regenerated:

* `work/recomp/` : the patched recompiler and runtime builds, generated C++ for the three modules,
  run logs and captured frames. All reproducible from `docs/recomp-build.md`.
* `work/t1/gen/` : the translator's C for 7,841 unmatched functions (`tools/asm2c/generate.py`
  regenerates it in about two hours).
* `work/eq1/` : equivalence checker results (summarised in `docs/equivalence-tier.md`).
* `work/specs/` : per-agent match specs for everything already integrated.
* `work/army/*-nearmiss/`, `work/army/*_scratch/` : near-miss sources. The notes are in
  `docs/agents/near-misses/`; the source files themselves are not committed.
