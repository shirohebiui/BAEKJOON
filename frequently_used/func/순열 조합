// https://cocoon1787.tistory.com/81


long factorial_combination(int N, int R)
{
    long long result = 1;
    int i = R+1;
    int j = 1;
    long tmp=j;
    while(1)
    {
        if(i < N+1)
            result *= i;
        if(j < N-R+1)
            tmp *= j;
        if(result % tmp == 0)
        {
            result /= tmp;
            tmp = 1;
        }
        if(!( i < N && j < N-R+1)) {
            break;
            result /= tmp;
        }
        i++; j++;
    }
    return result;
}

long factorial(int num)
{
    long result = 1;
    for (int i = 1; i <= num; ++i)
    {
        result = result * i;
    }
    return result;
}

long combination(int n, int r)
{
    if(n<20) //이걸 정하는게 핵심
        return factorial(n)/(factorial(r) * factorial(n-r));
    else
        return combination(n-1, r-1) + combination(n-1, r);
}