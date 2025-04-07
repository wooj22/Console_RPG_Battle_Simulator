#include <iostream>
#include "Character.h"
using namespace std;

// Lab : 콘솔 RPG 전투 시뮬레이터
// 자식클래스 인스턴스를 부모클래스 타입으로 다루어 게임로직을 만들기

/* 게임 규칙 */
// 턴제 방식으로 플레이어는 공격, 강화, 힐을 선택할 수 있다.
// 체력이 0이되면 Game Over, Enemy를 모두 처치하면 Game Success

const int enemyCount = 10;
const int s_enemyCount = 5;
int playerCommand;

int main() {
	cout << "/////////////////////////////////////////////" << endl;
	cout << "////////// 콘솔 RPG 전투 시뮬레이터 /////////" << endl;
	cout << "/////////////////////////////////////////////\n\n";

	cout << "<< 게임 규칙 설명 >>" << endl;
	cout << "플레이어는 턴 마다 공격/강화/힐을 선택할 수 있습니다." << endl;
	cout << "체력이 0이되면 Game Over.. Enemy를 모두 처치하면 Game Success!\n\n";

	// 캐릭터 스폰
	cout << "\nPlayer가 스폰됩니다..." << endl;
	Character* player = new Player();
	
	cout << "\nEnemy가 스폰됩니다..." << endl;
	Character* enemyArr[enemyCount];
	for (int i = 0; i < enemyCount; i++){
		enemyArr[i] = new Enemy();
	}

	cout << "\nStrong Enemy가 스폰됩니다..." << endl;
	Character* s_enemyArr[s_enemyCount];
	for (int i = 0; i < s_enemyCount; i++) {
		s_enemyArr[i] = new StrongEnemy();
	}
	
	// 게임 진행
	while (!player->IsDead())
	{
		cout << "\n\n\nPlayer Turn!" << endl;
		cout << "명령어를 입력하세요(공격 1 / 강화 2 / 힐 3)  >>> ";
		cin >> playerCommand;
		switch (playerCommand)
		{
		case 1:
			cout << "입력 : 공격" << endl;
			player->Attack(enemyArr[0]);
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

	// 게임 종료
	cout << "게임 종료";
}