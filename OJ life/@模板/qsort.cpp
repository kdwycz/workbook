void qsort(int l,int r){
	int i=l,j=r,mid=a[(l+r)/2];
	while (i<=j){
		while (a[i]<mid) ++i;
		while (a[j]>mid) --j;
		if (i<=j) swap(a[i++],a[j--]);
	}
	if (j>l) qsort(l,j);
	if (i<r) qsort(i,r);
}
