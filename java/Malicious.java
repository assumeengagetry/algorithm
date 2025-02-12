public class Malicious {
    public static void main(String[] args) {
        // 创建一个 CreditCard 类的实例
        maliciousMethod(new CreditCard());
    }
    static void maliciousMethod(CreditCard card) {
        card.expenses = 0;
        System.out.println(card.cardNumber);
    }
}
