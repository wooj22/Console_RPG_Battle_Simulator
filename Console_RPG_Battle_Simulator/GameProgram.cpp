#include <iostream>
#include "Character.h"
using namespace std;

// Lab : �ܼ� RPG ���� �ùķ�����
// �ڽ�Ŭ���� �ν��Ͻ��� �θ�Ŭ���� Ÿ������ �ٷ�� ���ӷ����� �����

/* ���� ��Ģ */
// ���� ������� �÷��̾�� ����, ��ȭ, ���� ������ �� �ִ�.
// ü���� 0�̵Ǹ� Game Over, Enemy�� ��� óġ�ϸ� Game Success

const int enemyCount = 10;
const int s_enemyCount = 5;
int playerCommand;

int main() {
	cout << "/////////////////////////////////////////////" << endl;
	cout << "////////// �ܼ� RPG ���� �ùķ����� /////////" << endl;
	cout << "/////////////////////////////////////////////\n\n";

	cout << "<< ���� ��Ģ ���� >>" << endl;
	cout << "�÷��̾�� �� ���� ����/��ȭ/���� ������ �� �ֽ��ϴ�." << endl;
	cout << "ü���� 0�̵Ǹ� Game Over.. Enemy�� ��� óġ�ϸ� Game Success!\n\n";

	// ĳ���� ����
	cout << "\nPlayer�� �����˴ϴ�..." << endl;
	Character* player = new Player();
	
	cout << "\nEnemy�� �����˴ϴ�..." << endl;
	Character* enemyArr[enemyCount];
	for (int i = 0; i < enemyCount; i++){
		enemyArr[i] = new Enemy();
	}

	cout << "\nStrong Enemy�� �����˴ϴ�..." << endl;
	Character* s_enemyArr[s_enemyCount];
	for (int i = 0; i < s_enemyCount; i++) {
		s_enemyArr[i] = new StrongEnemy();
	}
	
	// ���� ����
	while (!player->IsDead())
	{
		cout << "\n\n\nPlayer Turn!" << endl;
		cout << "��ɾ �Է��ϼ���(���� 1 / ��ȭ 2 / �� 3)  >>> ";
		cin >> playerCommand;
		switch (playerCommand)
		{
		case 1:
			cout << "�Է� : ����" << endl;
			player->Attack(enemyArr[0]);
			break;
		case 2:
			cout << "�Է� : ��ȭ" << endl;
			((Player*)player)->PowerUp();
			break;
		case 3:
			cout << "�Է� : ��" << endl;
			((Player*)player)->Recover();
			break;
		default:
			cout << "���� ��ȸ ��ħ..." << endl;
			break;
		}
		
	}

	// ���� ����
	cout << "���� ����";
}