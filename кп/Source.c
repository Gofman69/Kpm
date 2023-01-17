#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

float inizi2(int N, float first[99][7]);
void research(float first[99][7], int N, float sel);
void table(int N, float first[99][7]);
float** charact(float first[99][7], int sel, int sel2);
float** charactn(float first[99][7], int sel);
float** ot(float first[99][7], int N);
float** random(float first[99][7], int N);
float** sort(float first[99][7],int N);
int** zhrebiy(float first[99][7], int N);
void researchm(float first[99][7], int N);
int load(float first[99][7], int N);
int save(float first[99][7], int N);
float research1(float first[99][7], int N, int sel);
float research2(float first[99][7], int N, int sel);

void main()
{
	setlocale(LC_ALL, "rus");
	int n, selection, end = 1, selection1, selection2, selection3, selection4, selection5;	
	float h[99][7];
	printf("������� ���-�� ��������: ");
	scanf_s("%d", &n);
	inizi2(n, h);
	zhrebiy(h, n);
	system("cls");	
	while (1)
	{
		printf("��������� ����������� ������.\n");
		printf("�������:\n1) �������� �������.\n2) �������� ��������� ��������.\n3) ��������� ���������� �������.\n4) �������� ����.\n5) �������� ���-�� ��������.\n");
		printf("6) �����.\n7) ���������� �����.\n8) �������� �����.\n9) �����.\n");
		printf("������� �������: ");
		scanf_s("%d", &selection);
		system("cls");
		switch (selection)
		{
		case 1:
		{
			table(n, h);
			printf("\n\n");
			printf("���������� ���������?\n1) ��.\n2) ���.\n");
			printf("�������: ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		}
		case 2:
		{
			printf("1) �������� ����� ����������.\n2) �������� ����� ������.\n�������� �������: ");
			scanf_s("%d", &selection5);
			system("cls");
			switch (selection5)
			{
			case 1:
			{
				printf("������� ����� �������: ");
				scanf_s("%d", &selection1);
				system("cls");
				charactn(h, (selection1));
				break;
			}
			case 2:
			{
				printf("������� ����� �������: ");
				scanf_s("%d", &selection1);
				system("cls");
				printf("\n������� ����� ������: ");
				scanf_s("%d", &selection2);
				system("cls");
				charact(h, (selection1), (selection2));
				system("cls");
				break;
			}
			}
			break;
		}
		case 3:
		{
			printf("��������� ���������� �������?\n1) ��.\n2) ���.\n������� �������: ");
			scanf_s("%d", &selection3);
			system("cls");
			switch (selection3)
			{
			case 1:
			{
				random(h, n);
				break;
			}
			case 2:
			{
				break;
			}
			break;
			}
			break;
		}
		case 4:
		{
			printf("�������� ����?\n1) ��.\n2) ���.\n������� �������: ");
			scanf_s("%d", &selection4);
			system("cls");
			switch (selection4)
			{
			case 1:
			{
				inizi2(n, h);
				zhrebiy(h, n);
				break;
			}
			case 2:
			{
				break;
			}
			break;
			}
			break;
		}
		case 5:
		{
			printf("������� ���-�� ��������: ");
			scanf_s("%d", &n);
			system("cls");
			inizi2(n, h);
			zhrebiy(h, n);
			break;
		}
		case 6:
		{
			int sel1;
			printf("1) ����� �� �����.\n2) ����� �� ������ ����������.\n3) ����� ����������� ������� � ������.\n4) ����� ����������� ������� � ������.\n������� �������: ");
			scanf_s("%d", &sel1);
			switch (sel1)
			{
			case 1:
			{
				printf("������� ����� �������: ");
				scanf_s("%d", &selection1);
				research(h, n, selection1);
				printf("\n\n");
				printf("���������� ���������?\n1) ��.\n2) ���.\n");
				printf("�������: ");
				scanf_s("%d", &end);
				printf("\n\n");
				system("cls");
				break;
			}
			case 2:
			{
				researchm(h, n);
				printf("\n\n");
				printf("���������� ���������?\n1) ��.\n2) ���.\n");
				printf("�������: ");
				scanf_s("%d", &end);
				printf("\n\n");
				system("cls");
				break;
			}
			case 3:
			{
				int sel2, d;
				printf("������� ����� ������.\n");
				scanf_s("%d", &sel2);
				system("cls");				
				d = research1(h, n, sel2);				
				printf("\n\t���������� ����� ������: %3.2f\t\t����� �������: %10.0f", h[d][sel2+1], h[d][1]);
				printf("\n\n");
				printf("���������� ���������?\n1) ��.\n2) ���.\n");
				printf("�������: ");
				scanf_s("%d", &end);
				printf("\n\n");
				system("cls");
				break;
			}
			case 4:
			{
				int sel2, d;				
				printf("������� ����� ������.\n");
				scanf_s("%d", &sel2);
				system("cls");
				d = research2(h, n, sel2);				
				printf("\n\t���������� ����� ������: %3.2f\t\t����� �������: %10.0f", h[d][sel2+1], h[d][1]);
				printf("\n\n");
				printf("���������� ���������?\n1) ��.\n2) ���.\n");
				printf("�������: ");
				scanf_s("%d", &end);
				printf("\n\n");
				system("cls");
				break;
			}
			break;
			}
			break;
		}
		case 7:
		{
			printf("���������� �����.\n");
			save(h, n);
			printf("\n\n");
			printf("���������� ���������?\n1) ��.\n2) ���.\n");
			printf("�������: ");
			scanf_s("%d", &end);
			printf("\n\n");
			system("cls");
			break;
		}
		case 8:
		{
			printf("�������� �����.\n");
			load(h, n);
			printf("\n������� ���-�� ��������: ");
			scanf_s("%d", &n);
			system("cls");
			printf("\n");
			zhrebiy(h, n);
			break;
		}
		case 9:
		{
			end = 2;
			return end;
			break;
		}

		}
		if (end == 2)
		{
			return end;
			break;
		}
	}

	return 0;
}
/*������������� ������*/
int** zhrebiy(float first[99][7], int N)
{
	for (int i = 0; i < N; i++)
	{
		first[i][0] = i + 1;
	}
}
/*����� �������*/
void table(int N, float first[99][7])
{
	for (int l = 0; l < N; l++)
	{
		first[l][5] = 0;
	}
	ot(first, N);
	sort(first, N);
	printf("|%6s|%15s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "������", "����� �������", "1-�����", "2-�����", "3-�����", "���-�� �����", "����� �����", "�����");
	for (int i = 0; i < N; i++)
	{
		printf("%6.0f", first[i][0]);
		printf("%15.0f", first[i][1]);
		for (int k = 2; k < 5; k++)
		{
			printf("%13.2f", first[i][k]);
		}
		printf("%11d", N - i);
		printf("%14.2f", first[i][5]);
		printf("%10d", i + 1);
		printf("\n");
		first[i][6] = 0;
	}
}
/*��������� ������*/
float inizi2(int N, float first[99][7])
{
	for (int k = 0; k < N; k++)
	{
		for (int l = 1; l < 6; l++)
		{
			first[k][l] = 0;			
		}
	}
}
/*�������������� ������ �������*/
float** charact(float first[99][7], int sel, int sel2)
{
	int a, b;
	float c;
	printf("������� ����: ");
	scanf_s("%d", &a);
	printf("\n");
	printf("������� ������: ");
	scanf_s("%d", &b);
	printf("\n");
	printf("������� �������: ");
	scanf_s("%f", &c);
	printf("\n");
	first[sel-1][sel2+1] = a * 60 + b + c / 100;
}
/*�������������� ������ ������ ����������*/
float** charactn(float first[99][7], int sel)
{
	printf("������� ����� ���������� �������: ");
	scanf_s("%f", &first[sel-1][1]);
	system("cls");
	printf("\n");
}
/*������� ������ �������*/
float** ot(float first[99][7], int N)
{
	int a;
	for (int k = 0; k < N; k++)
	{
		for (int l = 2; l < 5; l++)
		{
			first[k][5] += first[k][l];
			a = first[k][5];
			if ((first[k][5] - a) >= 0.6)
			{				
				first[k][5] += 0.4;				
			}				
		}
	}
}
/*���������� ������ ���������� �������*/
float** random(float first[99][7], int N)
{
	for (int i = 0; i < N; i++)
	{
		first[i][1] = 100 + rand() % 899;
		for (int k = 2; k < 5; k++)
		{
			first[i][k] = 0 + rand() % 300;
		}
	}
}
/*���������� ������*/
float** sort(float first[99][7],int N)
{
	int name;
	float temp_h[6], temp_z;
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (first[j][5] > first[j + 1][5])
			{
				for (int k = 2; k < 6; k++)
				{
					temp_z = first[j][0];
					temp_h[k] = first[j][k];
					name = first[j][1];
				}
				for (int k = 2; k < 6; k++)
				{
					first[j][0] = first[j + 1][0];
					first[j][k] = first[j + 1][k];
					first[j][1] = first[j + 1][1];
				}
				for (int k = 2; k < 6; k++)
				{
					first[j + 1][0] = temp_z;
					first[j + 1][k] = temp_h[k];
					first[j + 1][1] = name;
				}
			}
		}
	}
}
/*����� �� �����*/
void research(float first[99][7], int N, float sel)
{
	ot(first, N);
	sort(first, N);
	for (int i = 0; i < N; i++)
	{
		if (sel - 1 == i)
		{
			printf("|%16s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "����� �������", "1-�����", "2-�����", "3-�����", "���-�� �����", "����� �����", "�����");
			printf("%15.0f", first[i][1]);
			for (int k = 2; k < 5; k++)
			{
				printf("%13.2f", first[i][k]);
			}
			printf("%11d", N - i);
			printf("%14.2f", first[i][5]);
			printf("%10d", i + 1);
			printf("\n");
		}
		first[i][3] = 0;
	}
}
/*����� �� ����������� ������� � ������������ ������*/
float research1(float first[99][7], int N,int sel)
{	
	float max = 0;
	ot(first, N);
	sort(first, N);
	int d;
	for (int i = 0; i < N; i++)
	{
		if (first[i][sel + 1] > max)
		{
			max = first[i][sel + 1];
			d = i;
		}
	}	
	return d;
}
/*����� �� ����������� ������� �
������������ ������*/
float research2(float first[99][7], int N, int sel)
{
	ot(first, N);
	sort(first, N);
	float min = 1500;
	int d;
	for (int i = 0; i < N; i++)
	{
		if (first[i][sel+1] < min)
		{
			min = first[i][sel+1];
			d = i;
						
		}
	}	
	return d;
	
}
/*����� �� ������ ����������*/
void researchm(float first[99][7], int N)
{
	float sel;
	ot(first, N);
	sort(first, N);
	printf("������� ����� ���������� �������, ����� ������ � ��� ����������: ");
	scanf_s("%f", &sel);
	system("cls");
	for (int i = 0; i < N; i++)
	{
		if (sel == first[i][1])
		{
			printf("\n|%16s|%12s|%12s|%12s|%12s|%12s|%8s|\n", "����� �������", "1-�����", "2-�����", "3-�����", "���-�� �����", "����� �����", "�����");
			printf("%15.0f", first[i][1]);
			for (int k = 2; k < 5; k++)
			{
				printf("%13.2f", first[i][k]);
			}
			printf("%11d", N - i);
			printf("%14.2f", first[i][5]);
			printf("%10d", i + 1);
			printf("\n");
		}
		first[i][5] = 0;
	}
}
/*�������� ������*/
int load(float first[99][7], int N)
{
	FILE* file;
	char* fname[20];
	char txt[5] = ".txt";
	int count = 0;
	printf("������� �������� �����: ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "r");
	printf("\n\n");
	while (fscanf(file, "%f %f %f %f", & (first[count][1]), &(first[count][2]), &(first[count][3]), &(first[count][4])) != EOF)
	{
		printf("%3.0f %3.2f %3.2f %3.2f\n", first[count][1], first[count][2], first[count][3], first[count][4]);
		count++;		
	}
	printf("\n\n%d - ���-�� ��������.", count);
	printf("\n\n");
	N = count;
	fclose(file);
	return N, first;
}
/*���������� ������*/
int save(float first[99][7], int N)
{		
	FILE* file;
	char* fname[20];
	char txt[5] = ".txt";
	printf("������� �������� �����: ");
	scanf("%s", fname);
	strcat(fname, txt);
	file = fopen(fname, "w");
	for (int i = 0; i < N; i++)
	{
		fprintf(file, "%5.0f\t ", first[i][1]);
		for (int k = 2; k < 5; k++)
		{
			fprintf(file, "%5.2f\t ", first[i][k]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
	return N;
}