int BinSearch(int Array[],int low,int high,int key)
{
    int mid;
    if(low>high) return -1;
	mid=(low+high)/2;
	if(key==Array[mid]) return mid;
	if(key>Array[mid]) return BinSearch(Array,mid+1,high,key);
	if(key<Array[mid]) return BinSearch(Array,low,mid-1,key);
}
