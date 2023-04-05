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
	string password;
};

const int MAX_SIZE = 1000;
int n_borrowed_books;

student students[MAX_SIZE];
book books[MAX_SIZE];

void save_data_books(int n);
void save_data_students(int n);
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

	save_data_books(nbooks);


	int nStudents;

	cout << "Enter number of students: ";
	cin >> nStudents;
	cin.ignore();

	for (int i = 0; i < nStudents; i++) {
		cout << "Enter student name: ";
		getline(cin, students[i].Name);

		cout << "Enter student password: ";
		getline(cin, students[i].password);

		cout << "Enter student ID: ";
		cin >> students[i].ID;
		cin.ignore();


		cout << "Enter number of borrowed books: ";
		cin >> n_borrowed_books;
		cin.ignore();

		cout << "Enter borrowed books names: ";
		for (int j = 0; j < n_borrowed_books; j++) {
			getline(cin, students[i].borrowed_book[j]);
		}
	}

	save_data_students(nStudents);
	
	read_data();
}

void save_data_books(int n) {
	fstream file;
	file.open("repo.txt", ios::out);

	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			file << books[i].Name << '\n';
			file << books[i].Author_name << '\n';
			file << books[i].Category << '\n';
			file << books[i].Edition << '\n';
			file << books[i].Code << '\n';
			file << books[i].is_available << '\n';
		}
		file.close();
	}

}


void save_data_students(int n) {
	fstream file;
	file.open("repo.txt", ios::app);

	if (file.is_open()) {
		for (int i = 0; i < n; i++) {
			file << students[i].Name << '\n';
			file << students[i].ID << '\n';
			file << students[i].password << '\n';
			for (int j = 0; j < n_borrowed_books; j++) {
				file << students[i].borrowed_book[j] << '\n';
			}
		}
	}

}


void read_data() {
	string word;

	ifstream in_file;
	
	in_file.open("repo.txt", ios::in);
	if (in_file.is_open()) {
		while (getline(in_file, word)) {
			cout << word << '\n';
		}
		in_file.close();
	}
}