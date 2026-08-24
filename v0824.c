#include <stdio.h>
#include <string.h>

struct address {
	char name[30];
	char age[5];
	char phone[15];
};

void print_menu();
void view_list();
void add_list();
void delete_list();


char* fname = "d://data//list.txt";

int main(void) {
	char select = 0;
	puts(" \n === 친구 목록 == \n");

	while (select != 4) {
		print_menu();
		select = getche();
		getchar();

		switch (select)
		{
		case '1': view_list();
			break;
		case '2': add_list();
			break;
		case '3': delete_list();
			break;
		case '4': return;
			break;
		default: printf("\n 잘못 입력했어요. 다시 선택하세요.\n");
		}
	}
	return;
}

void print_menu() {
	printf("\n");
	printf("1. 친구 목록 보기 \n");
	printf("2. 새 친구 저장 \n");
	printf("3. 친구 삭제 하기 \n");
	printf("4. 끝내기 \n");
}

void view_list() {
	char str[200] = "";
	FILE* rfp, * wfp;
	int i;

	rfp = fopen(fname, "r");

	if (rfp == NULL) {
		wfp = fopen(fname, "w");
		fclose(wfp);
		rfp = fopen(fname, "r");
	}

	for (i = 1; ; i++) {
		fgets(str, 200, rfp);

		if (feof(rfp))
			break;

		printf("%2d:  %s", i, str);
	}

	if (i == 1)
		puts("\n ** 리스트에 내용이 하나도 없군요. **\n");

	fclose(rfp);
}

void add_list() {
	struct address adr = { "", "", "" };
	char wstr[200] = "";
	FILE* wfp;

	wfp = fopen(fname, "a");

	printf("이름을 입력 ==> ");
	gets(adr.name);
	printf("나이를 입력 ==> ");
	gets(adr.age);
	printf("전화번호를 입력 ==> ");
	gets(adr.phone);

	strcat(wstr, adr.name);
	strcat(wstr, "\t");
	strcat(wstr, adr.age);
	strcat(wstr, "\t");
	strcat(wstr, adr.phone);
	strcat(wstr, "\n");

	fputs(wstr, wfp);

	fclose(wfp);
}


void delete_list() {




}
