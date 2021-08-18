#include "main.h"
#include <iostream>
#include <windows.h>
#include <limits>
#include <conio.h>

#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ENTER_KEY 13

int main(void) {
  std::string ai_command;
  std::vector<Symbols> board(9, Symbols::kNone);
  bool game_over = false, game_mode;
  auto current_player = Players::kPlayer1;
  game_mode = SelectAGameMode();
  while (game_over == false) {
    PrintMainBoard(board);
    PrintAvailableCommands(board);
    if(game_mode == true) {
      if(current_player == Players::kPlayer1) AskUserForCommand(board, current_player);
      else {
        ai_command = AICalculateBestMove(CalculateBestScore(board));
        TranslateCommandIntoSymbol(ai_command, board, current_player);
        std::cout << ai_command;
      }
    } else AskUserForCommand(board, current_player);
    game_over = CheckIfGameOver(board);
    ChangeCurrentPlayer(current_player);
  }
  PrintMainBoard(board);
  ChangeCurrentPlayer(current_player);
  std::cout << std::endl << "GAME OVER! " << std::endl;
  if(!CheckForDraw(board)) ShowWinner(current_player);
  else ShowDraw();
  system("pause");
  return 0;
}

void WipeInput() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return;
}

bool SelectAGameMode() {
  bool game_mode, last_item;
  last_item = PrintGameModeMenuHighlighted(0);
  while(_getch() != ENTER_KEY) {
    switch(_getch()) {
      case ARROW_DOWN: 
        switch(last_item) {
          case 0: 
            last_item = PrintGameModeMenuHighlighted(1);
            break;
          case 1:
            last_item = PrintGameModeMenuHighlighted(0);
            break;
        }
        break;
      case ARROW_UP: 
        switch(last_item) {
          case 0: 
            last_item = PrintGameModeMenuHighlighted(1);
            break;
          case 1:
            last_item = PrintGameModeMenuHighlighted(0);
            break;
        }
        break;
    }
  }
  return last_item;
}

bool PrintGameModeMenuHighlighted(bool option) {
  system("CLS");
  switch(option) {
    case 0:
      std::cout << "[Player VS Player]" << std::endl << std::endl;
      std::cout << "Player VS Enviroment" << std::endl << std::endl;
      return 0;
    case 1:
      std::cout << "Player vs Player" << std::endl << std::endl;
      std::cout << "[Player VS Enviroment]" << std::endl << std::endl;
      return 1;
  }
}

void PrintMainBoard(const std::vector<Symbols>& board_positions) {
  system("CLS");
  std::cout << "TIC TAC TOE" << std::endl << std::endl;
  switch(board_positions[0]) {
    case Symbols::kNone:
      std::cout << "   | ";
      break;
    case Symbols::kCircle:
      std::cout << " O | ";
      break;
    case Symbols::kCross:
      std::cout << " X | ";
      break;
  }
  switch(board_positions[1]) {
    case Symbols::kNone:
      std::cout << "  | ";
      break;
    case Symbols::kCircle:
      std::cout << "O | ";
      break;
    case Symbols::kCross:
      std::cout << "X | ";
      break;
  }
  switch(board_positions[2]) {
    case Symbols::kNone:
      std::cout << " " << std::endl;
      break;
    case Symbols::kCircle:
      std::cout << "O" << std::endl;
      break;
    case Symbols::kCross:
      std::cout << "X" << std::endl;
      break;
  }
  std::cout << "-----------" << std::endl;
  switch(board_positions[3]) {
    case Symbols::kNone:
      std::cout << "   | ";
      break;
    case Symbols::kCircle:
      std::cout << " O | ";
      break;
    case Symbols::kCross:
      std::cout << " X | ";
      break;
  }
  switch(board_positions[4]) {
    case Symbols::kNone:
      std::cout << "  | ";
      break;
    case Symbols::kCircle:
      std::cout << "O | ";
      break;
    case Symbols::kCross:
      std::cout << "X | ";
      break;
  }
  switch(board_positions[5]) {
    case Symbols::kNone:
      std::cout << " " << std::endl;
      break;
    case Symbols::kCircle:
      std::cout << "O" << std::endl;
      break;
    case Symbols::kCross:
      std::cout << "X" << std::endl;
      break;
  }
  std::cout << "-----------" << std::endl;
  switch(board_positions[6]) {
    case Symbols::kNone:
      std::cout << "   | ";
      break;
    case Symbols::kCircle:
      std::cout << " O | ";
      break;
    case Symbols::kCross:
      std::cout << " X | ";
      break;
  }
  switch(board_positions[7]) {
    case Symbols::kNone:
      std::cout << "  | ";
      break;
    case Symbols::kCircle:
      std::cout << "O | ";
      break;
    case Symbols::kCross:
      std::cout << "X | ";
      break;
  }
  switch(board_positions[8]) {
    case Symbols::kNone:
      std::cout << " " << std::endl;
      break;
    case Symbols::kCircle:
      std::cout << "O" << std::endl;
      break;
    case Symbols::kCross:
      std::cout << "X" << std::endl;
      break;
  }
  return;
}

void PrintAvailableCommands(const std::vector<Symbols>& board_positions) {
  std::cout << std::endl << "AVAILABLE POSITIONS: " << std::endl << std::endl;
  for (int i = 0 ; i < board_positions.size() ; ++i) {
    if (board_positions[i] == Symbols::kNone) {
      switch (i) {
        case 0: 
          std::cout << "Top left [tl]" << std::endl;
          break;
        case 1:
          std::cout << "Top [t]" << std::endl;
          break;
        case 2:
          std::cout << "Top right [tr]" << std::endl;
          break;
        case 3:
          std::cout << "Left [l]" << std::endl;
          break;
        case 4:
          std::cout << "Center [c]" << std::endl;
          break;
        case 5:
          std::cout << "Right [r]" << std::endl;
          break;
        case 6:
          std::cout << "Bottom left [bl]" << std::endl;
          break;
        case 7:
          std::cout << "Bottom [b]" << std::endl;
          break;
        case 8:
          std::cout << "Bottom right [br]" << std::endl;      
      }
    }
  }
  return;
}

void AskUserForCommand(std::vector<Symbols>& board, const Players& player) {
  switch(player) {
    case Players::kPlayer1:
      std::cout << std::endl <<  "Player 1, ";
      break;
    case Players::kPlayer2:
      std::cout << std::endl <<  "Player 2, ";
      break;
  }
  std::cout <<"enter a command: ";
  std::string command_temp;
  std::cin >> command_temp;
  std::cout << std::endl;
  while(!IsCommandCorrect(command_temp, board)) {
    WipeInput();
    std::cout << "Invalid command. Try again: ";
    std::cin >> command_temp;
    std::cout << std::endl;
  }
  TranslateCommandIntoSymbol(command_temp, board, player);
  return;
}

bool IsCommandCorrect(const std::string command, const std::vector<Symbols>& board) {
  if (!CheckCommandSyntax(command)) return false;
  if (!CheckCommandValidity(command, board)) return false;
  return true;
}

bool CheckCommandSyntax(const std::string command) {
  if (command != "tl" && command != "t" && command != "tr" && command != "l"
      && command != "c" && command != "r" && command != "bl" && command != "b"
      && command != "br") return false;
  return true;
}

bool CheckCommandValidity(const std::string command, const std::vector<Symbols>& board) {
  if (command == "tl" && board[0] != Symbols::kNone) return false;
  if (command == "t" && board[1] != Symbols::kNone) return false;
  if (command == "tr" && board[2] != Symbols::kNone) return false;
  if (command == "l" && board[3] != Symbols::kNone) return false;
  if (command == "c" && board[4] != Symbols::kNone) return false;
  if (command == "r" && board[5] != Symbols::kNone) return false;
  if (command == "bl" && board[6] != Symbols::kNone) return false;
  if (command == "b" && board[7] != Symbols::kNone) return false;
  if (command == "br" && board[8] != Symbols::kNone) return false;
  return true;
}

void TranslateCommandIntoSymbol(const std::string command, std::vector<Symbols>& board, const Players& player) {
  if (command == "tl") {
    switch(player) {
      case Players::kPlayer1: 
        board[0] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[0] = Symbols::kCircle;
        break;
    }
  }
  if (command == "t") {
    switch(player) {
      case Players::kPlayer1: 
        board[1] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[1] = Symbols::kCircle;
        break;
    }
  }
  if (command == "tr") {
    switch(player) {
      case Players::kPlayer1: 
        board[2] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[2] = Symbols::kCircle;
        break;
    }
  }
  if (command == "l") {
    switch(player) {
      case Players::kPlayer1: 
        board[3] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[3] = Symbols::kCircle;
        break;
    }
  }
  if (command == "c") {
    switch(player) {
      case Players::kPlayer1: 
        board[4] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[4] = Symbols::kCircle;
        break;
    }
  }
  if (command == "r") {
    switch(player) {
      case Players::kPlayer1: 
        board[5] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[5] = Symbols::kCircle;
        break;
    }
  }
  if (command == "bl") {
    switch(player) {
      case Players::kPlayer1: 
        board[6] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[6] = Symbols::kCircle;
        break;
    }
  }
  if (command == "b") {
    switch(player) {
      case Players::kPlayer1: 
        board[7] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[7] = Symbols::kCircle;
        break;
    }
  }
  if (command == "br") {
    switch(player) {
      case Players::kPlayer1: 
        board[8] = Symbols::kCross;
        break;
      case Players::kPlayer2:
        board[8] = Symbols::kCircle;
        break;
    }
  }
  return;
}

bool CheckIfGameOver(const std::vector<Symbols>& board) {
  if(CheckHorizontalCombinations(board)) return true;
  else if (CheckVerticalCombinations(board)) return true;
  else if (CheckDiagonalCombinations(board)) return true;
  else if(CheckIfBoardFull(board)) return true;
  else return false;
}

bool CheckHorizontalCombinations(const std::vector<Symbols>& board) {
  if (board[0] == board[1] && board[1] == board[2] && board[0] != Symbols::kNone) return true;
  else if (board[3] == board[4] && board[4] == board[5] && board[3] != Symbols::kNone) return true;
  else if (board[6] == board[7] && board[7] == board[8] && board[6] != Symbols::kNone) return true;
  return false;
}

bool CheckVerticalCombinations(const std::vector<Symbols>& board) {
  if (board[0] == board[3] && board[3] == board[6] && board[0] != Symbols::kNone) return true;
  else if (board[1] == board[4] && board[4] == board[7] && board[1] != Symbols::kNone) return true;
  else if (board[2] == board[5] && board[5] == board[8] && board[2] != Symbols::kNone) return true;
  return false;
}

bool CheckDiagonalCombinations(const std::vector<Symbols>& board) {
  if (board[0] == board[4] && board[4] == board[8] && board[0] != Symbols::kNone) return true;
  else if (board[2] == board[4] && board[4] == board[6] && board[2] != Symbols::kNone) return true;
  return false;
}

bool CheckIfBoardFull(const std::vector<Symbols>& board) {
  if (board[0] != Symbols::kNone && board[1] != Symbols::kNone &&
      board[2] != Symbols::kNone && board[3] != Symbols::kNone && 
      board[4] != Symbols::kNone && board[5] != Symbols::kNone &&
      board[6] != Symbols::kNone && board[7] != Symbols::kNone &&
      board[8] != Symbols::kNone) return true;
  else return false;
}

void ChangeCurrentPlayer(Players& player) {
  switch(player) {
    case Players::kPlayer1:
      player = Players::kPlayer2;
      break;
    case Players::kPlayer2:
      player = Players::kPlayer1;
      break;
  }
  return;
}

bool CheckForDraw(const std::vector<Symbols>& board) {
  if(!(CheckHorizontalCombinations(board) || CheckVerticalCombinations(board) || 
    CheckVerticalCombinations(board)) && CheckIfBoardFull(board)) return true;
  else return false;
}

void ShowDraw() {
  std::cout << "It's a draw!" << std::endl << std::endl;
  return;
}

void ShowWinner(const Players& winner) {
  switch (winner) {
    case Players::kPlayer1: 
      std::cout << "Winner is player 1" << std::endl << std::endl;
      break;
    case Players::kPlayer2:
      std::cout << "Winner is player 2" << std::endl << std::endl;
      break;
  }
  return;
}

std::vector<int> CalculateBestScore(const std::vector<Symbols>& board) {
  std::vector<int> position_score(9, 0);
  auto simulation_board = board;
  for(int i = 0 ; i < 9 ; ++i) {
    if (simulation_board[i] == Symbols::kNone) {
      simulation_board[i] = Symbols::kCircle;
      if (CheckIfGameOver(simulation_board)) {
        if (!CheckForDraw(simulation_board)) ++position_score[i];
      }
      simulation_board[i] = Symbols::kCross;
      if (CheckIfGameOver(simulation_board)) {
        if (!CheckForDraw(simulation_board)) ++position_score[i];
      }
    } else --position_score[i];
    simulation_board = board;
  }
  return position_score;
}

std::string AICalculateBestMove(const std::vector<int>& position_score) {
  int i;
  for (i = 0 ; i < 9 ; ++i) {
    if (position_score[i] == 1) break;
  }
  if (i == 9) {
    for(i = 0 ; i < 9 ; ++i) {
      if (position_score[i] == 0) break;
    }
  }
  switch(i) {
    case 0: return "tl";
    case 1: return "t";
    case 2: return "tr";
    case 3: return "l";
    case 4: return "c";
    case 5: return "r";
    case 6: return "bl";
    case 7: return "b";
    case 8: return "br";
  }
}