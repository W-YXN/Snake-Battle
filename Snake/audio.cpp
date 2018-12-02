#include"stdafx.h"
#include"Snake.h"
#include"INIReader.h"
#include<iostream>
#include<fstream>
#include<string>
#include<io.h>
#include<sstream>
#include<Windows.h>
#include<cmath>
#include <thread>
#pragma comment(lib, "winmm");

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

using namespace std;

//======================================================================================

void hide_mouse();
void warning(string title, string st1, string st2, string st3, string answer);
void wrong(string title, string st1, string st2, string st3, string answer);
void wrong_cover();
void gotoxy(short x, short y);
void color_out(string st, short x);
void pogress_bar();
int _rand(int x);
int *settings_synchronization();
void c_out(string st, short x);
void menu_back_print(short id);
void game_state();
void help_print(short id, short x);
void main_menu_video();
void shade_out(string st, short x, short y, int s, bool z);

//======================================================================================

struct audioInof {
	string name;
}AudioName[11];

short AudioData[10];
int *AudioSettingsData;
string AudioNames[11] = {
	"",
	"start.wav",//1.��ʼ
	"enter.wav",//2.����
	"back.wav",//3.����
	"exciting.wav",//4.�˷�
	"eating.wav",//5.��ʳ
	"danger.wav",//6.Σ��
	"lose.wav",//7.ʧ��
	"win.wav",//8.ʤ��
	"death.wav",//9.����
	"escape.wav"//10.����
};
//======================================================================================

void audio_settings_synchronization()
{
	AudioSettingsData = settings_synchronization();
}

void _playsound(WCHAR *str) {
	PlaySound(str, NULL, SND_FILENAME | SND_SENTRY);
}
void playsound(short id) {
	if (AudioSettingsData[3] == 0)
		return;
	string sstr;
	sstr = ".\\Audio\\";
	sstr += AudioName[AudioData[2]].name;
	sstr += "\\";
	sstr += AudioNames[id];
	stringstream ss;
	char s[100];
	memset(s, ' ', sizeof(s));
	ss << sstr;
	ss >> s;
	WCHAR wszClassName[256];
	memset(wszClassName, 0, sizeof(wszClassName));
	MultiByteToWideChar(CP_ACP, 0, s, strlen(s) + 1, wszClassName,
		sizeof(wszClassName) / sizeof(wszClassName[0]));
	thread t(_playsound, wszClassName);
	t.detach();
}

void audio_initialization() {
	ofstream audio;
	audio.open("audio.ini", ios::trunc);
	audio << "//�����������Ƶ�⣬���巽ʽ����İ���������10����" << endl
		<< "[audio]" << endl
		<< "total=1" << endl
		<< "choice=1" << endl
		<< "1=default" << endl;
	audio.close();
}

bool Integrity_check(string st) {
	//����ͨ������
	//return true;
	string str;
	char c[100];
		for (int i = 1;i <= 10;i++) {
			memset(c, ' ', sizeof(c));
			str = ".\\Audio\\";
			str += st;
			str += "\\";
			str += AudioNames[i];
			stringstream ss;
			ss << str;
			ss >> c;
			if ((_access(c, 0)) == -1)
				return false;
		}
	return true;
}

void audio_tidy() {
	ofstream audio;
	audio.open("audio.ini", ios::trunc);
	audio << "//�����������Ƶ�⣬���巽ʽ����İ���������10����" << endl
		<< "[audio]" << endl
		<< "choice=" << to_string(AudioData[2]) << endl
		<< "total=" << to_string(AudioData[1]) << endl;
	for (int i = 1;i <= AudioData[1];i++) {
		audio << to_string(i) << "=" << AudioName[i].name << endl;
	}
	audio.close();
}

void audio_read_wrong()
{
	Sleep(200);
	warning("                �ļ�����                ", " .\\��audio.ini���Ѿ������ģ��޷���ȡ ", "               ������ʼ��               ", "", "");
	gotoxy(24, 20);
	color_out("      ���ڳ�ʼ����audio.ini��                     ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	audio_initialization();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("          ���ڶ�ȡ��Ƶ��                         ", 1);
}

void audio_read_warning(short s)
{
	Sleep(200);
	warning("                �ļ�����                ", "     .\\��audio.ini���д��󲿷�   ", "             ����"+to_string(s)+"��ʧЧ����     ", "", "");
	gotoxy(24, 20);
	color_out("       ��������audio.ini��                     ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	audio_tidy();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	gotoxy(24, 20);
	color_out("          ���ڶ�ȡ��Ƶ��                        ", 1);
}

void audio_no_warning(){
	Sleep(200);
	wrong("                �ļ���ʧ                ", "           û�п��õ���Ƶ��   ", "     ��Ƶ���رգ��������Ժ����п���     ", "", "");
	gotoxy(30, 17);
	system("pause");
	wrong_cover();
	return;
}

void audio_read()
{
start:
	hide_mouse();
	short total,truetotal=0;
	bool rewrite = false;
	string st;
	INIReader reader("audio.ini");
	if (reader.ParseError() < 0) {
		audio_read_wrong();
		goto start;
	}

	total= (short)reader.GetInteger("audio", "total" , -1);
	if (total == -1) {
		audio_read_wrong();
		goto start;
	}
	AudioData[2] = (short)reader.GetInteger("audio", "choice", -1);
	if (AudioData[2] == -1) {
		audio_read_wrong();
		goto start;
	}

	if (total > 10){
		total = 10;
	rewrite = true;
	}

	if (AudioData[2] < 1) {
		AudioData[2] = 1;
		rewrite = true;
	}

	short i = 0;
	while (true) {
		if (i+1 > total)
			break;
		else
			i++;
		st = reader.Get("audio", to_string(i), "UNKNOWN");
		if (st == "UNKNOWN") {
			rewrite = true;
		}
		else if (Integrity_check(st) == false) {
			rewrite = true;
		}
		else {
			truetotal++;
			AudioName[truetotal].name = st;
		}
	}
	if (truetotal < 1)
	{
		audio_no_warning();
		AudioSettingsData[3] = 0;
		return;
	}
	AudioData[1] = truetotal;
	if (rewrite == true) {
		audio_read_warning(total-truetotal);
		goto start;
	}
	AudioData[1] = truetotal;
}

bool audio_open() {
	system("cls");
	gotoxy(24, 20);
	color_out("       ���ڶ�ȡ��Ƶ��                         ", 1);
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
	pogress_bar();
	Sleep(_rand(50) + 50);
start:
	hide_mouse();
	short total, truetotal = 0;
	bool rewrite = false;
	string st;
	INIReader reader("audio.ini");
	if (reader.ParseError() < 0) {
		audio_read_wrong();
		goto start;
	}

	total = (short)reader.GetInteger("audio", "total", -1);
	if (total == -1) {
		audio_read_wrong();
		goto start;
	}
	AudioData[2] = (short)reader.GetInteger("audio", "choice", -1);
	if (AudioData[2] == -1) {
		audio_read_wrong();
		goto start;
	}

	if (total > 10) {
		total = 10;
		rewrite = true;
	}

	if (AudioData[2] < 1) {
		AudioData[2] = 1;
		rewrite = true;
	}

	short i = 0;
	while (true) {
		if (i + 1 > total)
			break;
		else
			i++;
		st = reader.Get("audio", to_string(i), "UNKNOWN");
		if (st == "UNKNOWN") {
			rewrite = true;
		}
		else if (Integrity_check(st) == false) {
			rewrite = true;
		}
		else {
			truetotal++;
			AudioName[truetotal].name = st;
		}
	}
	if (truetotal < 1)
	{
		audio_no_warning();
		AudioSettingsData[3] = 0;
		return false;
	}
	AudioData[1] = truetotal;
	if (rewrite == true) {
		audio_read_warning(total - truetotal);
		goto start;
	}
	AudioData[1] = truetotal;
	return true;
}

void audio_DIY_menu() {
	main_menu_video();
	hide_mouse();
	SetConsoleTitle(TEXT("̰����    �Զ���·��"));
	gotoxy(4, 26);
	c_out(" Tips:����W/S�л�ѡ��,C���沢������һ��                                   ", 2);
	short choose = AudioData[2];
	short id = 14;
	bool temp = true;
	int x = 23, y = 12;
	int y1 = 10;
	int x1 = 33;
	help_print(0, 1);

	shade_out(" �Զ���·�� ", x1, y1, 50, false);
	shade_out("��ǰѡ��:", x, y + 1, 50,false);
	short k = 1;
	for (short i = choose;i <= (short)min(7, AudioData[1]);i++) {
		shade_out(AudioName[i].name, x + 10, y + k, 50, false);
		k++;
	}
	for (int i = min(7, AudioData[1])+1;i <= 7;i++) {
		gotoxy(x + 10, y + i);
		cout << "                    ";
	}
	while (temp)
	{
		gotoxy(x1, y1 + 1);
		cout << "    ("<<AudioData[2] << "/" << AudioData[1] << ")";
		game_state();
		Sleep(200);
		bool redraw = false;
		short z = 1;
		while (true)
		{
			if (KEY_DOWN('W') || KEY_DOWN('D') || KEY_DOWN(VK_RETURN) || KEY_DOWN('S') || KEY_DOWN('C') || KEY_DOWN(VK_BACK) || KEY_DOWN(VK_DOWN) || KEY_DOWN(VK_UP) || KEY_DOWN(VK_RIGHT))
			{
				if ((KEY_DOWN('W') || KEY_DOWN(VK_UP)) && choose !=1 )
				{
					choose--;
					AudioData[2]--;
					redraw = true;
					break;
				}
				if ((KEY_DOWN('S') || KEY_DOWN(VK_DOWN)) && choose != AudioData[1])
				{
					choose++;
					AudioData[2]++;
					redraw = true;
					break;
				}
				if (KEY_DOWN('C') || KEY_DOWN(VK_BACK))
				{
					playsound(3);
					temp = false;
					break;
				}
			}

		}
		if (redraw == true) {
			z = 1;
			int i = AudioData[2];
			while (true) {
				gotoxy(x + 10, y + z);
				c_out(AudioName[i].name, 1);
				for (int j = 1;j <= 20 - AudioName[i].name.size();j++)
					cout << " ";
				i++, z++;
				if (z > 7 || i > AudioData[1])
					break;
			}
			for ( i = z;i <= 7;i++) {
				gotoxy(x + 10, y + i);
				cout << "                    ";
			}
		}
	}

	help_print(0, 0);
}

void audio_settings() {
	if (AudioSettingsData[3] == 0) {
		wrong("                δ��������              ", "           �����Զ����迪������         ", "                                        ", "", "           Y:����      N:ȡ��           ");
		while (true)
		{
			if (KEY_DOWN('Y'))
			{
				playsound(2);
				if (audio_open() == true) {
					audio_DIY_menu();
					AudioSettingsData[3] = 1;
				}
				break;
			}
			if (KEY_DOWN('N'))
			{
				playsound(3);
				break;
			}
		}
	}
	else {
		audio_DIY_menu();
	}
	return;
}
