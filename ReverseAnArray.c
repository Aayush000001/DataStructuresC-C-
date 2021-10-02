#include <stdio.h>
/*
 * @author: Aayush Gulia
 * email: aayushgulia07@outlook.com
 */
struct Array{
    int arr[10];
    int length;
};

void Reverse(struct Array *arr){ // reverse using auxiliary array. ---> (n)
    int tempArray[10];
    for(int i=arr->length-1,j=0;i>=0;i--,j++){
        tempArray[j]=arr->arr[i];
    }
    for(int i=0;i<arr->length;i++){
        arr->arr[i]=tempArray[i];
    }
}

void Reverse2(struct Array *arr){  // reversing an array by using swapping. ---> (n)
    for(int i=0,j=arr->length-1;i<j;i++,j--){
        int temp;
        temp=arr->arr[i];
        arr->arr[i]=arr->arr[j];
        arr->arr[j]=temp;
    }
}

void Display(struct Array arr){ // this display method takes linear time ---> (n),
    for(int i=0;i<arr.length;i++){
        printf("%d ", arr.arr[i]);
    }
}

int main(){
    // Time complexity is O(n).
    struct Array arr = {{1,2,3,4,5,6}, 6};
    Reverse2(&arr);
    Display(arr);
}