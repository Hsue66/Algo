public String longestCommonPrefix(String[] str){
    int index = -1;
    int cnt = str.length;
    boolean done = false;

    if(cnt == 1){
        return str[0];
    }

    int len = str[0].length();
    for(int c=1; c<cnt; c++)
        len = Math.min(len,str[c].length());

    while(!done){
        index++;
        if(index >= len)
            break;
        for(int c=1; c<cnt; c++){
            if(str[0].charAt(index) != str[c].charAt(index))
                done = true;
        }
    }
    return str[0].substring(0,index);
}
