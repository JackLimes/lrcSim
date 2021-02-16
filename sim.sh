#!/bin/bash
#duct tape and bailing wire!
echo "Enter number of players"
read players
echo "Enter number of games"
read games

echo "Running simulation..."

SECONDS=0
echo "$players $games" | ./bin/lrcSim > ./bin/result.txt
echo "That took $SECONDS seconds"

echo "Displaying..."
python3 ./src/lrc.py

