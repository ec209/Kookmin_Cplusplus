//
//  prob3_v1.cpp
//  
//
//  Created by TAEGIKIM on 07/03/2017.
//
//

#include "prob3_v1.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
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
        int numData, data;
        int sum = 0;
        inStream >> numData; //number of numbers in the prob
        
        for (int j=0; j<numData; j++)//nested
        {
            inStream >> data;
            sum += data;
        }
        
        cout << sum << endl;
    }
    inStream.close();
    return 0;
}
