// 201503069 ������
#include "Common.h"

typedef struct {
	int _order;
	int _board[MAX_ORDER][MAX_ORDER];
} MagicSquare //����� ��ġ�� �߿��ϴ�. 

Boolean MagicSquare_ordersVaild(MagicSquare);
void MagicSquare_solve(MagicSquare , int aBoard[MAX_ORDER][MAX_ORDER]);



