#include <iostream> 
#include <Windows.h> 
#include <time.h> 
#include <functional> 
#include <algorithm> 
#include <fstream>
#include <vector> 
#include <map>
using namespace std;


// Sign in





// Menu
int m1() {
	int choice;
	cout << string(20, '-') << "\nTester - 0 \nAdmin  - 1\n" << string(20, '-') << "\nEnter choice: ";
	cin >> choice;
	return choice;
}
int m2() {
	int choice = m1();
	switch (choice)
	{
	case 0:
		// Tester
		system("cls");
		cout << "Tester\n";
		cout << string(20, '-') << "\nSign in - 0\n";
		cout << "Sign up - 1\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice;
		break;
	case 1:
		// Admin
		system("cls");
		cout << "Admin\n";
		cout << string(20, '-') << "\nSign in - 0\n";
		cout << "Sign up - 1\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice + 10;
		break;
	default:
		break;
	}
}

int m3() {
	int choice = m2();

	switch (choice)
	{
		// Tester
	case 10:
		// Sign in
		system("cls");
		cout << "Tester\n";
		cout << string(20, '-') << "\nSign in - 0\n";
		cout << "Sign up - 1\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice;
		break;
	case 1:
		// Admin
		system("cls");
		cout << "Admin\n";
		cout << string(20, '-') << "\nSign in - 0\n";
		cout << "Sign up - 1\n" << string(20, '-');
		cout << "\nEnter choice: ";
		cin >> choice;
		return choice + 10;
		break;
	default:
		break;
	}
}


void menu() {
	int n = m3();
}






int main() {
	srand(time(0));

	// Tester log
	map<string, string> tester_log;


	string key;
	string value;

	fstream fs;
	fs.open("D:/IT steap/C++/Final/Tester.txt", fstream::in);

	string name, surname, fname, adress, tel;

	while (!fs.eof()) {
		fs >> key >> value >> name >> surname >> fname >> adress >> tel;
		tester_log.insert({ key, value });
	}
	for (auto elem : tester_log)
		cout << elem.first << " : " << elem.second << "\n";
	cout << name << "-" << surname << "-" << fname << "-" << adress << "-" << tel;


	// Menu
	//menu();
	










	return 0;
}
