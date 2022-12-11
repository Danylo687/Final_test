#include <iostream> 
#include <Windows.h> 
#include <time.h> 
#include <functional> 
#include <algorithm> 
#include <fstream>
#include <vector> 
#include <map>
using namespace std;





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
	string login, password;
	string name, surname, fname;
	string adress;
	string number;
public:
	tester() {
		login = "Not set";
		password = "Not set";
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
	tester(string login, string password, string name, string surname, string fname, string adress, string number) {
		this->login = login;
		this->password = password;
		this->name = name;
		this->surname = surname;
		this->fname = fname;
		this->adress = adress;
		this->number = number;
	}

	void print() {
		cout << string(20, '-') << "\n";
		cout << "Login: " << login << "\n";
		cout << "Password: " << password << "\n";
		cout << "Name: " << name << "\n";
		cout << "Surame: " << surname << "\n";
		cout << "Fname: " << fname << "\n";
		cout << "Adress: " << adress << "\n";
		cout << "Number: " << number << "\n";
	}
	template <class T>
	void print(T a) {
		cout << string(20, '-') << "\n";
		cout << "Name: " << name << "\n";
		cout << "Surame: " << surname << "\n";
		cout << "Fname: " << fname << "\n";
		cout << "Adress: " << adress << "\n";
		cout << "Number: " << number << "\n";
	}

	void set() {
		cout << string(20, '-') << "\n";
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter fname: ";
		cin >> fname;
		cout << "Enter adress: ";
		cin >> adress;
		cout << "Enter number: ";
		cin >> number;
		cout << string(20, '-') << "\n";
	}

	void set(string login, string password) {
		cout << string(20, '-') << "\n";
		cout << "Enter name: ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter fname: ";
		cin >> fname;
		cout << "Enter adress: ";
		cin >> adress;
		cout << "Enter number: ";
		cin >> number;
		this->login = login;
		this->password = password;
		cout << string(20, '-') << "\n";
	}

	string getLogin() { return login; }
	string getPassword() { return password; }

	string getInfo() {
		string info = name + " " + surname + " " + fname + " " + adress + " " + number + "\n";
		return info;
	}
	string getAll() {
		string all = login + " " + password + " " + name + " " + surname + " " + fname + " " + adress + " " + number;
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

void printMap(map<string, string> m) {
	cout << string(20, '-') << "\n";
	for (auto el : m) {
		cout << el.first << " | " << el.second << "\n";
	}
	cout << string(20, '-') << "\n\n";

}

template <class T3>
void printAllTesters(vector<T3> v, map<string, string> m) {

	/*int i = 0;
	for (auto el : m) {
		cout << string(20, '-') << "\n";
		cout << el.first << " | " << el.second << "\n";
		v[i].print(); 
		i++;
		cout << string(20, '-') << "\n\n";
	}*/

	int i = 0;
	for (auto el : m) {
		cout << string(20, '-') << "\n";
		cout << v[i].getLogin() << " | " << v[i].getPassword() << "\n";
		v[i].print(1); 
		i++;
		cout << string(20, '-') << "\n\n";
	}

}


// Reading
void testersReadingFromFile(vector<tester>& testers, map<string, string>& tester_log) {

	fstream read_tester;
	read_tester.open("D:/IT steap/C++/Final/Tester.txt", fstream::in);

	string login, password, name, surname, fname, adress, number;

	while (!read_tester.eof()) {
		read_tester >> login >> password >> name >> surname >> fname >> adress >> number;

		tester t(login, password, name, surname, fname, adress, number);
		testers.push_back(t);
		tester_log.insert({ login, password });
	}

	read_tester.close();
}

// Writing
void testersWritingToFile(vector<tester> testers, map<string, string> tester_log) {
	fstream write_tester;
	write_tester.open("D:/IT steap/C++/Final/Tester.txt", fstream::out);

	int i = 0;
	for (auto el : tester_log) {
		//write_tester << el.first << " " << el.second << " ";
		int length = write_tester.tellg();
		if(length == 0)
			write_tester << testers[i].getAll();
		else
			write_tester << "\n" << testers[i].getAll();
		i++;
	}

	write_tester.close();
}


// Sign in
void testerSignIn(map<string, string> tester_log) {
	string login, password;

	system("cls");
	cout << "Sign in \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n";

	auto res = tester_log.find(login);
	if (res == tester_log.end()) cout << "Incorrect login\n";
	else {
		if (res->second != password) cout << "Incorrect password\n";
		else {
			cout << "Correct\n\n";
		}
	}
}

// Sign up
void testerSignUp(vector<tester>& testers, map<string, string>& tester_log) {
	string login, password;

	system("cls");
	cout << "Sign up \n";
	cout << string(20, '-') << "\n";
	cout << "Enter login: ";
	cin >> login;
	cout << "Enter password: ";
	cin >> password;
	cout << string(20, '-') << "\n\n";

	auto res = tester_log.find(login);
	if (res != tester_log.end()) cout << "This login is already used\n";
	else {
		tester t;
		t.set(login, password);
		t.print();
		tester_log.insert({ login, password });
		testers.push_back(t);
		cout << "Correct\n\n";
	}

}




int main() {
	srand(time(0));


	// Create tester
	vector<tester> testers;
	map<string, string> tester_log;


	// Testers reading from file
	testersReadingFromFile(testers, tester_log);

	// Testers writing to file
	//testersWritingToFile(testers, tester_log);


	// Menu
	int choice = m2();
	switch (choice)
	{
	case 0:
		testerSignIn(tester_log);
		break;
	case 1:
		testerSignUp(testers, tester_log);
		break;
	default:
		break;
	}


	printAllTesters(testers, tester_log);
	//cout << "\n\n" << string(100, '-') << "\n\n";
	//printMap(tester_log);
	//printVector(testers);

	testersWritingToFile(testers, tester_log);





	return 0;
}
