#include <iostream>
#include <string>
using namespace std;

char alphabet[26] = { 'a', 'b', 'c' , 'd', 'e',
					 'f', 'g', 'h' , 'i', 'j',
					 'k', 'l', 'm' , 'n', 'o',
					 'p', 'q', 'r' , 's', 't',
					 'u', 'v', 'w' , 'x', 'y',
					 'z' };

// вычисляет позицию в алфавите, если буквы нет, то возвращает -1
int charPos(char ch) {
	for (int i = 0; i < 26; i++) {
		if (ch == alphabet[i]) {
			return ++i;
		}
	}
	return -1;
}

string encodeString(string textToEncode) {
	string encodedString = "";
	for (int i = 0; i < textToEncode.length(); i++) {
		char charToEncode = textToEncode.at(i);
		int alpPos = charPos(charToEncode);

		if (alpPos != -1) {
			char ch = alphabet[(alpPos + i - 1) % 26];
			encodedString.push_back(ch);
		}
		else {
			encodedString.push_back(charToEncode);
		}
	}
	return encodedString;
}

int decodeCharPos(char ch, int pos) {
	for (int i = 0; i < 26; i++) {
		int alpPos = i + 1;
		char encodedCh = alphabet[(alpPos + pos - 1) % 26];

		if (ch == encodedCh) {
			return i;
		}
	}
	return -1;
}

string decodeString(string textToDecode) {
	string decodedString = "";

	for (int i = 0; i < textToDecode.length(); i++) {
		int pos = decodeCharPos(textToDecode.at(i), i);
		if (pos != -1) {
			decodedString.push_back(alphabet[pos]);
		}
		else {
			decodedString.push_back(textToDecode.at(i));
		}
	}

	return decodedString;
}

int main() {

	string stringToEncode = "Hello, world!";
	string encodedString = encodeString(stringToEncode);
	string decodedString = decodeString(encodedString);
	cout << "Encoded: " << encodedString << endl;
	cout << "Decoded: " << decodedString << endl;

	return 0;
}
