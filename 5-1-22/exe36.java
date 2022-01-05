import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class exe36 {
    public static void main(String[] args) throws IOException{
       
            File f = new File("./demo.txt");
            if (!f.exists()) 
            {
                f.createNewFile();
                System.out.println("created");
            }
                FileOutputStream fout = new FileOutputStream(f);
                String s = "java is language ";
                byte b[] = s.getBytes();
                fout.write(b);
                System.out.println("writing complete");
                FileInputStream fin = new FileInputStream(f);
                int i;
                while ((i = fin.read())!= -1) {
                    System.out.print((char) i);
                }
                s = "java is object orieneted language language";
                b = s.getBytes();
                fout.write(b);
                System.out.println("modificaion completed");
                while ((i = fin.read()) != -1) {
                    System.out.print((char) i);
                }
                fin.close();
                fout.close();
            }
        }
