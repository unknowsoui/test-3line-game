#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#define MAX_ROW 3
#define MAX_COL 3

int chess_board[MAX_ROW][MAX_COL];
void chessauto(){
	for (int i = 0; i < MAX_ROW; i++){
		for (int j = 0; j < MAX_COL; j++){
			chess_board[i][j] = ' ';
		}
	}
}
void print(){
	for (int i = 0; i < MAX_ROW; i++){
		printf("|%c|%c|%c|\n", chess_board[i][0], chess_board[i][1], chess_board[i][2]);
		if (i < MAX_ROW - 1){
			printf("|-|-|-|\n"); 
		}
	}
}
void playermove(){
	printf("玩家落子\n");
	int row=0, col=0;
	while (1){
		printf("输入坐标(例如3 3):\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || row > 2 || col < 0 || col > 2){
			printf("坐标输入有误！\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("坐标已经被占用了!\n");
			continue;
		}
		chess_board[row][col]='x';
		break;
	}
}
void compmove(){
	printf("计算机落子\n");
	srand((unsigned int)time(0));
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
char check(){
	int row, col;
	for (int row = 0; row < 3; row++){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2] ){
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < 3; col++){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (isfull() == 1){
		return 'q';
	}
	return ' ';
}
int isfull(){
	int row, col;
	for (row = 0; row < MAX_ROW; row++){
		for (col = 0; col < MAX_COL; col++){
			if (chess_board[row][col]==' '){
				break;
			}
		}
		if (col != 3){
			break;
		}
	}
	if (row == 3 && col == 3){
		return 1;
	}
}

void game(){
	char flag=' ';
	chessauto();
	while (1){
		print();
		playermove();
		flag = check();
		if (flag != ' '){
			break;
		}
		compmove();
		flag = check();
		if (flag != ' '){
			break;
		}
	}
	print();
	if (flag == 'x'){
		printf("赢\n");
	}
	else if (flag == 'o'){
		printf("草\n");
	}
	else if (flag == 'q'){
		printf("和\n");
	}
	else
		printf("error!\n");
	Sleep(1000);
	system("cls");
}
int main(){
	int choice = 0;
	while (1)
	{
		printf("**************************************\n");
		printf("1.begin\n");
		printf("2.exit\n");
		printf("**************************************\n");
		scanf("%d", &choice);
		if (choice == 1){
			game();
			system("cls");
		}
		else if (choice == 2){
			break;
		}
		else{
			printf("error!!");
			continue;
		}
	}
	system("pause");
}
}