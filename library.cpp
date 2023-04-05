#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct book
{
	int Code, Edition;
	string Name;
	string Author_name;
	string Category;
	char is_available;
};

struct student
{
	int ID;
	string Name, borrowed_book[100];
};

const int MAX_SIZE = 1000;
student students[MAX_SIZE];
book books[MAX_SIZE];

void save_data(int n);
void read_data();

void main() {
	int nbooks;

	cout << "Enter number of books:	";

	cin >> nbooks;
	cin.ignore();

	for (int i = 0; i < nbooks; i++) {

		cout << "Enter book name: ";
		getline(cin, books[i].Name);

		cout << "Enter book Author's name: ";
		getline(cin, books[i].Author_name);

		cout << "Enter book Category: ";
		getline(cin, books[i].Category);

		cout << "Enter book edition: ";
		cin >> books[i].Edition;
		cin.ignore();

		cout << "Enter book code: ";
		cin >> books[i].Code;
		cin.ignore();

		cout << "Is book available: ";
		cin >> books[i].is_available;
		cin.ignore();
	}

	save_data(nbooks);

}

void save_data(int n) {
	fstream file;
	file.open("repo.txt", ios::out);

	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			file << books[i].Name << endl;
			file << books[i].Author_name << endl;
			file << books[i].Category << endl;
			file << books[i].Edition << endl;
			file << books[i].Code << endl;
			file << books[i].is_available << endl;
		}
		file.close();
	}

}