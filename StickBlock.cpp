#include<iostream>
#include"StickBlock.h"

Stick::Stick(){
	zerofy();
	for(int i=0;i<4;i++){
		arr[i][1] = 1;
	}
}
void Stick::rotate(char a){
	if(arr[0][1]==1){
		zerofy();
		for(int i=0;i<4;i++){
			arr[3][i] = 1;
		}	
	}
	else{
		zerofy();
		for(int i=0;i<4;i++){
			arr[i][1] = 1;
		}	
	}
}

