#include<iostream>
#include<string>
#include<vector>
#define INFINITY 1000000
using namespace std;

struct sparseMarbles
{
	vector<string> sparse;
};

class AbaloneAI
{
	sparseMarbles whiteBlack[2];

	public:
		AbaloneAI()
		{
			string strW = "A7";
			string strB = "G1";
			for (int i = 0; i < 4; i++)
			{
				strW[1] += i;
				strB[1] += i;
				whiteBlack[0].sparse.push_back(strW);
				whiteBlack[1].sparse.push_back(strB);
			}
			strW = "B3";
			strB = "F1";
			for (int i = 0; i < 5; i++)
			{
				strW[1] += i;
				strB[1] += i;
				whiteBlack[0].sparse.push_back(strW);
				whiteBlack[1].sparse.push_back(strB);
			}
			strW = "C4";
			whiteBlack[0].sparse.push_back(strW); 
			strW[1]++;
			whiteBlack[0].sparse.push_back(strW);
			strB = "E3";
			whiteBlack[1].sparse.push_back(strB);
			strB[1]++;
			whiteBlack[1].sparse.push_back(strB);
		}
		void move(string, string);
		vector<string> findNeigh(string);
		bool isValid(string,string);
		string getDirection(string, string);
		string getFinals(string, string);
		vector<int> convertCoordinates(string);
		int eval();
        string findBestMove(int);
		bool ifpush(string,string);
		bool ifpushout(string,string);

};

string AbaloneAI::findBestMove(int player)
{
	int bestval= -1* INFINITY;
	string bestmove;


	//TRAVERSE ALL THE MARBLES
	for(auto i=whiteBlack[player].sparse.begin(); i!=whiteBlack[player].sparse.end;i++)
	{	//PROBABLY USE FINDNEIGH OVER HERE ...!!
		for(auto j=whiteBlack[player].sparse.begin(); j!=whiteBlack[player].sparse.end;j++)
		{
			if(isValid(*i,*j))	//IF THE MOVE IS VALID THEN ONLY IMPLEMENT MINIMAX
			{
				string initial,final,to_final,oppo_final;
				int pushed=0, pushout=0;
				initial=*i;
				final=*j;
				to_final=getFinals(initial,final);

				if(ifpush(initial,final))
				{
					pushed=1;
					oppo_final=getFinals(final,to_final);

					if(ifpushout(initial,final))
					{
						pushout=1;
					}
				}

				

				//MINMAX

				//REVERTING STAGE

				//IF MOVEVAL >BESTVAL.....CHANGE BESTVAL


			}
		}
	}
}

int main()
{
	cout<<"DONE!!!";
}