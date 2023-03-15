/*John Alex Burke
 * RecursiveMaze.cpp
 * 9/24/19
 * This program stores a 12x12 maze from a file into an array and solves it recursively
 * +KEY+++++++++++++++++++++++++++++++
 * + walls: * start= S end= E        +
 * + path found is marked with o's   +
 * +++++++++++++++++++++++++++++++++++
 */
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>

using namespace std;

void loadMaze(char mazeArray [12][12]);
void printMaze(char mazeArray [12][12]);
bool findPath(char mazeArray[12][12], int r, int c, int er, int ec);
int main()
{
	int 		startR, startC, endR, endC; // index: c= column r=row
	char 		mazeArray[12][12];

	loadMaze(mazeArray);
	printMaze(mazeArray);

	cout<<"Enter start position: "<<endl;
	cin>>startR>>startC;
	cout<<"Enter end position: "<<endl;
	cin>>endR>>endC;

	startR--;
	startC--;
	endR--;
	endC--;

	mazeArray[startR][startC]='S';
	mazeArray[endR][endC]='E';
	printMaze(mazeArray);

	if(findPath(mazeArray, startR,startC,endR,endC)==false)
		cout<<"There is no path!"<<endl;
	mazeArray[startR][startC]='S';
	printMaze(mazeArray);

	return 0;
}

void loadMaze(char mazeArray[12][12])
{
	int count=0;
	ifstream ifs;

	ifs.open("maze.txt");
	if(!ifs)
		cerr<<"file not found"<<endl;

	while(ifs)
	{
		ifs.get(mazeArray[count],13);
		ifs.ignore(99,'\n');
		count++;
	}
	ifs.close();
}

void printMaze(char mazeArray[12][12])
{
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
			cout<<mazeArray[i][j];
		cout<<endl;
	}
}
bool findPath(char mazeArray[12][12], int r, int c, int er, int ec) //index: r= row, c= column, er= end row ec= end column
{
	if(r<0||r>11||c<0||c>11)
		return false;
	else if(r==er&&c==ec)
		return true;
	else if(mazeArray[r][c]=='*'||mazeArray[r][c]=='o')
		return false;
	mazeArray[r][c]='o';
	if(findPath(mazeArray, r+1,c,er,ec)==true)
		return true;
	if(findPath(mazeArray, r-1,c,er,ec)==true)
		return true;
	if(findPath(mazeArray, r,c+1,er,ec)==true)
		return true;
	if(findPath(mazeArray, r,c-1,er,ec)==true)
		return true;
	mazeArray[r][c]=' ';
	return false;

}
