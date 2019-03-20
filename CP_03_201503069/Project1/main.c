#include"Common.h"
#include"MagicSquare.h"
#include"AppView.h"



#define END_OF_RUN -1

void Main_showBoard(int anOrder, int aBoard[MAX_ORDER][MAX_ORDER]) {
	char messageBuffer[255];

	sprintf_s(messageBuffer, sizeof(messageBuffer), "> Magic Square Board: ORder %2d\n", anOrder);
	AppView_out(messageBuffer);
	AppView_out("    ");

	for (int col = 0; col < anOrder; col++) {
		sprintf_s(messageBuffer, sizeof(messageBuffer), "[%2d]", col);
		AppView_out(messageBuffer);
	}

	AppView_out("\n");

	for (int row = 0; row < anOrder; row++) {
		printf("[%2d]", row);//���� �ؾ� ��
		for (int col = 0; col < anOrder; col++) {
			//�����ؾ� ��
			printf(" %d", aBoard[row][col]);

		}
		printf("\n");
	}

	AppView_out("\n");




}


int main() {
	int inputOrder;
	int board[MAX_ORDER][MAX_ORDER];

	AppView_out("<<< ������ Ǯ�̸� �����մϴ�. >>>\n");
	inputOrder = AppView_in_order(); //scanf �� ���Ͽ� �Է��� �޴´�. 
	while (inputOrder != END_OF_RUN) { //�����̸� ����

		if (MagicSquare_ordersVaild(inputOrder)) { //��ȿ�������� Ȯ��
			MagicSquare_solve(inputOrder, board); //���� �ذ�

			Main_showBoard(inputOrder, board);    //������ ��Ÿ����
		}

		inputOrder = AppView_in_order(); //���Է�
	}
	AppView_out("\n <<< ������ Ǯ�̸� �����մϴ�. >>>\n");


	return 0;
} //main ����
