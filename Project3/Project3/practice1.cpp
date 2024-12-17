#include<iostream> //�����
#include<vector> //����
using namespace std;

#define TABLE_X 20 // X�� ���� = 20
#define TABLE_Y 30 // Y�� ���� = 30

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
        cout << "\t\t"; cout << "                ������ �����Ϸ��� �ƹ�Ű�� ��������.\n\n\n\n\n\n\n";
        cout << "\t\t\t"; cout << "                   TetrisGame1.0\n";
        getchar(); // Ű �Է��� ��ٸ�
        system("cls"); // �ܼ� â ����
	}
};


class GameTable {
private:
    int x;
    int y;
    vector<vector<int> > table; // ���� 2�����迭(������ �����ϴ�)
public:
    GameTable(int x, int y) {
        this->x = x; // ���� ���� ���� �浹�� ���ϱ� ���� ���� ��ü �ּҸ� ����Ű�� ������(this)�� ���
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp; //�ӽ�temp ���͸� ����
            for (int j = 0; j < x; j++) {
                temp.push_back(0); //���Ϳ� 0�߰� < ���̰�j�� ���� ����
            }
            table.push_back(temp); //table�� temp���͸� i�� �߰��� ���� ����
        }
        //���� �ڸ� ���� ��ĥ�� ���� 1�� ä��
        for (int i = 0; i < x; i++) {
            table[0][i] = 1;
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y - 1; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
    }
    /*������ �׸��� �Լ�*/
    void DrawGameTable() {
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1)cout << "��";
                else cout << "  "; // �� ĭ ����
            }
            cout << "\n";
        }
    }
};


int main() {
    system("mode con cols=100 lines=40 | title ��Ʈ���� ����"); // �ܼ�â ũ�� �� ���� ����
    GameTable gt(TABLE_X, TABLE_Y); //���� �� �׸��� ��ü ����
    MainMenu();
    gt.DrawGameTable(); // �������� �׸���.
    getchar();
	return 0;
}