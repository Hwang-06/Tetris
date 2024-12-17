#include<iostream> //입출력
#include<vector> //벡터
using namespace std;

#define TABLE_X 20 // X축 길이 = 20
#define TABLE_Y 30 // Y축 길이 = 30

class MainMenu {
public:
	MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << "@@@@@@@@@@@@  @@@@@@@@@   @@@@@@@@@@@  @@@@@@@@   @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @                @       @      @   @   @          \n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @     @    @   @@@@@@@@@@@\n";
        cout << "\t\t"; cout << "      @       @                @       @ @ @      @             @\n";
        cout << "\t\t"; cout << "      @       @                @       @     @    @             @\n";
        cout << "\t\t"; cout << "      @       @@@@@@@@@        @       @      @   @   @@@@@@@@@@@\n\n\n\n\n";
        cout << "\t\t"; cout << "                게임을 시작하려면 아무키나 누르세요.\n\n\n\n\n\n\n";
        cout << "\t\t\t"; cout << "                   TetrisGame1.0\n";
        getchar(); // 키 입력을 기다림
        system("cls"); // 콘솔 창 정리
	}
};


class GameTable {
private:
    int x;
    int y;
    vector<vector<int> > table; // 동적 2차원배열(정수를 저장하는)
public:
    GameTable(int x, int y) {
        this->x = x; // 변수 명이 같아 충돌을 피하기 위해 현재 객체 주소를 가르키는 포인터(this)를 사용
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp; //임시temp 벡터를 생성
            for (int j = 0; j < x; j++) {
                temp.push_back(0); //벡터에 0추가 < 길이가j인 벡터 생성
            }
            table.push_back(temp); //table에 temp벡터를 i개 추가해 뼈대 생성
        }
        //가장 자리 뼈대 색칠할 곳을 1로 채움
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }
    /*게임판 그리는 함수*/
    void DrawGameTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1)cout << "▦";
                else cout << "  "; // 두 칸 띄우기
            }
            cout << "\n";
        }
    }
};


int main() {
    system("mode con cols=100 lines=40 | title 테트리스 게임"); // 콘솔창 크기 및 제목 설정
    GameTable gt(TABLE_X, TABLE_Y); //게임 판 그리기 객체 생성
    MainMenu();
    gt.DrawGameTable(); // 게임판을 그린다.
    getchar();
	return 0;
}