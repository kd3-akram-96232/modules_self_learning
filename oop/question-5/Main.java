class TextAnalyzer {

    public static void main(String[] args) {
        String s = "Hello World! 123";

        int v = 0, c = 0, sp = 0;

        s = s.toLowerCase();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if (Character.isLetter(ch)) {
                if ("aeiou".indexOf(ch) != -1)
                    v++;
                else
                    c++;
            } else if (!Character.isDigit(ch) && ch != ' ') {
                sp++;
            }
        }

        System.out.println("Vowels: " + v);
        System.out.println("Consonants: " + c);
        System.out.println("Special: " + sp);
    }
}