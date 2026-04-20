enum Day {
    MON, TUE, WED, THU, FRI, SAT, SUN;

    boolean isWeekend() {
        return this == SAT || this == SUN;
    }

    boolean isWeekday() {
        return !isWeekend();
    }
}

class TestDay {
    public static void main(String[] args) {
        Day d = Day.SAT;

        System.out.println(d.isWeekend());
        System.out.println(d.isWeekday());
    }
}