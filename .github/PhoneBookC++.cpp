
// PhoneBookC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//Arrays

const int arraySize = 100;
int PhoneNumbers[arraySize];
string Names[];

//Variables
bool stop;
int i = 0;
int entriesNum;
//Functions Identifiers
void Menu();
void Seperate();
void ShowPhonebook(int);
void ModifyEntry();
void AddEntry();
void DeleteEntry();
void Selection(int);
void NotValidEntry();
void Search();
int Choice();
void TerminateIfNeeded(bool&);


int main()
{
	
	cin >> entriesNum;
	
	while (!stop) {
		Menu();
		Selection(Choice());
		TerminateIfNeeded(stop);
	}
	
}

void Menu() {
	cout <<"Menu Options"<<endl;
	Seperate();
	cout << "1. Show Phonebook" << endl;
	Seperate();
	cout << "2. Enter/Modify entry" << endl;
	Seperate();;
	cout << "3. Delete an entrie" << endl;
	Seperate();
	cout << "4. Search" << endl;
	Seperate();
	cout << "Insert a number for any choice above and press Enter : " << endl;
}

void Selection(int c) {
	if (c == 1) {
		ShowPhonebook(entriesNum);
	}
	else if (c == 2) {
		cout << "You want to modify or Add new entry?" << endl << "1. Add New    " << "2. Modify";
		int mc= Choice();
		if (mc == 1) {
			AddEntry();
		}
		else if (mc == 2) {
			ModifyEntry();
		}		
	}
	else if (c == 3) {
		DeleteEntry();
	}
	else if (c == 4) {
		Search();
	}
	else {
		NotValidEntry();
	}
}

void ModifyEntry() {
	cout << "Give the id number of your entry " << endl;
	int c = Choice();
	cout << "Give the phone number of your new entry " << endl;
	int number;
	cin >> number;
	cout << "Give the name of your new entry " << endl;
	string name;
	cin >> name;
	PhoneNumbers[c] = number;
	Names[c] = name;

}

void AddEntry() {
	cout << "Give the id number of your entry "<<endl;
	int c = Choice();
	cout << "Give the phone number of your entry " << endl;
	int number;
	cin >> number;
	cout << "Give the name of your entry " << endl;
	string name;
	cin >> name;
	PhoneNumbers[c] = number;
	Names[c] = name;
	
}

void DeleteEntry() {
	cout << "Give the id number of the entry you want to delete" << endl;
	int c = Choice();
	
	PhoneNumbers[c] = 0;
	Names[c] = "";
}

void ShowPhonebook(int entriesNum) {
	i = 0;
	while (i !=arraySize) {
		cout << PhoneNumbers[i] << "  " << Names[i] << endl;
		i++;
	}
}

void Search() {
	cout << "Give the id number of the entry you want to search" << endl;
	int c = Choice();	
	cout <<PhoneNumbers[c]<< "  " << Names[c]<< endl;	
}

void Seperate() {
	string seperator = "__________________________________________________";
	cout << seperator << endl << endl;
}

int Choice() {
	int c;
	cin >> c;
	return c;
}

void NotValidEntry() {
	cout << "Not Valid Input...Try Again";
}

void TerminateIfNeeded(bool& stop) {
	string answer;
	cout << "You Want to stop using phonebook? " << endl << " Type yes or no" << endl;
	cin >> answer;
	if (answer == "yes") {
		stop = true;
	}
	else if (answer == "no") {
		stop = false;
	}
}