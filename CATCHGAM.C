#include<conio.h>
#include<stdio.h>
	int score=0;
	int life=3;
	int level=1;
	char key;
	int diff,i;
	int xcord=40;
	int ycord=3;
	int boxXcord=50;
	int boxYcord=24;
void boxcords(){
	gotoxy(boxXcord,boxYcord);
	printf("*");
	gotoxy(boxXcord+6,boxYcord);
	printf("*");
	gotoxy(boxXcord,boxYcord+1);
	printf("*******");
}
void boxmovements(){
	if(kbhit()){
		key=getch();
		if(key=='a' || key=='A')
		boxXcord--;
		if(key=='d' || key=='D')
		boxXcord++;
	}
}
void candy1(){
       gotoxy(xcord,ycord);
	printf("0");
	delay(210);
	ycord++;
}
void candy2(){
       gotoxy(xcord,ycord);
	printf("0");
	delay(200);
	ycord++;
}
void catchcandy(){
	if(ycord==25){
		diff=xcord-boxXcord;
		if(diff>=0 && diff<=6){
			score++;
			if(score%5==0){
				candy1();
			}
			if(score%10==0){
				candy2();
			}
			if(score%5==0 || score%10==0)
				level++;
		}
		else
			life--;
		xcord=rand()%60;
		ycord=3;
	}
}
void candy(){
	gotoxy(xcord,ycord);
	printf("0");
	delay(220);
	ycord++;
}
void gameover(){
	if(life==0){
		gotoxy(30,15);
		printf("Game over \n Your Score is:- %d\n Your Level is:- %d",score,level);
		delay(4000);
		exit(0);
	}
}
void main(){
	xcord=rand()%150;
	start:
	clrscr();
	gotoxy(30,1);
	printf("Score:- %d",score);
	gotoxy(60,1);
	printf("Level:- %d",level);
	gotoxy(30,2);
	printf("Lifes:- %d",life);
	//box cords
	boxcords();
	//box movements
	boxmovements();
	//catching the candy
	catchcandy();
	//candy cords
	candy();
	//game over
	gameover();
	goto start;
	getch();
}