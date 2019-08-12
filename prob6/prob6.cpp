//
//  prob6.cpp
//  
//
//  Created by TAEGIKIM on 07/03/2017.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include <ctime>

using namespace std;

int main(void)
{
    ifstream inStream;
    int numTestCases;
    inStream.open("input.txt"); //file input
    
    if(inStream.fail())//error checks
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    
    inStream >> numTestCases; //checks how many numbers you have

    for(int z=0; z<numTestCases; z++)
    {
        int numData;
        inStream >> numData;
        int totalDay = 0, total[3] = {0, 0, 0};
        for (int y=0; y<numData; y++)
        {
            int s[3], e[3], t[3]; //declare start, end, and time gap arrays
            inStream >> s[0] >> s[1] >> s[2] >> e[0] >> e[1] >> e[2]; //input those numbers
            t[0] = e[0] - s[0];//hour
            t[1] = e[1] - s[1];//min
            t[2] = e[2] - s[2];//sec
            total[2] += t[2];//accumulate
            total[1] += t[1];
            total[0] += t[0];
            // time calculation
            if (total[2] >= 60)
            {
                total[2] = total[2] - 60;
                total[1] += 1;
            }
            else if (total[2] < 0)
            {
                total[1] -= 1;
                total[2] = total[2] + 60;
            }
            
            if (total[1] >= 60)
            {
                total[1] = total[1] - 60;
                total[0] += 1;
            }
            else if (total[1] < 0)
            {
                total[0] -= 1;
                total[1] = total[1] + 60;
            }
            if (total[0] >= 24)
            {
                total[0] = total[0] - 24;
                totalDay = totalDay + 1;
            }
            else if (total[0] < 0)
            {
                totalDay -= 1;
                total[0] = total[0] - 24;
            }
        }
        cout << totalDay << " " << total[0] << " " << total[1] << " " << total[2] << " " << endl;
    }
    return 0;
}
