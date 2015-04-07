#include<iostream>
#include <time.h>
using namespace std;

extern "C" int LCM(int, int);

int properFactors(int number, int * factorList, int& numberOfFactors);
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

//void main()
//{
//	int a, b; int factorList[1000];
//	b = 0;
//
//	cout << "Enter one integer: ";
//	cin >> a;
//	while (a > 0)
//	{
//		properFactors(a, factorList, b);
//		cout << "Enter one integer: ";
//		cin >> a;
//	}
//}

#define MAXIMUM 1000000
int Factors[MAXIMUM];
int main() {
	int q;
	int numFactors;
	int PairCount = 0;
	clock_t StartClock = clock();
	for (int p = 1; p <= MAXIMUM; p++) {
		q = properFactors(p, Factors, numFactors);
		if (q > p) {
			if (properFactors(q, Factors, numFactors) == p) {
				cout << "Amicable Pair : " << p << ", " << q;
				cout << "(" << q << " has " << numFactors << " factors : ";
				cout << Factors[0];
				for (int i = 1; i<numFactors; i++)
					cout << ", " << Factors[i];
				cout << ")" << endl;
				PairCount++;
			}
		}
	}
	double TotalTime = (double)(clock() - StartClock) / CLOCKS_PER_SEC;
	cout << "Number of amicable pairs found = " << PairCount << endl;
	cout << "Time = " << TotalTime << " seconds" << endl;
}




int properFactors(int number, int * factorList, int& numberOfFactors)
{
	factorList[0] = 1; int count = 1; int sum = 1; int factor2;
	for (int k = 2; k * k <= number; k++)
	{
		if (number % k == 0)
		{
			factorList[count] = k;
			sum += k;
			count++;

			factor2 = number / k;
			if (factor2 != k)
			{
				factorList[count] = factor2;
				sum += factor2;
				count++;
			}
		}
	}

	numberOfFactors = count;

	return sum;
}





