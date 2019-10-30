//
//  prob8.cpp
//  
//
//  Created by TAEGIKIM on 14/03/2017.
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
    int line[3] = {0, 0, 0};
    for(int z=0; z<numTestCases; z++)
    {
        int abcx[3] = {0, 0, 0}, abcy[3] = {0, 0, 0};
        inStream >> abcx[0] >> abcy[0] >> abcx[1] >> abcy[1] >> abcx[2] >> abcy[2];
        
        //라인 구하기
        line[0] = pow(abcx[0] - abcx[1],2) + pow(abcy[0] - abcy[1],2);
        line[1] = pow(abcx[1] - abcx[2],2) + pow(abcy[1] - abcy[2],2);
        line[2] = pow(abcx[2] - abcx[0],2) + pow(abcy[2] - abcy[0],2); //라인2 가 최대
        
        //최대길이의 변 구하기 <<-- 이 부분의 생각한대로 안된듯...
        if(line[0] > line[2])
        {
            int temp1 = 0;
            temp1 = line[2];
            line[2] = line[0];
            line[0] = temp1;
        }
        else if(line[1] > line[2])
        {
            int temp2 = 0;
            temp2 = line[2];
            line[2] = line[1];
            line[1] = temp2;
        }
        
        if(((float)sqrt(line[2]) >= ((float)sqrt(line[1]) + (float)sqrt(line[0]))) || ((float)sqrt(line[1]) >= ((float)sqrt(line[2]) + (float)sqrt(line[0]))) || ((float)sqrt(line[0]) >= ((float)sqrt(line[2]) + (float)sqrt(line[1]))))
        {
            cout << 0 << " " << endl;
        }
        else if((line[0] + line[1]) == line[2] || (line[2] + line[1]) == line[0] || (line[0] + line[2]) == line[1]) //직각 삼각형
        {
            cout << 1 << " " << endl;
        }
        else if((line[0] + line[1]) < line[2] || (line[0] + line[2]) < line[1] || (line[2] + line[1]) < line[0]) //둔각 삼각형
        {
            cout << 2 << " " << endl;
        }
        else if((line[0] + line[1]) > line[2] || (line[0] + line[2]) > line[1] || (line[2] + line[1]) > line[0]) //예각 삼각형
        {
            cout << 3 << " " << endl;
        }

    }

    return 0;


}
