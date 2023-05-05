#include "declarations.h"

int main()
{
   extract();
   printf("%4.5f \n",currentLat);
   printf("%5.5f ",currentLong);
   return 0;
}

double toDouble(char * s, int length)
{
    unsigned long long int m = 1;
    int ret = 0;
    for (int i = length-1; i >= 0; i--) {
        if (s[i] == '.') continue;
        ret += (s[i] - '0') * m;
        m *= 10;
    }
    return (double)ret/100000;
}

void extract () {
    char arr1[10] = {'\0'};
    char arr2[11] = {'\0'};
    ptr = *currentGLL;
	ptr += 7;
    int i = 0;
    int flag = 0;
    while(flag < 2)
        {
        if ( * ptr != ',')
            {
            if (flag == 0)
            {
                arr1[i]= * ptr;
                ptr++;
                i++;
            }
            else if (flag == 1)
            {
                arr2[i]= * ptr ;
                ptr ++ ;
                i++;
            }
            }
        else
            {
            ptr +=3;
            flag++;
            i = 0;
            }
        }
    currentLat = toDouble(arr1,10);
    currentLong = toDouble(arr2,11);
}
