void heapSort(int arr[], int n) {
    // Write your code
    //inserting elements
    
    for(int i=1;i<n;i++){
        int childindex=i;
        while(childindex>0){
            int parentindex=(childindex-1)/2;
            if(arr[childindex]<arr[parentindex]){
                int temp=arr[childindex];
                arr[childindex]=arr[parentindex];
                arr[parentindex]=temp;
            }
            else{
                break;
            }
            childindex=parentindex;
        }
    }
    //removing elements
    
    int size=n;
    
    while(size>1){
        int temp1=arr[size-1];
        arr[size-1]=arr[0];
        arr[0]=temp1;
        
        size--;
        int parentindex=0;
        int leftindex=2*parentindex+1;
        int rightindex=2*parentindex+2;
        
        
        while(leftindex<size){
            int minindex=parentindex;
            if(arr[leftindex]<arr[minindex]){
                minindex=leftindex;
            }
            if(rightindex<size&&arr[rightindex]<arr[minindex]){
                minindex=rightindex;
            }
            if(minindex==parentindex){
                break;
            }
            int temp2=arr[minindex];
            arr[minindex]=arr[parentindex];
            arr[parentindex]=temp2;
            
            parentindex=minindex;
            leftindex=2*parentindex+1;
            rightindex=2*parentindex+2;
        }
    }
}