/* In this project you will develop the following system using TM4C123G LaunchPad:
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
    by Google Maps. */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double destLat = 30.0642310;
double destLong = 31.2798524;
double sumOfDist = 0;
double currentLat, currentLong, oldLat, oldLong, oldDist, startLat, startLong;
bool firstTime=0;
bool firstStep=0;

void GettingCloserOrFarther(double destX, double destY, double currentX, double currentY);
void CalculateStepsTaken(double currentX, double currentY);
double distance(double x1,double x2,double y1,double y2);


int main(void) {
    while(1) {
        if (!firstTime) {
            startLat = currentLat;
            startLong = currentLong;
            oldDist = distance(currentLat,destLat,currentLong,destLong);
            firstTime = 1;
        }
        GettingCloserOrFarther(destLat, destLong, currentLat, currentLong);
        if (!firstStep) {
            oldLat = currentLat;
            oldLong = currentLong;
            firstStep = 1;
        }
        CalculateStepsTaken(currentLat, currentLong);

    }
}
void GettingCloserOrFarther(double destX, double destY, double currentX, double currentY){
    double currentDist = distance(currentX,destX,currentY,destY);
    if (currentDist > 5 ){
        // turn on red
        if (currentDist < oldDist){
            // fast blink red
        }
        else {
            // constant red
        }
    }
    else if (currentDist < 5 && currentDist > 2.5){
        // turn on yellow
        if (currentDist < oldDist  ){
            // blink yellow
        }
        else {
            // constant yellow
        }
    }
    else {
        //turn on green
    }
    oldDist = currentDist;
}
void CalculateStepsTaken(double currentX, double currentY){
    double distFromLastStep = distance(oldLat,currentX,oldLong,currentY);
    sumOfDist += distFromLastStep;
    oldLat = currentX;
    oldLong = currentY;
}
double distance(double x1,double x2,double y1,double y2){
    return sqrt(pow((x2- x1),2) + pow((y2 - y1) , 2));
}