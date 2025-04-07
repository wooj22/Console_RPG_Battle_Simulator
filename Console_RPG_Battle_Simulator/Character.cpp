#include "Character.h"
#include <iostream>
using namespace std;

/*----------------- Player ------------------*/
void Player::Show() {
	cout << "[Player] HP : " << hp << ", Power : " << power << endl;
}

void Player::Attack(Character* other) {
	cout << "[Player] : ����!" << endl;
	other->TakeDamage(this->power);
}

void Player::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[Player] : ��... ����.. (���� ü�� : " << hp << ")" << endl;
		isDie = true;
	}
	else {
		cout << "[Player] : ���ݹ޾Ҵ�.. (���� ü�� : " << hp << ")" << endl;
	}
}

bool Player::IsDead() {
	return isDie;
}

void Player::Recover() {
	hp += 30;
	if (hp >= 100) hp = 100;
	cout << "[Player] : �� (���� ü�� : " << hp << ")" << endl;
}

void Player::PowerUp() {
	power += 10;
	cout << "[Player] : Power ��ȭ (���� Power : " << power << ")" << endl;
}


/*----------------- Enemy ------------------*/
void Enemy::Show() {
	cout << "[Enemy] HP : " << hp << ", Power : " << power << endl;
}

void Enemy::Attack(Character* other) {
	cout << "[Enemy] : ����" << endl; 
	other->TakeDamage(this->power);
}

void Enemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[Enemy] : ���" << endl;
		isDie = true;
	}
	else {
		cout << "[Enemy] : ũ�� (���� ü�� : " << hp << ")" << endl;
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
	cout << "[StrongEnemy] : ����" << endl; 
	other->TakeDamage(this->power);
}

void StrongEnemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp <= 0) {
		hp = 0;
		cout << "[StrongEnemy] :  ���" << endl;
		isDie = true;
	}
	else {
		cout << "[StrongEnemy] :  �� (���� ü�� : " << hp << ")" << endl;
	}
}

bool StrongEnemy::IsDead() {
	return isDie;
}