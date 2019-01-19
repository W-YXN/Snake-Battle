#include "Snake.h"
#include "stdafx.h"
#include "CMyINI.h"
#include "INIReader.h"
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<cmath>
#include<string>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

bool AllisNum(string str);
void warning(string title, string st1, string st2, string st3, string answer);
void gotoxy(short x, short y);
void color_out(string st, short x);
void pogress_bar();
int _rand(int x);
int wifi_check(int x, int i);
void hide_mouse();
void v_settings_check();
void c_out(string st, short x);
void shade_out(string st, short x, short y, int s, bool z);
void graph_out(short id, short color, bool x);
void normal_settings_show(short id, short choose);
void windowssize(short x, short y);
void playsound(short id);


//======================================================================================



int StatisticsData[12];
int SettingsData[25];
struct playerInfo
{
	std::string name;
	int score;
};

string MapWay;
string audioWay;
playerInfo Player[12];
bool ColorEggDifficulty = false;
string SettingsTemplet[] =
{
	"",
	"color",
	"animation",
	"audio",
	"help",
	"color_snake_h",
	"color_snake_b",
	"color_fruit",
	"color_wall",
	"graph_snake_h",
	"graph_snake_b",
	"graph_fruit",
	"graph_wall",
	"mod_variable_speed",
	"mod_wall",
	"mod_reversal",
	"color_mod_variable_speed",
	"color_mod_wall",
	"color_mod_reversal",
	"graph_mod_variable_speed",
	"graph_mod_wall",
	"graph_mod_reversal",
	"difficulty",
	">two_player"
};
string StatisticsTemplet[] =
{
	"",
	"played",
	"winner",
	"loser",
	"deserter",
	"s_fruit_n",
	"m_fruit_n",
	"meter_n",
	"score_n",
	"level",
	"level_n",
	"Player",
	"P1n",
	"P2n",
	"P3n",
	"P4n",
	"P5n",
	"P6n",
	"P7n",
	"P8n",
	"P9n",
	"P10n",
	"P1s",
	"P2s",
	"P3s",
	"P4s",
	"P5s",
	"P6s",
	"P7s",
	"P8s",
	"P9s",
	"P10s"
};

//======================================================================================

int *settings_synchronization()
{
	return SettingsData;
}

int *statistics_synchronization()
{
	return StatisticsData;
}

void sort_players() {
	for (int i = 1;i <= 11;i++) {
		for (int j = 1;j <= 10;j++) {
			if (Player[j].score < Player[j + 1].score)
				swap(Player[j], Player[j + 1]);
		}
	}
}

void check_settings()
{
	gotoxy(0, 0);
	for (int i = 1; i <= 23; i++)
	{
		cout << SettingsData[i] << " ";
	}
	cout << "|";
	v_settings_check();
}

void statistics_write()
{
	hide_mouse();
	ofstream statistics;
	statistics.open("statistics.ini", ios::trunc);
	statistics << "[statistics]" << endl;
	for (int i = 1; i <= 11; i++)
	{
		statistics << StatisticsTemplet[i] << "=" << StatisticsData[i] << endl;
	}
	statistics << "[Players]" << endl;
	int s = 0;
	for (int i = 12; i <= 21; i++) {
		++s;
		statistics << StatisticsTemplet[i] << "=" << Player[s].name << endl;
	}
	s = 0;
	for (int i = 22; i <= 31; i++) {
		++s;
		statistics << StatisticsTemplet[i] << "=" << Player[s].score << endl;
	}
	statistics.close();

	
}

void settings_write()
{
	hide_mouse();
	ofstream settings;
	settings.open("settings.ini", ios::trunc);
	settings << "[settings]" << endl;
	for (int i = 1; i <= 23; i++)
	{
		settings << SettingsTemplet[i] << "=" << SettingsData[i] << endl;
	}
	settings.close();
}

void statistics_initialization()
{
	hide_mouse();
	for (int i = 1; i <= 10; i++)
	{
		Player[i].name = "空";
		Player[i].score = 0;
	}
	ofstream statistics;
	statistics.open("statistics.ini", ios::trunc);
	statistics << "[statistics]" << endl
		<< "played=0" << endl
		<< "winner=0" << endl
		<< "loser=0" << endl
		<< "deserter=0" << endl
		<< "s_fruit_n=0" << endl
		<< "m_fruit_n=0" << endl
		<< "meter_n=0" << endl
		<< "score_n=0" << endl
		<< "level=0" << endl
		<< "level_n=0" << endl
		<< "Player=0" << endl
		<< "[Players]" << endl
		<< "P1n=" << endl
		<< "P2n=" << endl
		<< "P3n=" << endl
		<< "P4n=" << endl
		<< "P5n=" << endl
		<< "P6n=" << endl
		<< "P7n=" << endl
		<< "P8n=" << endl
		<< "P9n=" << endl
		<< "P10n=" << endl
		<< "P1s=0" << endl
		<< "P2s=0" << endl
		<< "P3s=0" << endl
		<< "P4s=0" << endl
		<< "P5s=0" << endl
		<< "P6s=0" << endl
		<< "P7s=0" << endl
		<< "P8s=0" << endl
		<< "P9s=0" << endl
		<< "P10s=0" << endl;
	statistics.close();
}

void statistics_read_wrong()
{
	hide_mouse();
	Sleep(200);
	warning("                文件错误                ", ".\\“statistics.ini”已经被更改，无法读取", "               即将初始化               ", "", "");
	gotoxy(26, 20);
	color_out("正在初始化“statistics.ini”                              ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	statistics_initialization();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(26, 20);
	color_out("正在读取统计                              ", 1);
}

void statistics_read()
{
start:
	hide_mouse();
	int temp;
	INIReader reader("statistics.ini");
	if (reader.ParseError() < 0) {
		statistics_read_wrong();
		goto start;
	}
	for (int i = 1;i <= 11;i++) {
		temp = reader.GetInteger("statistics", StatisticsTemplet[i],-1);
		if (temp == -1) {
			statistics_read_wrong();
			goto start;
		}
		StatisticsData[i] = temp;
	}
	string st;
	int s = 0;
	for (int i = 12;i <= 21;i++) {
		st = reader.Get("Players", StatisticsTemplet[i], "UNKNOWN");
		if (st == "UNKNOWN") {
			statistics_read_wrong();
			goto start;
		}
		Player[++s].name = st;
	}
	s = 0;
	for (int i = 22;i <= 31;i++) {
		temp = reader.GetInteger("Players", StatisticsTemplet[i], -1);
		if (temp == -1) {
			statistics_read_wrong();
			goto start;
		}
		Player[++s].score = temp;
	}
	void print_settings_synchronization();
	void video_settings_synchronization();
}

void settings_initialization()
{
	hide_mouse();
	ofstream settings;
	settings.open("settings.ini", ios::trunc);
	settings << "[settings]" << endl
		<< "color=1" << endl
		<< "animation=1" << endl
		<< "audio=1" << endl
		<< "help=1" << endl
		<< "color_snake_h=1" << endl
		<< "color_snake_b=1" << endl
		<< "color_fruit=1" << endl
		<< "color_wall=1" << endl
		<< "graph_snake_h=1" << endl
		<< "graph_snake_b=2" << endl
		<< "graph_fruit=3" << endl
		<< "graph_wall=4" << endl
		<< "mod_variable_speed=0" << endl
		<< "mod_wall=0" << endl
		<< "mod_reversal=0" << endl
		<< "color_mod_variable_speed=1" << endl
		<< "color_mod_wall=1" << endl
		<< "color_mod_reversal=1" << endl
		<< "graph_mod_variable_speed=6" << endl
		<< "graph_mod_wall=4" << endl
		<< "graph_mod_reversal=7" << endl
		<< "difficulty=1" << endl
		<< ">two_player=0" << endl;
	settings.close();
}

void settings_read_wrong()
{
	Sleep(200);
	warning("                文件错误                ", " .\\“settings.ini”已经被更改，无法读取 ", "               即将初始化               ", "", "");
	gotoxy(26, 20);
	color_out("正在初始化“settings.ini”                              ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	settings_initialization();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(26, 20);
	color_out("正在读取设置                              ", 1);
}

void settings_read()
{
start:
	hide_mouse();
	int temp;
	INIReader reader("settings.ini");
	if (reader.ParseError() < 0) {
		settings_read_wrong();
		goto start;
	}
	for (int i = 1;i <= 23;i++) {
		temp = reader.GetInteger("settings", SettingsTemplet[i],-1);
		if (temp == -1) {
			settings_read_wrong();
			goto start;
		}
		SettingsData[i] = temp;
	}
}

void normal_settings_set(short id, short choose)
{
	playsound(2);
	int x = 23 + 6 + 18, y = 12;
	gotoxy(x - 2, y + choose);
	cout << ">";
	while (true)
	{
		if (KEY_DOWN('W') || KEY_DOWN(VK_UP))
		{
			if (5 == id || 6 == id || 7 == id || 8 == id || 16 == id || 17 == id || 18 == id)
			{
				SettingsData[id]++;
				if (SettingsData[id]>15)
					SettingsData[id] = 0;
				normal_settings_show(id, choose);
				Sleep(200);
			}
			if (9 == id || 10 == id || 11 == id || 12 == id || 19 == id || 20 == id || 21 == id)
			{
				SettingsData[id]++;
				if (SettingsData[id]>108)
					SettingsData[id] = 1;
				normal_settings_show(id, choose);
				Sleep(200);
			}
			if ((id == 1 || id == 2 || id == 3 || id == 4 || id == 13 || id == 14 || id == 15 || id == 20) && SettingsData[id] == 0)
			{
				gotoxy(x, y + choose);
				cout << "√   ";
				SettingsData[id] = 1;
				Sleep(200);
			}
			else if ((id == 1 || id == 2 || id == 3 || id == 4 || id == 13 || id == 14 || id == 15 || id == 20) && SettingsData[id] == 1)
			{
				gotoxy(x, y + choose);
				cout << "×   ";
				SettingsData[id] = 0;
				Sleep(200);
			}
			if (id == 22 && SettingsData[22] != 10 && ColorEggDifficulty == false)
			{
				SettingsData[22]++;
				gotoxy(x, y + choose);
				cout << SettingsData[id] << "   ";
				Sleep(200);
			}
			if (id == 22 && SettingsData[22] != 99 && ColorEggDifficulty == true)
			{
				SettingsData[22]++;
				gotoxy(x, y + choose);
				cout << SettingsData[id] << "   ";
				Sleep(200);
			}
		}
		if (KEY_DOWN('S') || KEY_DOWN(VK_DOWN))
		{
			if (5 == id || 6 == id || 7 == id || 8 == id || 16 == id || 17 == id || 18 == id)
			{
				SettingsData[id]--;
				if (SettingsData[id]<0)
					SettingsData[id] = 15;
				normal_settings_show(id, choose);
				Sleep(200);
			}
			if (9 == id || 10 == id || 11 == id || 12 == id || 19 == id || 20 == id || 21 == id)
			{
				SettingsData[id]--;
				if (SettingsData[id]<1)
					SettingsData[id] = 108;
				normal_settings_show(id, choose);
				Sleep(200);
			}
			if ((id == 1 || id == 2 || id == 3 || id == 4 || id == 13 || id == 14 || id == 15 || id == 20) && SettingsData[id] == 0)
			{
				gotoxy(x, y + choose);
				cout << "√   ";
				SettingsData[id] = 1;
				Sleep(200);
			}
			else if ((id == 1 || id == 2 || id == 3 || id == 4 || id == 13 || id == 14 || id == 15 || id == 20) && SettingsData[id] == 1)
			{
				gotoxy(x, y + choose);
				cout << "×   ";
				SettingsData[id] = 0;
				Sleep(200);
			}
			if (id == 22 && SettingsData[22] != 1)
			{
				SettingsData[22]--;
				gotoxy(x, y + choose);
				cout << SettingsData[id] << "   ";
				Sleep(200);
			}
		}
		if (KEY_DOWN('A') || KEY_DOWN(VK_LEFT) || KEY_DOWN(VK_BACK))
		{
			playsound(3);
			break;
		}
	}
	gotoxy(x - 2, y + choose);
	cout << " ";
	Sleep(500);
}

void statistics_player_print(short Choose, bool Video)
{
	string st;
	hide_mouse();
	short x = 23, y = 12, temp = 0;
	if (true == Video)
	{
		gotoxy(x + 10, y - 2);
		c_out("   排行榜   ", 1);
		Sleep(50);
		for (int i = Choose; i <= Choose + 7; i++)
		{
			temp++;
			gotoxy(x, y + temp);
			cout << "                           ";
		}
		temp = 0;
		for (int i = Choose; i <= Choose + 7; i++)
		{
			temp++;
			gotoxy(x + 2, y + temp);
			st = to_string(temp) + ":";
			shade_out(st, x + 2, y + temp, 50, false);
		}
	}
	else
	{
		gotoxy(x, y);
		for (int i = Choose; i <= Choose + 7; i++)
		{
			temp++;
			if (i <= StatisticsData[11])
			{
				gotoxy(x, y + temp);
				int z = 25 - Player[i].name.size();
				for (int j = 1; j <= z; j++)
					cout << " ";
				gotoxy(x + 2, y + temp);
				c_out(to_string(i), 1);
				c_out(":", 1);
				c_out(Player[i].name, 1);
				gotoxy(x + 26, y + temp);
				cout << Player[i].score<<"    ";
			}
			else
			{
				gotoxy(x, y + temp);
				for (int j = 1; j <= 25; j++)
					cout << " ";
				gotoxy(x + 2, y + temp);
				c_out(to_string(i), 1);
				c_out(":", 1);
				c_out("空位", 1);
				gotoxy(x + 26, y + temp);
				cout << "×   ";
			}
		}
	}
}

void save_players(string name, short score)
{
	if (StatisticsData[11] != 10)
		StatisticsData[11]++;
	Player[11].name = name;
	Player[11].score = score;
	sort_players();
}