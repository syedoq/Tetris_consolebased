#ifndef SBLOCK_H
#define SBLOCK_H
#include"Block.h"
class S:public Block{
	
	private:
		bool rotationCompare(int arr[][4],int size);
		void copy(int temp[][4],int size);
	public:
		S();
		void rotate(char a);

};


#endif