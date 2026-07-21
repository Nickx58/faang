import java.util.Scanner;

public class FirstClass {
   public static void main(String[] args) {
        int currentYear = 2026;

        Scanner scanner = new Scanner(System.in);
        System.out.println("Hi, What is your Name");
        String name = scanner.nextLine();
        System.out.println("Hi " + name + " Nice to meet you. Lets cal your age. Enter your DOB.");
        String dob = scanner.nextLine();
        int age = currentYear - Integer.parseInt(dob);
        System.out.println("So you are " + age + " years old");
    }
}
