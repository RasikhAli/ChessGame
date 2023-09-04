//#include"Chess_V1.cpp"
#include<iostream>
using namespace std;

// ------------------------------------------------ Black Pieces -------------------------------------------------
char 	*Rook 		= "B_Rk";		// Black Rook
char 	*Knight 	= "B_Kn";		// Black Knight
char 	*Bishop 	= "B_Bi";		// Black Bishop
char 	*King 		= "B_Kg";		// Black King
char 	*Queen 		= "B_Qn";		// Black Queen
char 	*Pawn 		= "B_Pn";		// Black Pawn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// ------------------------------------------------ White Pieces -------------------------------------------------
char 	*rook 		= "W_Rk";		// White Rook
char 	*knight 	= "W_Kn";		// White Knight
char 	*bishop 	= "W_Bi";		// White Bishop
char	*king 		= "W_Kg";		// White king
char	*queen 		= "W_Qn";		// White queen
char	*pawn 		= "W_Pn";		// White pawn
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


char 	*EMPTY		= "    ";		// Empty Space


string arr[8][8] = {	Rook, 		Knight, 	Bishop, 	King,  		Queen, 		Bishop, 	Knight, 	Rook,
						Pawn,		  Pawn,		  Pawn,		Pawn,		 Pawn,		  Pawn,		  Pawn,		Pawn,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY, 		EMPTY, 		 EMPTY, 	 EMPTY,    EMPTY,
						pawn,		  pawn,		  pawn,		pawn,		 pawn,		  pawn,		  pawn,		pawn,
						rook, 		knight, 	bishop,    queen,  		 king, 		bishop, 	knight, 	rook 	};


class chess
{	
	public:
		int KnX[4] = {1, 6, 1, 6};
		int KnY[4] = {0, 0, 7, 7};
		
		void displayboard();
};


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

