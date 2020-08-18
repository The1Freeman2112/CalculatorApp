// 081820 SamuelG: Start project. Objective is to create a basic calculator
//
#include "Calculator.h";

using namespace std;

int main()
{
	RunMainDisplay();
}

void RunMainDisplay() {
	int option = 0;
	while (option != 8) {
		cout << "1. Add" << endl;
		cout << "2. Subtract" << endl;
		cout << "3. Multiply" << endl;
		cout << "4. Divide" << endl;
		cout << "5. Average" << endl;
		cout << "6. Simple Interest" << endl;
		cout << "7. Compound Interest" << endl;
		cout << "8. Exit" << endl;
		cin >> option;
		if (option < 1 || option>8) {
			cout << "Enter valid option" << endl;
			cin >> option;
		}
		SelectOption(option);
	}
}

void SelectOption(int option) {
	double dFinalResult = 0;
	switch (option)
	{
	case 1:
		dFinalResult = RunAddition();
		break;
	case 2:
		dFinalResult = RunSubtraction();
		break;
	case 3:
		dFinalResult = RunMultiplication();
		break;
	case 4:
		dFinalResult = RunDivision();
		break;
	case 5:
		dFinalResult = RunAverage();
		break;
	case 6:
		dFinalResult = RunSimpleInterest();
		break;
	case 7:
		dFinalResult = WhichCompoundInterest();
		break;
	case 8:
		cout << "Exiting..." << endl;
		system("pause");
		exit(0);
	default:
		break;
	}
	DisplayResult(dFinalResult);
}

void DisplayResult(double dFinalResult) {
	if (dFinalResult == -1) {
		cout << "There was an error, please make another selection" << endl;
	}
	cout << "Result: " << dFinalResult << endl;
}

/// <summary>
/// This code was being repeated unneccesarily, put this to gather values the user wants calculated. 
/// </summary>
/// <returns> returns a vector of type double to hold the values entered. </returns>
vector<double> FunctionDisplay() {
	int iCount = 0;
	vector<double> vValues;

	cout << "How many numbers are you working with?" << endl;
	cin >> iCount;

	for (int i = 0; i < iCount; i++) {
		double dCurrentValue = 0;
		cout << "Enter a value: " << endl;
		cin >> dCurrentValue;
		vValues.push_back(dCurrentValue);
	}
	return vValues;
}

/// <summary>
/// Logic for addition problems
/// </summary>
/// <returns> returns a double value of the sum of the values entered by the user</returns>
double RunAddition() {
	vector<double> vValues;
	double dTotalValue = 0;
	vValues = FunctionDisplay();

	for (double n : vValues) {
		dTotalValue += n;
	}
	return dTotalValue;
}

/// <summary>
///  Logic for subtracting the numbers entered by the user
/// </summary>
/// <returns>returns double value representing the total of numbers subtracted </returns>
double RunSubtraction() {
	vector<double> vValues;
	double dTotalValue = 0;
	vValues = FunctionDisplay();

	for (double n : vValues) {
		dTotalValue -= n;
	}
	return dTotalValue;
}

/// <summary>
///  Logic for multiplying the numbers entered by the user
/// </summary>
/// <returns>returns double value representing the total of numbers multiplied </returns>
double RunMultiplication() {
	vector<double> vValues;
	double dTotalValue = 1;
	vValues = FunctionDisplay();

	for (double n : vValues) {
		dTotalValue = dTotalValue * n;
	}
	return dTotalValue;
}

/// <summary>
///  Logic for division the numbers entered by the user
/// </summary>
/// <returns>returns double value representing the total of numbers divided </returns>
double RunDivision() {
	int iCount = 0;
	double dValue1, dValue2;
	double dTotalValue = 0;

	cout << "Enter first value to divide (numerator): " << endl;
	cin >> dValue1;
	cout << "Enter second value to divide (denominator): " << endl;
	cin >> dValue2;

	while (dValue2 == 0) {
		cout << "Denominator cannot be 0" << endl;
		cin >> dValue2;
	}

	dTotalValue = dValue1 / dValue2;

	return dTotalValue;
}

/// <summary>
/// averages user input
/// </summary>
/// <returns> returns a double representing the average of numbers entered</returns>
double RunAverage() {
	vector<double> vValues;
	double dTotalValue = 0;
	double dSum = 0;
	int iCount = 0;
	vValues = FunctionDisplay();
	iCount = vValues.size();
	cout << vValues.size() << endl;
	for (double x : vValues) {
		cout << x << endl;
	}
	if (vValues.size() == 0) {
		cout << "Number of elements cannot be 0";
		return -1;
	}

	for (double n : vValues) {
		dSum += n;
	}

	dTotalValue = dSum / iCount;

	return dTotalValue;

}

/// <summary>
/// calculates simple interest based on user input
/// </summary>
/// <returns> returns a double representing the simple interest</returns>
double RunSimpleInterest() {
	double dFinalAmount = 0;
	double dPrincipal = 0;
	double dInterestRate = 0;
	double dTime = 0;

	// get principal
	cout << "Enter the principal amount (USD): " << endl;
	cin >> dPrincipal;
	// get interest
	cout << "Enter the interest rate (annual interest): "<<endl;
	cout << "%"; cin >> dInterestRate;
	// get time
	cout << "Enter the time (in years): " << endl;
	cin >> dTime;

	//convert percentage into decimal
	dInterestRate = dInterestRate / 100;

	dFinalAmount = dPrincipal * (1 + (dInterestRate * dTime));

	return dFinalAmount;
}

/// <summary>
/// calculates compound interest based on user input
/// </summary>
/// <returns> returns a double representing the simple interest</returns>
double WhichCompoundInterest() {
	int choice = 0;
	double dResult = 0;

	cout << "What do you want to know? " << endl;
	cout << "1. The final amount based on a known time" << endl;
	cout << "2. The amount of time based on a known final amount" << endl;
	cin >> choice;
	while (choice < 1 || choice>2) {
		cout << "Not a valid choice, try again" << endl;
		cin >> choice;
	}

	switch (choice)
	{
	case 1:
		dResult = RunCompoundInterestByAmount();		
		break;
	case 2:
		dResult = RunCompoundInterestByTime();
		break;
	default:
		break;
	}

	return dResult;
}

double RunCompoundInterestByTime() {
	int iChoice = 0;
	double dFinalAmount = 0;
	double dPrincipal = 0;
	double dInterestRate = 0;
	double dTime = 0;
	int iNumberOfCompounds = 0;

	// get principal
	cout << "Enter the principal amount (USD): " << endl;
	cin >> dPrincipal;
	// get interest
	cout << "Enter the interest rate (annual interest): " << endl;
	cout << "%"; cin >> dInterestRate;
	// get time
	cout << "Enter the desired amount (USD): " << endl;
	cin >> dFinalAmount;

	cout << "Enter number of compounds:" << endl;
	cout << "1. Yearly" << endl;
	cout << "2. Semi-Yearly" << endl;
	cout << "3. Quarterly" << endl;
	cout << "4. Bi-Monthly" << endl;
	cout << "5. Monthly" << endl;
	cout << "6. Semi-Monthly" << endl;
	cout << "7. Bi-Weekly" << endl;
	cout << "8. Weekly" << endl;
	cout << "9. Daily" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		iNumberOfCompounds = 1;
		break;
	case 2:
		iNumberOfCompounds = 2;
		break;
	case 3:
		iNumberOfCompounds = 4;
		break;
	case 4:
		iNumberOfCompounds = 6;
		break;
	case 5:
		iNumberOfCompounds = 12;
		break;
	case 6:
		iNumberOfCompounds = 24;
		break;
	case 7:
		iNumberOfCompounds = 26;
		break;
	case 8:
		iNumberOfCompounds = 52;
		break;
	case 9:
		iNumberOfCompounds = 365;
		break;
	default:
		break;
	}



	//convert percentage into decimal
	dInterestRate = dInterestRate / 100;
	dTime = (log10(dFinalAmount / dPrincipal)) / (iNumberOfCompounds * (log10(1 + (dInterestRate / iNumberOfCompounds))));

	return dTime;
}

double RunCompoundInterestByAmount() {
	int iChoice = 0;
	double dFinalAmount = 0;
	double dPrincipal = 0;
	double dInterestRate = 0;
	double dTime = 0;
	int iNumberOfCompounds = 0;

	// get principal
	cout << "Enter the principal amount (USD): " << endl;
	cin >> dPrincipal;
	// get interest
	cout << "Enter the interest rate (annual interest): " << endl;
	cout << "%"; cin >> dInterestRate;
	// get time
	cout << "Enter the time (in years): " << endl;
	cin >> dTime;

	cout << "Enter number of compounds:" << endl;
	cout << "1. Yearly" << endl;
	cout << "2. Semi-Yearly" << endl;
	cout << "3. Quarterly" << endl;
	cout << "4. Bi-Monthly" << endl;
	cout << "5. Monthly" << endl;
	cout << "6. Semi-Monthly" << endl;
	cout << "7. Bi-Weekly" << endl;
	cout << "8. Weekly" << endl;
	cout << "9. Daily" << endl;
	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
		iNumberOfCompounds = 1;
		break;
	case 2:
		iNumberOfCompounds = 2;
		break;
	case 3:
		iNumberOfCompounds = 4;
		break;
	case 4:
		iNumberOfCompounds = 6;
		break;
	case 5:
		iNumberOfCompounds = 12;
		break;
	case 6:
		iNumberOfCompounds = 24;
		break;
	case 7:
		iNumberOfCompounds = 26;
		break;
	case 8:
		iNumberOfCompounds = 52;
		break;
	case 9:
		iNumberOfCompounds = 365;
		break;
	default:
		break;
	}

	

	//convert percentage into decimal
	dInterestRate = dInterestRate / 100;
	double dExponent = iNumberOfCompounds * dTime;
	dFinalAmount = dPrincipal * pow(1 + (dInterestRate * dTime),dExponent);

	return dFinalAmount;
	
}


