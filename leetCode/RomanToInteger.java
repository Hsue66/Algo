package Leet;

public class RomanToInteger {
    int getVal(char c){
        switch (c){
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
        }
        return 0;
    }

    public int romanToInt(String s){
        int res = 0; int before = 10000;
        int len = s.length();
        for(int i=0; i<len; i++){
            int now = getVal(s.charAt(i));
            if(before-now <0)
                res = res + now - (before*2);
            else
                res += now;
            before = now;
        }
        return res;
    }

    public static void main(String[] args) {
        RomanToInteger roman = new RomanToInteger();
        String s = "MCMXCIV";
        System.out.println(roman.romanToInt(s));
    }
}
