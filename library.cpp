#include <iostream>
#include <fstream>
#include <sstream>
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
	string Name;
	string password;
};

const int MAX_SIZE = 500;
book borrowed_book[MAX_SIZE];
int num_of_books;
int nstudents;
int borrowed;
student students[150];
book books[MAX_SIZE];

void save_data();
void read_data();

int main() {

	read_data();

	cout << " first book num of edition is: " << books[0].Edition << " and his name is " << books[0].Name << endl;
	cout << "first students name is : " << students[0].Name << " and his ID is " << students[0].ID << endl;
	cout << "Enter number of books: ";

	cin >> num_of_books;
	cin.ignore();

	for (int i = 0; i < num_of_books; i++) {

		cout << "Enter The name of the book: ";
		getline(cin, books[i].Name);

		cout << "Enter the author name of the book: ";
		getline(cin, books[i].Author_name);

		cout << "Enter the category of the book: ";
		getline(cin, books[i].Category);

		cout << "Enter the code of the book: ";
		cin >> books[i].Code;
		cin.ignore();

		cout << "Enter the book edition: ";
		cin >> books[i].Edition;
		cin.ignore();

		cout << "Enter availibility: ";
		cin >> books[i].is_available;
		cin.ignore();

		cout << "=======================\n";

	}

	cout << "Enter the number of students: ";
	cin >> nstudents;
	cin.ignore();
	for (int i = 0; i < nstudents; i++) {

		cout << "Enter the name of the student: ";
		getline(cin, students[i].Name);

		cout << "Enter the ID of the student: ";
		cin >> students[i].ID;
		cin.ignore();

		cout << "Enter the password of the student: ";
		getline(cin, students[i].password);

		cout << "Enter number of borrowed books by students: ";
		cin >> borrowed;
		cin.ignore();

		for (int j = 0; j < borrowed; j++) {

			cout << "Enter book name: ";
			getline(cin, borrowed_book[j].Name);

			cout << "Enter book author's name: ";
			getline(cin, borrowed_book[j].Author_name);

			cout << "Enter book category: ";
			getline(cin, borrowed_book[j].Category);

			cout << "Enter book code: ";
			cin >> borrowed_book[j].Code;

			cout << "Enter book edition: ";
			cin >> borrowed_book[j].Edition;

		}

	}

	save_data();
	return 0;
}

void save_data() {
	//save data student
	fstream file;

	file.open("students.txt", ios::out);
	if (file.is_open()) {

		for (int i = 0; i < nstudents; i++) {
			file << students[i].Name << ',' << students[i].ID << ',' << students[i].password;

			file << endl;
		}

		file.close();
	}

	// save data books
	file.open("books.txt", ios::out);
	if (file.is_open()) {

		for (int i = 0; i < num_of_books; i++) {
			file << books[i].Name << ',' << books[i].Author_name << ',' << books[i].Category << ','
				<< books[i].Code << ',' << books[i].Edition << ',' << books[i].is_available << endl;

		}

		for (int j = 0; j < borrowed; j++) {
			file << borrowed_book[j].Name << ',' << borrowed_book[j].Author_name << ',' << borrowed_book[j].Category <<
				',' << borrowed_book[j].Code << ',' << borrowed_book[j].Edition;
		}

		file.close();
	}
}

void read_data() {
	fstream file;
	file.open("students.txt", ios::in);

	// read data and put it into students array
	if (file.is_open()) {

		string str;
		int i = 0;

		while (getline(file, str)) {

			stringstream ss(str);
			getline(ss, students[i].Name, ',');

			string str2;
			getline(ss, str2, ',');
			students[i].ID = stoi(str2);

			getline(ss, students[i].password);
			i++;
		}

		file.close();
	}

	// read data and put it into books array

	fstream file2;
	file2.open("books.txt", ios::in);

	if (file2.is_open()) {

		string str;
		int j = 0;

		while (getline(file2, str)) {
			stringstream ss(str);

			getline(ss, books[j].Name, ',');
			getline(ss, books[j].Author_name, ',');
			getline(ss, books[j].Category, ',');

			string str2;
			getline(ss, str2, ',');
			books[j].Code = stoi(str2);

			string str3;
			getline(ss, str3, ',');

			books[j].Edition = stoi(str3);
			ss >> books[j].is_available;
			j++;
		}

		file.close();
	}

	// for borrowed books
	file2.open("books.txt", ios::in);
	if (file2.is_open()) {

		string str;
		int k = 0;


		while (getline(file2, str)) {
			stringstream ss(str);

			getline(ss, borrowed_book[k].Name, ',');
			getline(ss, borrowed_book[k].Author_name, ',');
			getline(ss, borrowed_book[k].Category, ',');

			string str2;
			getline(ss, str2, ',');
			borrowed_book[k].Code = stoi(str2);

			string str3;
			getline(ss, str3, ',');

			borrowed_book[k].Edition = stoi(str3);
			ss >> borrowed_book[k].is_available;
			k++;
		}

		file2.close();
	}
	
}