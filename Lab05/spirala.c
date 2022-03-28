//Jakub Domogała
//100%

//Treść: PDF

int main()
{
    int n;
    scanf("%d",&n);
    int T[n][n];
    int d,g,l,p,kolumna,wiersz,a=0;
    d=n-1;
    g = 0;
    l = 0;
    p = n-1;
    a = 1;
    kolumna = 0;
    wiersz = 0;
    while(a<=n*n)
    {
        while (kolumna <= p)
        {
            T[wiersz][kolumna] = a;
            kolumna +=1 ;
            a += 1;
        }
        p -= 1;
        kolumna -=1;
        wiersz += 1;

        while (wiersz <= d)
        {
            T[wiersz][kolumna] = a;
            wiersz +=1 ;
            a += 1;
        }

        d -= 1;
        kolumna -=1;
        wiersz -= 1;

        while (kolumna >= l)
        {
            T[wiersz][kolumna] = a;
            kolumna -=1 ;
            a += 1;
        }
        l += 1;
        kolumna +=1;
        wiersz -= 1;

        while (wiersz > g)
        {
            T[wiersz][kolumna] = a;
            wiersz -=1 ;
            a += 1;
        }
        g += 1;
        kolumna +=1;
        wiersz += 1;

    }

    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n;j++)
        {
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
}