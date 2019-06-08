from graphics import *
from math import *

res = 1000


numPlayers = 0
circList = []
winList = []
textList = []
winSum = 0
winFile = open("bin/result.txt", "r")
first = True
for line in winFile:
	winList.append(int(line[:-1])) #removes newline
	winSum = winSum + int(line[:-1])
	if(first):
		maxWins = int(line)
		minWins = int(line)
		first = False
	else:
		maxWins = max(maxWins, int(line))
		minWins = min(minWins, int(line))
	numPlayers = numPlayers + 1

win = GraphWin("Left Right Center", res, res)
for i in range(numPlayers):
	theta = i*(2*pi/(numPlayers))
	angleDelta=2*pi/numPlayers
	circRadius = sqrt(2*pow(res, 2) - 2*pow(res, 2)*cos(angleDelta))/6
	dist = res/2 - circRadius
	circList.append(Circle(Point((dist)*cos(theta) + res/2, (dist)*sin(theta) + res/2), circRadius))
	circList[i].setFill(color_rgb(int((255*((winList[i]-minWins)/(maxWins-minWins)))), int((255*((winList[i]-minWins)/(maxWins-minWins)))),int((255*((winList[i]-minWins)/(maxWins-minWins))))))
	#circList[i].setFill(color_rgb(int((255*((winList[i])/(maxWins)))), int((255*((winList[i])/(maxWins)))),int((255*((winList[i])/(maxWins))))))
	circList[i].draw(win)
	textList.append(Text(circList[i].getCenter(), str(100*winList[i]/winSum) + "%"))
	textList[i].setTextColor("green")
	textList[i].draw(win)
	if winList[i] == maxWins:
		winMarker = Line(Point(res/2, res/2), circList[i].getCenter())
		winMarker.setFill("red")
		winMarker.draw(win)

firstMarker = Line(Point(res/2, res/2), circList[0].getCenter())
firstMarker.draw(win)


#circ.setFill(color_rgb(255, 0, 0)) # 255-(255 * (wins/maxWins))
#255*((wins-minWins)/(maxWins-minWins)

win.getMouse() # pause
win.close()
