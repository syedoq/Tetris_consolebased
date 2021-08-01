#include<iostream>
#include"Block.h"
using namespace std;

Block::Block(){
	zerofy();
}
void Block::draw(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(arr[i][j] == 1){
				cout << "#";
			}
			else{
				cout << " ";
			}
		}
		cout << endl;
	}
}
int** Block::getShape(){
	int** temp = new int*[4];
	for(int i=0;i<4;i++){
		temp[i]=new int[4];
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			temp[i][j]=arr[i][j];
		}
	}
	return temp;
}
void Block::zerofy(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			arr[i][j]=0;
		}
	}
}
