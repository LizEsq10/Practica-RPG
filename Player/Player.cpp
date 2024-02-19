//
// Created by Victor Navarro on 15/02/24.
//

#include "Player.h"

Player::Player(string _name, int _health, int _attack, int _defense, int _speed) : Character(_name, _health, _attack, _defense, _speed) {
    level = 1;
    experience = 0;
}

void Player::doAttack(Character *target) {
    target->takeDamage(attack);
}

void Player::takeDamage(int damage) {
     TrueDamage = damage - defense;

    health-= TrueDamage;
}

void Player::levelUp() {
    level++;
}

int Player ::getTrueDamage() {
    return TrueDamage;
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 100-experience;
    }

}