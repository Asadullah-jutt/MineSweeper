#include<iostream>
#include<Windows.h>
#include<fstream>
#include<ctime>    // for eachtime different random values and Timer
#include <string>
using namespace std;
void HighScoreRecord(string lvl[],string scorename[][5],int score[][5]);
void DisplayHighScoreRecord(string lvl[],string scorename[][5],int score[][5]);
void myLine3(int x1, int y1, int x2, int y2,int R ,int G , int B);
void gotoxy(int x, int y);
void myLine(int x1, int y1, int x2, int y2,int color);
bool isCursorKeyPressed(int &whichKey);
void myRect(int x1, int y1, int x2, int y2, int R, int G, int B , int w );
void timer(bool);
void lettersnNumbers(int chr, int x1, int x2, int y1, int y2, int size, int R , int G , int B );
void letters(char chr, int x1, int x2, int y1, int y2, int size, int R , int G , int B );
void Capitalizer(char text[]);
void drawText(int size, int start_x, int start_y, int R, int G, int B, char text[], bool isNum , int num);
void duotriangle(int x1 , int y1 , int x2 , int y2 , int R , int G , int B);
void revtriange(int y2 , int x2 , int y1 , int x1 , int R , int G , int B);
void triange(int y2 , int x2 , int y1 , int x1 , int R , int G , int B);
class xy_cordinates{
	
protected :
	int x1 , x2 ;
	int y1 , y2 ;

public :

	xy_cordinates()
	{
		x1 = 0 ;
		x2 = 0 ;
		y1 = 0 ;
		y2 = 0 ;
	}
	xy_cordinates(int a1 , int a2 , int b1 , int b2 )
	{
		x1 = a1 ;
		x2 = a2 ;
		y1 = b1 ;
		y2 = b2 ;
	}
	void set_x1(int a)
	{
		x1 = a ;
	}
	void set_x2(int a)
	{
		x2 = a ;
	}
	void set_y1(int a)
	{
		y1 = a ;
	}
	void set_y2(int a)
	{
		y2 = a ;
	}
};
class cell : public xy_cordinates{

protected :
	bool check ;
	bool mine ;
	bool flag ;
	int mines_around ;

public :
	cell()
	{
		check = 0 ;
		mine = 0 ;
		flag = 0 ;
		mines_around = 0 ;
	}
	cell(bool a , bool b ,int c, int a1 , int a2 , int b1 , int b2 ):xy_cordinates(a1,a2,b1,b2)
	{
		check = 0 ;
		mine = a ;
		flag = b ;
		mines_around = c ;
	}
	void set_cell_coordinates( int a1 , int b1 , int a2 , int b2)
	{
		flag  = 0 ;
		x1 = a1 ;
		y1 = b1 ;
		x2 = a2 ;
		y2 = b2 ;
	}
	void set_check(bool a)
	{
		//if(mine == 0)
			check = a ;
	}
	bool get_check()
	{
		return check ;
	}
	void set_mine(bool a )
	{
		mine = a ;
	}
	void set_mines_around(int a )
	{
		mines_around = a ;
	}
	int get_mines_around()
	{
		return mines_around ;
	}
	bool get_flag()
	{
		return flag ;
	}
	void set_flag(bool a)
	{
	//	if(check == 0)
			flag = a ;
	}
	void cell_print()
	{
		if(check == 1 )
		{
			if(mine == 0 )
			{
				myRect(x1+5,y1-5,x2-5,y2+5,50,255,50,3);
				myRect(x1+10,y1-10,x2-10,y2+10,0,255,0,3);
				myRect(x1+20,y1-20,x2-20,y2+20,100,255,100,25);
				if(mines_around != 0)
					lettersnNumbers(mines_around, x1+12, x1+38, y1+12- 50,y1+38-50 , 30, 0,0,0);
				if(flag == 1)
				{
					myRect(x1+5,y1-5,x2-5,y2+5,255,255,200,3);
					myRect(x1+10,y1-10,x2-10,y2+10,255,255,100,3);
					myRect(x1+20,y1-20,x2-20,y2+20,255,255,0,25);
					letters('.', x1+10, x1+40, y1+10- 50,y1+40-50 , 30, 0,0,0);
				}
			}

			else if (mine == 1)
			{
				myRect(x1+5,y1-5,x2-5,y2+5,255,50,50,3);
				myRect(x1+10,y1-10,x2-10,y2+10,255,0,0,3);
				myRect(x1+20,y1-20,x2-20,y2+20,255,100,100,25);
				duotriangle(x1+20,y1-20,x2-20,y2+20,0,0,0);
				if(flag == 1)
					lettersnNumbers(0, x1+10, x1+40, y1+10- 50,y1+40-50 , 30, 0,0,0);
			}
			
		}
		if( check == 0 )
		{
			if(flag == 1)
			{
				myRect(x1+5,y1-5,x2-5,y2+5,255,255,200,3);
				myRect(x1+10,y1-10,x2-10,y2+10,255,255,100,3);
				myRect(x1+20,y1-20,x2-20,y2+20,255,255,0,25);
				letters('.', x1+10, x1+40, y1+10- 50,y1+40-50 , 30, 0,0,0);
			}
			else
			{
				myRect(x1+5,y1-5,x2-5,y2+5,50,50,255,3);
				myRect(x1+10,y1-10,x2-10,y2+10,0,0,255,3);
				myRect(x1+20,y1-20,x2-20,y2+20,100,100,255,25);
			}	
		}
		
		///gotoxy((x1+x2)/2,(y1+y2)/2) ;
		//cout<<" ";
	}
	bool getmine()
	{
		return mine;
	}
	void setmine(bool a)
	{
		mine = a ;
	}

};
class board{
protected :
	int level ;
	int mines_total ;
	int mines_found ;
	int rows ;
	int cols ;
public :
	board()
	{
		level = 0;
		mines_total = 0 ;
		mines_found = 0 ;
		rows = 0 ;
		cols = 0 ;
	}
	board(int a )
	{
		level = a ;
		if(level == 1)
		{
			rows = 9 ;
			cols = 9 ;
			mines_total = 3 ;
			mines_found = 0 ;
		}
		else if(level == 2)
		{
			rows = 16 ;
			cols = 16 ;
			mines_total = 40 ;
			mines_found = 0 ;
		}
		else if(level == 3)
		{
			rows = 16 ;
			cols = 30 ;
			mines_total = 99 ;
			mines_found = 0 ;
		}
	}
	int get_level()
	{
		return level ;
	}
	void grid_print()
	{
		int xx = 0 , yy = 0 ;
		if(level == 3)
		{
			xx = 1000 ;
			yy = 1700 ;
		}
		else if(level == 2)
		{
			xx = 1000 ;
			yy = 1000 ;
		}
		else if(level = 1)
		{
			xx = 650 ;
			yy = 650 ;
		}
		//else 
		for (int i = 0 ; i <= rows ; i++)
		{
			myLine(200,200 + i*50,yy,200 + i*50,255);
		}
		for (int j = 0 ; j <= cols ; j++)
		{
			myLine(200 + j*50,200 ,200 + j*50,xx,255);
		}

	}

};
class MineSweeper : public board 
{
	cell** cel ;
	friend void screen_idx(int x , int y);
public :
	MineSweeper(int lvl ):board(lvl)
	{
		cel = new cell*[rows] ;
		for(int i = 0 ; i < rows ; i++)
			cel[i] = new cell[cols] ;

		srand(time(0));
		int mine_distributer_rows ;
		int mine_distributer_cols ;
		int dised_mine = mines_total ;

		for (int i = 0 ; i < dised_mine ; i++)
		{
			mine_distributer_rows = rand()% rows ;
			mine_distributer_cols = rand()% cols ;
			if(cel[mine_distributer_rows][mine_distributer_cols].getmine()==0)
				cel[mine_distributer_rows][mine_distributer_cols].setmine(1);
			else
				i-- ;
		}
		int x1 , y1 , x2 , y2;
		//cout<<cols ;
		for(int i = 0 ; i < rows ; i++)  // shapes printing on the grid
		{
			for(int j = 0 ; j < cols ; j++)
			{
				x1 = 200 + j*50 ;
				y1 = 200 + (i+1)*50 ;
				x2 = 200 + (j+1)*50 ; 
				y2 = 200 + i*50;
				cel[i][j].set_cell_coordinates(x1,y1 ,x2 ,y2);
				//cout<<x1<<" , "<<y1<<"_"<<x2<<" , "<<y2<<" \n ";
			//	cel[i][j].cell_print();
				//Sleep(200);
			}
			//cout<<endl;
		}
		//cout<<x1<<":"<<y1<<x2<<" : "<<y2<<endl;
		// mines_around_count
		int count ;
		for(int i = 0 ; i < rows ; i++)  // shapes printing on the grid
		{
			for(int j = 0 ; j < cols ; j++)
			{
				count = 0 ;
				if(i > 0)
				{
					if(cel[i - 1][j].getmine() == 1)
						count++;
					if(j > 0)
						if(cel[i - 1][j - 1].getmine() == 1)
							count++;
					if(j < cols - 1)
						if(cel[i - 1][j + 1].getmine() == 1)
							count++;
				}
				if(j > 0)
				{
					if(cel[i][j - 1].getmine() == 1)
						count++;
				}
				
				if(i < rows - 1)
				{
					if(cel[i + 1][j].getmine() == 1)
						count++;
					
					if(j > 0)
						if(cel[i + 1][j - 1].getmine() == 1)
							count++;
				
				}
				if(j < cols - 1)
				{
					if(cel[i][j + 1].getmine() == 1)
						count++;
					if(i < rows - 1)
						if(cel[i + 1][j + 1].getmine() == 1)
							count++;

					/*if(i < rows - 1)
						if(cel[i + 1][j - 1].getmine() == 1)
							count++;*/
				}
				if(cel[i][j].getmine() == 1)
					count = 0 ;
				cel[i][j].set_mines_around(count);
				//cout<<cel[i][j].get_mines_around();
			//	cout<<"  ";
			}
			//cout<<endl;
		}
			
	}
	~MineSweeper()
	{
		for(int i = 0 ; i < rows ; i++)
			delete []cel[i] ;

		delete[]cel ;
	}
void screen_idx(int y , int x , bool mouse ,bool & gameover  )
{
	int xx = x  ;
	if(x > rows )
		xx = ( x - 135 ) / 33.2 ;
	int yy = y  ;
	if(y > cols)
		yy = ( y - 135 ) / 33.2 ;
	int xarr[8] ;
	int yarr[8] ;
	int count = 0 ;
	if(mouse == 1 && ( xx >= 0 && xx < rows ) && ( yy >= 0 && yy < cols ))
	{
		if(cel[xx][yy].get_flag() == 0 && cel[xx][yy].get_check()==0 )
		{
			cel[xx][yy].set_flag(1);
			mines_total--;
			myRect(250,50,350,100,10,10,10,30);
		}
		else if(cel[xx][yy].get_flag() == 1 && cel[xx][yy].get_check()==0)
		{
			cel[xx][yy].set_flag(0);
			mines_total++;
			myRect(250,50,350,100,10,10,10,30);
		}
	}
	else
	{
		if(( xx >= 0 && xx < rows ) && ( yy >= 0 && yy < cols ))
		{
			if(cel[xx][yy].getmine()==1 && cel[xx][yy].get_flag() == 0 )
			{
				cel[xx][yy].set_check(1);
				for(int i = 0 ; i < rows ; i++)  
					for(int j = 0 ; j < cols ; j++)
						if(cel[i][j].getmine()==1)
							cel[i][j].set_check(1);
				//cout<<"Game Over";
				gameover = 1 ;
			}
		//	cout<<"["<<xx<<"]"<<"["<<yy<<"]";
			if(cel[xx][yy].get_check() == 0 && cel[xx][yy].get_flag() == 0 )
			{
				cel[xx][yy].set_check(1);
				if(cel[xx][yy].get_mines_around() == 0)
				{
					if(xx > 0)
					{
						cel[xx - 1][yy].set_check(1);
						if(cel[xx - 1][yy].get_mines_around()== 0)
						{
							xarr[count] = xx - 1 - 1 ;
							yarr[count] = yy ;
							count++;
						}
						if(yy > 0)
						{
							cel[xx - 1][yy - 1].set_check(1);
							if(cel[xx - 1][yy - 1].get_mines_around()== 0)
							{
								xarr[count] = xx - 1 - 1;
								yarr[count] = yy - 1 - 1;
								count++;
							}
						}
						if(yy < cols - 1)
						{
							cel[xx - 1][yy + 1].set_check(1);
							if(cel[xx - 1][yy + 1].get_mines_around()== 0)
							{
								xarr[count] = xx - 1 - 1 ;
								yarr[count] = yy + 1 + 1;
								count++;
							}
						}
					}
					if(yy > 0)
					{
						cel[xx][yy - 1].set_check(1);
						if(cel[xx][yy - 1].get_mines_around()== 0)
						{
							xarr[count] = xx ;
							yarr[count] = yy - 1 -1;
							count++;
						}
					}
				
					if(xx < rows - 1)
					{
						cel[xx + 1][yy].set_check(1);
						if(cel[xx + 1][yy].get_mines_around()== 0)
						{
							xarr[count] = xx + 1 + 1;
							yarr[count] = yy ;
							count++;
						}
					
						if(yy > 0)
						{
							cel[xx + 1][yy - 1].set_check(1);
							if(cel[xx + 1][yy - 1].get_mines_around()== 0)
							{
								xarr[count] = xx + 1 + 1;
								yarr[count] = yy - 1 - 1;
								count++;
							}
						}
					}
					if(yy < cols - 1)
					{
						cel[xx][yy + 1].set_check(1);
						if(cel[xx][yy + 1].get_mines_around()== 0)
						{
							xarr[count] = xx ;
							yarr[count] = yy + 1 + 1;
							count++;
						}
						if(xx < rows - 1)
						{
							cel[xx + 1][yy + 1].set_check(1);
							if(cel[xx + 1][yy + 1].get_mines_around()== 0)
							{
								xarr[count] = xx + 1 + 1;
								yarr[count] = yy + 1 + 1;
								count++;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0 ; i < count ; i++)
	{
		screen_idx(yarr[i],xarr[i],0 ,gameover);
		//cout<<"---"<<i;
	}
}


void all_cell_print(bool &gamewon)
{
	int flagminecount = 0 ;
	for(int i = 0 ; i < rows ; i++)  // shapes printing on the grid
		for(int j = 0 ; j < cols ; j++)
		{
			if(cel[i][j].get_flag() == 1 && cel[i][j].getmine() == 1 && cel[i][j].get_check()==0)
				flagminecount++;
			if(cel[i][j].get_flag() == 0 && cel[i][j].getmine() == 0 && cel[i][j].get_check()==1)
				flagminecount++;
		}
		if(flagminecount == rows*cols)
		{
			gamewon = 1 ;
		}
		//cout<<flagminecount<<" ";
		//Sleep(100);
	grid_print();
	if(mines_total < 0)
		myLine3(270,80,290,80,255,100,100);
	else if(mines_total == 0)
		drawText(30,290,55,255,100,100 ,"0",0,0);
	drawText(30,80,50,255,100,100 ,"Mines: ",1,mines_total);
	//drawText(30,200,50,255,100,100,"",1,mines_total);
	for(int i = 0 ; i < rows ; i++)  // shapes printing on the grid
		for(int j = 0 ; j < cols ; j++)
		{
			cel[i][j].cell_print();
			//Sleep(50);
		}

}

};
int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE),CONSOLE_FULLSCREEN_MODE,0);
	HANDLE	color=GetStdHandle(STD_OUTPUT_HANDLE); // to color the text
	//SetConsoleTextAttribute(color,6);


	POINT pos;
	GetCursorPos(&pos);
	int x = pos.x; 
	int y = pos.y; 
	back:
	MineSweeper obj(1);
	int a ;

	// current date/time based on current system
	 time_t now ;
	 tm *ltm ;
	 int b = 0 ;
	 int hourb = 0 ;
	 int timerecord = 0;
	 int last_value ;
	 int timetemph, timetempmin , ttt = 0 ;
	bool mouseflag = 0 , gameover = 0 , gamewon = 0  ;
	int first_click = 0 ;
	int last_val = 0 ;
	int score[3][5] ;
	string level[3] , scorename[3][5] ;
	while(1)
	{
		
		x = pos.x;
		y = pos.y;
		GetCursorPos(&pos);
		isCursorKeyPressed(a);
		if(a == 11)
		{
			//cout<<"Left Clck";
			//cout << "Mouse Coordinates: " << x << ", " << y << endl;
		}
		if(a == 12)
		{
			first_click++;
		//	cout << "Mouse Coordinates: " << x << ", " << y ;
			if((x >= 1151 && x <=1219) && y >= 265 && y <= 355)
			{
				mouseflag = 1 ;
				//cout<<"Flag ";
				if(mouseflag == 1)
				{
					myRect(1730+30,400+30,1830-30,550-30,0,255,255,55);
					myRect(1730+30,550+30,1830-30,700-30,10,10,10,55);
				}

			}
			else if((x >= 1151 && x <=1219) && y > 365 && y <= 465)
			{
				mouseflag = 0 ;
				//cout<<"Norm";
				if(mouseflag == 0)
				{
					myRect(1730+30,550+30,1830-30,700-30,0,0,255,55);
					myRect(1730+30,400+30,1830-30,550-30,10,10,10,55);
				}
			}
			if(gameover == 0 )
				obj.screen_idx(x,y,mouseflag,gameover);
			if(gameover == 1)
			{

				cout<<"GameOver";
				//Sleep(2000);
			}
		}
		if(first_click == 1) //
		{
			//b = 0 ;
			now = time(0);
			ltm = localtime(&now);
			b = ltm->tm_sec ;
			hourb = ltm->tm_min ;
			
			first_click++;
		}
		if(first_click == 0)
		{
			drawText(30,400,50,255,100,100 ,"Time: ",1, 0);
			drawText(30,580,50,255,100,100 ,"0",0,0);
			myRect(1730,400,1830,550,255,255,255,5);
			myRect(1730,550,1830,700,255,255,255,5);
		}
		if(first_click > 1)
		{
			 now = time(0);
			 ltm = localtime(&now);
			 timetemph = ltm->tm_min - hourb ;
			 if(gameover == 0 && gamewon == 0)
				 timetempmin = ltm->tm_sec - b ;
			 if(gamewon == 1)
				 timerecord = timetempmin+timetemph*59 ;
			 drawText(30,400,50,255,100,100 ,"Time: ",1, timetempmin+timetemph*59);
			 if(last_val != ltm->tm_sec - b)
			 	myRect(600,50,700,100,10,10,10,60);
			 last_val = ltm->tm_sec - b ;
		}
		a = 0 ;
		if(gamewon == 1)
		{
			int aa ;
			cout<<"YOU woN"<<endl;
			cout<<"Press Any Key to Preceed";
			cin >>a;
			system("cls") ;
			int idx = 0 ;
			bool highscorefound = 0 ;
			HighScoreRecord(level,scorename,score);
			
			//DisplayHighScoreRecord(level,scorename,score) ;
			for(int i = 4 ; i>=0 ; i--)
			{
				if(timerecord < score[obj.get_level() - 1][i])
				{
					idx = i ;
					highscorefound = 1 ;
				}
			}
			if(highscorefound == 1)
			{
				cout<<"its an highScore "<<endl;
				cout<<"You are Ranked at "<<idx+1<<" in "<<level[obj.get_level() - 1]<<"Mode"<<endl;
				cout<<"You have Braged : ";
				for(int i = idx ; i < 5 ; i++)
					cout<<scorename[obj.get_level() -1][i]<<" , ";
				cout<<endl;
				cout<<"Enter Your Name : ";
				string newname ;
				cin >> newname ;
				for(int i = 4 ; i > idx ; i--)
				{
					swap(score[obj.get_level() - 1][i],score[obj.get_level() - 1][i - 1]);
					swap(scorename[obj.get_level() - 1][i],scorename[obj.get_level() - 1][i - 1]) ;
				}
				score[obj.get_level() - 1][idx] = timerecord ;
				scorename[obj.get_level() - 1][idx] = newname ;
				DisplayHighScoreRecord(level,scorename,score); 
				ofstream fout("highScore.txt") ;
				for(int i = 0 ; i < 3 ; i++)
				{
					fout << level[i] <<endl;
					for(int j = 0 ; j < 5 ; j++)
					{
						fout<<scorename[i][j]<<" "<<score[i][j]<<endl;
					}
				}
				cout<<"Press Any Key to Continue";
				cin>>aa ;
		
				break;
			}
		}
		obj.all_cell_print(gamewon);
		if(gameover == 1)
		{
			drawText(50,300,300,32,210,244,"GAME OVER!!!",0,0);
			cout<<"Press any key to Proceed";
			cin>>a;
			break;
		}
			//	Sleep(1);
	}
	char opt ;
	while(1)
	{
		drawText(50,300,300,32,210,244,"WOONA PLAY AGAIN!!!",0,0);
		drawText(50,300,460,32,210,244,"Press Y for yes",0,0);
		drawText(50,300,620,32,210,244,"Press any key to end",0,0);
		cin>>opt ;
		if(opt == 'y' && opt == 'Y')
			goto back;
		else
		{
			break;
		}
	}
	drawText(50,300,300,32,210,244,"Signing off!!!",0,0);
	Sleep(1000);
	system("pause");
	return 0 ;
}
void lettersnNumbers(int chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
    x1 += 5;
    x2 -= 5;
    y1 += 5;
    y2 -= 5;
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;


    if (chr == 0) {
        myLine3(x1, y1, x2, y2, R, G, B);
        myLine3(x2, y1, x1, y2, R, G, B);

    }
    else if (chr == 1) {
      //  myLine3(x1, mid_y - size / 2, mid_x, y1, R, G, B);
        myLine3(mid_x, y1, mid_x, y2, R, G, B);
       // myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 2) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x1, y2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 3) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x1, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == 4) {
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
    }
    else if (chr == 5) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == 6) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == 7) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 8) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == 9) {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '-')
        myRect(x1-5, y1-5, x2+5, y2+5, 0, 0, 0,2);
}
void letters(char chr, int x1, int x2, int y1, int y2, int size, int R = 0, int G = 0, int B = 0) {
    x1 += 5;
    x2 -= 5;
    y1 += 5;
    y2 -= 5;
    int mid_x = (x1 + x2) / 2;
    int mid_y = (y1 + y2) / 2;
	
    if (chr == '0') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == '1') {
      //  myLine3(x1, mid_y - size / 2, mid_x, y1, R, G, B);
        myLine3(mid_x, y1, mid_x, y2, R, G, B);
       // myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '2') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x1, y2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '3') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x1, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '4') {
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(mid_x + size / 6, y1, mid_x + size / 6, y2, R, G, B);
    }
    else if (chr == '5') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '6') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, mid_y, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '7') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == '8') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '9') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y1, x1, mid_y, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
    }
    else if (chr == '-')
        myRect(x1-5, y1-5, x2+5, y2+5, 0, 0, 0,2);
    if (chr == 'A') {
        myLine3(mid_x, y1, x1, y2, R, G, B);
        myLine3(mid_x, y1, x2, y2, R, G, B);
        myLine3(x1 + 2, mid_y + size / 2, x2 - 3, mid_y + size / 2, R, G, B);
    }
    else if (chr == 'B') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine3(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine3(x1, mid_y, mid_x, mid_y, R, G, B);
        myLine3(mid_x, mid_y, x2, mid_y + size / 4, R, G, B);
        myLine3(x2, mid_y + size / 4, mid_x + size / 8, y2, R, G, B);
        myLine3(mid_x + size / 8, y2, x1, y2, R, G, B);
    }
    else if (chr == 'C') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, y1 + size / 4, R, G, B);
        myLine3(x2, y2, x2, y2 - size / 4, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'D') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, mid_x + size / 4, y1 + size / 4, R, G, B);
        myLine3(mid_x + size / 4, y1 + size / 4, mid_x + size / 4, y2 - size / 4, R, G, B);
        myLine3(mid_x + size / 4, y2 - size / 4, x1, y2, R, G, B);
    }
    else if (chr == 'E') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'F') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
    }
    else if (chr == 'G') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x2, y1 + size / 4, R, G, B);
        myLine3(x2, y2, x2, y2 - size / 2, R, G, B);
        myLine3(x2, y2 - size / 2, mid_x, y2 - size / 2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'H') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x1, mid_y, x2, mid_y, R, G, B);
    }
    else if (chr == 'I') {
        myLine3(mid_x, y1, mid_x, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'J') {
        myLine3(x2, y1, x2, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y2, x1, y2, R, G, B);
        myLine3(x1, y2, x1, y2 - size / 2, R, G, B);
    }
    else if (chr == 'K') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, mid_y, x2, y1, R, G, B);
        myLine3(x1, mid_y, x2, y2, R, G, B);
    }
    else if (chr == 'L') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == 'M') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, mid_x, mid_y, R, G, B);
        myLine3(mid_x, mid_y, x2, y1, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'N') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y2, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'O') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);
    }
    else if (chr == 'P') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine3(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine3(x1, mid_y, mid_x, mid_y, R, G, B);

    }
    else if (chr == 'Q') {
        myLine3(x1, y1, x1, y2 - 5, R, G, B);
        myLine3(x1, y1, mid_x + 3, y1, R, G, B);
        myLine3(mid_x + 3, y1, mid_x + 3, y2 - 5, R, G, B);
        myLine3(x1, y2 - 5, mid_x + 3, y2 - 5, R, G, B);
        myLine3(mid_x - 2, mid_y, mid_x + 3, y2 - 5, R, G, B);
        myLine3(mid_x + 3, y2 - 5, x2, y2, R, G, B);
    }
    else if (chr == 'R') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y1, mid_x + size / 4, y1 + size / 8, R, G, B);
        myLine3(mid_x + size / 4, y1 + size / 8, mid_x, mid_y, R, G, B);
        myLine3(x1, mid_y, mid_x, mid_y, R, G, B);
        myLine3(mid_x, mid_y, x2, y2, R, G, B);
    }
    else if (chr == 'S') {
        myLine3(mid_x, y1, x2, y1 + size / 2, R, G, B);
        myLine3(mid_x, y1, x1, y1 + size / 2, R, G, B);
        myLine3(x1, y1 + size / 2, x2, y2 - size / 2, R, G, B);
        myLine3(x2, y2 - size / 2, mid_x, y2, R, G, B);
        myLine3(mid_x, y2, x1, y2 - size / 2, R, G, B);
    }
    else if (chr == 'T') {
        myLine3(mid_x, y1, mid_x, y2, R, G, B);
        myLine3(x1, y1, x2, y1, R, G, B);
    }
    else if (chr == 'U') {
        myLine3(x1, y1, x1, y2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
        myLine3(x2, y1, x2, y2, R, G, B);

    }
    else if (chr == 'V') {
        myLine3(x1, y1, mid_x, y2, R, G, B);
        myLine3(mid_x, y2, x2, y1, R, G, B);
    }
    else if (chr == 'W') {
        myLine3(x1, y1, mid_x - size / 8, y2, R, G, B);
        myLine3(mid_x - size / 8, y2, mid_x, mid_y, R, G, B);
        myLine3(mid_x, mid_y, mid_x + size / 8, y2, R, G, B);
        myLine3(mid_x + size / 8, y2, x2, y1, R, G, B);
    }
    else if (chr == 'X') {
        myLine3(x1, y1, x2, y2, R, G, B);
        myLine3(x2, y1, x1, y2, R, G, B);

    }
    else if (chr == 'Y') {
        myLine3(x1, y1, mid_x, mid_y, R, G, B);
        myLine3(x2, y1, x1, y2, R, G, B);
    }
    else if (chr == 'Z') {
        myLine3(x1, y1, x2, y1, R, G, B);
        myLine3(x2, y1, x1, y2, R, G, B);
        myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == '.') {
        myLine3(x1, mid_y - size/5, mid_x, y1, R, G, B);
		//myLine3(x1+7,3+ mid_y - size/5, mid_x , y1 +2, R, G, B);
		myLine3(x1, mid_y - size/5, mid_x, y1 + 8, R, G, B);
        myLine3(mid_x, y1, mid_x, y2, R, G, B);
		//myLine3(x1, y2, x2, y2, R, G, B);
    }
    else if (chr == ',') {
        myRect(x2, y2 - size / 3, mid_x + size / 4, y2 - size / 6, R, G, B,4);
        myLine(x2, y2 - size / 3, x2, y2, R);
        myLine(x2, y2, mid_x + size / 4, y2, R);
    }
    else if (chr == '!') {
        myRect(mid_x - size / 8, y1, mid_x - 1, y2 - size / 3, R, G, B,4);
        myRect(mid_x - size / 8, y2 - size / 8, mid_x, y2, R, G, B,4);
    }
    else if (chr == ':') {
        myRect(x2, y2 - 20, mid_x + size / 4, y2 - 16, R, G, B,4);
        myRect(x2, y2 - 4, mid_x + size / 4, y2, R, G, B,4);
    }
}
//This Function Converts a Cstring to uppercase
void Capitalizer(char text[]) {
    for (int i = 0; i < strlen(text); i++)
        if (text[i] >= 'a' && text[i] <= 'z')
            text[i] -= 32;
}
//This Function to print Text on Screen
void drawText(int size, int start_x, int start_y, int R, int G, int B, char text[], bool isNum = false, int num = 0) {
    int idx = 0;
    int idx_x = 0;
    int idx_y = 0;
    int x1, x2, y1, y2;
    int digit_count = 0;
    int len = strlen(text);
    char temp[100];

    strcpy_s(temp, text);
    //If this function takes a number to print then he converts the number into atring using following loop
    if (isNum == true) {
        int reverse_num = 0;
        int i;
		if(num < 0)
			num = -(num);
        for (; num > 0; num /= 10, digit_count++)
            reverse_num = (reverse_num * 10) + num % 10;

        for (i = len; i - len < digit_count; i++, reverse_num /= 10)
            temp[i] = (reverse_num % 10) + 48;

        temp[i] = '\0';
    }
    //Now the cstring is converted into upper case letters
    Capitalizer(temp);
    //This loop prints each individual letter on the screen
    for (idx = 0; idx < strlen(temp); idx++)
    {
        x1 = start_x + size * idx_x;
        x2 = start_x + size * (idx_x + 1);

        if (x2 > 1585 - size) {
            idx_y++;
            idx_x = 0;
            x1 = start_x + size * idx_x;
            x2 = start_x + size * (idx_x + 1);

        }

        y1 = start_y + 2 * size * idx_y;
        y2 = start_y + 2 * size * (idx_y + 1);
        letters(temp[idx], x1, x2, y1, y2, size, R, G, B);
        idx_x++;
    }

}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void myLine(int x1, int y1, int x2, int y2,int color) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,2,RGB(color,color,color)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
	
}
void myLine3(int x1, int y1, int x2, int y2,int R ,int G , int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen =CreatePen(PS_SOLID,3,RGB(R,G,B)); //2 is the width of the pen
    SelectObject(device_context,pen);
	MoveToEx(device_context,x1,y1,NULL);
    LineTo(device_context,x2, y2);
	ReleaseDC(console_handle, device_context);  
	DeleteObject(pen);
}

// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(VK_LBUTTON);
	if (key == 1)
	{
		whichKey = 11;		// 11 if left mouse button is pressed 
		return true;
	}

	key = GetAsyncKeyState(VK_RBUTTON);
	if (key == 1)
	{
		whichKey = 12;		// 12 if Right mouse button is pressed 
		return true;
	}
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{
		whichKey = 2;		// 2 if up key is pressed
		return true;
	}
	
	key = GetAsyncKeyState(39);
	if (key == 1)
	{
		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{
		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{
		whichKey = 5;   // 5 if Enter key is pressed
		return true;
	}
	key = GetAsyncKeyState('A');
	if (key == 1)
	{
		whichKey = 6;   // 6 to Swap the the candies left A key is pressed
		return true;
	}
	key = GetAsyncKeyState('W');
	if (key == 1)
	{
		whichKey = 7;   // 7 to Swap the the candies up W key is pressed
		return true;
	}
	key = GetAsyncKeyState('D');
	if (key == 1)
	{
		whichKey = 8;   // 8 to Swap the the candies right D key is pressed
		return true;
	}
	key = GetAsyncKeyState('S');
	if (key == 1)
	{
		whichKey = 9;   // 9 to Swap the the candies Down s key is pressed
		return true;
	}
	return false;
}

void myRect(int x1, int y1, int x2, int y2, int R, int G, int B , int w )
{
	HWND console_handle = GetConsoleWindow();
    HDC device_context = GetDC(console_handle);

    //change the color by changing the values in RGB (from 0-255)
	HPEN pen =CreatePen(PS_SOLID,w,RGB(R,G,B)); 
    SelectObject(device_context,pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(0,0,0)); //Fill color can also be passed as parameter to the function!!!
	SelectObject(device_context,brush);
	Rectangle(device_context,x1,y1,x2,y2);
	ReleaseDC(console_handle, device_context); 
	DeleteObject(pen);
	DeleteObject(brush);
}
 void triange(int x1 , int y1 , int x2 , int y2 , int R , int G , int B)
{
	int	x3 = (x1 + x2)/2 , y3 = y1 ;
	myLine3(x1, y1, x2, y3 ,R ,G ,B );
    myLine3(x1, y1, x3, y2 ,R ,G ,B );
    myLine3(x2, y3, x3, y2 , R ,G ,B );
}
void duotriangle(int x1 , int y1 , int x2 , int y2 , int R , int G , int B)
{
	triange(x1 , y1-3 , x2 , y2- 3, R , G , B);
	revtriange(x1 , y1+3 , x2 , y2+3 , R , G , B);
}
void revtriange(int y2 , int x2 , int y1 , int x1 , int R , int G , int B)
{
	int	x3 , y3;
	swap(x1,y1);     
	swap(x2,y2);
	swap(x3,y3);
	x3 = (x1 + x2)/2; 
	y3 = y1 ;
	myLine3( x1 , y1 , x2 , y3 , R , G , B ); 
    myLine3( x1 , y1 , x3 , y2 , R , G , B );
    myLine3( x2 , y3 , x3 , y2 , R , G , B );

}
void HighScoreRecord(string lvl[],string scorename[][5],int score[][5])
{
	ifstream fin ("highScore.txt");
	int i = 0 ;
	while(fin.eof()==0)
	{
		fin >> lvl[i] ;
		for(int j = 0 ; j < 5 ;j++)
		{
			fin >> scorename[i][j] ;
			fin >> score[i][j] ;
		}
		i++ ;
	}
}
void DisplayHighScoreRecord(string lvl[],string scorename[][5],int score[][5])
{
	cout<<"-----------------------------| High Score |-----------------------------------------"<<endl;
	for(int i = 0 ; i < 3 ; i++)
	{
		cout<<" - "<<lvl[i]<<" Mode - "<<endl ;
		for(int j = 0 ; j < 5 ;j++)
		{
			cout << "        --->   "<<scorename[i][j] <<"   "<< score[i][j] <<endl;
		}
		cout<<"-------------------------------------------------------------------------------"<<endl;
	}
}