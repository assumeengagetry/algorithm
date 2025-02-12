public class example {
    int memberVriable;

    void setVariable(int value) {
        // 使用 this 关键字引用当前对象的成员变量
        // this 关键字可以理解为“我的对象”
        this.memberVriable += value;
    }
}
