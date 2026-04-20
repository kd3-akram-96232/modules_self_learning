import java.util.*;

class Student {
    int roll;
    String name;
    String city;
    double marks;

    Student(int roll, String name, String city, double marks) {
        this.roll = roll;
        this.name = name;
        this.city = city;
        this.marks = marks;
    }

    void show() {
        System.out.println(roll + " " + name + " " + city + " " + marks);
    }
}

public class Main {

    public static void main(String[] args) {

        Student[] arr = {
            new Student(1, "Akram", "Pune", 85),
            new Student(2, "Ravi", "Mumbai", 90),
            new Student(3, "Aman", "Pune", 90),
            new Student(4, "Zaid", "Mumbai", 85)
        };

        Arrays.sort(arr, (a, b) -> {
            int c1 = b.city.compareTo(a.city);   // city desc
            if (c1 != 0) return c1;

            int c2 = Double.compare(b.marks, a.marks); // marks desc
            if (c2 != 0) return c2;

            return a.name.compareTo(b.name); // name asc
        });

        for (Student s : arr) {
            s.show();
        }
    }
}