#include <iostream>

char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}

inline int readInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();

	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

inline void swap(int * a, int * b) {
	int tmp = *a; *a = *b; *b = tmp;
}

int heap[100001] = {0,};
int heap_count = 0;

inline bool condition(int parent, int child){
    return abs(heap[parent]) > abs(heap[child])
        || (abs(heap[parent]) == abs(heap[child]) && heap[parent] > heap[child]); 
}

void push(int data){
    heap[++heap_count] = data;

    int child = heap_count;
    int parent = child / 2;

    while(child > 1 && condition(parent, child)){
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}

int pop(){
    int result = heap[1];
    swap(&heap[1], &heap[heap_count--]);

    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= heap_count) {
        child = (condition(child+1,child)) ? child : child + 1;
    }

    while(child <= heap_count && condition(parent, child)){
        swap(&heap[parent], &heap[child]);
        parent = child;
        child = parent * 2;
        if(child + 1 <= heap_count) {
            child = (condition(child+1,child)) ? child : child + 1;
        }
    }

    return result;
}

int main(){
    int N,i;
    N = readInt();
    for(i=0;i<N;i++){
        int data;
        data = readInt();
        if(data == 0) {
            if(heap_count == 0) printf("0\n");
            else printf("%d\n",pop());
        }
        else push(data);
    }
}