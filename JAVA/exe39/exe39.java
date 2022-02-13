import java.io.File;

public class exe39 
{
    public static void main(String[] args) 
    {
        File file = new File("D:/binary_search.txt");
        if (!file.exists()) {
            System.out.println("not exists ");
        } else {
            System.out.println("exists" + file.getAbsolutePath());
        }
    }
}