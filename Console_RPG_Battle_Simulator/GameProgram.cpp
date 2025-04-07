#include <iostream>
#include "Character.h"
using namespace std;

// Lab : �ܼ� RPG ���� �ùķ�����
// �ڽ�Ŭ���� �ν��Ͻ��� �θ�Ŭ���� Ÿ������ �ٷ�� ���ӷ����� �����

/* ���� ��Ģ */
// ���� ������� �÷��̾�� ����, ��ȭ, ���� ������ �� �ִ�.
// ü���� 0�̵Ǹ� Game Over, Enemy�� ��� óġ�ϸ� Game Success

// play data
int playerCommand;
int level = 1;
bool isClear = false;

// enemy data
const int enemyCount = 10;
const int s_enemyCount = 5;
int currentEnemy = 0;
int s_currentEnemy = 0;

// main program
int main() {
	cout << "/////////////////////////////////////////////" << endl;
	cout << "////////// �ܼ� RPG ���� �ùķ����� /////////" << endl;
	cout << "/////////////////////////////////////////////\n\n";

	cout << "<< ���� ��Ģ ���� >>" << endl;
	cout << "�÷��̾�� �� ���� ����/��ȭ/���� ������ �� �ֽ��ϴ�." << endl;
	cout << "ü���� 0�̵Ǹ� Game Over.. Enemy�� ��� óġ�ϸ� Game Success!\n\n";


	// Player Create
	cout << "\nPlayer�� �����˴ϴ�..." << endl;
	Character* player = new Player();
	
	// Enemy Create
	cout << "\nEnemy�� �����˴ϴ�..." << endl;
	Character* enemyArr[enemyCount];
	for (int i = 0; i < enemyCount; i++){
		enemyArr[i] = new Enemy();
	}

	// Strong Enemy ����
	Character* s_enemyArr[s_enemyCount];


	// Game Loop
	while (!isClear)
	{
		/*     Player Turn     */
		// command input
		cout << "\n\n\nPlayer Turn" << endl;
		cout << "��ɾ �Է��ϼ���(���� 1 / ��ȭ 2 / �� 3)  >>> ";
		cin >> playerCommand;

		// Level�� ���� ���� ���(enemy, s_enemy) controll
		if (level == 1) {
			switch (playerCommand)
			{
			case 1:
				cout << "�Է� : ����" << endl;
				player->Attack(enemyArr[currentEnemy]);

				if (enemyArr[currentEnemy]->IsDead()) {
					delete enemyArr[currentEnemy];
					currentEnemy++;
					cout << "���� Enemy :  " << (enemyCount - currentEnemy) << endl;

					if (currentEnemy >= enemyCount) {
						level++;
						cout << "\nStrong Enemy�� �����˴ϴ�..." << endl;
						for (int i = 0; i < s_enemyCount; i++) {
							s_enemyArr[i] = new StrongEnemy();
						}
						cout << "\n���� Strong Enemy�� ���ɴϴ�!\n\n";
					}
				}
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
		else {
			switch (playerCommand)
			{
			case 1:
				cout << "�Է� : ����" << endl;
				player->Attack(s_enemyArr[s_currentEnemy]);

				if (s_enemyArr[s_currentEnemy]->IsDead()) {
					delete s_enemyArr[s_currentEnemy];
					s_currentEnemy++;

					if (s_currentEnemy >= s_enemyCount) {
						isClear = true;
					}
				}
				cout << "���� Strong Enemy :  " << (s_enemyCount - s_currentEnemy) << endl;
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
		
		/*     Enemy Turn     */
		// Level�� ���� ���� ��ü(enemy, s_enemy) controll
		if (!isClear) {
			cout << "\n\nEnemy Turn" << endl;
			if (level == 1) enemyArr[currentEnemy]->Attack(player);
			else s_enemyArr[s_currentEnemy]->Attack(player);
		}
	}

	// ���� ����
	if(isClear) cout << "\n\nGame Success!\n\n\n";
	if (!isClear) cout << "\n\nGame Overn\n\n\n";
}