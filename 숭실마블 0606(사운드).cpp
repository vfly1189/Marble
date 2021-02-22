#include "soongsilmarble.h"

#define player1 10 //빨 
#define player2 20 //연한파란색 
#define player3 30 //초 
#define player4 40 //노 

#define player1_color 12	//1p 빨 
#define player2_color 9		//2p 연한파란색 
#define player3_color 2		//3p 초 
#define player4_color 6		//4p 노 

int menu_print[31][65] = 
{
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3,3,0,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3,3,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3,3,0,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3,3,0,3,3,0,0,0,4,4,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,3,3,0,3,3,0,0,0,4,4,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,3,3,0,0,0,4,4,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,3,3,3,3,3,0,3,3,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,2,2,2,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,4,4,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,2,2,2,2,2,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,0,0,2,2,2,0,2,2,2,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,2,2,2,0,0,0,2,2,2,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,2,2,2,0,0,0,0,0,2,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,2,2,0,0,0,0,0,0,0,2,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,2,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,4,4,4,4,4,4,4,4,4,4,4,0,0,0},	
} ;
int map[37][37] =  //맵 
{
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,86,0,0,0,0,7,87,0,0,0,0,7,88,0,0,0,0,7,89,0,0,0,0,7,90,0,0,0,0,7,91,0,0,0,0,7},
	{7,0,0,0,0,0,7,1200,0,0,0,0,7,1400,0,0,0,0,7,1600,0,0,0,0,7,1800,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,5000,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,5000,0,0,7},
	{7,0,20,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,30,0,0,7},
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,85,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,92,0,0,0,0,7},
	{7,1800,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1000,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,84,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,93,0,0,0,0,7},
	{7,1600,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1000,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,83,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,94,0,0,0,0,7},
	{7,1400,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1000,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,7,7,7,7,7,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,82,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,95,0,0,0,0,7},
	{7,1200,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,1000,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
	{7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7},
	{7,81,0,0,0,0,7,100,0,0,0,0,7,99,0,0,0,0,7,98,0,0,0,0,7,97,0,0,0,0,7,96,0,0,0,0,7},
	{7,0,0,0,0,0,7,1800,0,0,0,0,7,1600,0,0,0,0,7,1400,0,0,0,0,7,1200,0,0,0,0,7,0,0,0,0,0,7},
	{7,0,0,5000,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,5000,0,0,7},
	{7,10,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,0,0,7,0,0,0,40,0,7},
	{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7},
};
int dice[6][13][13] = //주사위 디자인 
{
	{//1
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{//2
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,2,0,0,0,2,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{//3
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,2,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{//4
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{//5
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
	{//6
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,2,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
	},
};

int mapx,mapy; //맵좌표 
struct player p1 = {"player",50000};
struct player p2 = {"computer1",50000};
struct player p3 = {"computer2",50000};
struct player p4 = {"computer3",50000};
int cursor_x=55,cursor_y=30;
int memory_x=0,memory_y=0;  //커서위치값 기억  
int turn1=1,turn2=0,turn3=0,turn4=0;  //변수 값 기억   
int lplayerx=0,lplayery=0; //플레이어 위치 추적 
int total_turn=1;  //총 턴 

//int player1_health_point=5000,player2_health_point=5000,player3_health_point=5000,player4_health_point=5000;
int player1_attack_damage=300,player2_attack_damage=300,player3_attack_damage=300,player4_attack_damage=300;
int player1_money_return=0,player2_money_return=0,player3_money_return=0,player4_money_return=0;
int attack_multiple = 100;
int produce_multiple = 600;


 
///////////////////////////////////////////////////////////
void effect_moving_screen(); //화면이동 이펙트 
void game_ending_credit();
void game_end();  //게임끝 
void mid_clear();//중간 검은색으로 비워버리기 
int Cursor_x(int start_x,int start_y,int variation,int end_x);//증감,끝값 
int Cursor_y(int start_x,int start_y,int variation, int end_y);//증감,끝값 
void print_map(); //맵출력
void search_player(int player_information); //플레이어 위치추적 
void how_to_play(); //게임방법 
void main_menu(); //메인메뉴 
void player_info(); //플레이어 정보 출력 
int player_move(int move_count, int player_number);  //플레이어 이동
void money_return(); //돈 회수
void player_turn(int); //턴 바꿈   
int rolling_dice(); //주사위 굴리기
int buying_land_active(int player_money, int build_info); //땅사는 함수 내부 반복 함수  
int buying_land_active_com(int player_info,int player_money,int turn,int player_build_produce_info,int player_build_attack_info); //컴퓨터 자동 땅  
void buying_land(); //땅사는 함수    
///////////////////////////////////////////////////////////
int main(void)
{	
	system("mode con:cols=150 lines=55"); //사이즈 설정 
	hideCursor();
	PlaySound(TEXT("start_sound.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP); //ㅋㅋ넷마블 사운드 
	int temp;	
	srand(time(NULL)); 
	effect_moving_screen(); 

	main_menu(); 
	
	while(1)
	{
		game_end(); 
		print_map(); 
		player_info();	
		
		player_turn(rolling_dice());
		buying_land();
		
		
		  
	}
	return 0;
}
/////////////////////////////////////////////////////////////
void effect_moving_screen()//화면이동 이펙트 
{
	int x_position=0,x_count=75;
	int y_position=0,y_count=54;
	
	draw_square(x_position,y_position,x_count,y_count,0xa1,0xe1);
	while(1)
	{
		if(x_count<=0 && y_count<=0) break;
		Sleep(30);
		
		color(0);
		draw_square(x_position,y_position,x_count,y_count,0xa1,0xe1);
		color(7);
		
		x_position+=2;
		y_position++;
		x_count-=2;
		y_count-=2;
		
		if(x_count<=0)
		{
			x_count=0;
			x_position-=2;
		}
		if(y_count<=0)
		{
			y_count=0;
			y_position--;
		}
		
		draw_square(x_position,y_position,x_count,y_count,0xa1,0xe1);
	}
} 
void game_ending_credit()
{
	if(turn1 == -1 || p1.money <=0)
	{
		int random;
		random = rand()%3;
		if(random == 0) PlaySound(TEXT("Bankrup_A01.wav"),NULL,SND_FILENAME | SND_ASYNC);
		else if(random == 1) PlaySound(TEXT("Bankrup_A02.wav"),NULL,SND_FILENAME | SND_ASYNC);
		else if(random == 2) PlaySound(TEXT("Bankrup_A03.wav"),NULL,SND_FILENAME | SND_ASYNC);
	}
	
	else if(turn1+turn2+turn3+turn4==-3)
	{
		PlaySound(TEXT("GameWin_A02.wav"),NULL,SND_FILENAME | SND_ASYNC);
	}
}
void game_end()  //게임끝 
{
	/*
	if(map[34][3] <= 0) return;
	if(map[4][3] <= 0) turn2 = -1;
	if(map[4][33] <= 0) turn3 = -1;
	if(map[34][33] <= 0) turn4 = -1;
	*/
	
	if(turn1==-1) return;
	
	if(p1.money <= 0)
	{
		game_ending_credit();
		effect_moving_screen(); 
	
		Sleep(2500);
		exit(1);
	}
	if(p2.money <= 0)
	{
		for(int y=0; y<37; y++)
		for(int x=0; x<37; x++)
		if(map[y][x]==12 || map[y][x] == 22  || map[y][x]==20) map[y][x] = 0;
			
		turn2 = -1;
	}
	if(p3.money <= 0) 
	{
		for(int y=0; y<37; y++)
		for(int x=0; x<37; x++)
		if(map[y][x]==13 || map[y][x] == 23 || map[y][x]==30) map[y][x] = 0;
			
		turn3 = -1;
	}
	if(p4.money <= 0)
	{
		for(int y=0; y<37; y++)
		for(int x=0; x<37; x++)
		if(map[y][x]==14 || map[y][x] == 24 || map[y][x]==40) map[y][x] = 0;
			
		turn4 = -1;
	}

	if(turn1+turn2+turn3+turn4 == -3)
	{
		Sleep(1000);
		
		game_ending_credit();
		//effect_moving_screen(); 
		system("cls");
		for(int i=1; i<=50; i++)
		{
			Sleep(50);
			gotoxy(1,i); printf("당신은 승리하셨습니다!!!!!!!!!!!!!!!");
		}
	
	
		Sleep(2500);
		exit(1);
	
	}
		
}
void mid_clear()//중간 검은색으로 비워버리기  
{
	color(0);
	draw_full_square(51,16,23,23,0xa1,0xe1);
	color(7);
}
int Cursor_x(int start_x,int start_y,int variation,int end_x)//증감,끝값  
{
	cursor_x=start_x,cursor_y=start_y;
	int temp = 0;
	char ch;
	gotoxy(cursor_x,cursor_y); printf(">>");
	while(1)
	{
		ch = getch();
		switch(ch)
		{
			//left
			case 75 :
			gotoxy(cursor_x+temp,cursor_y); printf("   ");
			if(temp <=0) temp = 0;
			else temp -=  variation;
			break;
			
			//right
			case 77 :
			gotoxy(cursor_x+temp,cursor_y); printf("   ");
			if(temp >= end_x) temp = end_x;
			else temp +=  variation;
			break; 
		}
		gotoxy(cursor_x+temp,cursor_y); printf(">>");
		memory_x = cursor_x+temp;
		if(ch == 13) break;
	}
	return ch;
} 
int Cursor_y(int start_x,int start_y,int variation, int end_y)
{
	cursor_x=start_x,cursor_y=start_y;
	int temp = 0;
	char ch;
	gotoxy(cursor_x,cursor_y); printf(">>");
	while(1)
	{
		ch = getch();
		switch(ch)
		{
			//left
			case 72 :
			gotoxy(cursor_x,cursor_y+temp); printf("   ");
			if(temp <=0) temp = 0;
			else temp -=  variation;
			break;
			
			//right
			case 80 :
			gotoxy(cursor_x,cursor_y+temp); printf("   ");
			if(temp >= end_y) temp = end_y;
			else temp +=  variation;
			break; 
		}
		gotoxy(cursor_x,cursor_y+temp); printf(">>");
		memory_y=cursor_y+temp;
		if(ch == 13) break;
	}
	return ch;
}
void print_map() //맵출력 
{
	for(int y=0,mapy=9; y<37; y++,mapy++)
	{
		for(int x=0,mapx=37; x<37; x++,mapx+=2)
		{
			gotoxy(mapx,mapy); //81~100 칸이름 코드 
			if(map[y][x]==7) printf("■");
			else if(map[y][x]==81)	{color(player1_color); printf("컴퓨터학부"); color(7);}
			else if(map[y][x]==82)	printf("  경상관"); 
			else if(map[y][x]==83)	printf("  문화관"); 
			else if(map[y][x]==84)	printf("  교육관");
			else if(map[y][x]==85)	printf("  백마관"); 
			else if(map[y][x]==86)	{color(player2_color); printf("  스시소"); color(7);}
			else if(map[y][x]==87)	printf("중앙도서관"); 
			else if(map[y][x]==88)	printf("형남공학관"); 
			else if(map[y][x]==89)	printf(" 학생회관"); 
			else if(map[y][x]==90)	printf("  창의관"); 
			else if(map[y][x]==91)	{color(player3_color); printf("소프트웨어"); color(7);} 
			else if(map[y][x]==92)	printf("  커밍홀"); 
			else if(map[y][x]==93)	printf(" 대운동장"); 
			else if(map[y][x]==94)	printf("  농구장"); 
			else if(map[y][x]==95)	printf("  전산관");
			else if(map[y][x]==96)	{color(player4_color); printf("  전정공"); color(7);}
			else if(map[y][x]==97)	printf("경직기념관");
			else if(map[y][x]==98)	printf("만식기념관");
			else if(map[y][x]==99)	printf("  미래관"); 
			else if(map[y][x]==100)	printf("정보과학관"); 
			
			else if(map[y][x]==10){color(player1_color); printf("★"); color(7);} //빨  1p
			else if(map[y][x]==20){color(player2_color); printf("★"); color(7);} //연한파란색  2p 
			else if(map[y][x]==30){color(player3_color); printf("★"); color(7);} //초  3p
			else if(map[y][x]==40){color(player4_color); printf("★"); color(7);} //노 	4p
			
			else if(map[y][x]==11){color(player1_color); printf("■"); color(7);}  //생산타워 표 시 
			else if(map[y][x]==12){color(player2_color); printf("■"); color(7);}
			else if(map[y][x]==13){color(player3_color); printf("■"); color(7);}
			else if(map[y][x]==14){color(player4_color); printf("■"); color(7);}
			
			else if(map[y][x]==21){color(player1_color); printf("▲"); color(7);}  //생산타워 표 시 
			else if(map[y][x]==22){color(player2_color); printf("▲"); color(7);}
			else if(map[y][x]==23){color(player3_color); printf("▲"); color(7);}
			else if(map[y][x]==24){color(player4_color); printf("▲"); color(7);}
			

			


			else if(x==3&&y==4) {color(player2_color); printf("%d",map[4][3]); color(7);} 
			else if(x==33&&y==4) {color(player3_color); printf("%d",map[4][33]); color(7);} 
			else if(x==3&&y==34) {color(player1_color); printf("%d",map[34][3]); color(7);}
			else if(x==33&&y==34) {color(player4_color); printf("%d",map[34][33]); color(7);}
			
			if(x==2 || x==32)
			{
				if(y==9 || y==15 || y==21 || y==27)
				{
					if(map[y-2][x-1]%10 == 1) {color(player1_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 2) {color(player2_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 3) {color(player3_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 4) {color(player4_color); printf(" %d",map[y][x]); color(7);}
				}
			}
			if(y==3 || y==33)
			{
				if(x==8 || x==14 || x==20 || x==26)
				{
					if(map[y-2][x-1]%10 == 1) {color(player1_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 2) {color(player2_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 3) {color(player3_color); printf(" %d",map[y][x]); color(7);}
					else if(map[y-2][x-1]%10 == 4) {color(player4_color); printf(" %d",map[y][x]); color(7);}
				}
			}
			
			
		}
		printf("\n"); 
	}
}
void search_player(int player_information)
{
	for(int y=1; y<=35; y++)
	{
		for(int x=1; x<=35; x++)
		{
			if(map[y][x]==player_information)
			{
				lplayerx=x;
				lplayery=y;
				return;
			}
		}
	}
}
void how_to_play()  //게임방법  
{
	system("cls");
	print_map();
	player_info();
	
	color(player1_color);	draw_straight_line_x(39,28,5,0xa1,0xe1);
	color(player2_color); 	draw_straight_line_x(51,10,5,0xa1,0xe3);
	color(player3_color);	draw_straight_line_x(99,28,5,0xa1,0xe1);
	color(player4_color);	draw_straight_line_x(63,40,5,0xa1,0xe3);
	
	color(7); 
	gotoxy(57,20); printf("건설 할 수 있는 건물의 종류는 2가지!");
	gotoxy(65,23); printf("(생산건물과 전초기지)"); 
	
	draw_straight_line_x(58,27,5,0xa1,0xe1);
	gotoxy(70,27); printf("<---   생산건물");
	gotoxy(60,29); printf("턴이 지날때마다 돈이 들어옴"); 
	draw_straight_line_x(58,33,5,0xa1,0xe3);
	gotoxy(70,33); printf("<---   전초기지"); 
	gotoxy(67,35); printf("공격력 증가");
		
	getch();
	
	mid_clear(); 
	
	gotoxy(70,20); printf("승리조건");
	gotoxy(62,25); printf("1. 상대의 돈을 모두 빼았는다.");
	gotoxy(62,28); printf("2. 상대의 진영을 파괴 한다.");
	gotoxy(63,29); printf("(각 진영은 모서리)"); 
	
	getch();
	
	system("cls");
}
void main_menu() //메인메뉴 
{
	int enter=0;
	PlaySound(NULL,0,0);
	PlaySound(TEXT("GameWaitting.wav"),NULL,SND_FILENAME | SND_ASYNC | SND_LOOP);
	while(1)
	{
		char c;
		for(int j=0; j<30; j++)
		{
			for(int i=0; i<128; i+=2)
			{
				//Sleep(10);
				gotoxy(10+i,5+j);
				if(menu_print[j][i/2]==1)	{	color(12);	printf("★");	color(7);	}//숭  
				else if(menu_print[j][i/2]==2)	{	color(14);	printf("★");	color(7);	}//실  
				else if(menu_print[j][i/2]==3)	{	color(10);	printf("★");	color(7);	}//마  
				else if(menu_print[j][i/2]==4)	{	color(9);	printf("★");	color(7);	}//블  	
			}
		}
		gotoxy(70,42); printf("게 임 시 작"); 
		gotoxy(70,45); printf("게 임 방 법"); 
		
		enter = Cursor_y(66,42,3,3);
		if(enter == 13 && memory_y == 42) break;
		else if(enter == 13 && memory_y == 45)
		{
			how_to_play();
		}
		
	} 
	PlaySound(NULL,0,0);
	effect_moving_screen();
}
void player_info()  //플레이어 정보 출력   
{
	//gotoxy(1,1); printf("%d",total_turn);
	
	//1p
	color(12);
	gotoxy(5,5); printf("%s's money = %d원",p1.name,p1.money);
	gotoxy(5,6); printf("공격력 : %d",player1_attack_damage); 
	gotoxy(5,7); printf("생산력 : %d",player1_money_return);
	color(7);
	
	//2p
	color(9);
	gotoxy(117,5); printf("%s's money = %d원",p2.name,p2.money);
	gotoxy(117,6); printf("공격력 : %d",player2_attack_damage); 
	gotoxy(117,7); printf("생산력 : %d",player2_money_return);
	color(7);
	
	//3p
	color(2);
	gotoxy(5,49); printf("%s's money = %d원",p3.name,p3.money);
	gotoxy(5,50); printf("공격력 : %d",player3_attack_damage); 
	gotoxy(5,51); printf("생산력 : %d",player3_money_return);
	color(7);
	
	//4p
	color(6);
	gotoxy(117,49); printf("%s's money = %d원",p4.name,p4.money);
	gotoxy(117,50); printf("공격력 : %d",player4_attack_damage); 
	gotoxy(117,51); printf("생산력 : %d",player4_money_return);
	color(7);
	
	gotoxy(70,1); printf("현재 턴 : %d",total_turn);
	
	/*
	gotoxy(1,0); printf("%d %d %d %d",map[4][3],map[34][3],map[4][33],map[34][33]);
	gotoxy(1,1); printf("%d %d %d %d",player1_attack_damage,player2_attack_damage,player3_attack_damage,player4_attack_damage);
	gotoxy(1,2); printf("%d %d %d %d",player1_money_return,player2_money_return,player3_money_return,player4_money_return);
	gotoxy(1,3); printf("%d %d %d %d",turn1,turn2,turn3,turn4);
	if(turn1==1)
	{
		gotoxy(1,4); printf("1");
	} 
	else if(turn2==1)
	{
		gotoxy(1,4); printf("2");
	} 
	else if(turn3==1)
	{ 
		gotoxy(1,4); printf("3");
	} 
	else if(turn4==1)
	{
		gotoxy(1,4); printf("4");
	} 
	
	*/
}
int player_move(int move_count, int player_number)  //플레이어 이동  
{
	//PlaySound(NULL,0,0);  //주사위굴리는 함수에서 시작된 주사위사운드 멈추는 명령어  
	int playerx,playery;
	int count,check=0;
	
	for(int y=1; y<=35; y++)    //플레이어 위치 정보 저장 
	{
		if(check==1) break;
		for(int x=1; x<=35; x++)
		{
			if(map[y][x]==player_number)
			{
				playerx = x;
				playery = y;
				check=1;
			}
		}
	}
	
	map[playery][playerx]=0;
	
	
	for(count=1; count<=move_count; count++) 
	{
		map[playery][playerx]=0;		
		if(playerx < 5 && playery-6 > 0) playery-=6; //1번라인 
		else if(playery < 6 && playerx+6 < 36) playerx+=6; //2번라인 
		else if(playerx > 30 && playery+6 < 36) playery+=6; //3번라인 
		else if(playery > 34 && playerx-6 > 0) playerx-=6; //4번라인 
		map[playery][playerx] = player_number;
	}
	system("cls");
	player_info();
	print_map();
	
	int turn=0;
	turn = map[playery][playerx]/10;
	
	//gotoxy(123,30); printf("%d %d %d %d",turn,map[playery-3][playerx+1],map[playery-2][playerx-turn+1],(map[playery-4][playerx-turn+1]%10));
	
	if(turn != (map[playery-4][playerx-turn+1]%10))  //인수비용 전달  
	{
		
		//갯수 * 가격 
		if(turn == 1) //1p
		{
			if(map[playery-4][playerx]%10 == 2) p2.money += (map[playery-3][playerx+1] * map[playery-2][playerx]);
			else if(map[playery-4][playerx]%10 == 3) p3.money += (map[playery-3][playerx+1] * map[playery-2][playerx]);
			else if(map[playery-4][playerx]%10 == 4) p4.money += (map[playery-3][playerx+1] * map[playery-2][playerx]);
			p1.money = p1.money - (map[playery-3][playerx+1] * map[playery-2][playerx-turn+1]);
			
						
			//gotoxy(20,1); printf("test : %d %d %d",map[playery-4][playerx]%10,map[playery-3][playerx+1],map[playery-2][playerx]); 
		}
		if(turn == 2) //2p
		{
			if(map[playery-4][playerx-1]%10 == 1) p1.money += (map[playery-3][playerx] * map[playery-2][playerx-1]);
			else if(map[playery-4][playerx-1]%10 == 3) p3.money += (map[playery-3][playerx] * map[playery-2][playerx-1]);
			else if(map[playery-4][playerx-1]%10 == 4) p4.money += (map[playery-3][playerx] * map[playery-2][playerx-1]);
			p2.money = p2.money - (map[playery-3][playerx] * map[playery-2][playerx-turn+1]);
			
			
			//gotoxy(20,1); printf("test : %d %d %d",map[playery-4][playerx-1]%10,map[playery-3][playerx],map[playery-2][playerx-1]); 
		}
		if(turn == 3)  //3p
		{
			if(map[playery-4][playerx-2]%10 == 1) p1.money += (map[playery-3][playerx-1] * map[playery-2][playerx-2]);
			else if(map[playery-4][playerx-2]%10 == 2) p2.money += (map[playery-3][playerx-1] * map[playery-2][playerx-2]);
			else if(map[playery-4][playerx-2]%10 == 4) p4.money += (map[playery-3][playerx-1] * map[playery-2][playerx-2]);
			p3.money = p3.money - (map[playery-3][playerx-1] * map[playery-2][playerx-turn+1]);
			
			
			//gotoxy(20,1); printf("test : %d %d %d",map[playery-4][playerx-2]%10,map[playery-3][playerx-1],map[playery-2][playerx-2]);
		}
		if(turn == 4) //4p
		{
			if(map[playery-4][playerx-3]%10 == 1) p1.money += (map[playery-3][playerx-2] * map[playery-2][playerx-3]);
			else if(map[playery-4][playerx-3]%10 == 2) p2.money += (map[playery-3][playerx-2] * map[playery-2][playerx-3]);
			else if(map[playery-4][playerx-3]%10 == 3) p3.money += (map[playery-3][playerx-2] * map[playery-2][playerx-3]);
			p4.money = p4.money - (map[playery-3][playerx-2] * map[playery-2][playerx-turn+1]);
			
			
			//gotoxy(20,1); printf("test : %d %d %d",map[playery-4][playerx-3]%10,map[playery-3][playerx-2],map[playery-2][playerx-3]); Sleep(1000);
		}
	}

	return 0;
}
void money_return()
{
	p1.money += player1_money_return;
	p2.money += player2_money_return;
	p3.money += player3_money_return;
	p4.money += player4_money_return;
}
void player_turn(int a) //턴 바꿈  
{
	if(turn1==1) 
	{
		money_return();
		player_move(a,player1);
	}
	else if(turn2==1) player_move(a,player2);
	else if(turn3==1) player_move(a,player3);
		
	else if(turn4==1)
	{
		player_move(a,player4);
		total_turn += 1; 
	}
}
int rolling_dice() //주사위 굴리기  
{
	int count=0;
	int number;
	int x=61,y=21; 
	
	mid_clear();
	gotoxy(62,21); printf("주사위를 굴리시겠습니까?");
	
	if(turn1 == 1)
	{
		//MyTurn_A01.wav
		PlaySound(TEXT("MyTurn_A01.wav"),NULL,SND_FILENAME | SND_ASYNC);
		getch(); //1p 만 주사위 굴림  
	}
	
	while(count<=10) //주사위 굴리는 것 처럼 보이게
	  
	{
		number = rand()%6;
		count++;
		y=21; 
		mid_clear(); 
		for(int i=0; i<13; i++)  //주사위출력 
		{
			x=61;
			for(int j=0; j<13; j++)
			{
				if(dice[number][i][j]==1)
				{
					gotoxy(x,y);
					printf("■");
				}
				else if(dice[number][i][j]==2)
				{
					gotoxy(x,y);
					printf("●");
				}
				x+=2;
			}
			printf("\n"); 
			y++;
		}
		Sleep(30);
	}
	if(number+1 == 1) PlaySound(TEXT("DiceNum_A01.wav"),NULL,SND_FILENAME | SND_ASYNC);//playermove 에서 멈춤 
	else if(number+1 == 2) PlaySound(TEXT("DiceNum_A02.wav"),NULL,SND_FILENAME | SND_ASYNC);
	else if(number+1 == 3) PlaySound(TEXT("DiceNum_A03.wav"),NULL,SND_FILENAME | SND_ASYNC);
	else if(number+1 == 4) PlaySound(TEXT("DiceNum_A04.wav"),NULL,SND_FILENAME | SND_ASYNC);
	else if(number+1 == 5) PlaySound(TEXT("DiceNum_A05.wav"),NULL,SND_FILENAME | SND_ASYNC);
	else if(number+1 == 6) PlaySound(TEXT("DiceNum_A06.wav"),NULL,SND_FILENAME | SND_ASYNC);
	Sleep(1000);
	return number+1;
}
int buying_land_active(int player_money, int build_info,int turn)
{
	int build_count=0,max_build=0;
	
	gotoxy(122,21); printf("현재자금 : %d",player_money);
	gotoxy(122,25); printf("건물가격 : %d",map[lplayery-2][lplayerx-turn]);
	if((player_money/map[lplayery-2][lplayerx-turn]) >= 5) max_build = 5;
	else max_build = (player_money/map[lplayery-2][lplayerx-turn]);
	gotoxy(122,29); printf("최대건설 : %d",max_build);
	
	gotoxy(63,21); printf("몇 개을 구입하시겠습니까?");
	gotoxy(74,30); scanf("%d",&build_count);
	
	if(build_count > 5) build_count = 5;
	map[lplayery-3][lplayerx + 1] = build_count;
	
	if(build_count > 0)
	{
		for(int i=0; i<5; i++) map[lplayery-4][lplayerx+i-turn]=0;	//이전 건물 이펙트 삭제 
		
		for(int i=0; i<build_count; i++) map[lplayery-4][lplayerx+i-turn]=build_info; //본인 건물  
		
		map[lplayery-2][lplayerx+1] = build_count * map[lplayery-2][lplayerx];
		
	}
	return build_count;
}
int buying_land_active_com(int player_info,int player_money,int turn,int player_build_produce_info,int player_build_attack_info)
{
	int random=0;
	int build_count=0;
	
	search_player(player_info);
	mid_clear();
	
	gotoxy(66,25); printf("%dp 가 진행중입니다.",player_info/10);
	
	
	random = rand() % 100;
	
	if(random >= 0 && random <=45) random = 0;
	else if(random > 45 && random <=95) random = 1;
	else random = 2; 
	
	
	if(random != 2)
	{
		memory_x = 52 + (14 * random);
		
		build_count = (player_money / map[lplayery-2][lplayerx-turn]);
		if(player_money - (build_count * map[lplayery-2][lplayerx-turn]) <= 0) build_count -= 1;
		
		
		if(build_count >= 5) build_count = 5;
		 
	
		if(memory_x == 52) //개인건물 건설 생산타워 
		{
			if(map[lplayery-4][lplayerx-turn]%10 != (player_info/10))  //생산력 감소 
			{
				if(map[lplayery-4][lplayerx-turn]/10 == 1)
				{
					//빨 
					if(map[lplayery-4][lplayerx-turn]%10 == 1) player1_money_return = player1_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//파 
					else if(map[lplayery-4][lplayerx-turn]%10 == 2) player2_money_return = player2_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//초 
					else if(map[lplayery-4][lplayerx-turn]%10 == 3) player3_money_return = player3_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//노 
					else if(map[lplayery-4][lplayerx-turn]%10 == 4) player4_money_return = player4_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
				}
				else if(map[lplayery-4][lplayerx-turn]/10 == 2)
				{
						//빨 
					if(map[lplayery-4][lplayerx-turn]%10 == 1) player1_attack_damage = player1_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//파 
					else if(map[lplayery-4][lplayerx-turn]%10 == 2) player2_attack_damage = player2_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//초 
					else if(map[lplayery-4][lplayerx-turn]%10 == 3) player3_attack_damage = player3_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//노 
					else if(map[lplayery-4][lplayerx-turn]%10 == 4) player4_attack_damage = player4_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
				}
			}
			

				
			for(int i=0; i<5; i++) map[lplayery-4][lplayerx-turn+i]=0; //이전 건물 이펙트 초기화
			
			
			if(build_count>= 5) for(int i=0; i<5; i++) map[lplayery-4][lplayerx-turn+i]=player_build_produce_info;
			else for(int i=0; i<build_count; i++) map[lplayery-4][lplayerx-turn+i]=player_build_produce_info;
			
			//파 
			if(player_info == 20) player2_money_return = player2_money_return + (build_count * produce_multiple); 
			//초 
			else if(player_info == 30) player3_money_return = player3_money_return + (build_count * produce_multiple); 
			//노 
			else if(player_info == 40) player4_money_return = player4_money_return + (build_count * produce_multiple); 
			
			map[lplayery-2][lplayerx-turn+1] = build_count * map[lplayery-2][lplayerx-turn];
		}
		else if(memory_x == 66)
		{
			//인수 할때 상대공격력 감소 
			if(map[lplayery-4][lplayerx-turn]%10 != (player_info/10))  //생산력 감소 
			{
				if(map[lplayery-4][lplayerx-turn]/10 == 1)
				{
					//빨 
					if(map[lplayery-4][lplayerx-turn]%10 == 1) player1_money_return = player1_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//파 
					else if(map[lplayery-4][lplayerx-turn]%10 == 2) player2_money_return = player2_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//초 
					else if(map[lplayery-4][lplayerx-turn]%10 == 3) player3_money_return = player3_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
					//노 
					else if(map[lplayery-4][lplayerx-turn]%10 == 4) player4_money_return = player4_money_return - (map[lplayery-3][lplayerx+1-turn] * produce_multiple);
				}
				else if(map[lplayery-4][lplayerx-turn]/10 == 2)
				{
						//빨 
					if(map[lplayery-4][lplayerx-turn]%10 == 1) player1_attack_damage = player1_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//파 
					else if(map[lplayery-4][lplayerx-turn]%10 == 2) player2_attack_damage = player2_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//초 
					else if(map[lplayery-4][lplayerx-turn]%10 == 3) player3_attack_damage = player3_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
					//노 
					else if(map[lplayery-4][lplayerx-turn]%10 == 4) player4_attack_damage = player4_attack_damage - (map[lplayery-3][lplayerx+1-turn] * attack_multiple);
				}
			}
			
			for(int i=0; i<5; i++) map[lplayery-4][lplayerx-turn+i]=0; //이전 건물 이펙트 초기화
			
			
			if(build_count>= 5) for(int i=0; i<5; i++) map[lplayery-4][lplayerx-turn+i]=player_build_attack_info;
			else for(int i=0; i<build_count; i++) map[lplayery-4][lplayerx-turn+i]=player_build_attack_info;
			
			 //공격력 계산 
			if(player_info == 20) player2_attack_damage += build_count * attack_multiple;
			else if(player_info == 30) player3_attack_damage += build_count * attack_multiple;
			else if(player_info == 40) player4_attack_damage += build_count * attack_multiple;
			
			map[lplayery-2][lplayerx-turn+1] = build_count * map[lplayery-2][lplayerx-turn];
			
		}	
		
		map[lplayery-3][lplayerx + 1 - turn] = build_count;
		
	}
	Sleep(1000);
	
	if(random != 2) return build_count * map[lplayery-2][lplayerx-turn];
}
void buying_land() //땅사는 함수  
{
	int random=0;
	int enter=0;
	int enter2=0;
	int check=1;
	int build_count=0;
	int cur_x=0,cur_y=30;
	mid_clear();
	
	
	if(turn1 == 1) //1p 턴일때  
	{
		search_player(10);
		if(map[lplayery-3][lplayerx] % 5 == 1)    //상대 진영 도착시 건설 불가 
		{
			
			mid_clear();
			PlaySound(TEXT("warning.wav"),NULL,SND_FILENAME | SND_ASYNC);
			gotoxy(68,21); printf("진영 공격!!");
			
			Sleep(500);
			
			if(map[lplayery-3][lplayerx] == 81)  //상대진영 선택공격 
			{
				gotoxy(64,21); printf("공격 진영을 선택하세요");
				gotoxy(58,30); printf("파랑");
				gotoxy(72,30); printf("초록");
				gotoxy(86,30); printf("노랑");	
				
				enter = Cursor_x(54,30,14,28); 
				
				//파 
				if(enter == 13 && memory_x == 54) map[4][3] = map[4][3] - player1_attack_damage;
				//초 
				else if(enter == 13 && memory_x == 68) map[4][33] = map[4][33] - player1_attack_damage;
				//노 
				else if(enter == 13 && memory_x == 82) map[34][33] = map[34][33] - player1_attack_damage;
			} 
			//파 
			else if(map[lplayery-3][lplayerx] == 86)
			{
				 map[4][3] = map[4][3] - player1_attack_damage;
				 if(map[4][3] <= 0 )
				 {
				 	turn2=-1;
				 	map[4][3] = 0;
				 }
			}
			//초 
			else if(map[lplayery-3][lplayerx] == 91)
			{
				map[4][33] = map[4][33] - player1_attack_damage;
				if(map[4][33] <= 0 )
				{
					turn3=-1;
					map[4][33] = 0;
				}
			}
			//노 
			else if(map[lplayery-3][lplayerx] == 96)
			{
				map[34][33] = map[34][33] - player1_attack_damage;
				if(map[34][33] <= 0 )
				{
					turn4=-1;
					map[34][33] = 0;
				}
			}
			
			
			
			//턴교체 
			turn1=0;
			
			if(turn2==-1 && turn3 == -1 && turn4 == -1) game_end();
			else if(turn2==-1 && turn3 == -1) turn4=1;
			else if(turn2==-1) turn3=1;
			else turn2=1;
			return;
		}
		
		
		if(map[lplayery-4][lplayerx] > 0 && (map[lplayery][lplayerx]/10 != map[lplayery-4][lplayerx] % 10))  //인수  
		{
			mid_clear();
			
			gotoxy(66,21); printf("인수 하시겠습니까?");
			gotoxy(64,30); printf("예"); gotoxy(82,30); printf("아니오");
			
			gotoxy(122,21); printf("인수가격 : %d",map[lplayery-3][lplayerx+1]*map[lplayery-2][lplayerx]); 
			
			
			enter = Cursor_x(60,30,18,18);
			 
			if(enter == 13 && memory_x == 60) PlaySound(TEXT("TakeOver1_A02.wav"),NULL,SND_FILENAME | SND_ASYNC);
			else if(enter == 13 && memory_x == 78)
			{
				Sleep(500);
				turn1=0;
				if(turn2==-1 && turn3 == -1 && turn4 == -1) game_end();
				else if(turn2==-1 && turn3 == -1) turn4=1;
				else if(turn2==-1) turn3=1;
				else turn2=1;
				return;
			}
			
			//gotoxy(20,1); printf("test : %d",p1.money); Sleep(2000);
			
			
		}
		while(1)  //건물 구매  
		{
			mid_clear();
			gotoxy(62,21); printf("무엇을 구입하시겠습니까?"); 
			gotoxy(56,30); printf("휴식지역"); gotoxy(70,30); printf("전초기지"); gotoxy(84,30); printf("취소"); 
			enter = Cursor_x(52,30,14,28);
			if(enter == 13 && memory_x == 52)  //생산 타워 
			{
				mid_clear();
				
				if(map[lplayery-4][lplayerx]%10 != 1)  //상대 생산력감소 
				{	
					if(map[lplayery-4][lplayerx]/10 == 1)
					{
						//파 
						if(map[lplayery-4][lplayerx]%10 == 2) player2_money_return = player2_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
						//초 
						else if(map[lplayery-4][lplayerx]%10 == 3) player3_money_return = player3_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
						//노 
						else if(map[lplayery-4][lplayerx]%10 == 4) player4_money_return = player4_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
					}
					else if(map[lplayery-4][lplayerx]/10 == 2)
					{
						//파 
						if(map[lplayery-4][lplayerx]%10 == 2) player2_attack_damage = player2_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);
						//초 
						else if(map[lplayery-4][lplayerx]%10 == 3) player3_attack_damage = player3_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);
						//노 
						else if(map[lplayery-4][lplayerx]%10 == 4) player4_attack_damage = player4_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);	
					}
				
				}

				if(turn1 == 1)  //빨  
				{
					build_count = buying_land_active(p1.money,11,0); 
					p1.money = p1.money - (map[lplayery-2][lplayerx] * build_count);		
				} 
				mid_clear();
				if(p1.money <= 0) game_end();
				
				player1_money_return = player1_money_return + (build_count*produce_multiple);
				
				
				
				break;
			}
			else if(enter == 13 && memory_x == 66)  //공격 타워 
			{
				mid_clear();
				if(turn1 == 1)  //빨  플레이턴 함수 끝나면 다음 플레이어턴 변수가 1로 바뀐상태이기때문에 
				{
					if(map[lplayery-4][lplayerx]%10 != 1)  //상대 생산력감소 
					{	
						if(map[lplayery-4][lplayerx]/10 == 1)
						{
							//파 
							if(map[lplayery-4][lplayerx]%10 == 2) player2_money_return = player2_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
							//초 
							else if(map[lplayery-4][lplayerx]%10 == 3) player3_money_return = player3_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
							//노 
							else if(map[lplayery-4][lplayerx]%10 == 4) player4_money_return = player4_money_return - (map[lplayery-3][lplayerx+1] * produce_multiple);
						}
						else if(map[lplayery-4][lplayerx]/10 == 2)
						{
							//파 
							if(map[lplayery-4][lplayerx]%10 == 2) player2_attack_damage = player2_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);
							//초 
							else if(map[lplayery-4][lplayerx]%10 == 3) player3_attack_damage = player3_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);
							//노 
							else if(map[lplayery-4][lplayerx]%10 == 4) player4_attack_damage = player4_attack_damage - (map[lplayery-3][lplayerx+1] * attack_multiple);	
						}
					
					}
						
					build_count = buying_land_active(p1.money,21,0); 
					p1.money = p1.money - (map[lplayery-2][lplayerx] * build_count);  //돈계산 
					
					player1_attack_damage += build_count * attack_multiple;	 //공격력 증가 
				} 
				mid_clear();
				
				if(p1.money <= 0) game_end();
				break;
			}
			else if(enter==13 && memory_x==80) //취소  
			{
				mid_clear();
				break;	
			}
			
			
		}	
		turn1=0;
		if(turn2==-1) turn3=1;
		else turn2=1;
	
		
	}
	else if(turn2 == 1)	//돈 계산 
	{
		search_player(20);
		
		if(map[lplayery-3][lplayerx-1] % 5 == 1)   //상대 진영 도착시 건설 불가 
		{
			mid_clear();
			PlaySound(TEXT("warning.wav"),NULL,SND_FILENAME | SND_ASYNC);
			gotoxy(68,21); printf("진영 공격!!");
			
			Sleep(500); 
			
			//빨
			if(map[lplayery-3][lplayerx-1] == 81)
			{
				map[lplayery-1][lplayerx + 1] -= player2_attack_damage;
				if(map[lplayery-1][lplayerx + 1] <= 0) return;
			} 
			else if(map[lplayery-3][lplayerx-1] == 86) //자기진영 도착시 
			{
				 random = rand()%3;
				 
				 //빨 
				 if(random == 0) map[34][3] = map[34][3] - player2_attack_damage;
				 //초 
				 else if(random == 1) map[4][33] = map[4][33] - player2_attack_damage;
				 //노 
				 else if(random == 2) map[34][33] = map[34][33] - player2_attack_damage;
			}
			//초  
			else if(map[lplayery-3][lplayerx-1] == 91)
			{
				map[lplayery-1][lplayerx + 1] -= player2_attack_damage;
				if(map[lplayery-1][lplayerx + 1] <= 0)
				{
					turn3=-1;
					map[lplayery-1][lplayerx + 1] = 0;
				}
			}
			//노 
			else if(map[lplayery-3][lplayerx-1] == 96)
			{
				 map[lplayery-1][lplayerx + 1] -= player2_attack_damage;
				 if( map[lplayery-1][lplayerx + 1] <= 0)
				 {
				 	turn4=-1;
				 	 map[lplayery-1][lplayerx + 1] = 0;
				 }
			}
			
			Sleep(500);
			turn2=0;
			
			if(turn3==-1 && turn4==-1 && turn1 == -1) game_end();
			else if(turn3==-1 && turn4==-1) turn1=1;
			else if(turn3==-1) turn4=1;
			else turn3=1;
			
			return;
		}
		
		p2.money = p2.money -  buying_land_active_com(20,p2.money,1,12,22);	Sleep(1000);
		
		turn2=0;
		if(turn3==-1) turn4=1;
		else turn3=1;	
	}  
	else if(turn3 == 1) 
	{
		search_player(30);
		if(map[lplayery-3][lplayerx-2] % 5 == 1) //상대 진영 도착시 건설 불가 
		{
			mid_clear();
			PlaySound(TEXT("warning.wav"),NULL,SND_FILENAME | SND_ASYNC);
			gotoxy(68,21); printf("진영 공격!!");
			
			Sleep(500); 
			
			//파
			if(map[lplayery-3][lplayerx-2] == 86)
			{
				map[lplayery-1][lplayerx + 0] -= player3_attack_damage; 
				if(map[lplayery-1][lplayerx + 0] <= 0)
				{
					turn2 = -1;
					map[lplayery-1][lplayerx + 0] = 0;
				}
			}
			//빨 
			else if(map[lplayery-3][lplayerx-2] == 81)
			{
				map[lplayery-1][lplayerx + 0] -= player3_attack_damage;
				if(map[lplayery-1][lplayerx + 0] <= 0) return;
			}
			else if(map[lplayery-3][lplayerx-1] == 91) //자기진영 도착시 
			{
				 random = rand()%3;
				 
				 //빨 
				 if(random == 0) map[34][3] = map[34][3] - player3_attack_damage;
				 //파 
				 else if(random == 1) map[4][3] = map[4][3] - player3_attack_damage;
				 //노 
				 else if(random == 2) map[34][33] = map[34][33] - player3_attack_damage;
			}
			//노 
			else if(map[lplayery-3][lplayerx-2] == 96)
			{
				map[lplayery-1][lplayerx + 0] -= player3_attack_damage;
				if(map[lplayery-1][lplayerx + 0] <= 0)
				{
					turn4=-1;
					map[lplayery-1][lplayerx + 0] = 0;
				}
			}
		
			Sleep(500);
			turn3=0;
			
			if(turn4==-1 && turn1==-1 && turn2==-1) game_end();
			else if(turn4==-1 && turn1==-1) turn2=1;
			else if(turn4==-1) turn1=1;
			else turn4=1;
			
			
			return;
		}
		
		p3.money = p3.money -  buying_land_active_com(30,p3.money,2,13,23);	Sleep(1000);
		
		turn3=0;
		if(turn4==-1) turn1=1;
		else turn4=1;	
	}
	else if(turn4 == 1) 
	{
		search_player(40);
		if(map[lplayery-3][lplayerx-3] % 5 == 1)    //상대 진영 도착시 건설 불가
		{
			mid_clear();
			PlaySound(TEXT("warning.wav"),NULL,SND_FILENAME | SND_ASYNC);
			gotoxy(68,21); printf("진영 공격!!");
			
			Sleep(500);
			
			//파 
			if(map[lplayery-3][lplayerx-3] == 86) 
			{
				map[lplayery-1][lplayerx - 1] -= player4_attack_damage; 
				if(map[lplayery-1][lplayerx - 1] <= 0)
				{
					turn2=-1;
					map[lplayery-1][lplayerx - 1] = 0;
				}
			}
			//초
			else if(map[lplayery-3][lplayerx-3] == 91)
			{
				map[lplayery-1][lplayerx - 1] -= player4_attack_damage; 
				if(map[lplayery-1][lplayerx - 1] <= 0)
				{
					turn3=-1;
					map[lplayery-1][lplayerx - 1] = 0;
				}
			}
			//빨 
			else if(map[lplayery-3][lplayerx-3] == 81)
			{
				map[lplayery-1][lplayerx - 1] -= player4_attack_damage;
				if(map[lplayery-1][lplayerx - 1] <= 0) return;
			}
			else if(map[lplayery-3][lplayerx-1] == 96) //자기진영 도착시 
			{
				 random = rand()%3;
				 
				 //빨 
				 if(random == 0) map[34][3] = map[34][3] - player4_attack_damage;
				 //초 
				 else if(random == 1) map[4][33] = map[4][33] - player4_attack_damage;
				 //파 
				 else if(random == 2) map[4][3] = map[4][3] - player4_attack_damage;
			}
			
			
			Sleep(500);
			turn4=0;
			
			if(turn1==-1 && turn2==-1 && turn3==-1)	game_end();
			else if(turn1==-1 && turn2==-1) turn3=1;
			else if(turn1==-1) turn2=1;
			else turn1=1;
			
			return;
		} 

		p4.money = p4.money -  buying_land_active_com(40,p4.money,3,14,24);	Sleep(1000);

		turn4=0;
		if(turn1==-1) turn2=1;
		else turn1=1;	
	}
}

