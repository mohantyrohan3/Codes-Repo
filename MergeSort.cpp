void merge(int input[],int si,int mid,int ei){
	int output[ei-si+1],k=0,i=si,j=mid+1;	
    while(i<=mid && j<=ei){
        if(input[i]<input[j]){
            output[k]=input[i];
            k++;
            i++;
        }
        else{
            output[k]=input[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        output[k++]=input[i++];
    }
    while(j<=ei){
        output[k++]=input[j++];
    }
    
    for(i = si; i <= ei; i++) {
		input[i] = output[i - si];
	}
    
    
    
}

void help(int input[],int si,int ei){
    if(si>=ei){
        return; 
    }
    int mid=(si+ei)/2;
    help(input,si,mid);
    help(input,mid+1,ei);
    merge(input,si,mid,ei);
    
    
}

void mergeSort(int input[], int size){
	// Write your code here
	help(input,0,size-1);
}
