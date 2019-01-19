#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<sstream>
#include<vector>
using namespace std;

bool AllisNum(string st);
void color_out(string st, short x);

string WrongInformation[9][10] =
{

	{
		"",
		"未知的指令，请查询帮助(help)",
		"参数错误个数",
	},
	{
		"",
		"错误的参数个数",
	},
	{
		"",
		"错误的参数个数",
		"无效的数值",
		"参数不在范围内(1~30)",
		"参数无效",
		"标签缺少目标",
		"目标无效",
		"目标参数不在范围内(1~900)",
	},
	{
		"",
		"错误的参数个数",
		"参数无效",
		"参数不在范围内(1~30)",
	},
	{
		"",
		"错误的参数个数",
		"参数无效",
		"参数不在范围内(0~65535)",
		"参数不在范围内(1~900)",
		"参数不在范围内(1~100|default)",
	},
	{
		"",
		"错误的参数个数",
		"参数无效",
	},
	{
		"",
		"错误的参数个数",
		"参数无效", 
	},
	{
		"",
		"错误的参数个数",
		"参数无效",
		"参数不在范围内(0~65535)",
	},
};
string RightCommand[9][2] =
{
	{
	"quit|exit                                   ",
	"[退出命令台]"
	},
	{
	"help                                        ",
	"[查询帮助]"
	},
	{
	"teleport <标签> <值:X> <值:Y>               ",
	"[传送]"
	},
	{
	"setblock <标签> <值:X> <值:Y>               ",
	"[放置]"
	},
	{
	"set <标签> <值>                             ",
	"[设置]"
	},
	{
	"game <值>                                   ",
	"[游戏]"
	},
	{
	"rule <标签> <值:true|false>                 ",
	"[规则]"
	},
	{
	"effect <标签> <值:step|clear>               ",
	"[效果]"
	},
};

//===================命令信号/次级判断区===================

int to_int(string st) {
	stringstream x;
	x << st;
	int s;
	x>>s;
	return s;
}

void command_wrong(string space,int id,string strall,string wrong ,int wrongid) {
	if (space == "main") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(wrong, 4);color_out("\"", 2); color_out("<=" + WrongInformation[0][1] + '\n' + '\n', 5);break;
		case 2:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[0][2] + ",预期1个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[0][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "teleport") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[2][1] + ",预期4个参数,现有"+to_string(wrongid)+"个"+'\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0]+'\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0]+'\n', 11);break;
		case 3:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][3] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0] + '\n' + '\n', 11);break;
		case 4:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][4] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0] + '\n' + '\n', 11);break;
		case 5:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][5] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0] + '\n' + '\n', 11);break;
		case 6:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][6] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0] + '\n' + '\n', 11);break;
		case 7:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[2][7] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[2][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "setblock") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[3][1] + ",预期4个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[3][0] + '\n' + '\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[3][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[3][0] + '\n' + '\n', 11);break;
		case 3:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[3][3] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[3][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "set") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[4][1] + ",预期3个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[4][0] + '\n' + '\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[4][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[4][0] + '\n' + '\n', 11);break;
		case 3:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[4][3] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[4][0] + '\n' + '\n', 11);break;
		case 4:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[4][4] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[4][0] + '\n' + '\n', 11);break;
		case 5:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[4][5] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[4][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "game") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[5][1] + ",预期2个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[5][0] + '\n' + '\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[5][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[5][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "rule") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[6][1] + ",预期3个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[6][0] + '\n' + '\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[6][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[6][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "effect") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[7][1] + ",预期3个参数,现有" + to_string(wrongid) + "个" + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[7][0] + '\n' + '\n', 11);break;
		case 2:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[7][2] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[7][0] + '\n' + '\n', 11);break;
		case 3:color_out("[错误]", 10);color_out(space + "中第" + to_string(wrongid) + "个参数:\"", 2);color_out(wrong, 4); color_out("\"", 2);color_out("<=" + WrongInformation[7][3] + '\n', 5); color_out("      命令格式:", 2); color_out(RightCommand[7][0] + '\n' + '\n', 11);break;
		}
	}
	if (space == "help") {
		switch (id) {
		case 1:color_out("[错误]", 10);color_out("\"", 2);color_out(strall, 4);color_out("\"", 2);color_out("<=" + WrongInformation[1][1] + ",预期1个参数,现有" + to_string(wrongid) + "个" + '\n', 5);color_out("      命令格式:", 2); color_out(RightCommand[1][0] + '\n' + '\n', 11);break;
		}
	}
}

//=======================命令识别区========================

void command_teleport(string key[],string old) {
	bool target[901];
	memset(target, false, sizeof(target));
	int x, y, block = 1;

	if (key[2].substr(0, 5) != "snake") {
		command_wrong("teleport", 4, old, key[2], 2);
		return;
	}
	if (key[2] == "snake") {
		target[1] = true;
	}
	else {
		int length = key[2].size();
		if ((key[2].find('{') == 5 && key[2].find('}') == length - 1) != 1) {
			command_wrong("teleport", 4, old, key[2], 2);
			return;
		}
		if (length == 7) {
			command_wrong("teleport", 5, old, key[2], 2);
			return;
		}
		string label = key[2].substr(6, length - 7);

		while (label.size() != 0) {
			int labelsize = label.size();
			if (labelsize < 7) {
				command_wrong("teleport", 6, old, label, 2);
				return;
			}
			if (label.substr(0, 6) != "block=") {
				command_wrong("teleport", 6, old, label, 2);
				return;
			}
			int end = label.find(',');
			string temp;
			if (end != label.npos) {
				temp = label.substr(0, end);
				label.erase(0, end+1);
			}
			else {
				temp = label;
				label.erase(0, sizeof(label));
			}
			string num = temp.substr(6, sizeof(temp)  - 6);
			int lian = num.find('-');
			if (lian != num.npos) {
				if (num.size() - lian <= 1) {
					command_wrong("teleport", 6, old, temp, 2);
					return;
				}
				string nas = num.substr(0, lian);
				string nbs = num.substr(lian+1, num.size() - 1);
				if (AllisNum(nas) && AllisNum(nbs) != true) {
					command_wrong("teleport", 6, old, temp, 2);
					return;
				}
				int na = to_int(nas), nb = to_int(nbs);
				if (na > nb) {
					command_wrong("teleport", 6, old, temp, 2);
					return;
				}
				if (na <1||na>900||nb<1||nb>900) {
					command_wrong("teleport", 6, old, temp, 2);
					return;
				}
				for (int i = na;i <= nb;i++) {
					target[i] = true;
				}
			}
			else {
				if (AllisNum(num) == false) {
					command_wrong("teleport", 6, old, temp, 2);
					return;
				}
				if (to_int(num) < 1 || to_int(num) > 900) {
					command_wrong("teleport", 7, old, temp, 2);
					return;
				}
				target[to_int(num)] = true;
			}
		}
	}

	if (AllisNum(key[3]) == false) {
		command_wrong("teleport", 2, old, key[3], 3);
		return;
	}
	if (AllisNum(key[4]) == false) {
		command_wrong("teleport", 2, old, key[4], 4);
		return;
	}
	x = to_int(key[3]);
	if (x < 1 || x>30) {
		command_wrong("teleport", 3, old, key[3], 3);
		return;
	}
	y = to_int(key[4]);
	if (y < 1 || y>30) {
		command_wrong("teleport", 3, old, key[4], 4);
		return;
	}

	//===============
	//执行命令
	int total=0;
	for (int i = 1;i <= 900;i++) {
		if (target[i] == true) {
			//
			total++;
		}
	}

	color_out("[完成]", 10);color_out("已将"+to_string(total)+"个目标移动至("+to_string(x)+","+to_string(y)+")"+'\n'+'\n', 2);
	//===============
}

void command_setblock(string key[], string old) {
	int x, y,id;

	if (key[2] == "fruit") {
		id = 1;
	}
	else if (key[2] == "wall") {
		id = 2;
	}
	else if (key[2] == "mod:variablespeed") {
		id = 3;
	}
	else if (key[2] == "mod:wall") {
		id = 4;
	}
	else if (key[2] == "mod:reversal") {
		id = 5;
	}
	else {
		command_wrong("setblock", 2, old, key[2], 2);
		return;
	}

	if (AllisNum(key[3]) == false) {
		command_wrong("setblock", 2, old, key[3], 3);
		return;
	}
	if (AllisNum(key[4]) == false) {
		command_wrong("setblock", 2, old, key[4], 4);
		return;
	}
	x = to_int(key[3]);
	if (x < 1 || x>30) {
		command_wrong("setblock", 3, old, key[3], 3);
		return;
	}
	y = to_int(key[4]);
	if (y < 1 || y>30) {
		command_wrong("setblock", 3, old, key[4], 4);
		return;
	}


	//===============
	//执行命令

	color_out("[完成]", 10);color_out("已在("+to_string(x)+","+to_string(y)+")处放置了\""+key[2]+"\"" + '\n' + '\n', 2);
	//===============
}

void command_set(string key[], string old) {
	int x, id;

	if (key[2] == "score") {
		id = 1;
	}
	else if (key[2] == "eaten") {
		id = 2;
	}
	else if (key[2] == "speed") {
		id = 3;
	}
	else {
		command_wrong("set", 2, old, key[2], 2);
		return;
	}

	if (AllisNum(key[3]) == false && id != 3) {
		command_wrong("set", 2, old, key[3], 3);
		return;
	}
	else if (key[3] != "default"&&id == 2) {
		command_wrong("set", 2, old, key[3], 3);
		return;
	}
	if (id == 3) {
		if (key[3] == "default")
			x = -1;
		else {
			x = to_int(key[3]);
			if (x < 1 || x>100) {
				command_wrong("set", 5, old, key[3], 3);
				return;
			}
		}
	}
	else {
		x = to_int(key[3]);
		if ((x < 0 || x >65535) && id == 1) {
			command_wrong("set", 3, old, key[3], 3);
			return;
		}
		if ((x < 0 || x >900) && id == 2) {
			command_wrong("set", 4, old, key[3], 3);
			return;
		}
	}

	//===============
	//执行命令
	color_out("[完成]", 10);color_out("已将\"" +key[2]+"\"设置为\""+key[3]+"\"" + '\n' + '\n', 2);
	//===============
}

void command_game(string key[], string old) {
	int  id;

	if (key[2] == "win") {
		id = 1;
	}
	else if (key[2] == "lose") {
		id = 2;
	}
	else if (key[2] == "escape") {
		id = 3;
	}
	else if (key[2] == "leave"|| key[2] == "quit") {
		id = 4;
	}
	else if (key[2] == "pause") {
		id = 5;
	}
	else if (key[2] == "run") {
		id = 6;
	}
	else {
		command_wrong("game", 2, old, key[2], 2);
		return;
	}


	//===============
	//执行命令
	color_out("[完成]", 10);color_out("已启动游戏条件\"" + key[2] + "\"" + '\n' + '\n', 2);
	//===============
}

void command_rule(string key[], string old) {
	int work, id;

	if (key[2] == "godmod") {
		id = 1;
	}
	else if (key[2] == "effect") {
		id = 2;
	}
	else {
		command_wrong("rule", 2, old, key[2], 2);
		return;
	}

	if (key[3] == "true") {
		work = 1;
	}
	else if (key[3] == "false") {
		work = 0;
	}
	else {
		command_wrong("rule", 2, old, key[3], 2);
	}

	//===============
	//执行命令
	color_out("[完成]", 10);color_out("已将\"" + key[2] + "\"设置为\"" + key[3] + "\"" + '\n' + '\n', 2);
	//===============
}

void command_effect(string key[], string old) {
	int step, id;

	if (key[2] == "mod:variablespeed") {
		id = 1;
	}
	else if (key[2] == "mod:reversal") {
		id = 2;
	}
	else {
		command_wrong("effect", 2, old, key[2], 2);
		return;
	}

	if (key[3] == "clear") {
		step = -1;
	}
	else {
		if (AllisNum(key[3]) == false) {
			command_wrong("effect", 2, old, key[3], 3);
			return;
		}
		step = to_int(key[3]);
		if (step < 0 || step>65535) {
			command_wrong("effect", 3, old, key[3], 3);
			return;
		}
	}

	//===============
	//执行命令
	if (step == -1) {
		color_out("[完成]", 10);color_out("已清除所有效果\n\n", 2);
	}
	else {
		color_out("[完成]", 10);color_out("已给予\"" + key[2] + "\"效果" + key[3] + "步" + '\n' + '\n', 2);
	}
	//===============
}


void command_distinguish(string key[], int total,string old) {
	if (key[1] == "") {
		return;
	}
	else if (key[1] == "teleport") {
		if (total == 4) {
			command_teleport(key,old);
		}
		else {
			command_wrong("teleport", 1, old, "", total);
		}
	}
	else if (key[1] == "setblock") {
		if (total == 4) {
			command_setblock(key,old);
		}
		else {
			command_wrong("setblock", 1, old, "", total);
		}
	}
	else if (key[1] == "set") {
		if (total == 3) {
			command_set(key, old);
		}
		else {
			command_wrong("set", 1, old, "", total);
		}
	}
	else if (key[1] == "game") {
		if (total == 2) {
			command_game(key, old);
		}
		else {
			command_wrong("game", 1, old, "", total);
		}
	}
	else if (key[1] == "rule") {
		if (total == 3) {
			command_rule(key, old);
		}
		else {
			command_wrong("rule", 1, old, "", total);
		}
	}
	else if (key[1] == "effect") {
		if (total == 3) {
			command_effect(key, old);
		}
		else {
			command_wrong("effect", 1, old, "", total);
		}
	}
	else if (key[1] == "help") {
		if (total == 1) {
			for (int i = 1;i <= 7;i++) {
				color_out(to_string(i)+' ', 2);
				color_out(RightCommand[i][0], 11);
				color_out(RightCommand[i][1] + '\n', 7);
			}
			color_out(to_string(8)+' ', 2);
			color_out(RightCommand[0][0], 11);
			color_out(RightCommand[0][1] + '\n' +'\n', 7);
		}
		else {
			command_wrong("help", 1, old, "", total);
		}
	}
	else if (key[1] == "quit"||key[1]=="exit") {
		command_wrong("main", 2, old, "", total);
	}
	else
	{
		command_wrong("main",1,old,key[1],0);
	}
}

//=======================命令主要函数======================

void command_getkey(const string&str, std::vector<string>&words) {
	words.clear();

	typedef string::size_type string_size;
	string_size i = 0;

	while (i != str.size())
	{
		while (i != str.size() && isspace(str[i]))
			++i;

		string_size j = i;
		while (j != str.size() && !isspace(str[j]))
			++j;
		if (i != j)
		{
			words.push_back(str.substr(i, j - i));
			i = j;
		}
	}
}

int command() {
	cout << "命令测试" << endl;
	vector<string> keytemp;
	string st;
	while (true) {
		color_out(">", 1);
		getline(cin, st);
		if (st == "quit"||st=="exit")
			return 0;
		string key[10];
		command_getkey(st, keytemp);
		int total = keytemp.size();
		for (int i = 0;i < total;i++) {
			key[i + 1] = keytemp[i];
		}
		command_distinguish(key, total, st);
	}
	return 0;
}
