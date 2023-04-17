import java.util.Scanner;

public class Coffee {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Integer[] ords = { 102, 109, 95, 106, 119, 61, 89, 117, 41, 108, 41, 106, 55, 68, 98, 110, 32, 119, 77, 93, 34, 139, 43, 118, 88, 101, 96, 152 };
        
        System.out.println("What would you like to drink?");
        String flag = scanner.nextLine();
        scanner.close();

        Boolean solved = true;

        for(int i = 0; i < ords.length; i++) {
            if(i % 2 == 1){
                if((int) flag.charAt(i) != ords[i] - i) {
                    System.out.println("This coffee is tasting a little bit... odd.");
                    solved = false;
                    break;
                }
            } else {
                if((int) flag.charAt(i) != ords[i] + i) {
                    System.out.println("This coffee a bit too even for my taste.");
                    solved = false;
                    break;
                }
            }
        }

        if(solved) {
            System.out.println("My favorite coffee, " + flag + "!");
        } else {
            System.out.println("Try again. ;D");
        } 
    }
}
