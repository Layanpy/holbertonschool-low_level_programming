# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken with the C standard library function `clock()` from `<time.h>`, which reports processor time consumed by the program. Each difference between two `clock()` values was converted to seconds by dividing by `CLOCKS_PER_SEC` and printed with `%.6f` precision. Every program was compiled with `gcc -Wall -Werror -Wextra -pedantic` and the source logic was never modified.

Three experiments were run. First, `baseline_loop.c` (100,000,000 iterations of a modulo-and-add loop) was executed three consecutive times to observe timing variability. Second, `comparison_algorithms.c` was executed three times, and the average time of each implementation was computed from those runs. Third, `instrumentation_lab.c` was instrumented with one timer around the whole workload (TOTAL) and one timer around each phase (BUILD_DATA, PROCESS, REDUCE), using the same boundary rule for every phase: `clock()` immediately before and immediately after the function call.

## Observed Performance Differences

The baseline loop produced 0.223729 s, 0.232446 s and 0.223842 s. The work was identical in every run, yet the slowest run was about 3.9% slower than the fastest. This confirms that a single measurement is not reliable and that repeated runs are necessary.

The algorithm comparison showed a much larger effect. The naive implementation, which uses a nested loop and performs roughly 1.25 billion checks (O(n²)), averaged 2.678711 s. The single-pass implementation, which checks each of the 50,000 elements once (O(n)), averaged 0.000108 s. The naive version was therefore about 24803 times slower. This difference is several orders of magnitude larger than the run-to-run noise seen in the baseline, so it is clearly caused by the algorithm and not by measurement variability.

The instrumentation experiment reported TOTAL = 0.000736 s, BUILD_DATA = 0.000274 s, PROCESS = 0.000317 s and REDUCE = 0.000138 s. All three phases are linear passes over 50,000 elements, so they are all very short and of similar magnitude, and their sum is consistent with the TOTAL value.

## Relation Between Runtime and Energy Consumption

Energy consumed by the processor is approximately its power draw multiplied by the time it stays busy. Since `clock()` measures CPU time, a program with a higher CPU time keeps the processor active longer and, under similar power conditions, consumes more energy. Based on the measured averages, the naive algorithm kept the CPU busy about 24803 times longer than the single-pass algorithm to answer the same question, so it can be expected to use proportionally more energy. Reducing runtime by choosing a better algorithm is therefore a direct way to reduce energy usage.

## Limitations of the Experiment

This experiment did not measure energy directly; no power meter or hardware energy counter was used, so the energy conclusions are inferred from CPU time only. The `clock()` function has limited resolution, and very short phases such as those in `instrumentation_lab.c` are close to that resolution, which makes their individual values less precise. Only three runs were performed per program, which is a small sample. The tests ran in a shared sandbox environment where other processes, CPU frequency scaling and caching could influence timing, as shown by the baseline variability.

## Practical Engineering Takeaway

The measurements show that algorithmic complexity has a far greater impact than run-to-run noise: moving from O(n²) to O(n) reduced the runtime by a factor of about 24803. Engineers should measure before optimizing, repeat measurements to account for variability, instrument programs to find where time is actually spent, and prioritize algorithmic improvements, because lower CPU time generally means lower energy consumption.
