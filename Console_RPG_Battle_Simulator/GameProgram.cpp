#include <iostream>
#include "Character.h"
using namespace std;

// Lab : 콘솔 RPG 전투 시뮬레이터
// 자식클래스 인스턴스를 부모클래스 타입으로 다루어 게임로직을 만들기

/* 게임 규칙 */
// 턴제 방식으로 플레이어는 공격, 강화, 힐을 선택할 수 있다.
// 체력이 0이되면 Game Over, Enemy를 모두 처치하면 Game Success

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
	cout << "////////// 콘솔 RPG 전투 시뮬레이터 /////////" << endl;
	cout << "/////////////////////////////////////////////\n\n";

	cout << "<< 게임 규칙 설명 >>" << endl;
	cout << "플레이어는 턴 마다 공격/강화/힐을 선택할 수 있습니다." << endl;
	cout << "체력이 0이되면 Game Over.. Enemy를 모두 처치하면 Game Success!\n\n";


	// Player Create
	cout << "\nPlayer가 스폰됩니다..." << endl;
	Character* player = new Player();
	
	// Enemy Create
	cout << "\nEnemy가 스폰됩니다..." << endl;
	Character* enemyArr[enemyCount];
	for (int i = 0; i < enemyCount; i++){
		enemyArr[i] = new Enemy();
	}

	// Strong Enemy 선언
	Character* s_enemyArr[s_enemyCount];


	// Game Loop
	while (!isClear)
	{
		/*     Player Turn     */
		// command input
		cout << "\n\n\nPlayer Turn" << endl;
		cout << "명령어를 입력하세요(공격 1 / 강화 2 / 힐 3)  >>> ";
		cin >> playerCommand;

		// Level에 따라 공격 대상(enemy, s_enemy) controll
		if (level == 1) {
			switch (playerCommand)
			{
			case 1:
				cout << "입력 : 공격" << endl;
				player->Attack(enemyArr[currentEnemy]);

				if (enemyArr[currentEnemy]->IsDead()) {
					delete enemyArr[currentEnemy];
					currentEnemy++;
					cout << "남은 Enemy :  " << (enemyCount - currentEnemy) << endl;

					if (currentEnemy >= enemyCount) {
						level++;
						cout << "\nStrong Enemy가 스폰됩니다..." << endl;
						for (int i = 0; i < s_enemyCount; i++) {
							s_enemyArr[i] = new StrongEnemy();
						}
						cout << "\n이제 Strong Enemy가 나옵니다!\n\n";
					}
				}
				break;

			case 2:
				cout << "입력 : 강화" << endl;
				((Player*)player)->PowerUp();
				break;

			case 3:
				cout << "입력 : 힐" << endl;
				((Player*)player)->Recover();
				break;

			default:
				cout << "공격 기회 놓침..." << endl;
				break;
			}
		}
		else {
			switch (playerCommand)
			{
			case 1:
				cout << "입력 : 공격" << endl;
				player->Attack(s_enemyArr[s_currentEnemy]);

				if (s_enemyArr[s_currentEnemy]->IsDead()) {
					delete s_enemyArr[s_currentEnemy];
					s_currentEnemy++;

					if (s_currentEnemy >= s_enemyCount) {
						isClear = true;
					}
				}
				cout << "남은 Strong Enemy :  " << (s_enemyCount - s_currentEnemy) << endl;
				break;
			case 2:
				cout << "입력 : 강화" << endl;
				((Player*)player)->PowerUp();
				break;
			case 3:
				cout << "입력 : 힐" << endl;
				((Player*)player)->Recover();
				break;
			default:
				cout << "공격 기회 놓침..." << endl;
				break;
			}
		}
		
		/*     Enemy Turn     */
		// Level에 따라 공격 주체(enemy, s_enemy) controll
		if (!isClear) {
			cout << "\n\nEnemy Turn" << endl;
			if (level == 1) enemyArr[currentEnemy]->Attack(player);
			else s_enemyArr[s_currentEnemy]->Attack(player);
		}
	}

	// 게임 종료
	if(isClear) cout << "\n\nGame Success!\n\n\n";
	if (!isClear) cout << "\n\nGame Overn\n\n\n";
}