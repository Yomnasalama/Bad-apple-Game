#include <bits/stdc++.h>
using namespace std;
const int N = 5;
const int M = 8;
char grid[N][M];
int score = 0;
char elements[] = {'0','1','2','3','4','5','6','7','8'};
void print_grid()
{
    bool flag = false;
    cout << "------";
    for (int i = 0; i < M+5; cout << "---", i++);
    cout << "----\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            cout << "|  ";
            cout << grid[i][j] << "  ";
        }
        cout << "|\n";
        cout << "----";
        for (int i = 0; i < M+5; cout << "---", i++);
        cout << "------\n";
    }
    cout << "YOUR SCORE IS: " << score << endl;
}
void clear_grid()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            grid[i][j] = '*';
        }
    }
    score = 0;
}
void set_elements(int i, int j)
{
    int x = 0;
    srand(time(0));
    x = (rand() % 8);
    grid[i][j] = elements[x];
    if(elements[x] != '0')
        score += elements[x] - '0';
}
bool check_win()
{
    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(grid[i][j] =='*')
                counter += 1;
        }
    }
    if(counter == 1)
        return true;
    return false;
}
bool check_fail(int i, int j)
{
    if(grid[i][j] == '0')
        return true;
    return false;
}
bool valid_position(int i, int j)
{
    if((i >= 0 && i < N) && (j >= 0 && j < M ))
        return true;
    return false;
}
bool valid_element(int i, int j)
{
    if(grid[i][j] == '*')
        return true;
    return false;
}
int read_input(int &i, int &j)
{   cout << "Enter the two points of the cards: ";
    cin >> i >> j;
    while (!valid_position(i, j) || !valid_element(i,j)) {
		cout << "Enter a valid two points of the cards: ";
		cin >> i >> j;
	}
}
void play_game()
{
    while(true)
    {
            cout<<"Bad-apple Game..."<<endl;
            print_grid();
            int i,j;
            read_input(i,j);
            set_elements(i,j);
            if(check_win())
            {
                print_grid();
                cout << "YOU WIN :)" << endl;
                break;
            }
            else if(check_fail(i,j))
            {
                print_grid();
                cout << "YOU LOSE :(" << endl;
                break;
            }
    }
}
int main() {
    while (true) {
    	clear_grid();
    	play_game();
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
}    }
