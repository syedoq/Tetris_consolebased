#include<iostream>
#include"SBlock.h"
using namespace std;
S::S(){
	zerofy();
	arr[2][2]=1;
	arr[2][3]=1;
	arr[3][1]=1;
	arr[3][2]=1;
}
void S::rotate(char pos){

	int counter = 0;
							//ALL POSSIBLE ROTATIONS
	int rotate1[4][4]={{0,0,0,0},{0,0,0,0},{0,0,1,1},{0,1,1,0}};
	int rotate2[4][4]={{0,0,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0}};
	
	if(rotationCompare(rotate1,4)){
		counter = 1;
	}
	else if(rotationCompare(rotate2,4)){
		counter = 2;
	}
	
	if(pos == 'L' || pos == 'l'){
		if(counter == 1){
			copy(rotate2,4);
		}
		else if(counter == 2){
			copy(rotate1,4);
		}
	}
	else if(pos == 'R' || pos == 'r'){
		if(counter == 1){
			copy(rotate2,4);
		}
		else if(counter == 2){
			copy(rotate1,4);
		}
	}
}
void S::copy(int temp[][4],int size){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			arr[i][j] = temp[i][j];
		}
	}
	
}
bool S::rotationCompare(int temp[][4],int size){
	int count = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j]==temp[i][j]){
				count++;
			}
		}
	}
	if(count == 16){
		return true;
	}
	else{
		return false;
	}
}