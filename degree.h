#pragma once
#include <string>
#include <iostream>
using namespace std; 

enum class DegreeProgram { UNDECLARED, SECURITY, NETWORK, SOFTWARE }; //Three degree programs & default value of undeclared
static const string degreeprogramStrings[] = { "UNDECLARED","SECURITY","NETWORK","SOFTWARE" }; //converting index to string