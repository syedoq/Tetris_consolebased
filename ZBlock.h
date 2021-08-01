#ifndef ZBLOCK_H
#define ZBLOCK_H
#include"Block.h"
class Z:public Block{
	
	private:
		bool rotationCompare(int arr[][4],int size);
		void copy(int temp[][4],int size);
	public:
		Z();
		void rotate(char a);

};


#endif