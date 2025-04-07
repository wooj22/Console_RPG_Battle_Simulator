#include "Character.h"
#include <iostream>
using namespace std;

void Player::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[Player] :  ����!" << endl;
}
void Player::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[Player] :  ��... �׾���. (���� ü�� : " << hp << ")" << endl;
		isDie = true;
	}
	else {
		cout << "[Player] :  ���ݹ޾Ҵ�! (���� ü�� : " << hp << ")" << endl;
	}
}
bool Player::IsDead() {
	if (!isDie) return false;
	else true;
}
void Player::Recover() {
	hp += 10;
	cout << "[Player] :  �� (���� ü�� : " << hp << ")" << endl;
}


void Enemy::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[Enemy] :  ����!" << endl;
}
void Enemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[Enemy] :  ���" << endl;
		isDie = true;
	}
	else {
		cout << "[Enemy] :  ũ��! (���� ü�� : " << hp << ")" << endl;
	}
}
bool Enemy::IsDead() {
	if (!isDie) return false;
	else true;
}


void StrongEnemy::Attack(Character* other) {
	other->TakeDamage(this->power);
	cout << "[StrongEnemy] :  ����!" << endl;
}
void StrongEnemy::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) {
		hp = 0;
		cout << "[StrongEnemy] :  ���" << endl;
		isDie = true;
	}
	else {
		cout << "[StrongEnemy] :  ��!! (���� ü�� : " << hp << ")" << endl;
	}
}
bool StrongEnemy::IsDead() {
	if (!isDie) return false;
	else true;
}