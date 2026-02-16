#include <bits/stdc++.h>
using namespace std;
int max_size=10000;
struct minheap{
    int*heap=new int[max_size]; 
    int size;
    minheap():size(0){};
    int parent(int i){
    return (i-1)/2;
}
    int left(int i){
        return i*2+1;
    }
    int right(int i){
        return i*2+2;
    }

    int i=size;
    void insert(int v){
        if(size>=max_size) return;

        heap[size]=v;
        int i=size;
        size++;

        while(i>0 && heap[parent(i)]>heap[i]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout << heap[i] << ' ';
        }
    }

    int extract_min(){
        if(size==0) return;
        if(size==1){
            size--;
            return heap[0];
        }
        int root=heap[0];
        heap[0]=heap[size-1];
        size--;
        heapify(0);
        return root;
    }

    void heapify(int i){
        int smallest=i;
        int l=left(i);
        int r=right(i);

        if(l<size && heap[l]<heap[smallest]){
            l=smallest; 
        }
        if(r<size && heap[r]<heap[smallest]){
            r=smallest; 
        }

        if(smallest!=i){
            swap(heap[i],heap[smallest]);
            heapify(smallest);
        }
    }
};

int main(){

}