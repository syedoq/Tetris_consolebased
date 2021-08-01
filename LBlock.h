#ifndef LBLOCK_H
#define LBLOCK_H
#include"Block.h"
class L:public Block{
	
	private:
		bool rotationCompare(int arr[][4],int size);
		void copy(int temp[][4],int size);
	public:
		L();
		void rotate(char a);

};


#endif