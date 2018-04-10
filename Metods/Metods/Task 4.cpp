#include <iostream>
#include <cmath>
using namespace std;

double f(double x)  
{
	// ����� ������������� ������� f(x) ��� w(x) = 1
	return 3 * pow(x, 4) + x + sin(x);
}
double w(double x)
{
	// ������� ������������ ������ ������� 
	return 1;
}

double easyIntegral(double a, double b) 
{
	// �������� �� ������� f(x) = 3 * x^2 + x
	double Jh = 0.6*(pow(b, 5) - pow(a, 5)) + 0.5*(pow(b, 2) - pow(a, 2)) - cos(b) + cos(a);
	return Jh;
}

double leftRiemannSum(double a, double b, double m)
{
	// ����� ����� ���������������
	double h = (b - a) / m;
	double sum = 0;
	for (int i = 0; i < m; ++i)
	{
		double x = a + i * h;
		sum += f(x) * w(x) * h;
	}
	return sum;
}

double rightRiemannSum(double a, double b, double m)
{
	// ����� ������ ���������������
	double h = (b - a) / m;
	double sum = 0;
	for (int i = 0; i < m; ++i)
	{
		double x = a + i * h + h;
		sum += f(x ) * w(x ) * h;
	}
	return sum;
}

double midpointRiemannSum(double a, double b, double m)
{
	// ����� ������� ���������������
	double h = (b - a) / m;
	double sum = 0;
	for (int i = 0; i < m; ++i)
	{
		double x = a + i * h + (h/2);
		sum += f(x) * w(x) * h;
	}
	return sum;
}

double trapezoidalMethod(double a, double b, double m)
{
	// ����� ��������
	double h = (b - a) / m;
	double sum = 0;
	double f1 = 0;
	double f2 = f(a) * w(a);
	for (int i = 0; i < m; ++i)
	{
		f1 = f2;
		double x2 = a + (i + 1) * h;
		f2 = f(x2) * w(x2);
		sum += h * (f1 + f2) / 2;
	}
	return sum;
}

double simpson(double a, double b, double m)
{
	// ����� ��������
	double h = (b - a) / m;
	double sum1 = 0;
	double sum2 = 0;
	for (int i = 0; i <= m - 1; ++i)
	{
		sum1 = sum1 + f(a + i * h + h / 2);
	}

	for (int i = 1; i <= m - 1; ++i)
	{
		sum2 = sum2 + f(a + i * h);
	}
	return  h * (1.0 / 6.0) * (f(a) + f(b) + 4 * sum1 + 2 * sum2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int m; //����� ����������� ������� [A,B] � ��������� ��
	double a, b;
	cout << "������� ����� m" << endl;
	cin >> m;
	cout << "������� ����� A � B" << endl;
	cin >> a >> b;
	double J = easyIntegral(a, b);
	printf("\n������ �������� ��������� �� f(x)*w(x) = J = %.10f\n\n", easyIntegral(a, b));

    printf("������������ �������� ��������� f(x) * w(x) ������� ����� ��������������� = %.10f\n", leftRiemannSum(a, b, m)); 
	printf("����������� = %.10f\n",abs (J-  leftRiemannSum(a, b, m)));

	printf("������������ �������� ��������� f(x) * w(x) ������� ������ ��������������� = %.10f\n", rightRiemannSum(a, b, m));
	printf("����������� = %.10f\n", abs(J - rightRiemannSum(a, b, m)));

	printf("������������ �������� ��������� f(x) * w(x) ������� ������� ��������������� = %.10f\n", midpointRiemannSum(a, b, m));
	printf("����������� = %.10f\n", abs(J - midpointRiemannSum(a, b, m)));

	printf("������������ �������� ��������� f(x) * w(x) ������� �������� = %.10f\n", trapezoidalMethod(a, b, m));
	printf("����������� = %.10f\n", abs(J - trapezoidalMethod(a, b, m)));

	printf("������������ �������� ��������� f(x) * w(x) ������� �������� = %.10f\n", simpson(a, b, m));
	printf("����������� = %.10f\n", abs(J - simpson(a, b, m)));

}