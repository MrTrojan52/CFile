#define SIZE 6
#define LEN 50
#define DOWN_ARROW 80
#define UP_ARROW 72

#include "CFile.h"
#include <iostream>
#include <conio.h>
int menu();
using namespace std;
int main()
{
	sMyData MyData;
	MyData.fk = 1.2;
	MyData.n = 9;
	char fName[100];
	int choice;
	CMyDataFile A;
	A.setMyData(MyData);
	do
	{
		switch (choice = menu())
		{
		case 1:
		{
			cout << "Enter file name: ";
			cin >> fName;
			break;
		}
		case 2:
		{

			if (A.Open(fName, CFile::modeRead) != NULL)
			{
				int n = -1;
				cout << "How many characters to read: ";
				do
				{
					cin >> n;
				} while (n <= 0);

				char * buf = new char[n];
				A.Read(buf, sizeof(char), n);
				system("cls");
				A.Close();
				for (int i = 0; i < n; i++)
				{
					cout << buf[i] << " ";
				}

			}
			else
			{
				cout << "Unable to open file";
			}
			_getch();
			break;
		}
		case 3:
		{
			if (A.Open(fName, CFile::modeWrite) != NULL)
			{
				int n = 0;
				cout << "How many characters to write: ";
				cin >> n;
				char * buf = new char[n];
				cin >> buf;
				A.Write(buf, sizeof(char), n);
				A.Close();
				cout << endl << "Success" << endl;
			}
			else
			{
				cout << "Unable to open file";
			}
			_getch();
			break;
		}
		case 4:
		{
			if (A.Open(fName, CFile::modeAppend) != NULL)
			{
				int n = 0;
				cout << "How many characters to write: ";
				cin >> n;
				char * buf = new char[n];
				cin >> buf;
				A.Write(buf, sizeof(char), n);
				A.Close();
				cout << endl << "Success" << endl;
			}
			else
			{
				cout << "Unable to open file";
			}
			_getch();
			break;
		}
		case 5:
			if (A.Open(fName, CFile::modeRead) != NULL)
			{
				cout << "File size: " << A.GetLength() << " bytes" << endl;
			}
			else
			{
				cout << "Unable to open file";
			}
			_getch();
			break;
		case 6:
			return 0;

		default:
			break;
		}
	} while (true);






	return 0;


}


int menu()
{
	char a[SIZE][LEN] = {
		"Set Filename",
		"Read from File",
		"Write to File",
		"Add to File",
		"Size of File",
		"Exit"
	};


	int choice = 0;
	int Key = 0;



	do
	{
		system("cls");
		for (int i = 0; i < SIZE; i++)
		{
			if (choice == i)
			{
				cout << "\t>> " << a[i] << endl << endl;

			}
			else
			{
				cout << "\t" << a[i] << endl << endl;

			}
		}
		Key = _getch();
		if (Key == 224)
		{
			Key = _getch();
			switch (Key)
			{
			case UP_ARROW:
				if (choice - 1 >= 0)
				{
					choice--;
				}
				else
				{
					choice = SIZE - 1;
				}
				break;
			case DOWN_ARROW:
				if (choice + 1 < SIZE)
				{
					choice++;
				}
				else
				{
					choice = 0;
				}
				break;
			default:
				break;
			}
		}

	} while (Key != 13);
	system("cls");
	return choice + 1;



}
