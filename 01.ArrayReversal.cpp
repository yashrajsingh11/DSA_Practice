string reverseWord(string str){
    char temp;
    for(int i = 0; i < str.length() / 2; i++) {
        temp = str[i];
        str[i] = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = temp;
    }
    return str;
}