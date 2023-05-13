/*
In this project you will develop the following system using TM4C123G LaunchPad:
    1. The GPS subsystem stores the coordinates of the start point.
    2. After reaching the destination point, the GPS subsystem stores the coordinates
        of the end point and calculates the total distance that was taken by the user.
    3. The output will be translated as the following.
            1. Stage 1: The built-in LED will be turned on(green) when the target
                        destination is reached.
            2. Stage 2: The built-in LED will be turned on(yellow) when the target
                        destination is about to be reached < 5 meters.
            3. Stage 3: The built-in LED will be turned on(red) when the target
                        destination is far away by distance > 5 meters.
    4. The trajectory of the distance should satisfy the following criteria:
            1. The total distance between the start and the end point should be > 100
                meters.
            2. The path from the start point to the end point should form a non-straight
                line that is similar to the provided baseline path below.
            3. You have the freedom to select any starting point on Google Maps.
    4. Your SW should calculate the distance between the starting point and the
        end point, and you should compare the calculated distance with the
        distance obtained from Google Maps.
    5. You should ensure that there is no big difference/deviation (error margin
        should be <= 5%) between your calculated distance and the one shown
        by Google Maps.
*/

#include "declarations.h"

char currentGLL[50] ;
char arr1[11] = {'\0'};
char arr2[12] = {'\0'};
char color[7] = {'\0'};
double  destLat, destLong, startLat, startLong,
        currentLat, currentLong, oldLat, oldLong,
        sumOfDist, currentDist, distFromLastStep;
bool firstTime = 0;

int __main(void) {
		
	destLat = 30.063779;
	destLong = 31.277873;
	sumOfDist = 0;
	firstTime = 0;
	
	initPortA();
	initPortB();
	initPortF();
	initUART0();
	initUART1();
	
	while(1) {
	
		makeInputString(currentGLL);
		getCoordinates(currentGLL);
		
		currentLat = fixCoordinate(currentLat);
		currentLong = fixCoordinate(currentLong);
		
		if (!firstTime) {
			startLat = currentLat;
			startLong = currentLong;
			oldLat = currentLat;
			oldLong = currentLong;
			firstTime = 1;
		}
		
		chooseLedColor(double destLat, double destLong, double currentLat, double currentLong);
		calculateStepsTaken(double oldLat, double oldLong, double currentLat, double currentLong);
		
		oldLat = currentLat;
		oldLong = currentLong;
		
		serialPrint();
    }
}
