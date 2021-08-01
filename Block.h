#ifndef BLOCK_H
#define BLOCK_H

class Block{
	
	protected:
		int arr[4][4];
		virtual void zerofy();
	public:
		Block();
		void draw();
		virtual void rotate(char pos)=0;
		int** getShape();
};

#endif	
