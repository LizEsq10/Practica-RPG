#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    Player *player = new Player("Mago", 100, 8, 4, 10);
    Enemy *enemy = new Enemy("Bestia", 50, 5, 2, 5, 10);
    int ronda =1;

    cout << player->toString() << endl;
    cout << enemy->toString() << endl;

    cout << "=====================" << endl;

    /*player->doAttack(enemy);
    enemy->doAttack(player);*/

        do {
            cout << "Turno " << ronda++ << endl;
            player->doAttack(enemy);
            cout << "El jugador " << player->getName() << "ha atacado al " << enemy->getName() << " con: "
                 << enemy->getTrueDamage() << endl;
            enemy->doAttack(player);
            cout << "El jugador " << enemy->getName() << "ha atacado al " << player->getName() << " con: "
                 << player->getTrueDamage() << endl;
        } while (player->getHealth() > 0 && enemy->getHealth() > 0);


    if (player->getHealth()>enemy->getHealth()){
        cout <<"Haz ganado el combate "<<player->getName()<<endl;
    }else {
        cout <<"Haz perdido el combate "<<enemy->getName()<<endl;
    }

    cout << player->toString() << endl;
    cout << enemy->toString() << endl;

    delete player;
    delete enemy;
    return 0;
}
