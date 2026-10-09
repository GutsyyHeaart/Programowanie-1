#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//STRUCTURY
typedef struct {
	char name[30];
	int hp;
	int maxhp;
	int level;
	int power;
} Player;

typedef struct {
	char name[20];
	int hp;
	int maxhp;
	int power;
} Enemy;

//OVERLOADING
void printMessage(const char* msg) {
	printf(">> %s\n", msg);
}

void printMessage(int val) {
	printf(">> Number: %d\n", val);
}

//PRACA Z PLIKAMI
void saveGame() {
	FILE* file = NULL;
}

bool loadGame(Player* p, int* level) {
	FILE* file = NULL;
	errno_t err = fopen_s(&file, "save.txt", "r");
	if (err == 0 && file != NULL) {
		int loadHp, loadLevel;
		if (fscanf_s(file, "%d %d", &loadHp, &loadLevel) == 2) {
			p->hp == loadHp;
			p->level == loadLevel;
			*level = loadLevel;
			fclose(file);
			return true;
		}
		fclose(file);
	}
	return false;
}

void printMap(char map[5][5]) {
	printf("\n--- Dungeon Map ---\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 20; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

int main() {

	char gameMap[5][20] = {
		{'@', '.', '.', 'E', '#', '.', '.', '.', '.', '.', '.', '.', '#', 'E', '.', '.', '.', '.', '.', 'E'},
		{'.', '#', '.', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '.', '.'},
		{'.', '#', '.', '.', '.', '.', '.', 'E', '#', '.', '#', '.', '.', '.', '.', '.', '#', 'E', '#', '.'},
		{'.', '#', '#', '#', '#', 'E', '#', '.', '#', '.', '#', '#', '#', '#', 'E', '#', '#', '.', '#', '.'},
		{'.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', 'E', '.', '.', '.', '#', '.', '.', '.', 'X'}
	};

	//MAIN MENU
	printf("WELCOME TO THE GAME");
	printf("\n1.New game\n2.Load game\nChoice: ");
	int mainMenuChoice;
	scanf_s("%d", &mainMenuChoice);

	if (mainMenuChoice = 2) {
		loadGame(&player, &currentLevel);
	}
}