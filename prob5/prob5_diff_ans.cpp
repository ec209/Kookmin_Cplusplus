/*******************************************************
 *                                                      *
 * Problem:  시간 계산                                    *
 *                                                      *
 *                                                      *
 *******************************************************/
/*******************************************************
 *                                                      *
 * 국민대학교 소프트웨어융합대학 소프트웨어학부 2학년              *
 *                                      20143389 김상열  *
 *                                                      *
 *******************************************************/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    ifstream inStream;
    int numTestCase;
    
    inStream.open("input.txt");
    if (inStream.fail()) {
        cerr << "Input file openning failed." << endl;
        exit(1);
    }
    
    inStream >> numTestCase;
    while (numTestCase--) {
        int numStaff, temp=0; //시,분,초를 초단위로 합산하여 temp에 입력
        tm timeResult;
        inStream >> numStaff;
        while (numStaff--) {
            tm timeStart, timeFinal;
            inStream >> timeStart.tm_hour >> timeStart.tm_min >> timeStart.tm_sec >> timeFinal.tm_hour >> timeFinal.tm_min >> timeFinal.tm_sec;
            temp += (timeFinal.tm_hour * 3600 + timeFinal.tm_min * 60 + timeFinal.tm_sec) - (timeStart.tm_hour * 3600 + timeStart.tm_min * 60 + timeStart.tm_sec);
        }
        timeResult.tm_sec = temp % 60;
        temp /= 60;
        timeResult.tm_min = temp % 60;
        temp /= 60;
        timeResult.tm_hour = temp % 24;
        temp /= 24;
        timeResult.tm_yday = temp;
        cout << timeResult.tm_yday << ' ' << timeResult.tm_hour << ' ' << timeResult.tm_min << ' ' << timeResult.tm_sec << endl;
    }
    inStream.close();
    return 0;
}
