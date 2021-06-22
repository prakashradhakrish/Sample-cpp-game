//Author : Prakash Radhakrishnan

#ifndef INIT_ROBOTS__WITH_GRID_HPP
#define INIT_ROBOTS__WITH_GRID_HPP
#include "init_robots.hpp"

//Generating the game environment in the grid size of 14x22
void grid(int rows,int columns,char (&gr)[14][22],int (&robotAI_grid)[14][22],int human_grid[14][22],vector<Robot> &player_list)
{
    //Initialising the values on the grid(gaming environment)
    cout << "\n\n           Printing game console " << endl;
    for (int i = 0; i<rows; i++)
    {
        for (int j = 0; j<columns; j++)
        {
            gr[i][j] = '.' ;
            robotAI_grid[i][j]=0;
            human_grid[i][j]=0;
        }
    }

    //Assigning values to each grid based on player list as H and R
    for(int k=0;k<player_list.size();k++)
    {
        if (k==0)
        {
            gr[player_list[k].getX()][player_list[k].getY()] = 'H'; //assigning human robots as H
            human_grid[player_list[k].getX()][player_list[k].getY()] = 1;
        }
        else
        {
            gr[player_list[k].getX()][player_list[k].getY()] = 'R'; //assigning human robots as R
            robotAI_grid[player_list[k].getX()][player_list[k].getY()] = 1;
        }         
    }

    //Printing grid with status of each player
    for (int i = 0; i<rows; i++)
    {
        cout << "\n  ";
        for (int j = 0; j<columns; j++)
        {
            cout<<gr[i][j];
            cout<<" ";
        }
    }
}

#endif
