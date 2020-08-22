#define _CRT_SECURE_NO_WARNINGS
#define TreeHigh 19
#define DinoY 11
#define TreeDistance 80
#define CRT_SECURE_NO_WARNINGS
#define CLS system("cls")

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>


void SetConsoleView(); // �ܼ�â ũ�� �����ϱ�
void gotoXY(int x, int y); // X��ǥ�� Y��ǥ �����ϱ�
void DinoSour(int Dinoleg); // ����׸� �׸���
void Tree1(int TreePosition); // ù��° ���� ��� �׸���
void Tree2(int TreePostin1); // �ι�° ���� ��� �׸���
char KeyInput(); // ���ڸ� �޴� �Լ�


int DinolegsSwing = true; // ������ �ٸ� �ʱ갪�� true�� ���� �Լ��� ����


int main(void)
{
    int TreeX2_Flag = 0; // �ι�° Ʈ���� ������ �ֱ� ����
    int DinosourHigh = DinoY; // ������ ���̸� 11�� ����
    int TreeX1 = TreeDistance; //ù��° ������ �Ÿ��� 80���� ����
    int TreeX2 = TreeDistance; // �ι�° ������ �Ÿ��� 80���� ����
    int Jumping = false; // ó�� ������ ���� false�� �ΰ� ����
    int Bottom = true; // ������ �ٴڿ� �־�߸� ������ �� �� ����
    int JumpingLevel = false; // ������ �ִ񰪿� ���ߴٸ� �������� ���� ����
    int StartOrder = 0;
    int UsersOrder = 0;
    int Score = 0;
    int End = 0;
    char UserAgain;
    SetConsoleView();

    // ���� �޴� ȭ��
    if (StartOrder == 0)
    {
        printf("         ============================================================================\n");
        printf("         |                                                                          |\n");
        printf("         |        ====        ==========    || ��        ||      ==========         |\n");
        printf("         |        ||   ��         | |       ||  ��       ||     /          ��       |\n");
        printf("         |        ||    ��        | |       ||   ��      ||    /            ��      |\n");
        printf("         |        ||     |        | |       ||    ��     ||   |              |      |\n");
        printf("         |        ||     |        | |       ||     ��    ||   |              |      |\n");
        printf("         |        ||    /         | |       ||      ��   ||   ��             /      |\n");
        printf("         |        ||   /          | |       ||       ��  ||    ��           /       |\n");
        printf("         |        ====         ==========   ||        �� ||       =========         |\n");
        printf("         |                                                                          |\n");
        printf("         |         =======        ===========      =====        =====   ======      |\n");
        printf("         |       /               /            ��      |            |    |      ��   |\n");
        printf("         |      |               /              ��     |            |    |       |   |\n");
        printf("         |       ��            |                |     |            |    |       /   |\n");
        printf("         |         =======     |                |     |            |    |======     |\n");
        printf("         |                 |    ��             /      |            |    | ��        |\n");
        printf("         |                 /     ��           /       ��           /    |   ��      |\n");
        printf("         |                /        ==========          ��         /     |     ��    |\n");
        printf("         |        ========                               ========                   |\n");
        printf("         ============================================================================\n");

    }

    // ���� ���� �޴�
    printf("                           1. ��  ��  ��                    2. ��  ��  ��  ��                  \n");
    printf("                                                  ");
Start:
    scanf("%d", &UsersOrder);

    // ���� ����ڰ� 2�� �Է��ߴٸ� ������ ����
    if (UsersOrder == 2)
    {
        printf("������ �����մϴ�.\n");
        exit(1);
    }
    // ����ڰ� 1�� �Է����ٸ� ������ ����
    if (UsersOrder == 1)
    {
AgainStart:
        printf("��  ��  ��....");
        Sleep(1000); // ������ �����ϱ� �� �ܼ��� ��� ����
        CLS;
        while (true)
        {
            Score++; // ������ ���� ����
            if (KeyInput() == 'w'&&Bottom) //���� w�� �Է��ϰ� ������ �ٴڿ� ��ġ�Ѵٸ� ���� ����
            {
                Bottom = false; //������ �Ѵٸ� bottom�� �������� ���Ѵ�.
                Jumping = true;
            }

            if (Jumping)
            {
                DinosourHigh--; // �����Ҷ� y��ǥ ����

            }

            if (DinosourHigh == 2) //���� ������ ���� ���̰� �ȴٸ� ���������� (���� ������ �Ѱ�)
            {
                JumpingLevel = true;
            }

            if (JumpingLevel)
            {
                DinosourHigh = DinoY; // ���� ���̸� DinoY(11)�� �ʱ�ȭ
            }

            if (DinosourHigh == 11) // ���� ������ �� ��ġ�� ���ƿԴٸ� �ٽ� Ű�Է��� �ޱ� ���� �������� �ʱ�ȭ
            {
                JumpingLevel = false;
                Jumping = false;
                Bottom = true;
            }

            TreeX1 -= 2; // 1��° ������ �����̴� ����

            if (TreeX1 <= 3)
            {
                TreeX1 = TreeDistance; // 1��° ������ x��ǥ�� 3���� �۾����ٸ� ������ ��ġ �ʱ�ȭ
            }

            if (TreeX1 == 40)
            {
                TreeX2_Flag += 1;; // 1��° Ʈ���� ��ġ�� �߰��� �Դٸ� 2��° Ʈ�� ����� ���� ���� �ʱ�ȭ
            }

            if (TreeX2_Flag == 1) 
            {
                Tree2(TreeX2);
                TreeX2 -= 2;
            }

            if (TreeX2 <= 3)
            {
                TreeX2 = TreeDistance; // 2��° Ʈ���� x��ǥ�� 3���� �۾����ٸ� ��ġ �ʱ�ȭ
                TreeX2_Flag = 0;
            }


            if (TreeX1 == 7 || TreeX1 == 8) // ���� 1��° Ʈ���� x��ǥ�� 7 �Ǵ� 8�̶�� (���� ����)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // ������ ������ ���� �ʰų� ���Ǻ��� �۰� ���������� (�浹ó��)
                {
                    End++; // ���� ���Ḧ ���� ���� ����
                    CLS;
                    break;
                }
            }

            if (TreeX2 == 7 || TreeX2 == 8) //2��° Ʈ���� x��ǥ�� 7 Ȥ�� 8�� �Ǿ����� (���� ����)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // ������ ������ ���� �ʰų� ���Ǻ��� �۰� ���������� (�浹ó��)
                {
                    End++; // ���� ���Ḧ ���� ���� ����
                    CLS;
                    break;
                }
            }
            Tree1(TreeX1);
            DinoSour(DinosourHigh);

            Sleep(100);
            CLS;
        }
    }

    else //UsersOrder�� �ùٸ��� �Էµ��� �ʾ��� ���
    {
        printf("�ùٸ� ���ڸ� �Է��ϼ���");
        goto Start; //69��° Start: �� �̵��Ͽ� �Է��� �ٽ� ����
    }

    if (End == 1) // ������ ������ ��� 
    {
        printf("\n\n");
        printf("     =======================================================================================\n");
        printf("     |      =========           ======     =======        ======           =========        |\n");
        printf("     |     /                   /          /       ��     /      |          |                |\n");
        printf("     |    |                   /          /         ��    |      |          |                |\n");
        printf("     |    ��                 /           |          |    |      /          |                |\n");
        printf("     |      =========       |            |          |    |    /            |=========       |\n");
        printf("     |              |       |            ��         /    |=====            |                |\n");
        printf("     |              |       ��            ��       /     |��               |                |\n");
        printf("     |             /         ��             ======       |   ��            |                |\n");
        printf("     |      =======            =======                                     ==========       |\n");
        printf("     |                                                                                      |\n");
        printf("     |                                                                                      |\n");
        printf("     |                                                                                      |\n");
        printf("     |                            ����� ������ ? : %d                                      |\n", Score);
        printf("     |                                                                                      |\n");
        printf("     |                                                                                      |\n");
        printf("     =======================================================================================\n");
        printf("\n\n\n");
        printf("                                   �ٽ� �÷��� �Ͻðڽ��ϱ�?                                    ");
        printf("\n\n");
        printf("                                       Y    /      N                                          \n");
        UserAgain = getch(); // ������� ���÷��� ���� �Է� ����

        if (UserAgain == 'Y' || UserAgain == 'y') // ���� �÷��� �Ѵٸ� 82�� ���� AgainStart�� goto
        {
            End = 0;
            Score = 0;
            Sleep(100);
            goto AgainStart;
        }

        else if (UserAgain == 'N' || UserAgain == 'n') // ���� ���÷��� �ǻ� X���� �ܼ�â ����
        {
            exit(1);
        }
    }
}

void DinoSour(int DinoHeight) // ������ ��Ÿ���� �Լ�
{

    gotoXY(0, DinoHeight);
    {
        printf("         $$$$$$$  \n");
        printf("         $$ $$$$$ \n");
        printf("         $$$$$$$$ \n");
        printf("$       $$$      \n");
        printf("$$      $$$$$$   \n");
        printf("$$$    $$$$$     \n");
        printf(" $$   $$$$$$$$$  \n");
        printf(" $$$$$$$$$$$     \n");
        printf("   $$$$$$$$$     \n");
        printf("     $$$$$$$      \n");


        if (DinolegsSwing) // ���� ���� �����̴� ����
        {

            printf("     $    $$$\n");
            printf("     $$        ");
            DinolegsSwing = false;
        }

        else
        {
            printf("     $$$  $   \n");
            printf("          $$    ");
            DinolegsSwing = true;
        }
    }
}


void SetConsoleView() // �ܼ�â ũ�� ����
{
    system("mode con cols=100 lines=25"); // �ܼ�â�� ���� 100 ���� 25�� ����
    system("title Google DinoSour Game - KBH"); // �ܼ�â ������ ����
}

void gotoXY(int x, int y) // �繰�� x��ǥ�� y��ǥ�� ��Ÿ���� �Լ�
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tree1(int TreePosition) //ù��° Ʈ��
{

    gotoXY(TreePosition, TreeHigh);
    printf("  * ");
    gotoXY(TreePosition, TreeHigh + 1);
    printf(" *** ");
    gotoXY(TreePosition, TreeHigh + 2);
    printf("*****");
    gotoXY(TreePosition, TreeHigh + 3);
    printf("  * ");
    gotoXY(TreePosition, TreeHigh + 4);
    printf("  * ");
}

void Tree2(int TreePostin1) // �ι�° Ʈ��
{
    gotoXY(TreePostin1, TreeHigh);
    printf("   *   ");
    gotoXY(TreePostin1, TreeHigh + 1);
    printf("*******");
    gotoXY(TreePostin1, TreeHigh + 2);
    printf("  *** ");
    gotoXY(TreePostin1, TreeHigh + 3);
    printf("  *** ");
    gotoXY(TreePostin1, TreeHigh + 4);
    printf("  ***  ");

}

char KeyInput() // Ű �Է��� �޴� �Լ�
{
    if (kbhit() != 0)
    {
        return getch();
    }
}