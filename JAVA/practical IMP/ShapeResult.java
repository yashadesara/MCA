abstract class shape {
    abstract void area(int h, int w);
}

class tringle extends shape {
    void area(int h, int w) {
        System.out.println("area of tringle is: " + (h + w));
    }
}

class rectangle extends shape {
    void area(int h, int w) {
        System.out.println("area of rectangle is: " + (h * w));
    }
}

class circle extends shape {
    void area(int h, int w) {
        System.out.println("area of circle is: " + (h - w));
    }
}

public class ShapeResult {
    public static void main(String[] args) {
        tringle t = new tringle();
        t.area(20, 10);

        rectangle r = new rectangle();
        r.area(20, 10);

        circle c = new circle();
        c.area(20, 10);
    }
}
