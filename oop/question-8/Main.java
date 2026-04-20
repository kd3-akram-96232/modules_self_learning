import java.util.stream.*;

class Fact {

    public static void main(String[] args) {
        int n = 5;

        int res = IntStream.rangeClosed(1, n)
                .reduce(1, (a, b) -> a * b);

        System.out.println(res);
    }
}