package Week_3.oops.RailwayCompartment;
import java.util.Random;

public class TestCompartment {
    public static void main(String[] args) {
        // Declare an array of Compartment of size 10
        Compartment[] compartments = new Compartment[10];
        
        // Create Random object to generate random numbers
        Random random = new Random();
        
        // Fill the array with random compartment types
        System.out.println("Creating 10 compartments with random types...\n");
        
        for (int i = 0; i < compartments.length; i++) {
            // Generate random number between 1 and 4
            int randomNumber = random.nextInt(4) + 1; // 1 to 4
            
            // Create compartment based on random number
            switch (randomNumber) {
                case 1:
                    compartments[i] = new FirstClass();
                    System.out.println("Compartment " + (i+1) + ": First Class");
                    break;
                case 2:
                    compartments[i] = new Ladies();
                    System.out.println("Compartment " + (i+1) + ": Ladies");
                    break;
                case 3:
                    compartments[i] = new General();
                    System.out.println("Compartment " + (i+1) + ": General");
                    break;
                case 4:
                    compartments[i] = new Luggage();
                    System.out.println("Compartment " + (i+1) + ": Luggage");
                    break;
            }
        }
        
        // Demonstrate polymorphic behavior
        System.out.println("\n=== Polymorphic Notice Display ===");
        System.out.println("Each compartment displays its specific notice:\n");
        
        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Compartment " + (i+1) + ": " + compartments[i].notice());
            System.out.println("----------------------------------------");
        }
        
        // Additional demonstration of polymorphism
        System.out.println("\n=== Polymorphism in Action ===");
        System.out.println("Even though we're calling notice() on Compartment references,");
        System.out.println("each one executes its own subclass implementation!\n");
        
        // Demonstrate with specific examples
        Compartment comp1 = new FirstClass();
        Compartment comp2 = new Ladies();
        Compartment comp3 = new General();
        Compartment comp4 = new Luggage();
        
        System.out.println("comp1 (FirstClass reference): " + comp1.notice());
        System.out.println("comp2 (Ladies reference): " + comp2.notice());
        System.out.println("comp3 (General reference): " + comp3.notice());
        System.out.println("comp4 (Luggage reference): " + comp4.notice());
    }
}