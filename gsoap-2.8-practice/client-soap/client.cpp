/**
 * @file client.cpp
 * @brief  
 * @author DongChenLong 
 * @version 1.0
 * @date 2017年10月16日 16时12分00秒
 */
#include "soapcalcProxy.h"
#include "calc.nsmap"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    double a = 4;
    double b = 2;
    double result;
    calcProxy calc;
    cout << "client..." << endl;
//    calc.soap_endpoint = "http://localhost:65531";
//    calc.soap_endpoint = "http://127.0.0.1:65531";
    calc.soap_endpoint = "http://192.168.0.9:65531";
    calc.add(a,b,&result);
    cout<<a<<"+"<<b<<"="<<result<<endl;
    return 0;
}
