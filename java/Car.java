class Car {
    private String model;  // 只能在该类内部访问
    public int year;       // 任何地方都能访问
    
    // 构造方法
    public Car(String model, int year) {
        this.model = model;
        this.year = year;
    }

    // 提供访问器方法
    public String getModel() {
        return model;  // 外部通过这个方法访问私有属性
    }
}

public class Main {
    public static void main(String[] args) {
        Car myCar = new Car("Tesla", 2022);
        System.out.println("Model: " + myCar.getModel());
        System.out.println("Year: " + myCar.year);  // 直接访问公共属性
    }
}
