public class rec {
    int length = 1, width = 1;
    static int count=0;

    static {
        System.out.println("static block");
    }

    {
        length = 0;
        width = 0;
        System.out.println("initializer block");
    }

    rec() {
        length = 1;
        width = 1;
        count++;
        System.out.println("default");
    }

    rec(rec r) {
        length = r.length;
        width = r.width;
        count++;
        System.out.println("copy");
    }

    rec(int l, int w) {
        this.length = l;
        this.width = w;
        count++;
        System.out.println("parametrized");
    }

    public void area() {
        System.out.println("area is: "+ length * width);
    }

    public static void main(String[] args) 
    {
        rec r = new rec();
        r.area();
        System.out.println("object created: "+rec.count);
        System.out.println();

        rec r2 = new rec(r);
        r2.area();
        System.out.println("object created: "+rec.count);
        System.out.println();

        rec r3 = new rec(3,3);
        r3.area();
        System.out.println("object created: "+rec.count);
        System.out.println();
    }
}
