# asm2c on functions of 256-2048 bytes (round T1)

Tooling round T1, 2026-11-14. Goal: raise the match rate of `tools/asm2c` on functions of
256-2048 bytes, following section 3 of `docs/decomp-remaining.md`.

## 1. Fixed sample and how it is measured

The sample is the game-code part of a deterministic stratified draw:

```sh
python3 tools/decomp_survey.py sample --lo 256 --hi 2048 -n 600 --seed 1 > work/t1/sample_all.txt
grep ' game:' work/t1/sample_all.txt > work/t1/sample_game.txt          # 342 functions, 203,176 bytes
awk '{print $1}' work/t1/sample_game.txt > work/t1/only.txt
sha256sum work/t1/only.txt   # aad771a8e30f1dd613ab4ce057d9c642f478b42b1fdd134e7c94345f67fb6813
```

Inputs: `config/54540859/match.json` sha256 `5b3beb18...14e18ab`, `symbols.txt` sha256
`0ba1dd99...dabdf`, `TS4_MATCHING_DIR=work/matching-b39` (the newest split whose `work/b39.log`
has a "Matched" line), Python 3.13.18, MSVC 16.00.10224.00 through `tools/fn_check.py`.

Each measurement is one fresh asm2c run over the sample with the K6M variant set, both flag sets,
in a scratch work dir with `--no-final` (`work/t1/measure.sh TAG`):

```sh
TS4_MATCHING_DIR=$PWD/work/matching-b39 python3 tools/asm2c/run.py --prefix t1m --family T1M \
  --work work/t1/m_$TAG --out-dir work/t1/m_$TAG/out --spec-dir work/t1/m_$TAG/specs --no-final \
  --max-size 0x800 --variants $VARIANTS --flagsets ",O1" --only-addrs work/t1/only.txt --jobs 4 --fresh
```

`VARIANTS` is `10w,10wV,20w,10wJ,10` unless the table says otherwise. Translation refusals are
counted with `work/t1/refusals.py 10w`, frame agreement with `work/t1/fcheck.py 10w` (both are
scratch drivers around `translate.gen` and `frame.frame_check`).

## 2. Results per change

RESULTS_TABLE

## 3. What MSVC does with locals (measured with tools/asm2c/probe.py)

`python3 tools/asm2c/probe.py file.c` compiles a file with the real compiler and prints each
function's listing and frame size. Probes (all `/O2 /Oi`):

| Probe | Result |
|---|---|
| four `ts4_word` locals, address passed to one call, declared in any order or renamed | same offsets every time: neither names nor declaration order matter |
| one of them used more often | it moves to the lowest offset |
| `char`, `W`, `W[2]`, `double` and a float->int conversion temporary | placed in order of increasing size: 0x50 char, 0x54 word, 0x58 8-byte array, 0x60 double, 0x68 conversion slot |
| 16-, 12-, 8-, 4-byte structs | 0x50 (4), 0x58 (8), 0x60 (12), 0x70 (16, 16-aligned) |
| the same objects wrapped in one struct | the struct is placed after the compiler's own 8-byte temporary (it is bigger) |
| two 8-byte arrays with equal use counts | the one referenced first in the code gets the lower offset |

So the locals are sorted by (size ascending, use count descending, first reference), compiler
temporaries included, with objects of 16 bytes or more 16-aligned. A word array where the
original had separate scalars changes the frame in two ways: its size moves it in the sort, and
it collects the uses of all its slots. Declaration order cannot be used to steer the layout.

## 4. Changes

CHANGES

## 5. Next limiting factors

NEXT
