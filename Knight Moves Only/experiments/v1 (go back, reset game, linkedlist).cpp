#include<iostream>
#include<cstdlib>
#include<string.h>
using namespace std;

struct node
{
	string element;
	struct node *prev;
	struct node *next;
};

// ------------------------------------------------ Black Pieces -------------------------------------------------
string 	Rook 		= "B_Rk";		// Black Rook
string 	Knight 		= "B_Kn";		// Black Knight
string 	Bishop 		= "B_Bi";		// Black Bishop
string 	King 		= "B_Kg";		// Black King
string 	Queen 		= "B_Qn";		// Black Queen
string 	Pawn 		= "B_Pn";		// Black Pawn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ------------------------------------------------ White Pieces -------------------------------------------------
string 	rook 		= "W_Rk";		// White Rook
string 	knight 		= "W_Kn";		// White Knight
string 	bishop 		= "W_Bi";		// White Bishop
string 	king 		= "W_Kg";		// White king
string 	queen 		= "W_Qn";		// White queen
string 	pawn 		= "W_Pn";		// White pawn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

string 	EMPTY		= "    ";		// Empty Space

int 	Game_End	= 0;

// ------------------------------------------------- Chess Board -------------------------------------------------
string arr[8][8] = {	Rook, 		Knight, 	Bishop, 	King,  		Queen, 		Bishop, 	Knight, 	Rook,
						Pawn,		  Pawn,		  Pawn,		Pawn,		 Pawn,		  Pawn,		  Pawn,		Pawn,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						pawn,		  pawn,		  pawn,		pawn,		 pawn,		  pawn,		  pawn,		pawn,
						rook, 		knight, 	bishop,    queen,  		 king, 		bishop, 	knight, 	rook 	};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
int newI = 0, newJ = 0;


// ----------------------------------------------- Start of Classes ----------------------------------------------
class chess
{	
	public:
		void displayboard();
};

class Kn: public chess
{
	public:
		void knight();
		
		void KnightMoves(int, int);
		
		bool MoveBlackKnightTo(int, int);
		
		bool MoveWhiteKnightTo(int, int);
		
		bool PieceExists(int, int);
		
		bool ValidKnightMove(int, int, int, int);
		
		bool FindKnight(int, int);
		
		bool GameEnd(int, int);
};

class linked_list
{
	private:
		node *head;
		node *tail;
		
	public:
		linked_list()
		{
			head = NULL;
			tail = NULL;
		}
		
		void insert(string newarr)
		{
			if(head == NULL && tail == NULL)
			{
				node* newnode = new node;
				newnode->element = newarr;
				newnode->next = head;
				newnode->prev = tail;
				
				head = newnode;
				tail = newnode;
			}
			else
			{
				node* newnode = new node;
				newnode->element = newarr;
				newnode->next = head;
				newnode->prev = tail;
				
				head->prev = newnode;
				head = newnode;
			}
			
		}		
		
		void traverse();
		
		void TransferBoard();	
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  End  of Classes ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


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

linked_list trans;
linked_list reset;
linked_list back;

void linked_list::traverse()
{
	node *ptr = head;
	
	int i = 7;
	int j = 7;
	
	for(int k = 1; k <=64; k++)
	{
		arr[i][j] = ptr->element;
		j--;
		if(j<0)
		{
			j = 7;
			i--;
		}

		ptr=ptr->next;
	}
}

void linked_list::TransferBoard()
{
	
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 8; j++)
		{
			linked_list::insert(arr[i][j]);
		}
	}
}

// ------------------------------------------------ Start of Main ------------------------------------------------
int main()
{
	reset.TransferBoard();
	
	char Reset;
	char Move;
	char Back;
	Move = 'Y';
	
	Kn move;
	chess call;
	
	GroupDetails();
	system("pause");
	system("cls");
	
	back.TransferBoard();
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
			cout << "\n";
			cout << "\t\t\t *** Reset Game ?   *** (y/n): ";
			cin  >> Reset;
			if(Reset == 'Y' || Reset == 'y')
			{
				reset.traverse();
				call.displayboard();
			}
			cout << "\t\t\t *** Go Back once ? *** (y/n): ";
			cin  >> Back;
			if(Back == 'Y' || Back == 'y')
			{
				back.traverse();
				call.displayboard();
			}
			cout << "\t\t\t *** Move Knight ?  *** (y/n): ";
			cin  >> Move;
			if(Move == 'Y' || Move == 'y')
			{
				back.TransferBoard();
				move.knight();
			}
		}
		
	}while(Move == 'Y' || Move == 'y');
	
	if(Move == 'n' || Move == 'N')
	{
		cout << "\n\t\t *** Thanks for Playing & Using Knight in Our Chess Game *** \n" << endl;
	}
	
	cout << endl << endl;
	system("pause");
	return 0;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  End  of Main ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


// ---------------------------------------------- Start of Functions ---------------------------------------------
void chess::displayboard()
{
	cout << endl;
	int k = 1;
	
	cout << "\t\t ___________________________________________________________________ \n";
	cout << "\t\t        1 	2	3 	4	5	6	7	8 \n";
	
	for(int i = 0; i<8; i++)
	{
		for(int j = 0; j<8; j++)
		{
			if(j == 0)
			{
				cout << "\t\t " << k <<"- [ ";
			}
			
			cout << arr[i][j];
			
			if(j < 7)
			{
				cout << " ][ ";
			}
			
			if(j == 7)
			{
				cout << " ] " << endl;
				k++;
			}
		}
	}
	k = 1;
}

void Kn::knight()
{
	
	
	int SelectPosX, SelectPosY;
	
	cout << "\n\t Select Position of Knight (like: 1 2) : ";
	cin >> SelectPosX >> SelectPosY;
	
	if(arr[SelectPosX-1][SelectPosY-1] == Knight)
	{
		KnightMoves(SelectPosX, SelectPosY);
	}
	else if(arr[SelectPosX-1][SelectPosY-1] == "W_Kn")
	{
		KnightMoves(SelectPosX, SelectPosY);
	}
	else
	{
		cout << "\n\t\t *** Position of Knight Not Found *** " << endl;
	}
	
}

bool Kn::FindKnight(int X, int Y)
{
	if(X >= 1 && X <= 8 && Y >=1 && Y <=8)
	{
		for(int i = 0; i<8; i++)
		{
			for(int j = 0; j<8; j++)
			{
				if(arr[i][j] == Knight || arr[i][j] == "W_Kn")
				{
					return true;
				}
			}
		}
	}
	else
	{
		return false;
	}
}

bool Kn::ValidKnightMove(int X, int Y, int PosX, int PosY)
{
	if(X == PosX-2 && Y == PosY+1 || X == PosX-1 && Y == PosY+2 || X == PosX+1 && Y == PosY+2 || X == PosX+2 && Y == PosY+1 || X == PosX+2 && Y == PosY-1 || X == PosX+1 && Y == PosY-2 || X == PosX-1 && Y == PosY-2 || X == PosX-2 && Y == PosY-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Kn::PieceExists(int PosX, int PosY)
{
	if(arr[PosX-1][PosY-1] != "    ")
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Kn::MoveWhiteKnightTo(int X, int Y)
{
	int PositionX, PositionY;
	
	if(FindKnight(X, Y) == true)
	{
		cout << "\t\t Position To Place White's Knight : ";
		cin >> PositionX >> PositionY;
		
		if(ValidKnightMove(PositionX, PositionY, X, Y) == true)
		{
			if(GameEnd(PositionX, PositionY) == true)
			{
				Game_End = 1;
				
				arr[PositionX-1][PositionY-1] = "W_Kn";
				return true;
			}
			else
			{
				arr[PositionX-1][PositionY-1] = "W_Kn";
				
				return true;
			}
			
			return true;	
		}
		else if (ValidKnightMove(PositionX, PositionY, X, Y) == false)
		{
			cout << "\t\t *** Wrong Input *** " << endl;
			system("pause");
			
			return false;
		}
	}
}

bool Kn::MoveBlackKnightTo(int X, int Y)
{
	int PositionX, PositionY;
	
	if(FindKnight(X, Y) == true)
	{
		cout << "\t\t Position To Place Black's Knight : ";
		cin >> PositionX >> PositionY;
		
		if(ValidKnightMove(PositionX, PositionY, X, Y) == true)
		{
			if(GameEnd(PositionX, PositionY) == true)
			{
				Game_End = 1;
				
				arr[PositionX-1][PositionY-1] = "B_Kn";
				return true;
			}
			else
			{
				arr[PositionX-1][PositionY-1] = "B_Kn";
				
				return true;
			}
			
			return true;	
		}
		else if (ValidKnightMove(PositionX, PositionY, X, Y) == false)
		{
			cout << "\t\t *** Wrong Input *** " << endl;
			system("pause");
			
			return false;
		}
	}
}

void Kn::KnightMoves(int PosX, int PosY)
{
	if(PieceExists(PosX, PosY) == false)
	{
		return;
	}
	else if(arr[PosX-1][PosY-1] == Knight)
	{	
	
		if(MoveBlackKnightTo(PosX, PosY) == true)
		{
			arr[PosX-1][PosY-1] = EMPTY;
		}
		
		displayboard();
	}
	else if(arr[PosX-1][PosY-1] == "W_Kn")
	{	
	
		if(MoveWhiteKnightTo(PosX, PosY) == true)
		{
			arr[PosX-1][PosY-1] = EMPTY;
		}
		
		displayboard();
	}
}

bool Kn::GameEnd(int PosX, int PosY)
{
	if(arr[PosX-1][PosY-1] == King)
	{
		cout << "\n\t\t *** Game has concluded by White's victory *** " << endl;
		
		return true;
	}
	else if(arr[PosX-1][PosY-1] == king)
	{
		cout << "\n\t\t *** Game has concluded by Black's victory *** " << endl;
		
		return true;
	}
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  End  of Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

