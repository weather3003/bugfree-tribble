#include<iostream>
using namespace std;


int SqrLenCrossProd(int x1, int y1, int z1, // Input vector 1
                    int x2, int y2, int z2) // Input vector 2
{
    int x3, y3, z3;
    int answer;

    __asm{
        mov     ebx, y1                 ; x3 = y1*z2 - y2*z1
        imul    ebx, z2
        mov     x3, ebx
        mov     ecx, y2
        imul    ecx, z1
        sub     x3, ecx

        mov     ebx, x2                 ; y3 = x2*z1 - x1*z2
        imul    ebx, z1
        mov     y3, ebx
        mov     ecx, x1
        imul    ecx, z2
        sub     y3, ecx

        mov     ebx, x1                 ; z3 = x1*y2 - x2*y1
        imul    ebx, y2
        mov     z3, ebx
        mov     ecx, x2
        imul    ecx, y1
        sub     z3, ecx

        mov     ebx, x3                 ; answer = (x3*x3 + y3*y3 + z3*z3)
        imul    ebx, x3
        mov     ecx, y3
        imul    ecx, y3
        mov     edx, z3
        imul    edx, z3
        mov     answer, ebx
        add     answer, ecx
        add     answer, edx
    }
    
    return answer;
}

void main()
{
    cout << SqrLenCrossProd(1, 2, 3, 1, 1, 1) << endl;
    cout << SqrLenCrossProd(1, 0, 0, 0, 1, 0) << endl;
    cout << SqrLenCrossProd(10, 10, 10, -10, 50, -15) << endl;
}