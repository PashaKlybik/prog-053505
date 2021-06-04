#include<stdio.h>
#include<Windows.h>
#include<string.h>
int main() {
	FILE* f;
	system("chcp 1251 > null");
	char name[20];
	int i = 0, i1 = 0;
	int bukv = 0, predloj = 0, r = 0, sl = 0;
	int p = 0, b = 0, maxb = 0, maxp = 0, r1 = 0;
	float srbukv = 0.0, srpredl = 0.0;
	char type[5] = ".txt";
	char s;
	fpos_t pi = 0, pb1 = 0, pb = 0, pi1 = 0;
	printf("Input name of file: ");
	gets_s(name, 20);
	while (name[i]) {
		i++;
	}
	while (type[i1]) {
		name[i] = type[i1];
		i++;
		i1++;
	}
	name[i] = '\0';
	if (!(f = fopen(name, "w+"))) {
		printf("Error\n");
		return 0;
	}
	char text[100];
	gets_s(text, 100);
	fprintf(f, "%s", text);
	rewind(f);
	fscanf(f, "%c", &s);
	rewind(f);
	while (1) {
		if (feof(f)) {             //конец фйла
			break;
		}
		while (!feof(f) && s == ' ') {           // самое длинное слово
			if (b > maxb) {
				maxb = b;
				pb = pb1;
			}
			sl++;
			fgetpos(f, &pb1);
			fscanf(f, "%c", &s);
			b = 0;
			if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {

				bukv++;
				b++;
				break;
			}
		}
		while (!feof(f) && s != ' ') {     // среднее кол во букв 

			fscanf(f, "%c", &s);
			if (feof(f)) {
				break;
			}
			if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) {
				bukv++;
				b++;
			}
			else if (s == '.') {
				r++;
			}

		}
	}
	if (b > maxb) {
		maxb = b;
		pb = pb1;
	}
	rewind(f);
	while (1) {            // самое длинное предложение
		if (feof(f)) {
			break;
		}
		while (!feof(f) && s == ' ') {
			fscanf(f, "%c", &s);
			if (r1 == 1) {
				if (maxp < p) {
					maxp = p;
					pi = pi1;
				}
				fgetpos(f, &pi1);
				pi1 = pi1 - 1;
				p = 0;
				r1 = 0;
			}
			else {
				p++;
			}
			if (s != ' ') break;
		}
		while (!feof(f) && s != ' ') {
			fscanf(f, "%c", &s);
			if (feof(f)) {
				break;
			}
			else if (s == '.') {
				r1 = 1;

			}

		}
	}
	if (maxp < p) {
		maxp = p;
		pi = pi1;
	}
	srbukv = (float)bukv / (sl + 1);
	srpredl = (float)(sl + 1) / (r);
	printf("Среднее количество букв %f\n", srbukv);
	printf("Среднее количество слов в предложении %f\n", srpredl);
	FILE * a;
	if (!(a = fopen("res.txt", "w+"))) {
		printf("Error\n");
		return 0;
	}
	fprintf(a, "%f", srbukv);
	fprintf(a, "%s", "\n");
	fprintf(a, "%f", srpredl);

	fsetpos(f, &pb);
	fprintf(a, "%s", "\n");
	while (1) {
		fscanf(f, "%c", &s);
		if ((feof(f)) || s == ' ' || s == '.') break;
		fprintf(a, "%c", s);
		printf("%c", s);
	}
	printf("\n");
	fsetpos(f, &pi);
	fprintf(a, "%s", "\n");
	while (1) {
		fscanf(f, "%c", &s);
		if ((feof(f)) || s == '.') break;
		fprintf(a, "%c", s);
		printf("%c", s);
	}
	fclose(a);
	fclose(f);
	return 0;
}