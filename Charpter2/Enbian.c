#include <stdio.h>

// mac上执行结果说明：mac是用小端法表示的机器。

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len) {
int i;
for (i=0; i<len; i++)
printf(" %.2x",start[i]);
printf("\n");
}

void show_int(int x) {
show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val) {
    int ival = val;
    float fval = (float) ival;
    int *pval = &ival;
    show_int(ival);
    show_float(ival);
    show_pointer(ival);
}

int main(int argc, char const *argv[]) {
	for (int i=0; i<sizeof(argv)/sizeof(argv[0]); i++) {
		test_show_bytes(&argv[i]);
	}
    
    return 0;
}

