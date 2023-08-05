.PHONY : clean

bc2: main.cpp Feeder.cpp Feeder.h bimodal.h bimodal.cpp bc2.cpp bc2.h
			g++ -g -o bc2 main.cpp Feeder.cpp Feeder.h bimodal.h bimodal.cpp bc2.cpp bc2.h

bimodal: main.cpp Feeder.cpp Feeder.h bimodal.h bimodal.cpp
			g++ -g -o bimodal main.cpp Feeder.cpp Feeder.h bimodal.h bimodal.cpp

Feed: main.cpp Feeder.cpp Feeder.h
			g++ -o feeder main.cpp Feeder.cpp Feeder.h
CleanFeed: 
			rm feeder $(objects) output.txt
CleanBimodal: 
			rm bimodal $(objects) output.txt
CleanBC2: 
			rm bc2 $(objects) output.txt