public class getMaxIndex {
    public static int getMaxIndex(int[] values) {
        if (values == null || values.length == 0) {
            throw new IllegalArgumentException("Array is null or empty");
        }
        int maxIndex = 0;
        for (int i = 1; i < values.length; i++) {
            if (values[i] > values[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }

    public static void main(String[] args) {
        int[] values = {1, 3, 7, 2, 5};
        int maxIndex = getMaxIndex(values);
        System.out.println("The index of the maximum value is: " + maxIndex);
    }
}
