//Author : Prakash Radhakrishnan

#ifndef GAME_STATIC_ROBOTS_HPP
#define GAME_STATIC_ROBOTS_HPP
#include "init_robots_with_grid.hpp"
#include <cstdlib>
#include<cmath>

// Check the status of the game as win or lose based on the human robot and AI robot position
void game_status(int &game_finished,int rows,int columns,int (&robotAI_grid)[14][22],int human_grid[14][22],vector<Robot> &player_list)
{
    // Checking the winning condition
    if(player_list[0].getX()==0 || player_list[0].getX()==13 || player_list[0].getY()==0 || player_list[0].getY()==21)
    {
        cout<<"\nGame status:"<<endl;
        cout<<"win"<<endl;
        game_finished =1;
    }
    else // Checking the losing condition
    {
        for (int i = 0; i<rows; i++)
            {
                for (int j = 0; j<columns; j++)
                {
                    if(robotAI_grid[i][j]==1 && human_grid[i][j]==1)
                    {
                        cout<<"\nGame over"<<endl;
                        cout<<"lose"<<endl;
                        game_finished =1;
                    }                    
                }
            }
    }  

}


#endif
