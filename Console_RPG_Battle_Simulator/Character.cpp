#include "Character.h"
#include <iostream>
using namespace std;

void Player::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[Player] :  공격!" << endl;
}
void Player::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[Player] :  컥... 죽었다. (남은 체력 : " << hp << ")" << endl;
		isDie = true;
	}
	else {
		cout << "[Player] :  공격받았다! (남은 체력 : " << hp << ")" << endl;
	}
}
bool Player::IsDead() {
	if (!isDie) return false;
	else true;
}
void Player::Recover() {
	hp += 10;
	cout << "[Player] :  힐 (남은 체력 : " << hp << ")" << endl;
}


void Enemy::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[Enemy] :  공격!" << endl;
}
void Enemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[Enemy] :  사망" << endl;
		isDie = true;
	}
	else {
		cout << "[Enemy] :  크헉! (남은 체력 : " << hp << ")" << endl;
	}
}
bool Enemy::IsDead() {
	if (!isDie) return false;
	else true;
}


void StrongEnemy::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[StrongEnemy] :  공격!" << endl;
}
void StrongEnemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[StrongEnemy] :  사망" << endl;
		isDie = true;
	}
	else {
		cout << "[StrongEnemy] :  윽!! (남은 체력 : " << hp << ")" << endl;
	}
}
bool StrongEnemy::IsDead() {
	if (!isDie) return false;
	else true;
}