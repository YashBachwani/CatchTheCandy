#include<stdio.h>
#include<conio.h>
void main(){
	int i,diff;
	char key;
	int life=3;
	int score=0;
	int level=1;
	int xcord;
	int ycord=3;
	int boxXcord = 50;
	int boxYcord= 24;
	xcord = rand()%100;
	start:
	clrscr();
	gotoxy(32,1);
	printf("Score: %d",score);
	gotoxy(50,1);
	printf("\t Level: %d",level);
	gotoxy(32,2);
	printf("Lifes: %d",life);
	//box cords
	gotoxy(boxXcord,boxYcord);
	printf("*");
	gotoxy(boxXcord+6,boxYcord);
	printf("*");
	gotoxy(boxXcord,boxYcord+1);
	printf("*******");
	//box movement
	if(kbhit()){
		key=getch();
		if(key == 'a' || key == 'A')
			boxXcord--;
		if(key == 'd' || key == 'D')
			boxXcord++;
	}
	if(ycord == 25){
		diff = xcord - boxXcord;
		if(diff >=0 && diff<=6){
			score++;
		}
		else{
			life--;
		}
		xcord = rand()%60;
		ycord=3;
	}
	if(life==0){
		clrscr();
		printf("\nGame over");
		printf("\n Score: %d",score);
		printf("\n Life: %d",life);
		delay(2000);
		exit(0);
	}
	//candy cords
	gotoxy(xcord,ycord);
	printf("0");
	delay(200);
	ycord++;
	goto start;
	getch();
}