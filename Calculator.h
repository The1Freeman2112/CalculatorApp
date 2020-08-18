#pragma once
#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <cmath>

using namespace std;

void RunMainDisplay();
void DisplayResult(double dFinalResult);
vector<double> FunctionDisplay();
void SelectOption(int option);
double RunAddition();
double RunSubtraction();
double RunMultiplication();
double RunAverage();
double RunDivision();
double RunSimpleInterest();
double WhichCompoundInterest();
double RunCompoundInterestByTime();
double RunCompoundInterestByAmount();