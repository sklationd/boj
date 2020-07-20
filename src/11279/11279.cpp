#include <iostream>

using namespace std;

void swap(int * a, int * b) {
	int tmp = *a; *a = *b; *b = tmp;
}

int heap[100001] = {0,};
int heap_count = 0;

void push(int data){
    heap[++heap_count] = data;

    int child = heap_count;
    int parent = child / 2;

    while(child > 1 && heap[parent] < heap[child]){
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
        child = (heap[child] > heap[child+1]) ? child : child + 1;
    }

    while(child <= heap_count && heap[parent] < heap[child]){
        swap(&heap[parent], &heap[child]);
        parent = child;
        child = parent * 2;
        if(child + 1 <= heap_count) {
            child = (heap[child] > heap[child+1]) ? child : child + 1;
        }
    }

    return result;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        int data;
        cin >> data;
        if(data == 0) {
            if(heap_count == 0) cout << 0 << "\n";
            else cout << pop() << "\n";
        }
        else push(data);
    }
}