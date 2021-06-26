/*
	Wesley Kim
	November 30, 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int MAX = 30;

void getData(int idArray[MAX], ifstream&fin);
int binarySearch(int array[MAX], int id, int start, int end);

int main()
{
	ifstream fileIn("ids.txt");
	if (!fileIn)
	{
		cout << "FILE NOT FOUND";
		return 1;
	}
	
	int idArray[MAX] = {0};
	
	getData(idArray, fileIn);
	
	int targetId = 0;
	cout << "Enter employee ID: " << endl;
	cin >> targetId;
	
	int idIndex = 0, startIndex = 0;
	idIndex = binarySearch(idArray, targetId, startIndex, MAX);
	
	if (idIndex == -1)
		cout << "ID NOT FOUND" << endl;
	else
		cout << "ID Index: " << idIndex << endl;
	
	fileIn.close();
	return 0;
}

void getData(int idArray[MAX], ifstream&fin)
{
	int id = 0, index = 0;
	while (fin >> id)
	{
		idArray[index] = id;
		index++;
	}
}

int binarySearch(int array[MAX], int id, int start, int end)
{
	int mid = 0, holder = 0;
	mid = start + (end-start)/2;
	holder = array[mid];
	if (((mid-start)==0) && (holder != id))
	{
		return -1;
	}
	else if (holder == id)
	{
		return mid;
	}
	else if (holder < id)
	{
		return binarySearch(array, id, mid, end);
	}
	else
	{
		return binarySearch(array, id, start, mid);
	}
}

/* TEST CASE 1
Enter employee ID:
1311
ID Index: 17

--------------------------------
Process exited after 2.864 seconds with return value 0
Press any key to continue . . .
*/

/* TEST CASE 2
Enter employee ID:
1855
ID Index: 26

--------------------------------
Process exited after 1.683 seconds with return value 0
Press any key to continue . . .
*/

/* TEST CASE 3
Enter employee ID:
2000
ID NOT FOUND

--------------------------------
Process exited after 2.278 seconds with return value 0
Press any key to continue . . .
*/

/* TEST CASE 4
Enter employee ID:
1101
ID Index: 0

--------------------------------
Process exited after 1.105 seconds with return value 0
Press any key to continue . . .
*/
