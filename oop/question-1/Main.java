class Address {
    String city;

    Address(String city) {
        this.city = city;
    }
}

class Student {
    int id;
    String name;
    Address addr;

    Student(int id, String name, Address addr) {
        this.id = id;
        this.name = name;
        this.addr = addr;
    }

    Student(Student s) { // shallow copy
        this.id = s.id;
        this.name = s.name;
        this.addr = s.addr;
    }

    Student(int id, String name, String city) { // deep copy
        this.id = id;
        this.name = name;
        this.addr = new Address(city);
    }

    void show() {
        System.out.println(id + " " + name + " " + addr.city);
    }

    public static void main(String[] args) {
        Address a = new Address("Pune");

        Student s1 = new Student(1, "Akram", a);
        Student s2 = new Student(s1); // shallow
        Student s3 = new Student(2, "Ali", "Mumbai"); // deep

        a.city = "Delhi";

        s1.show();
        s2.show();
        s3.show();
    }
}