#include "Character.h"
#include <iostream>
using namespace std;

/*----------------- Player ------------------*/
void Player::Show() {
	cout << "[Player] HP : " << hp << ", Power : " << power << endl;
}

void Player::Attack(Character* other) {
	cout << "[Player] : 공격!" << endl;
	other->TakeDamage(this->power);
}

void Player::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[Player] : 컥... 졌다.. (남은 체력 : " << hp << ")" << endl;
		isDie = true;
	}
	else {
		cout << "[Player] : 공격받았다.. (남은 체력 : " << hp << ")" << endl;
	}
}

bool Player::IsDead() {
	return isDie;
}

void Player::Recover() {
	hp += 30;
	if (hp >= 100) hp = 100;
	cout << "[Player] : 힐 (남은 체력 : " << hp << ")" << endl;
}

void Player::PowerUp() {
	power += 10;
	cout << "[Player] : Power 강화 (현재 Power : " << power << ")" << endl;
}


/*----------------- Enemy ------------------*/
void Enemy::Show() {
	cout << "[Enemy] HP : " << hp << ", Power : " << power << endl;
}

void Enemy::Attack(Character* other) {
	cout << "[Enemy] : 공격" << endl; 
	other->TakeDamage(this->power);
}

void Enemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[Enemy] : 사망" << endl;
		isDie = true;
	}
	else {
		cout << "[Enemy] : 크헉 (남은 체력 : " << hp << ")" << endl;
	}
}

bool Enemy::IsDead() {
	return isDie;
}



/*----------------- Strong Enemy ------------------*/
void StrongEnemy::Show() {
	cout << "[StrongEnemy] HP : " << hp << ", Power : " << power << endl;
}

void StrongEnemy::Attack(Character* other) {
	cout << "[StrongEnemy] : 공격" << endl; 
	other->TakeDamage(this->power);
}

void StrongEnemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[StrongEnemy] :  사망" << endl;
		isDie = true;
	}
	else {
		cout << "[StrongEnemy] :  윽 (남은 체력 : " << hp << ")" << endl;
	}
}

bool StrongEnemy::IsDead() {
	return isDie;
}