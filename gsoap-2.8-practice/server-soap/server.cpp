/**
 * @file server.cpp
 * @brief  
 * @author DongChenLong 
 * @version 1.0
 * @date 2017年10月16日 15时28分24秒
 */
#include "soapcalcService.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
    calcService calc;
    int port = 65531;

    if (calc.run(port)) {
        cerr << "Calc service run failed" << std::endl;
        exit(0);
    }
    return 0;
}

int calcService::add(double a, double b, double* result) {
    *result = a + b;
    return SOAP_OK;
}

