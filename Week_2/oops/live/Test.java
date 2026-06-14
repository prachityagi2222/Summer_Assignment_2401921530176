package live;

import music.string.Veena;
import music.wind.Saxophone;
import music.Playable;

public class Test {
    public static void main(String[] args) {
        // a. Create an instance of Veena and call play()
        Veena veena = new Veena();
        veena.play();

        // b. Create an instance of Saxophone and call play()
        Saxophone saxophone = new Saxophone();
        saxophone.play();

        // c. Place the instances in a variable of type Playable and then call play()
        Playable p1 = veena;
        Playable p2 = saxophone;
        p1.play();
        p2.play();
    }
}