#include<iostream>
#include"LBlock.h"
using namespace std;
L::L(){
	zerofy();
	for(int i=1;i<4;i++){
		arr[i][1] = 1;
	}
	arr[3][2] = 1;
}
void L::rotate(char pos){

	int counter = 0;
							//ALL POLLIBLE ROTATIONL
	int rotate1[4][4]={{0,0,0,0},
					   {0,1,0,0},
					   {0,1,0,0},
					   {0,1,1,0}};
	int rotate2[4][4]={{0,0,0,0},
					   {0,0,0,0},
					   {0,0,0,1},
					   {0,1,1,1}};
	int rotate3[4][4]={{0,0,0,0},
					   {0,1,1,0},
					   {0,0,1,0},
					   {0,0,1,0}};
	int rotate4[4][4]={{0,0,0,0},
					   {0,0,0,0},
					   {0,1,1,1},
					   {0,1,0,0}};
	
	if(rotationCompare(rotate1,4)){
		counter = 1;
	}
	else if(rotationCompare(rotate2,4)){
		counter = 2;
	}
	else if(rotationCompare(rotate3,4)){
		counter = 3;
	}
	else if(rotationCompare(rotate4,4)){
		counter = 4;
	}
	
	if(pos == 'L' || pos == 'l'){
		if(counter == 1){
			copy(rotate2,4);
		}
		else if(counter == 2){
			copy(rotate3,4);
		}
		else if(counter == 3){
			copy(rotate4,4);
		}
		else if(counter == 4){
			copy(rotate1,4);
		}
	}
	else if(pos == 'R' || pos == 'r'){
		if(counter == 1){
			copy(rotate4,4);
		}
		else if(counter == 2){
			copy(rotate1,4);
		}
		else if(counter == 3){
			copy(rotate2,4);
		}
		else if(counter == 4){
			copy(rotate3,4);
		}
	}
}
void L::copy(int temp[][4],int size){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			arr[i][j] = temp[i][j];
		}
	}
	
}
bool L::rotationCompare(int temp[][4],int size){
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
