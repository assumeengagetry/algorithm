public class GravityCalculator {
public static void newline(){
    System.out.println(" ");
}
public static void threelines(){
    newline();
    newline();
    newline();
}
public static void main(String[] args) {
    
    System.out.println("Welcome to the Gravitational Calculator!");
    threelines();

    String five  =  Integer.toString(5);
    System.out.println("The number of planets in the solar system is " + five);
    int six = Integer.parseInt("6");
    System.out.println("The number of planets in the solar system is " + six);
    System.err.println("This program will calculate the gravitational force between two objects.");
    
}
}
