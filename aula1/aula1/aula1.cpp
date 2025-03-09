// aula1.cpp : Defines the entry point for the application.
//

#include "aula1.h"
#include <cstring>

using namespace std;

int encrypt(char* text, int key, char* cipher_text) {
	int i = 0;
	while (true) {
		if (text[i] == '\0') break;
		
		if (isalpha(text[i])) {
			if (isupper(text[i])) {
				cipher_text[i] = ((text[i] - 'A' + key) % 26) + 'A';
			}
			else {
				cipher_text[i] = ((text[i] - 'a' + key) % 26) + 'a';
			}
		}
		else cipher_text[i] = text[i];
		
		cout << i << " " << text[i] << " " << cipher_text[i] << endl;
		++i;
	}
	return 0;
}


int main()
{
	char text[100]{ };
	char cipher_text[100]{ };
	int key;

	cout << "Insert a text to be encrypted: ";
	cin.getline(text, 100);
	cout << "Insert displacement number: ";
	while (true) {
		if (cin >> key && key > 8) cout << "Choose a shorter displacement: ";
		else break;
	}

	 encrypt(text, key, cipher_text);

	 cout << "Encrypted text: " << cipher_text << endl;

	//cout << "Hello CMake." << endl;
	return 0;
}

