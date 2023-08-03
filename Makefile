.PHONY : clean

bimodal: main.cpp Feeder.cpp Feeder.h
			g++ -o feeder main.cpp Feeder.cpp Feeder.h

Feed: main.cpp Feeder.cpp Feeder.h
			g++ -o feeder main.cpp Feeder.cpp Feeder.h
CleanFeed: 
			rm feeder $(objects) output.txt