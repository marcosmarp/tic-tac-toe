#include <vector>
#include <string>
enum class Symbols {kNone, kCross, kCircle};
enum class Players {kPlayer1, kPlayer2};
enum class Lines {kHorizontal, kVertical, kDiagonal};

void WipeInput(); // Clears the input stream from errors and residual characters
bool SelectAGameMode(); // Askk the user to select between the two game modes
bool PrintGameModeMenuHighlighted(bool); // Prints the game mode selection menu highlighted in the specified item
void PrintMainBoard(const std::vector<Symbols>&); // Prints the main board of the game updated to the last move
void PrintAvailableCommands(const std::vector<Symbols>&); // Prints the possible commands for the player
void AskUserForCommand(std::vector<Symbols>&, const Players& current_player); // Ask the user for a command
bool IsCommandCorrect(const std::string, const std::vector<Symbols>&); // Verifies that the users command is correct in syntax and validity terms
bool CheckCommandSyntax(const std::string); // Verifies the users command syntax 
bool CheckCommandValidity(const std::string, const std::vector<Symbols>&); // Verifies the users command validity
void TranslateCommandIntoSymbol(const std::string, std::vector<Symbols>&, const Players& player); // Translates the users command string into a symbol
bool CheckIfGameOver(const std::vector<Symbols>&); // Checks if someone won or for a draw
bool CheckHorizontalCombinations(const std::vector<Symbols>&); // Checks if any of the horizontal ways of winning happened
bool CheckVerticalCombinations(const std::vector<Symbols>&); // Checks if any of the vertical ways of winning happened
bool CheckDiagonalCombinations(const std::vector<Symbols>&); // Checks if any of the diagonal ways of winning happened
bool CheckIfBoardFull(const std::vector<Symbols>&); // Checks if the board is full so the game is over
void ChangeCurrentPlayer(Players&); // Alternates between the two players
bool CheckForDraw(const std::vector<Symbols>&); // Checks if there's a draw
void ShowDraw(); // Shows a IT'S A DRAW message
void ShowWinner(const Players&); // Shows who the winner is
std::vector<int> CalculateBestScore(const std::vector<Symbols>&); // Calculates the score for each cuadrant in the board
std::string AICalculateBestMove(const std::vector<int>&); // Selects the best move based on the scores of each cuadrant