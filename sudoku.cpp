#include <iostream>
#include <fstream>	

using namespace std;

bool check(int[9][9], int, int, int);
void explore(int[9][9], int , int);
void fprintGrid(int[9][9]);

int emptySize = 81;

int count = 0;

int main()
{
	int grid[9][9];

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> grid[i][j];
		}
	}

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(grid[i][j] != 0)
			{
				emptySize--;
			}
		}
	}
	explore(grid, 0, 0);
}	

bool check(int grid[9][9], int i, int j, int val)
{
	for(int k = 0; k < 9; k++)
	{
		if(grid[k][j] == val)
		{
			return false;
		}
		if(grid[i][k] == val)
		{
			return false;
		}
	}
	for(int k = 0; k < 9; k++)
	{
		for(int l = 0; l < 9; l++)
		{
			if((k/3 == i/3) && (l/3 == j/3))
			{
				if(grid[k][l] == val)
				{
					return false;
				}
			}
		}
	}
	return true;
}

void explore(int grid[9][9], int row, int col)
{
	if(row < 9)
	{
		for(int j = col; j < 9; j++)
		{
			if(grid[row][j] == 0)
			{
				int flag = 1;
				for(int temp = 1; temp <= 9; temp++)
				{
					if(check(grid,row,j,temp) == true)
					{
						//cout << "Checking " << temp << " at (" << row << ", " << j << ")" << endl;
						count++;
						grid[row][j] = temp;
						if(count == emptySize)
						{
							fprintGrid(grid);
							flag = 0;
						}
						explore(grid, row, j + 1);
						count--;
						grid[row][j] = 0;
					}
				}
				if(flag == 1)
				{
					return;
				}
			}
		}
	}
	for(int i = row + 1; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			if(grid[i][j] == 0)
			{
				int flag = 1;
				for(int temp = 1; temp <= 9; temp++)
				{
					if(check(grid,i,j,temp) == true)
					{
						//cout << "Checking " << temp << " at (" << i << ", " << j << ")" << endl;
						count++;
						grid[i][j] = temp;
						if(count == emptySize)
						{
							fprintGrid(grid);
							flag = 0;
						}
						explore(grid, i, j + 1);
						count--;
						grid[i][j] = 0;
					}
				}
				if(flag == 1)
				{
					return;
				}
			}
		}
	}
}
 
void fprintGrid(int grid[9][9])
{
	ofstream file;
	file.open("solution.txt", ios::trunc);
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			file << grid[i][j] << " ";
		}
		file << endl;
	}
	file.close();
}