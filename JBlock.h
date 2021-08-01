#ifndef JBLOCK_H
#define JBLOCK_H
#include"Block.h"
class J:public Block{
	
	private:
		bool rotationCompare(int arr[][4],int size);
		void copy(int temp[][4],int size);
	public:
		J();
		void rotate(char a);

};


#endif