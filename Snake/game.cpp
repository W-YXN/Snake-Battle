//wall 1|snakeb 2|snakeh 3|food 4
#include"stdafx.h"
#include"Snake.h"
#include<iostream>
#include<Windows.h>
#include<cstring>
#include<string>
#include<cstdlib>

#define __direct_right 0
#define __direct_down 1
#define __direct_left 2
#define __direct_up 3
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void hide_mouse();
void gotoxy(short x, short y);
void color_out(string st, short x);
void c_out(string st, short x);
void shade_out(string st, short x, short y, int s, bool z);
void shade_out_r(string st, short x, short y, int s, bool a, bool z);
void pogress_bar();
void g_out(short id, bool x);
int _rand(int x);
int *settings_synchronization();
int *statistics_synchronization();
void v_death();
void windowssize(short x, short y);
void statistics_write();
void save_players(string name,short score);
bool pause_menu();
void v_win();
void v_escape();
void playsound(short id);

//======================================================================================

int *GameSettingsData;
int *GameStatisticsData;
int Walked, SimpleFoodEaten, ModFoodEaten;
short GameData[20];
short StructureX = 1, StructureY = 1;
short Maps[32][32];
struct snake
{
	short x;
	short y;
} SnakeBody[901];
struct mod
{
	short x;
	short y;
} Food;
short Direct;
short DirectTemp;
short SnakeLength;
short SnakeEaten;
short SnakeScore;
short Mood, MoodTemp, MoodData[10];
int FoodAlready;
short FruitAddition;

//======================================================================================

void Game_settings_synchronization()
{
	GameSettingsData = settings_synchronization();
	GameStatisticsData = statistics_synchronization();
}

void death()
{
	short n = 5;
	Sleep(500);
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= SnakeLength; i++)
		{
			gotoxy(StructureX + SnakeBody[i].x * 2, StructureY + SnakeBody[i].y);
			cout << "  ";
		}
		Sleep(100);
		for (int i = 1; i <= SnakeLength; i++)
		{
			gotoxy(StructureX + SnakeBody[i].x * 2, StructureY + SnakeBody[i].y);
			g_out(Maps[SnakeBody[i].x][SnakeBody[i].y], false);
		}
		Sleep(100);
	}
	for (int i = 1; i <= SnakeLength; i++)
	{
		gotoxy(StructureX + SnakeBody[i].x * 2, StructureY + SnakeBody[i].y);
		cout << "  ";
	}
	Sleep(100);
	v_death();
}

void win()
{
	Sleep(100);
	v_win();
}

void escape()
{
	Sleep(100);
	v_escape();
}

void Snakestate()
{
	short GSx = StructureX + 67, GSy = StructureY + 2;
	gotoxy(GSx, GSy);
	cout << "分数:" << SnakeScore;
	gotoxy(GSx + 10, GSy);
	cout << "身长:" << SnakeLength;
	gotoxy(GSx + 20, GSy);
	cout << "进食次数:" << SnakeEaten;
}

void moodstate()
{
	short GSx = StructureX + 67 + 15, GSy = StructureY + 2 + 1;
	gotoxy(GSx, GSy);
	cout << "状态:";
	switch (Mood)
	{
	case 0:
		cout << "正常    ";
		break;
	case 1:
		cout << "进食中  ";
		break;
	case 2:
		cout << "危险  ";
		break;
	case 3:
		cout << "兴奋  ";
		break;
	case 4:
		cout << "失落  ";
		break;
	}
}

void DirectState()
{
	short GSx = StructureX + 67, GSy = StructureY + 2 + 1;
	short GSx2 = StructureX + 74, GSy2 = StructureY + 2 + 21;
	gotoxy(GSx2 + 10, GSy2 + 1);
	color_out("↑", 2);
	gotoxy(GSx2 + 10, GSy2 + 3);
	color_out("↓", 2);
	gotoxy(GSx2 + 5, GSy2 + 2);
	color_out("←", 2);
	gotoxy(GSx2 + 14, GSy2 + 2);
	color_out("→", 2);
	gotoxy(GSx, GSy);
	cout << "朝向: ";
	switch (Direct)
	{
	case __direct_right:
		cout << " →右";
		gotoxy(GSx2 + 14, GSy2 + 2);
		color_out("→", 4);
		break;
	case __direct_down:
		cout << " ↓下";
		gotoxy(GSx2 + 10, GSy2 + 3);
		color_out("↓", 4);
		break;
	case __direct_left:
		cout << " ←左";
		gotoxy(GSx2 + 5, GSy2 + 2);
		color_out("←", 4);
		break;
	case __direct_up:
		cout << " ↑上";
		gotoxy(GSx2 + 10, GSy2 + 1);
		color_out("↑", 4);
		break;
	}
	
}

void Gamestate()
{
	short GSx = StructureX + 67, GSy = StructureY + 2 + 27;
	gotoxy(GSx, GSy);
	c_out("颜色:", 2);
	if (GameSettingsData[1] == 1)
	{
		cout << "√";
	}
	else
	{
		cout << "×";
	}
	cout << " ";
	c_out("动画:", 2);
	if (GameSettingsData[2] == 1)
	{
		cout << "√";
	}
	else
	{
		cout << "×";
	}
	cout << " ";
	c_out("声音:", 2);
	if (GameSettingsData[3] == 1)
	{
		cout << "√";
	}
	else
	{
		cout << "×";
	}
	cout << " ";
	c_out("帮助:", 2);
	if (GameSettingsData[4] == 1)
	{
		cout << "√";
	}
	else
	{
		cout << "×";
	}
}

void GameTips()
{
	string st[2][5] = {
		{
			"        W[上]        ",
			"          ↑         ",
			"A[左]←P[暂停]→D[右]",
			"          ↓         ",
			"        S[下]        "
		},
		{
			"        S[下]        ",
			"          ↑         ",
			"D[右]←P[暂停]→A[左]",
			"          ↓         ",
			"        W[上]        "
		}
	};
	short GSx = StructureX + 74, GSy = StructureY + 2 + 21;

	if(GameData[4]==1)
		for (int i = 0;i <= 4;i++) {
			gotoxy(GSx, GSy + i);
			c_out(st[1][i], 2);
		}
	else
		for (int i = 0;i <= 4;i++) {
			gotoxy(GSx, GSy + i);
			c_out(st[0][i], 2);
		}
	DirectState();
}


void mood_manage()
{
	if (Mood != 0)
	{
		MoodTemp--;
		if (MoodTemp <= 0)
		{
			MoodTemp = 4;
			Mood = 0;
			moodstate();
		}
	}
}

bool mood_around(short x, bool style)
{
	const short _dir2[24][2] =
	{
		{ -2,2 },{ -1,2 },{ 0,2 },{ 1,2 },{ 2,2 },
		{ -2,1 },{ -1,1 },{ 0,1 },{ 1,1 },{ 2,1 },
		{ -2,0 },{ -1,0 },{ 1,0 },{ 2,0 },
		{ -2,-1 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 2,-1 },
		{ -2,-2 },{ -1,-2 },{ 0,-2 },{ 1,-2 },{ 2,-2 }
	};
	const short _dir1[8][2] =
	{
		{ -1,1 },{ 0,1 },{ 1,1 },
		{ -1,0 },{ 1,0 },
		{ -1,-1 },{ 0,-1 },{ 1,-1 }
	};
	if (style == true)
	{
		for (int i = 0; i <= 23; i++)
		{
			short tx = SnakeBody[SnakeLength].x + _dir2[i][0];
			short ty = SnakeBody[SnakeLength].y + _dir2[i][1];
			if (tx >= 0 && ty >= 0 && tx <= 31 && ty <= 31 && Maps[tx][ty] == x)
				return true;
		}
	}
	else
	{
		for (int i = 0; i <= 8; i++)
		{
			short tx = SnakeBody[SnakeLength].x + _dir1[i][0];
			short ty = SnakeBody[SnakeLength].y + _dir1[i][1];
			if (tx >= 0 && ty >= 0 && tx <= 31 && ty <= 31 && Maps[tx][ty] == x)
				return true;
		}
	}
	return false;
}
void mood_check()
{
	if (mood_around(1, false) || mood_around(6, false))
	{
		if (Mood == 2)
		{
			MoodTemp = 4;
		}
		else
		{
			playsound(6);
			Mood = 2;
			MoodTemp = 4;
			moodstate();
		}
	}
	if (Mood != 2 && mood_around(4, true))
	{
		MoodData[1] = 1;
		if (Mood == 3)
		{
			MoodTemp = 4;
		}
		else
		{
			playsound(4);
			Mood = 3;
			MoodTemp = 4;
			moodstate();
		}
	}
	if (Mood == 3 && MoodData[1] == 1 && MoodTemp == 1)
	{
		playsound(7);
		Mood = 4;
		MoodTemp = 4;
		MoodData[1] = 0;
		moodstate();
	}

}

void make_food()
{
	if (FoodAlready == 0)
	{
		while (true)
		{
			Food.x = _rand(29) + 1;
			Food.y = _rand(29) + 1;
			if (Maps[Food.x][Food.y] == 0)
			{
				FoodAlready++;
				Maps[Food.x][Food.y] = 4;
				gotoxy(StructureX + 2 * Food.x, StructureY + Food.y);
				g_out(4, false);
				break;
			}
		}
	}
}

void game_prepare()
{
	hide_mouse();
	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
	system("cls");
	for (int i = 0; i <= _rand(1) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(50) + 50);
	}
	gotoxy(32, 20);
	c_out("正在清理场地          ", 1);
	memset(Maps, 0, sizeof(Maps));
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(60) + 30);
	}
	gotoxy(32, 20);
	color_out("正在布置场地          ", 1);
	for (int i = 0; i <= 31; i++)
	{
		Maps[0][i] = 1;
		Maps[31][i] = 1;
		Maps[i][0] = 1;
		Maps[i][31] = 1;
	}
	memset(GameData, 0, sizeof(GameData));
	FruitAddition = 0;
	if (GameSettingsData[13] == 1)
		FruitAddition++;
	if (GameSettingsData[14] == 1)
		FruitAddition++;
	if (GameSettingsData[15] == 1)
		FruitAddition++;
	for (int i = 0; i <= _rand(2) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(35) + 50);
	}
	gotoxy(32, 20);
	color_out("正在放置贪吃蛇        ", 1);

	Maps[1][1] = 2;
	Maps[2][1] = 2;
	Maps[3][1] = 2;
	Maps[4][1] = 3;
	SnakeBody[1].x = 1;
	SnakeBody[1].y = 1;
	SnakeBody[2].x = 2;
	SnakeBody[2].y = 1;
	SnakeBody[3].x = 3;
	SnakeBody[3].y = 1;
	SnakeBody[4].x = 4;
	SnakeBody[4].y = 1;
	FoodAlready = 0;
	Direct = __direct_right;
	DirectTemp = __direct_right;
	Mood = 0;
	MoodTemp = 4;
	Walked = 0;
	SimpleFoodEaten = 0;
	ModFoodEaten = 0;

	for (int i = 0; i <= _rand(3) + 1; i++)
	{
		pogress_bar();
		Sleep(_rand(35) + 50);
	}

	gotoxy(32, 20);
	color_out("正在准备记录        ", 1);
	SnakeLength = 4;
	SnakeEaten = 0;
	SnakeScore = 0;

	for (int i = 0; i <= _rand(3) + 2; i++)
	{
		pogress_bar();
		Sleep(_rand(65) + 40);
	}
	Sleep(200);
	system("cls");
	Sleep(200);
	system("mode con cols=103 lines=34");
//	windowssize(103, 34);
}

void draw()
{
	for (int i = 0; i <= 31; i++)
	{
		for (int j = 0; j <= 31; j++)
		{
			if (Maps[i][j] != 0)
			{
				gotoxy(StructureX + 2 * i, StructureY + j);
				g_out(Maps[i][j], false);
			}
		}
	}
}

void de_bug_draw()
{
	for (int i = 0; i <= 31; i++)
	{
		for (int j = 0; j <= 31; j++)
		{
			if (Maps[i][j] != 0)
			{
				gotoxy(StructureX + 2 * i, StructureY + j);
				cout << Maps[i][j];
			}
		}
	}
}

void mod_wall()
{
	const short _dir[25][2] =
	{
		{ -2,2 },{ -1,2 },{ 0,2 },{ 1,2 },{ 2,2 },
		{ -2,1 },{ -1,1 },{ 0,1 },{ 1,1 },{ 2,1 },
		{ -2,0 },{ -1,0 },{ 0,0 },{ 1,0 },{ 2,0 },
		{ -2,-1 },{ -1,-1 },{ 0,-1 },{ 1,-1 },{ 2,-1 },
		{ -2,-2 },{ -1,-2 },{ 0,-2 },{ 1,-2 },{ 2,-2 }
	};

	bool put1 = true, put2;
	short sx, sy;

	if (GameData[1] <= 20 + GameSettingsData[22] / 4 - 1)
	{
		if (_rand(50 + 2 * GameData[1]) <= GameSettingsData[22] / 2 - 1)
		{
			while (put1)
			{
				put2 = true;
				sx = _rand(30);
				sy = _rand(30);
				if (sx>1 && sy>1 && sx<29 && sy<29)
				{
					for (int i = 0; i <= 24; i++)
					{
						short tx = sx + _dir[i][0];
						short ty = sy + _dir[i][1];
						if (tx <= 0 || ty <= 0 || tx >= 31 || ty >= 31)
							break;

						if (Maps[tx][ty] == 3 || Maps[tx][ty] == 6)
						{
							put2 = false;
							break;
						}
					}
					if (Maps[sx][sy] == 0 && put2 == true)
					{
						put1 = false;
					}
				}
			}
			Maps[sx][sy] = 6;
			gotoxy(StructureX + sx * 2, StructureY + sy);
			g_out(6, false);
			GameData[1]++;
		}
	}
}
void wait()
{
	for (int i = SnakeLength + 1;i <= 900;i++) {
		SnakeBody[i].x = SnakeBody[i].y = -1;
	}
	playsound(3);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:3.0秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.9秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.8秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.7秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.6秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.5秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.4秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.3秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.2秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.1秒"));
	Sleep(100);
	playsound(3);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:2.0秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.9秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.8秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.7秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.6秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.5秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.4秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.3秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.2秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.1秒"));
	Sleep(100);
	playsound(3);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:1.0秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.9秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.8秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.7秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.6秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.5秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.4秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.3秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.2秒"));
	Sleep(100);
	SetConsoleTitle(TEXT("贪吃蛇    等待中,剩余时间:0.1秒"));
	Sleep(100);
	playsound(2);
	SetConsoleTitle(TEXT("贪吃蛇    游戏中"));
}

void mod_state_clear() {
	int x = StructureX + 67;
	int y = StructureY + 3 + 1;
	for (int temp = 0;temp <= 1;temp++) {
		gotoxy(x + 6, y + 2 * temp);
		cout << "                  ";
		gotoxy(x + 6, y + 1 + 2 * temp);
		cout << "                  ";
	}
}

void mod_state() 
{
	int x = StructureX + 67;
	int y = StructureY + 3 + 1;
	gotoxy(x,y);
	cout << "效果:";
	short temp=0;
	if (GameData[4] == 0&& GameData[7] == 0) {
		mod_state_clear();
		GameTips();
		gotoxy(x + 6, y);
		cout << "无                ";
	}
	else {
		if (GameData[4] == 1) {
			gotoxy(x + 6, y + 2 * temp);
			cout << "[操作反转]        ";
			gotoxy(x + 6, y + 1 + 2 * temp);
			cout << "剩余时间:" << GameData[3] << "步    ";
			temp++;
		}
		if (GameData[7] == 1) {
			gotoxy(x + 6, y + 2 * temp);
			cout << "[变速]            ";
			gotoxy(x + 6, y + 1 + 2 * temp);
			cout << "剩余时间:" << GameData[6] << "步    ";
			temp++;
		}
	}
} 

void mod_reversal() {
	if (GameData[3] > 0 && GameData[4] != 0) {
		GameData[3]--;
	}
	if (GameData[3] == 0 && GameData[4] != 0) {
		GameData[4] = 0;
		mod_state_clear();
		mod_state();
	}

	short put = _rand(100 - GameSettingsData[22] / 5 + 1);
	if (GameData[2] == 0 && put == 0) {
		while (true) {
			short x = _rand(29) + 1, y = _rand(29) + 1;
			if (Maps[x][y] == 0) {
				Maps[x][y] = 7;
				GameData[2] = 1;
				gotoxy(StructureX + x * 2, StructureY + y);
				g_out(7, false);
				break;
			}
		}
	}
}

void mod_variable_speed() {
	if (GameData[6] > 0 && GameData[7] != 0) {
		GameData[6]--;
	}
	if (GameData[6] == 0 && GameData[7] != 0) {
		GameData[7] = 0;
		mod_state_clear();
		mod_state();
	}

	short put = _rand(100 - GameSettingsData[22] / 5 + 1);
	if (GameData[5] == 0 && put == 0) {
		while (true) {
			short x = _rand(29) + 1, y = _rand(29) + 1;
			if (Maps[x][y] == 0) {
				Maps[x][y] = 5;
				GameData[5] = 1;
				gotoxy(StructureX + x * 2, StructureY + y);
				g_out(5, false);
				break;
			}
		}
	}
}

void mod_build()
{
	if (1 == GameSettingsData[13])
	{
		mod_variable_speed();
	}
	if (1 == GameSettingsData[14])
	{
		mod_wall();
	}
	if (1 == GameSettingsData[15])
	{
		mod_reversal();
	}
	if (GameData[4]!=0||GameData[7]!=0) {
		mod_state();
	}

	if (_rand(2) == 0&&GameData[7]==1) {
		GameData[8] = _rand(2);
	}
	else {
		GameData[8] = -_rand(2);
	}
}

void redraw()
{
	system("cls");
	system("mode con cols=103 lines=34");
	draw();
	Snakestate();
	Gamestate();
	DirectState();
	moodstate();
	mod_state();
	GameTips();

	wait();
}

void direction()
{
	DirectTemp = Direct;
	unsigned long tstart, tend;
	int wait_times = GameSettingsData[22];
	tstart = GetTickCount();
	while (true)
	{
		if (GameData[3] > 0) {
			if (KEY_DOWN('S') || KEY_DOWN(VK_DOWN))
			{
				if (DirectTemp != __direct_down)
					Direct = __direct_up;
			}
			if (KEY_DOWN('A') || KEY_DOWN(VK_LEFT))
			{
				if (DirectTemp != __direct_left)
					Direct = __direct_right;
			}
			if (KEY_DOWN('W') || KEY_DOWN(VK_UP))
			{
				if (DirectTemp != __direct_up)
					Direct = __direct_down;
			}
			if (KEY_DOWN('D') || KEY_DOWN(VK_RIGHT))
			{
				if (DirectTemp != __direct_right)
					Direct = __direct_left;
			}
		}
		else {
			if (KEY_DOWN('W') || KEY_DOWN(VK_UP))
			{
				if (DirectTemp != __direct_down)
					Direct = __direct_up;
			}
			if (KEY_DOWN('D') || KEY_DOWN(VK_RIGHT))
			{
				if (DirectTemp != __direct_left)
					Direct = __direct_right;
			}
			if (KEY_DOWN('S') || KEY_DOWN(VK_DOWN))
			{
				if (DirectTemp != __direct_up)
					Direct = __direct_down;
			}
			if (KEY_DOWN('A') || KEY_DOWN(VK_LEFT))
			{
				if (DirectTemp != __direct_right)
					Direct = __direct_left;
			}
		}
		if (KEY_DOWN('P') || KEY_DOWN(VK_SPACE) || KEY_DOWN(VK_ESCAPE))
		{
			if (pause_menu() == true) {
				GameData[0] = 3;
				system("mode con cols=103 lines=34");
			}
			else
				redraw();
		}
		Sleep(1);
		tend = GetTickCount();
		if (GameData[7] == 1) {
			if ((tend - tstart + GameData[8]) > (1000 - SnakeEaten) / GameSettingsData[22]/2)
				break;
		}
		else {
			if (tend - tstart > (1000 - SnakeEaten) / GameSettingsData[22]/2)
				break;
		}
	}
	if (DirectTemp != Direct)
	{
		DirectState();
	}
}

void move_body()
{
	gotoxy(StructureX + SnakeBody[1].x * 2, StructureY + SnakeBody[1].y);
	cout << "  ";
	Maps[SnakeBody[1].x][SnakeBody[1].y] = 0;
	for (int i = 1; i <= SnakeLength; i++)
	{
		SnakeBody[i] = SnakeBody[i + 1];
	}
	if (Direct == __direct_up)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y - 1;
	}
	if (Direct == __direct_down)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y + 1;
	}
	if (Direct == __direct_left)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x - 1;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y;
	}
	if (Direct == __direct_right)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x + 1;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y;
	}
	gotoxy(StructureX + SnakeBody[SnakeLength - 1].x * 2, StructureX + SnakeBody[SnakeLength - 1].y);
	g_out(2, false);
	Maps[SnakeBody[SnakeLength - 1].x][SnakeBody[SnakeLength - 1].y] = 2;
	gotoxy(StructureX + SnakeBody[SnakeLength].x * 2, StructureX + SnakeBody[SnakeLength].y);
	g_out(3, false);
	Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y] = 3;
}

void eating_food(short id)
{
	playsound(5);
	SnakeLength++;
	switch (id) 
	{
	case 4:
		SimpleFoodEaten++;
		FoodAlready --;
		SnakeEaten++;
		SnakeScore += GameSettingsData[22];
		break;
	case 5:
		ModFoodEaten++;
		GameData[7] = 1;
		GameData[5] = 0;
		GameData[6] += 50 + GameSettingsData[22] / 2;
		SnakeEaten++;
		SnakeScore += GameSettingsData[22] * 3;
		break;
	case 7:
		ModFoodEaten++;
		GameData[4] = 1;
		GameData[2] = 0;
		GameData[3] += 50 + GameSettingsData[22] / 2;
		SnakeEaten++;
		SnakeScore += GameSettingsData[22]*3;
		GameTips();
		break;
	}
	//music
	Mood = 1;
	MoodTemp = 4;
	memset(MoodData, 0, sizeof(MoodData));
	moodstate();

	if (Direct == __direct_up)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y - 1;
	}
	if (Direct == __direct_down)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y + 1;
	}
	if (Direct == __direct_left)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x - 1;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y;
	}
	if (Direct == __direct_right)
	{
		SnakeBody[SnakeLength].x = SnakeBody[SnakeLength - 1].x + 1;
		SnakeBody[SnakeLength].y = SnakeBody[SnakeLength - 1].y;
	}
	gotoxy(StructureX + SnakeBody[SnakeLength - 1].x * 2, StructureX + SnakeBody[SnakeLength - 1].y);
	g_out(2, false);
	Maps[SnakeBody[SnakeLength - 1].x][SnakeBody[SnakeLength - 1].y] = 2;
	gotoxy(StructureX + SnakeBody[SnakeLength].x * 2, StructureX + SnakeBody[SnakeLength].y);
	g_out(3, false);
	Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y] = 3;

	Snakestate();
}

void move()
{
	if (SnakeLength >= 800)
	{
		GameData[0] = 1;
	}
	int x = 0;
	if (Direct == __direct_up)
	{
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 1 || Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 2 || Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 6)
		{
			x = 1;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 4)
		{
			x = 2;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 7)
		{
			x = 3;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y - 1] == 5)
		{
			x = 4;
		}
	}
	if (Direct == __direct_down)
	{
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 1 || Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 2 || Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 6)
		{
			x = 1;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 4)
		{
			x = 2;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 7)
		{
			x = 3;
		}
		if (Maps[SnakeBody[SnakeLength].x][SnakeBody[SnakeLength].y + 1] == 5)
		{
			x = 4;
		}
	}
	if (Direct == __direct_left)
	{
		if (Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 1 || Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 2 || Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 6)
		{
			x = 1;
		}
		if (Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 4)
		{
			x = 2;
		}
		if (Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 7)
		{
			x = 3;
		}
		if (Maps[SnakeBody[SnakeLength].x - 1][SnakeBody[SnakeLength].y] == 5)
		{
			x = 4;
		}
	}
	if (Direct == __direct_right)
	{
		if (Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 1 || Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 2 || Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 6)
		{
			x = 1;
		}
		if (Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 4)
		{
			x = 2;
		}
		if (Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 7)
		{
			x = 3;
		}
		if (Maps[SnakeBody[SnakeLength].x + 1][SnakeBody[SnakeLength].y] == 5)
		{
			x = 4;
		}
	}

	switch (x)
	{
	case 0:
		Walked++;
		move_body();
		break;
	case 1:
		GameData[0] = 2;//1.胜利 2.失败 3.逃跑
		break;
	case 2:
		eating_food(4);
		break;
	case 3:
		eating_food(7);
		break;
	case 4:
		eating_food(5);
		break;
	}
}

void show_score() 
{
	gotoxy(StructureX + 43, StructureY + 17);
	c_out("您的得分为：", 1);
	c_out(to_string(SnakeScore),1);
}

void make_players() {
	SetConsoleTitle(TEXT("贪吃蛇    玩家信息录入"));
	bool capslock = false;
	int size = 0;
	char name[20] = { "                   " }, temp;
	string playername;
	system("mode con cols=80 lines=31");
	system("cls");

	shade_out("[玩家信息录入]", 32, 10, 100, false);
	shade_out("请输入姓名:", 27, 12, 100, false);
	shade_out("剩余字数:", 27, 13, 100, false);
	shade_out("大写锁定:", 42, 13, 100, false);
	gotoxy(37, 13);
	cout << 15;
	gotoxy(52, 13);
	cout << "×";

	shade_out("Tips:请输入最大长度为15的英文字符,按下CapsLock开/关大小写锁定", 10, 15, 100, false);

	while (true) {
		if ((KEY_DOWN('A') || KEY_DOWN('B') || KEY_DOWN('C') || KEY_DOWN('D') || KEY_DOWN('E') ||
			KEY_DOWN('F') || KEY_DOWN('G') || KEY_DOWN('H') || KEY_DOWN('I') || KEY_DOWN('J') ||
			KEY_DOWN('K') || KEY_DOWN('L') || KEY_DOWN('M') || KEY_DOWN('N') || KEY_DOWN('O') ||
			KEY_DOWN('P') || KEY_DOWN('Q') || KEY_DOWN('R') || KEY_DOWN('S') || KEY_DOWN('T') ||
			KEY_DOWN('U') || KEY_DOWN('V') || KEY_DOWN('W') || KEY_DOWN('X') || KEY_DOWN('Y') ||
			KEY_DOWN('Z') || KEY_DOWN(VK_SPACE)) && size != 15)
		{
			if (KEY_DOWN('A'))
				temp = 'a';
			if (KEY_DOWN('B'))
				temp = 'b';
			if (KEY_DOWN('C'))
				temp = 'c';
			if (KEY_DOWN('D'))
				temp = 'd';
			if (KEY_DOWN('E'))
				temp = 'e';
			if (KEY_DOWN('F'))
				temp = 'f';
			if (KEY_DOWN('G'))
				temp = 'g';
			if (KEY_DOWN('H'))
				temp = 'h';
			if (KEY_DOWN('I'))
				temp = 'i';
			if (KEY_DOWN('J'))
				temp = 'j';
			if (KEY_DOWN('K'))
				temp = 'k';
			if (KEY_DOWN('L'))
				temp = 'l';
			if (KEY_DOWN('M'))
				temp = 'm';
			if (KEY_DOWN('N'))
				temp = 'n';
			if (KEY_DOWN('O'))
				temp = 'o';
			if (KEY_DOWN('P'))
				temp = 'p';
			if (KEY_DOWN('Q'))
				temp = 'q';
			if (KEY_DOWN('R'))
				temp = 'r';
			if (KEY_DOWN('S'))
				temp = 's';
			if (KEY_DOWN('T'))
				temp = 't';
			if (KEY_DOWN('U'))
				temp = 'u';
			if (KEY_DOWN('V'))
				temp = 'v';
			if (KEY_DOWN('W'))
				temp = 'w';
			if (KEY_DOWN('X'))
				temp = 'x';
			if (KEY_DOWN('Y'))
				temp = 'y';
			if (KEY_DOWN('Z'))
				temp = 'z';
			if (KEY_DOWN(VK_SPACE))
				temp = '-';
			if (capslock == true) {
				if (temp == '-')
					temp = '_';
				else
					temp = temp - 32;
			}
			size++;
			name[size] = temp;
			gotoxy(37, 13);
			cout << 15 - size << " ";
			gotoxy(37 + size, 12);
			cout << name[size];
			Sleep(200);
		}
		if (KEY_DOWN(VK_BACK) && size != 0) {
			size--;
			name[size + 1] = ' ';
			gotoxy(37, 13);
			cout << 15 - size << " ";
			gotoxy(37 + size + 1, 12);
			cout << " ";
			Sleep(150);
		}
		if (KEY_DOWN(VK_CAPITAL)) {
			gotoxy(52, 13);
			if (capslock == false) {
				capslock = true;
				cout << "√";
			}
			else {
				capslock = false;
				cout << "×";
			}
			Sleep(200);
		}
		if (KEY_DOWN(VK_RETURN))
			break;
	}
	if (size != 0) {
		playername = name;
	}
	else
	{
		playername = "?";
	}
	save_players(playername,SnakeScore);
}
void read_players() {
	shade_out("是否需要记录此次得分?", StructureX + 40, StructureY + 19, 50, false);
	shade_out("Y  |  N", StructureX + 47, StructureY + 20, 100, false);
	while (true){
		Sleep(50);
		if (KEY_DOWN('Y'))
		{
			make_players();
			break;
		}
		if (KEY_DOWN('N'))
		{
			break;
		}
	}
}


void game()
{
//de_bug_restart:
	game_prepare();
	make_food();
	draw();
	Snakestate();
	Gamestate();
	DirectState();
	moodstate();
	mod_state();
	GameTips();

	wait();

	SetConsoleTitle(TEXT("贪吃蛇    游戏中"));
	while (true)
	{
		gotoxy(0, 0);
		cout << FoodAlready;
		direction();
		move();
		make_food();


		mod_build();
		//		gotoxy(1,1);
		//		cout<<Mood<<" "<<MoodData[1];
		mood_check();
		mood_manage();
/*debug
		if (KEY_DOWN('L'))
		{
			de_bug_draw();
			Sleep(1000);
			draw();
		}
		if (KEY_DOWN('R'))
		{
			goto de_bug_restart;
		}
*/
		if (GameData[0] != 0)
		{
			break;
		}
	}

	GameStatisticsData[8] += SnakeScore;
	GameStatisticsData[7] += Walked;
	GameStatisticsData[5] += SimpleFoodEaten;
	GameStatisticsData[6] += ModFoodEaten;
	GameStatisticsData[1]+=1;
	switch (GameData[0])
	{
	case 1:
		GameStatisticsData[2]+=1;
		SetConsoleTitle(TEXT("贪吃蛇    胜利"));
		win();
		break;
	case 2:
		SetConsoleTitle(TEXT("贪吃蛇    失败"));
		GameStatisticsData[3]+=1;
		death();
		break;
	case 3:
		SetConsoleTitle(TEXT("贪吃蛇    逃跑??"));
		GameStatisticsData[4]+=1;
		escape();
		break;
	}


	show_score();
	
	shade_out("▼", 98, 16, 50, false);
	shade_out("■", 98, 17, 50, false);
	shade_out("保存中", 96, 18, 50, false);
	statistics_write();
	Sleep(300);
	shade_out_r("▼", 98, 16, 50, false, false);
	shade_out_r("■", 98, 17, 50, false, false);
	shade_out_r("保存中", 96, 18, 50, false, false);

	if (GameData[0] != 3 && SnakeScore>=1) {
		read_players();
		system("cls");
		system("mode con cols=80 lines=31");
		shade_out("▼", 76, 13, 50, false);
		shade_out("■", 76, 14, 50, false);
		shade_out("保存中", 74, 15, 50, false);
		statistics_write();
		Sleep(300);
		shade_out_r("▼", 76, 13, 50, false, false);
		shade_out_r("■", 76, 14, 50, false, false);
		shade_out_r("保存中", 74, 15, 50, false, false);
	}
	else
	{
		gotoxy(StructureX + 40, StructureY + 20);
		system("pause");
	}
	//	game_over();

	system("mode con cols=80 lines=31");
//	windowssize(80, 30);
}
