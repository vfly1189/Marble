#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <mmsystem.h> 
struct player
{
	char name[20];
	int money;
};
void gotoxy(int x, int y) //gotoxy  함수 
{
 COORD Cur;
 Cur.X=x;
 Cur.Y=y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}
void hideCursor() //커서 숨기기 
{
   CONSOLE_CURSOR_INFO CurInfo; 
   CurInfo.dwSize=1; 
   CurInfo.bVisible=FALSE; 
   SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo); 
} 
void color(int color_number) //글씨색상 함수 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}
//가로방향 직선 출력 
//시작지점(x),시작지점(y),갯수,16진수값,16진수값 
void draw_straight_line_x(int start_point_x,int start_point_y,int count,char a,char b)   
{
	for(int i=1; i<=count; i++)
	{
		gotoxy(start_point_x,start_point_y);
		printf("%c%c",a,b);
		start_point_x+=2; 
	}
}
//세로방향 직선 출력 
//시작지점(x),시작지점(y),갯수,16진수값,16진수값 
void draw_straight_line_y(int start_point_x,int start_point_y,int count,char a,char b)   
{
	for(int i=1; i<=count; i++)
	{
		gotoxy(start_point_x,start_point_y);
		printf("%c%c",a,b);
		start_point_y++; 
	}
}
//네모 그리기
//시작지점(x), 시작지점(y), x갯수, y갯수, 16진수값, 16진수값 
void draw_square(int start_point_x,int start_point_y,int x_count, int y_count,char a,char b) 
{
	draw_straight_line_x(start_point_x,start_point_y,x_count,0xa1,0xe1);
	draw_straight_line_x(start_point_x,start_point_y+y_count-1,x_count,0xa1,0xe1);
	
	draw_straight_line_y(start_point_x,start_point_y,y_count,0xa1,0xe1);
	draw_straight_line_y(start_point_x+(x_count*2)-2,start_point_y,y_count,0xa1,0xe1);
}
//꽉찬 네모
//시작지점(x), 시작지점(y), x갯수, y갯수, 16진수값, 16진수값 
void draw_full_square(int start_point_x,int start_point_y,int x_count, int y_count,char a,char b) 
{
	for(int i=0; i<y_count; i++) draw_straight_line_x(start_point_x,start_point_y+i,x_count,0xa1,0xe1);
}




