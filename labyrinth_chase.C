#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
int score=0,moves=0;
int flag[5]={0,0,0,0,0};
void loading();
void maze(int, int);
void move(char, int, int);
void food(int, int);
main()
{
	int gd = DETECT, gm, x, y;
	char ch;
	x = 300, y = 40;
	initgraph(&gd, &gm, "..\\BGI");
	loading();
	delay(200);
	cleardevice();
	maze(x,y);
	food(x,y);
	ch = 0;
	move(ch,x,y);
	getch();
	closegraph();
	return 0;
}
void loading()
{
	int i,j;
	rectangle(200,200,400,220);
	j = 1;
	for(i=250;i<=400;i=i+50)
	{
		cleardevice();
		rectangle(200,200,400,220);
		bar(200,200,i,220);
		if(j%3 == 1)
			outtextxy(260,230,"Loading.");
		else if(j%3 == 2)
			outtextxy(260,230,"Loading..");
		else
			outtextxy(260,230,"Loading...");
		j++;
		delay(300);
	}
}
void move(char ch, int x, int y)
{
	while(ch != 27)
	{
		ch = getch();
		if((x == 80 && y == 40) && (ch != 80))
		{
			outtextxy(400,200,"Invalid move!");
			outtextxy(400,160,"Penalty -10");
			continue;
		}
		switch(ch)
		{
			case 72: //up
				if(getpixel(x,y-10) == 3)
				{
					outtextxy(400,200,"Invalid move!");
					outtextxy(400,160,"Penalty -10");
					score-=10;
					continue;
				}
				else
					y-=10;
				break;
			case 80: //down
				if(getpixel(x,y+10) == 3)
				{
					outtextxy(400,200,"Invalid move!");
					outtextxy(400,160,"Penalty -10");
					score-=10;
					continue;
				}
				else
					y+=10;
				break;
			case 77: //right
				if(getpixel(x+10,y) == 3)
				{
					outtextxy(400,200,"Invalid move!");
					outtextxy(400,160,"Penalty -10");
					score-=10;
					continue;
				}
				else
					x+=10;
				break;
			case 75: //left
				if(getpixel(x-10,y) == 3)
				{
					outtextxy(400,200,"Invalid move!");
					outtextxy(400,160,"Penalty -10");
					score-=10;
					continue;
				}
				else
					x-=10;
				break;
		}
		cleardevice();
		food(x,y);
		maze(x,y);
		moves+=10;
		if(moves%50 == 0)
			score+=10;
		if((x>80 && x<120)&&(y == 410))
		{
			cleardevice();
			outtextxy(250,250,"You Won! :)");
			break;
		}
		if(score<0)
		{
			cleardevice();
			outtextxy(250,250,"Game over! You are dead:(");
		}
	}
}
void food(int x, int y)
{
	int i;
	char t[20];
	int x1[5]={100,300,180,340,140};
	int y1[5]={60,140,220,260,300};
	outtextxy(400,390,"Your current position");
	sprintf(t,"x %d, y %d",x,y);
	outtextxy(400,400,t);
	for(i=0;i<5;i++)
	{
		if(x1[i]==x && y1[i] == y)
		{
			flag[i] = 1;
			score+=20;
			outtextxy(400,160,"Bonus +20");
			maze(x,y);
		}
	}
	for(i=0;i<5;i++)
	{
		if(flag[i] == 0)
		{
			setcolor(4);
			circle(x1[i],y1[i],0);
			setfillstyle(2,3);
		}
	}

}
void maze(int x, int y)
{
	//score display
	char t[20];
	sprintf(t,"score= %d",score);
	outtextxy(400,150,t);
	//maze fixed lines
	setcolor(3);
	line(40,40,280,40);
	line(320,40,360,40);
	line(40,40,40,400);
	line(360,40,360,400);
	line(40,400,80,400);
	line(120,400,360,400);
	line(80,40,80,120);
	line(80,120,160,120);
	line(60,340,60,380);
	line(60,380,100,380);
	line(120,80,320,80);
	line(320,80,320,120);
	line(280,120,320,120);
	line(280,120,280,160);
	line(280,160,360,160);
	line(220,220,220,260);
	line(220,260,260,260);
	line(260,260,260,340);
	line(180,300,180,340);
	line(180,340,220,340);
	line(100,170,100,220);
	line(60,300,100,300);
	line(100,300,100,340);
	line(160,40,160,60);
	line(240,60,240,80);
	line(240,100,240,160);
	line(240,100,300,100);
	line(160,160,240,160);
	line(200,120,200,240);
	line(40,160,120,160);
	line(120,160,120,200);
	line(40,200,80,200);
	line(120,200,160,200);
	line(40,280,80,280);
	line(80,240,80,280);
	line(80,240,200,240);
	line(200,200,280,200);
	line(280,200,280,280);
	line(280,280,320,280);
	line(320,280,320,360);
	line(280,360,320,360);
	line(320,200,320,240);
	line(320,240,360,240);
	line(240,280,240,360);
	line(160,360,240,360);
	line(200,280,200,320);
	line(160,320,160,280);
	line(160,280,120,280);
	line(120,280,120,400);
	line(80,320,80,360);
	line(140,120,140,180);
	//entry exit labels
	setcolor(WHITE);
	outtextxy(290,20,"Entry");
	outtextxy(90,420,"Exit");
	//instructions display
	setcolor(6);
	outtextxy(400,40,"Instructions: Use the arrow keys");
	outtextxy(400,50,"to move up, down, left, right");
	outtextxy(400,60,"If you collide with any of the");
	outtextxy(400,70,"walls you are penalized by 10 points");
	outtextxy(400,80,"Red dots gives bonus points");
	//runner
	setcolor(YELLOW);
	circle(x,y,3);
	setfillstyle(1,2);
	floodfill(x,y,14);
}
