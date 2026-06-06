// LibraryInterfaceDemo.java

interface LibraryUser {
    void registerAccount();
    void requestBook();
}

class KidUser implements LibraryUser {
    int age;
    String bookType;

    public void registerAccount() {
        if(age < 12){
            System.out.println("You have succesfully registred under a Kids Account");
        } else {
            System.out.println("Sorry, Age must be less than 12 to register as kid");
        }
    }

    public void requestBook() {
        if(bookType.equals("Kids")){
            System.out.println("Book Issued succesfully.. please return in 10days");
        } else {
            System.out.println("Oops, you are allowed only kids books");
        }
    }
}

class AdultUser implements LibraryUser {
    int age;
    String bookType;

    public void registerAccount() {
        if(age > 12){
            System.out.println("You have succesfully registered under Adult Account");
        } else {
            System.out.println("Sorry Age must be greater than 12 to register as adult");
        }
    }

    public void requestBook() {
        if(bookType.equals("Fiction")){
            System.out.println("Book issued succesfully, pls return within 7 days");
        } else {
            System.out.println("Oops, only Fiction books allowed for adults");
        }
    }
}

public class LibraryInterfaceDemo {
    public static void main(String args[]) {
        KidUser kid1 = new KidUser();
        kid1.age=10;
        kid1.registerAccount();
        kid1.bookType="Kids";
        kid1.requestBook();

        KidUser kid2 = new KidUser();
        kid2.age = 18;
        kid2.registerAccount();
        kid2.bookType = "Fiction";
        kid2.requestBook();

        AdultUser adult1 = new AdultUser();
        adult1.age=5;
        adult1.registerAccount();
        adult1.bookType="Kids";
        adult1.requestBook();

        AdultUser adult2 = new AdultUser();
        adult2.age = 23;
        adult2.registerAccount();
        adult2.bookType="Fiction";
        adult2.requestBook();
    }
}
