/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int arr[],int st,int mid,int end){
    int i=st, j= mid+1,k=0;
    int size = end-st+1;
     int* temp = (int*)malloc(size * sizeof(int));

    while(i<= mid && j<=end){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else temp[k++] = arr[j++];
    }
    while( i<= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(int i=0;i<size;i++){
        arr[st+i] = temp[i];
    }
    free(temp);
}

void mg(int arr[],int st,int end){
    if(st<end){
        int mid = st + (end - st)/2;

        mg(arr,st,mid);//left
        mg(arr,mid+1,end);//right;

        merge(arr,st,mid,end);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    mg(nums,0,numsSize -1);

    return nums;
}