#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int max = 100;
	int a[max], b[max], c[2 * max], d[2 * max];
	int N, M, min;
	cout << "N="; cin >> N;
	cout << "M="; cin >> M;
	int nC = 0, nD = 0;
	cout << "Введите последовательность a:" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "a[" << i << "]="; cin >> a[i];
		if (a[i] % 2 == 0)
			c[nC++] = a[i];
		else
			d[nD++] = a[i];
	}
	cout << "Введите последовательность b:" << endl;
	for (int i = 0; i < M; i++)
	{
		min = b[0];
		cout << "b[" << i << "]="; cin >> b[i];
		if (b[i] % 2 == 0)
			c[nC++] = b[i];
		else
			d[nD++] = b[i];
		if (b[i] < b[0])
			min = b[i];
	}
	for (int i = 0; i < nD - 1; i++)
	{
		for (int j = i + 1; j < nD; j++)
			if (d[i] > d[j])
			{
				int t = d[i];
				d[i] = d[j];
				d[j] = t;
			}
	}
	int i = 0;
	cout << "Парные елементы последовательностей а и b " << endl;
	while (i < nC)
	{
		cout << "c[" << i << "]=" << c[i] << endl;
		i++;
	}
	if (i == 0)
		cout << "Таких елементов нет в даных последовательностях" << endl;

	int j = 0;
	cout << "Непарные елементы последовательностей а и b, что расположены в порядке возростания" << endl;
	while (j < nD)
	{
		cout << "d[" << j << "]=" << d[j] << endl;
		j++;
	}
	if (j == 0)
		cout << "Таких елементов нет в даных последовательностях" << endl;
	//2)
	cout << "Последовательность А=аА, где а-минимальний елемент последовательности В" << endl;
	for (int i = 0; i < N; i++)
	{
		a[i] = a[i] * min;
		cout << "a[" << i << "]=" << a[i] << endl;
	}
	//3)
	bool is_ordered1 = true;
	for (int i = 0; i < N - 1 && is_ordered1; i++)
		if (a[i] <= a[i + 1])
			is_ordered1 = false;
	cout << "Масив А " << (is_ordered1 ? "" : "не") << " упорядкований" << endl;
	bool is_ordered = true;
	for (int i = 0; i < M - 1 && is_ordered; i++)
		if (b[i] <= b[i + 1])
			is_ordered = false;
	cout << "Масив B " << (is_ordered ? "" : "не") << " упорядкований" << endl;
	return 0;
}

