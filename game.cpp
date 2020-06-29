#include "game_algorithm.hpp"

int main()
{

// Parameters initialisation
vector<Robot> player_list;
const int rows(14),columns(22);
int game_finished=0;
char gr[rows][columns];
int robotAI_grid[rows][columns];
int human_grid[rows][columns];

// Function to get input on initial position of robots
initializing_players(player_list);
print_playerstatus(player_list);

// Function to print grid based on initial condition
grid(rows, columns, gr, robotAI_grid, human_grid, player_list);

// Game loop runs based on defined condition
while(game_finished!=1)
{
    game_Statistics_robots(game_finished, rows, columns, gr, robotAI_grid, human_grid, player_list);
}

return 0;
}
