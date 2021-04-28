import random
N = 5
M = 8
grid = [['*']*M for _ in range(N)]
score = 0
elements = ['0','1','2','3','4','5','6','7','8']
def print_grid():
    print('--' + '---' * (M+7) + '--')
    for i in range(N):
        for j in range(M):
            print(end='|  ')
            print(grid[i][j], end='  ')
        print(end='|')
        print()
        print('--' + '---' * (M+7) + '--')
    print("YOUR SCORE IS: ", score)
def clear_grid():
    global score
    for i in range(N):
        for j in range(M):
            grid[i][j] = '*'
    score = 0
def set_elements(i, j):
    global score
    x = random.randint(0,8)
    grid[i][j] = elements[x]
    if(elements[x] != '0'):
        score += int(elements[x])
def check_win():
    counter = 0
    for i in range(N):
        for j in range(M):
            if grid[i][j] == '*':
                counter += 1
    if counter == 1:
        return True
    return False
def check_fail(i, j):
    if grid[i][j] == '0':
        return True
    return False
def valid_position(i, j):
    if i >= 0 and i < N and j >= 0 and j < M :
        return True
    return False
def valid_element(i, j):
    if grid[i][j] == '*':
        return True
    return False
def read_input(i, j):
    i, j= map(int, input("Enter the two points of the cards: ").split())
    while (not valid_position(i, j) or not valid_element(i,j)):
      i, j= map(int, input("Enter valid two points of the cards: ").split())
    return i,j
def play_game():
    print("Bad-apple Game...")
    while True:
            print_grid()
            i,j = 0,0
            i,j = read_input(i,j)
            set_elements(i,j)
            if check_win():
                print_grid()
                print("YOU win :)")
                break
            elif check_fail(i,j):
                print_grid()
                print("YOU LOSE :(")
                break
while True:
    clear_grid()
    play_game()
    print("Play Again [Y/N] ")
    c = input()
    if not c == 'y' and not c == 'Y':
       break
