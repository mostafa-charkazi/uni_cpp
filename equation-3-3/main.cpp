#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;
void get_matrix();
void show_equation(int);
void show_equations();
void show_xyz();

float matrix[3][4] = {0};
float numerator_x = 0;
float numerator_y = 0;
float numerator_z = 0;
float denominator = 0;

int main()
{
    char key = 0;
    while(key != 27)
    {
        system("CLS");

        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTitle("Equation 3_3");
        SetConsoleTextAttribute(hConsole, 3);

        cout << '\n';
        cout << '\t' << "Enter equations: \n\n\t";
        SetConsoleTextAttribute(hConsole, 7);
        get_matrix();

        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "Your equations are : " << '\n';

        SetConsoleTextAttribute(hConsole, 7);
        show_equations();

        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\t" << "Result : " << "\n";

        SetConsoleTextAttribute(hConsole, 7);
        show_xyz();


        cout << "Press any key to continue ... \n\t";
        cout << "(to exit, press ESC)" << "\n\n\t";
        key = getch();
    }
}

void get_matrix()
{
    for(int i=0;i<3;i++)
        for(int j=0; j<4;j++)
            cin >> matrix[i][j];
}

void show_equation(int equation_number)
{
    cout << "\n\t";

    for(int i=0;i<4;i++)
    {
        cout << matrix[equation_number - 1][i];
        switch (i)
        {
        case 0:
            cout << "x + ";
            break;
        case 1:
            cout << "y + ";
            break;
        case 2:
            cout << "z = ";
            break;
        }
    }
    cout << "\n\t";
}

void show_equations()
{
    show_equation(1);
    show_equation(2);
    show_equation(3);
}

void denominator_cal()
{
   denominator = ( matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] ) - ( matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[2][1] * matrix[1][2] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][1] );
}

void numerator_cal()
{
   numerator_x = ( matrix[0][3] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][3] + matrix[0][2] * matrix[1][3] * matrix[2][1] ) - ( matrix[2][3] * matrix[1][1] * matrix[0][2] + matrix[2][1] * matrix[1][2] * matrix[0][3] + matrix[2][2] * matrix[1][3] * matrix[0][1] );
   numerator_y = ( matrix[0][0] * matrix[1][3] * matrix[2][2] + matrix[0][3] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][3] ) - ( matrix[2][0] * matrix[1][3] * matrix[0][2] + matrix[2][3] * matrix[1][2] * matrix[0][0] + matrix[2][2] * matrix[1][0] * matrix[0][3] );
   numerator_z = ( matrix[0][0] * matrix[1][1] * matrix[2][3] + matrix[0][1] * matrix[1][3] * matrix[2][0] + matrix[0][3] * matrix[1][0] * matrix[2][1] ) - ( matrix[2][0] * matrix[1][1] * matrix[0][3] + matrix[2][1] * matrix[1][3] * matrix[0][0] + matrix[2][3] * matrix[1][0] * matrix[0][1] );
}

void show_xyz()
{
    denominator_cal();
    numerator_cal();
    cout << "\n\t";
    cout << "x = " << numerator_x << "/" << left << setw(20) << denominator << numerator_x / denominator << "\n\n\t";
    cout << "y = " << numerator_y << "/" << left << setw(20) << denominator << numerator_y / denominator << "\n\n\t";
    cout << "z = " << numerator_z << "/" << left << setw(20) << denominator << numerator_z / denominator << "\n\n\t";
}
