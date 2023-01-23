/*
    Project title:
        Big numbers calculator

    professor's name:
        Hadi Asharioun

    TA:
        Amin Haj Jafari

    Group members :
        Mostafa Cherkazi
        Mohammad Parsa Chinian
        Ali Asghar Bararjanpour
*/
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

// windows.h color - title (SetConsoleTitle) color (SetConsoleTextAttribute)
// iomanip fasele ha (setw)
// conio.h (getch)

//---- MAIN
void my_cal();  // bebinim operator chie tasmim begirim che tabe haee ejra she
void my_exit(); // khoroj
void show_menu(); // gereftan operator
void check_num_1(); // check kardan dorosti number_1 (manfi va ashar OK)
void check_num_2(); // check kardan dorosti number_2 (manfi va ashar OK)
void check_number(); // check kardan dorosti number (mosbat va sahih OK)
void get_numbers(); // cin kardan do adad
void get_number(); // cin kardan yek adad
//---- FUNCTION
int noghte(string); // peyda kardan jaygah ashar
int get_length(int[], const int); // dar array befahmim adad chand raghame
void string_to_int(string a, int [], const int); // tabdil string be array
string int_to_string(int [], const int); // tabdil array be string
void a_to_b(int a[],int b[]); // a meghdaresh barabar b beshe
void swap_array(int a[], int b[]); // jaye a va b avaz
void make_zero(int a[], const int n); // sefr kardan deraye haye array
int compare(string, string); // moghayese bozorgi va kochaki adad
bool is_this_a_string_of_numbers(string); // faghat adad bashe True age manfi ham dasht OK
void separate(); // joda kardan ashar va sahih adad ha
int separate_sign(string); // alamate adad chie
string separate_sahih(string); // ghesmate sahih chie
string separate_ashar(string); // ghesmate ashar chie
string remove_last_char(string); // 200 -> 20
string remove_first_char(string); // 123 -> 23
string fix_number(string);  // 00023 -> 23
void add_zero_to_ashar(); // .2.3 va 2.11  => ashareshoon mishe 30 va 11
string hazfe_sefre_ashar(string); // if ashar=20000000000 => ashar = 2


//---- MATH
// -- jam kardan
string summation(string, string);// jam kardan sahih
string floating_summation(string, string, string, string); // jam kardan ashari
string summation_final(); // jam kardan num1 va num2


// -- menha kardan
string subtract(string, string); // tafrigh sahih
string floating_subtract(string, string, string, string); // tafrigh ashari
string subtract_final(); // tafrigh num1 va num2


// --  zarb kardan
string multiply(string, string); // zarb adad sahih
string multiply_floating(string, string, string, string); // zarb kardan ashari
string multiply_final(); // zarb num1 va num2

// -- taghsim
string divide_primary(string, string); // slow taghsim
string divide_fast(string, string, bool); // fast taghsim (main algorithm) (bool mohasebe baghimande)
string divide_reminding(string, string, string); // mohasebe baghimande (num1,num2,result)
string divide_final(); // taghsim ba ashar va alamat
string divide_ashar(); // ashare taghsim

// -- adad aval
string is_prime(string); // kochik tarin maghsom aleyh return mishavad

//  STRUCTURES AND GLOBAL VARIABLES
struct Number
{
    int sign = 1; // +1 OR -1
    string number = "";
    string sahih = "";
    string ashar = "";
} num_1, num_2, baghi;
string ashare_taghsim = "";
char my_operator = 0;
char menu = 32; // 32: SPACE
const int num_size = 500; // Array size
const int num_size_result = 1000; // Array result size

int main()
{
    while(menu != 27)
        my_cal();
    my_exit();
    return 0;
}
//---- MAIN
void my_cal()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    if(menu==32)
        show_menu();

    if(my_operator == 'a' || my_operator == 'A')
    {
        SetConsoleTitle("Calculator : Summation");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "This section of the calculator is for summation";
        get_numbers();
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The result of the sum is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << summation_final() << "\n\n";
    }
    else if(my_operator == 'b' || my_operator == 'B')
    {
        SetConsoleTitle("Calculator : Subtraction");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "This section of the calculator is for subtraction";
        get_numbers();
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The result of minus is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << subtract_final() << "\n\n";
    }
    else if(my_operator == 'c' || my_operator == 'C')
    {
        SetConsoleTitle("Calculator : Multiplication");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "This section of the calculator is for multiplication";
        get_numbers();
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The result of multiplication is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << multiply_final() << "\n\n";
    }
    else if(my_operator == 'd' || my_operator == 'D')
    {
        SetConsoleTitle("Calculator : Division");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "This section of the calculator is for division";
        get_numbers();
        string taghsim_final = divide_final(); // javab = ghesmate sahih
        string tagsim_ashar = divide_ashar(); // javab = ghesmate ashar
        taghsim_final = (tagsim_ashar == "" || tagsim_ashar == "0") ? taghsim_final : taghsim_final + "." + tagsim_ashar;

        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The result of division is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << taghsim_final << "\n\n";

        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The remainder of the division is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << baghi.number <<  "\n\n";
    }
    else if(my_operator == 'e' || my_operator == 'E')
    {
        SetConsoleTitle("Calculator : Prime Number");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "This section of the calculator is for prime number";
        get_number();

        string my_prime_number = num_1.number;
        string is_prime_number;
        string divisor_prime;
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "The result of the number being prime is equal to:";
        SetConsoleTextAttribute(hConsole, 10);
        cout  << "\n\n\t";

        if (my_prime_number == "0")
        {
            is_prime_number = "not a valid number.";
            divisor_prime = "0 is not a valid number.";
        }
        else if(my_prime_number == "1")
        {
            divisor_prime = "1 is not prime by definition!";
            is_prime_number = "not prime by definition!";
        }
        else if(my_prime_number == "2" || my_prime_number == "3")
        {
            is_prime_number = "prime";
            divisor_prime = "prime";
        }
        else if (my_prime_number == "4")
        {
            is_prime_number = "not prime";
            divisor_prime = "2";
        }
        else
        {
            divisor_prime = is_prime(my_prime_number);
            is_prime_number = (divisor_prime == "prime") ? "prime" : "not prime";
        }

        cout << my_prime_number << " is " << is_prime_number << "\n\n";
        SetConsoleTextAttribute(hConsole, 3);
        cout << "\n\t" << "It is divisible by:";
        SetConsoleTextAttribute(hConsole, 10);
        cout << "\n\n\t" << divisor_prime <<  "\n\n";
    }
    SetConsoleTextAttribute(hConsole, 7);
    cout << "\n\t" << "Press any key to continue ...";
    cout  << "\n\t" << "(to show menu, press SPACE)";
    cout  << "\n\t" << "(to exit, press ESC)" << "\n\n\t";
    menu = getch();
}

void show_menu()
{
    SetConsoleTitle("Calculator : Menu");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while(1)
    {
        system("CLS");
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n\n\t" << "Please select an operator :" << "\n\n\n\t";
        SetConsoleTextAttribute(hConsole, 3);
        cout << setw(30) << left << "a: Summation" << "b: Subtraction"<< "\n\n\n\t";
        cout << setw(30) << left << "c: Multiplication" << "d: Division"<< "\n\n\n\t";
        cout << setw(30) << left << "e: Prime Number" << "\n\n\n\t";
        SetConsoleTextAttribute(hConsole, 7);
        cout << "Press any key to continue (to exit, press ESC) ..." << "\n\n\t";
        SetConsoleTextAttribute(hConsole, 14);
        my_operator = getch();
        cout << my_operator;

        if(my_operator == 27)
            my_exit();
        if(my_operator=='a' || my_operator=='b' || my_operator=='c'||my_operator=='d' || my_operator=='e' ||
           my_operator=='A' || my_operator=='B' || my_operator=='C'||my_operator=='D' || my_operator=='E')
            break;
    }
    system("CLS");
}

void my_exit()
{
    SetConsoleTitle("Calculator : Exit");
    system("CLS");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 6);
    cout << "\n\n\t" << "Mostafa Charkazi";
    cout << "\n\n\t" << "Mohammad Parsa Chinian";
    cout << "\n\n\t" << "Ali Asghar Bararjanpour";
    cout << "\n\n\t";
    Sleep(4000);
    exit(0);
}

void get_number()
{
    num_1.number = "";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\n\t" << "Please enter a number :" << "\n\n\t";
    SetConsoleTextAttribute(hConsole, 14);
    while(num_1.number == "")
    {
        SetConsoleTextAttribute(hConsole, 14);
        cin >> num_1.number;
        check_number();
    }
    num_1.number = fix_number(num_1.number);
    cout << "\n\t";
}

void get_numbers()
{
    num_1.number = "";
    num_2.number = "";
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);
    cout << "\n\n\t" << "Please enter two numbers :" << "\n\n\t";
    SetConsoleTextAttribute(hConsole, 14);
    while(num_1.number == "")
    {
        SetConsoleTextAttribute(hConsole, 14);
        cin >> num_1.number;
        check_num_1();
    }
    cout << "\n\t";
    while(num_2.number == "")
    {
        SetConsoleTextAttribute(hConsole, 14);
        cin >> num_2.number;
        check_num_2();
    }
    separate();
}

void check_number()
{
    string str = num_1.number;
    bool is_this_number_a_string_of_positive_numbers = true;
    for(int i=0; i<str.length(); i++)
    {
        if((str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' ||
                str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'))
        {
            continue;
        }
        else
        {
            is_this_number_a_string_of_positive_numbers = false;
            break;
        }
    }
    if(!is_this_number_a_string_of_positive_numbers)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        num_1.number = "";
        cout << "\n\t" << "Please enter the desired number more carefully !!!" << "\n\n\t";
    }
}

void check_num_1()
{
    bool is_num_1_a_string_of_numbers = is_this_a_string_of_numbers(num_1.number);
    if(!is_num_1_a_string_of_numbers)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        num_1.number = "";
        cout << "\n\t" << "Please enter the desired number more carefully !!!" << "\n\n\t";
    }
}

void check_num_2()
{
    bool is_num_2_a_string_of_numbers = is_this_a_string_of_numbers(num_2.number);
    if(!is_num_2_a_string_of_numbers)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 12);
        num_1.number = "";
        cout << "\n\t" << "Please enter the desired number more carefully !!!" << "\n\n\t";
    }
}
//---- FUNCTION
bool is_this_a_string_of_numbers(string str)
{
    bool number = true;
    int how_many_dots_we_have = 0;
    int i=0;
    if(str[0] == '-')
        i++;

    for(i; i<str.length(); i++)
    {
        if((str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' ||
                str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'))
        {
            continue;
        }
        else if(str[i] == '.')
        {
            how_many_dots_we_have++;
            if(how_many_dots_we_have >= 2)
            {
                number = false;
                break;
            }
        }
        else
        {
            number = false;
            break;
        }
    }
    return number;
}

int noghte(string number)
{
    int result = 0;
    for(int i=0; i<number.length(); i++)
    {
        if(number[i] == '.')
        {
            result = i;
            break;
        }
    }

    if(result == 0)
    {
        result = number.length();
    }

    return result;
}

void separate()
{
    /*
        dar sakhtar structure
        1. alamat ha ra moshakhas mikonim
        2. ghesmat sahih va ashar ra joda mikonim
        3. tabe add_zero_to_ashar baraye ezafe kardan sefr jolo ashar
    */
    // num_1.number => struct num_1
    // num_2.number => stcuct num_2

    // -------------- sign
    num_1.sign = separate_sign(num_1.number);
    num_2.sign = separate_sign(num_2.number);
    // -------------- sahih
    num_1.sahih = separate_sahih(num_1.number);
    num_2.sahih = separate_sahih(num_2.number);
    // -------------- ashar
    num_1.ashar = separate_ashar(num_1.number);
    num_2.ashar = separate_ashar(num_2.number);
    add_zero_to_ashar();  // ezafe kardan sefr jolo ashar

}

int get_length(int ar[], const int n)
{
    // length : 321 -> 3
    int x = n-1;
    for(int i=0; i<n; i++)
    {
        if(ar[i] != 0)
        {
            x = i;
            break;
        }
    }
    return (n-x);
}

void string_to_int(string a, int ar[], const int s)
{
    // string : ar[]
    const int n = s - a.length();
    for(int i=0; i<a.length(); i++)
        ar[n+i] = a[i] - '0';
}

string int_to_string(int ar[], const int n)
{
    // int ar[] : string
    string a = "";
    const int len = get_length(ar, n);
    int index = n - len;
    for(int i=0; i<len; i++)
        a += to_string(ar[index+i]);
    return a;
}

int compare(string a, string b)
{
    // a > b : 1
    // a = b : 0
    // a < b : -1
    int result;

    if(a.length() > b.length())
    {
        result = 1;
    }
    else if(a.length() == b.length())
    {
        for(int i=0; i<a.length(); i++)
        {
            if(a[i] == b[i])
            {
                if(i != (a.length() - 1))
                {
                    continue;
                }
                else
                {
                    result = 0;
                    break;
                }
            }
            else if(a[i] > b[i])
            {
                result = 1;
                break;
            }
            else
            {
                result = -1;
                break;
            }
        }
    }
    else
    {
        result = -1;
    }

    return result;
}

void a_to_b(int a[],int b[])
{
    // a = b;
    for(int i=0; i<num_size; i++)
        a[i] = b[i];
}

void swap_array(int a[], int b[])
{
    // temp = a; a = b; b=temp;
    int temp[num_size];
    a_to_b(temp,a);
    a_to_b(a,b);
    a_to_b(b,temp);
}


void make_zero(int a[], const int n)
{
    for(int i=0; i<n; i++)
        a[i] = 0;
}

void add_zero_to_ashar()
{
    int i, d;
    if(num_1.ashar.length() > num_2.ashar.length())
    {
        d = num_1.ashar.length() - num_2.ashar.length();
        for(i=0; i<d; i++)
            num_2.ashar.append("0");
    }
    else if(num_1.ashar.length() < num_2.ashar.length())
    {
        d = num_2.ashar.length() - num_1.ashar.length();
        for(i=0; i<d; i++)
            num_1.ashar.append("0");
    }
}

string fix_number(string number)
{
    // 00000023 -> 23
    string my_num = "";
    int shomaresh = -1;
    for(int i=0; i< number.length(); i++)
    {
        if(number[i] != '0')
        {
            shomaresh = i;
            break;
        }
    }

    for(int i=shomaresh; i<number.length(); i++)
    {
        my_num = my_num + number[i];
    }

    if(shomaresh == -1)
        my_num = "0";

    return my_num;
}

string remove_last_char(string str)
{
    // 200 -> 20
    string result = "";
    for(int i=0; i< str.length() - 1; i++)
        result = result + str[i];


    return result;
}

string remove_first_char(string str)
{
    // 321 -> 21
    string result = "";
    for(int i=1; i< str.length(); i++)
        result = result + str[i];

    return result;
}

int separate_sign(string str)
{
    if (str[0] == '-')
        return -1;
    else
        return 1;
}

string separate_sahih(string str)
{
    string result = "";
    int last_char_loacation = noghte(str);
    int i = 0;
    if (str[i] == '-')
        i++;

    for(i; i<last_char_loacation; i++)
        result = result + str[i];

    return result;
}

string separate_ashar(string str)
{
    string result = "";
    int first_char_loacation = noghte(str) + 1;

    for(int i=first_char_loacation; i<str.length(); i++)
        result = result + str[i];

    return result;
}

string hazfe_sefre_ashar(string str)
{
    string result = "";
    int tedade_sefr = 0;
    for (int i=str.length()-1; i>=0; i--)
    {
        if(str[i] == '0')
            tedade_sefr++;
        else
            break;
    }
    int len_ashar = str.length() - tedade_sefr;
    for(int i=0; i<len_ashar; i++)
        result = result + str[i];

    return result;

}
//---- MATH

// 3 tabe baraye jam kardan
string summation(string number_1, string number_2)
{
    // a + b
    // tabdil string be array
    int a[num_size] = {0};
    int b[num_size] = {0};
    string_to_int(number_1, a, num_size);
    string_to_int(number_2, b, num_size);

    int result[num_size_result] = {0};
    int n = (num_size_result) - 1;

    for(int i = (num_size - 1); i>=0; i--)
    {
        if(a[i] + b[i] + result[n] >= 10)
        {
            result[n] = (a[i] + b[i] + result[n]) % 10;
            result[n-1] += 1;
        }
        else
        {
            result[n] += (a[i] + b[i]);
        }
        n--;
    }
    return int_to_string(result, num_size_result);
}

string floating_summation(string sahih_1, string ashar_1, string sahih_2, string ashar_2)
{
    string sahih = "";
    string ashar = "";
    string temp = "";
    sahih = summation(sahih_1, sahih_2); // jam kardan ghesmate sahih

    if(ashar_1 == "" && ashar_2 == "")
        return sahih;

    ashar = summation(ashar_1, ashar_2); // jam kardane ghesmate ashari


    // age ashar1=98 ashar2=99  -> jameshoon = 187 mishe
    // adade samte rasti ro hazf mikonim va be ghesmate sahih yeki azafe mikonim

    if(ashar.length() > ashar_1.length())
    {
        temp = remove_first_char(ashar);
        ashar = temp;
        // adding 1 to sahih
        temp = summation(sahih, "1");
        sahih = temp;
    }
    return sahih + "." + ashar;
}

string summation_final()
{
    string sahih_1 = num_1.sahih, ashar_1 = num_1.ashar;
    string sahih_2 = num_2.sahih, ashar_2 = num_2.ashar;
    string mark = "";
    // alamat
    /*
    agar ham alamat bashand jam mishavand
    agar mokhalefe alamat bashand tafrigh
    */
    if((num_1.sign * num_2.sign) == 1)
    {
        // if negetive + negetive
        if(num_1.sign == -1)
            mark = "-";

        return mark + floating_summation(sahih_1, ashar_1, sahih_2, ashar_2);

    }
    else
    {
        // menha
        // alamat => ooni ke bozorg tare (4 halat)
        if((compare(sahih_1, sahih_2) == 1 && num_1.sign == -1) ||
            (compare(sahih_1, sahih_2) == -1 && num_2.sign == -1) ||
            (compare(sahih_1, sahih_2) == 0 && compare(ashar_1, ashar_2) == 1 && num_1.sign == -1) ||
            (compare(sahih_1, sahih_2) == 0 && compare(ashar_1, ashar_2) == -1 && num_2.sign == -1))
        {
            mark = "-";
        }

        return mark + floating_subtract(sahih_1, ashar_1, sahih_2, ashar_2);
    }
}

// ---------- 3 tabe baraye menha kardan
string subtract(string number_1, string number_2)
{
    // a - b;
    int a[num_size] = {0};
    int b[num_size] = {0};
    string_to_int(number_1, a, num_size);
    string_to_int(number_2, b, num_size);

    int result[num_size_result] = {0};
    int n = (num_size_result) - 1;


    // compare :
    //  avali  > dovomi : 1
    //  avali == dovomi : 0
    //  avali  < dovomi : -1

    int mark = compare(number_1,number_2);
    if (mark == -1)
        swap_array(a,b);

    for(int i = (num_size - 1); i>=0; i--)
    {
        if(a[i]-b[i]>=0)
        {
            result[n]=a[i]-b[i];
        }
        else
        {
            a[i-1] -= 1;
            a[i] += 10;
            result[n] = a[i] - b[i];
        }
        n--;
    }

    string s = int_to_string(result, num_size_result);
    string str = "";

    if(mark != -1)
    {
        str = s;
    }
    else
    {
        str = "-" + s;
    }

    return str;
}

string floating_subtract(string sahih_1, string ashar_1, string sahih_2, string ashar_2)
{
    /*
    in tabe ba alamat kari nadarad
    */
    string sahih = "";
    string ashar = "";
    string temp = "";
    int d,i;

    if(compare(sahih_1, sahih_2) == 0)
    {
        sahih = "0";
        if(compare(ashar_1, ashar_2) == 0)
            return sahih;
        else if(compare(ashar_1, ashar_2) == -1)
            swap(ashar_1, ashar_2);

        ashar = subtract(ashar_1, ashar_2);
        int d = ashar_1.length() - ashar.length();
        for(int i=0; i<d; i++)
            ashar = "0" + ashar;

        return sahih + "." + ashar;
    }
    else if(compare(sahih_1,sahih_2) == -1)
    {
        // adade aval hamishe bozorge
        swap(sahih_1, sahih_2);
        swap(ashar_1, ashar_2);
    }

    // 3 halat vojod darad    =>    age sahih1 >sahih2 bood => va chizi return nashode
    if(compare(ashar_1,ashar_2) == 1)
    {
        sahih = subtract(sahih_1, sahih_2);
        ashar = subtract(ashar_1, ashar_2);
        d = ashar_1.length() - ashar.length();
        for(i=0; i<d; i++)
        {
            ashar = "0" + ashar;
        }
        return sahih + "." + ashar;
    }
    else if(compare(ashar_1,ashar_2) == 0)
    {
        sahih = subtract(sahih_1, sahih_2);
        return sahih;
    }
    else
    {
        ashar_1 = "1" + ashar_1;
        ashar = subtract(ashar_1, ashar_2);
        sahih_1 = subtract(sahih_1,"1");
        sahih = subtract(sahih_1, sahih_2);

        d = ashar_2.length() - ashar.length();
        for(i=0; i<d; i++)
            ashar = "0" + ashar;

        return sahih + "." + ashar;
    }
}

string subtract_final()
{
    string sahih_1 = num_1.sahih, ashar_1 = num_1.ashar;
    string sahih_2 = num_2.sahih, ashar_2 = num_2.ashar;
    // ---------
    string temp = "", mark = "", sahih = "", ashar = "";

    // menha kardan
    /*
    compare :
        avali  > dovomi : 1
        avali == dovomi : 0
        avali  < dovomi : -1

    agar alamat fargh kone jam mishe  =>  alamat = alamate avali
    */

    if(num_1.sign * num_2.sign == -1)
    {
        if(num_1.sign == -1)
            mark = "-";
        // jam kardan ashari
        temp = floating_summation(sahih_1, ashar_1, sahih_2, ashar_2);
        return mark + temp;
    }

    /*
    agar alamat ha yeki bashad -> menha
    alamat = alamate ooni ke bozorg tare
    ------------------------------------
    agar sahih bozorg tar alamate oon
    agar sahih_1 = sahih_2 => alamat bastegi be ghesmate ashari
    */

    if(compare(sahih_1, sahih_2) == 1)
    {
        if((num_1.sign) == -1)
            mark = "-";

    }
    else if(compare(sahih_1, sahih_2) == -1)
    {
        if((num_2.sign) == 1)
            mark = "-";
    }
    else
    {
        // halati ke jofte adad ha ba ham barabar hastand
        if(compare(ashar_1, ashar_2) == -1)
            mark = "-";
    }
    return mark + floating_subtract(sahih_1, ashar_1, sahih_2, ashar_2);
}

string multiply(string number_1, string number_2)
{
    /*
         a * b;
         in tabe baraye zarb kardan avalie dorost shode
         tabe multiply_final az in tabe estefade mikonad ta zarb ashari ra anjam dahad
         2 array ke meghdar avalie an ha sefr ast
    */
    int a[num_size] = {0};
    int b[num_size] = {0};
    // vorodi haye tabe be array montaghel mishavad
    string_to_int(number_1, a, num_size);
    string_to_int(number_2, b, num_size);
    int len_a = number_1.length();
    int len_b = number_2.length();

    // array va moteghayer haye lazem baraye zarb
    int multi[num_size_result] = {0};
    int result[num_size_result] = {0};
    const int n = num_size_result - 1;
    int carry = 0;
    string s_answer = "";

    // START
    // n = akharin khone array
    // ignore = baraye inke dar har dore halghe bayad be khone ghabli ignore berim
    for(int i = (num_size - 1), ignore=0; i>=(num_size - len_a); i--,ignore++)
    {
        // k => baraye inke dar har dore az halghe lazeme be khone ghabli toye array multi berim
        for(int j =(num_size - 1), k=0; j>=(num_size-len_b); j--,k++)
        {
            multi[n-ignore-k] = ((a[i] * b[j]) + carry) % 10;
            carry = ((a[i] * b[j]) + carry) / 10;

            if(j == (num_size-len_b))
            {
                multi[n-ignore-k-1] = carry;
                carry = 0;
            }
        }

        // jam kardan multi va result
        s_answer = summation(int_to_string(multi,num_size_result), int_to_string(result,num_size_result));
        // tabdil string be array
        string_to_int(s_answer, result, num_size_result);
        // sefr kardam array multi baraye edame zarb
        make_zero(multi,num_size_result);
    }
    // atbdil array result be string
    s_answer = int_to_string(result,num_size_result);
    return s_answer;
}

string multiply_floating(string sahih_1, string ashar_1, string sahih_2, string ashar_2)
{
    string num_a, num_b, multip;
    string sahih = "";
    string ashar = "";
    // meghdar dehi num_a
    if(sahih_1 == "0")
        num_a = ashar_1;
    else
        num_a = sahih_1+ashar_1;

    // meghdar dehi num_b
    if (sahih_2 == "0")
        num_b = ashar_2;
    else
        num_b = sahih_2+ashar_2;

    // MULTIPLY
    multip = multiply(num_a, num_b);

        // age bade zarb ghesmate sahih=0 beshe
        // bayad bazi vaghtha be ghable zarbemoon 0 ezafe konim bad ashar bezanim

    int d = (ashar_1.length() + ashar_2.length()) - multip.length();
    for(int i=0; i<d; i++)
        multip = "0" + multip;

        // nahve ashar zadan
        // makane momayez ra hesab mikonim
        // sepas ghesmate sahih az ashar joda mishe

    int dot_location = multip.length() - (ashar_1.length() + ashar_2.length());
    // sahih
    for (int i=0; i<dot_location; i++)
        sahih += multip[i];

    if(sahih == "")
        sahih = "0";

    // ashar
    for (int i=dot_location; i<multip.length(); i++)
        ashar += multip[i];

    if(ashar == "")
        return sahih;
    else
        return sahih + "." + ashar;

}

string multiply_final()
{
    // alamat
    int sign = num_1.sign * num_2.sign;
    // multiply
    string mul = multiply_floating(num_1.sahih,num_1.ashar,num_2.sahih,num_2.ashar);
    if(sign == -1)
        mul = "-" + mul;
    return mul;
}

// ---- taghsim
string divide_primary(string dividend, string divisor)
{
    // Slow Divide
    /*
    taghsim avalie ke dar divide_final estefade mishavad
    khoroji      0 <= x <= 9
    agar khoroji adade bodorg tari bashad kond mibashad
    */



    // formule riazi taghsim
    // dividend =        d_q         +     r
    // dividend = divisor * quotient + remainder
    if(divisor == "0")
        return "";

    int mark = 1;
    string quotient = "0"; // baraye bar aval farz (javab = 0)
                            // baraye dafe haye badi be javab yeki azafe mishavad
                            // moghayese soorat migirad
    while(mark == 1)
    {
        string d_q = multiply(divisor,quotient);
        string r = subtract(dividend,d_q);

        mark = compare(r, divisor);
        if(mark != -1)
            quotient = summation(quotient,"1");
    }
    return quotient;
}

string divide_fast(string dividend, string divisor, bool calculate_remainder)
{
    string secondary_dividend = dividend;
    string secondary_divisor = divisor;
    string temp = "", result = "", multi = "";
    // adding 0 to secondary_divisor

    int d = secondary_dividend.length() - secondary_divisor.length();

    for(int i=0; i<d; i++)
        secondary_divisor.append("0");

    /*
    Example:
        422 / 2            -> result = ''

    Step 1:
        422/200=2          -> result = 2
        200*2=400          422-400=22

    Step 2:
        22/20=1            -> result = 21
        20*1=20            22-20=2

    Step 3:
        2/2 = 1            -> result = 211
    */

    while(compare(secondary_divisor, divisor) != -1)
    {
        temp = divide_primary(secondary_dividend, secondary_divisor);
        result.append(temp);
        multi = multiply(temp, secondary_divisor);
        temp = subtract(secondary_dividend, multi);
        secondary_dividend = temp;

        // changing secondary_divisor (removing 0)
        temp = remove_last_char(secondary_divisor);
        secondary_divisor = temp;
    }
    result = fix_number(result);

    // baghi mandeh
    if(calculate_remainder == true)
    {
        divide_reminding(num_1.number, num_2.number, result);
    }

    return result;
}

string divide_final()
{
    int sign = num_1.sign * num_2.sign;
    string dividend = num_1.sahih + num_1.ashar;
    string divisor = num_2.sahih + num_2.ashar;
    string result = "";

    dividend = fix_number(dividend);
    divisor = fix_number(divisor);

    if(divisor == "0")
    {
        baghi.number = "Cannot divide by zero";
        return "Cannot divide by zero";
    }

    result = divide_fast(dividend, divisor, true);
    result = fix_number(result);

    if(sign == -1)
        result = "-" + result;

    return result;
}

string divide_reminding(string dividend, string divisor, string quotient)
{
    // formule riazi baghimande :
    // R = dividend - (divisor * quotient)
    int dividend_sign = separate_sign(dividend);
    string dividend_sahih = separate_sahih(dividend);
    string dividend_ashar = separate_ashar(dividend);

    int divisor_sign = separate_sign(divisor);
    string divisor_sahih = separate_sahih(divisor);
    string divisor_ashar = separate_ashar(divisor);

    int quotient_sign = separate_sign(quotient);
    string quotient_sahih = separate_sahih(quotient);

    // CALCULATING
    int d_q_sign = divisor_sign * dividend_sign;
    string d_q = multiply_floating(divisor_sahih,divisor_ashar,quotient_sahih,"");
    string d_q_sahih = separate_sahih(d_q);
    string d_q_ashar = separate_ashar(d_q);

    if(dividend_ashar == "" || d_q_ashar != "")
    {
        int tedade_sefr = d_q_ashar.length();
        for(int i=0;i<tedade_sefr;i++)
            dividend_ashar.append("0");
    }
    else if(dividend_ashar != "" || d_q_ashar == "")
    {
        int tedade_sefr = dividend_ashar.length();
        for(int i=0;i<tedade_sefr;i++)
            d_q_ashar.append("0");
    }

    string remainder;
    if(d_q_sign == 1)
        remainder = floating_subtract(dividend_sahih, dividend_ashar, d_q_sahih, d_q_ashar);
    else
        remainder = floating_summation(dividend_sahih, dividend_ashar, d_q_sahih, d_q_ashar);

    baghi.sahih = separate_sahih(remainder);
    baghi.ashar = separate_ashar(remainder);
    baghi.ashar = hazfe_sefre_ashar(baghi.ashar);

    if(baghi.ashar != "")
        baghi.number = baghi.sahih + "." + baghi.ashar;
    else
        baghi.number = baghi.sahih;

    if(dividend_sign == -1 && baghi.number != "0")
    {
        baghi.sign = -1;
        baghi.number = "-" + baghi.number;
    }

    return baghi.number;
}

string divide_ashar()
{
    // Mohasebe ghesmate ashari

    string dividend = baghi.sahih + baghi.ashar + "0";
    string divisor = num_2.sahih + num_2.ashar;
    string result = "", temp = "";
    dividend = fix_number(dividend);
    divisor = fix_number(divisor);
    int tedade_sefr = 0;
    while(compare(dividend, divisor) == -1)
    {
        dividend.append("0");
        tedade_sefr++;
    }

    for(int i=0; i<30; i++)
        dividend.append("0");

    if(divisor == "0")
        return "";

    temp = divide_fast(dividend, divisor, false);
    result = fix_number(temp); // 00312 : 312
    ashare_taghsim = hazfe_sefre_ashar(result);
    for(int i=0; i<tedade_sefr; i++)
        ashare_taghsim = "0" + ashare_taghsim;

    return ashare_taghsim;
}

// ----- Adade Aval
string is_prime(string number)
{
    // baraye 0,1,2,3,4 : dar tabe my_cal mohasebate lazem soorat gerefte ast va in tabe ejra nemishavad

    string half_number = divide_fast(number,"2",false); // max tekrare halghe be hamin tedade
    string divisor = "2";
    string temp = "", quotient = "", remain = "";

    while(compare(divisor, half_number) == -1)
    {
        quotient = divide_fast(number, divisor, true);
        remain = divide_reminding(number,divisor,quotient);
        if(remain == "0")
            break;

        temp = summation(divisor, "1");
        divisor = temp;
    }
    if (divisor == half_number)
    {
        divisor = "prime";
    }
    // chizi ke return mishe adad bashe => yani adad prime nabod
    return divisor;
}
