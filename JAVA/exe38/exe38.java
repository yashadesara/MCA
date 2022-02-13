import java.io.File;

public class exe38 {
    public static void main(String[] args) {

        File file = new File("./5.txt");
        if (!file.exists()) {
            System.out.println("not exists ");
        } else {
            System.out.println("exists"+file.getAbsolutePath());
        }
    }
}
