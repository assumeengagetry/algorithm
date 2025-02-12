public class counter {
    int count =0;
    static int ourcount = 0;
    void incorrent(){
        count++;
        ourcount++;
    }
    public static void main(String[] args) {
        counter c1 = new counter();
        counter c2 = new counter();
        c1.incorrent();
        c1.incorrent();
        c2.incorrent();
        System.out.println(c1.count + " " + c1.ourcount);
        System.out.println(c2.count + " " + c2.ourcount);
    }
}