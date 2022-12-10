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
void testerSignIn() {

}




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


void menu() {
	int n = m2();
}


class tester {
	string name, surname, fname;
	string adress;
	string number;
public:
	tester() {
		name = "Not set";
		surname = "Not set";
		fname = "Not set";
		adress = "Not set";
		number = "Not set";
	}
	tester(string name, string surname, string fname, string adress, string number) {
		this->name = name;
		this->surname = surname;
		this->fname = fname;
		this->adress = adress;
		this->number = number;
	}

	void print() {
		cout << string(20, '-') << "\n";
		cout << "Name: " << name << "\n";
		cout << "Surame: " << surname << "\n";
		cout << "Fname: " << fname << "\n";
		cout << "Adress: " << adress << "\n";
		cout << "Number: " << number << "\n";
	}

	string getName() { return name; }

	string getAll() { 
		string all = name + " " + surname + " " + fname + " " + adress + " " + number + "\n";
		return all; 
	}
};


// Print
template <class T>
void printVector(vector<T> v) {
	cout << string(50, '-') << "\n\n";
	for (int i = 0; i < v.size(); i++)
		v[i].print();
	cout << string(50, '-') << "\n";

}

template <class T2>
void printAllTesters(vector<T2> v, map<string, string> m) {

	int i = 0;
	for (auto el : m) {
		cout << string(20, '-') << "\n";
		cout << el.first << " | " << el.second << "\n";
		v[i].print(); i++;
		cout << string(20, '-') << "\n\n";
	}
		
}


// Reading
void testersReadingFromFile(vector<tester>& testers, map<string, string>& tester_log) {
	string key;
	string value;

	fstream read_tester;
	read_tester.open("D:/IT steap/C++/Final/Tester.txt", fstream::in);

	string login, password, name, surname, fname, adress, number;

	while (!read_tester.eof()) {
		read_tester >> key >> value >> name >> surname >> fname >> adress >> number;

		tester t(name, surname, fname, adress, number);
		testers.push_back(t);
		tester_log.insert({ key, value });
	}

	read_tester.close();
}

// Writing
void testersWritingToFile(vector<tester> testers, map<string, string> tester_log) {
	fstream write_tester;
	write_tester.open("D:/IT steap/C++/Final/Tester.txt", fstream::out);

	int i = 0;
	for (auto el : tester_log) {
		write_tester << el.first << " " << el.second << " ";
		write_tester << testers[i].getAll();
		i++;
	}

	write_tester.close();
}





int main() {
	srand(time(0));


	// Create tester
	vector<tester> testers;
	map<string, string> tester_log;


	// Testers reading from file
	testersReadingFromFile(testers, tester_log);

	
	











	return 0;
}
