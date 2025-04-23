#ifndef INCLUDE_BATTLE_H
#define INCLUDE_BATTLE_H

#include <cstdint>
enum BoardState : uint8_t {
  FREE_SPACE,
  PLAYER_SPACE,
  ENEMY_SPACE,
};

void startBattle(void);

#endif
