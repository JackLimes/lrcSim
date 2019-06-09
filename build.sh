mkdir bin 2> /dev/null
g++ -pthread ./src/lrc.cpp ./src/cpuRunner.cpp -o ./bin/lrcSim
