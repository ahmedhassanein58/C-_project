#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct book {
	int Code, Edition;
	string Name;
	string Author_name;
	string Category;
	char is_available;
};

struct student {
	int ID;
	string Name, borrowed_book;
};

int main() {
	int num;
	const int NUMBER_OF_BOOKS = 100;
	fstream file("repo.txt", ios::out);

	book books[NUMBER_OF_BOOKS];
	cout << "Enter the number of books: ";
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cout << "Enter the information of Book number #" << i << endl;
		cout << "Enter book name: ";
		cin >> books[i].Name;
		cout << "Enter author name : ";
		cin >> books[i].Author_name;
		cout << "Enter edition number: ";
		cin >> books[i].Edition;
		cout << "Availability: ";
		cin >> books[i].is_available;
		cout << "Enter book code: ";
		cin >> books[i].Code;
		cout << "Enter book category: ";
		cin >> books[i].Category;
		if (file.is_open()) {
			file << books[i].Name << '\n';
			file << books[i].Author_name << '\n';
			file << books[i].Edition << '\n';
			file << books[i].is_available << '\n';
			file << books[i].Code << '\n';
			file << books[i].Category << '\n';
			file.close();
		}
	}

	return 0;
}
