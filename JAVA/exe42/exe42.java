import java.io.File;
import java.io.FileInputStream;
import java.util.*;

public class exe42 {
    public static void main(String[] args) 
    {
        try {
            File f = new File("temp.txt");
            Scanner sc = new Scanner(f);
            int count = 0;
            while (sc.hasNextLine()) {
                sc.nextLine();
                count++;
            }
            sc.close();
            System.out.print("there is " + count + " Lines");
        } catch (Exception e) {

        }

    }
}
