/**
 * \file Source.cpp
 *
 * \author Dalton Lauerman
 * This program is a simple GPA calculator
 * It calculates your GPA, Technical GPA, and Combined GPA
 */

#include <iostream>
#include <limits>
#include <stdexcept>

/** Main function
 * When the program is run, it will prompt the user with a series of questions:
 * How many classes? Grade? Number of credits for class? Was it a technical class?
 * It will then make the calculations based off these inputs.
 */
int main() {

	double total_credits = 0;  // Total Credits
	double tech_credits = 0;   // Total technical credits
	double gpa = 0;            // Sum of Grade * credits
	double total_tech = 0;     // Sum of Tech grade * credits
	int num_classes = 0;       // Number of classes   
	double grade = 0;          // Grade for each class
	double credits = 0;        // Credits for reach class
	int tech = 0;			   // Is it a technical class? 1 == yes 0 == no

	std::cout << "GPA and Tech GPA Calculator" << std::endl;

	while (true) {
		try {
			std::cout << "Enter yout total number of classes" << std::endl;
			std::cin >> num_classes;
			if (std::cin.fail()) {
				throw (num_classes);
			}
			else {
				break;
			}

		}
		catch (int fail) {
			std::cout << "Please enter a number" << std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
	}
	
	

	for(num_classes ; num_classes > 0 ; num_classes --) {
		while (true) {
			try {
				std::cout << "Enter your grade (0.0-4.0)" << std::endl;
				std::cin >> grade;
				if (grade < 0.0 || grade > 4.0) {
					throw (grade);
				}
				if (std::cin.fail()) {
					throw (grade);
				}
				else {
					break;
				}

			}
			catch (double grade_fail) {
				std::cout << "Please enter a number(0.0-4.0)" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
		}
		while (true) {
			try {
				std::cout << "Enter the amount of credits" << std::endl;
				std::cin >> credits;
				if (std::cin.fail()) {
					throw (credits);
				}
				else {
					break;
				}

			}
			catch (double fail) {
				std::cout << "Please enter a number" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
		}
		while (true) {
			try {
				std::cout << "Was it a technicl class? (yes == 1/no == 0)" << std::endl;
				std::cin >> tech;
				if (tech != 0 && tech != 1) {
					throw (tech);
				}
				if (std::cin.fail()) {
					throw (tech);
				}
				else {
					break;
				}

			}
			catch (int fail) {
				std::cout << "Please enter a number" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
		}
		

		if(tech == 1){
			tech_credits += credits;
			total_tech += (credits * grade);
		}
		total_credits += credits;
		gpa += (credits * grade);
	}
	double total_gpa = gpa / total_credits;               // Calculation to find total GPA
	double tech_gpa = total_tech / tech_credits;          // Calculation to find tech GPA
	double combined_gpa = (total_gpa + tech_gpa) / 2;     // Calculation to find combined GPA
	std::cout << "GPA: " << total_gpa << std::endl;
	std::cout << "Tech GPA: " << tech_gpa << std::endl;
	std::cout << "Combined GPA: " << combined_gpa << std::endl;
}