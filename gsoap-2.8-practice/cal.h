/**
 * @file cal.h
 * @brief  
 * @author DongChenLong 
 * @version 1.0
 * @date 2017年10月16日 15时20分17秒
 */

//gsoap ns service name: calc Simple calculator service
//gsoap ns service style: rpc
//gsoap ns service encoding: encoded
//gsoap ns service namespace: http://localhost/calc.wsdl
//gsoap ns service location: http://localhost/server.cgi
//gsoap ns schema namespace: urn:calc
int ns__add(double a, double b, double *result);
