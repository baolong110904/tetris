#include <iostream>
#include <string>
#include <unordered_map>
// For testing, remove later
#include "../Windows/Windows.cpp"
// #include "../Game/Game.cpp"
// ==========
#include <random>
#include <fstream>

using namespace std;
int current_option;
const string options[8] = { "Play", "Help", "Exit", "Back", "Exit"};
class Menu{
public:
    static void mainScreen(){
			unordered_map<string, void(*)()> function_map = {
			{options[0], playMenu},
			{options[1], helpScreen},
			{options[2], exitScreen},
			// {options[3], playGame},
			{options[3], goBack},
			{options[4], exitScreen}
		};
		//Windows::playSound(BACKGROUND_SOUND);
		printAnimation();
		bool loadMenu = 1;
		while (true)
		{
			if (loadMenu)
				mainMenu();
			switch (Windows::getConsoleInput())
			{
			case 2:
				changeOption(0, 1);
				loadMenu = 0;
				break;
			case 5:
				changeOption(1, 1);
				loadMenu = 0;
				break;
			case 6:
				if (current_option == 0)
					loadMenu = 0;
				else
					loadMenu = 1;
				function_map[options[current_option]]();
				break;
			default:
				//Windows::playSound(ERROR_SOUND);
				loadMenu = 0;
			}
		}

		Windows::clearConsole();
    }								//Màn hình chính
	static void mainMenu(){
		Windows::setColor("brightwhite", "red");
		Windows::clearConsole();
		printLogo();
		//printOptionsBoard();
		current_option = 3;
		changeOption(0, 0);
		changeOption(0, 0);
		changeOption(0, 1);
	}									//Menu
	static void playMenu(){
		current_option = 7;
		changeOption(0, 0);
		changeOption(0, 0);
		changeOption(0, 1);
	}	
    static void helpScreen(){
		Windows::hideCursor();
		Windows::setColor("brightwhite", "black");
		Windows::clearConsole();
		int left = 5, top = 2, width = 85, height = 23;
		int line1 = 6, line2 = 19, line3 = 20, line4 = 15;
		printRectangle(left, top, width, height);
		Windows::gotoXY(left + 1, line1);
		for (int i = 0; i < width; i++)
		{
			putchar(196);
		}
		Windows::gotoXY(left + 1, line2);
		for (int i = 0; i < width; i++)
		{
			putchar(196);
		}
		Windows::gotoXY(left + 1, line4);
		for (int i = 0; i < width; i++)
		{
			putchar(196);
		}
		for (int i = 1; i < height; i++)
		{
			Windows::gotoXY(line3, top + i);
			putchar(179);
		}
		Windows::gotoXY(line3, line1);
		putchar(197);
		Windows::gotoXY(line3, line2);
		putchar(197);

		Windows::setColor("brightwhite", "blue");
		Windows::gotoXY(left + 3, top + 2);
		cout << "Moves:";
		Windows::gotoXY(left + 20, top + 1);
		putchar(249); cout << "Up:    W, up arrow";
		Windows::gotoXY(left + 52, top + 1);
		putchar(249); cout << "Down:  S, down arrow";
		Windows::gotoXY(left + 20, top + 3);
		putchar(249); cout << "Left:  A, left arrow";
		Windows::gotoXY(left + 52, top + 3);
		putchar(249); cout << "Right: D, right arrow";


		Windows::gotoXY(left + 3, top + 8);
		cout << "Rules:";
		Windows::gotoXY(left + 17, top + 5);
		int left1 = left + 17;
		putchar(249); cout << " The Matching Game (commonly known as the Pikachu Puzzle Game)";
		Windows::gotoXY(left1, top + 6);
		cout << " includes a board of multiple cells, each of which presents a figure.";
		Windows::gotoXY(left1, top + 8);
		putchar(249); cout << " The player finds and matches a pair of cells that contain the same";
		Windows::gotoXY(left1, top + 9);
		cout << " figure and connect each other in some particular pattern.";
		Windows::gotoXY(left1, top + 11);
		putchar(249); cout << " A legal match will make the two cells disappear. The game ends when";
		Windows::gotoXY(left1, top + 12);
		cout << " all matching pairs are found.";

		Windows::gotoXY(left + 3, top + 15);
		cout << "Scoring:";
		Windows::setColor("brightwhite", "green");
		Windows::gotoXY(left1 + 10, top + 14);
		putchar(249); cout << " I Matching: +1 BTC";
		Windows::setColor("brightwhite", "green");
		Windows::gotoXY(left1 + 40, top + 14);
		putchar(249); cout << " L Matching: +2 BTC";
		Windows::setColor("brightwhite", "green");
		Windows::gotoXY(left1 + 10, top + 15);
		putchar(249); cout << " Z Matching: +3 BTC";
		Windows::gotoXY(left1 + 40, top + 15);
		putchar(249); cout << " U Matching: +4 BTC";
		Windows::setColor("brightwhite", "red");
		Windows::gotoXY(left1 + 10, top + 16);
		putchar(249); cout << " Not Matched: -2 BTC";
		Windows::setColor("brightwhite", "red");
		Windows::gotoXY(left1 + 40, top + 16);
		putchar(249); cout << " Move suggestion: -2 BTC";

		Windows::setColor("brightwhite", "blue");
		Windows::gotoXY(left + 3, top + 20);
		cout << "Developers:";
		Windows::gotoXY(left + 31, top + 19);
		cout << "Dev 1: Tran Tung Lam (21127337)";
		Windows::gotoXY(left + 31, top + 21);
		cout << "Dev 2: Le Minh (21127645)";

		Windows::setColor("brightwhite", "black");
		printRectangle(45, 27, 8, 2);
		Windows::setColor("brightwhite", "red");
		Windows::gotoXY(43, 28);
		putchar(175);
		Windows::gotoXY(48, 28);
		cout << "Back";
		Windows::gotoXY(56, 28);
		putchar(174);
		while (Windows::getConsoleInput() != 6)
		{
			//Windows::playSound(ERROR_SOUND);
		}
	}								//Màn hình hướng dẫn
	static void exitScreen(){
		Windows::hideCursor();
		Windows::setColor("brightwhite", "black");
		Windows::clearConsole();
		Windows::setColor("brightwhite", "black");
		Menu::printRectangle(34, 13, 35, 8);
		Menu::printRectangle(37, 18, 7, 2);
		Menu::printRectangle(60, 18, 6, 2);
		Windows::setColor("brightwhite", "red");
		Windows::gotoXY(0, 0);
		printLogo();
		Windows::gotoXY(42, 16);
		cout << "Do you want to exit?";
		string str[2] = { "Yes", "No" };
		int left[] = { 35,40,47,58,63,69 }, word[] = { 32,32,175,174 }, color[] = { BLACK, RED }, top = 19;
		bool choice = 0;
		bool loop = 1;
		auto print1 = [&]()
		{
			int i = 0;
			while (i < 2)
			{
				//Windows::playSound(MOVE_SOUND);
				Windows::setColor("brightwhite", "blue");
				Windows::gotoXY(left[choice * 3], top);        putchar(word[i * 2]);
				Windows::gotoXY(left[choice * 3 + 1], top);    cout << str[choice];
				Windows::gotoXY(left[choice * 3 + 2], top);    putchar(word[i * 2 + 1]);
				if (!i++)
					choice = !choice;
			}
		};
		print1();
		while (loop)
		{
			int key = Windows::getConsoleInput();
			if ((key == 3 && choice == 1) || (key == 4 && choice == 0))
			{
				print1();
			}
			else if (key == 6)
			{
				if (!choice)
				{
					Windows::setColor("black", "brightwhite");
					Windows::clearConsole();
					exit(0);
				}
				return;
			}
			else
			{
				//Windows::playSound(ERROR_SOUND);
			}
		}
	}								//Màn hình thoát
	// static void playGame(){
	// 	Game g({10, 28});
	// 	g.run();
	// }
    static void printLogo(){
		unsigned char logo[] = R"(

		 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. 
		| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
		| |  _________   | || |  _________   | || |  _________   | || |  _______     | || |     _____    | || |    _______   | |
		| | |  _   _  |  | || | |_   ___  |  | || | |  _   _  |  | || | |_   __ \    | || |    |_   _|   | || |   /  ___  |  | |
		| | |_/ | | \_|  | || |   | |_  \_|  | || | |_/ | | \_|  | || |   | |__) |   | || |      | |     | || |  |  (__ \_|  | |
		| |     | |      | || |   |  _|  _   | || |     | |      | || |   |  __ /    | || |      | |     | || |   '.___`-.   | |
		| |    _| |_     | || |  _| |___/ |  | || |    _| |_     | || |  _| |  \ \_  | || |     _| |_    | || |  |`\____) |  | |
		| |   |_____|    | || | |_________|  | || |   |_____|    | || | |____| |___| | || |    |_____|   | || |  |_______.'  | |
		| |              | || |              | || |              | || |              | || |              | || |              | |
		| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
		'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'                                                                  
	)";
	cout << logo;
	Windows::gotoXY(38, 0);
	Windows::setColor("brightwhite", "blue");
	cout << "Tran Tung Lam - Le Minh";
	Windows::gotoXY(40, 1);
	cout << "21127337 - 21127165";
	Windows::gotoXY(38, 8);
	Windows::setColor("brightwhite", "blue");
// 	cout << R"(
//   _____  _  _  ___   __  __    _  _____  ___  _  _  ___  _  _   ___    ___    _    __  __  ___ 
//  |_   _|| || || __| |  \/  |  /_\|_   _|/ __|| || ||_ _|| \| | / __|  / __|  /_\  |  \/  || __|
//    | |  | __ || _|  | |\/| | / _ \ | | | (__ | __ | | | | .` || (_ | | (_ | / _ \ | |\/| || _| 
//    |_|  |_||_||___| |_|  |_|/_/ \_\|_|  \___||_||_||___||_|\_| \___|  \___|/_/ \_\|_|  |_||___|
// 	)";
	}
    static void goBack() {}	
    //static void printOptionsBoard();						//In ra các bảng lựa chọn
	
	static int getRandomInt(int begin, int end)
	{
		static random_device rd;
		static mt19937 mt(rd());
		uniform_int_distribution<int> dist(0, end);
		return dist(mt);
	}
	static string getRandomColor() {
		const string colors[] = {
			"black", "blue", "green", "aqua", "red", "purple", "yellow", "white",
			"gray", "light blue", "light green", "light aqua", "light red", "light purple", "light yellow", "bright white"
		};

		return colors[getRandomInt(0, 15)];
	}
	static void printAnimation(){
		Windows::setColor("brightwhite", "black");
		Windows::clearConsole();
		char symbolpos[] = { 5,0,19,0,33,0,47,0,61,0,75,0,89,0,0,103,5,13,19,
								13,33,13,47,13,61,13,75,13,89,13,13,103,13,18,26,18,40,18,
								54,18,68,18,82,18,18,96,5,24,19,24,33,24,47,24,61,24,75,24,
								89,24,24,103,12,30,26,30,40,30,54,30,68,30,82,30,96,30 };
		int n = (sizeof(symbolpos) / sizeof(symbolpos[0])) / 2;
		bool turn = 0;
		unsigned char symbol[] = { 4,15 };

		int color[] = { LIGHT_AQUA, AQUA, LIGHT_BLUE, BLUE, LIGHT_PURPLE, PURPLE };
		int colorcount = 0;
		int loop = 10;
		while (loop--)
		{
			for (int i = 0; i < n; i += 2)
			{
				Windows::setColor("brightwhite", getRandomColor());
				Windows::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
				putchar(symbol[turn]);
			}
			for (int i = 1; i < n; i += 2)
			{
				Windows::setColor("brightwhite", getRandomColor());
				Windows::gotoXY(symbolpos[i * 2], symbolpos[i * 2 + 1]);
				putchar(symbol[!turn]);
			}
			Windows::gotoXY(0, 0);
			printLogo();
			colorcount++;
			turn = !turn;
			Sleep(250);
		}
	}							//In hiệu ứng mở đầu
	static void printRectangle(int left, int top, int width, int height){
		Windows::gotoXY(left, top);
		putchar(218);
		for (int i = 0; i < width; i++)
			putchar(196);
		putchar(191);

		int i = 0;
		for (; i < height; i++)
		{
			Windows::gotoXY(left, top + i + 1);
			putchar(179);
			Windows::gotoXY(left + width + 1, top + i + 1);
			putchar(179);
		}

		Windows::gotoXY(left, top + i);
		putchar(192);
		for (i = 0; i < width; i++)
			putchar(196);
		putchar(217);
	}			//Vẽ hình chữ nhật
	static void changeOption(bool direction, bool flag){
		int top = 21;
		if ((direction == 0 && (current_option == 4 || current_option == 0))
			|| (direction == 1 && (current_option == 3 || current_option == 7)))
		{
			//Windows::playSound(ERROR_SOUND);
			return;
		}
		Windows::setColor("brightwhite", "black");
		Windows::gotoXY(50 - (int)options[current_option].length() / 2, top + current_option % 4 * 2);
		cout << options[current_option];
		if (flag)
		{
			Windows::gotoXY(40, top + current_option % 4 * 2);
			putchar(32);
			Windows::gotoXY(60, top + current_option % 4 * 2);
			putchar(32);
		}
		(direction == 1) ? current_option++ : current_option--;
		if (flag)
		{
			//Windows::playSound(MOVE_SOUND);
			Windows::setColor("brightwhite", "red");
			Windows::gotoXY(40, top + current_option % 4 * 2);
			putchar(175);
			Windows::gotoXY(50 - (int)options[current_option].length() / 2, top + current_option % 4 * 2);
			cout << options[current_option];
			Windows::gotoXY(60, top + current_option % 4 * 2);
			putchar(174);
		}
	}

};

