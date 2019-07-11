#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(void)
{
 ifstream inStream;
 int numTestCases;

 inStream.open("input.txt");
 if(inStream.fail())
 {
  cerr << "Input file opening failed.\n";
  exit(1);
 }
 inStream >> numTestCases;
 //cout << numTestCases;
 for(int i=0; i<numTestCases; i++)
 {
  int numData, data;
  int sum = 0;
  //cout << numTestCases;
  inStream >> numData;
  cout << numData;
  for (int j=0; j<numData; j++)
  {
   inStream >> data;
   sum += data;
   //cout << numData;
  }

// cout << sum << endl;
 }
 inStream.close();
 return 0;
}

