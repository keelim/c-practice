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
		AppView_out("���� ������ �ʹ� �۽��ϴ�. 3���� ũ�ų� ���ƾ� �Ѵ�. \n");
		return FALSE;

	} else if (anOrder > MAX_ORDER) {
		char messageBuffer[255];
		sprintf_s(messageBuffer, sizeof(messageBuffer), "����: ������ �ʹ� Ů�ϴ�. %d ���� �۾ƾ� �մϴ�. \n", MAX_ORDER);
		AppView_out(messageBuffer);
		return FALSE;

	} else if ((anOrder % 2) == 0) {

		AppView_out("����: ������ ¦�� �Դϴ�. Ȧ���̾�� �մϴ�. \n");
		return FALSE;

	} else {
		return TRUE;
	}
}


void MagicSquare_solve(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) {
	int row, col;

	for (row = 0; row < anOrder; row++) { //ó������ -1�� �����Ѵ�. 
		for (col = 0; col < anOrder; col++) {
			aBoard[row][col] = EMPTY_CELL;
		}
	}

	CellLocation cu_loc;
	CellLocation next_loc;

	cu_loc._row = 0;
	cu_loc._col = anOrder / 2;

	int CellValue = 1;
	aBoard[cu_loc._row][cu_loc._col] = CellValue;

	int lastCellValue = anOrder * anOrder;
	CellValue = 2;
	next_loc = cu_loc;

	for (CellValue = 2; CellValue <= lastCellValue; CellValue++) {

		next_loc._row = cu_loc._row - 1;

		if (next_loc._row < 0) {
			next_loc._row = anOrder - 1;

		}
		next_loc._col = cu_loc._col + 1;

		if (cu_loc._col >= anOrder) {
			next_loc._col = 0;

		}

		
		if (aBoard[next_loc._row][next_loc._col] != EMPTY_CELL) { //ä���� �ִ����� Ȯ��
			next_loc._row = cu_loc._row + 1;
			next_loc._col = cu_loc._col;

		}
					   		 
		cu_loc = next_loc;
	}


}



