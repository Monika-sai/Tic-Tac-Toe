#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>


char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
char u1[50],u2[50],x,o;
void rules();
int checkWin();
void drawBoard();
bool decision(char *x, char *o, unsigned char *u1);
int main(){
    
    FILE *p;
    p=fopen("score.txt","a+");
    fclose(p);
     
	int player = 1, i ,choice;
	char mark; // X,O
	rules();
	char dec;
	int s;
	printf("\n\nType 1 to start the game:-\nType 2 to view leader board:-\n");
    scanf("%d",&s);
    switch(s) {
        case 1:
            do {
                p=fopen("score.txt", "a+");
                printf("\nEnter name of player1: ");
                scanf("%s",u1);
                fprintf(p,"\n%s\t\t\t",u1);
                printf("Enter name of player2: ");
                scanf("%s",u2);
                fprintf(p,"%s\t\t\t",u2);
                fclose(p);
                !strcmp(u1,u2) ? printf("Enter names of different players!\n\n") : false;
            } while(!strcmp(u1,u2));
            decision(&x, &o, u1);
	        do {
		    drawBoard();
		    player = (player % 2) ? 1 : 2;
		    if(player==1)
                    printf("%s Type any digit from 1-9 to fill your response:- ",u1);
            else
                    printf("%s Type any digit from 1-9 to fill your response:- ",u2);
            scanf("%d",&choice);
		    mark = (player == 1) ? x : o;
		    if(choice == 1 && square[1] == '1')
			square[1] = mark;
		    else if(choice == 2 && square[2] == '2')
			square[2] = mark;
			else if(choice == 3 && square[3] == '3')
			square[3] = mark;
			else if(choice == 4 && square[4] == '4')
			square[4] = mark;
			else if(choice == 5 && square[5] == '5')
			square[5] = mark;
			else if(choice == 6 && square[6] == '6')
			square[6] = mark;
			else if(choice == 7 && square[7] == '7')
			square[7] = mark;
			else if(choice == 8 && square[8] == '8')
			square[8] = mark;
			else if(choice == 9 && square[9] == '9')
			square[9] = mark;
			
			else {
				printf("Invalid option !");
				player--;
				getch();
			}
			i = checkWin();
			player++;	
		
	        }while(i == -1);
	        p=fopen("score.txt","a+");
	        drawBoard();
	        if(i==1){
		    if(player==2){
                    printf("\n\n*****Player1 %s Wins!*****\n\n",u1);
                    fprintf(p,"%s",u1);
                    getchar();
            }
            else {
                    printf("\n\n*****Player2 %s Wins!*****\n\n",u2);
                    fprintf(p,"%s",u2);
                    getchar();
            }
                fclose(p);
		
	        }
	    else {
		printf("*****Game draw*****");
		fprintf(p,"%s","DRAW");
	    }
		getch();
		return 0;
		break;
	    case 2:
            printf("\n\n");
            printf("\tLEADERBOARD\n\n");
            printf("PLAYER1\t\t\tPLAYER2\t\t\tWINNER");
            char c;
            
            p=fopen("score.txt","r");
            while((c=getc(p))!=EOF) {
                printf("%c",c);
            }
            fclose(p);
            getchar();
            break;
        default:
            printf("\n\nShould have typed 1 to play the game!\nHope to see you back soon!\n\n");
            getchar();
            break;
    }
}
int checkWin(){
	if(square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if(square[7] == square[8] && square[8] == square[9])
		return 1;
	else if(square[1] == square[4] && square[4] == square[7])
		return 1;
	else if(square[2] == square[5] && square[5] == square[8])
		return 1;
	else if(square[3] == square[6] && square[6] == square[9])
		return 1;
	else if(square[1] == square[5] && square[5] == square[9])
		return 1;
	else if(square[3] == square[5] && square[5] == square[7])
		return 1;
	else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] !='4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else 
		return -1;	
}

void rules(){
    printf("\t*****Tic Tac Toe*****\n\n");
	printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-\n");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
}
void drawBoard(){

	printf("\n\n\t Tic Tac Toe \n\n");
    printf("\n\n");
    printf("%s:- (%c)\n%s:-  (%c)\n\n\n",u1,x,u2,o);
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[1],square[2],square[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[4],square[5],square[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",square[7],square[8],square[9]);
	printf("     |     |     \n");	
	
}
bool decision(char *x, char *o, unsigned char *u1)
{
    char dec;
    printf("\n\n");
    do {
        printf("Player1 %s choose the X or 0:",u1);
        dec=getchar();
        scanf("%c", &dec);
    } while(dec!='X' && dec!='x' && dec!='0');
    if (dec=='X' || dec=='x') {
        *x='X';
        *o='0';
    }
    else {
        *x='0';
        *o='X';
    }
    return 1;
}
