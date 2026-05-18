// import java.util.Scanner;

// public class App {
//     public static void main(String[] args) throws Exception {
//         Scanner scanner = new Scanner(System.in);

//         System.out.print("Enter roll: ");
//         int roll = scanner.nextInt();

//         System.out.print("Enter username: ");
//         scanner.nextLine();
//         String username = scanner.nextLine();

//         System.out.print("Enter marks: ");
//         double marks = scanner.nextDouble();

//         System.out.println( "roll: " + roll + ", username: " + username +", marks: " + marks);

//     }
// }

// public class App {
//     public static void main(String[] args){
//         int one = 10;
//         byte two = (byte) one;

//         // byte - 1
//         // short - 2
//         // char - 2
//         // int - 4
//         // float - 4
//         // long - 8
//         // double - 8
//     }
// }

// TODO: For each:

// public class App {
//     public static void main(String[] args){
//         int[] arr = new int[5];

//         for(int i = 0; i < arr.length; i++){
//             arr[i] = i * 10;
//         }

//         for(final int elm : arr){
//             System.out.println(elm);
//         }

//     }
// }

// Todo: Boxing and Unboxing

// public class App {
// public static void main(String[] args){
/* 
     int i = 12;
     Integer integer = new Integer(i); // boxing
     Integer k = i; // auto-boxing

        (Stack)    |    (Heap)
       i = 123     |
       j integer   |   new Integer(i) ( 123 )
        K          |   new Integer(i) ( 123 )
                   |

*/
// }
// }

// Todo: Create employee class

// import java.util.ArrayList;
// import java.util.Scanner;

// class Employee {
//     private String fullName;
//     private int rollNumber;
//     private double marks;

//     public Employee() {
//     }

//     public Employee(String fullName, int rollNumber, double marks) {
//         this.fullName = fullName;
//         this.rollNumber = rollNumber;
//         this.marks = marks;
//     }

//     void accept(Scanner scanner) {
//         System.out.print("Enter full name: ");
//         scanner.nextLine();
//         fullName = scanner.nextLine();
//         System.out.print("Enter roll number: ");
//         rollNumber = scanner.nextInt();
//         System.out.print("Enter marks: ");
//         marks = scanner.nextDouble();
//     }

//     void display() {
//         System.out.println("Full full name: " + fullName);
//         System.out.println("Full roll number: " + rollNumber);
//         System.out.println("Full marks: " + marks);
//     }

// }

// public class App {

//     static void printActions() {
//         System.out.println("1. Add employee.");
//         System.out.println("2. Show all employees.");
//     }

//     static int menuList(ArrayList<Employee> emps, Scanner scan) {
//         printActions();
//         int choice;
//         System.out.print("Enter choice: ");
//         choice = scan.nextInt();

//         switch (choice) {
//             case 1:{
//                 Employee emp = new Employee();
//                 emp.accept(scan);
//                 emps.add(emp);
//                 break;
//             }
//             case 2:{
//                 for(Employee emp : emps){
//                     emp.display();
//                 }
//                 break;
//             }
//             default:
//                 {
//                     System.out.println("Program exit!");
//                     break;
//                 }
//         }

//         return choice;

//     }

//     public static void main(String[] args) {
//         ArrayList<Employee> list = new ArrayList<Employee>();
//         Scanner scanner = new Scanner(System.in);
//         while (menuList(list, scanner) != 0) {
//         }

//         scanner.close();

//     }

// }

// TODO: Calender class

// import java.util.Calendar;
// import java.util.Scanner;
// import java.util.spi.CalendarNameProvider;

// class Date {
//     private int day;
//     private int month;
//     private int year;

//     public Date(){
//         day = 0;
//         month = 0;
//         year = 0;
//     }
//     public Date(int day, int month, int year){
//         this.day = day;
//         this.month = month;
//         this.year = year;
//     }

//     public void initializeDate(){
//         Calendar c = Calendar.getInstance();
//         day = c.get(Calendar.DATE);
//         month = c.get(Calendar.MONTH);
//         year = c.get(Calendar.YEAR);
//     }

//     public void accept(Scanner scanner){
//         System.out.print("Enter day: ");
//         this.day = scanner.nextInt();
//         System.out.print("Enter month: ");
//         this.month = scanner.nextInt();
//         System.out.print("Enter year: ");
//         this.year = year;
//     }

//     public void display(){
//         System.out.println("day: " + day + ", month: " + month + ", year: " + year);
//     }

// }


// public class App {
//     public static void main(String[] args) {
//         Scanner scanner  = new Scanner(System.in);
//         Date date = new Date();
//         date.initializeDate();

//         date.display();
//     }
// }

// cqlsh 192.168.1.10 9042 -u admin -p mypassword

// java Program.java 10 20 30
// mysql -u admin -p mypassword