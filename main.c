#include <stdio.h>
#include <malloc.h>


struct Rectangle{
    int length;
    int breadth;
};

int sum(int n){
    if(n==0){
        return 0;
    }
    return sum(n-1)+n;
}

int Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}

int area(struct Rectangle *rectangle){
    rectangle->length=20;rectangle->breadth=10;
    return rectangle->length*rectangle->breadth;
}

struct Array{
    int A[10];
    int size;
    int length;

};

void Display(struct Array array){
    for (int i = 0; i < array.length; ++i) {
        printf("%d ", array.A[i]);
    }
}

void Append(struct Array *arr, int x){
    if(arr->length<arr->size){
        arr->A[arr->length++]=x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if(index>=0 && index<arr->size){
        for (int i=arr->length;i>index;i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{
    for(int i=index;i<arr->length-1;i++){
        int x = arr->A[index];
        arr->A[i]=arr->A[i+1];
    }
    arr->length--;
}
int LinearSearch(struct Array *arr, int key){
    for (int i=0; i<arr->length; i++){
        if(key == arr->A[i]){
            Swap(&arr->A[i], &arr->A[i-1]); // Transposition
            //Swap(&arr->A[i], &arr->A[0]);  // Move to front OR Move to head.
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l,h,mid;
    l = 0;
    h = arr.length-1;
    while(l<=h){
        mid = (l+h)/2;
        if(key==arr.A[mid]){
            return mid;
        }
        else if(key<arr.A[mid]){
            h = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return -1;
}

int Get(struct Array arr, int index){
    return arr.A[index];
}
void Set(struct Array *arr, int element, int index){
    arr->A[index] = element;
    printf("Element inserted at given index: 1\n");
}
int Max(struct Array arr){
    int max=arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(max<arr.A[i]){
            max=arr.A[i];
        }
    }
    return max;
}
int Min(struct Array arr){
    int min=arr.A[0];
    for(int i=1; i<arr.length; i++ ){
        if(min>arr.A[i]){
            min=arr.A[i];
        }
    }
    return min;
}

float Average(struct Array arr){
    float total;
    for(int i=0; i<arr.length; i++){
        total = total + arr.A[i];
    }
    return (float)total/arr.length;
}

void Reverse(struct Array *arr){ //using a temporary array
    int TempArray[9];
    for(int i=arr->length-1,j=0;i>=0;i--,j++){
        TempArray[j] = arr->A[i];
    }
    for (int i=0;i<arr->length;i++){
        arr->A[i] = TempArray[i];
    }
}

void RightShiftByOne(struct Array *arr){ //Right shift array by 1 element.
    //Q what if we want to shift it by 2 elements ?
    int x = arr->A[0];
    for(int i=0;i<=arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
    }
    arr->A[arr->length-1] = x;
}

void RightShiftByTwo(struct Array *arr){
    int x;
    int y;
    x = arr->A[0];
    y = arr->A[1];
    for (int i=0;i<arr->length;i++){
        arr->A[i] = arr->A[i+2];
    }
    arr->A[arr->length-1] = y;
    arr->A[arr->length-2] = x;
}

void Reverse2(struct Array *arr){
    int i,j;
    for(i=0,j=arr->length-1;i<j;i++,j--){
        // we can use previously written Swap function.
        Swap(&arr->A[i],&arr->A[j]);
        // we have to swap elements;
//        int temp = arr->A[i];
//        arr->A[i] = arr->A[j];
//        arr->A[j] = temp;
    }
}

void InsertInSortedArray(struct Array *arr, int element){
    int x = element;
    int i = arr->length-1;

    while(arr->A[i]>x){
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}

void IsSorted(struct Array arr, int n){
    for(int i=0;i<n-1;i++){
        if(arr.A[i]>arr.A[i+1]){
            printf("False");
            return;
        }
    }
    printf("True");
}

void Rearrange(struct Array *arr){
    int i=0;
    int j=arr->length-1;
    while(i<j){
        while(arr->A[i]<0){
            i++;
        }
        while(arr->A[j]>=0){
            j--;
        }
        if(i<j){
            Swap(&arr->A[i], &arr->A[j]);
        }
    }
}

struct Array* Merging(struct Array *arr1,struct Array*arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            k++;
            i++;

        }
        else
        {
            arr3->A[k]=arr2->A[j];
            k++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k] = arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        arr3->A[k] = arr2->A[j];
        k++;
    }
    arr3->length = arr1->length+arr2->length;
    arr3->size=10;

    return arr3;

}

struct Array * Union(struct Array *arr1, struct Array *arr2){
    int i,j,k;
    i=j=k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            k++;
            i++;
        }
        else if(arr2->A[j]<arr1->A[i]){
            arr3->A[k]=arr2->A[j];
            k++;
            j++;
        }
        else{
            arr3->A[k]=arr1->A[i];
            i++;
            k++;
            j++;
        }
    }
    for(;i<arr1->length;i++){
        arr3->A[k]=arr1->A[i];
        k++;
    }
    for(;j<arr2->length;j++){
        arr3->A[k]=arr2->A[j];
        k++;
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

struct Array * Intersection(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]==arr2->A[j]){

            arr3->A[k]=arr1->A[i];
            k++;
            i++;
            j++;
        }
        else{
            i++;
            j++;
        }
    }
    arr3->length=k;
    arr3->size=10;
    return arr3;
}

struct Array * Difference(struct Array *arr1, struct Array *arr2){
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
//    int i,j,k;
//    i=j=k=0;

//    struct Array *arr3=(struct Array *)malloc(sizeof(struct
//            Array));
//
//    while(i<arr1->length && j<arr2->length)
//    {
//        if(arr1->A[i]<arr2->A[j])
//            arr3->A[k++]=arr1->A[i++];
//        else if(arr2->A[j]<arr1->A[i])
//            j++;
//        else
//        {
//            i++;
//            j++;
//        }
//    }
//    for(;i<arr1->length;i++)
//        arr3->A[k++]=arr1->A[i];
//
//
//    arr3->length=k;
//    arr3->size=10;
//
//    return arr3;
    int i,j,k;
    i=j=k=0;
    while(i<arr1->length && j<arr2->length){
        if(arr1->A[i]<arr2->A[j]){
            arr3->A[k]=arr1->A[i];
            k++;
            i++;
        }
        else if(arr2->A[j]>arr1->A[i]){
            j++;
        }
        else{
            i++;j++;
        }
    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;
    return arr3;
}


int main(){
    struct Array arr = {{1,-1,0,4,-74,8,9,-2},10,8};
    struct Array array = {{2,4,6,8,10},10,5};
    struct Array arr1 = {{1,2,3,4,5}, 10,5};
    struct Array arr2 = {{1,2,3,6,7}, 10,5};
    struct Array *arr3;
//    arr3=Merging(&arr1,&arr2);
    arr3=Difference(&arr1,&arr2);
    Display(*arr3);
//    InsertInSortedArray(&arr,3);


//    RightShiftByOne(&array);
//    Display(&array);
//    printf("\n");
//    Display(&array);
//    RightShiftByTwo(&array);
//    Display(&array);

//    int Ary[] = {1,2,3,4,5,6,7,8,9};
//    int TempAry[9];
//    int i,j;
//    for (i=9-1,j=0;i>=0;i--,j++){
//        TempAry[j]=Ary[i];
//        printf("%d\n",TempAry[j]);
//    }


//    printf("maximum element is : %d\n", Max(arr));
//    printf("minimum element is : %d\n", Min(arr));
//    printf("average element is : %f\n", Average(arr));


    //    int searchResult = BinarySearch(arr,74);
//    printf("%d\n", searchResult);











//    struct Rectangle r = {10,5};
//    printf("rectangle 1 length and breadth is : %d %d \n", r.length,r.breadth);
//    printf("Area of rectangle is :  %d \n", r.breadth*r.length);
//    int areaOfRectangle =  area(&r);
//    printf("area of rectangle 1.1 %d\n", areaOfRectangle);

//    int a=500,b=250;
//    int *p;
//    Swap(&a,&b);
//    printf("%d ", a);

//    struct Rectangle r = {10,5};
//    struct Rectangle *p;

//    p = (struct Rectangle*)malloc(sizeof(struct Rectangle)); //dynamic allocation of memory.
//    p->length=15;
//    printf("%d\n", p->length);


//    struct Rectangle r = {10,5}; //declaration
//    int *p; // initialization we have to use *
//    int *f;
//    f = (int *)malloc(10*sizeof(int));
//    f[0]=10;
//    f[9]=90;
//    printf("%d\n", f[9]);
//    int A = 37;
//    p=&A; //storing address of variable A by using & sign.
//    printf("%d\n", *p); //dereferencing we have to use *
}
