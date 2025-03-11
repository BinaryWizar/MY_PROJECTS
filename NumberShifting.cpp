#include<iostream>
#include<termios.h>
#include<unistd.h>
#include<cstdlib>
#include<time.h>
using namespace std;
class gboard{
    protected:
    int moves;
    int **board;
    int *temp_arr;
    bool check_unique_position(int num,int index){
        for(int i=0;i<index;i++){
            if(temp_arr[i]==num)
                return false;
        }
            return true;
     }
     char getch() {
        struct termios oldt, newt;
        char ch;
        
        tcgetattr(STDIN_FILENO, &oldt);  // Get current terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // Disable buffering & echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
        read(STDIN_FILENO, &ch, 1);  // Read a single character
    
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old settings
        return ch;
    }
    
    public:
    virtual void create_board()=0;  
    void game_rules() //gives games rules to end user's
        {
            char ch;
            printf("                      RULE FOR THIS GAME\n\n");
            printf("1.you can make only 1 step at a time by arrow key\n");
            printf("Move Up   :  by Up arrow key\n");
            printf("Move Down :  by Down arrow key\n");
            printf("Move Left :  by Left arrow key\n");
            printf("Move Right:  by Right arrow key\n\n");
            printf("2.Your can move number at empty position only\n");
            printf("3.For each valid move : Your total number move will decreased by 1\n");
            printf("Wining situation : Arrange number in such order like given below\n\n");
            printf("                  WINNING SITUATION:\n");
            printf("-----------------\n");
            printf("| 1 | 2 | 3 | 4 |\n");
            printf("| 5 | 6 | 7 | 8 |\n");
            printf("| 9 |10 |11 |12 |\n");
            printf("|13 |14 |15 |   |\n");
            printf("-----------------\n");
            printf("\n               Happy Gaming , Good Luck.\n");
            printf("     \nPress Enter key:::::  OK,");
            scanf("%c",&ch);

        }
};
class board2 :public gboard{
 private:

 void random_position_generator(){
    srand(time(0));
    for(int i=0;i<4;i++){
        int temp=(rand()%4)+1;
        if(check_unique_position(temp,i))
            temp_arr[i]=temp;
        else
            i--;
    }
 }
 
 public:
 board2(){
    board = new int*[2];
    temp_arr = new int[4];
    for(int i=0;i<2;i++){
        board[i]=new int[2];
    }
 }
 int* zerokhoj(){
    int* ptr = (int*) malloc(sizeof(int)*2);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(board[i][j]==4){
                ptr[0]=i;
                ptr[1]=j;
                return ptr;
            }
        }
    }
    return NULL;
 }
 void create_board(){
    random_position_generator();
    int index=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            board[i][j]=temp_arr[index];
            index++;
        }
    }
 }
 void display_board(){
    cout<<"PRESS Q FOR EXIT>>>>  \tREMAINING MOVES: "<<moves<<"\n";
    cout<<" ------------ "<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(board[i][j]==4)
            cout<<"|     ";
            else
            cout<<"|  "<<board[i][j]<<"  ";
        }
        cout<<"|\n";
    }
    cout<<" ------------ "<<endl;

 }
 void move_up(){
    if(board[0][0]==4||board[0][1]==4){}
    else{
        int*p;
        p = zerokhoj();
        int i = p[0];
        int j = p[1];
        cout<<"values are :"<<p[0]<<p[1]<<endl;
        board[i][j]= board[i-1][j];
        board[i-1][j]= 4;
        moves--;
    }
 }
 void move_down(){
    if(board[1][0]==4||board[1][1]==4){}
    else{
        int*p;
        p = zerokhoj();
        int i = p[0];
        int j = p[1];
       
        board[i][j]= board[i+1][j];
        board[i+1][j]= 4;
        moves--;
    }
 }
 void move_left(){
    if(board[1][0]==4||board[0][0]==4){}
    else{
        int*p;
        p = zerokhoj();
        int i = p[0];
        int j = p[1];
        board[i][j]= board[i][j-1];
        board[i][j-1]= 4;
        moves--;
    }
 }
 void move_right(){
    if(board[1][1]==4||board[0][1]==4){}
    else{
        int*p;
        p = zerokhoj();
        int i = p[0];
        int j = p[1];
        board[i][j]= board[i][j+1];
        board[i][j+1]= 4;
        moves--;
    }
 }
 bool win_condition(){
    if(board[0][0]==1&&board[0][1]==2&&board[1][0]==3&&board[1][1]==4){
        printf("YOU WON!----)))))");
        return true;
    }
    else 
    return false;
 }

void run_game(int m){
    game_rules();
    moves = m;
    create_board();
    char choices;
    while(true){
        display_board();
        choices = getch();
        if(choices=='\033'){
            choices  = getch();
           }
        else if(moves==0){
            cout<<"No moves left ((((( ";
            break;
        }
        else if(win_condition())
            break;
        
        switch (choices)
        {
        case 'A':
            move_up();
            break;
        case 'B':
            move_down();
            break;
        case 'C':
            move_right();
            break;
        case 'D':
             move_left();
            break;
        default:
            printf("\nYou have entered wrong key>>>>>Please try again later!____");
            break;
        }
        system("clear");
    }   
   
 }
};

class board3 :public gboard{
private:
 void random_position_generator(){
    srand(time(0));
    for(int i=0;i<9;i++){
        int temp=(rand()%9)+1;
        if(check_unique_position(temp,i))
            temp_arr[i]=temp;
        else
            i--;
    }
 }
 
 public:
board3(){
    board = new int*[3];
    temp_arr = new int[9];
    for(int i=0;i<3;i++){
        board[i]=new int[3];
    }
}
bool win_match(){
    int value=1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j]!=value)
            {
                return false;
            }
            value++;
        }
    }
    return true;
}
void create_board(){
    random_position_generator();
    int index=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=temp_arr[index];
            index++;
        }
    }
 }
 void display_board(){
    cout<<"PRESS Q FOR EXIT>>>>  \tREMAINING MOVES: "<<moves<<"\n";
    cout<<" ------------------ "<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]==9)
            cout<<"|     ";
            else
            cout<<"|  "<<board[i][j]<<"  ";
        }
        cout<<"|\n";
    }
    cout<<" ------------------ "<<endl;
}
int * nine_khojo(){
    int *arr=(int*)malloc(sizeof(int)*2);
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            if(board[i][j]==9){
                arr[0]=i;
                arr[1]=j;
                return arr;
            }   
        }
    }
    return NULL;
}
void move_up(){
    if(board[0][0]==9||board[0][1]==9||board[0][2]==9){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = nine_khojo();
        board[p[0]][p[1]] = board[p[0]-1][p[1]];
        board[p[0]-1][p[1]]=9;
        moves--;
    }
}
void move_down(){
    if(board[2][0]==9||board[2][1]==9||board[2][2]==9){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = nine_khojo();
        board[p[0]][p[1]] = board[p[0]+1][p[1]];
        board[p[0]+1][p[1]]=9;
        moves--;
    }
}
void move_left(){
    if(board[0][0]==9||board[1][0]==9||board[2][0]==9){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = nine_khojo();
        board[p[0]][p[1]] = board[p[0]][p[1]-1];
        board[p[0]][p[1]-1]=9;
        moves--;
    }
}
void move_right(){
    if(board[0][2]==9||board[1][2]==9||board[2][2]==9){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = nine_khojo();
        board[p[0]][p[1]] = board[p[0]][p[1]+1];
        board[p[0]][p[1]+1]=9;
        moves--;
    }
}

void run_game(int m){
    game_rules();
    moves = m;
    create_board();
    while(true){
        display_board();
        char choice = getch();
        if(choice=='q'){
         cout<<"Thank YOU for playing>>>>>>>EXIT"<<endl;
         getch();
         break;
        }
        else if (moves==0)
        {
            cout<<"All moves completed....No moves left"<<endl;
            break;
        }
        
        else if(win_match()){
            cout<<"YOu Won CONGRATS!!)))))"<<endl;
            getch();
            break;
        }
        else if(choice=='\033'){
            choice = getch();
        }
        switch (choice)
        {
        case 'A':
            move_up();
            break;
        case 'B':
            move_down();
            break;
        case 'C':
            move_right();
            break;
        case 'D':
            move_left();
            break;
    
        default:
            cout<<"Entered WRONG KEY......Please Try Again(((";
            break;
        }
        system("clear");
    }
}
};
class board4 :public gboard{
    private:
    void random_position_generator(){
       srand(time(0));
       for(int i=0;i<16;i++){
           int temp=(rand()%16)+1;
           if(check_unique_position(temp,i))
               temp_arr[i]=temp;
           else
               i--;
       }
    }
    
public:
board4(){
    board = new int*[4];
    temp_arr = new int[16];
    for(int i=0;i<4;i++){
        board[i]=new int[4];
    }
}
bool win_match(){
    int value=1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j]!=value)
            {
                return false;
            }
            value++;
        }
    }
    return true;
}
int * solah_khojo(){
    int *arr=(int*)malloc(sizeof(int)*2);
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            if(board[i][j]==16){
                arr[0]=i;
                arr[1]=j;
                return arr;
            }   
        }
    }
    return NULL;
}
void create_board(){
    random_position_generator();
    int index=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            board[i][j]=temp_arr[index];
            index++;
        }
    }
 }
 void move_up(){
    if(board[0][0]==16||board[0][1]==16||board[0][2]==16||board[0][3]==16){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = solah_khojo();
        board[p[0]][p[1]] = board[p[0]-1][p[1]];
        board[p[0]-1][p[1]]=16;
        moves--;
    }
}
void move_down(){
    if(board[3][0]==16||board[3][1]==16||board[3][2]==16||board[3][3]==16){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = solah_khojo();
        board[p[0]][p[1]] = board[p[0]+1][p[1]];
        board[p[0]+1][p[1]]=16;
        moves--;
    }
}
void move_left(){
    if(board[0][0]==16||board[1][0]==16||board[2][0]==16||board[3][0]==16){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = solah_khojo();
        board[p[0]][p[1]] = board[p[0]][p[1]-1];
        board[p[0]][p[1]-1]=16;
        moves--;
    }
}
void move_right(){
    if(board[0][3]==16||board[1][3]==16||board[2][3]==16||board[3][3]==16){
        cout<<"OOPS!!!....problem occur"<<endl;
        getch();
    }
    else{
        int * p;
        p = solah_khojo();
        board[p[0]][p[1]] = board[p[0]][p[1]+1];
        board[p[0]][p[1]+1]=16;
        moves--;
    }
}
 void display_board(){
    cout<<"  PRESS Q FOR EXIT>>>>  \t\tREMAINING MOVES: "<<moves<<"\n";
    cout<<" ------------------------ "<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==16)
                printf("|     ");
            else
               printf("| %3d ",board[i][j]);
        }
        cout<<" |\n";
    }
    cout<<" ------------------------ \n";
}
void run_game(int m){
    game_rules();
    moves = m;
    create_board();
    while(true){
        display_board();
        char choice = getch();
        if(choice=='q'){
         cout<<"Thank YOU for playing>>>>>>>EXIT"<<endl;
         getch();
         break;
        }
        else if (moves==0)
        {
            cout<<"All moves completed....No moves left"<<endl;
            break;
        }
        
        else if(win_match()){
            cout<<"YOu Won CONGRATS!!)))))"<<endl;
            getch();
            break;
        }
        else if(choice=='\033'){
            choice = getch();
        }
        switch (choice)
        {
        case 'A':
            move_up();
            break;
        case 'B':
            move_down();
            break;
        case 'C':
            move_right();
            break;
        case 'D':
            move_left();
            break;
    
        default:
            cout<<"Entered WRONG KEY......Please Try Again(((";
            break;
        }
        system("clear");
    }
}
};

int main(){
board4 obj;
obj.run_game(10000);
}