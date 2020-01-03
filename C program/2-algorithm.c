#include <string.h>
#include <stdio.h>
#include <math.h>

#include <stdlib.h> //随机数生成函数srand()与rand() 所需的头文件
#include <time.h>   //time()所需的头文件
/* 计算1到100的和*/
int sum1To100()
{
    int res = 0;
    for (int i = 1; i <= 100; i++)
    {
        res += i;
    }
    return res;
}

/* 1 - 1/2 + 1/3 - 1/4 + ... + 1/99 - 1/100 */
float sum2()
{
    int deno = 1;
    int sign = 1;
    float res = 0;
    for (int i = 1; i < 100; i++)
    {
        res += (1.0 / deno) * sign;
        sign = -sign;
        deno += 1;
    }
    return res;
}

/* 求方程 ax^2 + bx +c = 0的根 */
float solveEquation(int a, int b, int c, float *res1, float *res2)
{
    int t1 = b * b;
    int t2 = 4 * a * c;
    if (t1 < t2)
    {
        printf("无解.\n");
        return -1;
    }
    int t3 = t1 - t2;
    *res1 = (float)(-b + sqrt(t3)) / (2 * a);
    *res2 = (float)(b + sqrt(t3)) / (2 * a);
}

/* 定义变量 */
void variable()
{
    int a = 0xffff;
    float b = 1203.;
    double c = 1.234e25;
    printf("%d, %f, %lf\f", a, b, c);
    printf("%c%c%d\f", '\101', '\102', '\104');
}
/* 特殊的转义字符 */
void escapeCharacter()
{
    printf("\a\a\a\a\a\a\a");
}

/* 数据类型长度 */
void sizeofDataType()
{
    unsigned char ch = 0x80;
    printf("%c", ch);
}

/* 算数运算符 */
void oprands(int *arr)
{
    int a = 1;
    float b = 2.5;
    //加法运算符 > 移位运算符
    int res = a++ << 1 * (int)++b * 2 % 4 == 3 & 1;
    putchar(0x41);
    int *t;
}
/* 翻译密码 */
void translate(char *str)
{
    char *curr = str;
    while (*curr != '\0')
    {
        if (*curr >= 'A' && *curr <= 'A' + 26)
        {
            printf("%c", 'A' + (*curr + 4 - 'A') % 26);
        }
        else if (*curr >= 'a' && *curr <= 'a' + 26)
        {
            printf("%c", 'a' + (*curr + 4 - 'a') % 26);
        }
        else
        {
            printf("%c", *curr);
        }
        curr += 1;
    }
}
/* 水仙花数 */
void printSXHNumber(int low, int high)
{
    for (int i = low; i < high; i++)
    {
        int t = i;
        int sum = 0;
        while (t > 0)
        {
            int currDigit = t % 10;
            sum += currDigit * currDigit * currDigit;
            t /= 10;
        }
        if (sum == i)
        {
            printf("%d, ", i);
        }
    }
}

/* 完数 */
void printCompleteNumber(int low, int high)
{
    for (int i = low; i < high; i++)
    {
        int arr[1000] = {0};
        for (int j = 1; j <= i / 2; j++)
        {
            if (i % j == 0)
                arr[j] = 1;
        }
        int sum = 0;
        for (int k = 0; k < 1000; k++)
        {
            if (arr[k] == 1)
                sum += k;
        }
        if (sum == i)
        {
            printf("%d, its factors are ", i);
            for (int k = 0; k < 1000; k++)
            {
                if (arr[k] == 1)
                {
                    printf("%d,", k);
                }
            }
            printf("\n");
        }
    }
}
/* sum of a sequence */
void sumOfSequence()
{
    int up1 = 2, up2 = 3;
    int low1 = 1, low2 = 2;
    float sum = 1 + up2 / low2 * 1.0;
    for (int i = 2; i < 20; i++)
    {
        int up = up1 + up2;
        int low = low1 + low2;
        sum += up / low * 1.0;
        if (i % 2 == 0)
        {
            up1 = up;
            low1 = low;
        }
        else
        {
            up2 = up;
            low2 = low;
        }
        printf("%d/%d\t", up, low);
    }
    printf("%f", sum);
}

void testStaticLocalVariable()
{
    static int c = 1;
    printf("%d, ", c++);
}

char character[10][10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

// 递归打印sum每一位对应的汉字
void printCharacter(int sum)
{
    if (sum == 0)
    {
        return;
    }
    printCharacter(sum / 10);
    printf("%s ", character[sum % 10]);
}
void sumOfDigit(int n)
{
    int sum = 0;
    while (n != 0)
    {
        // t是n的最后一位
        int t = n % 10;
        sum += t;
        n /= 10;
    }
    printCharacter(sum);
    printf("\n");
}

void countFrequency(char *str)
{
    int res[26][1] = {0}; //用来存储a-z 26个字母的出现次数
    char *curr = str;
    while (*curr != '\0')
    {
        if (*curr >= 'A' && *curr <= 'Z')
        {
            res[*curr - 'A'][0] += 1;
        }
        if (*curr >= 'a' && *curr <= 'z')
        {
            res[*curr - 'a'][0] += 1;
        }
        curr = curr + 1;
    }
    int maxCount = 0;     //当前的最大出现次数
    int ch = -1, fre = 0; // 要输出的字母以及它的出现次数
    // 遍历统计结果
    for (int i = 0; i < 26; i++)
    {
        if (res[i][0] > maxCount)
        {

            ch = 'a' + i;
            fre = res[i][0];
            maxCount = res[i][0];
        }
    }
    printf("%c %d\n", ch, fre);
}

void guessNumber()
{
    srand((unsigned)time(NULL));   //随机数发生器初始化函数，以时间为种子
    int number = rand() % 100 + 1; //随机生成1到100的随机数
    int times = 0;                 //记录猜的次数
    int guessed = -1;
    printf("ready!\n");
    while (guessed != number)
    {
        times += 1;
        printf("enter a number:\n");
        scanf("%d", &guessed);
        if (guessed > number)
        {
            printf("bigger\n");
        }
        else if (guessed < number)
        {
            printf("smaller\n");
        }
        else
        {
            printf("correct, you guessed %d times.\n", times);
        }
    }
}
void findEscaper()
{

    int i, j, k, c;

    for (i = 1; i <= 9; i++)     //i:车号前二位的取值
        for (j = 0; j <= 9; j++) //j:车号后二位的取值
            if (i != j)          //判断二位数字是否相异
            {
                k = i * 1000 + i * 100 + j * 10 + j; //计算出可能的整数
                for (c = 31; c < 100; c++)           //循环判断该数是否为另一整数的平方，c的取值范围 31-99 之间
                    if (c * c == k)                  //是否等于c的平方
                        printf("%d\n", k);
            }
}

//递归反向输出
void reversePrintWord(char *str)
{
    char *tail = strchr(str, ' ');
    // 没有找到' '
    if (tail == NULL)
        printf("%s", str);
    else
    {
        //先输出剩余的str
        reversePrintWord(tail + 1);
        *tail = '\0';
        //输出当前的str
        printf(" %s", str);
    }
}

int main()
{
    sumOfDigit(12345678);
}
