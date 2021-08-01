#ifndef BOARD_H
#define BOARD_H

#include "SquareBlock.h"
#include "StickBlock.h"
#include "TBlock.h"
#include "SBlock.h"
#include "ZBlock.h"
#include "JBlock.h"
#include "LBlock.h"

class Board{

	private:
		static const int R = 24;   //Define Rows of the Board
		static const int C = 20;	//Coloumns of the Board
		char matrix[R][C];			//Board Array
		Block* ptr;				//Block type Pointer
		int x;					//Height index(row) of the current Block
		int y;					//Base Height of the current Block
		int rowFt;				//The first index(cols) of current Block
		int rowLt;				//Last index(cols) of current Block			
		int height;				//MAXIMUM height in board array	
		int score;
	public:
		Board();
		void gameLoop();		
		void copyCurrentShape();  //COPY THE CURRENT BLOCK TO BOARD ARRAY
		bool animate();			//BRINGS ONE STEP DOWNWARDS IF REACHED TO BOTTOM RETURN TRUE
		void print();		
		void switchBlock();		//CHANGE THE POINTER TYPE OF BLOCK(CHANGING THE SHAPE)
		void rotate(char pos);	
		void moveLeft();
		void moveRight();
		bool isExist();		//CHECK IF IT COLLIDES WITH THE PREVIOUS BLOCK
		void gameOver();
		void kaBoom();				//1) find which index to boom
		void boom(int index);		//2) boom the index and swap blocks
		bool isColliding(char pos);	//Extension of move (left and right)	
		void menu();
};

#endif