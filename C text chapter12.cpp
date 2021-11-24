#include<stdio.h>
#define _1205

#ifdef _1201
#define NAME_LEN 64
struct student {
	char name[NAME_LEN];
	int height;
	float weight;
	long schols;
};

int main(void) {
	struct student takao = { "Takao",137,86.2 };

	printf("氏　名 = %p\n", &takao.name);
	printf("身　長 = %p\n", &takao.height);
	printf("体　重 = %p\n", &takao.weight);
	printf("奨学金 = %p\n", &takao.schols);

	return 0;
}
#endif

#ifdef _1202
#define NAME_LEN 64
typedef struct student {
	char name[NAME_LEN];
	int height;
	float weight;
	long schols;
} Student;
void hiroko(Student* std) {
	if (std->height < 180) std->height = 180;
	if (std->weight > 80) std->weight = 80;
}

int main(void) {
	Student A;
	printf("氏　名 : "); scanf_s("%s", A.name, sizeof(A.name));
	printf("身　長 : "); scanf_s("%d", &A.height);
	printf("体　重 : "); scanf_s("%f", &A.weight);
	printf("奨学金 : "); scanf_s("%ld", &A.schols);
	putchar('\n');

	hiroko(&A);

	printf("氏　名 = %s\n", A.name);
	printf("身　長 = %d\n", A.height);
	printf("体　重 = %.1f\n", A.weight);
	printf("奨学金 = %ld", A.schols);

	return 0;
}
#endif

#ifdef _1203
struct xyz {
	int x;
	long y;
	double z;
};
struct xyz scan_xyz(){
	struct xyz temp;

	printf("x : "); scanf_s("%d", &temp.x);
	printf("y : "); scanf_s("%ld", &temp.y);
	printf("z : "); scanf_s("%lf", &temp.z);

	return temp;
}

int main(void) {
	struct xyz s = { 0,0,0 };

	s = scan_xyz();

	printf("x = %d\n", s.x);
	printf("y = %ld\n", s.y);
	printf("z = %lf", s.z);

	return 0;
}
#endif

#ifdef _1204
#include<string.h>
#define NUMBER 3
#define NAME_LEN 64
/*学生データ構造体*/
typedef struct {
	char name[NAME_LEN];
	int height;
	float weight;
	long schols;
} Student;
/*ソート時の入れ替え*/
void swap_Student(Student* x, Student* y) {
	Student temp = *x;
	*x = *y;
	*y = temp;
}
/*身長昇順にソート*/
void sort_by_height(Student a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (a[j - 1].height > a[j].height) {
				swap_Student(&a[j - 1], &a[j]);
			}
		}
	}
}
/*名前昇順にソート*/
void sort_by_name(Student a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (*a[j - 1].name != *a[j].name && *a[j - 1].name < *a[j].name) {
				swap_Student(&a[j - 1], &a[j]);
			}
			else if (*a[j - 1].name == *a[j].name &&
					 *a[j - 1].name + 1 != *a[j].name + 1 && *a[j - 1].name + 1 < *a[j].name + 1) {
				swap_Student(&a[j - 1], &a[j]);
			}
			else if (*a[j - 1].name == *a[j].name && *a[j - 1].name + 1 == *a[j].name + 1 &&
				*a[j - 2].name + 2 != *a[j].name + 2 && *a[j - 2].name + 2 < *a[j].name + 2) {
				swap_Student(&a[j - 1], &a[j]);
			}
			else if (*a[j - 1].name == *a[j].name && *a[j - 1].name + 1 == *a[j].name + 1 && *a[j - 1].name + 2 == *a[j].name + 2 &&
				*a[j - 2].name + 3 != *a[j].name + 3 && *a[j - 2].name + 3 < *a[j].name + 3) {
				swap_Student(&a[j - 1], &a[j]);
			}
		}
	}
}

int main(void) {
	int sw = 0;
	Student s[NUMBER] = { 0 };
	for (int i = 0; i < NUMBER; i++) {
		printf("学生[%d]\n", i + 1);
		printf("氏　名 : "); scanf_s("%s", s[i].name, sizeof(s[i].name));
		printf("身　長 : "); scanf_s("%d", &s[i].height);
		printf("体　重 : "); scanf_s("%f", &s[i].weight);
		printf("奨学金 : "); scanf_s("%ld", &s[i].schols);
		putchar('\n');
	}

	puts("/-----ソート方法を選択してください-----/");
	printf("身長昇順:0, 名前(英字)昇順:1  →"); scanf_s("%d", &sw);
	switch (sw) {
	case 0: sort_by_height(s, NUMBER); break;
	case 1: sort_by_name(s, NUMBER); break;
	default: puts("0か1を選択してください");
	}

	for (int i = 0; i < NUMBER; i++) {
		printf("学生[%d]\n", i + 1);
		printf("氏　名 = %s\n", s[i].name);
		printf("身　長 = %d\n", s[i].height);
		printf("体　重 = %f\n", s[i].weight);
		printf("奨学金 = %ld\n", s[i].schols);
		putchar('\n');
	}

	return 0;
}
#endif

#ifdef _1205
#include<math.h>
/*初期残燃料*/
#define FUEL 160.0
/*燃費*/
#define FUEL_ECONOMY 5
#define sqr(n) ((n) * (n))
/*位置情報の構造体*/
typedef struct {
	double x;
	double y;
}Point;
/*車情報の構造体*/
typedef struct {
	Point pt;
	double fuel;
}Car;
/*現在位置から移動先座標までの直線距離*/
double distance_of_pt(Point pa, Point pb) {
	return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}
/*現在位置から指定したX,Y方向までの直線距離*/
double distance_of_xy(Point pa, Point pb) {
	return sqrt(sqr(pa.x - (pa.x + pb.x)) + sqr(pa.y - (pa.y + pb.y)));
}
/*現在の車の状況を表示する*/
void put_info(Car c) {
	printf("現在位置 : (%.2f, %.2f)\n", c.pt.x, c.pt.y);
	printf("残り燃料 : %.2fリットル\n", c.fuel);
	putchar('\n');
}
/*移動と位置の更新を行う(移動不可の時は更新しない)*/
int move(Car* c, Point dest, int sw) {
	double d = 0;
	if (sw == 1) d = distance_of_pt(c->pt, dest);
	else if (sw == 2) d = distance_of_xy(c->pt, dest); 
	if (d > c->fuel) return 0;
	if (sw == 1) c->pt = dest;
	else if (sw == 2) {
		c->pt.x += dest.x;
		c->pt.y += dest.y;
	}
	c->fuel -= d / FUEL_ECONOMY;
	return 1;
}
int main(void) {
	Car mycar = { {0.0,0.0}, FUEL };

	while (1) {
		int select;
		int sw = 1;
		/*移動先の座標*/
		Point dest = { 0 };
		put_info(mycar);
		printf("移動しますか【Yes…1／No…0】 : ");
		scanf_s("%d", &select);
		if (select != 1) break;

		puts("移動方法を選択してください。");
		printf("【目的地の座標…1／X,Yの移動距離…2】 : ");
		scanf_s("%d", &sw);
		if (sw == 1) {
			printf("目的地のX座標 : "); scanf_s("%lf", &dest.x);
			printf("目的地のY座標 : "); scanf_s("%lf", &dest.y);
		}
		else if (sw == 2) {
			printf("X方向の移動距離 : "); scanf_s("%lf", &dest.x);
			printf("Y方向の移動距離 : "); scanf_s("%lf", &dest.y);
		}
		if (!move(&mycar, dest, sw)) puts("\a燃料不足で移動できません。");
	}

	return 0;
}
#endif

