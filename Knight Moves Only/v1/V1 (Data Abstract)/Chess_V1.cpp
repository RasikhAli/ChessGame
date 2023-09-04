#include<iostream>
#include"knight.h"
using namespace std;

void GroupDetails()
{
	cout << "\n";
	cout << "\t\t\t    *** DSA GROUP MEMBERS *** 	" << endl;
	cout << "\t\t\t  BSEM-F18-191 	Muhammad Imran 	" << endl;
	cout << "\t\t\t  BSEM-F19-101 	Muhammad Ehsan	" << endl;
	cout << "\t\t\t  BSEM-F19-062 	Ahmed Naeem 	" << endl;
	cout << "\t\t\t  BSEM-F19-060 	Rasikh Ali 		" << endl;
	
	cout << "\n\n";
	cout << "\t\t    *** Project: Chess Game :: Version 1 *** 	" << endl;
	cout << "\t\t\t  1- Functional Chess								" << endl;
	cout << "\t\t\t  2- Movements of Knight 							" << endl;
	cout << "\n\n";
}

// ------------------------------------------------ Start of Main ------------------------------------------------
int main()
{
	char Option;
	Option = 'Y';
	
	Kn move;
	chess call;
	
	GroupDetails();
	system("pause");
	system("cls");
	
	call.displayboard();
	move.knight();
	
	do
	{	
		if(Game_End == 1)
		{
			cout << "\n\t\t *** Thanks for Playing & Using Knight in Our Chess Game *** \n" << endl;
			
			break;
		}
		else if(Game_End == 0)
		{ 
			cout << "\t\t Move Knight? (y/n): ";
			cin  >> Option;
			move.knight();
		}
	}while(Option == 'Y' || Option == 'y');
	
	if(Option == 'n' || Option == 'N')
	{
		cout << "\n\t\t *** Thanks for Playing & Using Knight in Our Chess Game *** \n" << endl;
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  End  of Main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


