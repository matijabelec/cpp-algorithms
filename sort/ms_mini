void ms(int* p, int a, int b) {
    if(a<b) {
        int k = (a+b)/2;
        ms(p, a, k);
        ms(p, k+1, b);
        int i=a, j=k+1, c=0;
        int *p2 = new int[b-a+1];
        while(i<=k && j<=b)
            p2[c++] = p[ (p[i]<=p[j] ? i++ : j++) ];	
        if(i>k)
            while(j<=b) p2[c++] = p[j++];
        else
            while(i<=k) p2[c++] = p[i++];
        for(int m=a; m<=b; m++) p[m] = p2[m-a];
        delete[] p2;
    }
}

//ms(p, 0, n-1)
