#include <vector>
#include <string>
enum class Symbols {kNone, kCross, kCircle};
enum class Players {kPlayer1, kPlayer2};

void WipeInput();
void PrintMainBoard(const std::vector<Symbols>&);
void PrintAvailableCommands(const std::vector<Symbols>&);
void AskUserForCommand(std::vector<Symbols>&, const Players& current_player);
bool IsCommandCorrect(const std::string, const std::vector<Symbols>&);
bool CheckCommandSyntax(const std::string);
bool CheckCommandValidity(const std::string, const std::vector<Symbols>&);
void TranslateCommandIntoSymbol(const std::string, std::vector<Symbols>&, const Players& player);
bool CheckIfGameOver(const std::vector<Symbols>&);
bool CheckHorizontalCombinations(const std::vector<Symbols>&);
bool CheckVerticalCombinations(const std::vector<Symbols>&);
bool CheckDiagonalCombinations(const std::vector<Symbols>&);
bool CheckIfBoardFull(const std::vector<Symbols>&);
void ChangeCurrentPlayer(Players&);
bool CheckForDraw(const std::vector<Symbols>&);
void ShowDraw();
void ShowWinner(const Players&);