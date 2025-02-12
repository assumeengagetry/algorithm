package parenttools; 
public class Baby { 
    int servings; // 成员变量 servings

    void feed(int servings) { 
        // 方法级别的 servings 变量
        this.servings = this.servings + servings; 
    } 

    void poop() { 
        System.out.println("All better!"); 
        servings = 0; 
    } 
}
