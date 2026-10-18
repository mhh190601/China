#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

int main() {
	//ANSI 指令
	SetConsoleOutputCP(65001); //UTF-8

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(hOut, &mode);
	SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	int W, H; //高度和宽度
	int r, g, b, _r, _g, _b; //RGB起点和终点

	cout << "Width:" << endl;
	cin >> W;
	cout << "Height:"<< endl;
	cin >> H;
	cout << "r(start):" << endl;
	cin >> r;
	cout << "g(start):" << endl;
	cin >> g;
	cout <<  "b(start):" << endl;
	cin >> b;
	cout << "r(end):" << endl;
	cin >> _r;
	cout << "g(end):" << endl;
	cin >> _g;
	cout << "b(end):" << endl;
	cin >> _b;

	char gqjkl[6][4] = { "国","庆","节","快","乐","!" };  //国庆节快乐

	//计数（每行多少个字符，即爱心内部）
	for (int i = 0; i < H; i++) {
		int linecount = 0;
		for (int j = 0; j < W; j++) {
			double x = (j - W / 2.0) / (W / 2.0) * 1.6;
			double y = (H / 2.0 - i) / (H / 2.0) * 1.3;

			double t = x * x + y * y - 1;
			bool inside = (t * t * t - x * x * y * y * y <= 0); //爱心公式

			if (inside == 1) {
				linecount++;
			}
		}
		
		int rem = linecount % 6; //多余的字符
		int k = 0; //记已经填入的字
		
		for (int j = 0;j < W; j++) {
			double x = (j - W / 2.0) / (W / 2.0) * 1.6;
			double y = (H / 2.0 - i) / (H / 2.0) * 1.3;
			double t = x * x + y * y - 1;
			bool inside = (t * t * t - x * x * y * y * y <= 0);

			if (inside) {
				double f = (y + 1) / 2.3; //将值缩减至0-1
				if (f < 0) {
					f = 0;
				}
				if (f > 1) {
					f = 1;
				}

				if (r > 255) r = 255;
				else if (r < 0) r = 0;

				if (g > 255) g = 255;
				else if (g < 0) g = 0;

				if (b > 255) b = 255;
				else if (b < 0) b = 0;

				if (_r > 255) _r = 255;
				else if (_r < 0) _r = 0;

				if (_g > 255) _g = 255;
				else if (_g < 0) _g = 0;

				if (_b > 255) _b = 255;
				else if (_b < 0) _b = 0;

				int R = (int)(r + (_r - r) * f);
				int G = (int)(g + (_g - g) * f);
				int B = (int)(b + (_b - b) * f);
				
				if (k < linecount - rem) { //判断本行足够容下6个字的空间
					cout << "\033[38;2;" << R << ";" << G << ";" << B << "m"; //RGB输出
					cout << gqjkl[k % 6]; 
					cout << "\033[0m"; //结束
				}
				else { //不够则用！代替
					cout << "\033[38;2;" << R << ";" << G << ";" << B << "m";
					cout << "! ";
					cout << "\033[0m";
				}
				k++;
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
		this_thread::sleep_for(chrono::milliseconds(150));
	}

	return 0;
}


