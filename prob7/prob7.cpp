//
//  prob7.cpp
//  
//
//  Created by TAEGIKIM on 08/03/2017.
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
    ifstream in_put;
    int roof1;
    in_put.open("input.txt");
    
    if(in_put.fail())//error checks
    {
        cerr << "Input file opening failed.\n";
        exit(1);
    }
    
    in_put >> roof1;
    while(roof1--)
    {
        //cout << roof1;
        int roof2, clue2, num2, i, j;
        in_put >> roof2;
        
        for(i=1;i<=roof2;i++)
        {
            cout << i << " ";
            int ref = roof2;
            int temp = i;
            for(j=1;j<i;j++)
            {
                //cout << endl;
                //cout << num2 << " ";
//                clue2 = roof2;
//                clue2--;
//                num2 += clue2;
                temp += --ref;
                cout << temp << " ";

            }
            cout << endl;

        }
        
    }
    return 0;
}
