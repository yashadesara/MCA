import java.io.File;
import java.io.IOException;

public class exe36 
{
    public static void main(String[] args) 
    {
        File f = new File("./Demo.txt");
        try 
        {
            if (f.createNewFile()) 
                System.out.println(f.getName() + " Created succesfully on " + f.getAbsolutePath() + " it's length is "+f.length());
            else 
                System.out.println("not created");
        } 
        catch (Exception e) {
        }
    }
}
