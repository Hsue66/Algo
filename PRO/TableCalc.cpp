#define MAXR		99
#define MAXC		26

struct Elem {
	int val;
	int op;
	int tmp;
	int start[2];
	int finish[2];
};

Elem MAP[MAXR][MAXC];
int r, c;
int checked[MAXR][MAXC];

void init(int C, int R) {
	r = R, c = C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			MAP[i][j].op = MAP[i][j].val = 0;
	}
}

int stoi(char* str) {
	int idx, num;
	idx = num = 0;
	int flag = 1;
	if (!('0' <= str[idx] && str[idx] <= '9')) {
		if (str[idx] == '-')
			flag = -1;
		idx++;
	}
	do {
		num = num * 10 + (str[idx] - '0');
	} while (str[++idx]);
	return num * flag;
}

void divide(char input[], char* left, char* right) {
	int flag = 0;
	for (int i = 0; *input; *input++, i++) {
		if (*input == ',') {
			flag = 1;
			continue;
		}
		if (3 < i && flag == 0)
			* left++ = *input;
		if (flag == 1 && *input != ')')
			* right++ = *input;
	}
	*right = *left = '\0';
}

void set(int col, int row, char input[]) {
	int i = row - 1;
	int j = col - 1;
	if (input[0] <= '9' || input[0] == '-') {// 숫자일 경우
		MAP[i][j].op = 0;
		MAP[i][j].val = stoi(input);
	}
	else {
		MAP[i][j].op = 1;
		char left[4], right[4];
		divide(input, left, right);
		MAP[i][j].start[1] = left[0] - 'A';
		MAP[i][j].start[0] = stoi(left)-1;
		MAP[i][j].finish[1] = right[0] - 'A';
		MAP[i][j].finish[0] = stoi(right)-1;
		switch (input[2]) {
		case 'D':
			MAP[i][j].val = 0;
			break;
		case 'B':
			MAP[i][j].val = 1;
			break;
		case 'L':
			MAP[i][j].val = 2;
			break;
		case 'V':
			MAP[i][j].val = 3;
			break;
		case 'X':
			MAP[i][j].val = 4;
			break;
		case 'N':
			MAP[i][j].val = 5;
			break;
		case 'M':
			MAP[i][j].val = 6;
			break;
		default:
			break;
		}
	}
}

int max(int a, int b) {
	int res = a;
	if (res < b)
		res = b;
	return res;
}

int min(int a, int b) {
	int res = a;
	if (res > b)
		res = b;
	return res;
}

int getVal(int i, int j) {
	if (checked[i][j] == 1) {
		if (MAP[i][j].op == 0)
			return MAP[i][j].val;
		else
			return MAP[i][j].tmp;
	}
	else {
		checked[i][j] = 1;
		if(MAP[i][j].op == 0)
			return MAP[i][j].val;
		else {
			int res;
			switch (MAP[i][j].val) {
			case 0:
				MAP[i][j].tmp = getVal(MAP[i][j].start[0], MAP[i][j].start[1]) + getVal(MAP[i][j].finish[0], MAP[i][j].finish[1]);
				break;
			case 1:
				MAP[i][j].tmp = getVal(MAP[i][j].start[0], MAP[i][j].start[1]) - getVal(MAP[i][j].finish[0], MAP[i][j].finish[1]);
				break;
			case 2:
				MAP[i][j].tmp = getVal(MAP[i][j].start[0], MAP[i][j].start[1]) * getVal(MAP[i][j].finish[0], MAP[i][j].finish[1]);
				break;
			case 3:
				MAP[i][j].tmp = getVal(MAP[i][j].start[0], MAP[i][j].start[1]) / getVal(MAP[i][j].finish[0], MAP[i][j].finish[1]);
				break;
			case 4:
				res = -1000000001;
				for (int i0 = MAP[i][j].start[0]; i0 <=MAP[i][j].finish[0]; i0++) {
					for (int j0 = MAP[i][j].start[1]; j0 <= MAP[i][j].finish[1]; j0++)
						res = max(getVal(i0, j0), res);
				}
				MAP[i][j].tmp = res;
				break;
			case 5:
				res = 1000000001;
				for (int i0 = MAP[i][j].start[0]; i0 <= MAP[i][j].finish[0]; i0++) {
					for (int j0 = MAP[i][j].start[1]; j0 <=MAP[i][j].finish[1]; j0++)
						res = min(getVal(i0, j0), res);
				}
				MAP[i][j].tmp = res;
				break;
			case 6:
				res = 0;
				for (int i0 = MAP[i][j].start[0]; i0 <= MAP[i][j].finish[0]; i0++) {
					for (int j0 = MAP[i][j].start[1]; j0 <= MAP[i][j].finish[1]; j0++) 
						res += getVal(i0, j0);
				}
				MAP[i][j].tmp = res;
				break;
			default:
				break;
			}
			return MAP[i][j].tmp;
		}
	}
}

void update(int value[MAXR][MAXC]) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			checked[i][j] = 0;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
				value[i][j] = getVal(i, j);
		}
	}
/*
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << value[i][j] << " ";

		}cout << endl;
	}*/
}

/*
void test() {
	int R, C;
	R = C = 5;
	init(R, C);

	set(3, 2, (char*)"5");
	set(5, 2, (char*)"13");
	set(1, 5, (char*)"2");
	set(2, 1, (char*)"6");
	set(1, 1, (char*)"-9");
	set(3, 4, (char*)"9");
	set(2, 2, (char*)"3");
	set(2, 4, (char*)"7");
	set(5, 3, (char*)"2");
	set(3, 1, (char*)"5");
	int value[MAXR][MAXC];
	update(value);
}*/
