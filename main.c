
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define MAX_SIZE 100
typedef struct {
    char player1_name[MAX_SIZE];
    char player2_name[MAX_SIZE];
    int  player1_score;
    int  player2_score;

}player_inf;



void assign_arr( int row,int col,int game[row][col]){
//nis number of sides 2 or 5
int i,j;
for(i=0;i<row;i++){
    for(j=0;j<col;j++){
        game[i][j]=32;
    }
}
for(i=0;i<row;i+=4){
    for(j=0;j<col;j+=4){
        game[i][j]=111;
    }
}

}
void print_arr( int row,int col,int game[row][col]){
    int ronu=1,conu=1,k=0;
    /*ronu numbers print on row
    conu number print on col*/
    printf("   ");
    for(int i=0;i<col;i+=2){
            if(ronu>=10){
                printf("%d      ",ronu);
            } else{
        printf("%d       ",ronu);
        }  ronu++; }

    printf("\n\n");
    for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){ if(i==k){
            k+=2;if(conu>=10){printf("%d ",conu);}

        else {printf("%d  ",conu);}
        conu++;
    }else{printf("   ");}
        printf("%c",game[i][j]);
    }printf("\n");
}

    }
    void print_enter_face(){
  HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
 SetConsoleTextAttribute(hConSole,FOREGROUND_RED);
        printf("\n\n\n\n\n\n\n");
       printf("\t\t\t\t *          * *       **********      * *     * *        *                 *     *\n");
       printf("\t\t\t\t *  *      *     *        **         *       *   *       *                  *   *                  **\n");
       printf("\t\t\t\t *   *    *       *       **         *        * *        *         * *       * *       * *        *\n");
       printf("\t\t\t\t *    *   *       *       **           *      * *   *    **      *    *       *      *    *        *\n");
       printf("\t\t\t\t *    *   *       *       **           *    *    * *     *  *    *    *      * *     * * *          *\n");
       printf("\t\t\t\t *   *     *     *        **          *     *     *      *  *    *    *     *   *     *            *\n");
       printf("\t\t\t\t * *         * *          **       * *       *  *   *    ***      * *      *     *      * *      **\n");

        SetConsoleTextAttribute(hConSole,saved_attributes);
         SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
   printf("\t\t\t\t");
  for(int i=0;i<101;i++){
    printf("%c",196);
  }

SetConsoleTextAttribute(hConSole,saved_attributes);



       }
void check_occurance(int col,int *row_index,int *col_index,int game[][col]){
        int x,y;
        /*x indicate row of the arr y indicate col of the arr*/
        y=(*col_index-1)*2;
        x=(*row_index-1)*2;

        while(game[x][y]==111||game[x][y]==196||game[x][y]==124||(*col_index%2==0&&*row_index%2==0)){
            printf("\t\tInvalid\n");
             printf("Enter Row:");
        scanf("%d",&*row_index);
        printf("Enter Column:");
        scanf("%d",&*col_index);
        printf("\n");
        y=(*col_index-1)*2;
        x=(*row_index-1)*2;

     }
}
void place_line(int col ,int row_index,int col_index,int game[][col] ){
    int x,y;
        /*x indicate row of the arr y indicate col of the arr*/
        y=(col_index-1)*2;
        x=(row_index-1)*2;

if(row_index%2==0){   x-=1;
for(int i=0;i<3;i++,x++){
    game[x][y]=124;
}
}
  else{
    y-=1;
    for(int i=0;i<3;i++,y++){
        game[x][y]=196;
    }
  }



}
int check_box(int col,int n,int turn,int game[][col]){

   int i,j,score=0;
   for(i=2;i<col;i+=4){
    for(j=2;j<col;j+=4){
    if(game[i][j+2]!=32&&game[i][j-2]!=32&&game[i+2][j]!=32&&game[i-2][j]!=32&&game[i][j]==32)  {
        score++;
        if(turn==0){
            game[i][j]=65;
        }
        else{game[i][j]=66;}

}
}
}

return score ;
}



int start()
{  int n;
    print_enter_face();
    printf("\n\n\n");
    system("pause");
    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t\t\t\t\t\t*******Main Menu*******\n");
    printf("\t\t\t\t\t\t\t\t\t1-Start game\n\t\t\t\t\t\t\t\t\t2-Load game\n\t\t\t\t\t\t\t\t\t3-Show the Top 10\n\t\t\t\t\t\t\t\t\t4-Exit\n");
    int operation;
    scanf("%d",&operation);
    //we will remember to test if user press wrong input
    system("cls");
    switch (operation)
    {
    case 1:
    printf("\t\t\t\t\t\t\t\t\tChoose Difficulty:\n");
    printf("\t\t\t\t\t\t\t\t\t1-Beginner\n\t\t\t\t\t\t\t\t\t2-Expert\n");
    /*computer vs human or human vs human */
    int difficulty;
    scanf("%d",&difficulty);
    system("cls");
    if(difficulty==1)
    {
        n=2;
    }
    else if(difficulty==2)
    {
        n=5;
    }
    else {}


        break;
    case 2:
        break;

    case 3:
        break;

    case 4:
        break;
    default:
        break;

    }
      return n ;


}
void player_print(player_inf vs){
    HANDLE hConSole=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hConSole,&consoleInfo);
    WORD saved_attributes =consoleInfo.wAttributes;
    printf("\n\n\n\t\tPlayer's Names");
 SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
    printf("\t%s\t",vs.player1_name);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%s\n\n",vs.player2_name);
    SetConsoleTextAttribute(hConSole,saved_attributes);
     printf("\t\tPlayer's Score");
    SetConsoleTextAttribute(hConSole,FOREGROUND_BLUE);
   printf("\t%d\t",vs.player1_score);
    SetConsoleTextAttribute(hConSole,saved_attributes);
    SetConsoleTextAttribute(hConSole,FOREGROUND_GREEN);
    printf("%d\n\n",vs.player2_score);
    SetConsoleTextAttribute(hConSole,saved_attributes);

}

void turn(int n,int row,int col,int game[][col])
{

      player_inf h_vs_h;
    int end_loop=n*(n+1)*2;
    int row_index,col_index;
    int k,turn;
    print_arr(row,col,game);
    printf("\n\n\n");

    printf("Enter Player First Name  : ");

    scanf("%s",h_vs_h.player1_name);
    printf("\nEnter Player Second Name : ");
     scanf("%s",h_vs_h.player2_name);

     h_vs_h.player1_score=0;
     h_vs_h.player2_score=0;
    for(k=0; k<end_loop; k++)
    {
        if((k%2)==0)
        {    turn=0;
            printf("\t\t%c %s Turn %c\n",186,h_vs_h.player1_name,186);

     /*chech succes i++*/
        }
        else if((k%2)==1)
        {   turn=1;

            printf("\t\t%c %s Turn %c\n",186,h_vs_h.player2_name,186);
        }
        //fuction to check and to print line
        printf("\t\tEnter Row:");
        scanf("%d",&row_index);
        printf("\t\tEnter Column:");
        scanf("%d",&col_index);
        printf("\n");
     check_occurance(col,&row_index,&col_index ,game);
     check_box(col,n,turn,game);
     place_line(col,row_index,col_index,game);
        system("cls");
        int check;
        check=check_box(col,n,turn,game);
     if(check!=0){
        if(turn==0){
            h_vs_h.player1_score+=check;
        }
        else{ h_vs_h.player2_score+=check;}
        k++,end_loop++;
     }
        print_arr(row,col,game);
       player_print(h_vs_h);
        printf("\n\n");
    }

}


int main()
{ int col,row,n;


    n=start();

system("cls");
col=n+n*3+1,row=n+n*3+1;
int game[row][col];
/* 5 as i have 5 - bet two horizontal points
3 as i have 3 | bet two vertical points*/
assign_arr(row,col,game);
turn(n,row,col,game);



    return 0;
}
