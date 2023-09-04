#include"chess.h"

using namespace std;


int 	Game_End	= 0;

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


// ---------------------------------------------- Start of Functions ---------------------------------------------
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
