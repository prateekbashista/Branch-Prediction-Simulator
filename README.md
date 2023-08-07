# Branch Prediction Simulator #

This project implements a branch direction predictor that is used in CPU designs to predict the taken or not-taken behaviour of the branch. The simulator is capable of simulating 2bc Saturing Counter Predictor, 1-bit Bimodal Predictor and Gshare Branch History Predictor. 

The simulator uses unordered maps data structure in C++ to mimic the cache behaviour and provides O(1) search times. 

The simulator tests the branch prediction implementation against 3 workloads: test_br.ctrace, house.ctrace, wireframe.ctrace using the custom feeder program which reads the aforementioned files, extracts the PC, read the instruction and decides if the PC is a branch or not, and feeds the data to predictors.

Since, my simulator knows if the PC is a branch or not, the predictor in the original CPU hardware will sit at the decode stage. Additionally, predictors can be simulated in future by adding BTB and whether it's a branch or not to the program.

### Steps to run the Simulator ###

The Makefile has commands for all three simulators with each having backward compatibility, so 2bc compiles bimodal as well and gshare compiles everything.

1) Clean Command
```
make CleanGshare
```
2) Compile Command
```
make gshare
```
3) Output Command

```
./gshare > output.txt
```

