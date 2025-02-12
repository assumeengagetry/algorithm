public class ScopeReview {
    private int var3; 

    void scopeMethod(int var1) { 
        // 将传入的参数 var1 赋值给类的成员变量 var3
        var3 = var1; 
        String var2;
        // 根据 var1 的值决定 var2 的内容
        if (var1 > 0) {
            var2 = "above 0";
        } else {
            var2 = "less than or equal to 0"; 
        } 
        // 输出 var2 的值
        System.out.println(var2); 
    }
}
