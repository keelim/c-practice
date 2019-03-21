// 201503069 ������
#include"Common.h"
#include"MagicSquare.h"
#include"AppView.h"



#define END_OF_RUN -1

void Main_showBoard(MagicSquare aMagicSquare) {
	int anOrder = aMagicSquare._order;
	
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
			printf("  %d", aMagicSquare._board[row][col]);

		}
		printf("\n");
	}

	AppView_out("\n");




}


int main() {
	MagicSquare magicSquare;
	
	AppView_out("<<< ������ Ǯ�̸� �����մϴ�. >>>\n");
	int inputOrder = AppView_in_order(); //scanf �� ���Ͽ� �Է��� �޴´�. 
	while (inputOrder != END_OF_RUN) { //�����̸� ����
		magicSquare._order = inputOrder;
		if (MagicSquare_ordersVaild(magicSquare)) { //��ȿ�������� Ȯ��
			MagicSquare_solve(magicSquare, magicSquare._board); //���� �ذ�

			Main_showBoard(magicSquare);    //������ ��Ÿ����
		}

		inputOrder = AppView_in_order(); //���Է�
	}
	AppView_out("\n <<< ������ Ǯ�̸� �����մϴ�. >>>\n");


	return 0;
}
