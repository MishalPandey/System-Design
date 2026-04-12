public class SimpleSingleton {
    //In java yaha static ko class ke andar bhi intialise kar sakte hai
    private static SimpleSingleton instance = null;

    private SimpleSingleton() {
        System.out.println("Singleton Constructor called");
    }

    public static SimpleSingleton getInstance() {
        if (instance == null) {
            instance = new SimpleSingleton();
        }
        return instance;
    }

    public static void main(String[] args) {
        SimpleSingleton s1 = SimpleSingleton.getInstance();
        SimpleSingleton s2 = SimpleSingleton.getInstance();

        System.out.println(s1 == s2);
        // Output will be 1 (true) since both s1 and s2 point to the same instance
        // it is a Singleton class
    }
}
