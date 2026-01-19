#include <iostream>
#include <iomanip>
#include <limits>

void inputGrades(double& g1, double& g2, double& g3) {
	std::cout << "Enter three grades: ";
	std::cin >> g1 >> g2 >> g3;
}

double calculateAverage(const double g1, const double g2, const double g3) {
	return (g1 + g2 + g3) / 3.0;
}

char getLetterGrade(const double average) {
	if (average >= 90.0) return 'A';
	else if (average >= 80.0) return 'B';
	else if (average >= 70.0) return 'C';
	else if (average >= 60.0) return 'D';
	else return 'F';
}

int main() {
	double grade1 = 0.0, grade2 = 0.0, grade3 = 0.0;
	int choice;
	do {
		std::cout << "Menu:\n"
		<< "1. Input Grades\n"
		<< "2. Calculate and Display Average\n"
		<< "3. Assign and Display Letter Grade\n"
		<< "4. Quit\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail() || choice < 1 || choice > 4) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
			continue;
		}

		switch (choice) {
			case 1:
				inputGrades(grade1, grade2, grade3);
				break;
			case 2: {
				double avg = calculateAverage(grade1, grade2, grade3);
				std::cout << std::fixed << std::setprecision(2);
				std::cout << "The average grade is: " << avg << "\n";
			}
			case 3: {
				double avg = calculateAverage(grade1, grade2, grade3);
				char letter = getLetterGrade(avg);
				std::cout << "The letter grade is: " << letter << "\n";
				break;
			}
			case 4:
				std::cout << "Goodbye!\n";
				break;
		}

	} while (choice != 4);

	return 0;
}