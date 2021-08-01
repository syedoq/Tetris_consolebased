#ifndef TBLOCK_H
#define TBLOCK_H
#include"Block.h"
class T:public Block{
	
	private:
		bool rotationCompare(int arr[][4],int size);
		void copy(int temp[][4],int size);
	public:
		T();
		void rotate(char a);
	
};


#endif