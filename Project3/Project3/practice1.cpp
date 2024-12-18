#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib> // rand
#include <ctime> // time
using namespace std;

/*
���� = 0
�� = 1
�� = 2
*/

#define TABLE_X 20 //��Ʈ���� �� x �� ����
#define TABLE_Y 38 //��Ʈ���� �� y �� ����

#define LEFT 75 // ��
#define RIGHT 77  // ��
#define UP 72 // ��
#define DOWN 80 // ��

/*Ŀ�� �����(0) or ���̱�(1) */
void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

/*�ܼ� Ŀ�� ��ġ �̵�*/
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
/*1�� ��*/
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },

};
/*2�� ��*/
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },

};
/*3�� ��*/
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*4�� ��*/
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },

};
/*5�� ��*/
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },

};

/*�� �θ� Ŭ����*/
class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x��ǥ
    int y; // y��ǥ
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]�� 4���� ���� ǥ��
public:
    int getShape(int rotationCount, int y, int x) {
        return shape[rotationCount][y][x];
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getRotationCount() {
        return rotationCount;
    }
    void down() { // �� �� ĭ �Ʒ� �̵�
        y++;
    }
    void left() { // �� �� ĭ ���� �̵�
        x--;
    }
    void right() { // �� �� ĭ ������ �̵�
        x++;
    }
    void rotate() { // �� ȸ��
        rotationCount = (rotationCount + 1) % 4; // 0 , 1, 2 , 3 ���� ȸ�� ǥ��
    }
};
/*1�� �� Ŭ����*/
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*2�� �� Ŭ����*/
class Block2 : public Block {
public:
    Block2() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*3�� �� Ŭ����*/
class Block3 : public Block {
public:
    Block3() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*4�� �� Ŭ����*/
class Block4 : public Block {
public:
    Block4() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};
/*5�� �� Ŭ����*/
class Block5 : public Block {
public:
    Block5() {
        x = TABLE_X / 2 - 3; // �ʱ� ���� �� �� �߾� ������ ����
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k]; // �� ��ü ���� ����
                }
            }
        }
    }
};

/*���� �޴� Ŭ����*/
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
/*��Ʈ���� ���� ���̺� Ŭ����*/
class GameTable {
private:
    int x; // ����
    int y; // ����
    Block* blockObject;
    vector<vector<int> > table; // ���� 2�����迭(������ �����ϴ�)
public:
    GameTable(int x, int y) {
        blockObject = nullptr;
        this->x = x; // ���� ���� ���� �浹�� ���ϱ� ���� ���� ��ü �ּҸ� ����Ű�� ������(this)�� ���
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
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
                else if (table[i][j] == 2) cout << "��";
                else cout << "  "; // �� ĭ ����
            }
            cout << "\n";
        }
    }
    /*�� ����*/
    void createBlock() {
        srand((unsigned int)time(NULL));
        int select = rand() % 5 + 1; // 1 ~ 5 ��
        if (select == 1) blockObject = new Block1(); // 1�� �� ����
        else if (select == 2)blockObject = new Block2(); // 2�� �� ����
        else if (select == 3)blockObject = new Block3(); // 3�� �� ����
        else if (select == 4)blockObject = new Block4(); // 4�� �� ����
        else if (select == 5)blockObject = new Block5(); // 5�� �� ����

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                //�� ��ü�� ���̺� ������Ʈ
            }
        }
    }
    /*�� �̵�*/
    void MoveBlock(int key) {
        /*���̺��� �� ��ü �����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2) { // ���� ���̸�
                    table[Y][X] = 0; // ���̺��� �����
                }
            }
        }
        if (key == DOWN) blockObject->down(); // ���� ���ڷ� ���� key�� �Ʒ� �����̸� ���� �Ʒ��� �̵�
        else if (key == LEFT) blockObject->left();  // ���� ���ڷ� ���� key�� ���� �����̸� ���� �������� �̵�
        else if (key == RIGHT) blockObject->right(); // ���� ���ڷ� ���� key�� ������ �����̸� ���� ���������� �̵�

        /*�̵��� �� ���¸� ���̺� ����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 0) { //������� ��쿡 �̵��� �� ������ ���̺� ����
                    table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                }
            }
        }
    }
    /*�� ȸ��*/
    void RotateBlock() {
        blockObject->rotate(); // ���� ȸ��
        /*���̺��� �� ��ü �����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 2) { // ���� ���̸�
                    table[Y][X] = 0; // ���̺��� �����
                }
            }
        }
        /*ȸ���� �� ���¸� ���̺� ����*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (table[Y][X] == 0) { //������� ��쿡 �̵��� �� ������ ���̺� ����
                    table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                }
            }
        }
    }
};
/*���� ���� Ŭ����*/
class GamePlay {
private:
    GameTable* gt;
public:
    GamePlay() {
        gt = new GameTable(TABLE_X, TABLE_Y); //���� �� �׸��� ��ü ����
        gt->createBlock(); // �ʱ� �� ����
        gt->DrawGameTable(); // �������� �׸���.
        while (true) { // ����Ű �Է� �̺�Ʈ
            int nSelect;
            if (_kbhit()) {
                nSelect = _getch();
                if (nSelect == 224) {
                    nSelect = _getch();
                    switch (nSelect) {
                    case UP: // ȭ��ǥ �� ������ ��
                        gt->RotateBlock(); // ���� 90�� ȸ�� 
                        gotoxy(0, 0); //system("cls") �Ⱦ��� (0, 0)���� Ŀ�� �̵� ��
                        gt->DrawGameTable(); // ����� 
                        break;
                    case DOWN: // ȭ��ǥ �Ʒ� ������ ��
                        gt->MoveBlock(DOWN); // ���� �� ĭ �Ʒ��� �̵�
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case LEFT: // ȭ��ǥ ���� ������ ��
                        gt->MoveBlock(LEFT); // ���� �� ĭ �������� �̵�
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    case RIGHT: // ȭ��ǥ ������ ������ ��
                        gt->MoveBlock(RIGHT); // ���� �� ĭ ���������� �̵�
                        gotoxy(0, 0);
                        gt->DrawGameTable();
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    ~GamePlay() { // ���� ���� �̺�Ʈ
        delete gt;
    }
};
int main(void) {
    CursorView(false); // �ܼ� ȭ�� Ŀ�� ���� 
    system("mode con cols=100 lines=40 | title ��Ʈ���� ����"); // �ܼ�â ũ�� �� ���� ����
    GameTable gt(TABLE_X, TABLE_Y);
    MainMenu(); // ���� �޴� �׸��� ������ ȣ��
    GamePlay(); // ���� �÷���
    getchar();


    return 0;
}
