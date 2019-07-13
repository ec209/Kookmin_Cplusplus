//
//  prob5.cpp
//  
//
//  Created by TAEGIKIM on 07/03/2017.
//
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
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
    for(int i=0; i<numTestCases; i++) // iterate using numTestCases counts (total 3 probs to solve)
    {
        int numData, data, data_p;
        int sum = 1;
        inStream >> numData; //number of numbers in the prob
        
        for (int j=0; j<numData; j++)//nested
        {
            inStream >> data;
            if(data > 10)
            {
                data_p = data % 10;
            }
            else
            {
                data_p = data;
            }
            sum *= data_p;
            if(sum >= 10)
            {
                sum = sum % 10;
            }
        }
        cout << sum << " " << endl;
    }
    inStream.close();
    return 0;
}
