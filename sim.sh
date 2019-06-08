#!/bin/bash
#duct tape and bailing wire this bitch!
echo "Enter number of players"
read players
echo "Enter number of games"
read games

echo "Running simulation..."

echo "$players $games" | ./bin/lrcSim > ./bin/result.txt
echo "Displaying..."
python3 ./src/lrc.py

