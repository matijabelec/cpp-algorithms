void qs(int* p, int a, int b) {
    int i=a, j=b;
    int m=p[a], s;
    while(i<=j) {
        while(p[i] < m) i++;
        while(p[j] > m) j--;
        if(i<=j) {
            s=p[i]; p[i]=p[j]; p[j]=s;
            i++; j--;
        }
    }
    if(a<j) qs(p, a, j);
    if(i<b) qs(p, i, b);
}

//qs(p, 0, n-1)
