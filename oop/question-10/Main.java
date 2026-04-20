import java.util.IntSummaryStatistics;
import java.util.stream.*;

class Main {

    public static void main(String[] args) {

        IntStream s = IntStream.rangeClosed(1, 10);

        System.out.println(s.sum());

        IntSummaryStatistics stats =
                IntStream.rangeClosed(1, 10).summaryStatistics();

        System.out.println(stats);
    }
}