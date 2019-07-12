//
//  prob4.cpp
//  find out MAX and MIN values.
//
//  Created by TAEGIKIM on 07/03/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <climits>
using namespace std;

/*
int Max(int param[])
{
    int max = param[0];
    for(i=0;i<param[].size();i++)
    {
        if(param[i] >= max)
        {
            max = param[i];
        }
    }
    
}
int Min(int param[])
{
    int min = param[0];
    for(i=0;i<param[].size();i++)
    {
        if(param[i] <= min)
        {
            min = param[i];
        }
    }
}
*/
 
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
    for(int i=0; i<numTestCases; i++) // iterate using numTestCases counts (total 3 probs to solve)
    {
        int numData, data;
        int max = INT_MIN,min = INT_MAX		;
        inStream >> numData; //number of numbers in the prob
        
        for (int j=0; j<numData; j++)//nested
        {
            inStream >> data;
            if(data > max)
            {
                max = data;
            }
            if(min > data)
            {
                min = data;
            }
            
        }
        
        cout << max << " " << min << endl;
    }
    inStream.close();
    return 0;
}
