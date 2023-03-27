#include<iostream>
#include<stdio.h>
#include<vector>

using namespace::std;

class point{
public:
	int cord_x;
	int cord_y;
	point(int x, int y){
		cord_x = x;
		cord_y = y;
	}
};

class solution{
private:
	int count;
	vector<vector<int>> board;

public:
	solution(int length){
		count = 1;
		vector<int> temp(length, 1);
		for(int i=0;i<length;i++){
			board.push_back(temp);
		}
	}
	
	void init_squares(vector<point> black_squares){
		for(int i=0;i<black_squares.size();i++){
			board[black_squares[i].cord_x][black_squares[i].cord_y] = 0;
		}
	}
	
	void print_board(){
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board.size();j++){
				printf("%d ",board[i][j]);
			}
			printf("\n");
		}
	}
	
	void one_black_square(point black_square, point start, int length){
		int dimension = calculate_dimension(black_square, start, length);
		if(length == 2){
			put_tromino(dimension, start);
		}
		if(dimension != 1){
			one_black_square(point(length/2-1, length/2-1), start, length/2);
		}
		if(dimension != 2){
			one_black_square(point(length/2, length/2-1), point(start.cord_x+length/2, start.cord_y), length/2);
		}
		if(dimension != 3){
			one_black_square(point(length/2-1, length/2), point(start.cord_x, start.cord_y+length/2), length/2);
		}
		if(dimension != 4){
			one_black_square(point(length/2, length/2), point(start.cord_x+length/2, start.cord_y+length/2), length/2);
		}
		one_black_square(black_square, point(start.cord_x+length/2, start.cord_y+length/2), length/2);
		put_tromino(dimension, point(length/2-1, length/2-1));
	}
	
	int calculate_dimension(point black_square, point start, int length){
		if(black_square.cord_x < start.cord_x+length/2){
			if(black_square.cord_y < start.cord_y+length/2){
				return 1;
			}else{
				return 3;
			}
		}else{
			if(black_square.cord_y < start.cord_y+length/2){
				return 2;
			}else{
				return 4;
			}
		}
	}
	
	void put_tromino(int dimension, point start){
		
		if(dimension != 1){
			board[start.cord_x][start.cord_y] = count;
		}
		if(dimension != 2){
			board[start.cord_x+1][start.cord_y] = count;
		}
		if(dimension != 3){
			board[start.cord_x][start.cord_y+1] = count;
		}
		if(dimension != 4){
			board[start.cord_x+1][start.cord_y+1] = count;
		}
		printf("hi\n");
		count++;
	}
};

int main(){
	int black_num = 0, len = 0;
	scanf("%d %d", &black_num, &len);
	
	vector<point> black_squares;
	
	for(int i=0;i<black_num;i++){
		int x, y;
		scanf("%d %d", &x, &y);
		black_squares.push_back(point(x,y));
	}
	printf("hi\n");
	solution ans = solution(len);
	ans.init_squares(black_squares);
	ans.one_black_square(black_squares[0], point(0, 0), len);
	ans.print_board();
	return 0;
}

