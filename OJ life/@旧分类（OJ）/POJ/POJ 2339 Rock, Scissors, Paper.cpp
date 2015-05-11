#include <iostream>
#include <string>
using namespace std;

char grid[110][110];
char tmp[110][110];

int main()
{
    int tc, r, c, n, i, j;
    cin >> tc;
    while (tc--)
    {
          cin >> r >> c >> n;
          for (i = 1; i <= r; i++)
            for (j = 1; j <= c; j++){
                cin >> grid[i][j];
                tmp[i][j] = grid[i][j];
            }
          
          while (n--){
                for (i = 1; i <= r; i++)
                {
                   for (j = 1; j<= c; j++)
                   {
                       if (grid[i][j] == 'R')
                       {
                           if (i-1 > 0 && grid[i-1][j] == 'S')
                               tmp[i-1][j] = 'R';
                           if (j-1 > 0 && grid[i][j-1] == 'S')
                               tmp[i][j-1] = 'R';
                           if (i+1 <= r && grid[i+1][j] == 'S')
                               tmp[i+1][j] = 'R';
                           if (j+1 <= c && grid[i][j+1] == 'S')
                               tmp[i][j+1] = 'R';
                       }
                       else if (grid[i][j] == 'S')
                       {
                            if (i-1 > 0 && grid[i-1][j] == 'P')
                               tmp[i-1][j] = 'S';
                            if (j-1 > 0 && grid[i][j-1] == 'P')
                               tmp[i][j-1] = 'S';
                            if (i+1 <= r && grid[i+1][j] == 'P')
                               tmp[i+1][j] = 'S';
                            if (j+1 <= c && grid[i][j+1] == 'P')
                               tmp[i][j+1] = 'S';
                       }
                       else if (grid[i][j] == 'P')
                       {
                            if (i-1 > 0 && grid[i-1][j] == 'R')
                               tmp[i-1][j] = 'P';
                            if (j-1 > 0 && grid[i][j-1] == 'R')
                               tmp[i][j-1] = 'P';
                            if (i+1 <= r && grid[i+1][j] == 'R')
                               tmp[i+1][j] = 'P';
                            if (j+1 <= c && grid[i][j+1] == 'R')
                               tmp[i][j+1] = 'P';
                       }
                   }
                }
                   for (i = 1; i <= r; i++)
                      for (j = 1; j <= c; j++)
                          grid[i][j] = tmp[i][j];
          }
          
          for (i = 1; i <= r; i++)
          {
             for (j = 1; j <= c; j++)
                 cout << grid[i][j];
             cout << endl;
          }
          if (tc != 0)
             cout << endl;
    }
    return 0;
}
