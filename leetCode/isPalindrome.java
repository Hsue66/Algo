public boolean isPalindrome(int x){
    if(x < 0)
        return false;
    int res = 0;
    int ori = x;
    while(x != 0){
        res = res*10 + x%10;
        x = x/10;
    }
    if(ori == res)
        return true;
    else
        return false;
}
