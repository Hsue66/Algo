public class Solution {
    public boolean isValid(String s) {
        Stack stack = new Stack();
        int len = s.length();

        if(len%2 != 0)
            return false;

        if(s.charAt(0) == '(' || s.charAt(0) == '{' || s.charAt(0) == '[')
            stack.push(s.charAt(0));
        else
            return false;

        for(int i=1; i<len; i++){
            switch (s.charAt(i)){
                case ')':
                    if(stack.empty() || !stack.peek().equals('('))
                        return false;
                    stack.pop();
                    break;
                case '}':
                    if(stack.empty() || !stack.peek().equals('{'))
                        return false;
                    stack.pop();
                    break;
                case ']':
                    if(stack.empty() || !stack.peek().equals('['))
                        return false;
                    stack.pop();
                    break;
                default:
                    stack.push(s.charAt(i));
            }
        }

        if(stack.empty())
            return true;
        else
            return false;
    }
  }
