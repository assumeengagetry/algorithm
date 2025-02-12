public class CreditCard {
    // 信用卡号码
    public String cardNumber;
    // 信用卡消费金额
    public double expenses;

    // 向信用卡收费
    public void charge(double amount) {
        expenses += amount;
    }

    // 获取信用卡号码（需要密码）
    public String getCardNumber(String password) {
        if(password.equals("password")) {
            return cardNumber;
        } else {
            return "wrong password";
        }
    }
}