// 201503069 김재현
#include"MagicSquare.h"
#include"AppView.h"
#include<stdio.h>

typedef struct {
	int _row;
	int _col;
} CellLocation;

#define EMPTY_CELL -1

Boolean MagicSquare_ordersVaild(int anOrder) {
	if (anOrder < 3) {
		AppView_out("오류 차수가 너무 작습니다. 3보다 크거나 같아야 합니다. \n");
		return FALSE;

	} else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "오류: 차수가 너무 큽니다. %d 보다 작아야 합니다. \n", MAX_ORDER);
		AppView_out(messageBuffer);
		return FALSE;

	} else if ((anOrder % 2) == 0) {

		AppView_out("오류: 차수가 짝수 입니다. 홀수이어야 합니다. \n");
		return FALSE;

	} else {
		return TRUE;
	}
}


void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) {
	int row, col;

	for (row = 0; row < anOrder; row++) { //처음에는 -1을 대입한다. 
		for (col = 0; col < anOrder; col++) {
			aBoard[row][col] = EMPTY_CELL;
		}
	}

	CellLocation cu_loc;
	CellLocation next_loc;

	cu_loc._row = 0;
	cu_loc._col = anOrder / 2;
	next_loc._row = 0;
	next_loc._col = anOrder / 2;


	int CellValue = 1;
	aBoard[cu_loc._row][cu_loc._col] = CellValue;

	int lastCellValue = anOrder * anOrder; // 제곱수로 돌아가야 하니까
	CellValue = 2; //1은 채웠으니까


	for (CellValue = 2; CellValue <= lastCellValue; CellValue++) {

		next_loc._row -= 1;

		if (next_loc._row < 0) {
			next_loc._row = anOrder - 1;

		}
		next_loc._col += 1;

		if (next_loc._col >= anOrder) {
			next_loc._col = 0;

		}


		if (aBoard[next_loc._row][next_loc._col] != EMPTY_CELL) { //-1이 아닌수로 채워져 있는지를 확인
			next_loc._row = cu_loc._row + 1;
			next_loc._col = cu_loc._col;

		}
		aBoard[next_loc._row][next_loc._col] = CellValue; //cellValue 로 정의

		cu_loc = next_loc;
	}


}



