#include<iostream>
#include<string>
#pragma warning (disable: 4996)
using namespace std;
int palindrome(string str)
{
	int length = str.length();
	for (int i = 0; i < length / 2; i++)
	{
		if (str[i] != str[length - i - 1])
		{
			return 0;
			break;
		}
	}
	return 1;
}
void find_substring1(string str_for_search_in, string substring)
{
	bool flag = false;
	for (int i = 0; i < str_for_search_in.length() - substring.length(); i++)
	{
		if (str_for_search_in.substr(i, substring.length()) == substring)
		{
			cout << i << " ";
			flag = true;
			break;
		}
	}
	if (flag == false)
		cout << "NONE";
}
void find_substring2(string str_for_search_in, string substring)
{
	bool flag = false;
	for (int i = 0; i < str_for_search_in.length() - substring.length(); i++)
	{
		if (str_for_search_in.substr(i, substring.length()) == substring)
		{
			cout << i << " ";
			flag = true;
		}
	}
	if (flag == false)
		cout << "NONE";
}
void encrypt(char str_for_encrypt[100])
{
	char ch;
	int key;
	cout << "Enter a message to encrypt: ";
	cin.ignore();
	cin.getline(str_for_encrypt, 100);
	cout << "Enter key: ";
	cin >> key;
	for (int i = 0; str_for_encrypt[i] != '\0'; ++i) {
		ch = str_for_encrypt[i];
		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;
			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}
			str_for_encrypt[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;
			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}
			str_for_encrypt[i] = ch;
		}
	}
	cout << "Encrypted message: " << str_for_encrypt;
}
void menu()
{
	cout << "================menu===============" << endl;
	cout << "\n1.check palindrome";
	cout << "\n2.find_substring1";
	cout << "\n3.find_substring2";
	cout << "\n4.encrypt";
	cout << "\n5.text";
	cout << "\n6.end";
}
void text()
{
	{
		string s;
		cout << "enter s:";
		cin.ignore();
		getline(cin, s);
		string res = "";
		int i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == '"')
			{
				while (s[i] != '\0' && s[i] == '"') ++i;
				while (s[i] != '\0' && s[i] != '"')
				{
					res += s[i];
					++i;
				}
				if (res != "") cout << res << '|';
				res = "";
				if (s[i] == '\0') break;
				else ++i;
			}
			else ++i;
		}

	}
}
int main()
{
	string str;
	string str_for_search_in;
	string substring;
	char str_for_encrypt[100];
	int key;
	int chose;
	menu();
	do
	{
		cout << "\nenter chose:" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
			cout << "enter string:";
			cin.ignore();
			getline(cin, str);
			if (palindrome(str) == 1)
			{
				cout << "palindrome";
			}
			else
			{
				cout << " no palindrome";
			}
			break;
		case 2:
			cout << "enter str_for_search_in:";
			cin.ignore();
			getline(cin, str_for_search_in);
			cout << "enter substring:";
			cin.ignore();
			getline(cin, substring);
			find_substring1(str_for_search_in, substring);
			break;
		case 3:
			cout << "enter str_for_search_in:";
			cin.ignore();
			getline(cin, str_for_search_in);
			cout << "enter substring:";
			cin.ignore();
			getline(cin, substring);
			find_substring2(str_for_search_in, substring);
			break;
		case 4:
			encrypt(str_for_encrypt);
			break;
		case 5:
			text();
			break;
		case 6:exit(0); break;
		default:cout << "illegal";
		}
	} while (chose != 1 || chose != 2 || chose != 3 || chose != 4 || chose != 5 || chose != 6);
}