#include "battle.h"
#include <array>
#include <iostream>

#define BOARD_W 30
#define COORDS_TO_INDEX(x, y) (BOARD_W * y + x)
#define INDEX_TO_COORDS(index) ({index % BOARD_W, index / BOARD_W})

static std::array<enum BoardState, BOARD_W * BOARD_W> board;
static bool battle_active = false;

static void battleLoop();
static void renderBoard();
static void handleCmd();

struct Vector2 {
  int x;
  int y;
};

static struct Vector2 playerPos = {BOARD_W / 2, BOARD_W / 2 + 6};
static struct Vector2 enemyPos = {BOARD_W / 2, BOARD_W / 2 - 6};

void startBattle() {
  board.fill(BoardState::FREE_SPACE);
  playerPos = {BOARD_W / 2, BOARD_W / 2 + 6};
  enemyPos = {BOARD_W / 2, BOARD_W / 2 - 6};

  board[COORDS_TO_INDEX(playerPos.x, playerPos.y)] = BoardState::PLAYER_SPACE;
  board[COORDS_TO_INDEX(enemyPos.x, enemyPos.y)] = BoardState::ENEMY_SPACE;
  battle_active = true;
  battleLoop();
}

static void battleLoop() {
  while (battle_active) {
    renderBoard();
    handleCmd();
  }
}

static void renderBoard() {
  for (int i = 0; i < BOARD_W; i++) {
    for (int j = 0; j < BOARD_W; j++) {
      switch (board[COORDS_TO_INDEX(j, i)]) {
      case BoardState::FREE_SPACE:
        std::cout << ' ';
        break;
      case BoardState::PLAYER_SPACE:
        std::cout << 'P';
        break;
      case BoardState::ENEMY_SPACE:
        std::cout << 'E';
        break;
      }
    }
    std::cout << std::endl;
  }
}

static void handleCmd() {
  char cmd;
  std::cin >> cmd;

  switch (cmd) {
  case 'W':
  case 'w':
    board[COORDS_TO_INDEX(playerPos.x, playerPos.y)] = BoardState::FREE_SPACE;
    board[COORDS_TO_INDEX(playerPos.x, --playerPos.y)] =
        BoardState::PLAYER_SPACE;
    break;
  case 'D':
  case 'd':
    board[COORDS_TO_INDEX(playerPos.x, playerPos.y)] = BoardState::FREE_SPACE;
    board[COORDS_TO_INDEX(++playerPos.x, playerPos.y)] =
        BoardState::PLAYER_SPACE;
    break;
  case 'A':
  case 'a':
    board[COORDS_TO_INDEX(playerPos.x, playerPos.y)] = BoardState::FREE_SPACE;
    board[COORDS_TO_INDEX(--playerPos.x, playerPos.y)] =
        BoardState::PLAYER_SPACE;
    break;
  case 'S':
  case 's':
    board[COORDS_TO_INDEX(playerPos.x, playerPos.y)] = BoardState::FREE_SPACE;
    board[COORDS_TO_INDEX(playerPos.x, ++playerPos.y)] =
        BoardState::PLAYER_SPACE;
    break;
  default:
    break;
  }
}
