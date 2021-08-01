#include<iostream>
#include<conio.h>
#include<windows.h>
#include "SquareBlock.h"
#include "Board.h"
using namespace std;

Board::Board(){
	height = 0;
	score = 0;
	ptr = NULL;
	x=0;
	y=0;
	rowFt=99;
	rowLt=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(i==0){				
				matrix[i][j]=95;
			}
			else if(j == C-1 || j == 0){
				matrix[i][j]='|';
			}
			else{
				matrix[i][j]=95;
			}
		}
	}
	switchBlock();
}
void Board::menu(){
	
	system("cls");
	cout << endl << endl;
	   cout<<"\t%%      %%      ";
       cout<<"\n\t%%      %% %%%%%%% %%      %%%%%%  %%%%%% %%%%  %%%% %%%%%%%";
       cout<<"\n\t%%      %% %%      %%      %%      %%  %% %%  %%% %% %%       ";
       cout<<"\n\t%%  %%  %% %%%%%   %%      %%      %%  %% %%  %%% %% %%%%%      ";
       cout<<"\n\t%%  %%  %% %%      %%      %%      %%  %% %%      %% %%           ";
       cout<<"\n\t%%%%%%%%%% %%%%%%% %%%%%%% %%%%%%% %%%%%% %%      %% %%%%%%%     ";
       cout<<"\n\n\t\t\t        $$$$$$$$  $$$$$        ";
       cout<<"\n\t\t\t           $$     $   $      ";
       cout<<"\n\t\t\t           $$     $$$$$    ";

       cout<<"\n\n\n\t\tTETRIS GAME (******** Tetris(beta) v1.0 *******)" << endl<< endl<< endl;
	   cout << "Tip :  Control Keys are WASD " << endl<< endl<< endl;
	   cout << "Warning !! This is a beta version might contains bugs operate normally.. " << endl;
	system("pause");
	gameLoop();
	
}
void Board::switchBlock(){
	
	int number;
	number = rand() % 10;
	if(number == 1){
		ptr = new Square;
	}
	else if(number == 2){
		ptr = new Stick;
	}
	else if(number == 3){
		ptr = new T;
	}
	else if(number == 4){
		ptr = new S;
	}
	else if(number == 5){
		ptr = new Z;
	}
	else if(number == 6){
		ptr = new J;
	}
	else{
		ptr = new L;
	}
	rowFt=99;
	rowLt=0;
	copyCurrentShape();
}
bool Board::isExist(){
	bool check = false;
	for(int j=rowFt;j<=rowLt;j++){
		if(matrix[y+1][j] == 48 && matrix[y][j] == 48){
			check = true;
		}
	}
	return check;
}	
bool Board::animate(){
	
	int check = 0;
	if(y!=R-1){
		for(int i=y;i>=x;i--){
			for(int j=rowFt;j<=rowLt;j++){
				if(j==rowFt && i==y){
					if(isExist()){
						check = 1;
					}
				}
				if(matrix[i][j]==48 && check == 0){
					matrix[i+1][j]=matrix[i][j];
					matrix[i][j]=95;
				}
				if(i==R-1){
					check = 1;
				}
			}
		}
		if(check != 1){
			x++;
			y++;
		}
	}
	else{
		return true;
	}
	if(check == 1){
		return true;
	}
	else{
		return false;
	}
	
}
void Board::copyCurrentShape(){
	int check = 0,loop =1;
	int** shapeArr;
	shapeArr=ptr->getShape();
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(check == 0 && shapeArr[i][j] == 1){
				check = 1;
			}
			if(check == 1){
				if(shapeArr[i][j]==1 && loop == 1){
					x = loop;
					matrix[loop][j+(R/2)-2] = '0';
				}
				else if(shapeArr[i][j]==1){
					matrix[loop][j+(R/2)-2] = '0';
				}
			}
		}
		if(check == 1){
			loop++;
			y = loop;
		}		
	}
	y--;
	for(int i=0;i<4;i++){
		delete[] shapeArr[i];
	}
	delete[] shapeArr;
	
	for(int i=0;i<4;i++){
		for(int j=0;j<C;j++){
			if(matrix[i][j] == '0'){
				if(rowFt > j){
					rowFt = j;
				}
				if(rowLt < j){
					rowLt = j;
				}
			}
		}
	}
}
void Board::moveLeft(){
	int check = 0;
	if(y != R-1 && isColliding('l')){
		for(int i=x;i<=y;i++){
			for(int j=rowFt;j<=rowLt;j++){
				if(j-1<1){
					break;
				}				
				if(matrix[i][j] == '0' && matrix[i][j-1] != '0'){
					matrix[i][j-1]=matrix[i][j];
					matrix[i][j] = 95;
					check = 1;
				}
				
			}
		}
		if(check){
			rowFt--;
			rowLt--;
		}
	}
}
bool Board::isColliding(char pos){
	
	int count = 0, loop  = -99;
	if(pos == 'l' || pos == 'L'){
		for(int i=x;i<=y;i++){
			if(matrix[i][rowFt] == '0'){
				loop = i;
				break;
			}
		}
	}
	else if(pos == 'r' || pos == 'R'){
		for(int i=x;i<=y;i++){
			if(matrix[i][rowLt] == '0'){
				loop = i;
				break;
			}
		}		
	}
	if(matrix[loop][rowLt+1] != '0' && pos == 'r'){
		return true;
	}
	else if(matrix[loop][rowFt-1] != '0' && pos == 'l'){
		return true;
	}
	else{
		return false;
	}	
}
void Board::moveRight(){
	int check = 0;
	if(y != R-1 && isColliding('r')){
		for(int i=x;i<=y;i++){
			for(int j=rowLt;j>=rowFt;j--){
				if(j == C-2){
					break;
				}		
				if(matrix[i][j] == '0' && matrix[i][j+1] != '0'){
					matrix[i][j+1]=matrix[i][j];
					matrix[i][j] = 95;
					check = 1;
				}
			}
		}
		if(check){
			rowFt++;
			rowLt++;
		}
	}
}
void Board::rotate(char pos){
	
	int** shapeArr;
	int left = 99 , right = 0;
	
	if(pos == 'l'){
		ptr->rotate('l');
	}	 
	else{
		ptr->rotate('r');
	}
	shapeArr=ptr->getShape();

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(shapeArr[i][j] == 1){
				if(left > j){
					left = j;
				}
				if(right < j){
					right = j;
				}
			}
		}
	}
	int k = 0 , l = 0;
	for(int i=y;i>=x;i--){
		for(int j=rowFt;j<=rowLt;j++){
			matrix[i][j] = '_';
		}
	}
	x -=2;
	int temp;
	temp = x+4;
	
	for(int i=x;i<=temp;i++){
		for(int j=rowFt;j<=(rowFt+4);j++){
			if(shapeArr[k][l] == 1){				
				matrix[i][j] = '0';
			}
			l++;
			if(l==5){
				break;
			}
		}
		l=0;
		k++;
		if(k==4){
			break;
		}
	}
	int limiter = 0,saver = 0, rowTemp = 0,tempX= 0;
	saver = x;
	rowTemp = rowFt;
	tempX = x;
	rowFt = 99;
	rowLt = 0;
	for(int i=tempX;i<tempX+4;i++){
		for(int j=rowTemp;j<=(rowTemp+4);j++){
			if(matrix[i][j] == '0' && limiter == 0){
				x = i;
				limiter = 1;
			}
			if(matrix[i][j] == '0'){	
				if(rowFt > j){
					rowFt = j;
				}
				if(rowLt < j){
					rowLt = j;
				}
			}
		}
	}
	for(int i=saver+4;i>=saver;i--){
		for(int j=rowFt;j<=rowLt;j++){
			if(matrix[i][j] == '0'){
				y = i;
				i = -2;
			}
		}
	}	
	for(int i=0;i<4;i++){
		delete[] shapeArr[i];
	}
	delete[] shapeArr;

}
void Board::gameLoop(){
	bool status = 0;
	char ch;
	while(1){
			
		system("cls");
		status = animate();
		if(kbhit()){ //kbhit()
			ch = getch();
			if(ch == 'a'){
				moveLeft();
			}
			else if(ch == 'd'){
				moveRight();
			}
			else if(ch == 's'){
				rotate('l');
			}
			else if(ch == 'w'){
				rotate('r');
			}
		}
		print();
		Sleep(320);
		if(status){
			height += x;
			delete ptr;
			kaBoom();
			switchBlock();
		}

		if(height == 1){
			gameOver();
			break;
		}
		
	}
}
void Board::print(){
	for(int i=0;i<R;i++){
		cout << "\t\t";
		for(int j=0;j<C;j++){
			cout << matrix[i][j];
			if(i == R/2 && j == C-1){
				cout << "\t\tScore =  " << score;
			}
		}
		cout << endl;
	}
}
void Board::kaBoom(){
	
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(matrix[i][j] == '0'){
				height = i;
				i = R;
			}
		}	
	}
	int count = 0;
	for(int i=R-1;i>=height;i--){
		for(int j=0;j<C;j++){
			if(matrix[i][j] == '0'){
				count++;
			}
		}
		if(count == C-2){
			boom(i);
			count = 0;
			score+=5;
			i+=2;
			
		}
		else{
			count = 0;
		}
	}
	
}
void Board::boom(int index){
	
	for(int j=1;j<C-1;j++){
		matrix[index][j] = 95;
	}
	for(int i=index;i>=height;i--){
		for(int j=1;j<C-1;j++){
			matrix[i][j] = matrix[i-1][j];
			matrix[i-1][j] = 95;
		}
	}
	
}
void Board::gameOver(){
	
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\tYour Score is =  " << score;
	cout << endl << endl << endl;
	cout << endl;
	cout << " #####     #    #     # ####### ####### #     # ####### ######\n" ;
    cout << "#     #   # #   ##   ## #       #     # #     # #       #     #\n";
    cout << "#        #   #  # # # # #       #     # #     # #       #     #\n";
    cout << "#  #### #     # #  #  # #####   #     # #     # #####   ######\n";
    cout << "#     # ####### #     # #       #     #  #   #  #       #   #\n";
    cout << "#     # #     # #     # #       #     #   # #   #       #    #\n";
    cout << " #####  #     # #     # ####### #######    #    ####### #     #\n";
	
}