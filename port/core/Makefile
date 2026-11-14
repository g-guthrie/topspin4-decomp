# ts4core host build and tests.   make            -> build/ts4core_test
#                                  make test       -> run the self-tests (needs python3 for the synthetic blob)
#                                  make wasm       -> ../../work/port/ts4core.wasm (see build_wasm.sh)
# Every source must pass `cc -std=c99 -Wall -Wextra -Werror`.
CC      ?= cc
HERE    := $(abspath $(dir $(lastword $(MAKEFILE_LIST))))
REPO    := $(abspath $(HERE)/../..)
REF     := $(REPO)/ref/gameplay
BUILD   ?= $(HERE)/build
CFLAGS  ?= -O2
WARN    := -std=c99 -Wall -Wextra -Werror
FP      := -ffp-contract=off -fno-fast-math
INC     := -I$(HERE)/shim -I$(HERE)/include -I$(HERE)/src -I$(REPO)/src/xbox360 -I$(REF)

CORE_SRCS := $(HERE)/src/softmath.c $(HERE)/src/data.c $(HERE)/src/ball.c $(HERE)/src/shot.c $(HERE)/src/sim.c
REF_SRCS  := $(REF)/rules.c $(REF)/movement.c $(REF)/ai_driver.c $(REF)/stats.c $(REF)/swing_window.c $(REF)/clip_fit.c
DRAFT     := $(REPO)/src/xbox360/drafts/gp4b_ball_model.c

all: $(BUILD)/ts4core_test $(BUILD)/gp4b_selftest

$(BUILD)/ts4core_test: $(HERE)/test/test_core.c $(CORE_SRCS) $(REF_SRCS) $(wildcard $(HERE)/src/*.h $(HERE)/include/*) $(DRAFT)
	@mkdir -p $(BUILD)
	$(CC) $(WARN) $(FP) $(CFLAGS) $(INC) $(HERE)/test/test_core.c $(CORE_SRCS) $(REF_SRCS) -lm -o $@

# the reference ball model's own golden-vector self-test, built with the same shim (software exp/log/fmaf)
$(BUILD)/gp4b_selftest: $(DRAFT) $(HERE)/src/softmath.c
	@mkdir -p $(BUILD)
	$(CC) $(WARN) $(FP) $(CFLAGS) -DGP4B_SELFTEST $(INC) $(DRAFT) $(HERE)/src/softmath.c -lm -o $@

$(BUILD)/synthetic.ts4d: $(HERE)/tools/ts4d.py $(HERE)/data/provisional.tunables.json
	@mkdir -p $(BUILD)
	python3 $(HERE)/tools/ts4d.py synthetic --out $@

$(BUILD)/nograph.ts4d: $(BUILD)/synthetic.ts4d
	python3 $(HERE)/tools/ts4d.py synthetic --out $@ --no-graphs

$(BUILD)/notpl.ts4d: $(BUILD)/synthetic.ts4d
	python3 $(HERE)/tools/ts4d.py synthetic --out $@ --no-templates-tree

test: all $(BUILD)/synthetic.ts4d $(BUILD)/nograph.ts4d $(BUILD)/notpl.ts4d
	$(BUILD)/gp4b_selftest | tail -1
	$(BUILD)/ts4core_test $(BUILD)/synthetic.ts4d $(BUILD)/nograph.ts4d $(BUILD)/notpl.ts4d

wasm:
	$(HERE)/build_wasm.sh

clean:
	rm -rf $(BUILD)

.PHONY: all test wasm clean
