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

## 2. Where each track stands

| Track | State | Read |
|---|---|---|
| Gameplay understanding | Done as far as code reading goes. About 24 checks need the running game. | `docs/gameplay/GAMEPLAY.md`, `TUNING.md`, `OPEN.md` (section 11 = runtime checks R1-R24), `symbols.md` |
| Retune design | Structure fixed. Numbers tuned by simulation; a balance re-run was in progress at handover. Nothing is implemented in the game. | `docs/design/retune-systems.md` (authority for structure), `retune-spec.md` (numbers), `retune-baseline.md` (measured retail) |
| Retune plan for the owner | Published page, revision 2 with later edits; the page source is committed. The design notes above are the record where they differ. | `docs/design/retune-plan.html` |
| Data-only patch set | In progress at handover: `tuning/retune-v0/` and `tools/apply_retune.py`. Lets the owner try the data half of the retune on the original game in the emulator. | `tuning/retune-v0/README.md` when present; `docs/data-patching.md` |
| Native build | All three modules translate and compile. Boots through the logos and title screen; after START the main module runs the practice ground. The picture from the main module is black or nearly so. No menus seen, no match. | `docs/recomp-feasibility.md`, `docs/recomp-build.md`, `tools/recomp/` |
| Renderer and front end | Mapped for the port. | `docs/renderer-map.md` (frame order, hand-over, ranked causes of black frames, checks C1-C9), `docs/frontend-map.md` (waits before the menu, how a match starts, pointer chains to ball and players) |
| Byte-matching | 30,437 functions, 2,937,704 of 10,154,036 bytes (28.93%), build b46. The local agent owns it outside the gameplay and ball ranges. | `docs/decomp-remaining.md`, `docs/ltcg-route.md`, `docs/agents/matching-tips.md`, `docs/agents/near-misses/` |
| Equivalence tier | Checker built and validated. | `docs/equivalence-tier.md` (section 9 = status of the gameplay functions the retune must modify) |

## 3. What to do first on the owner's machine

1. **Build the native game with a real GPU** by following `docs/recomp-build.md`. The cloud container
   had no GPU and drew in software at about 1 frame a second; several workarounds there (offscreen
   swapchain, synchronous shader compile, drawing only every Nth frame) exist only for that reason.
   The first question a real GPU answers is whether the black frames are a software-rendering
   artefact or a real fault. `docs/renderer-map.md` section 6 lists what to log if they persist; its
   top suspect is the resolve of the back buffer into the game's own front-buffer texture before Swap.
2. **Reach a match.** After START the game is on the practice ground (engine state 4 there is normal,
   not a hang). START again opens the main menu. `docs/frontend-map.md` gives the pad script to an
   exhibition match and an untested direct call. Gate each press on the scene-name watch.
3. **Try the data-only retune in the emulator** with `tools/apply_retune.py` on the owner's own copy.
   Not yet verified by anyone: that the game accepts a rebuilt archive, the layout signature word, and
   which archive wins when the title update and the disc both carry a member. Check those first.
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

Open at handover: the big server was too strong in simulation before returns were regraded (re-run
pending); the two functions that matter most for the code changes, grade selection `fn_886629C8` and
the timing value `fn_8867DF68`, have no usable C yet; whether the grade is known before the swing
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
