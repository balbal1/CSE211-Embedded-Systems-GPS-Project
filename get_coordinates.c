#include "declarations.h"

extern double currentLat;
extern double currentLong;
extern char arr1[11];
extern char arr2[12];

void getCoordinates (char * ptr) {
    int i = 0;
    int flag = 0;
		ptr += 7;
    for (flag = 0; flag < 22; flag++) {
			if (flag < 10) {
				arr1[i]= * ptr;
      } else if (flag == 10) {
				ptr +=2;
        i = -1;
			} else {
				arr2[i]= * ptr ;
      }
			ptr ++;
      i++;
    }
		arr1[10] = '\0';
		arr2[11] = '\0';
		
		currentLat = atof(arr1);
    currentLong = atof(arr2);
		
}

double fixCoordinate (double coordinate) {
	double intCoord, fractCoord;
    coordinate /= 100;
    fractCoord = modf(coordinate, &intCoord);
    fractCoord *= (double)10/6;
    return intCoord + fractCoord;
}
