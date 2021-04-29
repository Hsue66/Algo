public class ReverseInteger {
    int Min = -2147483648;
    int Max = 2147483647;

    public int reverse(int x){
        long res = 0;
        int sign = 1;
        if(x < 0){
            sign  = -1;
            x *= sign;
        }

        while(x != 0){
            res = res*10 + x%10;
            x = x/10;
        }

        if(res < Min || Max < res)
            res = 0;

        return ((int)res)*sign;
    }
}
