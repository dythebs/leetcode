class Solution {
    public String addStrings(String num1, String num2) {
        int[] num = new int[5200];
        if (num1.length() < num2.length()) {
            String temp = num1;
            num1 = num2;
            num2 = temp;
        }
        int carry = 0;
        int offset = num1.length() - num2.length();
        int numindex = 0;
        for (int i = num2.length() - 1 ; i >= 0 ; i--) {
            int temp = carry + (num2.charAt(i) - '0') + (num1.charAt(offset + i) - '0');
            if (temp >= 10) {
                carry = 1;
                temp %= 10;
            } else {
                carry = 0;
            }
            num[numindex++] = temp;
        }
        for (int i = offset - 1 ; i >= 0 ; i--) {
            int temp = carry + (num1.charAt(i) - '0');
            if (temp >= 10) {
                carry = 1;
                temp %= 10;
            } else {
                carry = 0;
            }
            num[numindex++] = temp;
        }

        if (carry == 1) {
            num[numindex] = 1;
        } else {
            numindex -= 1;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = numindex ; i >= 0 ; i--) {
            sb.append(num[i]);
        }
        return sb.toString();
    }
}