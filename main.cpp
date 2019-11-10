//Unit 5 Assignment Part 1
//Bowlby, Dr_T 9-21-2019 COSC 1436-57005
/*
	Input Validation with Ref Functions 
	A cleaner way to do input validation
	Validating input, an essential process.
	Source: http://stackoverflow.com/questions/514420/how-to-validate-numeric-input-c
	Keeping Dr. McMillan from breaking my code, defend against "dark side of the force",
	and/or legitimate user error. 
	//Try and Catch blocks are used in error checking
	Teacher: Dr. Tyson McMillan 
*/
#include <cstdlib>  // Provides EXIT_SUCCESS
#include <iostream>  // Provides cout, cerr, endl
#include "Input_Validation_Extended.h" // Provides getValidatedInput<T>(), a header File with a Template Class
                              // Extended 2-11-2016 by Dr. McMillan to add validation methods by datatype
#include<string> //for string manipulation
#include<sstream> //for string manipulation and comparison
#include<string>
#include<locale> //to use toupper() transform char
#include<iomanip>
using namespace std;


double weeklyPay(double, double,string);// function prototype
double getNetPay(double, double,string);// function prototype 
void convertLower(string);
void convertUpper(string);
locale loc;

int main( )
{
  //Unit 5 Part 2
  



      
         //a function call for each person - no input from the console for part 1
         cout << fixed << setprecision(2);//setting the decimal for $$
         cout << weeklyPay(39, 125, "David") << endl;
         cout << weeklyPay(39, 65.78,"Caleb") << endl;
         cout << weeklyPay(40, 90.75, "Alejandra") << endl;
         cout << getNetPay(32.5, 55.25, "\nDr.T") << endl;
         
          
         
         

       
  return 0;
}


double weeklyPay(double hours, double rate, string name)
{// complete the function definition
double netPay = 0.0, grossPay = 0.0, taxableWages = 0.0;
double ss = 0.062, med = 0.0145, sSwages = 0.0, medWages = 0.0;
double FIT = 0.010, fitTax = 0.0, dental = 0.0, retirement = 0.0;
double clockHours = 40.0, overtimeRate = 2.0;
locale loc;
string status = "";
string reset = "\x1b[0m";
string color = "\x1b[" + to_string(32) + ";4m"; //green and underlined 

//display the name on screen CAP and in color
cout << color << endl; // call color function
for(int i = 0; i < name.length(); i++)
{
  cout << toupper(name[i], loc);
}
cout << reset << endl; //a line after the name

//determine the status of the employee
/*
if(empType == 1)
{
  status = "Fulltime";
}
else if(empType == 2)
{
  status = "Parttime";
}
else
{
  status = "Error ";
}*/


FIT = (rate < 15.0) ? 0.12 : 0.15; //set FIT based upon rate
cout << "FIT Rate: " << FIT << endl;
grossPay = (hours <= clockHours) ? (hours * rate): ((clockHours * rate) + (hours - clockHours) * (overtimeRate * rate));
cout << "Gross Pay: " << grossPay << endl;

taxableWages = grossPay - (dental + retirement);
fitTax = taxableWages * FIT; //less pre-tax deductions
cout << "Taxable Wages: $" << taxableWages << endl;

sSwages = grossPay * ss;
medWages = grossPay * med;
cout << "SSDed = $" << sSwages << endl;
cout << "MedDed = $" << medWages << endl;

netPay = grossPay - (dental + retirement + fitTax + sSwages + medWages);

cout << "$";
return netPay;
}
double getNetPay(double hours, double rate, string name)
 {
   locale loc;
   for (int i =0; i < name.length(); i++)
  {
    cout << toupper(name[i], loc);
  }
  cout << endl;
   return (hours * rate);
 }

void convertLower(string a)//tolower code
{
  for (int i =0; i < a.length();i++)
  {
    cout << tolower(a[i], loc);
  }
}

void convertUpper(string a)//toupper code
{
  for (int i =0; i < a.length(); i++)
  {
    cout << toupper(a[i], loc);
  }
}




