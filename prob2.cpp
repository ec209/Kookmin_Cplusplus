#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

int max(int a, int b)
{
 return a>b?a:b;
}
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

 while(numTestCases--)
 {
 int a,b;
 inStream >> a >> b;
  

 cout << a + b << " " << a - b << " " << abs(a - b) << " " << a * b << " " <<  a % b << " " <<  max(a,b) << " " << (a == b) ;
 }
 inStream.close();
 return 0;
}
