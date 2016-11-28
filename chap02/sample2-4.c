#include <stdio.h>
/* Code to print the byte representation of program objects. This code uses casting to circumvent the type system. Similar functions are easily defined for other data types. */
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len);
void show_int(int x);
void show_float(float x);
void show_pointer(void *x);

int main(){
	int x = 100;
	float y = 100.0;
	void *z;

	show_int(x);
	show_float(y);
	show_pointer(z);
	return 0;
}

void show_bytes(byte_pointer start, int len){
	int i;
	for (i = 0; i < len; i++)
		printf("%.2x ", start[i]);
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}
